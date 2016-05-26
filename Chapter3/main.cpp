#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
using namespace std;

int main()
{
	Stack<int> stk;
	stk.push(1);

	cout << "this is top:" << stk.top() << endl;
	stk.show_all();
	stk.pop();
	cout << "this is top:" << stk.top() << endl;
	stk.show_all();

	return 0;
}