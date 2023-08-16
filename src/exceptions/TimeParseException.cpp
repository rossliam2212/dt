/**
 * @file TimeParseException.cpp
 * @author liam (rossliam2212[at]gmail.com)
 * @date 01/08/2023
 * @copyright Copyright (c) 2023 liam under MIT licence.
 */

#include "../../include/dt/exceptions/TimeParseException.hpp"

namespace dt {
    /**
     * @brief @c TimeParseException constructor.
     * @param message
     *          The exception message.
     */
    TimeParseException::TimeParseException(const char* message)
        : message{message} {
    }

    /**
     * @brief @c TimeParseException constructor.
     * @param message
     *          The exception message.
     */
    TimeParseException::TimeParseException(const std::string& message)
        : message{message} {
    }

    /**
     * @brief Gets the exception message.
     * @return The exception message.
     */
    const char* TimeParseException::what() const noexcept {
        return message.c_str();
    }
}