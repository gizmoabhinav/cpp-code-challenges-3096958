// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

const unsigned char month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int year) {
    if (year%4 != 0) {
        return false;
    } else if (year%100 != 0) {
        return true;
    } else if (year%400 != 0) {
        return false;
    } else {
        return true;
    }
}

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    time_t now = time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    today_d = tstruct.tm_mday;
    today_m = tstruct.tm_mon + 1;
    today_y = tstruct.tm_year + 1900;

    // days left in birth year
    int days_left_in_month = month_days[birth_m-1]-birth_d;
    int days_left_in_year = 0;
    for (int i=birth_m;i<12;i++) {
        days_left_in_year += month_days[i];
    }
    if (is_leap_year(birth_y)) {
        if (birth_m == 2) {
            days_left_in_month += 1;
        }
        if (birth_m == 1) {
            days_left_in_year += 1;
        }
    }

    // days completed in current year
    int days_completed_last_month = 0;
    for (int i=0;i<today_m-1;i++) {
        days_completed_last_month += month_days[i];
    }
    if (is_leap_year(today_y)) {
        if (today_m > 2) {
            days_completed_last_month += 1;
        }
    }

    // days in intermediate years
    int intermediate_year_days = 0;
    for (int i=birth_y+1;i<today_y;i++) {
        if (is_leap_year(i)) {
            intermediate_year_days += 366;
        } else {
            intermediate_year_days += 365;
        }
    }

    age = days_left_in_month + days_left_in_year + intermediate_year_days + days_completed_last_month + today_d;

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
