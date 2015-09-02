#include <iostream>

using namespace std;
#include "my_object.h"

My_object::My_object(){
  My_object::x = 4;
}
void My_object::print(){
   cout << x << endl;
}
