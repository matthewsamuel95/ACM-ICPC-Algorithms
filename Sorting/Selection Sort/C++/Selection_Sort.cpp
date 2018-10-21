#include <algorithm>
#include <iterator>
#include <iostream>
 
template<typename ForwardIterator> void selection_sort(ForwardIterator begin,ForwardIterator end) 
{
  for(auto i = begin; i != end; ++i)
  {
    std::iter_swap(i, std::min_element(i, end));
  }
}
 
int main() { 
  int N;
  std::cin>>N;
  int a[N];
  for(int i=0;i<N;i++)
  {
      std::cin>>a[i];
  }
  selection_sort(a,a+N);
  copy(a,a+N, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}
