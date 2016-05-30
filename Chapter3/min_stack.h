#ifndef CC150_MIN_STACK
#define CC150_MIN_STACK
#include <iostream>
#include "stack.h"
template <typename T>
class state_node
{
public:
	state_node() = default;
	state_node(const T& v, const T& min):value(v), minimum(min) {}
	state_node(const state_node& old):value(old.value), minimum(old.minimum){};
	

	T value;
	T minimum;
};


template <typename T>
class Stack_min:public Stack<T>
{
public:
	Stack_min():min(999){}
	virtual void push(const T&);
	virtual void pop();
	virtual T& top();

	T find_min() const;
	DoubleList<state_node<T>> list_min;
	T min;
};

template <typename T>
T Stack_min<T>::find_min() const
{
	return min;
}


template <typename T>
void Stack_min<T>::push(const T& value)
{
	if(value <= min)
	{
		state_node<T> node(value, value);
		list_min.push_front(node);
		min = value;
	}
	else
	{
		state_node<T> node(value, min);
		list_min.push_front(node);
	}
}

template <typename T>
T& Stack_min<T>::top()
{
	return list_min.front().value;
}
template <typename T>
void Stack_min<T>::pop()
{
	list_min.pop_front();
	min = this->top();
}


#endif