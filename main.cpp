#include <iostream>
#include <array>
#include <algorithm>
#include "Person.hpp"


// constant for possible courses
const std::array<std::string, 5> ALLCOURSES = {"COP 2006", "COP 3003", "COP 2001", "CEN 3031", "CNT 4104"};

// prototypes
// let's assume you can only choose 2 choices less than the number offered - electives and what not
std::string get_course();
bool check_if_more(const std::string&, std::string);
void display_choices(std::array<std::string, ALLCOURSES.size()-2>);

int main() {
  Person student = Person();
  student.set_student();
  std::cout << "Welcome " << student.get_fullname() << "!\n";
  std::cout << "You are " << student.get_age() << "years old\n";

  // setup array with 3 0 values (for now)
  // We are now going to shift this to a string array of "courses"
  // let's assume you can only choose 2 choices less than the number offered - electives and what not
  std::array<std::string, ALLCOURSES.size()-2> courses{};
  int count = 0;

  while(count < courses.size()) {
    std::string course = get_course();
    if (!course.empty()) {
        courses[count] = course;
        count++;
    }

    if (!check_if_more("Would you like to continue? (Y to continue)", "Y")) {
      break;
    }
  }

  // Let's use a basic algorithm from the algorithm library to sort our array then print it
  display_choices(courses);
}

std::string get_course() {
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

        if (std::tolower(course[0]) == 'y') {
            return c;
        }
    }
    return "";
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

void display_choices(std::array<std::string, ALLCOURSES.size()-2> to_display) {
  std::cout << "Your " << to_display.size() << " choices were (from lowest to highest):\n";
  std::sort(to_display.begin(), to_display.end());

  for (const auto &e : to_display) {
    std::cout << e << "\n";
  }
}