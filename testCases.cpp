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

