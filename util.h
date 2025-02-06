#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <eigen3/Eigen/Dense>

void ecrit(const std::string& nomFichier, const Eigen::VectorXf& h, const Eigen::VectorXf& delta);

#endif