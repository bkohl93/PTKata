#include <iostream>
#include <vector>
#include <stdlib.h>
#include "testCases.h"

// takes a valid arabic integer and returns its roman numeral representation
std::string arabicToRoman(int n)
{
  std::string str = "";
  int index = 0;

  std::string roman [13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int arabic [13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  while (n > 0)
  {
    if (n < arabic[index]) //if n is too small, try the next number in the array
    {
      index++;
    }
    else //otherwise, subtract the largest possible value and concatenate str with its roman numerals 
    {
      str += roman[index];
      n -= arabic[index];
    }
  }  
  return str;
}

//takes a string of valid roman numerals and returns its arabic integer representation
int romanToArabic(std::string s)
{
  int num = 0, len = s.length();
  std::vector<int> numbers(len);

  for (int i = 0; i < len; i++)
  {
    if (s[i] == 'I')
    {
      numbers[i] = 1;	//put the corresponding arabic number in the number array
    }
    else if (s[i] == 'V')
    {
      numbers[i] = 5;
    }
    else if (s[i] == 'X')
    {
      numbers[i] = 10;
    }
    else if (s[i] == 'L')
    {
      numbers[i] = 50;
    }
    else if (s[i] == 'C')
    {
      numbers[i] = 100;
    }
    else if (s[i] == 'D')
    {
      numbers[i] = 500;
    }
    else if (s[i] == 'M')
    {
      numbers[i] = 1000;
    }
  }

  for (int i = 0; i < len-1; i++)
  {
    if (numbers[i] < numbers[i+1]) //if a smaller integer precedes a larger one, it is subtracted
    {
      num -= numbers[i];
    }
    else
    {
      num += numbers[i];
    }
  }

  num += numbers[len-1];

  return num;
}


bool validateNumber(std::string str)
{
  int len = str.length();
  bool isANumber = true;

  if (len > 0)				 //check for empty string
  {
    if (len < 5 && str[0] != 0)		 //check that the string is not too large an integer, nor has a leading zero
    {
      for (int i = 0; i < len; i++)
      {
        if (str[i] < '0' || str[i] > '9') //make sure all of the characters in the string are numbers
        {
          isANumber = false;
        }
      }
    }
    else
    {
      isANumber = false;
    }

    if (isANumber)
    {
      int n = atoi(str.c_str());

      if (n < 1 || n > 3999)	 //check that n is not zero, negative, or greater than 3999
      {
        std::cout <<  "No roman numeral representation of integers less than 1 or greater than 3,999 exists." << std::endl;
        isANumber = false;
      }
    }
  }
  else
  {
    isANumber = false;
  }

  return isANumber;
}


bool validateString(std::string str)
{
  int len = str.length();
  bool isAString = true;
 
  if (len > 0)
  {
    for (int i = 0; i < len; i++)
    {
      if (str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M')
      {
        isAString = false; //check that the string only contains roman numerals
      }
    }
      
    if (str != arabicToRoman(romanToArabic(str)))
    {
      isAString = false; //guarantees that the roman numerals are not improperly formatted
    }
  }
  else
  {
    isAString = false;
  }

  return isAString; 
}


int main()
{
  std::string str;

 // std::cout << "Please enter an arabic number to convert to roman numerals, or vice-versa, or enter 0 to exit." << std::endl; 
  std::cin >> str;

  while (str != "0")
  {
    if (validateNumber(str))
    {
      std::cout << arabicToRoman(atoi(str.c_str())) << std::endl;
    }
    else if (validateString(str))
    {
      std::cout << romanToArabic(str) << std::endl;
    }
    else
    {
      std::cout << "This input is not valid." << std::endl;  
    }
   // std::cout << "Please enter an arabic number to convert to roman numerals, or vice-versa, or enter 0 to exit." << std::endl;
    std::cin >> str;
  }

 // testCases();

  return 0;
}
