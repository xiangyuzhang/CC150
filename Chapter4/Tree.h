#ifndef CC150_TREE_H
#define CC150_TREE_H
#include <iostream>
#include <algorithm>
#include "Tree_node.h"
#include "queue.h"

template <typename T>
class Tree    										// 二叉搜索树：不一定是完全二叉，甚至不一定是平衡二叉。每一个左子树小于其根，右字数大于其根
{
public:
	Tree();
	Tree(const Tree&);								// 涉及遍历
	Tree(Tree&&) noexcept;							// 涉及遍历
//	virtual Tree & operator=(const Tree&);			// 涉及遍历
	virtual void swap(Tree&);						
//	virtual ~Tree();								// 涉及遍历

	virtual void insert(const T&, const unsigned&);
	virtual void remove(const unsigned&);
//	virtual void swapElement(const unsigned&, const unsigned&);

	virtual TreeNode<T>& find(const unsigned&) const;
	virtual TreeNode<T>& findRoot() const;
	virtual TreeNode<T>& findMin() const;
//	virtual TreeNode<T>& findMax() const;


//	virtual bool isInternal(const T&) const;
//	virtual bool isExternal(const T&) const;
//	virtual bool isRoot(const T&) const;

	virtual bool isEmpty() const;
	virtual unsigned depth() const;
	virtual unsigned size_of() const;
	virtual unsigned num_leaves() const;
	
//=====================================================
// practice
//	virtual unsigned num_of_node_level(const unsigned&) const;
	virtual bool isSame(const Tree&) const;					// 检查两个二叉树是否一样
	virtual bool isPerfect() const;						// 检查这个二叉树是否是Prefect的
	virtual bool isComplete() const;
	virtual bool isAVL() const;
	virtual void Mirror();
//	virtual TreeNode<T>& find_common_parent(const unsigned&, const unsigned&) const;  // 找到两个节点的最低公共祖先
	virtual void pre_order() const;
	virtual void in_order() const;
	virtual void pos_order() const;
	virtual void level_order() const;

//private:
	void insert(const T& value, const unsigned& index, TreeNode<T>*& tree);
	void remove(const unsigned& index, TreeNode<T>*& tree);
	TreeNode<T>* find(const unsigned& index, TreeNode<T>* node) const;
	TreeNode<T>* findMin(TreeNode<T>* node) const;

	void pre_order(TreeNode<T>* startpoint) const;
	void in_order(TreeNode<T>* startpoint) const;
	void pos_order(TreeNode<T>* startpoint) const;

	unsigned depth(TreeNode<T>* tree) const;
	bool isAVL(TreeNode<T>* tree) const;
	unsigned size_of(TreeNode<T>* tree) const;
	unsigned num_leaves(TreeNode<T>* tree) const;
	void Mirror(TreeNode<T>* tree);

	bool isSame(TreeNode<T>* tree1, TreeNode<T>* tree2) const;
	bool isPerfect(TreeNode<T>* tree) const;
	TreeNode<T>* root;
	unsigned size;
};
//=======================================================
//=======================================================
//=======================================================
// copy control
template <typename T>
Tree<T>::Tree():root(nullptr), size(0){}

template <typename T>
void Tree<T>::swap(Tree& rhs) 
{ 
	std::swap(this->root, rhs.root);
	std::swap(this->size, rhs.size);
}

//=======================================================
//interface
template <typename T>
void Tree<T>::insert(const T& value, const unsigned& index)
{
	insert(value, index, this->root);
}

template <typename T>
void Tree<T>::remove(const unsigned& index)
{
	remove(index, this->root);
}

template <typename T>
unsigned Tree<T>::depth() const {return depth(root);}

template <typename T>
void Tree<T>::level_order() const
{
	Queue<TreeNode<T>*> *queue = new Queue<TreeNode<T>*> ;
	queue->push(root);
	
	while(queue->size_of() != 0)
	{
		if(queue->back()->left != nullptr) queue->push(queue->back()->left);
		if(queue->back()->right != nullptr) queue->push(queue->back()->right);
		std::cerr << queue->back()->value << " ";
		queue->pop();
//		std::cerr << "Queue size = " << queue->size_of() << std::endl;
	}

	std::cerr << std::endl;
}
template <typename T>
void Tree<T>::pre_order() const {pre_order(root);}

template <typename T>
void Tree<T>::in_order() const { in_order(root);}

template <typename T>
void Tree<T>::pos_order() const {pos_order(root);}

