Logistics:
• TinyFeedback — your chance to report on what is going well and what isn't going well in the class.
Homework 1:
• Due Thursday -- office hours, LaIR, Piazza available
Vector review and Big-O with Vectors
Strings
• C++ strings vs C strings
• Characters
• Member Functions
• Stanford Library extensions
• Char and <cctype>

和java string不同 c++string可变

## string
#include<string>
string s = "fear the tree"
char c1=s[3]
char c2=s.at(2)

## stirng operators

s.append(str)add text to the end of a string
s.compare(str)return -1, 0, or 1 depending on relative ordering
s.erase(index, length)delete text from a string starting at given index
s.find(str)
s.rfind(str)first or last index where the start of str appears in
this string (returns string::npos if not found)
s.insert(index, str)add text into a string at a given index
s.length() or s.size()number of characters in this string
s.replace(index, len, str)replaces len chars at given index with new text
s.substr(start, length) or
s.substr(start)the next length characters beginning at start
(inclusive); if length omitted, grabs till end of string

## vs C strings
c++有两种string 一种来自c 一种来自 c++ lib
c string没有成员函数  CS107
可以在两者之间进行转换
string("text") c-->c++
string.c_str() c++-->c

## stanford string lib
#include "strlib.h"


endsWith(str, suffix)
startsWith(str, prefix)returns true if the given string begins or ends with
the given prefix/suffix text
integerToString(int)
realToString(double)
stringToInteger(str)
stringToReal(str)returns a conversion between numbers and strings
equalsIgnoreCase(s1, s2)true if s1 and s2 have same chars, ignoring casing
toLowerCase(str)
toUpperCase(str)returns an upper/lowercase version of a string
trim(str)returns string with surrounding whitespace removed


## recap
c++ string are more functional and easier to use


## exercise
Write a function called nameDiamond that accepts a string as a parameter and prints it
in a "diamond" format as shown below.
•
For example, nameDiamond("CHRIS") should print:
C
CH
CHR
CHRI
CHRIS
 HRIS
  RIS
   IS
    S
