/**
 * @file InvalidTimeException.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 29/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/exceptions/InvalidTimeException.hpp"

namespace dt {
    /**
     * @brief @c InvalidTimeException constructor.
     * @param message
     *          The exception message.
     */
    InvalidTimeException::InvalidTimeException(const char* message)
        : message{message} {
    }

    /**
     * @brief @c InvalidTimeException constructor.
     * @param message
     *          The exception message.
     */
    InvalidTimeException::InvalidTimeException(const std::string& message)
        : message{message} {
    }

    /**
     * @brief Gets the exception message.
     * @return The exception message.
     */
    const char* InvalidTimeException::what() const noexcept {
        return exception::what();
    }
}