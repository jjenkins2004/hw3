#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

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
  PComparator comp;
  int n;
  std::vector<T> tree;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) 
{
  comp = c;
  n = m;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return tree.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return tree.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  tree.push_back(item);
  int index = tree.size()-1;
  while (index > 0) {
    int parent = (index-1)/n;
    if(comp(tree[index], tree[parent])) {
      std::swap(tree[index], tree[parent]);
      index = parent;
    } else {
      break;
    }
  }
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
    throw std::underflow_error("heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return tree[0];

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
    throw std::underflow_error("heap is empty");
  }

  std::swap(tree[0], tree[size()-1]);
  //std::cout << "deleting: " << tree[size()-1] << std::endl;
  tree.pop_back();

  int index = 0;

  while (index < size()) {
    int leftC = 2*index+1;
    int rightC = 2*index+2;
    if (leftC >=size()) {
      break;
    }
    if (rightC >= size()) {
      if (comp(tree[leftC], tree[index])) {
        std::swap(tree[leftC], tree[index]);
        break;
      }
    }
    //std::cout << tree[index] << " is at " << index << " comparing to " << tree[leftC] << " and " << tree[rightC] << std::endl;
    if (comp(tree[leftC], tree[index]) && comp(tree[leftC], tree[rightC])) {
      std::swap(tree[leftC], tree[index]);
      //std::cout << "determined that " << tree[index] << " should be swapped with " << tree[leftC] << "\n" << std::endl;
      index = leftC;
    }
    else if (comp(tree[rightC], tree[index]) && comp(tree[rightC], tree[leftC])) {
      std::swap(tree[rightC], tree[index]);
       //std::cout << "determined that " << tree[index] << " should be swapped with " << tree[rightC] << "\n" << std::endl;
      index = rightC;
    }
    else {
      //std::cout << tree[index] << " is good where it is" << std::endl;
      break;
    }
  }



}



#endif

