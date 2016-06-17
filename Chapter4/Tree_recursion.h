#ifndef TREE_RECUSION_H
#define TREE_RECUSION_H
#include <iostream>
#include <algorithm>
#include "Tree_node.h"
#include "queue.h"
#include "Tree.h"
template <typename T>
TreeNode<T>* Tree<T>::findMin(TreeNode<T>* node) const
{
	if(node == nullptr) std::cerr << "the tree is empty" << std::endl;
	else if(node->left != nullptr) return findMin(node->left);
	else return node;
}

template <typename T>
TreeNode<T>* Tree<T>::find(const unsigned& index, TreeNode<T>* node) const
{
	if(node == nullptr)
	{
		std::cerr << "can't find element" << std::endl;
	}
	else if(index < node->index)
	{
		return find(index, node->left);
	}
	else if(index > node->index)
	{
		return find(index, node->right);
	}
	else if(index == node->index)
	{
		return node;
	}


}
template <typename T>
void Tree<T>::insert(const T& value, const unsigned& index, TreeNode<T>*& tree)
{
	if(tree == nullptr)
	{
		tree = new TreeNode<T>(value, index);
	}
	else if(index < tree->index)
	{
		insert(value, index, tree->left);
	}
	else if(index > tree->index)
	{
		insert(value, index, tree->right);
	}
}

template <typename T>
void Tree<T>::remove(const unsigned& index, TreeNode<T>*& tree)
{
	std::cerr << "current: " << tree << "->"<<tree->index << std::endl;
	std::cerr <<"left at: " << tree->left << std::endl;
	std::cerr <<"right at: " << tree->right << std::endl;
	if(tree == nullptr)
	{
		std::cerr << "remove: can't find target" << std::endl;
	}
	else if(index < tree->index)
	{
		remove(index, tree->left);
	}
	else if(index > tree->index)
	{
		remove(index, tree->right);
	}
	else if(index == tree->index)
	{
		if(tree->degree() == 2)
		{
			tree->index = findMin(tree->right)->index;
			tree->value = findMin(tree->right)->value;
			remove(tree->index, tree->right);
		}
		else
		{
			std::cerr << "delete: " << tree->index << std::endl;
 			std::cerr << "tree is at: " << tree << std::endl;
			auto oldNode = tree;
			std::cerr << "oldNode is at: " << oldNode << std::endl;

			tree = (tree->left != nullptr) ? tree->left: tree->right;
			delete oldNode;
			std::cerr << "tree is at: " << tree << std::endl;

			std::cerr << "oldNode is at: " << oldNode << std::endl;

//			oldNode = nullptr;

		}
	}
}

template <typename T>
unsigned Tree<T>::depth(TreeNode<T>* tree) const
{

	if(tree == nullptr) return 0;
	else return depth(tree->left) > depth(tree->right) ? depth(tree->left) + 1 : depth(tree->right) + 1;
}

template <typename T>
void Tree<T>::pre_order(TreeNode<T>* startpoint) const
{
	if(startpoint == nullptr) return;
	std::cerr<< startpoint->value << " ";
	pre_order(startpoint->left);
	pre_order(startpoint->right);

}

template <typename T>
void Tree<T>::in_order(TreeNode<T>* startpoint) const
{
	if(startpoint == nullptr) return;
	in_order(startpoint->left);
	std::cerr<< startpoint->value << " ";
	in_order(startpoint->right);
}

template <typename T>
void Tree<T>::pos_order(TreeNode<T>* startpoint) const
{
	if(startpoint == nullptr) return;
	pos_order(startpoint->left);
	pos_order(startpoint->right);
	std::cerr<< startpoint->value << " ";

}
#endif