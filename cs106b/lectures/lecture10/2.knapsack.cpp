#include <vector>
#include <iostream>
using namespace std;

struct objectT
{
    int weight;
    int value;
};

int fillKnapsack(vector<objectT> &objects, int weight, int bestScore)
{
    if (weight < 0)
        return 0;
    int localBestScore = bestScore; // keep track of score
    int obSize = objects.size();
    for (int i = 0; i < obSize; i++)
    {
        objectT originalOb = objects[i];
        int currValue = bestScore + originalOb.value;
        int currWeight = weight - originalOb.weight; // loop and update
        // TIP: remove current to recurse
        objects.erase(objects.begin() + i);
        currValue = fillKnapsack(objects, currWeight, currValue);
        if (localBestScore < currValue)
        {
            localBestScore = currValue;
            cout << "find a solution at" << originalOb.value << endl;
        }
        // replace
        objects.insert(objects.begin() + i, originalOb);
    }

    return localBestScore;
}

int fillKnapsack(vector<objectT> &objects, int targetWeight)
{
    return fillKnapsack(objects, targetWeight, 0);
}

int main()
{
    objectT book, milk, gold, sand;
    book.value = 5;
    book.weight = 5;
    milk.value = 3;
    milk.weight = 4;
    gold.value = 9;
    gold.weight = 9;
    sand.value = 1;
    sand.weight = 1;

    vector<objectT> objects;
    objects.push_back(book);
    objects.push_back(milk);
    objects.push_back(gold);
    objects.push_back(sand);
    int volume;
    while (1)
    {
        cout << "what is the volume of you bag?" << endl;
        cin >> volume;
        int best = fillKnapsack(objects, volume);
        for (vector<objectT>::iterator it = objects.begin(); it != objects.end(); it++)
        {
            cout << ' ' << (*it).value << ":" << (*it).weight;
        }
        cout << endl;
        cout << "target score is 13" << endl;
        cout << "best store is:" << best << endl;
    }

    return 0;
}