//
// Created by JGreenwell on 4/5/2023.
//

#include "Person.hpp"

Person::Person(int yob, long ssn, string name, int grade) {
    this->yob = yob;
    this->ssn = ssn;
    this->name = name;
    this->grade = grade;
}

int Person::get_yearofbirth() {
    return yob;
}

string Person::get_ssn() {
    return "***********";
}

string Person::get_grade() {
    return std::to_string(grade);
}

string Person::get_firstname() {
    return std::string();
}

string Person::get_lastname() {
    return std::string();
}

string Person::get_fullname() {
    return name;
}


