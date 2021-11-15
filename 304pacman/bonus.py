#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 304pacman_2021
## File description:
## pacman bonus
##

import enum
from tool import val
import pygame as pg

def getBonus(arr):
    res = []

    for x in range(len(arr)):
        stk = []
        for y in range(len(arr[x])):
            if   (arr[x][y] == val.WAL) : stk.append([0, 0])
            elif (arr[x][y] == val.EMP) : stk.append([0, 1])
            elif (arr[x][y] == val.FAN) : stk.append([0, 2])
            elif (arr[x][y] == val.PAC) :
                stk.append([0, 3])
                pac = [x, y]
            elif (not isinstance(arr[x][y], enum.Enum)) : stk.append([0, 1])
            elif (arr[x][y] == val.LIN) : break
        res.append(stk)
    v = [999, -1] if (pac[1] == 0 or (pac[1] != 0 and isinstance(arr[pac[0]][pac[1] - 1], enum.Enum))) else [arr[pac[0]][pac[1] - 1], 1]
    newv = 999 if (pac[0] == len(arr) - 1 or (pac[0] != len(arr) - 1 and isinstance(arr[pac[0] + 1][pac[1]], enum.Enum))) else arr[pac[0] + 1][pac[1]]
    v = [newv if (newv < v[0]) else v[0], 2 if (newv < v[0]) else v[1]]
    newv = 999 if (pac[1] == len(arr[pac[0]]) - 1 or (pac[1] != len(arr[pac[0]]) - 1 and isinstance(arr[pac[0]][pac[1] + 1], enum.Enum))) else arr[pac[0]][pac[1] + 1]
    v = [newv if (newv < v[0]) else v[0], 3 if (newv < v[0]) else v[1]]
    newv = 999 if (pac[0] == 0 or (pac[0] != 0 and isinstance(arr[pac[0] - 1][pac[1]], enum.Enum))) else arr[pac[0] - 1][pac[1]]
    v = [newv if (newv < v[0]) else v[0], 4 if (newv < v[0]) else v[1]]
    if   (v[1] == 1) : pac[1] -= 1
    elif (v[1] == 2) : pac[0] += 1
    elif (v[1] == 3) : pac[1] += 1
    elif (v[1] == 4) : pac[0] -= 1
    while (v[0]):
        if (pac[1] - 1 != 0 and not isinstance(arr[pac[0]][pac[1] - 1], enum.Enum) and arr[pac[0]][pac[1] - 1] == v[0] - 1):
            res[pac[0]][pac[1]] = [1, 0] if v[1] == 1 else [2, 1] if v[1] == 2 else [2, 0]
            pac[1] -= 1
            v[1]    = 1
        elif (pac[0] != len(arr) - 1 and not isinstance(arr[pac[0] + 1][pac[1]], enum.Enum) and arr[pac[0] + 1][pac[1]] == v[0] - 1):
            res[pac[0]][pac[1]] = [2, 2] if v[1] == 1 else [1, 1] if v[1] == 2 else [2, 0]
            pac[0] += 1
            v[1]    = 2
        elif (pac[1] != len(arr[pac[0]]) and not isinstance(arr[pac[0]][pac[1] + 1], enum.Enum) and arr[pac[0]][pac[1] + 1] == v[0] - 1):
            res[pac[0]][pac[1]] = [2, 2] if v[1] == 2 else [1, 0] if v[1] == 3 else [2, 1]
            pac[1] += 1
            v[1]    = 3
        elif (pac[0] != 0 and not isinstance(arr[pac[0] - 1][pac[1]], enum.Enum) and arr[pac[0] - 1][pac[1]] == v[0] - 1):
            res[pac[0]][pac[1]] = [2, 1] if v[1] == 1 else [2, 3] if v[1] == 3 else [1, 1]
            pac[0] -= 1
            v[1]    = 4
        v[0] -= 1
    if (pac[1] - 1 != 0 and not isinstance(arr[pac[0]][pac[1] - 1], enum.Enum) and arr[pac[0]][pac[1] - 1] == val.FAN):
        res[pac[0]][pac[1]] = [1, 0] if v[1] == 1 else [2, 1] if v[1] == 2 else [2, 0]
    elif (pac[0] != len(arr) - 1 and arr[pac[0] + 1][pac[1]] == val.FAN):
        res[pac[0]][pac[1]] = [2, 2] if v[1] == 1 else [1, 1] if v[1] == 2 else [2, 0]
    elif (pac[1] != len(arr[pac[0]]) and arr[pac[0]][pac[1] + 1] == val.FAN):
        res[pac[0]][pac[1]] = [2, 2] if v[1] == 2 else [1, 0] if v[1] == 3 else [2, 1]
    elif (pac[0] != 0 and arr[pac[0] - 1][pac[1]] == val.FAN):
        res[pac[0]][pac[1]] = [2, 1] if v[1] == 1 else [2, 3] if v[1] == 3 else [1, 1]
    return res

def dispBonus(res, scr):
    ass = [[pg.image.load('assets/wall.png'), pg.image.load('assets/slo.png'), pg.image.load('assets/fan.png'), pg.image.load('assets/pac.png')],
           [pg.image.load('assets/s1.png'), pg.image.load('assets/s2.png')],
           [pg.image.load('assets/t1.png'), pg.image.load('assets/t2.png'), pg.image.load('assets/t3.png'), pg.image.load('assets/t4.png')]]

    for x in range(len(res)):
        for y in range(len(res[x])):
            scr.blit(ass[0][1], [600 - (len(res[x]) * 10) + y * 21, 450 - (len(res) * 10) + x * 21])
            if (res[x][y] is not [0, 1]) : scr.blit(ass[res[x][y][0]][res[x][y][1]], [600 - (len(res[x]) * 10) + y * 21, 450 - (len(res) * 10) + x * 21])

def launchBonus(arr):
    res = getBonus(arr)
    pg.init()
    scr = pg.display.set_mode([1200, 900])
    pg.display.set_caption("Pacman")
    noEsc = True

    scr.fill([222, 222, 42])
    dispBonus(res, scr)
    pg.display.update()
    while (noEsc):
        for e in pg.event.get():
            if (e.type == pg.QUIT or (e.type == pg.KEYDOWN and e.key == pg.K_ESCAPE)) : noEsc = False
