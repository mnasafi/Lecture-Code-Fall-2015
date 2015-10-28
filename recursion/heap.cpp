// recursive function f() is called three times
// f() has a local variable (local_variable) and a dynamically allocated
//     variable (ptr)
//
// f() prints the addresses of local_variable and the address returned by new
//
// this demonstrates how the stack grows one way and the heap grows another
// HOWEVER: heap is more complicated than this an does not always strictly
//          grow in one direction

#include <iostream>
using namespace std;

void f(int count)
{
    int local_variable;

    int *ptr = new int;

    cout << "start of f(), &local_variable = " << &local_variable
         << " ptr = " << ptr
         << " count = " << count << endl;

    if (count > 0)
    {
        f(count - 1);
    }
    cout << "end of f() count = " << count << endl;
}

int main()
{
    cout << "start of main()" << endl;
    f(500000);
    cout << "end of main()" << endl;

    return 0;
}
