#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

void fake(int*& tree)
{
	auto old = tree;
	delete old;
}

int main()
{
	Tree<string> tree;
	tree.insert("3",3);
	tree.insert("1",1);
	tree.insert("4",4);
	tree.insert("2",2);

	Tree<string> tree2;
//	tree2.insert("5",5);
//	tree2.insert("7",7);
//	tree2.insert("3",3);
//	tree2.insert("2",2);
//	tree2.insert("4",4);
//	tree2.insert("6",6);
//	tree2.insert("8",8);

	Tree<string> tree3;
//	tree3.insert("5",5);
//	tree3.insert("7",7);
//	tree3.insert("3",3);
//	tree3.insert("2",2);
//	tree3.insert("4",4);
//	tree3.insert("6",6);
//	tree3.insert("8",8);


	if(tree.isSame(tree2))
	{
		cout << "is Same" << endl;
	}
	else
	{
		cout << "is not Same" << endl; 
	}
	tree.level_order();

	if(tree.isComplete()) cout << "is Complete" << endl;
	else cout << "is not Complete" << endl;
//
//	if(tree.isAVL()) cout << "is AVL" << endl;
//	else cout << "is not AVL" << endl;
/*	
//	tree.remove(1);
//	tree.remove(2);
//	tree.remove(3);
//	tree.remove(4);
//	cout << tree.find(2).value << endl;
	cout << tree.root->value << endl;
	cout << tree.root->left->value << " ";
	cout << tree.root->right->value << endl;
	cout << tree.root->left->right->value << endl;
	*/
//	cout << "level_order: " << endl;
	tree.level_order();
//	tree.Mirror();
//	cout << "level_order: " << endl;
//	tree.in_order();	
	/*
	cout << "in_order" << endl;
	tree.in_order();
	cout << endl;
	cout << "pre_order" << endl;
	tree.pre_order();
	cout << endl;
	cout << "pos_order" << endl;
	tree.pos_order();
	cout << endl;

	cout << "depth = " << tree.depth() << endl;
*/
	return 0;
}