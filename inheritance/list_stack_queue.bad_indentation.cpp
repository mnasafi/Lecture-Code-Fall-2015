// this file is a copy of list_stack_queue.cpp with all the spaces
// at the start of the line removed
// The intention is to demonstrate that it is harder to read a program with
// bad spacing



/***
This file demonstrates inheritance.

class Dlist is a list of doubles.

class Dqueue is a queue of doubles.  
It inherits class Dlist

class Dstack is a stack of doubles.  
It inherits class Dlist

***/

#include <iostream>
using namespace std;

class Dlist
{
public:
Dlist() {m_head = 0;}
void insert_front(double value);
void insert_back(double value);
bool remove_front(double &value);
protected:
class Node
{
public:
Node(double value, Node *next) 
{m_value = value; m_next = next;}
double m_value;
Node *m_next;
};
Node *m_head;
Node *m_tail;
};

void 
Dlist::insert_front(double value)
{
m_head = new Node(value, m_head);
if (m_head->m_next == 0)
m_tail = m_head;
}
void 
Dlist::insert_back(double value)
{
if (m_head == 0)
insert_front(value);
else
{
m_tail->m_next = new Node(value, 0);
m_tail = m_tail->m_next;
}
}

bool 
Dlist::remove_front(double &value)
{
if (m_head == 0)
return false;
value = m_head->m_value;
Node *tmp = m_head;
m_head = m_head->m_next;
delete tmp;
return true;
}

class Dqueue : protected Dlist
{
public:
Dqueue() {}
void enqueue(double value);
bool dequeue(double &value);
};

void Dqueue::enqueue(double value)
{
insert_back(value);
}
bool Dqueue::dequeue(double &value)
{
return remove_front(value);
}

class Dstack : protected Dlist
{
public:
Dstack() {}
void push(double value);
bool pop(double &value);
bool empty();
};

void Dstack::push(double value)
{
insert_front(value);
}
bool Dstack::pop(double &value)
{
return remove_front(value);
}

bool 
Dstack::empty()
{
if (m_head == 0)
return true;
else return false;

// the above code is the same as
// return m_head == 0
}

int main()
{
double value;

// declare a queue & enqueue 10 numbers
Dqueue queue;
for (int i = 0; i < 10; i++)
queue.enqueue(i);

cout << "printing queue" << endl;
// as long as there are values on the queue, remove them and print them
while (queue.dequeue(value))
cout << value << endl;


// declare a stack & push 10 numbers
Dstack stack;
for (int i = 0; i < 10; i++)
stack.push(i);

cout << "printing stack" << endl;
// as long as there are values on the stack, remove them and print them
while (stack.pop(value))
cout << value << endl;
}









