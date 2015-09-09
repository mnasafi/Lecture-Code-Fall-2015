#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
  int size = 0;
  if(argc>1){
    size = atoi(argv[1]);
  }
  int x[size];
  for(int i=0;i<size;i++){
    x[i]=i;
  }
  for(int i=0;i<size;i++){
    cout << x[i] << endl;
  }

}
