/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** main IQ
*/

#include <cstring>
#include "Errors.hpp"
#include "IQ.hpp"

static return_values_t help(void)
{
    std::cout << "USAGE\n    ./205IQ u s [IQ1] [IQ2]\n"
              << "\nDESCRIPTION\n"
              << "    u        mean\n"
              << "    s        standard derivation\n"
              << "    IQ1      minimum IQ\n"
              << "    IQ2      maximum IQ"
              << std::endl;
    return (SUCCESS);
}

IQ::IQ(const int& a, const int& b, const int& i, const int& j) :  u(a), s(b), IQmin(i), IQmax(j) {}
IQ::~IQ(void) {}

AError::AError(const std::string& e) : msg(e) {}
AError::~AError(void) {}

int main(int ac, char **av)
{
    if (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))
        return (help());
    try {
        if (ac < 3 || ac > 5)
            throw (AError(ERR_NBR_ARG));
        if (!isValidNumber(av[1]) || std::stoi(av[2]) <= 0 ||
        (ac > 3 && !isValidNumber(av[3]))||(ac > 4 && !isValidNumber(av[4])) ||
        (ac == 5 && std::stoi(av[3]) > std::stoi(av[4])))
            throw (AError(ERR_INV_ARG));
    } catch (const AError& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Try './205IQ --help' for more information." << std::endl;
        return (FAILURE);
    }
    IQ iq(std::stoi(av[1]), std::stoi(av[2]),
          std::stoi(ac > 3 ? av[3] : "-1"), std::stoi(ac > 4 ? av[4] : "-1"));
    return (iq.main());
}
