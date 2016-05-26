#include <iostream>
#include <string>
#include "DoubleList.h"

using namespace std;

int main()
{
	DoubleList<int> list;
	DoubleList<int> list2;
	list.push_front(0);
	list.push_back(1);
	list.insert(1,2);
	list.show_all();

	list2.push_back(11);
	list2.show_all();
	list.swap(list2);
	list2.show_all();
	list.show_all();
	return 0;
}