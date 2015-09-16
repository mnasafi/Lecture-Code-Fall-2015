#ifndef LIST_H
#define LIST_H

class List{
  public:
    List();
    ~List();
    void insert(int value);
    void insertAtEnd(int value);
    void insertSorted(int value);
    void print();
  private:
    class Node{
      public:
        int m_value;
        Node *m_next;
        Node(int value, Node *next){
          m_value=value;
          m_next=next;
        }
    };
    Node *m_head;
};

#endif
