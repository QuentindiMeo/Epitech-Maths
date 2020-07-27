/*
** EPITECH PROJECT, 2020
** 201yams_2019
** File description:
** yams tool functions
*/

#include "Yams.hpp"

int pow(const uint& a, const uint& p)
{
    if (!p) return (1);

    int res = a;

    for (int i = p - 1; i; i--) res *= a;
    return (res);
}

double fac(const uint& x)
{
    if (!x) return (1);

    int res = 1;

    for (uint i = x; i != 1; i--) res *= i;
    return (res);
}

int KinN(const int& k, const int& n)
{
    int nomin = fac(n);
    int denom = fac(k) * fac(n - k);

    return (nomin / denom);
}

double proba(const int& dice)
{ return (static_cast<double>(1) / (pow(6, dice))); }

int subtop(const int& a, const int& b)
{ return ((a - b < 0) ? 0 : a - b);  }

static bool isInVector(const std::vector<int>& a, const int& n)
{
    for (int i : a) if (i == n) return (true);
    return (false);
}

int countStraight(const std::vector<int>& a, const int& n)
{
    int cnt = 0;

    for (int i = n; i != n - 5; i--) if (isInVector(a, i)) cnt++;
    return (cnt);
}

int count(const std::vector<int>& a, const int& n)
{
    int cnt = 0;

    for (int i : a) if (i == n) cnt++;
    return (cnt);
}

double Yams::calcul(const int& p1, const int& p2)
{ return ((this->*(tab[this->combi]))(p1, p2)); }
