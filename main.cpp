
/*
 * Data Structures - Internal Activity 3, Question 2
 * PRN: 202501100047
 * Scenario: Student Marks
 * Seed: 47
 * Hash Function: Mid-Square Method
 * Collision Handling: Separate Chaining
 */

#include <iostream>
#include <string>
using namespace std;

const long long PRN = 202501100047LL;
const int SEED = 47;
const int M = 10;
const int N = 20;

// Student names
const string NAMES[N] = {
    "Student01", "Student02", "Student03", "Student04",
    "Student05", "Student06", "Student07", "Student08",
    "Student09", "Student10", "Student11", "Student12",
    "Student13", "Student14", "Student15", "Student16",
    "Student17", "Student18", "Student19", "Student20"
};

// Array to store student marks
int marks[N];

int main() {
    cout << "Student Marks Hash Table" << endl;
    cout << "PRN: " << PRN << endl;
    cout << "Seed: " << SEED << endl;
    cout << "Table Size: " << M << endl;
    cout << "Dataset Size: " << N << endl;

    cout << "\nProject setup completed." << endl;

    return 0;
}
