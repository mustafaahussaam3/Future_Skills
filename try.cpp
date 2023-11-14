#include <iostream>
#include <vector>

using namespace std;

// Function to generate Pascal's Triangle using summation
vector<string> generatePascalTriangle(int n) {
    vector<string> returnValue;

    for (int i = 0; i < n; ++i) {
        string row = "";
        int val = 1; // The first element in each row is always 1

        for (int j = 0; j <= i; ++j) {
            row += to_string(val) + " ";
            val = val * (i - j) / (j + 1);
        }

        row.pop_back(); // Remove the trailing space
        returnValue.push_back(row);
    }

    return returnValue;
}

int main() {
    int n = 10;
    vector<string> pascalTriangle = generatePascalTriangle(n);

    // Print the generated Pascal's Triangle
    for (const string &row : pascalTriangle) {
        cout << row << endl;
    }

    return 0;
}
