#include <iostream>
#include "forward_list.h"
using namespace std;

int main()
{
	forward_list<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);
	list.push_front(5);
	list.push_front(1);
	list.push_front(2);
	list.show_all();
	cout << (list.find_kth(2))->content << endl;;
	return 0;
}