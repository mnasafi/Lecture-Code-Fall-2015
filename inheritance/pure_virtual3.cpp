// Compare this program to pure_virtual2.cpp 
//  the only change is the instantiation of Date is commented out

#include <iostream>
#include <string>
using namespace std;

class Date
{
    public:
        Date(string date);
        virtual void print() = 0; // now print is a pure virtual function
    protected:
        string m_date;
};

Date::Date(string date) 
{
    m_date = date;
}

// this use to cause a compiler error because of the "= 0" above
// the "= 0" makes print a pure virtual function
// when you provide a body it is ignored
void Date::print()
{
    cout << "date = " << m_date << endl;
}

class Time : public Date
{
    public:
        Time(string date, string time);
        /* virtual */ void print();
    private:
        string m_time;
};

Time::Time(string date, string time) : Date(date)
{
    m_time = time;
}

void Time::print()
{
    cout << "time = " << m_date << " " << m_time << endl;
}

int main()
{
    // can't instantiate an abstract class (one w/a purely virtual function)
    // Date *date = new Date("4/24/08");
    // date->print();

    Date *ptr = new Time("4/24/08", "2:00pm");
    ptr->print();
}
