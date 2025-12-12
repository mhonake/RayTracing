
#include "color.h"

#include <iostream>
#include <iomanip>

void print_progress(int progress, int len)
{
    const int barWidth = 50;
    int pos = double(progress)/len * barWidth;

    std::clog << "\r[";

    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)      std::clog << "=";
        else if (i == pos) std::clog << ">";
        else              std::clog << " ";
    }

    std::clog << "] " << std::fixed << std::setprecision(1)
              << (double(progress)/len * 100.0) << "% | Lines Remaining: " << len - progress << "  " << std::flush;
}

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