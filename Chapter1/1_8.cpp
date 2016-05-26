#include <iostream>
using namespace std;

bool isSubstring(char old_string[], char new_string[])
{
	int size = 0;
	int is = true; 
	while(*(new_string + size)!= '\0')
		++size;
	// cout << "size is:" << size << endl;
	auto begin = new_string;
	auto end = new_string + size;
	auto pos = old_string;
	while(*(pos + size) != '\0')
	{
		for(auto item = 0; item < end - begin; ++item)
		{
			cout << *(item+begin) << "<->" << *(pos + item) << endl;
			if(*(item+begin) == *(pos + item)) is = is && true;
			else is = is && false;
		}

		if(is) return true;
		else ++pos;
	}
	return false;
}

bool isRotate(char old_string[], char new_string[])
{
	int size = 0;
	while(*(old_string + size) != '\0')
		++size;
	cout << "size is " << size << endl;
	char combined_string[size*2];
	auto pos_old = old_string;
	
	for(auto pos = 0; pos != size; ++pos, ++pos_old)
	{
		*(combined_string + pos) = *pos_old;
		*(combined_string + pos + size) = *pos_old;
	}

	cout << combined_string << endl;
	
	return isSubstring(combined_string, new_string);
	

}
int main()
{
	char original_string[] = "waterbottle";
	char new_string[] = "lewaterbott";
	if(isSubstring(original_string, new_string)) cout << "isSubstring" << endl;
	if(!isSubstring(original_string, new_string)) cout << "is not isSubstring" << endl;
	if(isRotate(original_string, new_string)) cout << "is rotate" << endl;
	return 0;
}