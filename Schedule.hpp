//
// Created by JGreenwell on 3/27/2023.
//

#ifndef DATASTRUCTURESAMPLE_SCHEDULE_HPP
#define DATASTRUCTURESAMPLE_SCHEDULE_HPP

#include <chrono>
#include <iostream>
#include <iomanip>

class Schedule {
private:
    std::string get_today_date()
    {
        // have to use old school why here which is not thread safe
        // but I also just want date not time so only have to run once so meh.
        // if c++ 20 just use the string stream function that's built into chrono whole_time
        const auto whole_time = std::chrono::system_clock::now();
        const auto to_build_struct = std::chrono::system_clock::to_time_t(whole_time);

        std::stringstream just_date_str;

        struct tm strftime_str;
        const auto errno_value = localtime_s(&strftime_str, &to_build_struct);
        if(errno_value != 0)
        {
            throw std::runtime_error("localtime_s() failed: " + std::to_string(errno_value));
        }

        just_date_str << std::put_time(&strftime_str, "%Y-%m-%d");
        return just_date_str.str();
    }

public:
    std::string today;

    Schedule() {
        today = get_today_date();
    }
};


#endif //DATASTRUCTURESAMPLE_SCHEDULE_HPP
