#ifndef TREE_VECTOR_H
#define TREE_VECTOR_H
#include <vector>
#include <iostream>
#include "Tree_node.h"

template <typename T>
class Tree_array
{
public:
	Tree_array();
	Tree_array(const Tree_array&);
	Tree_array(Tree_array&&) noexcept;
	Tree_array& operator=(const Tree_array&);
//	virtual ~Tree_array();

	virtual void insert(const T&, const unsigned&);
	virtual void remove(const unsigned&);

//	virtual TreeNode<T>& find(const unsigned&) const;
//	virtual TreeNode<T>& findRoot() const;
	virtual TreeNode<T>& findMin() const;

//	virtual bool isEmpty() const;
//	virtual unsigned depth() const;
//	virtual unsigned size_of() const;
//	virtual unsigned num_leaves() const;
	
//=====================================================
// practice
//	virtual unsigned num_of_node_level(const unsigned&) const;
//	virtual bool isSame(const Tree&) const;					// 检查两个二叉树是否一样
//	virtual bool isPerfect() const;						// 检查这个二叉树是否是Prefect的
//	virtual bool isComplete() const;
//	virtual bool isAVL() const;
//	virtual void Mirror();
//	virtual TreeNode<T>& find_common_parent(const unsigned&, const unsigned&) const;  // 找到两个节点的最低公共祖先
//	virtual void pre_order() const;
//	virtual void in_order() const;
//	virtual void pos_order() const;
	virtual void level_order() const;

private:
	TreeNode<T>* array[1000] = {nullptr};
	TreeNode<T>* root;

	void _insert(const T& value, const unsigned& key, const unsigned& pos);
	void _remove(const unsigned& key, const unsigned& pos);

	TreeNode<T>* _findMin(const unsigned& tree) const;
};


//=====================================================
// interface

template <typename T>
Tree_array<T>::Tree_array()
{

}


template <typename T>
void Tree_array<T>::insert(const T& value, const unsigned& key)
{
	_insert(value, key, 1);
}

template <typename T>
void Tree_array<T>::remove(const unsigned& key)
{
	_remove(key, 1);
}


template <typename T>
TreeNode<T>& Tree_array<T>::findMin() const
{
	return *_findMin(1);
}
template <typename T>
void Tree_array<T>::level_order() const
{
	for(unsigned i = 1; i < 100; ++i)
	{
		if(array[i] != nullptr)
		{
			std::cerr << array[i]->value << " ";
		}
	}
}
//=====================================================
// implementation
template <typename T>
void Tree_array<T>::_insert(const T& value, const unsigned& key, const unsigned& pos)
{
	if(array[pos] == nullptr) array[pos] = new TreeNode<T>(value, key);
	else if(key < array[pos]->index) _insert(value, key, 2*pos);
	else if(key > array[pos]->index) _insert(value, key, 2*pos + 1);
}

template <typename T>
void Tree_array<T>::_remove(const unsigned& key, const unsigned& pos)
{
	std::cerr << "target: " << key << std::endl;
	if(array[pos] == nullptr) 
	{
		std::cerr << "_remove: wrong target pos" << std::endl;
	}
	else if(array[pos]->index == key) 
	{
		if((array[pos*2] != nullptr) && (array[pos*2 + 1] != nullptr))
		{
			auto min = _findMin(pos*2 + 1);
			array[pos] = min;
			delete min;
			min = nullptr;
		}
		else if((array[pos*2] == nullptr) && (array[pos*2 + 1] == nullptr))
		{
			std::cerr << "deleting: " << array[pos]->index << std::endl;
			delete array[pos];
			array[pos] = nullptr;
		}
		else if((array[pos*2] == nullptr) || (array[pos*2 + 1] == nullptr))
		{
			if(array[pos*2] != nullptr)
			{
				auto temp = array[pos*2]->index;
				array[pos] = array[pos*2];
				_remove(temp, pos*2);
			}
			else
			{
				auto temp = array[pos*2+1]->index;
				array[pos] = array[pos*2 +1];
				_remove(temp, pos*2+1);
			}
		}
	}
	else if(array[pos]->index < key)
	{
		_remove(key, 2*pos);
	}
	else if(array[pos]->index > key)
	{
		_remove(key, 2*pos + 1);
	}
}
template <typename T>
TreeNode<T>* Tree_array<T>::_findMin(const unsigned& tree) const
{
	if(array[tree*2] != nullptr) return _findMin(tree*2);
	else return array[tree];
}


#endif