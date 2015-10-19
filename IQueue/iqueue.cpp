#include "iqueue.h"
#include "assert.h"

Iqueue::Iqueue(int initial_size){
  assert(initial_size>0);
  m_max_size=initial_size;
  m_values = new int[m_max_size];
  m_size=0;
}

Iqueue::~Iqueue(){
  delete [] m_values;
}

void Iqueue::enqueue(int value){

  //special case of an empty queue
  if(m_size==0){
    m_values[0]=value;
    m_first=0;
    m_last=0;
    m_size=1;
    return;
  }
  //if array is full, double it
  if(m_size==m_max_size){
    int *new_values = new int[m_size*2];

    //new_i is the index in new array
    //old_i is the index in old array
    //copy in order from old to new
    for(int new_i=0,old_i=m_first;new_i<m_size;new_i++,old_i=(old_i+1)%m_size){
      new_values[new_i]=m_values[old_i];
    }
    m_first=0;
    m_last=m_size-1;
    delete [] m_values;
    m_values=new_values;
    m_max_size*=2;
  }
  // array is large enough to insert one value
  assert(m_size<m_max_size);
  m_last=(m_last+1)%m_max_size;
  m_values[m_last]=value;
  m_size++;
}

bool Iqueue::dequeue(int &value){
  if(m_size==0){
    return false;
  }
  value=m_values[m_first];
  m_first=(m_first+1)%m_max_size;
  m_size--;
  return true;
}

void Iqueue::print(){
  if(m_size!=0){
    for(int count=0, cur=m_first; count<m_size; count++, cur=(cur+1)%m_max_size){
      cout << m_values[cur] << " ";
    }
  }
  cout << endl;
}
