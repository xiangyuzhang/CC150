#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
	virtual void insert(const T& value, const unsigned& key);	// finished hard
	virtual void remove(const unsigned& key);					// finished hard
	virtual void Mirror();										

//===================================
// access
	virtual T& find(const unsigned& key) const;					// finished
	virtual T& findMin() const;									// finished
	virtual bool find_path(const unsigned& key, std::vector<TreeNode<T>*>& path) const;  // finished hard

//===================================
// check state
	virtual bool isEmpty() const;								// finished
	virtual unsigned depth() const;								// finished
	virtual unsigned size_of() const;							// finished
	virtual unsigned num_leaves() const;						// finished

	virtual bool isSame(const Tree<T>&) const;					// finished hard
	virtual bool isPerfect() const;								// finished						
	virtual bool isComplete() const;							// finished hard						
	virtual bool isAVL() const;									// finished

	virtual unsigned find_K_level_size(const unsigned&) const;	// finsihed hard
	virtual T& find_common_parent(const unsigned& key_1, const unsigned& key_2) const;  	// finshed hard
	virtual unsigned find_max_length() const;												// finshed 			
//	virtual void find_path_for_X(const unsigned& amount) const;

//===================================
// travel
	virtual void pre_order() const;										// finished, no-recoursion hard											
	virtual void in_order() const;								// finished, no-recoursion hard
	virtual void pos_order() const;								// finished, no-recoursion hard
	virtual void level_order() const;								// finished

//===================================
// trans
	virtual void to_DoubleList(TreeNode<T>*& first_p, TreeNode<T>*& last_p);  // finished hard


	TreeNode<T> *root;

	void _insert(TreeNode<T>*& tree, const T& value, const unsigned& key);
	void _remove(TreeNode<T> *&tree, const unsigned& key);
	TreeNode<T>* _findMin(TreeNode<T>* tree) const;
	TreeNode<T>* _find(TreeNode<T>* tree, const unsigned& key) const;
	void _Mirror(TreeNode<T>* tree);

	unsigned _depth(const TreeNode<T>* tree) const;
	unsigned _size_of(const TreeNode<T>* tree) const;
	unsigned _num_leaves(const TreeNode<T>* tree) const; 
	bool _isSame(const TreeNode<T>* tree1, const TreeNode<T>* tree2) const;
	bool _isPerfect(TreeNode<T>* tree) const;
	bool _isAVL(const TreeNode<T>* tree) const; 
	void _to_DoubleList(TreeNode<T>*& first_p, TreeNode<T>*& last_p,TreeNode<T>*&  tree);
	unsigned _find_K_level_size(const unsigned& k, const TreeNode<T>* tree) const;
	bool _find_path(const unsigned& key, std::vector<TreeNode<T>*>& path, TreeNode<T>* tree) const;

	void _pre_order(const TreeNode<T>* tree) const;


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
void Tree<T>::Mirror(){ _Mirror(root);}

//===================================
// access
template <typename T>
T& Tree<T>::find(const unsigned& key) const{ return _find(root, key)->value; }

template <typename T>
T& Tree<T>::findMin() const
{
	return _findMin(root)->value;
}

