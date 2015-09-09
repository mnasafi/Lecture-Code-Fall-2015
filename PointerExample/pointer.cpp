#include <iostream>
#include <stdlib.h>

using namespace std;

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
      cout << x[i] << endl;
    }
    delete x;
  }


}
