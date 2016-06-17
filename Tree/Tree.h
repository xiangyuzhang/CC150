#include <iostream>
#include "Tree_node.h"
#include "queue.h"
#include "DoubleList.h"
template <typename T>
class Tree
{
public:
	Tree():root(nullptr){std::cerr << "Tree has been initialized" << std::endl;};
	Tree(const Tree&);
	Tree& operator=(const Tree&);
	Tree(Tree&&) noexcept;

//	virtual ~Tree();
//===================================
// modifier
	virtual void insert(const T& value, const unsigned& key);	// finished
	virtual void remove(const unsigned& key);					// finished
	virtual void Mirror();										

//===================================
// access
	virtual T& find(const unsigned& key) const;					// finished
	virtual T& findMin() const;									// finished

//===================================
// check state
	virtual bool isEmpty() const;								// finished
	virtual unsigned depth() const;								// finished
	virtual unsigned size_of() const;							// finished
	virtual unsigned num_leaves() const;

	virtual bool isSame(const Tree&) const;
	virtual bool isPerfect() const;
	virtual bool isComplete() const;
	virtual bool isAVL() const;

	virtual unsigned find_K_level_size() const;
	virtual T& find_common_parent(const unsigned& key_1, const unsigned& key_2) const;
	virtual unsigned find_max_length() const;

//===================================
// travel
	virtual void pre_order() const;
	virtual void in_order() const;
	virtual void pos_order() const;
	virtual void level_order() const;

//===================================
// trans
	virtual DoubleList<T> to_DoubleList() const;


	TreeNode<T> *root;

	void _insert(TreeNode<T>*& tree, const T& value, const unsigned& key);
	void _remove(TreeNode<T> *&tree, const unsigned& key);
	TreeNode<T>* _findMin(TreeNode<T>* tree) const;
	TreeNode<T>* _find(TreeNode<T>* tree, const unsigned& key) const;

	unsigned _depth(const TreeNode<T>* tree) const;
	unsigned _size_of(const TreeNode<T>* tree) const;
	unsigned _num_leaves(const TreeNode<T>* tree) const; 

};






//template <typename T>
//Tree<T>::~Tree(){};
//===================================
// modifier
template <typename T>
void Tree<T>::insert(const T& value, const unsigned& key){_insert(root, value, key);}

template <typename T>
void Tree<T>::remove(const unsigned& key){_remove(root, key);}
template <typename T>
void Tree<T>::Mirror(){}

//===================================
// access
template <typename T>
T& Tree<T>::find(const unsigned& key) const{ return _find(root, key)->value; }

template <typename T>
T& Tree<T>::findMin() const
{
	return _findMin(root)->value;
}

//===================================
// check state
template <typename T>
bool Tree<T>::isEmpty() const
{
	if(root == nullptr) return true;
	else if(root != nullptr) return false; 
}

template <typename T>
unsigned Tree<T>::depth() const{ return _depth(root);}

template <typename T>
unsigned Tree<T>::size_of() const{ return _size_of(root);}

template <typename T>
unsigned Tree<T>::num_leaves() const {return _num_leaves(root);}

template <typename T>
bool Tree<T>::isSame(const Tree&) const{}
template <typename T>
bool Tree<T>::isPerfect() const{}
template <typename T>
bool Tree<T>::isComplete() const{}
template <typename T>
bool Tree<T>::isAVL() const{}

template <typename T>
unsigned Tree<T>::find_K_level_size() const{}
template <typename T>
T& Tree<T>::find_common_parent(const unsigned& key_1, const unsigned& key_2) const{}
template <typename T>
unsigned Tree<T>::find_max_length() const{}

//===================================
// travel
template <typename T>
void Tree<T>::pre_order() const{}
template <typename T>
void Tree<T>::in_order() const{}
template <typename T>
void Tree<T>::pos_order() const{}
template <typename T>
void Tree<T>::level_order() const
{
	Queue<TreeNode<T>*> *que = new Queue<TreeNode<T>*>;
	if(root == nullptr) std::cerr << "level_order: tree is empty" << std::endl;
	else
	{
		que->push(root);
		while(que->size_of() != 0)
		{
			if(que->back()->left != nullptr) que->push(que->back()->left);
			if(que->back()->right != nullptr) que->push(que->back()->right);
			std::cerr << que->back()->value << " ";
			que->pop();
		}
	}
	std::cerr << std::endl;
}


//===================================
// trans
template <typename T>
DoubleList<T> Tree<T>::to_DoubleList() const{}




//===================================
// modifier
template <typename T>
void Tree<T>::_insert(TreeNode<T>*& tree, const T& value, const unsigned& key)
{
//	TreeNode<T> node(value, key);
//	if(tree == nullptr) tree = &node;
	TreeNode<T> *node = new TreeNode<T>(value, key);
	if(tree == nullptr) tree = node;

	else if(key < tree->index) _insert(tree->left, value, key);
	else if(key > tree->index) _insert(tree->right, value, key);
	else if(key == tree->index) std::cerr << "_insert: repeating key" << std::endl;
}

template <typename T>
void Tree<T>::_remove(TreeNode<T> *&tree, const unsigned& key)
{
	if(tree == nullptr) std::cerr << "_remove: target is empty" << std::endl;
	else if(key < tree->index) _remove(tree->left, key);
	else if(key > tree->index) _remove(tree->right, key);
	else if(tree->index == key)
	{
		if((tree->left != nullptr) && (tree->right != nullptr))
		{
			TreeNode<T>* min = _findMin(tree->right);
			tree->value = min->value;
			tree->index = min->index;
			_remove(tree->right, tree->index);
		}
		else if((tree->left == nullptr) && (tree->right != nullptr))
		{	
			auto dum = tree;
			tree = tree->right;
			delete dum;
		}
		else if((tree->left != nullptr) && (tree->right == nullptr))
		{
			auto dum = tree;
			tree = tree->left;
			delete dum;
		}
		else if((tree->left == nullptr) && (tree->right == nullptr))
		{
			auto dum = tree;
			tree = nullptr;
			delete dum;
		}
	}
}


//===================================
// access
template <typename T>
TreeNode<T>* Tree<T>::_find(TreeNode<T>* tree, const unsigned& key) const
{ 
	if(tree == nullptr) return nullptr;
	else if(key < tree->index) return _find(tree->left, key);
	else if(key > tree->index) return _find(tree->right, key);
	else if(key == tree->index) return tree;
}

template <typename T>
TreeNode<T>* Tree<T>::_findMin(TreeNode<T>* tree) const
{
	if(tree->left == nullptr) return tree;
	else return _findMin(tree->left);
}

//===================================
// check state
template <typename T>
unsigned Tree<T>::_depth(const TreeNode<T>* tree) const
{
	if(tree == nullptr) return 0;
	else if((tree->left == nullptr) && (tree->right == nullptr)) return 1;
	else 
	{
		auto p_left = _depth(tree->left);
		auto p_right = _depth(tree->right);
		return p_left > p_right ? p_left + 1: p_right + 1;
	}
}

template <typename T>
unsigned Tree<T>::_size_of(const TreeNode<T>* tree) const
{
	if(tree == nullptr) return 0;
	else if((tree->left == nullptr) && (tree->right == nullptr)) return 1;
	else return _size_of(tree->left) + _size_of(tree->right) + 1;
}

template <typename T>
unsigned Tree<T>::_num_leaves(const TreeNode<T>* tree) const 
{
	if(tree == nullptr) return 0;
	else if((tree->left == nullptr) && (tree->right == nullptr)) return 1;
	else return _num_leaves(tree->left) + _num_leaves(tree->right);
}

