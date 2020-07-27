/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** IQ tool functions
*/

#include <cmath>
#include <string>

double formula(const double& x, const int& mean, const int& stdDeriv)
{
    double v1 = 1 / (stdDeriv * std::sqrt(2 * M_PI));
    double nomin = std::pow(x - mean, 2);
    double denom = std::pow(stdDeriv, 2) * 2;
    double v2 = exp(-1 * nomin / denom);

    return (v1 * v2);
}

bool isValidNumber(const std::string& s)
{
    for (char c : s) if (c < '0' || c > '9') return (false);
    if  (std::stoi(s) > 200)                 return (false);
    return (true);
}
