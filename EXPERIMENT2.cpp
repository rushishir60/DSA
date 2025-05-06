/*

Lab Asssignment 2

Implement all the functions of a dictionary (ADT) using hashing and handle collisions 
using chaining with / without replacement. 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key) 

*/


#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;  // Size of the hash table

// Structure to store key-value pairs (word, meaning)
struct data {
    string name;      // Key (word)
    string name1;     // Value (meaning)
};

// Hashing class with dictionary operations
class hashing {
    data d[SIZE];     // Array of data to store the dictionary

public:
    hashing() {
        // Initialize the dictionary with default values (empty strings)
        for (int i = 0; i < SIZE; i++) {
            d[i].name = "0";
            d[i].name1 = "0";
        }
    }

    // Function to insert key-value pairs into the dictionary
    void insert() {
        int n;
        cout << "\nEnter number of words: ";
        cin >> n;  // Number of words to insert

        for (int j = 0; j < n; j++) {
            string na, na1;
            cout << "\nEnter the word: ";
            cin >> na;
            cout << "Enter the meaning: ";
            cin >> na1;

            // Hash the word and find its position in the hash table
            int sum = 0;
            for (char c : na) {
                sum += c;  // Sum ASCII values of characters
            }
            int x = (sum / na.length()) % SIZE;
            int c = x;  // Store initial index to detect full table

            // Linear probing to handle collisions
            while (true) {
                if (d[x].name == "0") {  // If the position is empty
                    d[x].name = na;
                    d[x].name1 = na1;
                    cout << "Word added.\n";
                    break;
                }
                x = (x + 1) % SIZE;  // Linear probing
                if (c == x) {
                    cout << "\nHash table is full.\n";
                    break;
                }
            }
        }
    }

    // Function to search for a word in the dictionary
    void search() {
        string na;
        cout << "\nEnter word to search: ";
        cin >> na;

        int sum = 0;
        for (char c : na) {
            sum += c;  // Sum ASCII values of characters
        }
        int x = (sum / na.length()) % SIZE;
        int c = x;  // Store initial index to detect the loop

        // Linear probing to handle collisions
        while (true) {
            if (d[x].name == na) {  // Word found
                cout << "\nWord: " << d[x].name << "\nMeaning: " << d[x].name1 << "\n";
                break;
            }
            x = (x + 1) % SIZE;
            if (c == x) {  // We have looped through the table
                cout << "\nWord not found.\n";
                break;
            }
        }
    }

    // Function to delete a word from the dictionary
    void delet() {
        string na;
        cout << "\nEnter word to delete: ";
        cin >> na;

        int sum = 0;
        for (char c : na) {
            sum += c;  // Sum ASCII values of characters
        }
        int x = (sum / na.length()) % SIZE;
        int c = x;  // Store initial index to detect the loop

        // Linear probing to handle collisions
        while (true) {
            if (d[x].name == na) {  // Word found and deleted
                d[x].name = "0";
                d[x].name1 = "0";
                cout << "Word '" << na << "' deleted.\n";
                break;
            }
            x = (x + 1) % SIZE;
            if (c == x) {  // We have looped through the table
                cout << "\nWord not found.\n";
                break;
            }
        }
    }

    // Function to display all words in the dictionary
    void display() {
        cout << "\nKey\tMeaning\n----------------";
        for (int i = 0; i < SIZE; i++) {
            if (d[i].name != "0") {  // Only display non-empty slots
                cout << "\n" << d[i].name << "\t" << d[i].name1;
            }
        }
        cout << "\n";
    }
};

// Main function with menu options
int main() {
    hashing h;  // Create an instance of the hashing class
    int choice;
    bool loop = true;

    while (loop) {
        cout << "\n-------------------------";
        cout << "\n       DICTIONARY        ";
        cout << "\n-------------------------";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Delete";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.insert();  // Insert operation
                break;
            case 2:
                h.display();  // Display all records
                break;
            case 3:
                h.search();  // Search operation
                break;
            case 4:
                h.delet();  // Delete operation
                break;
            case 5:
                loop = false;  // Exit the loop
                break;
            default:
                cout << "\nInvalid choice, please try again.\n";
        }
    }
    return 0;
}
