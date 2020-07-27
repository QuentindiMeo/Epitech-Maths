/*
** EPITECH PROJECT, 2020
** 201yams_2019
** File description:
** main yams
*/

#include <algorithm>
#include <cstring>
#include "Errors.hpp"
#include "Yams.hpp"

static void checkValidComb(const std::string& t)
{
    if (t.length() < 6)
        throw (AError(ERR_INV_CBN));

    std::string end = t.substr(t.length() - 3, t.length());

    if (end[2] < '1' || end[2] > '6' || end[1] != '_' ||
        (t.rfind("full_", 0) && (end[0] < 'a' || end[0] > 'z')))
        throw (AError(ERR_INV_CBN));
    if (!t.rfind("full_", 0) && t[t.length() - 1] == t[t.length() - 3])
        throw (AError(ERR_INV_CBN));
    if (!t.rfind("pair_", 0) || !t.rfind("three_", 0) || !t.rfind("four_", 0) ||
        !t.rfind("straight_", 0) || !t.rfind("yams_", 0)) {
        if (!t.rfind("straight_", 0) && (end[2] != '5' && end[2] != '6'))
            throw (AError(ERR_INV_CBN));
        return;
    }
    end = t.substr(t.length() - 4, t.length());
    if (end[0] == '_' && end[1] >= '1' && end[1] <= '6' &&
        end[2] == '_' && end[3] >= '1' && end[3] <= '6')
        return;
    throw (AError(ERR_INV_CBN));
}

static void checkValidDice(const std::vector<std::string>& ta)
{
    for (std::string s : ta)
        if (s.length() != 1)
            throw (AError(ERR_INV_DIC));
    for	(std::string s : ta)
        if (s[0] < '0' || s[0] > '6')
            throw (AError(ERR_INV_DIC));
}

static return_values_t help(void)
{
    std::cout << "USAGE\n    ./201yams d1 d2 d3 d4 d5 c\n"
        << "\nDESCRIPTION\n"
        << "    d1      value of the first die (0 if not thrown)\n"
        << "    d2      value of the second die (0 if not thrown)\n"
        << "    d3      value of the third die (0 if not thrown)\n"
        << "    d4      value of the fourth die (0 if not thrown)\n"
        << "    d5      value of the fifth die (0 if not thrown)\n"
        << "    c       expected combination" << std::endl;
    return (SUCCESS);
}

Yams::Yams(std::vector<int> a, std::string s) : dice(a), combi(s)
{
    tab["pair"]     = &Yams::doPair;
    tab["three"]    = &Yams::doThree;
    tab["four"]     = &Yams::doFour;
    tab["full"]     = &Yams::doFull;
    tab["straight"] = &Yams::doStraight;
    tab["yams"]     = &Yams::doYams;
}

Yams::~Yams(void) {}

AError::AError(const std::string& e) : msg(e) {}
AError::~AError(void) {}

int main(int ac, char **av)
{
    if (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))
        return (help());
    try {
        if (ac != 7)
            throw (AError(ERR_INV_ARG));
        checkValidDice({av[1], av[2], av[3], av[4], av[5]});
        checkValidComb(av[6]);
    } catch (const AError& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Try './201yams --help' for more information."<< std::endl;
        return (FAILURE);
    }
    printCombi(av[6]);
    Yams yams({std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]),
               std::stoi(av[4]), std::stoi(av[5])}, av[6]);
    return (yams.printProba());
}
