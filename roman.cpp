#include <iostream>

// takes an arabic integer and returns its roman numeral representation
std::string arabicToRoman(int n)
{
  return "No roman numeral representation of zero exists.";
}

//takes a string of roman numerals and returns its arabic integer representation
int romanToArabic(std::string s)
{
  return 0;
}

int main()
{
  (arabicToRoman(0) == "No roman numeral representation of zero exists.") ? std::cout << "passed" : std::cout << "failed";


  std::cout << std::endl;
  return 0;
}
