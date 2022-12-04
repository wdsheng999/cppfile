Logistics:
• Due date for Assignment 3 (Recursion): Thursday, Noon
• Practice midterm: Thursday 8pm-10pm, Bishop Auditorium.

• Common Problem Types for Recursive Backtracking
• Partitionable (determine whether a solution exists)
• Knapsack Problem (find the best solution)
• Maze Solving (find a solution)
• Clumsy Thumbsy (find all solutions)

continue the five problems of last lecture in recursion, we have some examples here to show
## 回溯法 backtracking
code STEP BY STEP
### whether a solution exists--partition 

this is the first example of recursive backtracking, we make some difference that must store some info from previous data.-->时序电路/逻辑电路

Keep track of the two sums! Must use helper function.
Keep removing values from the Vector until we have no more values left
(base case)
Search each possible path
