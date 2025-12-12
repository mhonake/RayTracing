
#ifndef PRINT_PROGRESS_H
#define PRINT_PROGRESS_H

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

#endif