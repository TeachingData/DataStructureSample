//
// Created by JGreenwell on 4/5/2023.
//

#ifndef DATASTRUCTURESAMPLE_COURSES_HPP
#define DATASTRUCTURESAMPLE_COURSES_HPP

#include <array>
#include <iostream>
#include <algorithm>

class Courses {
public:
    // constant for possible courses
    static const inline std::array<std::string, 5> ALLCOURSES = {"COP 2006", "COP 3003", "COP 2001", "CEN 3031", "CNT 4104"};

    Courses()=default;

    std::string get_course();

    void display_choices(std::array<std::string, Courses::ALLCOURSES.size() - 2> to_display);
};


#endif //DATASTRUCTURESAMPLE_COURSES_HPP
