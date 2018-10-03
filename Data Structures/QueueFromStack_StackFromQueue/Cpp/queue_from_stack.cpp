#include <stack>
#include <cassert>

template<class T>
class queue_from_stack {
  std::stack<T> st1, st2;
	void transfer();
public:
	queue_from_stack();
  bool empty() const;
  size_t size() const;
	T &front();
  void push(const T &);
  void pop();
};

template<class T>
queue_from_stack<T>::queue_from_stack() {}

template<class T>
void queue_from_stack<T>::transfer() {
	while(!st1.empty()) {
		st2.push(st1.top());
		st1.pop();
	}
}

template<class T>
bool queue_from_stack<T>::empty() const {
  return st1.empty() && st2.empty();
}

template<class T>
size_t queue_from_stack<T>::size() const {
  return st1.size() + st2.size();
}

template<class T>
T &queue_from_stack<T>::front() {
  if (st2.empty()) transfer();
  return st2.top();
}

template<class T>
void queue_from_stack<T>::push(const T &x) {
	st1.push(x);
}

// removes the element at front
template<class T>
void queue_from_stack<T>::pop() {
	if (st2.empty()) transfer();
	st2.pop();
}

int main() {

	queue_from_stack<int> qfs;
	assert(qfs.size() == 0);
	assert(qfs.empty());

	qfs.push(1);
	qfs.push(2);
	qfs.push(3);

	assert(qfs.front() == 1);

	qfs.pop();

	assert(qfs.front() == 2);

	qfs.pop();
	qfs.push(4);
	qfs.push(5);

	assert(qfs.size() == 3);
	assert(qfs.front() == 3);

	qfs.pop();

	assert(qfs.front() == 4);

	return 0;
}