
#include "color.h"
#include "print_progress.h"

#include <iostream>

int main()
{
    // IMAGE

    int WIDTH = 256;
    int HEIGHT = 256;

    // RENDER
    // the following code writes a file in the PPM Image Format

    std::cout << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    for (int row = 0; row < HEIGHT; row++)
    {
        print_progress(row, HEIGHT-1);
        for (int col = 0; col < WIDTH; col++)
        {
            auto pixel_color = color(double(col)/(WIDTH-1), double(row)/(HEIGHT-1), 0);
            write_color(std::cout, pixel_color);
        }
        std::cout << "\n";
    }
    print_progress(HEIGHT-1, HEIGHT-1);
    std::clog << "\nDone.\n";

    return 0;
}