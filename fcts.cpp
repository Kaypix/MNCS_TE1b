#include "fcts.h"
#include <cmath>
#include <iostream>

float k ;

float sinf (float t) {
    return sin(k*t) ;
}

float derivSinAna (float t) {
    return k * cos(k*t) ;
}

float expf (float t) {
    return exp(k*t) ;
}

float derivExpAna (float t) {
    return k*exp(k*t) ;
}