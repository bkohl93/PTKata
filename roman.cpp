#include <iostream>

// takes an arabic integer and returns its roman numeral representation
std::string arabicToRoman(int n)
{
  std::string str = "";
  int index = 0;

  std::string roman [9] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int arabic [9] = {100, 90, 50, 40, 10, 9, 5, 4, 1};

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
  return 0;
}

int main()
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
  arabicToRoman(200) == "CC"
  ) ? std::cout << "passed" : std::cout << "failed";

  std::cout << std::endl;
  return 0;
}
