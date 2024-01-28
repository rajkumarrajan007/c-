#include <iostream>
#include <algorithm> // Include the algorithm header for std max
using namespace std;

// Inline function to obtain the largest of three numbers
inline int maxOfThree(int x, int y, int z) {
    return max({x, y, z});
}

int main() {
    int num1, num2, num3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    int largestNumber = maxOfThree(num1, num2, num3);

    cout << "The largest number is: " << largestNumber << endl;

    return 0;
}
