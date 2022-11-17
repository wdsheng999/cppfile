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
