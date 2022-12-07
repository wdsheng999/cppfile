/*
 * CS 106B, Marty Stepp
 *
 * This program contains code for various sorting algorithms
 * including insertion sort, selection sort,
 * recursive merge sort, and in-place quick sort.
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "filelib.h"
#include "random.h"
#include "vector.h"
#include "timer.h"
#include "support.h"
#include "shuffle.h"

using namespace std;

// constants
static const int INITIAL_SIZE = 10;         // starting size of array

// function prototype declarations
int requestTest();
void selectionSort(Vector<int>& v);
void insertionSort(Vector<int>& v);
void mergeSort(Vector<int>& v);
void merge(Vector<int> &vec, Vector<int> &v1, Vector<int> &v2);
void quickSort(Vector<int>& vec);
void quickSort(Vector<int> &vec, int start, int finish);
void naiveQuickSort(Vector<int> &v);
void swap(Vector<int>& v, int i, int j);

int main() {
    int maxSize;

    int testNum = requestTest();
    while (testNum != -1) {
        switch (testNum) {
        case 0: // insertion sort
        case 1: // selection sort
            maxSize = 50000;
            break;
        case 2: // merge sort
            maxSize = 2000000;
            break;
        case 3: // quicksort
        case 4:
            maxSize = 10000000;
            break;
        }
        cout << endl;
        for (int N = INITIAL_SIZE; N <= maxSize; N *= 2) {
            // cout << "Creating the vector..." << endl;
            Vector<int> v;
            fillRandomIntVector(v, N);

            // perform the sort time how long it takes
            Timer tim(true);

            switch (testNum) {
            case 0:
                insertionSort(v);
                break;
            case 1:
                selectionSort(v);
                break;
            case 2:
                mergeSort(v);
                break;
            case 3:
                quickSort(v);
                break;
            case 4:
                naiveQuickSort(v);
                break;
            }

            long elapsedTime = tim.stop();

            if (!isSorted(v)) {
                throw "Vector is not sorted!";
            }

            cout << "N=" << setw(8) << N << ", time=" << setw(5) << elapsedTime << endl;
        }
        cout << endl;
        testNum = requestTest();
    }
    cout << "Goodbye!" << endl;
    
    return 0;
}

int requestTest() {
    int response = -2; // initial condition
    cout << "Sorting Tests" << endl;
    cout << "0. Insertion Sort" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Quicksort (in-place)" << endl;
    cout << "4. Quicksort (naive)" << endl;
    cout << endl;
    while (response < -1 or response > 4) {
        response = getInteger("Please choose an option (0-3), -1 to quit: ");
    }
    return response;
}

/*
 * Rearranges the elements of v into sorted order using
 * the selection sort algorithm.
 */
void selectionSort(Vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        // walk across the array looking for the smallest value
        int smallestIndex = i;
        for (int j = i+1; j < v.size(); j++) {
            if (v[j] < v[smallestIndex]) {
                smallestIndex = j;
            }
        }
        // swap v[i] with v[smallestIndex]
        swap(v, i, smallestIndex);
    }
}

/*
 * Rearranges the elements of v into sorted order using
 * the insertion sort algorithm.
 */
void insertionSort(Vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int temp = v[i];
        
        // slide elements right to make room for v[i]
        int j = i;
        while (j >= 1 && v[j - 1] > temp) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = temp;
    }
}

// Rearranges the elements of v into sorted order using
// the merge sort algorithm.
void mergeSort(Vector<int> &vec) {
    int n = vec.size();
    if (n <= 1) return;
    Vector<int> v1;
    Vector<int> v2;
    for (int i=0; i < n; i++) {
        if (i < n / 2) {
            v1.add(vec[i]);
        } else {
            v2.add(vec[i]);
        }
    }
    mergeSort(v1);
    mergeSort(v2);
    vec.clear();
    merge(vec, v1, v2);
}

// Merges the left/right elements into a sorted result.
// Precondition: left/right are sorted, and vec is empty
void merge(Vector<int> &vec, Vector<int> &v1, Vector<int> &v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    int p1 = 0;
    int p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (v1[p1] < v2[p2]) {
            vec.add(v1[p1++]);
        } else {
            vec.add(v2[p2++]);
        }
    }
    while (p1 < n1) {
        vec.add(v1[p1++]);
    }
    while (p2 < n2) {
        vec.add(v2[p2++]);
    }
}

