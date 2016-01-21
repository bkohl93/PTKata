#include <iostream>

// takes an arabic integer and returns its roman numeral representation
std::string arabicToRoman(int n)
{
  std::string str = "";

  if (n < 1)
  {
    str = "No roman numeral representation of integers less than one exist.";
  }
  else if (n > 3999)
  {
    str = "No roman numeral representation of integers greater than 3,999 exist.";
  }
  else
  {
    while (n > 0)
    {
      if (n < 5 && n != 4)
      {
        str += "I";
	n--;
      }
      else if (n == 4)
      {
	str = "IV";
	n = n - 4;
      }
      else
      {
	str += "V";
	n = n - 5;
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
  arabicToRoman(8) == "VIII"
  ) ? std::cout << "passed" : std::cout << "failed";


  std::cout << std::endl;
  return 0;
}
