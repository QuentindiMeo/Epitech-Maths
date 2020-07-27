/*
** EPITECH PROJECT, 2020
** 201yams_2019
** File description:
** include yams
*/

#include <iostream>
#include <map>
#include <vector>

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
} return_values_t;

typedef unsigned int uint;

class Yams {
public:
    Yams(std::vector<int> arrayOfDice, std::string combination);
    ~Yams();

    double doYams(    const int& p, const int& _uu = 0);
    double doStraight(const int& p, const int& _uu = 0);
    double doFull(    const int& p1, const int& p2);
    double doFour(    const int& p, const int& _uu = 0);
    double doThree(   const int& p, const int& _uu = 0);
    double doPair(    const int& p, const int& _uu = 0);

    double calcul(    const int& p1, const int& p2);
    return_values_t printProba(void);
private:
    std::vector<int> dice;
    std::string     combi;
    std::map<std::string, double (Yams::*)(const int &, const int &)> tab;
};

void printCombi(const std::string& combi);

double fac(const uint& x);
int KinN(const int& a, const int& b);
int pow(const uint& a, const uint& p);
int permu(const int& size);
double proba(const int& n);
int subtop(const int& a, const int& b);
int countStraight(const std::vector<int>& a, const int& n);
int count(const std::vector<int>& a, const int& n);
