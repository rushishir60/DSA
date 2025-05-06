/*
Experiment 5 : C++ Program To read details of a book consists of chapters, chapters consist of sections and sections      
               consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.
*/

#include <iostream>
#include <string>
using namespace std;

struct node // Node Declaration
{
    string label;   // Title of the book, chapter, section, or subsection
    int ch_count;   // Count of child elements (chapters, sections, etc.)
    node *child[10]; // Array of child nodes (subsections)
} * root;

class GT // Class Declaration for Book Tree
{
public:
    void create_tree(); // Method to create the book structure
    void display(node *r1); // Method to display the tree structure

    GT() { root = NULL; } // Constructor initializes root to NULL
};

// Method to create the book tree (book -> chapters -> sections -> subsections)
void GT::create_tree()
{
    int tchapters, i, j, k;
    root = new node; // Create root node
    cout << "Enter name of book: ";
    cin.ignore(); // To clear the input buffer before using getline
    getline(cin, root->label); // Read the book name
    cout << "Enter number of chapters in the book: ";
    cin >> tchapters; // Number of chapters
    root->ch_count = tchapters; // Set chapter count

    // Loop to create chapters
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node; // Create a new chapter node
        cout << "Enter the name of Chapter " << i + 1 << ": ";
        cin.ignore(); // Clear the buffer before reading chapter name
        getline(cin, root->child[i]->label); // Read chapter name

        cout << "Enter number of sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count; // Number of sections in the chapter

        // Loop to create sections
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node; // Create new section node
            cout << "Enter Name of Section " << j + 1 << ": ";
            cin.ignore(); // Clear buffer before reading section name
            getline(cin, root->child[i]->child[j]->label); // Read section name
        }
    }
}

// Method to display the tree structure (book -> chapters -> sections)
void GT::display(node *r1)
{
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy---";
        cout << "\nBook title: " << r1->label;
        int tchapters = r1->ch_count; // Get the number of chapters
        for (int i = 0; i < tchapters; i++)
        {
            cout << "\nChapter " << i + 1 << ": " << r1->child[i]->label;
            cout << "\nSections: ";
            for (int j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout << "\n" << r1->child[i]->child[j]->label; // Display section name
            }
        }
    }
    cout << endl;
}

int main()
{
    int choice;
    GT gt; // Create object of GT class
    while (1)
    {
        cout << "\n-----------------";
        cout << "\nBook Tree Creation";
        cout << "\n-----------------";
        cout << "\n1. Create";
        cout << "\n2. Display";
        cout << "\n3. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            gt.create_tree(); // Call create_tree() to create the book structure
            break;
        case 2:
            gt.display(root); // Call display() to show the book structure
            break;
        case 3:
            cout << "Thanks for using this program!!!"; // Exit message
            exit(1); // Exit the program
        default:
            cout << "Wrong choice!!!" << endl; // Handle invalid choice
        }
    }
    return 0;
}
