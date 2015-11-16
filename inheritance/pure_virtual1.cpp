// Compare this program to pure_virtual2.cpp to see how to make the 
// Date::print() a pure virtual function
//

#include <iostream>
#include <string>
using namespace std;

class Date
{
    public:
        Date(string date);
        virtual void print( );
    protected:
        string m_date;
};

Date::Date(string date) 
{
    m_date = date;
}

void Date::print()
{
    cout << "date = " << m_date << endl;
}

class Time : public Date
{
    public:
        Time(string date, string time);
        void print();
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
    Date *date = new Date("4/24/08");
    cout << "printing Date *date\n";
    date->print();

    cout << "printing Date *time\n";
    Date *time = new Time("4/24/08", "2:00pm");
    time->print();
}









