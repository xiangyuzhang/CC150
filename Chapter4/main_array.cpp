#include "Tree_vetor.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	Tree_array<string> tree;
	tree.insert("3",3);
	tree.insert("1",1);
	tree.insert("4",4);
	tree.insert("2",2);

	tree.remove(3);
	tree.level_order();
	cout << "min = " << tree.findMin().value;
	cout << endl;
	return 0;
}