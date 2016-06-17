#include <iostream>
#include "Tree.h"


using namespace std;


int main(int argc, char const *argv[])
{
	Tree<string> tree;
	tree.insert("4", 4);
	tree.insert("2", 2);
	tree.insert("3", 3);
	tree.insert("5", 5);
	tree.level_order();
	cout << "test find min" << endl;
	cout << tree.findMin() << endl;
	cout << "test find " << endl;
	cout << tree.find(3) << endl;
	cout << "test depth " << endl;
	cout << tree.depth() << endl;
	cout << "test size " << endl;
	cout << tree.size_of() << endl;
	cout << "test num_leaves " << endl;
	cout << tree.num_leaves() << endl;

	return 0;
}