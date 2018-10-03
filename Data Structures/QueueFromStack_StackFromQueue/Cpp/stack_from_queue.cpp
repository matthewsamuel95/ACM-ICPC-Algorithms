#include <queue>
#include <cassert>

template<class T>
class stack_from_queue {
  std::queue<T> q1, q2;
public:
	stack_from_queue();
  bool empty() const;
  size_t size() const;
	T &top();
  void push(const T &);
  void pop();
};

template<class T>
stack_from_queue<T>::stack_from_queue() {}

template<class T>
bool stack_from_queue<T>::empty() const {
  return q1.empty();
}

template<class T>
size_t stack_from_queue<T>::size() const {
  return q1.size();
}

template<class T>
T &stack_from_queue<T>::top() {
  return q1.front();
}

template<class T>
void stack_from_queue<T>::push(const T &x) {
	std::queue<T> qtemp;
  qtemp.push(x);
  while(!q1.empty()) {
    qtemp.push(q1.front());
    q1.pop();
  }
  std::swap(q1, qtemp);
}

template<class T>
void stack_from_queue<T>::pop() {
	q1.pop();
}

int main() {

	stack_from_queue<int> sfq;
	assert(sfq.size() == 0);
	assert(sfq.empty());

	sfq.push(1);
	sfq.push(2);
	sfq.push(3);

	assert(sfq.top() == 3);

	sfq.pop();

	assert(sfq.top() == 2);

	sfq.pop();
	sfq.push(4);
	sfq.push(5);

	assert(sfq.size() == 3);
	assert(sfq.top() == 5);

	sfq.pop();

	assert(sfq.top() == 4);

	return 0;
}