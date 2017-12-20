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
    auto const solver = InverseCaptcha::CaptchaSolver({ 1, 1, 2, 2 });
    REQUIRE(solver.solve() == 3);
}
