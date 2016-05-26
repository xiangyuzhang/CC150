#ifndef CC150_STACK_H
#define CC150_STACK_H
#include "DoubleList.h"
template <typename T>
class Stack
{
public:
	Stack() = default;
	~Stack() = default;
	Stack(const Stack&);
	Stack(Stack &&) noexcept;
	Stack & operator=(Stack);

	T& top() const;

	bool empty() const;
	const unsigned size_of() const;

	void push(const T&);
	void pop();
	void swap(Stack &);

	void show_all();

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
void Stack<T>::show_all() {list.show_all();}


#endif