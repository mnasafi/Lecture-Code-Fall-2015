#ifndef _Tree_h
#define _Tree_h

#include <iostream>
#include <queue>
using namespace std;

class Tree
{
  public:
    Tree() {m_root = NULL;}
    //Need Node's destructor to be recursive.
    ~Tree() {delete m_root; m_root = NULL;}
    bool insert(int value) {return insert(value, m_root);}
    bool lookup(int value) {return lookup(value, m_root);}
    void preorder(){preorder(m_root);}
    void inorder(){inorder(m_root);}
    void postorder(){postorder(m_root);}
    void breadth();
    int sumleaves(){return sumleaves(m_root);}
  private:
    class Node
    {
      public:
        Node(int value) {m_value = value; m_left = NULL; m_right = NULL;}
        //recursive destructor
        ~Node() {delete m_left; delete m_right;}
        int m_value;
        Node *m_left;
        Node *m_right;
    };
    Node *m_root;
    bool insert(int value, Node *&cur_root);
    bool lookup(int value, Node *cur_root);
    void inorder(Node* cur_root);
    void preorder(Node* cur_root);
    void postorder(Node* cur_root);
    int sumleaves(Node* cur_root);

};

#endif
