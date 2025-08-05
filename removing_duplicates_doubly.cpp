#include <iostream>
using namespace std;

// Definition of a doubly linked list node
struct Node
{
  int data;
  Node *prev;
  Node *next;

  Node(int val)
  {
    data = val;
    prev = nullptr;
    next = nullptr;
  }
};

// Function to insert a node at the end of the DLL
void insertAtEnd(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (!head)
  {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

// Function to remove duplicates from sorted DLL
Node *removeDuplicates(Node *head)
{
  Node *temp = head;

  while (temp && temp->next)
  {
    if (temp->data == temp->next->data)
    {
      Node *duplicate = temp->next;
      temp->next = duplicate->next;
      if (duplicate->next)
      {
        duplicate->next->prev = temp;
      }
      delete duplicate;
    }
    else
    {
      temp = temp->next;
    }
  }

  return head;
}

// Function to print the DLL
void printList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data;
    if (temp->next)
      cout << " <-> ";
    temp = temp->next;
  }
  cout << endl;
}

// Main function
int main()
{
  Node *head = nullptr;

  // Inserting sorted elements (with duplicates)
  insertAtEnd(head, 1);
  insertAtEnd(head, 1);
  insertAtEnd(head, 2);
  insertAtEnd(head, 3);
  insertAtEnd(head, 3);
  insertAtEnd(head, 4);
  insertAtEnd(head, 5);
  insertAtEnd(head, 5);
  insertAtEnd(head, 5);

  cout << "Original list: ";
  printList(head);

  head = removeDuplicates(head);

  cout << "After removing duplicates: ";
  printList(head);

  return 0;
}
