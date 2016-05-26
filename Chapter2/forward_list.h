#ifndef CC150_CHAPTER2_FORWARD_LIST_H
#define CC150_CHAPTER2_FORWARD_LIST_H

#include <iostream>
template <typename T> class node
{
public:
	static void swap(node &, node &);
	node<T>* operator++() const;
	node() = default;
	node(const T&);
	node(const node&);

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
	forward_list & operator=(const forward_list&);
//==============================================================
//element access
	T &front() const;								// 返回链表中第一个元素的引用，O(1)
	void show_all() const;
//==============================================================
//iterator
	node<T> *begin() const;
	node<T> *end() const;
	node<T> *move_to(const unsigned&);

//==============================================================
//capacity
	bool empty() const;
	unsigned size_of() const;
//==============================================================
//modifier
	void clear();				// 清除所有的元素，O（n）
	node<T>* insert_after(const unsigned&, const T&);				// O(n)
	void insert_after(node<T>*, const T&);				// O(1)
	node<T>* erase_after(const unsigned&);							// 返回被删除的元素的后面那个的指针
	unsigned erase_after(node<T>*);							// 返回被删除的元素的后面那个的索引
	void push_front(const T&);
	void pop_front();
	void resize(const unsigned&);								// 如果目前的大小大于指定，那么缩小，否则，增大
	void swap(forward_list&);						// 与另外一个forward_list交换，O(1)
//==============================================================
//operations
	void merge(forward_list &);
	//	splice_after();
	//	remove();
	void reverse();
	//	unqiue()
//==============================================================
//2_1.cpp
	void unique();
//2_2.cpp
	node<T> *find_kth(const unsigned &);
//2_3.cpp
	void erase(node<T> *);
//2_4.cpp
	void split(node<T> *);

	void free();
	node<T> *head;
	node<T> *tail;
	unsigned size;
};

//==============================================================
template <typename T>
node<T>* node<T>::operator++() const{return this->next;}

template <typename T>
node<T>::node(const T& value):content(value),next(nullptr){}

template <typename T>
node<T>::node(const node<T> & value):content(value.content), next(value.next){}


template <typename T>
void node<T>::swap(node<T> &lhs, node<T> &rhs)
{
	std::swap(lhs.content, rhs.content);
	std::swap(lhs.next, rhs.next);
}
//==============================================================
//==============================================================
//2_1.cpp
template <typename T>
void forward_list<T>::unique()
{
	if(size > 1)
	{
		for(auto element = head->next; element != tail; element = element->next)
		{
			node<T> * pre = element;
			node<T> * current;
			for(auto check = element->next; check != tail; check = check->next)
			{
				if(check->content == element->content)
				{
					std::cout << "found:" << element->content << " = " << check->content << std::endl;
					erase_after(pre);
				}
				pre = pre->next;
			}
		}
	}
}

//2_2.cpp
template <typename T>
node<T> *forward_list<T>::find_kth(const unsigned& index)
{
	unsigned pos = size - index;
	return move_to(pos);
}
//2_3.cpp
template <typename T>
void forward_list<T>::erase(node<T> * target)
{
	if((target != head) && (target != tail))
	{
		if(target->next != tail)
		{
			target->content = (target->next)->content;
			erase_after(target);
			--size;				
		}
		else if(target->next == tail)
		{
			target->next = nullptr;
			delete tail;
			tail = target;
		}
	
	}
	else std::cout << "can't delete head or tail" << std::endl;

}
//2_4.cpp
template <typename T>
void forward_list<T>::split(node<T>* target)
{
	std::cout << "target is: " << target->content << std::endl;
	T value = target->content;
	auto element = head->next;
	auto n = element->next;
	while(element != target)
	{		// 错误在于erase把target给删掉了
		std::cout << "element = " << element->content << std::endl;
		if(element->content > value)
		{
			n = element->next;
			insert_after(target, element->content);
			if(element->next == target)   // 有点麻烦，这个erase可能会将target删除了，但是这个只可能发生在element的下一个是target的时候，解决方法是将现在的element变成target，因为erase之后现在的element会变成target的值
			{
				target = element;
			}
			erase(element);
		}
		else element = element->next; 
	}
	std::cout << "left side is finished" << std::endl;
	show_all();
	element = target->next;
	while(element != tail)
	{
		if(element->content <= value)
		{
			push_front(element->content);
			erase(element);
			show_all();

		}
		else element = element->next;
	}

}
//==============================================================
//==============================================================
/*
template <typename T> 
void forward_list<T>::reverse()
{
	if(size > 1)
	{
		node<T> * pre = head->next;
		node<T> * current = pre->next;
		while(current != tail)
		{
			push_front(current->content);
			current = current->next;
			erase_after(pre);
		}

	}

}

template <typename T> 
void forward_list<T>::reverse()
{
	if(!empty()) 		// 起点是先把head指向null，然后p指向head,q指向下一个
	{
		node<T> * p = head;
		node<T> * q = head->next;
		node<T> * r = nullptr;
		head->next = nullptr;
		while(p != tail)	//然后像虫子一样，r先前进，之后改变方向，然后qp再前进，直到p = tail
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		node<T> * temp;
		temp = head;
		head = tail;
		tail = temp;
	}

}
*/
//	forward_list(const forward_list &);
//	forward_list(forward_list &&);
//	forward_list & operator=(forward_list);
template <typename T>
forward_list<T>::forward_list(const forward_list & old):head(new node<T>(old.head)), tail(new node<T>(old.tail)), size(old.size){}
template <typename T>
forward_list<T> & forward_list<T>::operator=(const forward_list & rhs)
{
	if(this != &rhs)
	{
		free();
		this->head = rhs.head;
		this->tail = rhs.tail;
		this->size = rhs.size;
	}
	return *this;
}

