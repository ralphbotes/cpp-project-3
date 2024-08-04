# Date Class Project

## Overview

This project implements a `Date` class in C++ for managing and manipulating date objects. The class includes constructors, accessors, mutators, and operators for date calculation, taking leap years into account. The project also includes a main function to test the `Date` class functionalities.

## Class Declaration

```cpp
class Date {
public:
    // Constructors
    Date();
    Date(int day, int month, int year);

    // Accessors
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Mutators
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    // Operators to calculate next and previous days
    Date &operator++();
    Date &operator--();
    bool operator<(const Date &d);

private:
    // The current day, month, and year
    int theday;
    int themonth;
    int theyear;

    // Return the length of the current month, taking into account leap years
    int monthLength();
};
```

## Implementation Details
    - The default constructor initializes the date to 14 September 1752.
    - The overloaded constructor initializes the date with the given day, month, and year.
    - The functions getDay(), getMonth(), and getYear() return the current day, month, and year respectively.
    - The functions setDay(), setMonth(), and setYear() change the current day, month, or year to the given value.
    - The operator ++ advances the date by one day and returns the new date.
    - The operator -- sets the date back by one day and returns the new date.
    - The operator < calculates whether the receiving date object (left argument) precedes the parameter date (right argument).
    - The private member function monthLength() returns the length of the current month, taking into account leap years.
    - The insertion operator << is overloaded to output a date to the screen in the format: 14 September 1752.

## Testing
The Date class is tested with the following steps in the main function:

    1. Declare a new Date object called d1.
    2. Display the day, month, and year of d1 on the screen.
    3. Change the date to 28 February 2000.
    4. Advance this date by one and display the new date on the screen.
    5. Change the date to 1 January 2002.
    6. Set this date back by one and display the new date on the screen.
    7. Change the date to 31 December 2002.
    8. Advance this date by one and display the new date on the screen.
    9. Declare a second date object d2(1,1,2003).
    10. Determine if d1 is earlier than d2 and write the result on the screen.

## Compilation and Execution
    To compile and run the program in Code::Blocks:

    - Open Code::Blocks and create a new console application.
    - Add the Date class implementation and the main function in the appropriate source files.
    - Build and run the project.