/*
 * CaptchaSolver.h
 * Copyright (C) 2017 Loïc Benet <loic.benet.jca@gmail.com>
 *
 * Distributed under terms of the GPLv3 license.
 */

#ifndef INVERSE_CAPTCHA_INCLUDE_CAPTCHASOLVER_H_
#define INVERSE_CAPTCHA_INCLUDE_CAPTCHASOLVER_H_

#include <cstdint>
#include <forward_list>

namespace InverseCaptcha {

/**
 * @brief Class defining a captcha.
 */
class CaptchaSolver {
    std::forward_list<uint8_t> captcha;
 public:
    /**
     * @brief Captcha solver constructor.
     *
     * @param iCaptcha The captcha to work with.
     */
    explicit CaptchaSolver(std::forward_list<uint8_t> const& iCaptcha);

    /**
     * @brief Solves the captcha.
     *
     * @return The result of the captcha problem.
     */
    int solve() const;
};

};  // namespace InverseCaptcha

#endif  // INVERSE_CAPTCHA_INCLUDE_CAPTCHASOLVER_H_
