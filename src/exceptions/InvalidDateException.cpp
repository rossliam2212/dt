/**
 * @file InvalidDateException.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 28/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/exceptions/InvalidDateException.hpp"

namespace dt {
    /**
     * @brief @c InvalidDateException constructor.
     * @param message
     *          The exception message.
     */
    InvalidDateException::InvalidDateException(const char* message)
        : message{message} {
    }

    /**
     * @brief @c InvalidDateException constructor.
     * @param message
     *          The exception message.
     */
    InvalidDateException::InvalidDateException(const std::string& message)
        : message{message} {
    }

    /**
     * @brief Gets the exception message.
     * @return The exception message.
     */
    const char* InvalidDateException::what() const noexcept {
        return message.c_str();
    }
}