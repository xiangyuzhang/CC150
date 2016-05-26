#ifndef CC150_QUEUE_H
#define CC150_QUEUE_H
#include "DoubleList.h"
template <typename T>
class Queue
{
public:
	Queue() = default;
	~Queue() = default;
	Queue & operator=(const Queue &);

	T &front() const;
	T &back() const;

	bool empty() const;
	const unsigned size_of() const;

	void push(const T &);
	void pop();
	void swap(Queue &);

	void show_all();
private:
	DoubleList<T> list;
};

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> & rhs)
{
	if(this != &rhs)
	{
		list = rhs.list;
	}
	return *this;
}


template <typename T>
T &Queue<T>::front() const { return list.front();}

template <typename T>
T &Queue<T>::back() const {return list.back();}

template <typename T>
bool Queue<T>::empty() const {return list.empty();}

template <typename T>
const unsigned Queue<T>::size_of() const {return list.size_of();}

template <typename T>
void Queue<T>::push(const T & value) {list.push_front(value);}

template <typename T>
void Queue<T>::pop() {list.pop_back();}

template <typename T>
void Queue<T>::swap(Queue<T> & rhs) {list.swap(rhs.list);}

template <typename T>
void Queue<T>::show_all() {list.show_all();}
#endif
