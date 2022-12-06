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

