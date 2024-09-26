#include <iostream>
using namespace std;

struct  Node
{
  int data;
  Node* next;

  Node(int new_data)
  {
      data= new_data;
      next= nullptr;
  }
};

Node* insertAtEnd(Node*head, int new_data)
{	//Create a new node with the given data
    Node* new_node= new Node(new_data);

    if(head ==nullptr) // if the list is empty, make the new node the head
    {
        return new_node;
    }

    Node* last= head; // find the last node in the list

    while(last->next !=nullptr)
    {
        last= last->next;
    }
    last->next= new_node; // Append the new node to the end of the list

    return head;
}

void printList(Node* node)
{ 	// iterate through the list and print each node’s data
    while(node !=nullptr)
    {
        cout<<" "<<node->data;
        node= node->next;
    }
}

int main ()
{
    Node* head= new Node(2);
    head->next= new Node(3);
    head->next->next= new Node(4);
    head->next->next->next= new Node(5);
    head->next->next->next->next= new Node(6);

    cout<<"Original Linked List:"; printList(head);

    cout<<"\nAfter inserting Nodes at the end:";
    int data= 1;
    head= insertAtEnd(head,data); printList(head);

    return 0;
}
