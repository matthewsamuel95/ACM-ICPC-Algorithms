#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <cassert>
 
template <class E>
struct pile_less {
  bool operator()(const std::stack<E> &pile1, const std::stack<E> &pile2) const {
    return pile1.top() < pile2.top();
  }
};
 
template <class E>
struct pile_greater {
  bool operator()(const std::stack<E> &pile1, const std::stack<E> &pile2) const {
    return pile1.top() > pile2.top();
  }
};
 
 
template <class Iterator>
void patience_sort(Iterator first, Iterator last) {
  typedef typename std::iterator_traits<Iterator>::value_type E;
  typedef std::stack<E> Pile;
 
  std::vector<Pile> piles;
  // sort into piles
  for (Iterator it = first; it != last; it++) {
    E& x = *it;
    Pile newPile;
    newPile.push(x);
    typename std::vector<Pile>::iterator i =
      std::lower_bound(piles.begin(), piles.end(), newPile, pile_less<E>());
    if (i != piles.end())
      i->push(x);
    else
      piles.push_back(newPile);
  }
 
  // priority queue allows us to merge piles efficiently
  // we use greater-than comparator for min-heap
  std::make_heap(piles.begin(), piles.end(), pile_greater<E>());
  for (Iterator it = first; it != last; it++) {
    std::pop_heap(piles.begin(), piles.end(), pile_greater<E>());
    Pile &smallPile = piles.back();
    *it = smallPile.top();
    smallPile.pop();
    if (smallPile.empty())
      piles.pop_back();
    else
      std::push_heap(piles.begin(), piles.end(), pile_greater<E>());
  }
  assert(piles.empty());
}
 
int main() {
  int a[] = {4, 65, 2, -31, 0, 99, 83, 782, 1};
  patience_sort(a, a+sizeof(a)/sizeof(*a));
  std::copy(a, a+sizeof(a)/sizeof(*a), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;
  return 0;
}