// Partitions a with elements < pivot on left and
// elements > pivot on right;
// returns index of element that should be swapped with pivot
int partition(Vector<int> &vec, int start, int finish) {
    int pivot = vec[start];
    int lh = start + 1;
    int rh = finish;

    while (true) {
        while (lh < rh && vec[rh] >= pivot) rh--;
        while (lh < rh && vec[lh] < pivot) lh++;
        if (lh == rh) break;

        // swap
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }

    if (vec[lh] >= pivot) return start;
    vec[start] = vec[lh];
    vec[lh] = pivot;
    return lh;
}

void quickSort(Vector<int> &vec, int start, int finish) {
    if (start >= finish) return;
    int boundary = partition(vec, start, finish);
    quickSort(vec, start, boundary - 1);
    quickSort(vec, boundary + 1, finish);
}

/*
 * Rearranges the elements of v into sorted order using
 * a recursive quick sort algorithm.
 */
void quickSort(Vector<int> &vec) {
    quickSort(vec, 0, vec.size() - 1);
}


Vector<int> naiveQuickSortHelper(Vector<int> v) { // not passed by reference!
    // base case: list of 0 or 1
    if (v.size() < 2) {
        return v;
    }
    // choose pivot to be left-most element
    int pivot = v[0];

    // create two new vectors to partition into
    Vector<int> left, right;

    // put all elements <= pivot into left
    // and all elements > pivot into right
    for (int i=1; i<v.size(); i++) {
        if (v[i] <= pivot) {
            left.add(v[i]);
        }
        else {
            right.add(v[i]);
        }
    }
    left = naiveQuickSortHelper(left); // recursively deal with the left
    right = naiveQuickSortHelper(right); // recursively deal with the right

    // put the pivot at the end of the left
    left.add(pivot);

    // return the combination of left and right
    return left + right;
}

void naiveQuickSort(Vector<int> &v) {
    v = naiveQuickSortHelper(v);
}

/*
runtimes:

insertion sort:
N=      10, time=    0
N=      20, time=    0
N=      40, time=    0
N=      80, time=    0
N=     160, time=    0
N=     320, time=    2
N=     640, time=    6
N=    1280, time=   24
N=    2560, time=   90
N=    5120, time=  360
N=   10240, time= 1431
N=   20480, time= 5753
N=   40960, time=22541

selection sort
N=      10, time=    0
N=      20, time=    0
N=      40, time=    0
N=      80, time=    0
N=     160, time=    1
N=     320, time=    3
N=     640, time=    8
N=    1280, time=   33
N=    2560, time=  128
N=    5120, time=  514
N=   10240, time= 1992
N=   20480, time= 8041
N=   40960, time=32282

merge sort:
N=      10, time=    0
N=      20, time=    0
N=      40, time=    0
N=      80, time=    0
N=     160, time=    0
N=     320, time=    1
N=     640, time=    1
N=    1280, time=    3
N=    2560, time=    6
N=    5120, time=   13
N=   10240, time=   27
N=   20480, time=   57
N=   40960, time=  112
N=   81920, time=  238
N=  163840, time=  501
N=  327680, time= 1059
N=  655360, time= 2259
N= 1310720, time= 4377

quick sort (in-place):
N=      10, time=    0
N=      20, time=    0
N=      40, time=    0
N=      80, time=    0
N=     160, time=    0
N=     320, time=    0
N=     640, time=    1
N=    1280, time=    1
N=    2560, time=    2
N=    5120, time=    4
N=   10240, time=    8
N=   20480, time=   15
N=   40960, time=   33
N=   81920, time=   69
N=  163840, time=  144
N=  327680, time=  297
N=  655360, time=  648
N= 1310720, time= 1369
N= 2621440, time= 2781
N= 5242880, time= 5792

naive quicksort:
N=      10, time=    0
N=      20, time=    0
N=      40, time=    0
N=      80, time=    0
N=     160, time=    1
N=     320, time=    1
N=     640, time=    2
N=    1280, time=    3
N=    2560, time=    6
N=    5120, time=   13
N=   10240, time=   27
N=   20480, time=   57
N=   40960, time=  116
N=   81920, time=  239
N=  163840, time=  498
N=  327680, time= 1038
N=  655360, time= 2203
N= 1310720, time= 4632
N= 2621440, time= 9594
N= 5242880, time=21367

*/
