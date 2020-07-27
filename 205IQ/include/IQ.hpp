/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** IQ include
*/

#ifndef IQ_HPP_
#define IQ_HPP_

#include <iostream>

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
    EMPTY = -1,
} return_values_t;

typedef unsigned int uint;

class IQ {
public:
    IQ(const int& a, const int& b, const int& i, const int& j);
    ~IQ();

    return_values_t printPercentage(void);
    return_values_t plotDensity(void);
    return_values_t main(void);
private:
    uint u;
    uint s;
    uint IQmin;
    uint IQmax;
};

double formula(const double& x, const int& mean, const int& stdDeriv);

bool isValidNumber(const std::string& s);

#endif /* !IQ_HPP_ */
