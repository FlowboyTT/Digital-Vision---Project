#include <iostream>

using namespace std;

class Node {
public:
 int data;
   Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);

        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteFirstNode() {
        if (!head) {
            cout << "List is empty" << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

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
    LinkedList linkedList;

    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);

    cout << "Original List:" << endl;
    linkedList.printList();

    linkedList.deleteFirstNode();


    cout << "List after deleting the first node:" << endl;
    linkedList.printList();

    return 0;
}
