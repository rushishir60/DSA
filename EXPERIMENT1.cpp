#include <iostream>
using namespace std;

const int SIZE = 100;  // Hash table size

// Structure for storing a record
struct Record {
    string name, phone;
    bool occupied = false;
};

// Hash table class using linear probing
class PhoneBook {
    Record table[SIZE];

    // Simple hash function
    int hash(string name) {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) sum += name[i];
        return sum % SIZE;
    }

public:
    void insert(string name, string phone) {
        int idx = hash(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (idx + i) % SIZE;
            if (!table[pos].occupied) {
                table[pos] = { name , phone, true};
                cout << "Record added.\n";
                return;
            }
        }
        cout << "Table full!\n";
    }

    void search(string name) {
        int idx = hash(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (idx + i) % SIZE;
            if (table[pos].occupied && table[pos].name == name) {
                cout << "Found: " << table[pos].phone << "\n";
                return;
            }
        }
        cout << "Not found.\n";
    }

    void update(string name, string newPhone) {
        int idx = hash(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (idx + i) % SIZE;
            if (table[pos].occupied && table[pos].name == name) {
                table[pos].phone = newPhone;
                cout << "Updated.\n";
                return;
            }
        }
        cout << "Not found.\n";
    }

    void remove(string name) {
        int idx = hash(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (idx + i) % SIZE;
            if (table[pos].occupied && table[pos].name == name) {
                table[pos].occupied = false;
                cout << "Deleted.\n";
                return;
            }
        }
        cout << "Not found.\n";
    }

    void display() {
        cout << "\nName\tPhone\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << table[i].name << "\t" << table[i].phone << "\n";
        }
    }
};

// Main function with input validation
int main() {
    PhoneBook pb;
    int choice;
    string name, phone;

    while (true) {
        cout << "\n1.Insert 2.Display 3.Search 4.Update 5.Delete 6.Exit\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Name: "; cin >> name;
                cout << "Phone: "; cin >> phone;
                pb.insert(name, phone); break;
            case 2: pb.display(); break;
            case 3:
                cout << "Search name: "; cin >> name;
                pb.search(name); break;
            case 4:
                cout << "Name: "; cin >> name;
                cout << "New phone: "; cin >> phone;
                pb.update(name, phone); break;
            case 5:
                cout << "Name to delete: "; cin >> name;
                pb.remove(name); break;
            case 6: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
