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
    for (int i = 0; i < n / 2; ++i) {
        int t = arr[i];
        int fromEnd = n - i - 1;
        arr[i] = arr[fromEnd];
        arr[fromEnd] = t;
    }
}


const int WIDTH = 0;
const int LENGTH = 0;

void transpose(const int input[][LENGTH], const int output[][WIDTH]) {

}

int main() {

    piSim(20000);
    int max[] = {1,2,3,4,5,6,7,8,9};
    // printArray(max, 9);

    reverseArray(max, 9);
}