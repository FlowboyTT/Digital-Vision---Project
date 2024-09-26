#include <iostream> // Include the standard input/output library header

using namespace std; // Use the standard namespace

struct Node {
    int data; // Data stored in the node
    Node* next; // Pointer to the next node in the list

    Node(int data) : data(data), next(nullptr) {} // Constructor to initialize data and next pointer
};

class ForwardLinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    ForwardLinkedList() : head(nullptr) {} // Constructor to initialize the head pointer

    // Insert a new node at the front of the list
    void insertAtFront(int data) {
        Node* newNode = new Node(data); // Create a new node with the given data
        newNode->next = head; // Set the next pointer of the new node to the current head
        head = newNode; // Update the head to point to the new node
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data); // Create a new node with the given data

        if (!head) { // If the list is empty
            head = newNode; // Set the new node as the head
        } else {
            Node* current = head;
            while (current->next) { // Traverse the list until the last node
                current = current->next;
            }
            current->next = newNode; // Set the next pointer of the last node to the new node
        }
    }

    // Insert a new node at a specific position in the list
    void insertAtPosition(int data, int position) {
        if (position <= 0) { // Check for invalid position
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(data); // Create a new node with the given data

        if (position == 1) { // Insert at the beginning
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int pos = 1;
            while (current && pos < position - 1) { // Traverse the list until the node before the desired position
                current = current->next;
                pos++;
            }

            if (current) { // If the desired position exists
                newNode->next = current->next; // Set the next pointer of the new node to the node at the current position
                current->next = newNode; // Set the next pointer of the node before the desired position to the new node
            } else {
                cout << "Invalid position" << endl;
            }
        }
    }

    // Delete the first node in the list
    void deleteFirstNode() {
        if (!head) { // Check for empty list
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head; // Store the head node temporarily
        head = head->next; // Update the head to point to the next node
        delete temp; // Delete the old head node
    }

    // Delete the last node in the list
    void deleteLastNode() {
        if (!head) { // Check for empty list
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == nullptr) { // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next) { // Traverse the list until the node before the last node
                current = current->next;
            }
            delete current->next; // Delete the last node
            current->next = nullptr; // Set the next pointer of the second-to-last node to nullptr
        }
    }

    // Delete a node at a specific position in the list
    void deleteAtPosition(int position) {
        if (position <= 0) { // Check for invalid position
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1) { // Delete the first node
            deleteFirstNode();
        } else {
            Node* prev = head;
            Node* current = head->next;
            int pos = 2;

            while (current && pos < position) { // Traverse the list until the node at the desired position
                prev = current;
                current = current->next;
                pos++;
            }

            if (current) { // If the desired position exists
                prev->next = current->next; // Set the next pointer of the node before the desired position to the node after the desired position
                delete current; // Delete the node at the desired position
            } else {
                cout << "Invalid position" << endl;
            }
        }
    }

    // Print the elements of the list
    void printList() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    ForwardLinkedList list; // Create an instance of the ForwardLinkedList class

    list.insertAtFront(5); // Insert 5 at the front
    list.insertAtFront(4); // Insert 4 at the front
    list.insertAtFront(3); // Insert 3 at the front
    list.insertAtFront(2); // Insert 2 at the front
    list.insertAtFront(1); // Insert 1 at the front

    cout << "Original list: ";
    list.printList();

    list.insertAtPosition(6, 3); // Insert 6 at position 3
    cout << "List after inserting 6 at position 3: ";
    list.printList();

    list.deleteFirstNode(); // Delete the first node
    cout << "List after deleting the first node: ";
    list.printList();

    list.deleteLastNode(); // Delete the last node
    cout << "List after deleting the last node: ";
    list.printList();

    list.deleteAtPosition(2); // Delete the node at position 2
    cout << "List after deleting the node at position 2: ";
    list.printList();

    return 0;
}
