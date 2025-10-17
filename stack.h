#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> //use private here because we don't really want the users to have access to the real vector operations
{
public:
    Stack()
    {

    }
    ~Stack()
    {

    }
    bool empty() const{
      return std::vector<T>::empty();
    }
    size_t size() const{
      return std::vector<T>::size();
    }
    void push(const T& item){
      std::vector<T>::push_back(item);
    }
    void pop(){ // throws std::underflow_error if empty
      if(this->empty()){
        throw std::underflow_error("Stack Underflow");
      }
      std::vector<T>::pop_back();
    } 
    const T& top() const{ // throws std::underflow_error if empty
      if(this->empty()){
        throw std::underflow_error("Stack Underflow");
      }
      return std::vector<T>::back();
    } 
    // Add other members only if necessary
};


#endif