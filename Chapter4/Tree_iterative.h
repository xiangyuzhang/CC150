#ifndef TREE_ITERATIVE_IMPLEMENTATION_H
#define TREE_ITERATIVE_IMPLEMENTATION_H
#include <iostream>
#include <algorithm>
#include "Tree_node.h"
#include "queue.h"

//#include "Tree.h"

template <typename T>
void Tree<T>::insert(const T& value, const unsigned& index)
{
//	std::cerr << "inserting: " << index << std::endl;
	TreeNode<T> *new_node = new TreeNode<T>(value, index);
	if(isEmpty())	
	{
		root = new_node;
		++size;
	}
	else
	{
		auto current_pos = root;
		while(current_pos != nullptr)
		{
//			std::cerr << "here" << std::endl;
			if(index < current_pos->index) 
			{
//				std::cerr << index << " left to " << current_pos->value << std::endl;
				if(current_pos->left == nullptr) 
				{
					++size;
					current_pos->left = new_node;
					break;
				}
				else current_pos = current_pos->left;	
			}

			else if(index > current_pos->index) 
			{
//				std::cerr << index << " right to " << current_pos->value << std::endl;

				if(current_pos->right == nullptr) 
				{
					++size;
					current_pos->right = new_node;
					break;
				}
				else current_pos = current_pos->right;	
			}
			else
			{
				std::cerr << "insert: node already inserted " << std::endl;
			}
		}
	}
}


template <typename T>
TreeNode<T>& Tree<T>::find(const unsigned& index) const   	// 核心：因为左一定大于根，右一定小于根部，则用一个移动指针去搜索，index大于根就往右，否则往左
{


	if(isEmpty()) 
	{
		std::cerr << "find: tree is empty" << std::endl;
		return *root;
	}
	else
	{
		auto current_pos = root;
		while(current_pos != nullptr)
		{
			if(index < current_pos->index) current_pos = current_pos->left;
			if(index > current_pos->index) current_pos = current_pos->right;	
			if(index == current_pos->index) return *current_pos;			
		}

			std::cerr << "find: can't find index: " << index << std::endl;
			return *root;		
	}

}



template <typename T>
TreeNode<T>& Tree<T>::findMin() const
{
	auto temp = root;
	while(temp != nullptr)
	{
		if(temp->left != nullptr) temp = temp->left;
	}
	return *temp;
}
#endif