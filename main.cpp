
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
// Generate student marks using seed
void generateMarks() {
    for (int i = 0; i < N; i++) {
        marks[i] = 35 + ((SEED * (i + 1) * 7) % 66);
    }
}

// Display student marks
void displayMarks() {
    cout << "\nGenerated Student Marks:\n";

    for (int i = 0; i < N; i++) {
        cout << NAMES[i] << " : " << marks[i] << endl;
    }
}
// Mid-Square Hash Function
int midSquareHash(int key) {
    long long square = (long long)key * key;
    string str = to_string(square);

    int middle = str.length() / 2;

    return (str[middle] - '0') % M;
}
// Node structure for Separate Chaining
struct Node {
    int studentIndex;
    int mark;
    Node* next;
};

// Hash table with linked list heads
Node* hashTable[M] = {nullptr};
// Insert student using Separate Chaining
void insertStudent(int index) {
    int hashIndex = midSquareHash(marks[index]);

    Node* newNode = new Node;
    newNode->studentIndex = index;
    newNode->mark = marks[index];
    newNode->next = nullptr;

    if (hashTable[hashIndex] == nullptr) {
        hashTable[hashIndex] = newNode;
    }
    else {
        newNode->next = hashTable[hashIndex];
        hashTable[hashIndex] = newNode;
    }
}
// Display Hash Table
void displayHashTable() {
    cout << "\nHash Table using Separate Chaining:\n";

    for (int i = 0; i < M; i++) {
        cout << "Index " << i << " : ";

        Node* temp = hashTable[i];

        while (temp != nullptr) {
            cout << NAMES[temp->studentIndex]
                 << "(" << temp->mark << ") -> ";

            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

int main() {
    cout << "Student Marks Hash Table" << endl;
    cout << "PRN: " << PRN << endl;
    cout << "Seed: " << SEED << endl;
    cout << "Table Size: " << M << endl;
    cout << "Dataset Size: " << N << endl;

    cout << "\nProject setup completed." << endl;
    generateMarks();
    displayMarks();
    cout << "\nMid-Square Hash Values:\n";

    for (int i = 0; i < N; i++) {
        cout << NAMES[i] << " | Marks: " << marks[i]
            << " | Hash Index: " << midSquareHash(marks[i]) << endl;
    }
    // Insert all students into Hash Table
    for (int i = 0; i < N; i++) {
        insertStudent(i);
    }

    // Display Separate Chaining Hash Table
    displayHashTable();

    return 0;
    
}
