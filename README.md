# PTKata
Roman Numeral Kata

Author: Benjamin Kohl

Date: 1/22/16

USAGE:

compile with: 	g++ roman.cpp testCases.cpp

run with: 	./a.out

test with: 	./a.out < numbers.txt | diff numerals.txt - 

testCases.cpp can be run by uncommenting the function call in roman.cpp

In order to run the test pipe command, roman.cpp must be slightly edited to supress all output except for the 
invalid message and the actual roman numeral output.

Running with ./a.out will ask the user for an input.  If a valid arabic integer is entered, its roman numeral
equivalent will be returned. If a valid roman numeral is entered, its arabic integer equivalent will be returned.
If an invalid input is given, the user will be told the input is invalid. If 0 is entered, the program will exit
and thus stop asking for input.
