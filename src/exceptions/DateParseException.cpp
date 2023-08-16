/**
 * @file DateParseException.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 31/07/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/exceptions/DateParseException.hpp"

namespace dt {
    /**
     * @brief @c DateParseException constructor.
     * @param message
     *          The exception message.
     */
    DateParseException::DateParseException(const char* message)
        : message{message} {
    }

    /**
     * @brief @c DateParseException constructor.
     * @param message
     *          The exception message.
     */
    DateParseException::DateParseException(const std::string& message)
        : message{message} {
    }

    /**
     * @brief Gets the exception message.
     * @return The exception message.
     */
    const char* DateParseException::what() const noexcept {
        return message.c_str();
    }
}