template <typename T>
bool Tree<T>::find_path(const unsigned& key, std::vector<TreeNode<T>*>& path) const
{
	return _find_path(key, path, root);
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
bool Tree<T>::isSame(const Tree<T>& tree) const{ return _isSame(root, tree.root);}

template <typename T>
bool Tree<T>::isPerfect() const{ return _isPerfect(root);}

template <typename T>
bool Tree<T>::isComplete() const
{
	Queue<TreeNode<T>*> que;
	bool must_has_no_child = false;
	if(root == nullptr) return false;
	else
	{
		que.push(root);
		while(que.size_of() != 0)
		{
			if(must_has_no_child)
			{
				if((que.back()->left != nullptr) || (que.back()->right != nullptr))
				{
					return false;
				}
				else return true;
			}
			if((que.back()->left != nullptr) && (que.back()->right != nullptr))
			{
				que.push(que.back()->left);
				que.push(que.back()->right);
				que.pop();
			}
			else if((que.back()->left != nullptr) && (que.back()->right == nullptr))
			{
				must_has_no_child = true;
				que.push(que.back()->left);
				que.pop();
			}
			else if((que.back()->left == nullptr) && (que.back()->right != nullptr))
			{
				return false;
			}
			else
			{
				must_has_no_child = true;
			}
		}
	}

}
template <typename T>
bool Tree<T>::isAVL() const { return _isAVL(root);}

template <typename T>
unsigned Tree<T>::find_K_level_size(const unsigned& k) const{ return _find_K_level_size(k, root);}

template <typename T>
T& Tree<T>::find_common_parent(const unsigned& key_1, const unsigned& key_2) const
{
	std::vector<TreeNode<T>*> path_1;
	std::vector<TreeNode<T>*> path_2;
	std::vector<TreeNode<T>*> ancestors;
	find_path(key_1, path_1);
	find_path(key_2, path_2);
	auto size_path_1 = path_1.size();
	auto size_path_2 = path_2.size();
	auto size = size_path_1 <= size_path_2 ? size_path_1: size_path_2;
	for(int i = 0; i != size; ++i)
	{
		if(path_1.at(i)->index == path_2.at(i)->index) ancestors.push_back(path_1.at(i));
	}
	return ancestors.back()->value;
}
template <typename T>
unsigned Tree<T>::find_max_length() const
{
	/* the following is O(n^2) version
	unsigned dep = depth();
	unsigned width_for_current_level = 0;
	for(int i = 1; i <= dep; ++i)
	{
		width_for_current_level = width_for_current_level > find_K_level_size(i) ? width_for_current_level:find_K_level_size(i);
	}
	return width_for_current_level;
	*/

	if(root == nullptr) return 0;
	else
	{
		std::queue<TreeNode<T>*> que;
		que.push(root);
		unsigned width = 0;
		while(!que.empty())
		{
			int size = que.size();
			width = width > size ? width : size;
			while(--size >= 0)
			{	
				auto last = que.front();
				if(last->left != nullptr) 
				{
					que.push(last->left);
				}
				if(last->right != nullptr) 
				{
					que.push(last->right);
				}
				que.pop();
			}
		}
		return width;
	}

}

//===================================
// travel
template <typename T>
void Tree<T>::pre_order() const
{ 
//	_pre_order(root);
	std::stack<TreeNode<T>*> s;
	TreeNode<T>* current = root;
	while(!s.empty() || current)
	{
		if(current)
		{
			std::cerr << current->index << " ";
			s.push(current);
			current = current -> left;
		}
		else
		{
			current = s.top();
			s.pop();
			current = current ->right;
		}
	}
}

template <typename T>
void Tree<T>::in_order() const
{
	TreeNode<T>* current = root;
	std::stack<TreeNode<T>*> stk;
	bool done = false;
	while(!stk.empty() || current)					// the later condition avoid initialiating the stack
	{
		if(current)
		{
			stk.push(current);
			current = current->left;
		}
		else
		{
			current = stk.top();						// current gose back to current no-void pointer
			stk.pop();
			std::cerr << current->index << " ";
			current = current->right;
		}
	}
}

template <typename T>
void Tree<T>::pos_order() const
{
	if(!root) return;
	std::stack<TreeNode<T>*> s;
	s.push(root);
	TreeNode<T>* prev = nullptr;
	while (!s.empty()) {
	    TreeNode<T> *curr = s.top();
	    // we are traversing down the tree
	    if (!prev || prev->left == curr || prev->right == curr) {
	      if (curr->left) 
	      {
	      	std::cerr << "push " << curr->left->index  << std::endl;
	        s.push(curr->left);
	      } 
	      else if (curr->right) 
	      {
	      	std::cerr << "push " << curr->right->index  << std::endl;

	        s.push(curr->right);
	      } 
	      else 
	      {
	      	std::cerr << "pop " << curr->index  << std::endl;
//	        std::cout << curr->index << " ";
	        s.pop();
	      }
	    } 
	    // we are traversing up the tree from the left
	    else if (curr->left == prev) 
	    {
	      if (curr->right) 
	      {
	      	std::cerr << "push " << curr->right->index  << std::endl;
	        s.push(curr->right);
	      } 
	      else 
	      {
	      	std::cerr << "pop " << curr->index  << std::endl;
	        s.pop();
	      }
	    }
	    // we are traversing up the tree from the right
	    else if (curr->right == prev) 
	    {
	      	std::cerr << "pop " << curr->index  << std::endl;
	      s.pop();
	    }

	    prev = curr;  // record previously traversed node
	  }
}

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
void Tree<T>::to_DoubleList(TreeNode<T>*& first_p, TreeNode<T>*& last_p) 
{
	_to_DoubleList(first_p, last_p, root);
}




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

template <typename T>
void Tree<T>::_Mirror(TreeNode<T>* tree)
{ 
	if(tree == nullptr) return;
	else
	{
		_Mirror(tree->left);
		_Mirror(tree->right);
		auto temp = tree->left;
		tree->left = tree->right;
		tree->right = temp;
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

template <typename T>
bool Tree<T>::_find_path(const unsigned& key, std::vector<TreeNode<T>*>& path, TreeNode<T>* tree) const
{
	if(tree == nullptr) return false;
	else
	{
//		std::cerr << tree->index << std::endl;
		path.push_back(tree);
		if(tree->index == key) 
		{
			return true;
		}
		else if((tree->left && _find_path(key, path, tree->left))||(tree->right && _find_path(key, path, tree->right)))
		{
			return true;
		}
		else 
		{
			path.pop_back();
			return false;
		}
	}
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

template <typename T>
bool Tree<T>::_isSame(const TreeNode<T>* tree1, const TreeNode<T>* tree2) const
{ 
	if((tree1 == nullptr) && (tree2 == nullptr)) return true;
	else if ((tree1 == nullptr) || (tree2 == nullptr)) return false;
	return _isSame(tree1->left, tree2->left) && _isSame(tree1->right, tree2->right);	
}

template <typename T>
bool Tree<T>::_isPerfect(TreeNode<T>* tree) const
{ 
	if(tree == nullptr) return true;
	else if((tree->left == nullptr) && (tree->right == nullptr)) return true;
	else if((tree->left != nullptr) && (tree->right != nullptr)) return (_isPerfect(tree->left) && _isPerfect(tree->right));
	else return false;
}

template <typename T>
bool Tree<T>::_isAVL(const TreeNode<T>* tree) const 
{ 
	if(tree == nullptr) return true;
	else if((tree->left == nullptr) && (tree->right == nullptr)) return true;
	else if(_isAVL(tree->left) && (_isAVL(tree->right)))
	{
		if (abs(_depth(tree->left) - _depth(tree->right)) <= 1) return true;
		else return false;
	}
}

template <typename T>
void Tree<T>::_pre_order(const TreeNode<T>* tree) const
{ 
	if(tree == nullptr) return;
	else
	{
		std::cerr << tree->value << std::endl;
		_pre_order(tree->left);
		_pre_order(tree->right);		
	}
}


template <typename T>
void Tree<T>::_to_DoubleList(TreeNode<T>*& first_p, TreeNode<T>*& last_p,TreeNode<T>*&  tree)
{
	TreeNode<T>* left_first_p; 
	TreeNode<T>* left_last_p;
	TreeNode<T>* right_first_p; 
	TreeNode<T>* right_last_p;

	if(tree == nullptr)
	{
		first_p = nullptr;
		last_p = nullptr;
		return;
	}
	else 
	{
		if(tree->left == nullptr) 
		{
			first_p = tree;
		}
		else
		{
			_to_DoubleList(left_first_p, left_last_p, tree->left);
			first_p = left_last_p;
			tree->left = left_last_p;
			left_last_p->right = tree;

		}

		if(tree->right == nullptr)
		{
			last_p = tree;
		}
		else
		{
			_to_DoubleList(right_first_p, right_last_p, tree->right);
			last_p = right_last_p;
			tree->right = right_first_p;
			right_first_p->left = tree;
		}
	}
}

template <typename T>
unsigned Tree<T>::_find_K_level_size(const unsigned& k, const TreeNode<T>* tree) const
{ 
	if(tree == nullptr || k < 1) return 0;
	if(k == 1) return 1;
	return _find_K_level_size(k-1, tree->left) + _find_K_level_size(k-1, tree->right);
}
