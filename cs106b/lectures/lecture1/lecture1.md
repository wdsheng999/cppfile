# goals
## Explore common abstractions 
These are all solved with the same abstraction! (using a "graph," which we will learn 
about near the end of the course) 
• By learning common abstractions, we can use those abstractions to solve many 
problems. 
• See the course website to see the list of topics we will cover

## Harness the power of recursion 

## Learn and analyze efficient algorithms

Steps: 
1. Install QT Creator (see Assignment 0!) 
2. Download the example "simple-project": http://web.stanford.edu/
class/cs106b/qtcreator/simple-project.zip
3. Rename the .pro file hello-world.pro
4. Open the src folder, delete hello.h and rename hello.cpp to 
hello-world.cpp
5. Open hello-world.pro
6. Click "Configure Project" 
7. Open Sources->src->hello-world.cpp
8. Delete everything! 
9. Now we're ready to code

code2
data structure
<img src="./datastuct.png">
Why are there such discrepancies??
Bottom line:
• Some structures carry more information simply because of their design.
• Manipulating structures takes time


## HW
hw0 tools including installation of Qt java
and using the debug mode, according to the pdf 
>using "call stack" to check which function call up to the breakpoint.
在 call stack中 level0是目前打代码 然后不要太深入
callstack提示了如何走到这里打

range based for loop``for(char ch:first+last)
单步调试 此时由于转小写 变量表中发生变化打参数变红

清除断点并step over, 执行出函数
此时 returned vaue is the result, 但是原来打值变了 不再是返回值 是一个任意数字 
step out 停留在赋左值之前 再次step over

hw1 