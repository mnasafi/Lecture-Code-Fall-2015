#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    float value;
    while(cin.peek()!=EOF){
      if(isdigit(cin.peek())){
        cin >> value;
        if(cin.good()){
          cout << "success " << value << endl;
        }
        else{
          cout << "failure " << value << endl;
        }
      }
      else if(isspace(cin.peek())){
        cin.ignore();
        cout << "space" << endl;
      }
      else if(cin.peek()=='.'){
        cin>>value;
        cout << "dot " <<value << endl;
      }
      else{
        cin.ignore();
      }
    }
}
