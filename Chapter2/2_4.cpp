#include <iostream>
#include "forward_list.h"
using namespace std;

int main()
{
	forward_list<int> list;
	list.push_front(5);
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(3);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);

	list.show_all();
	list.split(list.move_to(4));
	list.show_all();
	return 0;
}