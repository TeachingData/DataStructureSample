//
// Created by JGreenwell on 4/5/2023.
//

#ifndef DATASTRUCTURESAMPLE_PERSON_HPP
#define DATASTRUCTURESAMPLE_PERSON_HPP

#include<string>

using std::string;

class Person {
private:
    int yob;
    long ssn;
    string name;
    int grade;

public:
    Person()=default;
    Person(int, long, string, int);

    int get_yearofbirth();
    string get_ssn();

    string get_firstname();
    string get_lastname();
    string get_fullname();

    string get_grade();

};


#endif //DATASTRUCTURESAMPLE_PERSON_HPP
