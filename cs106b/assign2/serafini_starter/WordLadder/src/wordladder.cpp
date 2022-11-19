
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include"simpio.h"
#include"lexicon.h"
#include"stack.h"
#include"queue.h"
#include"hashset.h"
using namespace std;
//-----------------data---------

fstream input;
Lexicon dic;
string start;
string endword;
Set<Stack<string>> storeSet;
//----------------func----------
void welcomeinfo();
void loadDictionary(Lexicon& dic);
bool loadWords(string& start, string& endword);
bool checkWord(string& start, string& endword,const Lexicon& dic);
Set<Stack<string>> ladderSet(string& start, string& endword, Lexicon& dic);
HashSet<string> neighborWord(string& word,const Lexicon& dic);
void longLadder(Set<Stack<string>>& storeSet);
//main
int main(){
    welcomeinfo();
    loadDictionary(dic);
    while(loadWords(start,endword)){
        if(checkWord(start,endword,dic)){
            Set<Stack<string>> storeSet= ladderSet(start,endword,dic);
            longLadder(storeSet);

        }
    }

    cout << "Have a nice day." << endl;
    return 0;
    return 0;
}

void welcomeinfo(){
    cout << "Welcome to CS 106B Word Ladder.\n"
            << "Please give me two English words, and I will change the\n"
            << "first into the second by changing one letter at a time.\n\n";
}

void loadDictionary(Lexicon& dic){
    string filename=getLine("Dictionary file name?");
    fstream input;
    do{
         input.open(filename);
    }while(input.fail());
    dic=Lexicon(input);
}

bool loadWords(string& start,string& endword){
    start=getLine("Word #1 (or Enter to quit):");
    endword=getLine("Word #2 (or Enter to quit):");
    if(start.empty()||endword.empty()){
        return false;
    }
    start=toLowerCase(start);
    endword=toLowerCase(endword);
    return true;
}
bool checkWord(string& start, string& endword,const Lexicon& dic)
{
    if(start.length()!=endword.length()){
        cout<<"The two words must be the same length.\n";
        return false;
    }else if(!dic.contains(start)||!dic.contains(endword)){
        cout<<"must be in the dic"<<endl;
        return false;
    }else if(start==endword){
        cout<<"two words must not be same"<<endl;
        return false;

    }
    return true;
}

Set<Stack<string>> ladderSet(string& start, string& endword, Lexicon& dic)
{
    Stack<string> partialLadder{start};
    Queue<Stack<string>> LadderQueue{partialLadder};
    Set<Stack<string>> storeSet;
    while(!LadderQueue.isEmpty()){
        Stack<string> currLadder=LadderQueue.dequeue();
        string currWord=currLadder.peek();
        if(currWord==endword){
            //solution find, save the stack for final compare
            storeSet.add(currLadder);
        }else{
            //find neighbor, no repeatence before
            Set<string> beforeset;
            Stack<string> beforeStack=currLadder;
            while(!beforeStack.isEmpty()){
                string tmp=beforeStack.pop();
                beforeset.add(tmp);
            }
            for(string neighbor:neighborWord(currWord,dic)){
                if(!beforeset.contains(neighbor)){
                    Stack<string> copyLadder=currLadder;
                    copyLadder.push(neighbor);
                    LadderQueue.enqueue(copyLadder);
                }

            }
        }
    }

    return storeSet;
}
HashSet<string> neighborWord(string& word,const Lexicon& dic)
{
    HashSet<string> neighbors;
    string tmp=word;
    for(int i=0;i<word.length();i++)
    {
        for(char ch='a';ch<='z';ch++){
            tmp[i]=ch;
            if(dic.contains(tmp)){
                neighbors.add(tmp);
            }
        }
        tmp=word;
    }
    return neighbors;
}

void longLadder(Set<Stack<string>>& storeSet){
    cout<<storeSet.toString();
}
