#include <iostream>

// takes an arabic integer and returns its roman numeral representation
std::string arabicToRoman(int n)
{
  std::string str = "I";

  if (n < 1)
  {
    str = "No roman numeral representation of integers less than one exist.";
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
  arabicToRoman(1) == "I"
  ) ? std::cout << "passed" : std::cout << "failed";


  std::cout << std::endl;
  return 0;
}
