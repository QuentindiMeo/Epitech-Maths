/*
** EPITECH PROJECT, 2020
** 209poll_2019
** File description:
** poll include
*/

#ifndef POLL_HPP_
#define POLL_HPP_

#include <iostream>
#include "Enums.hpp"

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
} return_values_t;

typedef unsigned int uint;

class Poll
{
public:
    ~Poll();
    Poll(const int& pSize, const int& sSize, const double& perc);

    void   ceiling_floor(void);
    double getConfidence(const confidence_id_t& low_high, const int& interval);
    double getVariance(void);

    void   printConfidence(void);
    void   calculations(void);
    return_values_t main(void);

private:
    int    pSize;
    int    sSize;
    double perc;
    double calc[5];
};

#endif /* !POLL_HPP_ */
