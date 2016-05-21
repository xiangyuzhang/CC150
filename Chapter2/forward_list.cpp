#include <iostream>
#include "forward_list.h"






template <typename T> 
node<T>* forward_list<T>::insert_after(const unsigned& index, const T& value)
{
	node<T> *new_node = new node<T>;
	new_node->content = value;
	auto target = move_to(index);
	new_node->next = target->next;
	target->next = new_node;
	return new_node;
}




