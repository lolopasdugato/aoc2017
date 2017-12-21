/*
 * FileReader.tst.cpp
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include <algorithm>
#include <vector>
#include "catch/catch.hpp"
#include "FileReader.h"


TEST_CASE("Reading method", "[Public method]") {
    auto const reader       = InverseCaptcha::FileReader();
    auto const data         = reader.read("tests/resources/test-filereader");
    auto const expected     = std::vector<uint8_t> { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    auto const not_expected = std::vector<uint8_t> { 3, 8, 8, 6, 5, 4, 3, 2, 1, 0 };
    REQUIRE(std::equal(data.begin(), data.end(), expected.begin()));
    REQUIRE_FALSE(std::equal(data.begin(), data.end(), not_expected.begin()));
}

