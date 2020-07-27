/*
** EPITECH PROJECT, 2020
** 209poll_2019
** File description:
** poll tool functions
*/

#include <cmath>
#include "Poll.hpp"

void Poll::ceiling_floor(void)
{
    if (this->calc[FIVE_BOT] < 0)   this->calc[FIVE_BOT] =   0;
    if (this->calc[FIVE_TOP] > 100) this->calc[FIVE_TOP] = 100;
    if (this->calc[NINE_BOT] < 0)   this->calc[NINE_BOT] =   0;
    if (this->calc[NINE_TOP] > 100) this->calc[NINE_TOP] = 100;
}

double Poll::getConfidence(const confidence_id_t& t, const int& itv)
{
    double v        = this->calc[VARIANCE];
    double interval = (itv == 95) ? INTERVAL95 : INTERVAL99;

    return (this->perc + (t ? 1 : -1) * interval * std::sqrt(v) / 2 * 100);
}

double Poll::getVariance(void)
{
    double a = static_cast<double>(this->perc / 100);
    double b = static_cast<double>(1 - this->perc / 100) / this->sSize;
    double c = static_cast<double>(this->pSize - this->sSize)/(this->pSize - 1);

    return (a * b * c);
}
