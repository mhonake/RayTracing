
#include "color.h"
#include "ray.h"
#include "print_progress.h"

#include <iostream>

bool hit_sphere(const point3& center, double radius, const ray& r)
{
    vec3 oc = center - r.origin();
    double a = dot(r.direction(), r.direction());
    double b = -2.0 * dot(r.direction(), oc);
    double c = dot(oc, oc) - radius*radius;
    double discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

color ray_color(const ray& r)
{
    if (hit_sphere(point3(0,0,-1), 0.5, r))
    {
        return color(1,0,0);
    }

    vec3 unit_direction = unit(r.direction());
    double a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{

    // Image
    
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    int image_height = int(image_width/aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;


    // Camera

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width)/image_height);
    point3 camera_center = point3(0, 0, 0);

    vec3 viewport_u = vec3(viewport_width, 0, 0);
    vec3 viewport_v = vec3(0, -viewport_height, 0);

    vec3 pixel_delta_u = viewport_u / image_width;
    vec3 pixel_delta_v = viewport_v / image_height;

    vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    vec3 pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);


    // Render
    // the following code writes a file in the PPM Image Format

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int row = 0; row < image_height; row++)
    {
        print_progress(row, image_height-1);
        for (int col = 0; col < image_width; col++)
        {
            vec3 pixel_center = pixel00_loc + (col * pixel_delta_u) + (row * pixel_delta_v);
            
            // TODO: investigate impact of not forcing ray_direction to be a unit vector
            vec3 ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
        std::cout << "\n";
    }
    print_progress(image_height-1, image_height-1);
    std::clog << "\nDone.\n";

    return 0;
}