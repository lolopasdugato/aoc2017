/*
 * FileReader.h
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef INVERSE_CAPTCHA_INCLUDE_FILEREADER_H_
#define INVERSE_CAPTCHA_INCLUDE_FILEREADER_H_

#include <fstream>
#include <vector>
#include <string>

namespace InverseCaptcha {

/**
 * @brief Class reading a file for input resources.
 */
class FileReader {
 public:
     /**
      * @brief Reads the specified file to extract data.
      *
      * @param iFile The file path.
      *
      * @return The data to extract.
      */
    std::vector<int> read(std::string const& iFile) const;
};

};  // namespace InverseCaptcha

#endif  // INVERSE_CAPTCHA_INCLUDE_FILEREADER_H_
