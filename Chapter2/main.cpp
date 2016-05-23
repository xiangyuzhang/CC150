#include <iostream>
#include <string>
#include "forward_list.h"

using namespace std;

int main()
{
	cout << "test start" << endl;
	forward_list<std::string> list;
	list.push_front("last");
	list.push_front("begin");
	list.insert_after(1, "3");
	list.show_all();
	list.erase_after(list.move_to(0));
	list.show_all();


	forward_list<std::string> list2;
	list2.push_front("another1");
	list2.push_front("another2");
	list2.push_front("another3");
	list2.push_front("another4");
	list2.push_front("another5");
	list2.push_front("another6");

	list2.show_all();
	cout << "swap" << endl;
	list.swap(list2);
	list.show_all();
	list2.show_all();

	list.reverse();
	list.show_all();
	return 0;
}