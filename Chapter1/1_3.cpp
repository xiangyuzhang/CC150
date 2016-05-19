#include <iostream>

using namespace std;
bool checkSame(const char * str_1, const int size_1, const char * str_2, const int size_2)
{
	if (size_2 != size_1) return false;
	int char_set_1[256] = {0};
	int char_set_2[256] = {0};
	for(int index = 0; index <= size_1; ++index)
	{
		++char_set_1[*(str_1 + index)];
		++char_set_2[*(str_2 + index)];

	}
	for(int index = 0; index < 256; ++index)
	{
		if(char_set_1[index] != char_set_2[index]) return false;
	}

	return true;


}
int main()
{
	const char str_1[] = "aassdd1234";
	const char str_2[] = "aassed1234";
	const int size_1 = sizeof(str_1)/sizeof(char);
	const int size_2 = sizeof(str_2)/sizeof(char);
	bool res = checkSame(str_1, size_1, str_2, size_2);
	if(res == true) cout << "same" << endl;
	if(res == false) cout << "not same" << endl;

	return 0;
}