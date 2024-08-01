#include "entities/DateTime.hpp"

#include <sstream>
#include <iomanip>

DateTime::DateTime(int unixTime):
    m_unixTime{unixTime} {}

DateTime::DateTime(int year, int month, int day, int hour, int minute) {
    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    DateTime(std::mktime(&timeinfo));
}

const std::string DateTime::toString() const {
    std::ostringstream oss;
    time_t time = m_unixTime;
    oss << std::put_time(std::localtime(&time), "%d/%m/%Y %I:%M:%S %p");
    std::string formattedTime = oss.str();
    return formattedTime;
}

void DateTime::setTime(int unixTime) {
    m_unixTime = unixTime;
}

int DateTime::getTime() const {
    return m_unixTime;
}

std::unique_ptr<IDateTime> DateTime::clone() const {
    return std::make_unique<DateTime>(*this);
}