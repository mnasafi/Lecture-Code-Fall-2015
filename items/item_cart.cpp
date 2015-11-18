#include <iostream>
#include <vector>
using namespace std;

class Item{
  public:
    Item(string desc);
    virtual void print();
  protected:
    string m_desc;
};

Item::Item(string desc){
  m_desc=desc;
}

void Item::print(){
  cout << m_desc << endl;
}

class Cold_item : public Item{
  public:
    Cold_item(string desc, int temp);
    void print();
  protected:
    int m_temp;
};

Cold_item::Cold_item(string desc, int temp) : Item(desc){
  m_temp=temp;
}

void Cold_item::print(){
  cout << m_desc << " at " << m_temp << " degrees\n";
}

class Perishable : public Item {
  public:
    //description and sell by date arguments
    Perishable(string desc, string sbd);
    void print();
  protected:
    string m_sbd;
};

Perishable::Perishable(std::string desc, string sbd) : Item(desc){
  m_sbd = sbd;
}

void Perishable::print(){
  cout << m_desc << " should be sold by: " << m_sbd << endl;
}

class Vegetable : public Perishable{
  public:
    Vegetable(string desc, string sbd, bool tasty);
  //  void print();
  protected:
    bool m_tasty;
};

Vegetable::Vegetable(string desc, string sbd, bool tasty) : Perishable(desc,sbd){
  m_tasty=tasty;
}

class Cart{
  public:
    void insert(Item* item);
    void print();
  private:
    std::vector<Item*> m_items;
};

void Cart::insert(Item* item){
  m_items.push_back(item);
}

void Cart::print(){
  /* Conventional For Loop Approach
  for(int i=0; i<m_items.size();i++){
    m_items[i]->print();
  }*/
  vector<Item *>::iterator iter;
  for(iter=m_items.begin(); iter!=m_items.end(); iter++){
    //(*iter)->print();
    Item *cur_item = *iter;
    cur_item->print();
  }

}

int main(){
  Cart cart;
  cart.insert(new Item("Bag of Holding"));
  cart.insert(new Cold_item("Ice Cream", 0));
  cart.insert(new Perishable("Milk", "11/20/2015"));
  cart.insert(new Vegetable("Green Bean", " 11/19/2015", false));
  cart.print();
}
