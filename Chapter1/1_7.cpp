#include <iostream>
#include <string>
using namespace std;

void print_array(const string array[][5], const unsigned length = 4, const unsigned width = 5)
{
	for(int row = 0; row != length; ++row)
	{
		for(int col = 0; col != width; ++col)
		{
			cout << array[row][col] << " ";
		}
		cout << endl;
	}
}


void reset_zero(string array[][5], const unsigned length = 4, const unsigned width = 5)
{

	bool back_up_array[length][width];
	for(int row = 0; row != length; ++row)
	{
		for(int col = 0; col != width; ++col)
		{
			if(array[row][col] == "  ") back_up_array[row][col] = true;
			else back_up_array[row][col] = false;
		}
	}

	for(int row = 0; row != length; ++row)
	{
		for(int col = 0; col != width; ++col)
		{
			if(back_up_array[row][col] == true)
			{
				for(int i = 0; i != width; ++i)
					array[row][i] = "";
				for(int i = 0; i != length; ++i)
					array[i][col] = "";		
			} 
		}
	}


}



int main()
{
	string array[][5] = {{"11", "  ","13", "14", "15"},
						{"21", "22","23", "24", "25"},
						{"31", "32","  ", "34", "35"},
						{"41", "42","43", "44", "45"}};
	print_array(array);
	cout << endl;
	reset_zero(array);
	print_array(array);
	return 0;
}