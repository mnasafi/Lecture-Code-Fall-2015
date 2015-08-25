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
  int x;
  cout << "Enter desired fibonacci number: ";
  cin >> x;
  cout << fib(x) << "\n";
}
