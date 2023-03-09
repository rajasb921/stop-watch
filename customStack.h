#ifndef MY_CUSTOM_STACK_H
#define MY_CUSTOM_STACK_H

#include <string>
#include <iostream>
#include "emptystack.h"

//the each stack node
template <typename T>
class SNode { 
public: // figure out friend class and making this private!!!
    T data; 
    SNode<T>* next; 
    //friend class StackLinkedList<T>; // provide StackLinkedList access
};

template <typename T> 
class StackLL { //gotta implement the stack as a singly linked list of elements
private:
    SNode<T>* top;
    std::string stack_empty;
    //OtherLinkedList<T> S; // alternative to SNode<T>* top;
    size_t n; //number of elements in stack

public:
    StackLL()
    : top(NULL){};
    ~StackLL(){
        while (top != NULL) {
        pop();
        }
    };
    
    bool empty() const;
    const T &show_top() const; // maybe const T (see Runner::addLapTimes()
    void print_stack() const; // for custom types
    void print_stack(bool builtin) const; //for builtin types
    int size() const;
    void push(T t);
    void pop();
};

template <typename T> 
bool StackLL<T>::empty() const { 
    return top == NULL;
}

template <typename T> 
void StackLL<T>::push(T t) {
    SNode<T>* node = new SNode<T>;
    node->data = t;
    node->next = top;
    top = node;
    ++n;
}

template <typename T>
void StackLL<T>::pop() { 
    if (empty())
        throw emptyStack();
    SNode<T>* node = top;
    top = top->next;
    delete (node);
    --n;
}

template <typename T>
const T &StackLL<T>::show_top() const { 
    if (empty())
        throw emptyStack(); 
    return top->data;
}

//overloaded to allow for built-in functions to use StackLL::print_stack
template <typename T>
void StackLL<T>::print_stack(bool builtin) const{ 
    SNode<T>* ptr;
    T obj;
    if (empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        for (ptr = top; ptr != NULL; ptr = ptr->next) {
            obj = ptr->data;
            std::cout << obj << " | "; //works for classes of built-in types
        }
        std::cout << std::endl;
    }
}

template <typename T>
void StackLL<T>::print_stack() const{ 
    SNode<T>* ptr;
    T obj;
    if (empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        for (ptr = top; ptr != NULL; ptr = ptr->next) {
            obj = ptr->data;
            obj.print();// works for classes with pre-defined print functions
        }
        std::cout << std::endl;
    }
}

template <typename T> 
int StackLL<T>::size() const {
    return n;
}

#endif
