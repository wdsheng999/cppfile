#include"mygrid.h"
#include<iostream>

using namespace std;

// void Make_Grid(char *Grid)
// {
	
// 	char  Grid[6][14] = {
// 		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
// 		{ ' ', '\xDA', '\xC4', '\xC2', '\xB3', '\xBF', '\xB3', '\xC3', '\xC4', '\xC5', '\xB4', '\xC0', '\xC1', '\xD9' },
// 		{ ' ', '\xC9', '\xCD', '\xCB', '\xBA', '\xBB', '\xBA', '\xCC', '\xCD', '\xCE', '\xB9', '\xC8', '\xCA', '\xBC' },
// 		{ ' ', '\xC9', '\xCD', '\xD1', '\xBA', '\xBB', '\xB3', '\xC7', '\xC4', '\xC5', '\xB6', '\xC8', '\xCF', '\xBC' },
// 		{ ' ', '\xD6', '\xC4', '\xD2', '\xBA', '\xB7', '\xBA', '\xC7', '\xC4', '\xD7', '\xB6', '\xD3', '\xD0', '\xBD' },
// 		{ ' ', '\xD5', '\xCD', '\xD1', '\xB3', '\xB8', '\xB3', '\xC6', '\xCD', '\xD8', '\xB5', '\xD4', '\xCF', '\xBE' },

// 	};
// }

int main(){
    char  Grid[6][14] = {
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', '\xDA', '\xC4', '\xC2', '\xB3', '\xBF', '\xB3', '\xC3', '\xC4', '\xC5', '\xB4', '\xC0', '\xC1', '\xD9' },
		{ ' ', '\xC9', '\xCD', '\xCB', '\xBA', '\xBB', '\xBA', '\xCC', '\xCD', '\xCE', '\xB9', '\xC8', '\xCA', '\xBC' },
		{ ' ', '\xC9', '\xCD', '\xD1', '\xBA', '\xBB', '\xB3', '\xC7', '\xC4', '\xC5', '\xB6', '\xC8', '\xCF', '\xBC' },
		{ ' ', '\xD6', '\xC4', '\xD2', '\xBA', '\xB7', '\xBA', '\xC7', '\xC4', '\xD7', '\xB6', '\xD3', '\xD0', '\xBD' },
		{ ' ', '\xD5', '\xCD', '\xD1', '\xB3', '\xB8', '\xB3', '\xC6', '\xCD', '\xD8', '\xB5', '\xD4', '\xCF', '\xBE' },

	};

    for(auto i : Grid){
        cout<<i<<" "<<endl;
    }
    
}