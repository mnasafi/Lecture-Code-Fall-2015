#include <iostream>
using namespace std;

#include "list.h"

int main(){
  List list;

  list.print();
  list.insert(1);
  list.print();
  list.insert(2);
  list.print();
  list.insert(3);
  list.print();
}
