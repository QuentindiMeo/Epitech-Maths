#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 304pacman_2021
## File description:
## pacman algorithm functions
##

from tool import val, getMaxLen

def algo(arr, loop, toOpen, foundPac):
    newToOpen = []

    for [x, y] in toOpen:
        if (x > 0):
            if (arr[x - 1][y] == val.PAC):
                foundPac = True
                return
            elif (arr[x - 1][y] == val.EMP):
                arr[x - 1][y] = loop
                newToOpen.append([x - 1, y])
        if (y < len(arr[x]) - 1):
            if (arr[x][y + 1] == val.PAC):
                foundPac = True
                return
            elif (arr[x][y + 1] == val.EMP):
                arr[x][y + 1] = loop
                newToOpen.append([x, y + 1])
        if (x < len(arr) - 1):
            if (arr[x + 1][y] == val.PAC):
                foundPac = True
                return
            elif (arr[x + 1][y] == val.EMP):
                arr[x + 1][y] = loop
                newToOpen.append([x + 1, y])
        if (y > 0):
            if (arr[x][y - 1] == val.PAC):
                foundPac = True
                return
            elif (arr[x][y - 1] == val.EMP):
                arr[x][y - 1] = loop
                newToOpen.append([x, y - 1])
    if (not len(newToOpen)) : return
    algo(arr, loop + 1, newToOpen, foundPac)

def applyAlgo(arr):
    loop     = 1
    toOpen   = []
    foundPac = False

    for x in range(len(arr)):
        if (val.FAN in arr[x]):
            pFan = arr[x].index(val.FAN)
            if (x > 0):
                if (arr[x - 1][pFan] == val.PAC):
                    foundPac = True
                    return
                elif (arr[x - 1][pFan] == val.EMP):
                    arr[x - 1][pFan] = loop
                    toOpen.append([x - 1, pFan])
            if (pFan < len(arr[x]) - 1):
                if (arr[x][pFan + 1] == val.PAC):
                    foundPac = True
                    return
                elif (arr[x][pFan + 1] == val.EMP):
                    arr[x][pFan + 1] = loop
                    toOpen.append([x, pFan + 1])
            if (x < len(arr) - 1):
                if (arr[x + 1][pFan] == val.PAC):
                    foundPac = True
                    return
                elif (arr[x + 1][pFan] == val.EMP):
                    arr[x + 1][pFan] = loop
                    toOpen.append([x + 1, pFan])
            if (pFan > 0):
                if (arr[x][pFan - 1] == val.PAC):
                    foundPac = True
                    return
                elif (arr[x][pFan - 1] == val.EMP):
                    arr[x][pFan - 1] = loop
                    toOpen.append([x, pFan - 1])
    if (not len(toOpen)) : return
    algo(arr, loop + 1, toOpen, foundPac)

def getMap(path):
    arr = []
    fil = open(path)

    for s in fil:
        a = []

        if (s == "\n") : continue
        for c in s:
            if   (c == '\n') : a.append(val.LIN)
            elif (c == '0')  : a.append(val.EMP)
            elif (c == '1')  : a.append(val.WAL)
            elif (c == 'F')  : a.append(val.FAN)
            elif (c == 'P')  : a.append(val.PAC)
        arr.append(a)
    maxlen = getMaxLen(arr)
    for x in range(len(arr)):
        if (len(arr[x]) < maxlen):
            arr[x] = arr[x][0 : len(arr[x]) - 1] + ([val.EMP] * (maxlen - len(arr[x]))) + [val.LIN]
    return arr
