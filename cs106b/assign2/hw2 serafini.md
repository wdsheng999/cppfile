# Assignment 2: Serafini

This Serafini in reference to Luigi Serafini who wrote a book called the Codex Seraphinianus. The codex is filled with scientific looking writing and figures, all of which are believed to be the product of Serafini's imagination. Two features that Serafini's work primarily embody are morphings—many objects in the codex change from one to another—and random writing.

this assignment consists of two parts 
A) word ladders: morph one word to another
B) random writter:stochastically generates text
each part is programmed separately

Turn in only the following files: in the starter code
wordladder.cpp, the C++ code for the Part A Word Ladder program (including a main function)
ngrams.cpp, the C++ code for the Part B N-grams program (including a main function)
myinput.txt, your own unique Part B input file representing text to read in as your program's input

## word ladder

using:
lexiconLIB--> contains()/queue/stack

algorithm: shortest-path problem
{internet packets/comparing gene mutations/google map,etc}
breadth-first search 广度优先搜索(BFS)
BFS:
search process that expands out from a start position, considering all possibilities that are one step away, then two steps away, and so on, until a solution is found. BFS guarantees that the first solution you find will be as short as any other.

strategy:
 start by examining ladders that are one step away from the original word, where only one letter is changed. Then check all ladders that are two steps away, where two letters have been changed. Then three, four, etc. 
using:We implement the breadth-first algorithm using a queue to store partial ladders that represent possibilities to explore. Each partial ladder is a stack, which means that your overall collection is a **queue of stacks.**

we have out pseudo code
Finding a word ladder between words w1 and w2:
	Create an empty queue of stacks.
  	Create/add a stack containing {w1} to the queue. 
  	While the queue is not empty:
		Dequeue the partial-ladder stack from the front of the queue.
		For each valid English word that is a "neighbor" (differs by 1 letter) 
		of the word on top of the stack:
			If that neighbor word has not already been used in a ladder before: 
				If the neighbor word is w2:
					Hooray! we have found a solution (and it is the stack you are working on in the queue).
				Otherwise:
					Create a copy of the current partial-ladder stack. 
					Put the neighbor word on top of the copy stack. 
					Add the copy stack to the end of the queue.


some of the code corresponds almost one-to-one with actual c++ code. one abstract part is the neighbor. how to define a same length word with only one letter different.

one way is to loop the given dict, which is way too slow. we should loop through the alphabet of every position in the word. which is a n-26 loop
each loop word should go through the dict, to check is a valid word or not.

then it's to keep it shortest. cut off the middle. so first step to form a queue, then try to cut shorter. 
also need to caution that word may cause infinite loop

Another subtle issue is that you do not reuse words that have been included in a previous shorter ladder. 

思路: 解决这个问题--> partial ladder
 partial ladder cat → cot → cog → to the queue. Lateron, if your code is processing ladder cat → cot → con, one neighbor of con is cog, so you might want to examine cat → cot → con → cog. 

设计上, 保存每一个字串 每一个字串进入队列  在没法向下打时候自动出列 则留下能继续的串
唯一性 就是当找下个打时候 不使用之前哪怕不能继续进行打串已经用过打词

如果改为 最长路径 则要使用那些没走的串用过打词 但是不能重复使用本队列中打单词即可 所以字典不需要 而且只要

最长路径打考虑,如果是按照alphabetic排序 也是唯一的
那么循环打终止条件不再是找到目标单词
而是将所有能到达打路径全部存下来,找最长打,再利用set把其中打重复去除

内存资源占用多 用小字典

## PartB Random writter

you will write a program that reads an input file and uses it to build a large data structure of word groups called "N- grams" as a basis for randomly generating new text that sounds like it came from the same author as that file.

using:Map / Vector 

### step1 building map of Ngram

into steps:
1 welcome
2 read input:Unlike in the previous assignment, here we are interested in each word. If you want to read a file one word at a time, an effective way to do so is using the input >> variable; syntax rather than getLine, etc.



### step2 generate random text
Each particular piece of text randomly generated in this way is also called a Markov chain. Markov chains are very useful in computer science and elsewhere, such as artificial intelligence, machine learning, economics, and statistics.

