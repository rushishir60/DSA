#include <iostream>
#include <string>
using namespace std;

// Define the structure for a Node (Chapter, Section, or Subsection)
struct Node {
    string name;  // Name of the Chapter, Section, or Subsection
    Node* next;   // Pointer to the next node (for sections and subsections)
    
    // Constructor to initialize node with a name
    Node(string n) : name(n), next(nullptr) {}
};

// Function to print the tree (book structure) recursively
void printTree(Node* root, int level = 0) {
    if (root == nullptr) return;

    // Print the current node with indentation based on the level of depth
    for (int i = 0; i < level; i++) cout << "  ";  // Indentation for level
    cout << root->name << endl;

    // Recursively print the next node (children of this node)
    printTree(root->next, level + 1);  // Increase depth level for child nodes
}

// Function to create a simple Chapter node and add sections/subsections
Node* createChapter(string chapterName, string sectionName1, string subsection1, string subsection2) {
    Node* chapter = new Node(chapterName);  // Create chapter node
    Node* section1 = new Node(sectionName1);  // Create section node
    Node* subsec1 = new Node(subsection1);  // Create subsection 1
    Node* subsec2 = new Node(subsection2);  // Create subsection 2

    // Link sections and subsections to the chapter
    chapter->next = section1;  
    section1->next = subsec1;
    subsec1->next = subsec2;  // Linked subsections

    return chapter;  // Return the created chapter
}

int main() {
    // Create the root node for the book
    Node* book = new Node("Book: Introduction to Data Structures");

    // Create a chapter with sections and subsections
    Node* chapter1 = createChapter("Chapter 1: Basics of Data Structures", "Section 1: Introduction", "Subsection 1.1: What is a Data Structure?", "Subsection 1.2: Types of Data Structures");
    Node* chapter2 = createChapter("Chapter 2: Arrays and Linked Lists", "Section 1: Arrays", "Subsection 2.1: Array Basics", "Subsection 2.2: Array Operations");

    // Link chapters to the book
    book->next = chapter1;
    chapter1->next = chapter2;

    // Print the book structure
    cout << "Book Structure:" << endl;
    printTree(book);

    return 0;
}