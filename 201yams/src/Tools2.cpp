/*
** EPITECH PROJECT, 2020
** 201yams_2019
** File description:
** yams tool functions 2
*/

#include "Yams.hpp"

static double bernoulli(int k, int n)
{
    int k_in_n = KinN(k, n);
    double f1 = proba(k);
    double f2 = proba(n - k) * pow(5, n - k);

    return (static_cast<double>(k_in_n) * f1 * f2);
}

double Yams::doYams(const int& p, const int& _uu)
{
    return (proba(5 - count(this->dice, p)));
}

double Yams::doStraight(const int& p, const int& _uu)
{
    if (this->dice[0] == this->dice[1] - 1 &&
        this->dice[1] == this->dice[2] - 1 &&
        this->dice[2] == this->dice[3] - 1 &&
        this->dice[3] == this->dice[4] - 1 && this->dice[4] == p)
            return (1);

    int sub = 5 - countStraight(this->dice, p);

    return (fac(sub) * proba(sub));
}

double Yams::doFull(const int& p1, const int& p2)
{
    if (count(this->dice, p1) == 3 && count(this->dice, p2) == 2) return (1);

    int sub =       subtop(3, count(this->dice, p1));
    int top = sub + subtop(2, count(this->dice, p2));

    return (KinN(sub, top) * proba(top));
}

double Yams::doFour(const int& p, const int& _uu)
{
    if (count(this->dice, p) > 3)  return (1);
    if (count(this->dice, p) == 3) return (bernoulli(1, 2) + bernoulli(2, 2));
    if (count(this->dice, p) == 2) return (bernoulli(2, 3) + bernoulli(3, 3));
    if (count(this->dice, p) == 1) return (bernoulli(3, 4) + bernoulli(4, 4));
    return (bernoulli(4, 5) + bernoulli(5, 5));
}

double Yams::doThree(const int& p, const int& _uu)
{
    if (count(this->dice, p)  > 2) return (1);
    if (count(this->dice, p) == 2)
        return (bernoulli(1, 3) + bernoulli(2, 3) + bernoulli(3, 3));
    if (count(this->dice, p) == 1)
        return (bernoulli(2, 4) + bernoulli(3, 4) + bernoulli(4, 4));
    return (bernoulli(3, 5) + bernoulli(4, 5) + bernoulli(5, 5));
}

double Yams::doPair(const int& p, const int& _uu)
{
    if (count(this->dice, p) > 1)  return (1);
    if (count(this->dice, p) == 1) return (bernoulli(1, 4) + bernoulli(2, 4) +
                                           bernoulli(3, 4) + bernoulli(4, 4));
    return (bernoulli(2, 5) + bernoulli(3, 5) +
            bernoulli(4, 5) + bernoulli(5, 5));
}
