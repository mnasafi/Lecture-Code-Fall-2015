#include <iostream>
using namespace std;

#include "list.h"

int main(){
  List list;

  list.print();
  list.insertSorted(4);
  list.print();
  list.insertSorted(2);
  list.print();
  list.insertSorted(3);
  list.print();
  list.insertSorted(6);
  list.print();
}
