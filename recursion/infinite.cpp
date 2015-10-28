#include <iostream>
using namespace std;
int count = 0;

void f()
{
    count++;
    cout << count << endl;
    f();
}

int main()
{
    f();
    return 0;
} 
