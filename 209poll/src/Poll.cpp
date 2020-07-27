/*
** EPITECH PROJECT, 2020
** 209poll_2019
** File description:
** main poll
*/

#include <cstring>
#include "Errors.hpp"
#include "Poll.hpp"

static void checkInvalidArgs(char **av)
{
    if (atof(av[3]) < 0 || atof(av[3]) > 100) throw (AError(ERR_INV_ARG));
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0) throw (AError(ERR_INV_ARG));
    if (atoi(av[1]) < atoi(av[2]))            throw (AError(ERR_INV_ARG));
}

static return_values_t help(void)
{
    std::cout << "USAGE\n\t./209poll pSize sSize p\n"
              << "\nDESCRIPTION\n"
              << "\tpSize\tsize of the population\n"
              << "\tsSize\tsize of the sample (supposed to be representative)\n"
              << "\tp\tpercentage of voting intentions for a specific candidate"
              << std::endl;
    return (SUCCESS);
}

Poll::~Poll() {}
Poll::Poll(const int& a, const int& b, const double& c)  :  pSize(a), sSize(b), perc(c), calc{0,0,0,0,0} {}

AError::AError(const std::string& e) : msg(e) {}
AError::~AError(void) {}

int main(int ac, char **av)
{
    if (ac == 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "--help")))
        return (help());
    try {
        if (ac != 4)
            throw (AError(ERR_NBR_ARG));
        checkInvalidArgs(av);
    } catch (const AError& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Try './209poll --help' for more information." <<std::endl;
        return (FAILURE);
    }

    Poll poll(std::stoi(av[1]), std::stoi(av[2]), std::stod(av[3]));
    return (poll.main());
}
