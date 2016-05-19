#include <iostream>

using namespace std;


void cout_word(char * word, int wordCounter)
{
	for(int index = 0; index <= wordCounter; ++index)
	{
		cout << *(word + index);
	}
	cout << endl;
}
void changeSpace(char * word)
{
	char stringVector[10][10];
	int stringSize[10];
	int wordCounter = 0;
	int charCounter = 0;
	char result[100];
	int pos = 0;
	for(int index = 0; index != 14; ++index)
	{
		if(*(word + index) != ' ')
		{
			stringVector[wordCounter][charCounter++] = *(word + index);
		}
		else
		{
			stringSize[wordCounter] = charCounter - 1;
			++wordCounter;
			charCounter = 0;
		}
	}

	for( int index = 0; index <= wordCounter; ++index)
	{
		cout << "word size is: " << stringSize[index] << " ->";
		cout_word(stringVector[index], stringSize[index]);
	}

	for(int index = 0; index <= wordCounter; ++index)
	{
		cout << "The size is:" << stringSize[index] << endl;
		cout << "first letter is:" << stringVector[index][0] << endl;

		for(int i = 0; i <= stringSize[index]; ++i)
		{
			result[pos++] = stringVector[index][i];			
		}
		result[pos++] = '%';
		result[pos++] = '2';
		result[pos++] = '0';
	}
	int digits = 13 + (wordCounter - 2) * 3;
	for(int i = 0; i <= digits; ++i){cout << result[i];}
	cout << endl;




}

int main()
{
	char word[] = "Mr John Smith ";
	changeSpace(word);
}