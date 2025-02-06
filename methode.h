#ifndef METHODE_H
#define METHODE_H

#include <functional>

float deriv2tdd (std::function<float(float)>f, const float t0, const float h) ;

float deriv2tdg (std::function<float(float)>f, const float t0, const float h) ;

float deriv2tc (std::function<float(float)>f, const float t0, const float h) ;

#endif 