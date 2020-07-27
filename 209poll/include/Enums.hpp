/*
** EPITECH PROJECT, 2020
** 209poll_2019
** File description:
** poll enums include
*/

#ifndef POLLENUMS_HPP_
#define POLLENUMS_HPP_

typedef enum {
    BOT = false,
    TOP = true,
} confidence_id_t;

typedef enum {
    VARIANCE,
    FIVE_BOT,
    FIVE_TOP,
    NINE_BOT,
    NINE_TOP,
} calculations_t;

const static double INTERVAL95 = 2 * 1.96;
const static double INTERVAL99 = 2 * 2.58;

#endif /* !POLLENUMS_HPP_ */
