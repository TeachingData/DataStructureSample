#include <iostream>
#include <array>
#include <algorithm>
#include "Person.hpp"
#include "Courses.hpp"

// prototypes
bool check_if_more(const std::string&, std::string);

int main() {
  Courses allcourses = Courses();
  Person student = Person();
  student.set_student();
  std::cout << "Welcome " << student.get_fullname() << "!\n";
  std::cout << "You are " << student.get_age() << "years old\n";

  // setup array with 3 0 values (for now)
  // We are now going to shift this to a string array of "courses"
  // let's assume you can only choose 2 choices less than the number offered - electives and what not
  // TODO: Integrate this with People (composite field? or just vector?)
  std::array<std::string, allcourses.ALLCOURSES.size()-2> courses{};
  int count = 0;

  while(count < courses.size()) {
    std::string course = allcourses.get_course();
    if (!course.empty()) {
        courses[count] = course;
        count++;
    }

    if (!check_if_more("Would you like to continue? (Y to continue)", "Y")) {
      break;
    }
  }

  // Let's use a basic algorithm from the algorithm library to sort our array then print it
  allcourses.display_choices(courses);
}

bool check_if_more(const std::string& question, std::string continue_option) {
  std::string user_choice;

  std::cout << question;
  std::cin >> std::ws;
  std::cin >> user_choice;
  std::cin.ignore(1000, '\n'); // remove newline, getline is better
  // would use getline - leaving as example of all the ways

  // cheat with toupper (uses a char)
  if (std::toupper(user_choice[0]) == continue_option[0]) {
    return true;
  }
  return false;
}