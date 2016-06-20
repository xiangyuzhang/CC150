#include <iostream>
#include "Tree.h"


using namespace std;


int main(int argc, char const *argv[])
{
	Tree<string> tree;
	tree.insert("6", 6);
	tree.insert("4", 4);
	tree.insert("10", 10);
	tree.insert("8", 8);
	tree.insert("11", 11);
	tree.insert("2", 2);
	tree.insert("3", 3);
	tree.insert("5", 5);
	Tree<string> tree1;
	tree1.insert("4", 4);
	tree1.insert("2", 2);
	tree1.insert("3", 3);
	tree1.insert("5", 5);
	tree.level_order();
	cout << "=====test find min" << endl;
	cout << tree.findMin() << endl;
	cout << "=====test find " << endl;
	cout << tree.find(3) << endl;
	cout << "=====test depth " << endl;
	cout << tree.depth() << endl;
	cout << "=====test size " << endl;
	cout << tree.size_of() << endl;
	cout << "=====test num_leaves " << endl;
	cout << tree.num_leaves() << endl;
	cout << "=====test isSame " << endl;
	if(tree1.isSame(tree1)) cout << "true" << endl;
	if(!tree1.isSame(tree1)) cout << "false" << endl;
	cout << "=====test isPerfect " << endl;
	if(tree1.isPerfect()) cout << "is perfect" << endl;
	else if(tree1.isPerfect() == false) cout << "is not perfect" << endl;
	cout << "=====test isComplete " << endl;
	if(tree1.isComplete()) cout << "is complete" << endl;
	else if(!tree1.isComplete()) cout << "is not complete" << endl;
	cout << "=====test isAVL " << endl;
	if(tree1.isAVL()) cout << "is AVL" << endl;
	else if(!tree1.isAVL()) cout << "is not AVL" << endl;
	cout << "=====test to_doubleLinkList " << endl;
	TreeNode<string>* first_p;
	TreeNode<string>* last_p;
	TreeNode<string>* pointer;
//	tree.to_DoubleList(first_p, last_p);
//	pointer = last_p;
	pointer = first_p;
	while(pointer != nullptr)
	{
//		cout << pointer->value << " " << endl;
//		pointer = pointer->left;
		pointer = pointer->right;
	}
	vector<TreeNode<string>*> path;
	tree1.find_path(3, path);
	cout << "=====test find path " << endl;

	for(auto i: path)
	{
		cout << i->index << " " << endl;
	}
	cout << "=====test find LCA " << endl;
	cout << tree.find_common_parent(2,11) << endl;
	cout << "=====test find max length " << endl;
	cout << endl;
	cout << tree.find_max_length() << endl;
	cout << "=====test in order " << endl;
	tree.in_order();
	cout << endl;
	cout << "=====test pre order " << endl;
	tree.pre_order();
	cout << endl;
	cout << "=====test pos order " << endl;
	tree.pos_order();
	cout << endl;
	return 0;
}