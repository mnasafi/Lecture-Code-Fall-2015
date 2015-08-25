#include <iostream>

using namespace std;

int fib(int n){
  if(n<2){
    return 1;
  }
  else{
    return fib(n-1)+fib(n-2);
  }
}

int main(){
  cout << fib(4) << "\n";
}
