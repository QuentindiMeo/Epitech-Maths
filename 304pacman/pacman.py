#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 304pacman_2021
## File description:
## main pacman
##

from   sys import exit, argv
from  enum import Enum
from  algo import getMap, applyAlgo
from  tool import count,  dispMap,  madeOf,  val

####################### PERSONAL ENUMS #######################

class Err(Enum):
    NB_ARGS = 0
    INV_ARG = 1
    INV_PAC = 2

####################### CORE FUNCTIONS #######################

def pacman(path, wall, emp, bonus):
    arr = getMap(path)
    if (not count(val.PAC, arr)):
        dispMap(arr, wall, emp)
        return error(Err.INV_PAC)
    applyAlgo(arr)
    if (not bonus) : dispMap(arr, wall, emp)
    else :
        from bonus import launchBonus
        launchBonus(arr)
    return 0

############################ MAIN ############################

def error(code):
    if   (code == Err.NB_ARGS) : print ("Invalid number of arguments.")
    elif (code == Err.INV_ARG) : print ("Invalid file passed as parameter.")
    elif (code == Err.INV_PAC) : return 84
    print ("Try './304pacman --help' for more information.")
    return 84

def invalidArguments(av):
    try:
        arr = []
        fil = open(av[1])

        for s in fil:
            if (s == "\n") : continue
            arr.append(s)
        fil.close()
        if (len(av[2]) > 1 or len(av[3]) > 1)            : return True
        if (not madeOf("01FP", arr))                     : return True
        if (count('F', arr) != 1 or count('P', arr) > 1) : return True
        return False
    except:
        return True

def help():
    print ("    file    file describing the board, using the following characters:")
    print ("                '0' for an empty square,")
    print ("                '1' for a wall,")
    print ("                'F' for the ghost's position,")
    print ("                'P' for Pacman's position.")
    print ("    c1      character to display for a wall")
    print ("    c2      character to display for an empty space.")
    return 0

def main(ac, av, bonus = False):
    if (ac == 2 and (av[1] == "-h" or av[1] == "--help")) : return help()
    if (ac == 5 and  av[4] == "--bonus")                  : return main(ac - 1, av[:-1], True)
    if (ac != 4)                                          : return error(Err.NB_ARGS)
    if (invalidArguments(av))                             : return error(Err.INV_ARG)
    return pacman(av[1], av[2][0], av[3][0], bonus)

if (__name__ == "__main__") : exit(main(len(argv), argv))
