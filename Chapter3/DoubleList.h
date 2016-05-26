#ifndef CC150_DOUBLE_LIST_H
#define CC150_DOUBLE_LIST_H
#include <algorithm>
#include <iostream>
template<typename T>
class DoubleNode
{
public:
	DoubleNode();
	~DoubleNode();
	DoubleNode(DoubleNode& );
	DoubleNode &operator=(const DoubleNode&);

	void swap(DoubleNode &);

	T content;
	DoubleNode* before;
	DoubleNode* next;
};

template <typename T>
DoubleNode<T>::DoubleNode():before(nullptr), next(nullptr){}

template <typename T>
DoubleNode<T>::~DoubleNode()
{
	if(this->before != nullptr) this->before->next = this->next;
	if(this->next != nullptr) this->next->before = this->before;
}

template <typename T>
DoubleNode<T>::DoubleNode(DoubleNode & old):content(old.content), before(old.before), next(old.next){}

template<typename T>
DoubleNode<T> &DoubleNode<T>::operator=(const DoubleNode<T>& old)
{
	if(this != &old)
	{
		this->before = old.before;
		this->next = old.next;
		this->content = old.content;
	}
	return *this;
}

template<typename T>
void  DoubleNode<T>::swap(DoubleNode<T> & rhs)
{
	std::swap(this->before, rhs.before);
	std::swap(this->next, rhs.before);
	std::swap(this->content, rhs.content);
}





template <typename T>
class DoubleList
{
public:
	DoubleList();
	~DoubleList();
	DoubleList(const DoubleList &);
	DoubleList & operator=(DoubleList);

	T& front() const;
	T& back() const;
	DoubleNode<T> *begin() const;
	DoubleNode<T> *end() const;

	bool empty() const;
	const unsigned size_of() const;

	void clear();
	void insert(DoubleNode<T>*, const T&);
	void insert(const unsigned&, const T&);
	void erase(DoubleNode<T>*);
	void erase(const unsigned&);
	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void swap(DoubleList &);

	void reverse();
	void unqiue();
	void unique();
	void sort();

	void show_all() const;

private:
	unsigned size;
	DoubleNode<T> *head;
	DoubleNode<T> *tail;
	DoubleNode<T> * move_to(const unsigned &);
};

template <typename T>
DoubleList<T>::DoubleList():size(0)
{
	tail = new DoubleNode<T>;
	head = tail;
	head->next = tail;
	tail->before = head;
}

template <typename T>
DoubleList<T>::~DoubleList() {clear();}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList &old):size(old.size)
{
	DoubleList();
	for(DoubleNode<T>* pos = old.head; pos != tail; pos = pos->next)
	{
		push_back(pos->content);
	}
}

template <typename T>
DoubleList<T> & DoubleList<T>::operator=(DoubleList rhs){swap(rhs);}

template <typename T>
T& DoubleList<T>::front() const {return head->content;}

template <typename T>
T& DoubleList<T>::back() const {return tail->before->content;}

template <typename T>
DoubleNode<T>* DoubleList<T>::begin() const {return head;}

template <typename T>
DoubleNode<T>* DoubleList<T>::end() const {return tail->before;};

template <typename T>
bool DoubleList<T>::empty() const
{
	if(size == 0) return true;
	else if(size > 0) return false;
}

template <typename T>
const unsigned DoubleList<T>::size_of() const {return size;}

template <typename T>
void DoubleList<T>::clear()
{
	for(DoubleNode<T>* pos = head; pos != tail; pos = pos->next)
	{
		delete pos;
	}
	delete tail;
}

template <typename T>
void DoubleList<T>::insert(DoubleNode<T> * pos, const T& value)
{
	DoubleNode<T> *temp = new DoubleNode<T>;
	temp->before = pos->before;
	temp->next = pos;
	(pos->before)->next = temp;
	pos->before = temp;
	temp->content = value;
	head->before = nullptr;
	tail->next = nullptr;
	++size;
}

template <typename T>
void DoubleList<T>::insert(const unsigned& index, const T& value)
{
	DoubleNode<T> *pos = move_to(index);
	insert(pos, value);
}

template <typename T>
void DoubleList<T>::erase(DoubleNode<T> *pos)
{
	pos->before->next = pos->next;
	pos->next->before = pos->before;
	delete pos;
	--size;
}

template <typename T>
void DoubleList<T>::erase(const unsigned& index)
{
	DoubleNode<T> *pos = move_to(index);
	erase(pos);

}

template <typename T>
void DoubleList<T>::push_front(const T& value)
{
	DoubleNode<T> * temp = new DoubleNode<T>;
	temp->content = value;
	head->before = temp;
	temp->next = head;
	temp->before = nullptr;
	head = temp;
	tail->next = nullptr;
	++size;
}

template <typename T>
void DoubleList<T>::push_back(const T& value)
{
	if(!empty())
	{
		insert(tail, value);
	}
	else
	{
		++size;
		DoubleNode<T>* temp = new DoubleNode<T>;
		temp->content = value;
		tail->before = temp;
		tail->next = nullptr;
		temp->next = tail;
		temp->before = nullptr;
		head = temp;
	}
}

template <typename T>
void DoubleList<T>::pop_front()
{
	auto temp = head;
	head = head->next;
	head->before = nullptr;
	delete temp;
	--size;
}

template <typename T>
void DoubleList<T>::pop_back(){erase(tail->before);}

template <typename T>
void DoubleList<T>::swap(DoubleList & rhs)
{
	std::swap(this->head, rhs.head);
	std::swap(this->tail, rhs.tail);
	std::swap(this->size, rhs.size);

}

template <typename T>
void DoubleList<T>::show_all() const
{
	for(DoubleNode<T> * i = head; i != tail; i = i->next)
		std::cout << i->content << " -> ";
	std::cout << std::endl;
}

template <typename T>
DoubleNode<T>* DoubleList<T>::move_to(const unsigned& index)
{
	if(index > size - 1)
	{
		std::cerr << "move_to: illegal index" << std::endl;
		exit(0);
	}
	DoubleNode<T> * result = head;
	for(unsigned i = 0; i < index; ++i)
		result = result->next;
	return result;
}

#endif