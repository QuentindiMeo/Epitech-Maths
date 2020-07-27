/*
** EPITECH PROJECT, 2020
** 201yams_2019
** File description:
** yams core functions
*/

#include <algorithm>
#include <iomanip>
#include "Yams.hpp"

static int getParam(const std::string& s, const int id)
{
    if (!id)
        for (int cursor = 0; s[cursor]; cursor++)
            if (s[cursor] >= '0' && s[cursor] <= '9')
                return (s[cursor] - 48);
    return (s[s.length() - 1] - 48);
}

return_values_t Yams::printProba(void)
{
    std::string t = this->combi;
    int cursor = 0;
    double res;

    std::sort(this->dice.begin(), this->dice.end());
    for (char c : this->combi) {
        if (c == '_') break;
        cursor++;
    }
    this->combi = this->combi.substr(0, cursor);
    res = this->calcul(getParam(t, 0), getParam(t, 1));
    std::cout << std::fixed << std::setprecision(2);
    std::cout << res * 100  << "%" << std::endl;
    return (SUCCESS);
}

void printCombi(const std::string& combi)
{
    std::string msg = "Chances to get a ";

    if (combi.rfind("fu", 0))
        msg += combi[combi.length() - 1];
    if      (!combi.rfind("p", 0))  msg += " pair";
    else if (!combi.rfind("t", 0))  msg += " three-of-a-kind";
    else if (!combi.rfind("fo", 0)) msg += " four-of-a-kind";
    else if (!combi.rfind("s", 0))  msg += " straight";
    else if (!combi.rfind("y", 0))  msg += " yams";
    else if (!combi.rfind("fu", 0)) {
        msg += combi[combi.length() - 3];
        msg += " full of ";
        msg += combi[combi.length() - 1];
    }
    std::cout << msg << ": ";
}
