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

```c
bool partitionable(Vector<int>& nums)
{
    return partitionable(nums,0,0);
}
bool partitionable(Vector<int>& rest, int sum1, int sum2){
    if(rest.isEmpty()){
        return sum1==sum2
    }else{
        int n=rest[0];
        bool answer=partitionable()
    }
}
```

see ./part.cpp for searching an existing result

### knapsack: best solution
first we represent an object with struct

```c
struct objectT{
    int weight;
    int value;
}

int fillKnapsack(vector<objectT>& objects, int weight, int bestScore){
    if(weight<0) return 0;
    int localBestScore=bestScore;//keep track of score
    int obSize=objects.size();
    for (int i=0;i<obSize;i++){
        object
    }
    
}

int fillKnapsack(vector<objectT>& objects, int targetWeight)
{
    return fillKnapsack(objects,targetWeight,0);
}
```

### maze solving:find a solution
A classic example of backtracking is solving a
maze: if you go down one path and it isn't the
correct path, then you backtrack to your last
decision point to try an alternate path.

you need to un-choose the path already used that fail, or mark 

you need to mark the path before entering for making sure not going twice

The code for today's class includes a text-based
recursive maze creator and solver.
The mazes look like the one to the right
• There is a Start (marked with an "S") and a
Finish (marked with an "F").
• The Xs represent walls, and the spaces
represent paths to walk through the maze.
<img src="./maze%20in%20text.png">
The program will put dots in the correct positions.
<img src="./maze%20solved.png">

and it will also put b in the wrong way 

#### method
 hand on wall, notice that circular maze will disrupt it
 backtracking, keep track of where you've been
 use compass directions. e.g. N/E/S/W

follow this method we can have
    mark positions we have seen with a period ('.'), and mark backtracking with 'b'.

start: row=1 col=1, marking .
try all the path N/E/S/W. if we hit the wall, change direction.
 N-->row=0,col=1,'X' E--> rol=1,col=2, marking .
 ...
 fail all direction, marking b, back to last pos
 what next? we check south to get there, so finishing with checking south. -->fail--> mark as b--> back
 we use recursion to do it and return back quick

start to write recursion:
 1. base case
    (1) If we go out of the bounds of the maze (the grid bounds).
    • This actually won't happen for our mazes, because we have surrounded all
    paths with walls.
    (2) If we hit a backtracked position ('b')
    •Also won't happen, because once we mark as backtracked, we'll never get
    there again.
    (3) If we hit a wall ('X')
    (4) If we hit a position we have seen before ('.')
    (5) If we find the finish ('F')
 2. check 4 directions, using recursion


### Clumsy Thumbsy: Find All Solutions

