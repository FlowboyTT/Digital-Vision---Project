#include <iostream>

using namespace std;
// Define a node structure represent an element in the linked list
struct  Node
{
  int data; // Data stored in the node
  Node* next; // Pointer to the next node in the list

   // Constructor to initialize a new node with given data
  Node(int new_data)
  {
      data= new_data;
      next= nullptr;
  }
};
// Function to insert a new node at the front of the linked list
Node* insertAtFront(Node*head, int new_data)
{
Node* new_node= new Node(new_data); //Create a new node with the given data

    new_node->next= head; ////Make the new node point to the current head(old first node)

//Update the head to point to the new node (new first node)
    return new_node;
}
void printList(Node* head) // function to print the elements of the linked list
{
    Node* curr= head; // start from the head node
// iterate through the list until the end is reached
    while(curr !=nullptr)
    {
        cout<<" "<<curr->data; // print the data of the current node
        curr= curr->next; // move to the next node
    }
     cout<<endl; // Print a newline to separate the list from the other output
}

int main () // main function to create and manipulate the linked list
{
     //Create a linked list with initial nodes
    Node* head= new Node(6);
    head->next= new Node(3);
    head->next->next= new Node(4);
    head->next->next->next= new Node(5);
     //Print the original linked list
    cout<<"Original Linked List:"; printList(head);

    cout<<"After inserting Nodes at the front:"; // print updated list
    int data= 1;  //insert new node at the front with data 1
    head= insertAtFront(head,data); printList(head);

    return 0;
}
