
#ifndef RAY_TRACING_CONSTANTS_H
#define RAY_TRACING_CONSTANTS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double deg_to_rad(double degrees)
{
    return degrees * pi / 180.0;
}

inline double rad_to_deg(double radians)
{
    return radians / pi * 180.0;
}

// Common Headers

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif