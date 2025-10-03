#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;


// int sum(int x, int y) {
//     return x + y;
// }
//
// int sum (double x, double y) {
//     return x + y;
// }
//
// int sum (int x, int y, int z) {
//     return x + y + z;
// }
//
// int sum (int x, int y, int z, int w) {
//     return x + y + z + w;
// }
//
// int sum (double x = 0, double y = 0, double z = 0, double w = 0) {
//     return x + y + z + w;
// }


// int sum(const int numbers[], const int n) {
//     if ( n == 0 ) return 0;
//     return numbers[0] + sum(numbers + 1, n - 1);
// }


// section 5


double piSim(int n) {
    srand(time(NULL));
    double hits = 0;
    double misses = 0;

    for (int i = 0; i < n; i++) {

        double y = rand();
        double x = rand();
        y = y / RAND_MAX;
        x = x / RAND_MAX;

        // cout << " x = " << x << endl;
        // cout << " y = " << y << endl;
        //
        // cout << "x squared = " << pow(x,2) << endl;
        // cout << "y squared = " << pow(y,2) << endl;
        //
        //
        // cout << "position = " << sqrt(pow(x,2) + pow(y,2)) << endl;

        if (sqrt(pow(x,2) + pow(y,2)) <= 1) {
            hits++;
        } else {
            misses++;
        }
    }

    // cout << hits << endl;
    // cout << misses << endl;

    double a = (4 * hits / n);

    cout << "pi = " << a << endl;
    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
}

void reverseArray(int arr[], const int n) {
    int tmp[n];
    for (int i = 0; i < n; i++) {
        tmp[i] = arr[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
        cout << arr[i] << ", ";
    }
}



void reverseArrayPtr(int arr[], const int n) {
    int tmp[n];
    for (int i = 0; i < n; i++) {
        *(tmp + i) = *(arr + n - i - 1);
    }
    for (int i = 0; i < n; i++) {
        *(arr + i) = *(tmp + i);
        cout << *(tmp + i) /* --> equivalent to tmp[i] */ << ", ";
    }
}


// suitNames[suitNum - 1] = *(suitNames + suitNums - 1)



const int WIDTH = 0;
const int LENGTH = 0;

void transpose(const int input[][LENGTH], int output[][WIDTH]) {

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            output[i][j] = input[j][i];
        }
    }
}


void intSwap(int &a, int &b) {

    int c = a;

    a = b;

    b = c;

}

void intSwapPtr(int a, int b) {

    int c = a;
    int *ptrA = &a;
    int *ptrC = &c;
    cout << ptrA;

    int *ptrB = &b;

    a = *ptrB;
    b = *ptrC;


    cout << endl << a << ", " << b;


}

void strLength(char * str) {

    int strPtr = *str;
    int i = 1;
    int len = 0;

    while ( ((strPtr + i) >= 65 && (strPtr + i) <= 90) || ((strPtr + i) >= 97 && (strPtr + i) <= 122)) {
        strPtr = *(str + len);

        cout << strPtr << endl;

        len++;
    }
    cout << endl << "length of string is: " << len - 1;

}

void ptrSwap(int a, int b) {
    int *ptr1 = &a, *ptr2 = &b;

    int *c = &a;

    ptr1 = ptr2;

    ptr2 = c;

    cout << *ptr1 << " " << *ptr2;

}

void sevenFive(char * str) {

    char *nthCharPtr = (str+6); // 1

    nthCharPtr -= 2; // 2

    cout << *nthCharPtr << endl; // 3

    char ** pointerPtr = &nthCharPtr; // 4

    cout << *pointerPtr << endl; // 5

    cout << **pointerPtr << endl; // 6

    nthCharPtr += 1; // 7

    cout << 5;

}

int main() {

    piSim(20000);
    int max[] = {1,2,3,4,5,6,7,8,9};
    // printArray(max, 9);

    reverseArray(max, 9);

    cout << endl;

    reverseArrayPtr(max, 9);

    /*
    const char *suitNames[] = {"Clubs","Diamonds","Spades","Clubs"};
    cout << "Enter a suit number (1-4): ";
    unsigned int suitNum;
    cin >> suitNum;
    if (suitNum <= 3) {
        cout << suitNames[suitNum - 1];
    }
    */

    cout << endl << endl;

    strLength("twelve");

    cout << endl;

    int one = 2;
    int two = 1;

    intSwap(one, two);

    intSwapPtr(one, two);

    cout << endl << endl;

    ptrSwap(4,5);

}