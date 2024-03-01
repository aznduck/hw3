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

  void trickleUp(int loc);


private:
  std::vector<T> heap_;
  int m_;
  PComparator c_;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) 
{
  m_ = m;
  c_ = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heap_.push_back(item);
  trickleUp(heap_.size() - 1);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int loc)
{
// could be implemented recursively
  int parent = (loc-1)/m_;
  while(parent >= 0 && c_(heap_[loc], heap_[parent]))
  { 
    std::swap(heap_[parent], heap_[loc]);
    loc = parent;
    parent = (loc-1)/m_;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap_.size();
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){   
      throw std::underflow_error("Can't pop element on empty heap");
  }
  std::swap(heap_[0], heap_.back());
  heap_.pop_back();
  size_t curr = 0;
  while(curr * m_ + 1 < heap_.size())
  {
    size_t best = curr;
    //find best child to swap with the current node
    for(int i = 1; i <= m_; i++)
    {
      size_t index = m_ * curr + i;
      if(index < heap_.size() && c_(heap_[index], heap_[best]))
      {
        best = index;
      }
    }
    if(curr == best) break;
    std::swap(heap_[curr], heap_[best]);
    curr = best;
  }
}


#endif

