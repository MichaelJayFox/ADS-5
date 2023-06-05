// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
 private:
  int top;
  T* array;
 
 public:
  TStack() : top(-1) {array = new T[size];}
  void push(T value) {
      if (isFull()) {
          throw std::string("FULL!!!");
      } else {
          array[++top] = value;
      }
  }
  bool isEmpty() const {
    return top == -1;
  }
  const T& pop() {
      if (isEmpty())
          throw std::string("Stack is Empty!");
      else
          return array[top--];
  }
  bool isFull() const {
    return top == size - 1;
  }
  const T& get() const {
    return array[top];
  }
};
#endif  // INCLUDE_TSTACK_H_
