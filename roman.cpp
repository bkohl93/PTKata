#include <iostream>
#include <vector>
#include <stdlib.h>

// takes an arabic integer and returns its roman numeral representation
std::string arabicToRoman(int n)
{
  std::string str = "";
  int index = 0;

  std::string roman [13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int arabic [13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  if (n < 1) //check that n is not zero or negative
  {
    str = "No roman numeral representation of integers less than one exist.";
  }
  else if (n > 3999) //check that n is within the range of valid roman numerals
  {
    str = "No roman numeral representation of integers greater than 3,999 exist.";
  }
  else
  {
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
  }
  
  return str;
}

//takes a string of roman numerals and returns its arabic integer representation
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


void testCases()
{
  (arabicToRoman(0) == "No roman numeral representation of integers less than one exist." &&
  arabicToRoman(-1) == "No roman numeral representation of integers less than one exist." &&
  arabicToRoman(1) == "I" &&
  arabicToRoman(4000) == "No roman numeral representation of integers greater than 3,999 exist." &&
  arabicToRoman(2) == "II" &&
  arabicToRoman(3) == "III" &&
  arabicToRoman(4) == "IV" &&
  arabicToRoman(5) == "V" &&
  arabicToRoman(6) == "VI" &&
  arabicToRoman(7) == "VII" &&
  arabicToRoman(8) == "VIII" &&
  arabicToRoman(9) == "IX" &&
  arabicToRoman(10) == "X" &&
  arabicToRoman(11) == "XI" &&
  arabicToRoman(12) == "XII" &&
  arabicToRoman(13) == "XIII" &&
  arabicToRoman(90) == "XC" &&
  arabicToRoman(100) == "C" &&
  arabicToRoman(110) == "CX" &&
  arabicToRoman(199) == "CXCIX" &&
  arabicToRoman(200) == "CC" &&
  arabicToRoman(999) == "CMXCIX" &&
  arabicToRoman(1999) == "MCMXCIX" &&
  arabicToRoman(2000) == "MM" &&
  arabicToRoman(2001) == "MMI" &&
  arabicToRoman(3999) == "MMMCMXCIX"
  ) ? std::cout << "passed" : std::cout << "failed";
  std::cout << std::endl;

 (romanToArabic("I") == 1 &&
  romanToArabic("II") == 2 &&
  romanToArabic("III") == 3 &&
  romanToArabic("IV") == 4 &&
  romanToArabic("V") == 5 &&
  romanToArabic("VI") == 6 &&
  romanToArabic("VII") == 7 &&
  romanToArabic("VIII") == 8 &&
  romanToArabic("IX") == 9 &&
  romanToArabic("X") == 10 &&
  romanToArabic("XI") == 11 &&
  romanToArabic("XII") == 12 &&
  romanToArabic("XIII") == 13 &&
  romanToArabic("XC") == 90 &&
  romanToArabic("C") == 100 &&
  romanToArabic("CX") == 110 &&
  romanToArabic("CXCIX") == 199 &&
  romanToArabic("CC") == 200 &&
  romanToArabic("CMXCIX") == 999 &&
  romanToArabic("MCMXCIX") == 1999 &&
  romanToArabic("MM") == 2000 &&
  romanToArabic("MMI") == 2001 &&
  romanToArabic("MMMCMXCIX") == 3999
  ) ? std::cout << "passed" : std::cout << "failed";
  std::cout << std::endl;

  bool allTestsPassed = true;

  for (int i = 1; i < 4000; i++)
  {
    if (romanToArabic(arabicToRoman(i)) != i)
    {
      allTestsPassed = false;
    }
  }

  (allTestsPassed) ? std::cout << "Passed" << std::endl : std::cout << "Failed" << std::endl;
}


void validate(std::string str)
{
  int len = str.length();
  bool isAString = true;
  bool isANumber = true;

  if (len > 0)
  {
    if (len < 5 && str[0] != 0) //check that the string is not too large an integer, nor has a leading zero
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
      std::cout << str << " is " << arabicToRoman(atoi(str.c_str())) << std::endl;
    }
    else
    {
      for (int i = 0; i < len; i++)
      {
        if (str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M')
        {
          isAString = false;
        }
      }

      for (int i = 0; i < len-2; i++)
      {
        if (str[i] == str[i+1] && str[i] == str[i+2]) //check that three occurences of one letter don't appear in a row
        {
          isAString = false;
        }
      }

      if (isAString)
      {
        std::cout << str << " is " << romanToArabic(str) << std::endl;
      }
      else
      {
        std::cout << "This input is not valid." << std::endl;
      }
    }
  }
}


int main()
{
  std::string str;

  std::cout << "Please enter an arabic number to convert to roman numerals, or vice-versa." << std::endl; 
  std::cin >> str;

  validate(str);

 // testCases();

  return 0;
}
