#include <stdio.h>
#include<stdlib.h>


int pack4Chars2Int(char c1, char c2, char c3, char c4);
int checkEvenParity(short input);


void main()
{
	// Test pack4Chars2Int
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	int num = pack4Chars2Int(a, b, c, d);
	

	// Test checkEvenParity
	printf("%d\n", checkEvenParity(24));

}


int pack4Chars2Int(char c1, char c2, char c3, char c4)
{
	int num = 0;
	num = num | c1;
	num = num << 8;
	num = num | c2;
	num = num << 8;
	num = num | c3;
	num = num << 8;
	num = num | c4;
	return num;
}


int checkEvenParity(short input)
{
	int countones = 0; // Variable for counting number of bits that are '1'

	for (int i = 0; i < sizeof(input) * 8; i++)
	{ 
		if (input & 1 == 1) // Perform bitwise AND to check if the LSB of the input was '0' or '1'
			countones++;
		input = input >> 1; // Shift input's LSB to the next bit
	}

	// Check if number of ones is even or odd
	if (countones % 2 == 0)
		return 1;
	else
		return 0;
}