# recursion
• Logistics:
• Tiny Feedback:
• Writing a simple program all by yourself
• Serafini Due Thursday, April 20th, noon
• One submission of two files (wordLadder, Ngrams)
• Recursion!

TODO:
--writing program 
order in Sets: for booleans and integers/doubles, how would the set be ordered? For integers would it be from most negative to positive?

ANS: they are in order of the negative to positive order.
./code/mainRecurse.cpp

Hanoi puzzle --> recursion

## why recursion?
1. great style 
2. power tool
3. master of control flow

如果main调用自身 seg fault


对于数身后人数打例子
```c
int numStudentBehind(Student curr){
    if(noOneBehind(curr)){
        return 0;
    }else{
        Student personBehind = curr.getBehind();
        return numStudentBehind(personBehind)+1
    }
}
```
typical structure: if{no recursion} else(call recursion)

every recursive algorithm involves at least two cases: base case/recursive case

the final case should be turing towards the base case

TODO: write a power()function that returns the x^n

```c
int power(int x,int n){
    if(n==0){
        return 1;
    }else{
        return x*power(x,n-1);
    }
}
```

faster: Ologn by cutting into 2 parts
```c
int power(int x, int n){
    if(n==1) return 1;
    else{
        if(n%2==1){
            //n is odd
            return x*power(x,n-1);
        }else{
            //n is even
            int y=power(x,n/2);
            return y*y;
        }
    }
}

```
## hailstone 
if n==1, done
if n is even, n/2
if n is odd, n=3*n+1

cannot make sure that the direction goes towards the base case.


## tower of hanoi
hard problem to be solved iteratively, but easy in recursion

if only one piece, done
if more than one, we need an auxiliary spindle

```c
void hanoi(int n, char source, char target, char aux)
{
    if (n==1){
        movingSingleDisk(source,target);
    }else{
        findSolution(n-1,source,aux,target);
        moingSingleDisk(source,target);
        findSolution(n-1,aux,target,source);
    }
}
```

see qt for source code

this is a very good example of graphic coding but believe it will be examples in the following

## recap
recursion is about every time a small piece of a large problem

converting decimal to binary
```c
// Prints the given integer's binary representation.
// Precondition: n >= 0
void printBinary(int n) {
if (n < 2) {
// base case; same as base 10
cout << n;
} else {
// recursive case; break number apart
printBinary(n / 2);
printBinary(n % 2);
}
}
```