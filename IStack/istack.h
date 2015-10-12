#ifndef ISTACK_H
#define ISTACK_H

class Istack{
  public:
    Istack(int size);
    ~Istack();
    void push(int value);
    bool pop(int &value);
  private:
    int m_size;
    int m_top;
    int *m_values;
};

#endif
