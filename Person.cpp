//
// Created by JGreenwell on 4/5/2023.
//

#include <limits>
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

int Person::set_student() {
        for (int i=0; i<PERSONCATS.size(); i++) {
            std::cout << "Please enter your " << PERSONCATS[i] << ": ";

            switch(i) {
                case 0:
                    std::cin >> std::ws;
                    std::cin >> yob;
                    std::cin.ignore(1000, '\n');
                    break;
                case 1:
                    std::cin >> std::ws;
                    std::cin >> ssn;
                    std::cin.ignore(1000, '\n');
                    break;
                case 2:
                    std::getline(std::cin>>std::ws, name);
                    break;
                case 3:
                    std::cin >> std::ws;
                    std::cin >> grade;
                    // #include <limits>
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                default:
                    std::cout << "Invalid option";
            }
        }
}


