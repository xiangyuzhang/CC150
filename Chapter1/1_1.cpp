#include <iostream>
#include <algorithm>
using namespace std;

void Solution1(char* beg_p, char* end_p)  // sort
{

	sort(beg_p, end_p);
	char before = *beg_p;
	for(char* letter = beg_p + 1; letter != end_p; ++letter)
	{
		if(*letter == before) cout << "has repeating letter: " << *letter << endl;
		else before = *letter;
	}

}

void Solution2(char* beg_p, char* end_p) // sort + unique
{
	sort(beg_p, end_p);
	unique(beg_p, end_p);
	cout << "original size = " << end_p - beg_p << endl;
	cout << "current  size = " << end_p - beg_p << endl;
	for(char * pos = beg_p; pos != end_p; ++pos)
		cout << pos;
	cout << endl;
}

void Solution3(char* beg_p, char* end_p) // 用ASCII编码
{
	const int length = end_p - beg_p;
	if(length > 256)
	{
		cout << "has repeating(1)" << endl;
	}
	else
	{
		bool char_set[256];
		auto pos = beg_p;
		for(char * pos = beg_p; pos != end_p; ++pos)
		{
			if(char_set[*pos]) cout << "has repeat: " << *pos << endl;
			else char_set[*pos] = true; 
		}

	}
}
int main()
{

	char str[] = "adbhiloueqrwhnvacnxviou";
	char * beg_p = begin(str);
	char * end_p = end(str);

	Solution3(beg_p, end_p);
	return 0;
}