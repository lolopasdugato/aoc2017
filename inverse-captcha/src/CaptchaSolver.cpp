/*
 * CaptchaSolver.cpp
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "CaptchaSolver.h"
#include <iostream>

InverseCaptcha::CaptchaSolver::CaptchaSolver(std::forward_list<uint8_t> const& iCaptcha) : captcha(iCaptcha) {
}

int InverseCaptcha::CaptchaSolver::solve() const {
    auto sum    = 0;
    auto next   = captcha.cbegin();
    for (auto it = captcha.cbegin(); it != captcha.cend(); ++it) {
        next = (++next != captcha.end()) ? next : captcha.cbegin();
        sum += (*it == *next) ? *it : 0;
    }
    return sum;
}
