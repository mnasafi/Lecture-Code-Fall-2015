#include "istack.h"

#include <iostream>
using namespace std;

int main(){
  Istack stack(5);

  for(int i=0; i<100; i++){
    stack.push(i);
  }

  int value;
  while(stack.pop(value)){
    cout << value << endl;
  }
  return 0;
}
