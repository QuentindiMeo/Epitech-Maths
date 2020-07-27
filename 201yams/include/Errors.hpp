/*
** EPITECH PROJECT, 2020
** 201yams_2019
** File description:
** yams errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

static const std::string ERR_INV_ARG = "Invalid number of arguments.";
static const std::string ERR_INV_DIC = "One die or more is/are invalid.";
static const std::string ERR_INV_CBN = "Invalid combination.";
static const std::string ERR_UNK     = "Unknown error.";

class AError : public std::exception
{
public:
    ~AError();
    AError(std::string const &message = ERR_UNK);

    const char *what() const noexcept override { return (this->msg.c_str()); }
private:
    std::string msg;
};

#endif /* !ERRORS_HPP_ */
