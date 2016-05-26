#include <iostream>
#include <string>
using namespace std;

#define right 1
#define down 2
#define left 3
#define up 4


void rotate_array(string array[][5], const unsigned size = 5)
{
	//从外往里面，每一条边进行旋转
	for(int dim = 0; dim != (size+1)/2; ++dim) 		// 对每一层
	{
		int first = dim;							// first为本层边中的第一个元素
		int last = size - 1 - dim;					// last为本层边中的最后一个元素
		for(int i = first; i < last; ++i)			// i为本层中每一个边的某个元素
		{
			int offset = i - first;
			auto top = array[first][i];
			array[first][i] = array[last - offset][first];
			array[last - offset][first] = array[last][last - offset];
			array[last][last- offset] = array[i][last];
			array[i][last] = top;
		}
	}
}
void print_array(const string array[][5], const unsigned size = 5)
{
	for(int row = 0; row != size; ++row)
	{
		for(int col = 0; col != size; ++col)
		{
			cout << array[row][col] << " ";
		}
		cout << endl;
	}
}






int main()
{
	string array[][5] = {{"11", "12","13", "14", "15"},
						{"21", "22","23", "24", "25"},
						{"31", "32","33", "34", "35"},
						{"41", "42","43", "44", "45"},
						{"51", "52","53", "54", "55"}};
	print_array(array);
	rotate_array(array);
	cout << endl;
	print_array(array);
	return 0;
}