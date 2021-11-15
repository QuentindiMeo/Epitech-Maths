#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 304pacman
## File description:
## pacman test functions
##

from     os import system
# from   copy import deepcopy as objdup
from pacman import *
import unittest

class TestArguments(unittest.TestCase):
    def test_arg_too_many(self):
        self.assertEqual(main(5, ["./304pacman", "file", "o", "l", "toomany"]), 84)
    def test_arg_too_little(self):
        self.assertEqual(main(1, ["./304pacman"]),              84)
        self.assertEqual(main(2, ["./304pacman", "file"]),      84)
        self.assertEqual(main(3, ["./304pacman", "file", "o"]), 84)
    def test_arg_empty_file(self):
        system('touch tests/thisIsAnEmptyFile.txt')
        self.assertEqual(main(4, ["./304pacman", "tests/thisIsAnEmptyFile.txt", "o", "l"]), 84)
        system('rm -f tests/thisIsAnEmptyFile.txt')
    def test_arg_invalid_file(self):
        self.assertEqual(main(4, ["./304pacman", "DEADBUFF.txt", "o", "l"]), 84)
    def test_arg_help(self):
        self.assertEqual(main(2, ["./304pacman", "-h"]),     0) # let through
        self.assertEqual(main(2, ["./304pacman", "--help"]), 0) # let through

class TestPacman(unittest.TestCase):
    def test_map_basic1(self):
        self.assertEqual(main(4, ["./304pacman", "tests/map3.txt", "*", " "]), 0)
    def test_map_basic2(self):
        self.assertEqual(main(4, ["./304pacman", "tests/map4.txt", "*", " "]), 0)
    def test_map_subject1(self):
        self.assertEqual(main(4, ["./304pacman", "tests/map1.txt", "*", " "]), 0)
    def test_map_subject2(self):
        self.assertEqual(main(4, ["./304pacman", "tests/map2.txt", "*", " "]), 0)
    def test_map_borderless(self):
        self.assertEqual(main(4, ["./304pacman", "tests/mapb.txt", "*", " "]), 0)
    def test_map_lshaped(self):
        self.assertEqual(main(4, ["./304pacman", "tests/mapl.txt", "*", " "]), 0)
    def test_map_boxed(self):
        self.assertEqual(main(4, ["./304pacman", "tests/mapi.txt", "*", " "]), 0)
    def test_arg_without_pacman(self):
        self.assertEqual(main(4, ["./304pacman", "tests/mapn.txt", "*", " "]), 84)

if (__name__ == '__main__') : exit(unittest.main())
