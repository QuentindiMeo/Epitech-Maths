/*
** EPITECH PROJECT, 2020
** 209poll_2019
** File description:
** poll core functions
*/

#include <iomanip>
#include "Poll.hpp"

void Poll::printConfidence(void)
{
    std::cout << "95% confidence interval:\t[";
    std::cout << this->calc[FIVE_BOT] << "%; " << this->calc[FIVE_TOP] << "%]";
    std::cout << std::endl;

    std::cout << "99% confidence interval:\t[";
    std::cout << this->calc[NINE_BOT] << "%; " << this->calc[NINE_TOP] << "%]";
    std::cout << std::endl;
}

void Poll::calculations(void)
{
    this->calc[VARIANCE] = getVariance();
    this->calc[FIVE_BOT] = getConfidence(BOT, 95);
    this->calc[FIVE_TOP] = getConfidence(TOP, 95);
    this->calc[NINE_BOT] = getConfidence(BOT, 99);
    this->calc[NINE_TOP] = getConfidence(TOP, 99);
}

return_values_t Poll::main(void)
{
    Poll::calculations(); Poll::ceiling_floor();
    std::cout << std::fixed;
    std::cout << "Population size:\t\t"   << this->pSize          << std::endl;
    std::cout << "Sample size:\t\t\t"     << this->sSize          << std::endl;
    std::cout << std::setprecision(2);
    std::cout << "Voting intentions:\t\t" << this->perc << "%"    << std::endl;
    std::cout << std::setprecision(6);
    std::cout << "Variance:\t\t\t"        << this->calc[VARIANCE] << std::endl;
    std::cout << std::setprecision(2);
    Poll::printConfidence();
    return (SUCCESS);
}
