/*
 * FileReader.cpp
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#include "FileReader.h"

std::vector<int> InverseCaptcha::FileReader::read(std::string const& iFile) const {
    auto ifs    = std::ifstream(iFile);
    auto data   = std::vector<int>();
    auto c      = 'a';
    if (ifs.is_open()) {
        while (ifs.get(c)) {
            data.push_back(static_cast<int>(c - '0'));
        }
    }
    // Remove eof.
    data.pop_back();
    ifs.close();
    return data;
}
