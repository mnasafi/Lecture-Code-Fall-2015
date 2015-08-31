#include <iostream>

using namespace std;

#define max 10

int main(){
  int vals[max];
  int num=0;
  while(num<max){
    cin >>vals[num];
    if(vals[num]==0){
      break;
    }
    num++;
  }
  cout << endl;
  for(;num>=0;num--){
    cout << vals[num] << " ";
  }
  cout << endl;

}