template <typename T>
void forward_list<T>::free()
{
	node<T> * n;
	for(auto pos = head; pos != tail;)
	{
		n = pos->next;
		delete pos;
		pos = n;
	}
	delete tail;
}
template <typename T>
node<T> *forward_list<T>::begin() const {return head->next;}
template <typename T>
unsigned forward_list<T>::size_of() const {return size;}
template <typename T>
void forward_list<T>::reverse()
{
	if(size > 1)
	{
		node<T> * f = head->next;
		node<T> * p = f;
		node<T> * c = p->next;
		node<T> * n = c->next;
		while(c != tail)
		{
			head->next = c;
			f->next = n;
			c->next = p;
			p = c;
			c = n;
			n = n->next;
		}
	}
}


template <typename T> 
bool forward_list<T>::empty() const
{
	if(head->next == tail) return true;
	else return false;
}

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
}

template <typename T>
void forward_list<T>::pop_front()
{
	auto dum = head->next;
	head->next = dum->next;
	delete dum;
}

template <typename T>
void forward_list<T>::show_all() const
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
node<T>* forward_list<T>::erase_after(const unsigned& index)							// 返回被删除的元素的后面那个的指针
{
	auto target = move_to(index);
	erase_after(target);
	--size;
	return target->next;
}
template <typename T>
unsigned forward_list<T>::erase_after(node<T>* target)							// 返回被删除的元素的后面那个的索引
{
	auto dum = target->next;
	target->next = dum->next;
	--size;
	delete dum;
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
void forward_list<T>::resize(const unsigned& size)							// 如果目前的大小大于指定，那么缩小，否则，增大
{

}


template <typename T>
void forward_list<T>::swap(forward_list<T>& rhs)
{
	std::swap(this->head, rhs.head);
	std::swap(this->tail, rhs.tail);
	std::swap(this->size, rhs.size);
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

//2_5.cpp
template <typename T>
forward_list<T> add_reverse(forward_list<T>& lhs, forward_list<T>& rhs)
{
	forward_list<T> result;
	if(lhs.size_of() != rhs.size_of())
	{
		std::cerr << "size not match" << std::endl;
		exit(0);
	}
	else
	{
		lhs.show_all();
		rhs.show_all();
		unsigned size_both = lhs.size_of();
		unsigned carry = 0;
		for(unsigned index = 0; index != size_both; ++index)
		{
			const unsigned left = (lhs.move_to(index))->content;
			const unsigned right = (rhs.move_to(index))->content;
			unsigned sum = left + right + carry;
			std::cout << "current carry is: " << carry <<std::endl;
			std::cout << "current left = " << left << std::endl;
			std::cout << "current right = " << right << std::endl;
			std::cout << "sum is " << sum << std::endl;
			if(sum >= 10)
			{
				carry = 1;
				result.push_front(sum - 10);
			}
			else
			{

				carry = 0;
				result.push_front(sum);
			}
		}
		if(carry != 0) 
		{
			result.push_front(carry);
		}
		result.reverse();
		return result;
	}

}
template <typename T>
forward_list<T> add(forward_list<T>& lhs, forward_list<T>& rhs)
{
	lhs.reverse();
	rhs.reverse();
	forward_list<T> result = add_reverse(lhs, rhs);
	result.reverse();
	return result;

}

//2_6.cpp
template <typename T>
void find_dup(forward_list<T> &target, const unsigned & index)  // 假设节点的值为可重复的，并且不知道环形的size
{

	std::cout << "index is: " << index << std::endl;
	std::cout << "size is: " << target.size << std::endl;
	// connect
	node<T>* last = target.move_to(target.size - 1);
	std::cout << "last is: " << last->content << std::endl;
	last->next = target.move_to(index);

	node<T> * fast_pointer = target.head->next->next;
	node<T> * slow_pointer = target.head->next;

	// print
	while(fast_pointer != slow_pointer)
	{
		std::cout << "fast:" << fast_pointer->content << " --- slow: " << slow_pointer->content << std::endl;
		fast_pointer = fast_pointer->next->next;
		slow_pointer = slow_pointer->next;
	}

	std::cout << "meet at: " << fast_pointer->content << std::endl; 
	// report
}
#endif