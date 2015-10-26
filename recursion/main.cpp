#include <iostream>
using namespace std;

findLargest(Node *cur, int &max){
  if(cur){
    if(cur->m_value>max){
      max=cur->m_value;
    }
    findLargest(cur->m_next,max);
  }
}

bool findValue(Node* cur, int value){
  if(cur){
    if(cur->m_value==value){
      return true;
    }
    else{
      return findValue(cur->m_next, value);
    }
  }
  else{
    return false;
  }
}

int sumNodes(Node* cur){
  if(cur){
    return cur->m_value + sumNodes(cur->next);
  }
  else{
    return 0;
  }
}

bool palindrome(char *str, int size){
  if(size<=1){
    return true;
  }
  if(str[0]!=str[size-1]){
    return false;
  }
  return palindrome(str+1,size-2);
}

int main(){
  int max =0;
  findLargest(head,max);

  cout << max << endl;

  cout << findValue(head, 5) << endl;

  cout << sumNodes(head) << endl;
}
