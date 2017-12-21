/*
 * main.cpp
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include <iostream>
#include <vector>
#include "CaptchaSolver.h"
#include "FileReader.h"

int main() {
    std::cout << "Solving inverse captcha problem...\n";
    auto const reader   = InverseCaptcha::FileReader();
    auto const data     = reader.read("resources/inverse-captcha");
    auto const solver   = InverseCaptcha::CaptchaSolver({ std::make_move_iterator(data.begin()), std::make_move_iterator(data.end()) });
    std::cout << "Result is " << solver.solve() << ".\n";
    return 0;
}
