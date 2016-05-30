#ifndef CC150_STACK_H
#define CC150_STACK_H
#include "DoubleList.h"


template <typename T>
class Stack
{
public:
	Stack() = default;
	virtual ~Stack() = default;
	Stack(const Stack&);
	Stack(Stack &&) noexcept;
	Stack & operator=(Stack);

	virtual T& top() const;


	virtual bool empty() const;
	virtual const unsigned size_of() const;

	virtual void push(const T&);
	virtual void pop();
	virtual void swap(Stack &);

	virtual void show_all() const;

private:
	DoubleList<T> list;
};


//==================================================================
//copy control
template <typename T>
Stack<T>::Stack(const Stack& old):list(old.list){}

template <typename T>
Stack<T>::Stack(Stack && old) noexcept:list(old.list){old.~old();}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack rhs) {swap(rhs);}

//==================================================================
//element access
template <typename T>
T& Stack<T>::top() const {return list.front();}

//==================================================================
//capacity
template <typename T>
bool Stack<T>::empty() const {return list.empty();}

template <typename T>
const unsigned Stack<T>::size_of() const {return list.size_of();}

//==================================================================
//modifier
template <typename T>
void Stack<T>::push(const T& value) {list.push_front(value);}

template <typename T>
void Stack<T>::pop() {list.pop_front();}

template <typename T>
void Stack<T>::swap(Stack & rhs) {list.swap(rhs.list);}

template <typename T>
void Stack<T>::show_all() const {list.show_all();}


#endif