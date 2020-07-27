/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** IQ core functions
*/

#include <iomanip>
#include "IQ.hpp"

return_values_t IQ::printPercentage(void)
{
    double proba = 0;

    std::cout << std::fixed << std::setprecision(1);
    if (this->IQmax == EMPTY) {
        for (double x = this->IQmin - 0.001;  x > 0;  x -= 0.001)
            proba += formula(x, this->u, this->s);
        proba += formula(0, this->u, this->s);
        std::cout << proba / 10  << "% of people have an IQ inferior to "
                  << this->IQmin << std::endl;
    } else {
        for (double x = this->IQmin; x < this->IQmax; x += 0.001)
            proba += formula(x, this->u, this->s);
        std::cout << proba / 10  << "% of people have an IQ between "
                  << this->IQmin << " and " << this->IQmax << std::endl;
    }
    return (SUCCESS);
}

return_values_t IQ::plotDensity(void)
{
    std::cout << std::fixed << std::setprecision(5);
    for (uint x = 0; x <= 200; x++)
        std::cout << x << " " << formula(x, this->u, this->s) << std::endl;
    return (SUCCESS);
}

return_values_t IQ::main(void)
{
    return (this->IQmin == EMPTY ? this->plotDensity()
                                 : this->printPercentage());
}
