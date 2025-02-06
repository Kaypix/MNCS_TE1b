#include "methode.h"
#include <eigen3/Eigen/Dense>
#include <functional>
#include <iostream>

using namespace std ;
using namespace Eigen ;

float deriv2tdd (function<float(float)>f, const float t0_, const float h) { 
        return (f(t0_+h)-f(t0_))/h ;
} 

float deriv2tdg (function<float(float)>f, const float t0_, const float h) { 
        return (f(t0_)-f(t0_-h))/h ;
} 

float deriv2tc (function<float(float)>f, const float t0_, const float h) { 
        return (f(t0_+h)-f(t0_-h))/(2*h) ;
} 
