#ifndef IQUEUE_H
#define IQUEUE_H

#include <iostream>
using namespace std;

class Iqueue{
  public:
    Iqueue(int initial_size);
    ~Iqueue();
    void enqueue(int value);
    bool dequeue(int &value);
    void print();
    bool empty(){return m_size==0;}
  private:
    int m_size; // the number of elements in the queue
    int m_first; // index to first element in queue (front)
    int m_last; // index to end of queue
    int m_max_size; // size of array
    int *m_values; // int pointer to act as array pointer
};

#endif
