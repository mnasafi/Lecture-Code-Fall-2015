#include "tree.h"


bool Tree::insert(int value, Node *&cur_root){
  if(!cur_root){
    cur_root = new Node(value);
    return true;
  }
  if(value == cur_root->m_value){
    return false;
  }
  if(value < cur_root->m_value){
    return insert(value, cur_root->m_left);
  }
  if(value > cur_root->m_value){
    return insert(value, cur_root->m_right);
  }
  return false;
}
bool Tree::lookup(int value, Node *cur_root){
  if(!cur_root){
    return false;
  }
  if(value == cur_root->m_value){
    return true;
  }
  if(value < cur_root->m_value){
    return lookup(value, cur_root->m_left);
  }
  if(value > cur_root->m_value){
    return lookup(value, cur_root->m_right);
  }
  return false;
}

void Tree::inorder(Node* cur_root){
  if(!cur_root){
    return;
  }
  inorder(cur_root->m_left);
  cout << cur_root->m_value << " ";
  inorder(cur_root->m_right);
}
void Tree::preorder(Node* cur_root){
  if(!cur_root){
    return;
  }
  cout << cur_root->m_value << " ";
  preorder(cur_root->m_left);
  preorder(cur_root->m_right);
}
void Tree::postorder(Node* cur_root){
  if(!cur_root){
    return;
  }
  postorder(cur_root->m_left);
  postorder(cur_root->m_right);
  cout << cur_root->m_value << " ";
}

void Tree::balance(Node *&cur_root){
  if(!cur_root){
    return;
  }
  std::vector<int> v;
  values(cur_root, v);
  delete cur_root;
  balance(m_root, v, 0, v.size()-1);
}
void Tree::balance(Node *&cur_root, vector<int> v, int start, int stop){

  if(start==stop){
    cur_root=new Node(v[start]);
    return;
  }
  int middle = (stop-start)/2 + start;
  //cout << middle << endl;
  cur_root=new Node(v[middle]);
  balance(cur_root->m_left, v, start,middle-1);
  balance(cur_root->m_right, v, middle+1, stop);
}

void Tree::values(Node* cur_root, std::vector<int> &v){
  if(!cur_root){
    return;
  }
  values(cur_root->m_left, v);
  v.push_back(cur_root->m_value);
  values(cur_root->m_right,v);
}

void Tree::breadth(){
  if(!m_root){
    return;
  }
  queue<Node*> q;
  q.push(m_root);
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    cout << temp->m_value << " ";
    if(temp->m_left){
      q.push(temp->m_left);
    }
    if(temp->m_right){
      q.push(temp->m_right);
    }
  }

}

int Tree::sumleaves(Node* cur_root){
  if(!cur_root){
    return 0;
  }
  if(!cur_root->m_left && !cur_root->m_right){
    return cur_root->m_value;
  }
  return sumleaves(cur_root->m_left)+sumleaves(cur_root->m_right);
}

int main(){
  Tree tree;
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);
  tree.insert(7);
  tree.insert(8);
  tree.insert(9);
  tree.balance();
  for(int i=0;i<20;i++){
    if(tree.lookup(i)){
      cout << i << " is in tree\n";
    }
  }

  tree.inorder();
  cout << endl;
  tree.preorder();
  cout << endl;
  tree.postorder();
  cout << endl;
  tree.breadth();
  cout << endl;
  cout << tree.sumleaves() << endl;
}
