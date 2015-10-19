#include <iostream>
using namespace std;

#include "iqueue.h"

int main(){
  Iqueue *queue=new Iqueue(2);

  queue->enqueue(1);
  queue->print();
  queue->enqueue(2);
  queue->print();
  queue->enqueue(3);
  queue->print();
  queue->enqueue(4);
  queue->print();
  int value;
  if(queue->dequeue(value)){
    cout << value << endl;
  }
  queue->print();
  if(queue->dequeue(value)){
    cout << value << endl;
  }
  queue->print();
}
