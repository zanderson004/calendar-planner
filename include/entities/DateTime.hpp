#pragma once

#include "interfaces/IDateTime.hpp"

/// @brief Implementation of a basic date and time object
class DateTime : public IDateTime {
    private:
        /// @brief Stores the seconds since 00:00:00 UTC 1/1/1970 as an int
        int m_unixTime;
        
    public:
        /// @brief Construct object with specified date and time value
        /// @param unixTime Seconds since 00:00:00 UTC 1/1/1970
        DateTime(int unixTime);

        const std::string toString() const override;
        int getTime() const override;
        void setTime(int unixTime) override;
};