template <typename T>
TreeNode<T> &Tree<T>::findMin() const
{
	return *findMin(root);
}

template <typename T>
TreeNode<T>& Tree<T>::find(const unsigned& index) const
{
	return *find(index, root);
}

template <typename T>
bool Tree<T>::isSame(const Tree& target) const
{
	return isSame(root, target.root);
}
template <typename T>
bool Tree<T>::isPerfect() const
{
	return isPerfect(root);
}

template <typename T>
bool Tree<T>::isAVL() const
{
	return isAVL(root);
}


template <typename T>
void Tree<T>::Mirror() 
{
	Mirror(root);
}

template <typename T>
unsigned Tree<T>::num_leaves() const
{
	return num_leaves(root);
}

template <typename T>
bool Tree<T>::isComplete() const
{
	Queue<TreeNode<T>*> *queue = new Queue<TreeNode<T>*> ;
	queue->push(root);
	bool flag = false;
	bool result = true;
	while(queue->size_of() != 0)
	{
		auto temp = queue->front();
		std::cerr << "checking " << temp->value << std::endl;
		if(flag) 
		{
			if(!(temp->isLeaf())) 
			{
				result = false;
				break;
			}
		}
		else
		{
			if((temp->left != nullptr) && (temp->right != nullptr))
			{
				queue->push(temp->left);
				queue->push(temp->right);
			}
			else if((temp->left != nullptr) && (temp->right == nullptr))
			{
				queue->push(temp->left);
				flag = true;
			}
			else if((temp ->left == nullptr) && (temp->right != nullptr))
			{
				result = false;
				break;
			}
			else
			{
				flag = true;
			}
		}
		queue->pop();
	}
	return result;
}
//======================================================
// iterative version

//======================================================
// recusrion version
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
		std::cerr << "inserting: " << index << " " << std::endl;

	}
	else if(index < tree->index)
	{
		std::cerr << "inserting: " << index << " ";
		std::cerr << "follow " << tree->index << " left " << std::endl;
		insert(value, index, tree->left);
	}
	else if(index > tree->index)
	{
		std::cerr << "inserting: " << index << " ";
		std::cerr << "follow " << tree->index << " right " << std::endl;
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

template <typename T>
unsigned Tree<T>::size_of(TreeNode<T>* tree) const
{
	if(!tree) return 0;
	else if(tree->isLeaf()) return 1;
	else return size_of(tree->left) + size_of(tree->right);
}
template <typename T>
unsigned Tree<T>::num_leaves(TreeNode<T>* tree) const
{
	if(!tree) return 0;
	else if(tree->isLeaf()) return 1;
	else return num_leaves(tree->right) + num_leaves(tree->left);
}


template <typename T>
bool Tree<T>::isSame(TreeNode<T>* tree1, TreeNode<T>* tree2) const 
{
	if(!(tree1 || tree2)) return true;
	else if(tree1 == nullptr || tree2 == nullptr) return false;
	else 
	{	
		if(tree1->value != tree2->value) return false;
		else return isSame(tree1->right, tree2->right) && isSame(tree1->left, tree2->left);

	}

}

template <typename T>
bool Tree<T>::isPerfect(TreeNode<T>* tree) const
{
	if(tree == nullptr) return false;
	else if(tree->isLeaf()) return true;
	else if(tree->degree() == 1) return false;
	else return isPerfect(tree->left) && isPerfect(tree->right);

}

template <typename T>
bool Tree<T>::isAVL(TreeNode<T>* tree) const
{
	if(tree == nullptr) return true;
	else if(isAVL(tree->left) && isAVL(tree->right))
	{
		if(abs(depth(tree->left) - depth(tree->right)) <= 1) return true;
		else return false;
	}
}

template <typename T>
void Tree<T>::Mirror(TreeNode<T>* tree)
{
	if(tree == nullptr) return;
	Mirror(tree->left);
	Mirror(tree->right);

	std::swap(tree->left, tree->right);
//	tree->left = right_m;
//	tree->right = left_m;

}
//======================================================
// utility
template <typename T>
bool Tree<T>::isEmpty() const 
{
//	std::cerr << "size = " << size_of() << std::endl;
	if(size_of() > 0) return false;
	else return true;
}

template <typename T>
TreeNode<T> &Tree<T>::findRoot() const {return *root;}


template <typename T>
unsigned Tree<T>::size_of() const {return this->size;}



#endif