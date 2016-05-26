#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
	Queue<int> que;
	que.push(0);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.show_all();
	cout << "first:" << que.front() << endl;
	cout << "last:" << que.back() << endl;
	que.pop();
	que.show_all();
	return 0;
}