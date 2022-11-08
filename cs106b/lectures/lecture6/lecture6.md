•Logistics:
•Tiny Feedback: some responses!
•Not enough motivation for why we care about ADTs: good point!
•More interactive classes: I'll see what I can do!
•KEY pages (
)
•Late credits change: up to two calendar days equals one late credit. You get
three automatic late credits per quarter.
•the "const" qualifier
•Postfix refresher
•Structs (details will come later!)
•Sets
•Maps

## const 
tell the compiler that the object passed cannot be changed 
 i.e. we print the grid in a way that using ref but not changing
 ``void printLifeGrid(Grid<char> cont &lifeGrid);``

## struct
another way to output many results in return
pack them up in a struct 
- define a new type for us to use
i.e.
```c
struct Roots{
    double root1;
    double root2;
};

/*
* Solves a quadratic equation ax^2 + bx + c = 0,
* storing the results in output parameters root1 and root2.
* Assumes that the given equation has two real roots.
*/
Roots quadratic(double a, double b, double c){
    Roots roots;
    double d=sqrt(b*b-4*a*c);
    roots.root1=(-b+d)/(2*a);
    roots.root2=(-b-d)/(2*a);
    return roots;
}
```

## sets and maps

sets: collection with no duplicate
maps: key/value
```c
Set<string> friends;
friend.add("chris");
friend.add("anton");
cout<<friends.contains("voldemort")<<endl;
for(string person:friends){
    cout<<person<<endl;}
```

### set
binary search tree --> sorted order
size
add
contains
remove
isEmpty

how to loop a set?

### hashset
hash table --> unsorted order


## map
a generalization of an array, which the index is no number

put get

### generate a map
```c
Map<string,int>votes;
Map<string,Vector<string>> friendMap;
```

### method 
clear sontainsKey isEmpty .keys()
m[key]=value / m.put(key,value)
m.size m.toString m.values m.remove(key)

### map example

```c
Map<string,string>wiki;
wiki.put("neopalpa donaldtrump",articleHTML);
cout<<wiki.get("yosemite national park");
wiki.remove("Bratian in the E.U.");
```

### hashmap

order is unpredictable in a hashmap

### loop a map
```c
Map<string, double> gpa=load();
for(string name:gpa){
    cout....
}
