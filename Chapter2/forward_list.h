#ifndef CC150_CHAPTER2_FORWARD_LIST_H
#define CC150_CHAPTER2_FORWARD_LIST_H

#include <iostream>
template <typename T> struct node
{
	node<T>* operator++() const;
	node() = default;
	node(const T&);

	T content;
	node<T> * next = nullptr;

};

template <typename T> class forward_list
{


public:
//==============================================================
//member function
	forward_list();
	forward_list(const forward_list &);
	forward_list(forward_list &&);
	forward_list & operator=(forward_list);
//==============================================================
//element access
	T &front() const;								// 返回链表中第一个元素的引用，O(1)
	void show_all();
//==============================================================
//iterator
	node<T> *begin() const;
	node<T> *end() const;
	node<T> *move_to(const unsigned&);

//==============================================================
//capacity
	bool empty() const;
//==============================================================
//modifier
	void clear();				// 清除所有的元素，O（n）
	node<T>* insert_after(const unsigned&, const T&);				// O(n)
	void insert_after(node<T>*, const T&);				// O(1)
	node<T>* erase_after(const unsigned&);							// 返回被删除的元素的后面那个的指针
	unsigned erase_after(const node<T>*);							// 返回被删除的元素的后面那个的索引
	void push_front(const T&);
	void pop_front();
	void resize(const unsigned&);								// 如果目前的大小大于指定，那么缩小，否则，增大
	void swap(forward_list&);						// 与另外一个forward_list交换，O(1)
//==============================================================
//operations
	void merge(forward_list &);
	//	splice_after();
	//	remove();
	//	reverse();
	//	unqiue()
private:
	node<T> *head;
	node<T> *tail;
	unsigned size;
};

//==============================================================
template <typename T>
node<T>* node<T>::operator++() const{return this->next;}

template <typename T>
node<T>::node(const T& value):content(value),next(nullptr){}
//==============================================================


//==============================================================
//==============================================================
template <typename T> 
forward_list<T>::forward_list():head(new node<T>), tail(new node<T>), size(0)
{
	head->next = tail;
}

template <typename T>
void forward_list<T>::push_front(const T& value)
{
	node<T> *new_node = new node<T>;
	new_node->content = value;
	new_node->next = head->next;
	head->next = new_node;
	++size;
	std::cerr << "current size = " << size << std::endl;
}

template <typename T>
void forward_list<T>::show_all()
{
	for(node<T>* now = head->next; now != tail; now=now->next)
	{
		std::cout << now->content << " -> ";
	}
	std::cout << std::endl;
}

template <typename T>
void forward_list<T>::insert_after(node<T>* target, const T& value)
{
	node<T> *new_node = new node<T>;
	new_node->content = value;
	new_node->next = target->next;
	target->next = new_node;
	++size;
}
template <typename T> 
node<T>* forward_list<T>::insert_after(const unsigned& index, const T& value)
{

	auto target = move_to(index);
	insert_after(target, value);
//	new_node->next = target->next;
//	target->next = new_node;
//	++size;
//	std::cerr << "current size = " << size << std::endl;

	return target->next;
}




template <typename T>
node<T>* forward_list<T>::move_to(const unsigned& index)
{
	if(index >= size)
	{
		std::cerr << "illegal index, quit" << std::endl;
		exit(-1);
	}
	auto pos = head;
	for(unsigned offset = 0; offset <= index; ++offset)
		pos=pos->next;
	return pos;
}

#endif