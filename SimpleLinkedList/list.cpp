#include <iostream>
using namespace std;

#include "list.h"

//create List
List::List(){
  m_head=NULL;
}
//destroy List
List::~List(){
  while(m_head!=NULL){
    Node* temp = m_head;
    m_head=m_head->m_next;
    delete temp;
  }
}
//Insert at front of List
void List::insert(int value){
  m_head=new Node(value, m_head);
}
void List::insertSorted(int value){
  //Combined null head & value less than head check
  if(!m_head||m_head->m_value>value){
    m_head=new Node(value,m_head);
  }
  else{
    Node* cur = m_head;
    while(cur->m_next&&cur->m_next->m_value<value){
      cur=cur->m_next;
    }
    cur->m_next=new Node(value, cur->m_next);
  }
}

void List::insertAtEnd(int value){
  if(m_head==NULL){
    m_head=new Node(value, m_head);
  }
  else{
    Node *cur = m_head;
    while(cur->m_next!=NULL){
      cur=cur->m_next;
    }
    cur->m_next=new Node(value, NULL);
  }
}
void List::print(){
  if(m_head!=NULL){
    Node* cur = m_head;
    while(cur!=NULL){
      cout << cur->m_value << " ";
      cur = cur->m_next;
    }
  }
  cout << endl;
}
