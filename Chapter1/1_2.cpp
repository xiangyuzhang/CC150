#include <iostream>
#include <algorithm>
using namespace std;

void reverse(char * str)
{
	char * beg = str;
	char * end = str;
	char temp;
	while(*end != '\0') ++end;
	--end;
	cout << "now: " << *end << endl;
	while(beg < end)
	{
		temp = *beg;
		*beg++ = *end;
		*end-- = temp;
	}
}
int main()
{
	char str[] = "abcdefghijklmn";
	reverse(str);
	const int length = sizeof(str)/sizeof(char);
	cout << "size = " << length << endl;
	for(char * pos = str; pos != str + length; ++pos)
		cout << *pos;
	cout << endl;
	return 0;
}