

template <typename T>
Tree<T>::Tree():root(nullptr){}

//template <typename T>
//Tree<T>::~Tree(){};
//===================================
// modifier
template <typename T>
void Tree<T>::insert(const T& value, const unsigned& key){_insert(root, value, key);}

template <typename T>
void Tree<T>::remove(const unsigned& key){}
template <typename T>
void Tree<T>::Mirror(){}

//===================================
// access
template <typename T>
T& Tree<T>::find(const unsigned& key) const{}
template <typename T>
T& Tree<T>::findMin() const{}

//===================================
// check state
template <typename T>
bool Tree<T>::isEmpty() const{}
template <typename T>
unsigned Tree<T>::depth() const{}
template <typename T>
unsigned Tree<T>::size_of() const{}
template <typename T>
unsigned Tree<T>::num_leaves() const{}

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
	Queue<TreeNode<T>*> que;
	if(root == nullptr) std::cerr << "level_order: tree is empty" << std::endl;
	else
	{
		que.push(root);
		while(!que.empty())
		{
			if(que.back()->left != nullptr) que.push(que.back()->left);
			if(que.back()->right != nullptr) que.push(que.back()->right);
			std::cerr << que.back()->value << " ";
			que.pop();
		}
	}
}


//===================================
// trans
template <typename T>
DoubleList<T> Tree<T>::to_DoubleList() const{}



template <typename T>
void Tree<T>::_insert(TreeNode<T>* tree, const T& value, const unsigned& key)
{
	TreeNode<T> node(value, key);
	if(tree == nullptr) root = node;
	else if(key < tree->index) _insert(tree->left);
	else if(key > tree->index) _insert(tree->right);
	else std::cerr << "_insert: repeating key" << std::endl;
}
