#include <iostream>
#include <algorithm> // Include the algorithm header for max
using namespace std;

#define MAX_OF_THREE(x, y, z) max({x, y, z})

int main() {
    int num1, num2, num3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    int largestNumber = MAX_OF_THREE(num1, num2, num3);

    cout << "The largest number is: " << largestNumber <<endl;

    return 0;
}
