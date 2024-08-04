#include <iostream>
#include <string>

using namespace std;

class Date{
    public:
        //constructors
        Date() : theday(14), themonth(9), theyear(1752) {};
        Date(int day, int month, int year) : theday(day), themonth(month), theyear(year) {};

        //accessors
        int getDay() const {
            return theday;
        };
        int getMonth() const {
            return themonth;
        };
        int getYear() const {
            return theyear;
        };

        //mutators
        void setDay(int day) {
            theday = day;
        };
        void setMonth(int month) {
            themonth = month;
        };
        void setYear(int year) {
            theyear = year;
        };

        // Friend functions to overload operators
        friend Date& operator++(Date& date);
        friend Date& operator--(Date& date);
        friend bool operator<(const Date& d1, const Date& d2);
        friend ostream& operator<<(ostream& os, const Date& date);

    private:
        //the current day month and year
        int theday;
        int themonth;
        int theyear;

        //return the length of current month, taking into account leap years
        int monthLength() {
            // February is the weird one
            if (themonth == 2) {
                if ((theyear % 4 == 0 && theyear % 100 != 0) || (theyear % 400 == 0)) {
                    return 29;
                } else {
                    return 28;
                }
            } else if (themonth == 4 || themonth == 6 || themonth == 9 || themonth == 11) {
                // 30 day months (April, June, September, November)
                return 30;
            }

            // No else neccessary as if this part is reached, it is a 31 day month
            return 31;
        };
};

// friend functions of class Date
Date& operator++(Date& date) {
    ++date.theday;
    if (date.theday > date.monthLength()) {
        date.theday = 1;
        ++date.themonth;
        if (date.themonth > 12) {
            date.themonth = 1;
            ++date.theyear;
        }
    }
    return date;
};
Date& operator--(Date& date) {
    --date.theday;
    if (date.theday < 1) {
        date.theday = date.monthLength();
        --date.themonth;
        if (date.themonth < 1) {
            date.themonth = 12;
            --date.theyear;
        }
    }
    return date;
};
bool operator<(const Date& d1, const Date& d2) {
    // Receiving date is object date
    // Parameter date is given parameter d date
    // Example: thedate(1,1,2002) < d(1,3,2002)

    // First check years
    if (d1.theyear < d2.theyear) {
        return true;
    } else if (d1.theyear > d2.theyear) {
        return false;
    } else if (d1.themonth < d2.themonth) {      // Up to this point, years are the same, now check months
        return true;
    } else if (d1.themonth > d2.themonth) {
        return false;
    } else if (d1.theday > d2.theday) {      // Up to this point, months are the same, now check days
        return false;
    }
    // Time not available to check, so at the end of the day, all that remains is true
    return true;
};

// Overload the << operator
ostream& operator<<(ostream& os, const Date& date) {
    static const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    os << date.theday << " " << months[date.themonth - 1] << " " << date.theyear;
    return os;
}

int main()
{
    // Declare a new Date object called d1.
    Date d1;

    // Display the day, month and year of d1 on the screen.
    cout << "d1 date: " << d1 << endl;

    // Change the date to 28 February 2000.
    d1.setDay(28);
    d1.setMonth(2);
    d1.setYear(2000);

    // Advance this date by one and display the new date on the screen.
    ++d1;
    cout << "d1 date: " << d1 << endl;

    // Now change the date to 1 January 2002.
    d1.setDay(1);
    d1.setMonth(1);
    d1.setYear(2002);

    // Set this date back by one and display the new date on the screen.
    --d1;
    cout << "d1 date: " << d1 << endl;

    // Finally change the date to 31 December 2002.
    d1.setDay(31);
    d1.setMonth(12);
    d1.setYear(2002);

    // Advance this date by one and display the new date on the screen.
    ++d1;
    cout << "d1 date: " << d1 << endl;

    // Declare a second date object d2(1,1,2003).
    Date d2(1, 1, 2003);

    // Determine if d1 is earlier than d2 and write the result on the screen.
    if (d1 < d2) {
        cout << "d1 is earlier than d2" << endl;
    } else {
        cout << "d1 is not earlier than d2" << endl;
    }

    return 0;
}
