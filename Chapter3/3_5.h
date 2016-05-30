#ifndef CC150_MYQUEUE_H
#define CC150_MYQUEUE_H
#include "stack.h"
#include <iostream>

template <typename T>
class Myqueue: public Stack<T>
{
public:
	void push(const T&);
	void pop();
	T& top();

	void show_all() const;

private:
	void turn_ass();
	void turn_pri();
	Stack<T> primary_stk;
	Stack<T> associate_stk;
};

template <typename T>
void moveTop(Stack<T> &from, Stack<T> &to)
{
	auto temp = from.top();
	to.push(temp);
	from.pop();
}

template <typename T>
void Myqueue<T>::push(const T& value)
{
	if(primary_stk.empty() && (!associate_stk.empty())) turn_ass();
	primary_stk.push(value);
}

template <typename T>
void Myqueue<T>::pop()
{
	if(!(primary_stk.empty()) && (associate_stk.empty())) turn_pri();
	associate_stk.pop();
}

template <typename T>
T& Myqueue<T>::top() 
{
	if(primary_stk.empty() && (!associate_stk.empty())) turn_ass();
	return primary_stk.top();
}

template <typename T>
void Myqueue<T>::show_all() const 
{
	std::cout << "primary_stk: "  << std::endl;
	primary_stk.show_all();
	std::cout << "associate_stk: " << std::endl;
	associate_stk.show_all();
}


template <typename T>
void Myqueue<T>::turn_ass()
{
	while(!associate_stk.empty())
	{
		moveTop(associate_stk, primary_stk);
	}
}

template <typename T>
void Myqueue<T>::turn_pri()
{
	while(!primary_stk.empty())
	{
		moveTop(primary_stk, associate_stk);
	}
}


#endif