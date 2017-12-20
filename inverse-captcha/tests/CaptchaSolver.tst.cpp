/*
 * CaptchaSolver.tst.cpp
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

#include "CaptchaSolver.h"

TEST_CASE("Solving method", "[Public method]") {
    auto const solver1 = InverseCaptcha::CaptchaSolver({ 1, 1, 2, 2 });
    auto const solver2 = InverseCaptcha::CaptchaSolver({ 1, 1, 1, 1 });
    auto const solver3 = InverseCaptcha::CaptchaSolver({ 1, 2, 3, 4 });
    auto const solver4 = InverseCaptcha::CaptchaSolver({ 9, 1, 2, 1, 2, 1, 2, 9 });
    REQUIRE(solver1.solve() == 3);
    REQUIRE(solver2.solve() == 4);
    REQUIRE(solver3.solve() == 0);
    REQUIRE(solver4.solve() == 9);
}
