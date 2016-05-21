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
	return 0;
}