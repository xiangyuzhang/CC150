#include <iostream>
#include "3_4.h"

using namespace std;

int	main(int argc, char const *argv[])
{
	tower<int> orig("orig");
	tower<int> dest("dest");
	tower<int> buff("buff");


	orig.push(1);
	orig.push(2);
	orig.push(3);
	orig.push(4);
	orig.push(5);
	orig.push(6);
	orig.push(7);
	orig.push(8);
	orig.push(9);
	orig.push(10);
	cout << "This is before:" << endl;
	orig.show_all();	
	buff.show_all();
	dest.show_all();

	Hanoi(10, orig, dest, buff);
	cout << "This is after:" << endl;
	orig.show_all();
	buff.show_all();
	dest.show_all();
	return 0;
}