#ifndef CC150_QUEUE_H
#define CC150_QUEUE_H
#include "forward_list.h"
template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	Queue & operator=(const Queue &);

	T &front() const;
	T &back() const;

	void empty() const;
	const unsigned size() const;

	void push(node<T> &);
	void pop();
	void swap(queue &);
private:
	forward_list<T> list;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue & rhs)
{
	if(this != &rhs)
	{
		list = rhs.list;
	}
	return *this;
}


template <typename T>
T &front() const { return list.begin()->content;}
#endif
