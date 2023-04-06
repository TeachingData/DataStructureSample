//
// Created by JGreenwell on 4/5/2023.
//

#include "Courses.hpp"

// let's assume you can only choose 2 choices less than the number offered - electives and what not
std::string Courses::get_course() {
    // set a temp variable to check if course is valid
    std::string course;

    for (auto c : ALLCOURSES) {
        // print each course and ask if this is it
        // not efficient, but we'll refactor later

        std::cout << "Is " << c << " a course your taking this semester? (y/n) ";
        std::getline(std::cin>>std::ws, course);
        // note - getline also eats the \n so no ignore needed
        // however windows needs to also remove \r so change a bit here
        // also removing leading whitespace

        // TODO: fix error below (most students missed it cause they use [] for index)
        // Leaving broken for students to debug as practice (hint: its not the index its the leftover bits on istream)
        if (std::tolower(course.at(0)) == 'y') {
            return c;
        }
    }
    return "";
}

void Courses::display_choices(std::array<std::string, ALLCOURSES.size()-2> to_display) {
    std::cout << "Your " << to_display.size() << " choices were (from lowest to highest):\n";
    std::sort(to_display.begin(), to_display.end());

    for (const auto &e : to_display) {
        std::cout << e << "\n";
    }
}