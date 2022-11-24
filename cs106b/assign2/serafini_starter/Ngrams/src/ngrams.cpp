// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include"map.h"
#include"vector.h"
#include"simpio.h"
#include"random.h"

using namespace std;
void welcome();
void getInputFile(fstream& input,string& filename, int& gramN);
Map<Vector<string>,Vector<string>> generateNgram(const int& gramN,fstream& input);
void newLine(Map<Vector<string>,Vector<string>>& ngramMap);
int main() {
    // TODO: Finish the program!
    fstream input;//input
    string filename;
    int gramN=0;
    Map<Vector<string>,Vector<string>> ngramMap;

    welcome();
    getInputFile(input,filename,gramN);
    ngramMap= generateNgram(gramN,input);
    newLine(ngramMap);
    cout << "Exiting." << endl;
    return 0;
}
void welcome(){
    cout<<"Welcome to CS 106B Random Writer ('N-Grams').\n\
    This program makes random text based on a document. \n\
    Give me an input file and an 'N' value for groups \n\
    of words, and I'll create random text for you."<<endl;
}

void getInputFile(fstream& input,string& filename, int& gramN){

    do{
        filename=getLine("Input file name?");
        input.open(filename);
        if(!input.is_open()){
            cout<<"Unable to open that file.  Try again."<<endl;
        }
    }while(!input.is_open());

    do{
        gramN=getInteger("Value of N?");
        if(gramN<2){
            cout<<"N must be 2 or greater."<<endl;
        }

    }while(gramN<2);

}
Map<Vector<string>,Vector<string>> generateNgram(const int& gramN,fstream& input){
    Map<Vector<string>,Vector<string>> ngramMap;
    string word;
    Vector<string> wordlist;
    Vector<string> window,suffix;
    while(input>>word){
        wordlist.add(word);
    }
    for(int i=0;(i<wordlist.size());i++){
        window.clear();
        suffix.clear();
        //gene window
        for(int j=i;j<i+gramN-1;j++){
            window.add(wordlist.get(j%wordlist.size()));
        }
        //gene suffix
        int suffix_num=(i+gramN-1)%wordlist.size();
        word=wordlist.get(suffix_num);
        if (ngramMap.containsKey(window)){
            //if have, then copy suffix and add new
            suffix=ngramMap.get(window);
            suffix.add(word);
            ngramMap.put(window,suffix);
        }
        else{
            //if don't have, put suffix
            suffix.add(word);
            ngramMap.put(window,suffix);
        }
        //cout<<ngramMap.toString()<<endl;

    }
    return ngramMap;
}

void newLine(Map<Vector<string>,Vector<string>>& ngramMap){
    int n;

    n=getInteger("# of random words to generate (0 to quit)?");
    while(n!=0 && n<4){
        cout<<"Must be at least 4 words."<<endl;
        n=getInteger("# of random words to generate (0 to quit)?");
    }
    while(n>=4){

        Vector<string> line;
        Vector<Vector<string>>windowlist=ngramMap.keys();
        int length=windowlist.size()-1;

        //initialize the begining
        Vector<string> window=windowlist.get(randomInteger(0,length));
        Vector<string>suffixlist=ngramMap.get(window);
        string suffix=suffixlist.get(randomInteger(0,suffixlist.size()-1));
        for(auto str : window){
            line.add(str);
        }
        line.add(suffix);
        //cout<<line.toString()<<endl;
        //finish the vector
        while(line.size()<n){
            //cout<<"processing..."<<endl;
            window.remove(0);
            window.add(suffix);
            //cout<<window<<endl;
            suffix=randomElement(ngramMap.get(window));
            line.add(suffix);}
        cout<<"... ";
        for(auto j : line){
            cout<<j<<" ";
        }
        cout<<"..."<<endl;
        n=getInteger("# of random words to generate (0 to quit)?");
    }
}


