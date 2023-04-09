// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
 private:
  int top;
  T *arr;
 
 public:
  TStack() : top(-1) {array=new T[size];}
  void push(T value) {
      if (isFull()) {
          throw std::string("FULL!!!");
      } else {
          arr[++top] = value;
      }
  }
  const T& pop() {
      if (isEmpty())
          throw std::string("Stack is Empty!");
      else
          return arr[top--];
  }
  bool isEmpty() const {
    return top == -1;
  }
  bool isFull() const {
    return top == size - 1;
  }
  T get() const {
    return arr[top];
  }
};

#endif  // INCLUDE_TSTACK_H_
