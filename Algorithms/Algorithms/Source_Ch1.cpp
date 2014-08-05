#include <iostream>
#include <string>
#include "RevereseString.h"
#include "LargestCommonSubstring.h"
#include "AllUniqueCharacters.h"
#include "RemoveDuplicateCharacters.h"
#include "Anagrams.h"
#include "ReplaceCharacters.h"
#include "Matrix.h"
#include "IsRotation.h"
#include "SwitchCase.h"
#include <climits>

void ReverseStringTest()
{
	std::cout << "REVERSE STRING TEST" << std::endl;
	char str[] = "abc";
	std::cout << "Original: " << str << std::endl;
	reverse(str);
	std::cout << "Reversed: " << str << std::endl;
	std::cout << std::endl;
}

void LargestCommonSubstringTest()
{
	std::cout << "LARGEST COMMON SUBSTRING TEST" << std::endl;
	char str1[] = "abcsdsmonkeysdas";
	char str2[] = "sdsmonmmmonkdsmonkeyasd";
	char sstr[100] = "abc";
	largestCommonSubstring(str1, str2, sstr);
	std::cout << "Largest Common: " << sstr << std::endl;
	std::cout << std::endl;
}

void AllUniqueCharactersTest()
{
	std::cout << "ALL UNIQE CHARACTERS TEST" << std::endl;
	char str[] = "fgfgfdbgbhnjhmj";
	bool unique = allUnique(str);
	std::cout << "Unique: " << unique << std::endl;

	unique = allUniqueNoDatastructures(str);
	std::cout << "Unique no ds: " << unique << std::endl;
	std::cout << std::endl;
}

void RemoveDuplicateCharactersTest()
{
	std::cout << "REMOVE DUPLICATE CHARACTERS TEST" << std::endl;

	char str[] = "fgfgfdbgbhnjhmj";
	char out[100] = "";

	std::cout << "Original: " << str << std::endl;
	removeDuplicateCharacters(str, out);
	std::cout << "No duplicates: " << out << std::endl;
	std::cout << std::endl;
}

void CheckAnagramsTest()
{
	std::cout << "CHECK ANAGRAMS TEST" << std::endl;
	char str1[] = "monkey";
	char str2[] = "ynkemo";
	bool anagrams = checkAnagrams(str1, str2);
	std::cout << "Anagrams: " << anagrams << std::endl;
	std::cout << std::endl;
}

void ReplaceCharactersTest()
{
	std::cout << "REPLACE CHARACTERS TEST" << std::endl;
	
	char str[] = "I am feeling sleepy when studying algorithms";
	std::cout << "Original: " << str << std::endl;
	char c = ' ';

	char *replaced = replaceCharacters(str, c, "___");
	
	std::cout << "Replaced: " << replaced << std::endl;
	delete[] replaced;

	std::cout << std::endl;
}

void RotateMatrix()
{
	std::cout << "ROTATE MATRIX TEST" << std::endl;
	Matrix m(5, 5);
	m.populateRandom();
	std::cout << "Original" << std::endl;
	m.print();
	m.rotateSquare();
	std::cout << "Rotated" << std::endl;
	m.print();
	std::cout << std::endl;
}

void ZerofyMatrix()
{
	std::cout << "ZEROFY MATRIX TEST" << std::endl;
	Matrix m(13, 7);
	m.populateValue(1);
	m.setValue(3, 3, 0);
	m.setValue(9, 1, 0);
	std::cout << "Original" << std::endl;
	m.print();
	m.zerofy();
	std::cout << "Zerofy" << std::endl;
	m.print();
	std::cout << std::endl;
}

void IsRotationTest()
{
	std::cout << "IS ROTATION TEST" << std::endl;
	char str1[] = "erbottlewat";
	char str2[] = "waterbottle";
	bool rotation = isRotation(str1, str2);

	std::cout << "Rotation: " << rotation << std::endl;
	std::cout << std::endl;
}

void SwitchCaseTest()
{
	std::cout << "IS ROTATION TEST" << std::endl;
	char str[] = "12 MonkeyS eat 13 baNaNas!1!?*#(@&#";
	std::cout << "Original: " << str << std::endl;
	switchCase(str);
	std::cout << "Modified: " << str << std::endl;
	std::cout << std::endl;
}

unsigned storage[4];
void ShiftLeft(int count)
{
	std::cout << "SHIFT LEFT TEST" << std::endl;
	if (count >= 128) //if shifting by more than 128 bits, number will just be 0
	{
		storage[0] = 0;
		storage[1] = 0;
		storage[2] = 0;
		storage[3] = 0;
	}
	else if (count >= 32) //shifting by more then 32 is same as shifting by count-32 but moving elements up one index
	{
		storage[0] = storage[1];
		storage[1] = storage[2];
		storage[2] = storage[3];
		storage[3] = 0;
		ShiftLeft(count - 32);
	}
	else //otherwise shift every element, and add carryover from previous one
	{
		storage[0] = (storage[0] << count) | (storage[1] >> (32 - count));
		storage[1] = (storage[1] << count) | (storage[2] >> (32 - count));
		storage[2] = (storage[2] << count) | (storage[3] >> (32 - count));
		storage[3] = (storage[3] << count);
	}
	std::cout << std::endl;
}

int findMinimumElement(int arr[], int low, int high)
{
	if (low == high)
		return low;

	int mid = (high + low) / 2;

	if (mid == low)
		return high;

	if (arr[low] > arr[mid])
		return findMinimumElement(arr, low, mid-1);	
	return findMinimumElement(arr, mid, high);
}

int findMinimumElement2(int arr[], int length)
{
	int prev = INT_MAX;
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < prev)
		{
			if (prev != INT_MAX || length == 1)
				return i;			
		}
		prev = arr[i];
	}
	return -1;
}

int main()
{
	LargestCommonSubstringTest();
	ReverseStringTest();
	AllUniqueCharactersTest();
	RemoveDuplicateCharactersTest();
	CheckAnagramsTest();
	ReplaceCharactersTest();
	RotateMatrix();
	ZerofyMatrix();
	IsRotationTest();
	SwitchCaseTest();

	std::cout << "Test array: ";
	int testArray[] = { 23, 52, 74, 100, 100, 1, 1, 4, 4, 19, 21 };
	std::cout << findMinimumElement(testArray, 0, sizeof(testArray)/sizeof(int) - 1) << std::endl;
	
	int testArrayDuplicates[] = { 23, 52, 74, 100, 100, 1, 1, 4, 4, 19, 21 };
	std::cout << findMinimumElement2(testArrayDuplicates, 11) << std::endl;

	int n;
	std::cin>>n;
	return 0;
}