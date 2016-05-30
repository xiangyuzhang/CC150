#include <iostream>
#include "min_stack.h"

using namespace std;

int main()
{
	Stack_min<int> stk;
	stk.push(3);
	cout << "min is: " << stk.find_min() << endl;
	stk.push(2);
	cout << "min is: " << stk.find_min() << endl;

		stk.push(1);
			stk.push(4);
	cout << "min is: " << stk.find_min() << endl;

				stk.push(0);
	cout << "min is: " << stk.find_min() << endl;
	stk.pop();
	cout << "min is: " << stk.find_min() << endl;

	return 0;
}