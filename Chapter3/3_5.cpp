#include <iostream>
#include "3_5.h"


int main()
{
	Myqueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.show_all();
	queue.pop();
	queue.show_all();
	queue.push(20);
	queue.show_all();
	return 0;
}