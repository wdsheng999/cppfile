Logistics:
• Signing up for section
• A note on the honor code  -->integrity thing
• Review
• Vectors
• Grids
• Introduction to Computational Complexity and "Big O" (maybe...)
• Reading Assignment: Chapter 5.1-5.2, Section 10.2

## a review: project Gameshow
注意 main和各个函数的关系安排 整个程序打组织
setupGame ifstream openfile getline
循环读取

## vectors and grids
c++ powerful collection: vector grid map stack queue set

vector list of element can grow or shrink
have index advanced array 
include "vector.h"

### details:
boundary check: know its size
constructor creates an empty array

### create
```c
Vector<int> vec;
vec.add
vec.size
remove clear insert vec[i] isEmpty
可以使用 for each循环
for(int value: vec){cout<<value<<endl;}
```
http://www.martinstepp.com/cppdoc/Vector-class.html


## grid
advanced 2d array

default constructor make size 0

### create 
Grid<int> matrix(2,2)
matrix[0][0]=42;
matrix[1][0]=matrix[0][1]

numRows numCols resize(rows,cols)
inBounds(row,col) true/false
