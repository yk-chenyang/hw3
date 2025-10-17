#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  // Helper functions to deal with the special characteristics of a m-ary heap
  size_t parentIdx(size_t i) const {
    return (i-1)/m_; //determines parent index, base 0
  }
  size_t kthChildIdx(size_t i, int k) const {
    return m_*i+k; //determines the kth child's index, base 0 for i but base 1 for k
  }
  void trickleUp(); // trickle up after push
  void trickleDown(); //trickle down after pop
  
  // private data members
  std::vector<T> heap_; //our m-ary heap
  int m_; //keeps track of m so we can figure out idx for parent/children
  PComparator comp_; //keeps track of the comparator
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): heap_(), m_(m), comp_(c) //constructor
{

}

template <typename T, typename PComparator> 
Heap<T,PComparator>::~Heap() //destructor
{

}

template <typename T, typename PComparator> 
bool Heap<T,PComparator>::empty() const{
  return heap_.empty();
}

template <typename T, typename PComparator> 
size_t Heap<T,PComparator>::size() const{
  return heap_.size();
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap Underflow");
  }

  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();
}

template <typename T, typename PComparator> 
void Heap<T,PComparator>::push(const T& item){
  heap_.push_back(item);
  trickleUp(); //fix heap traits
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap Underflow");
  }
  heap_[0]=heap_.back(); //throw away the element to be popped
  heap_.pop_back(); //fix the size of heap
  trickleDown(); //fix heap trait
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(){
  size_t i = heap_.size()-1;
  while(i>0){
    if(parentIdx(i)>=0 && comp_(heap_[i],heap_[parentIdx(i)])){ //checks if parentIdx(i) is valid, and then compare
      std::swap(heap_[i],heap_[parentIdx(i)]);
      i=parentIdx(i); //swap and update i
    }
    else{
      break; //we're done
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(){
  size_t i = 0;
  size_t bestIdx = i;
  while(i<heap_.size()){
    bestIdx = i; //where we are right now
    for(int k=1; k<=m_; k++){ //traverse each and every child of the ith element to see if there's a better option
      if(kthChildIdx(i,k)<heap_.size() && comp_(heap_[kthChildIdx(i,k)],heap_[bestIdx])){ //first make sure kthChildIdx is valid, then compare using comp_
        bestIdx=kthChildIdx(i,k); //update bestIdx
      }
    }
    if(i!=bestIdx){ //if we still have room for improvement
      std::swap(heap_[i],heap_[bestIdx]);
      i=bestIdx; //swap elements and update where we're now
    }
    else{ //if we are done
      break;
    }
  }
}

#endif

