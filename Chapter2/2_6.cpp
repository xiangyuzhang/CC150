#include <iostream>
#include "forward_list.h"
using namespace std;

int main()
{
	forward_list<string> list;
	list.push_front("E");
	list.push_front("D");
	list.push_front("C");
	list.push_front("B");
	list.push_front("A");
	find_dup(list, 2);


	return 0;
}