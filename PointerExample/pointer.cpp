#include <iostream>
#include <stdlib.h>

using namespace std;

void passbyvalue(int value){
  value = 4;
  return;
}

void passbypointer(int *value){
  *value = 5;
  return;
}

void passbyreference(int &value){
  value = 4;
  return;
}

int main(int argc, char* argv[]){
  int size = -1;
  int *x;
  while(size!=0){
    cout << "Enter Size (0 to quit):";
    cin >> size;
    x = new int(size);
    for(int i=0;i<size;i++){
      x[i]=i;
    }
    for(int i=0;i<size;i++){
      passbyvalue(x[i]);
      cout << x[i] << ", ";
      passbyreference(x[i]);
      cout << x[i] << ", ";
      passbypointer(&x[i]);
      cout << x[i] << endl;
    }
    delete x;
  }


}
