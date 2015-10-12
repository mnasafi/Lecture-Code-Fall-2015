#include "istack.h"

#include <iostream>
using namespace std;

Istack::Istack(int size){
  m_size=size;
  m_values = new int[m_size];

  m_top=-1;
}

Istack::~Istack(){
  delete m_values;
}

void Istack::push(int value){
  //exceeded size of current array
  if(m_top+1==m_size){
    //create new larger array
    int *new_values = new int[m_size + 1];
    //copy values from old to new array
    for(int i=0;i<m_size;i++){
      new_values[i]=m_values[i];
    }
    //delete old array
    delete [] m_values;
    //give m_values address of new array
    m_values = new_values;
    //increase size
    m_size++;
  }
  //push value on the stack
  m_top++;
  m_values[m_top]=value;
}

bool Istack::pop(int &value){
  //Check if stack is empty
  if(m_top==-1){
    return false;
  }
  //grab element on top of the stack and assign to value
  value=m_values[m_top];
  m_top--;
  return true;

}
