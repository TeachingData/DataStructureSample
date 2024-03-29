//
// Created by JGreenwell on 4/5/2023.
//

#ifndef DATASTRUCTURESAMPLE_PERSON_HPP
#define DATASTRUCTURESAMPLE_PERSON_HPP

#include<iostream>
#include<array>
#include "Schedule.hpp"

using std::string;

class Person {
private:
    // using this as an example - not recommended usage for struct
    const std::array<std::string, 4> PERSONCATS = {"year of birth", "ssn", "name", "grade"};

    int yob;
    long ssn;
    string name;
    int grade;
    int age;

    Schedule schedule;
    void calc_age();
public:
    Person()=default;
    Person(int, long, string, int);

    void set_student();
    int get_yearofbirth();
    string get_ssn();
    int get_age();

    string get_firstname();
    string get_lastname();
    string get_fullname();

    string get_grade();
};


#endif //DATASTRUCTURESAMPLE_PERSON_HPP
