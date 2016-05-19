#include <iostream>

using namespace std;

void shorten(char word[], const int length)
{
	char res[length];
	int res_pos = 0;
	int len = 0;
	for(int pos = 1; pos != length; ++pos)
	{
		static char *before = word;
		static int occur = 1;
		if(*before == word[pos])
		{	
			// cout << "pos :" << before - word << " = " << "pos: " << pos << endl;
			++before;
		 	++occur;

		}
		else if(*before != word[pos])
		{
			res[res_pos++] = *before;
			res[res_pos++] = '0' + occur;
			occur = 1;
			++before;
			len += 2;
		}
	}
	cout << endl;
	for(int i = 0; i  != len; ++i)
	{
		cout << res[i];
	}
	cout << endl;
}


int main()
{

	char word[] = "aabacdddeeee";  // a2b1a1c1a1d3e3
	const int length = sizeof(word)/sizeof(char);
	shorten(word, length);
	return 0;
}