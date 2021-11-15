#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 304pacman_2021
## File description:
## pacman tool functions
##

from enum import Enum

class val(Enum):
    LIN = -84
    EMP = -42
    WAL =  0
    FAN = -1
    PAC = -2

def getMaxLen(arr):
    maxlen = 0

    for s in arr:
        if (maxlen < len(s)):
            maxlen = len(s)
    return maxlen

def madeOf(chars, arr):
    chars += '\n'
    for s in arr:
        for c in s:
            if (c not in chars) : return False
    return True

def count(char, arr):
    ctr = 0

    for s in arr:
        for c in s:
            if (c == char) : ctr += 1
    return ctr

def dispMap(arr, wal, emp):
    for s in arr:
        for i in range(len(s)):
            if   (s[i] == val.LIN) : print ("")
            elif (s[i] == val.EMP) : print (emp,       end = "")
            elif (s[i] == val.WAL) : print (wal,       end = "")
            elif (s[i] == val.FAN) : print ("F",       end = "")
            elif (s[i] == val.PAC) : print ("P",       end = "")
            else                   : print (s[i] % 10, end = "")
