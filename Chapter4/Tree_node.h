#ifndef CC150_TREE_NODE_H
#define CC150_TREE_NODE_H
template <typename T>
class TreeNode   // 潜复制
{
public:
	TreeNode();
	TreeNode(const T&);
	TreeNode(const T&, const unsigned&);
	~TreeNode() = default;
	TreeNode(const TreeNode&);
	TreeNode(TreeNode &&) noexcept;
	TreeNode& operator=(const TreeNode&);

	void swap();
	bool isLeaf() const;
	const unsigned degree() const;

	T value;
	unsigned index = 0;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next = nullptr;
};

template <typename T>
TreeNode<T>::TreeNode():left(nullptr), right(nullptr){}

template <typename T>
TreeNode<T>::TreeNode(const T& v):left(nullptr), right(nullptr), value(v), index(0) {}

template <typename T>
TreeNode<T>::TreeNode(const TreeNode& old):left(old.left), right(old.right), value(old.value),index(old.index) {}

template <typename T>
TreeNode<T>::TreeNode(const T& v, const unsigned& i):left(nullptr), right(nullptr), value(v), index(i) {}

template <typename T>
bool TreeNode<T>::isLeaf() const
{
	if(degree() == 0) return true;
	else return false;
}

template <typename T>
const unsigned TreeNode<T>::degree() const
{
	if(left && right) return 2;
	else if(left || right) return 1;
	else return 0;

}

template <typename T>
TreeNode<T>::TreeNode(TreeNode && old) noexcept: left(old.left), right(old.right), value(old.value), index(old.index) 
{
	if(this != &old) 
	{
		old.left = nullptr;
		old.right = nullptr;
	}
}

template <typename T>
TreeNode<T>& TreeNode<T>::operator=(const TreeNode& rhs)
{
	if(this != &rhs)
	{
		this->left = rhs.left;
		this->right = rhs.right;
		this->value = rhs.value;
		this->index = rhs.index;
	}
	return *this;
}



#endif