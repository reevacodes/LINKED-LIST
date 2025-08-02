#include <iostream>
using namespace std;

// Node class definition
class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    this->data = 0;
    this->next = NULL;
  }

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

// Function to sort linked list of 0s, 1s, and 2s
Node *sortList(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *zeroHead = new Node(-1);
  Node *oneHead = new Node(-1);
  Node *twoHead = new Node(-1);

  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;

  Node *temp = head;

  while (temp)
  {
    if (temp->data == 0)
    {
      zero->next = temp;
      zero = temp;
    }
    else if (temp->data == 1)
    {
      one->next = temp;
      one = temp;
    }
    else
    {
      two->next = temp;
      two = temp;
    }
    temp = temp->next;
  }

  // Connect the three sublists
  zero->next = oneHead->next ? oneHead->next : twoHead->next;
  one->next = twoHead->next;
  two->next = nullptr;

  Node *sortedHead = zeroHead->next;

  // Free dummy nodes
  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return sortedHead;
}

// Helper function to build list from array
Node *buildList(int arr[], int n)
{
  Node *head = NULL;
  Node *tail = NULL;

  for (int i = 0; i < n; i++)
  {
    Node *newNode = new Node(arr[i]);
    if (!head)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  return head;
}

// Helper function to print list
void printList(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Main function
int main()
{
  int arr[] = {1, 2, 0, 1, 2, 0, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  Node *head = buildList(arr, n);

  cout << "Original List: ";
  printList(head);

  Node *sortedHead = sortList(head);

  cout << "Sorted List:   ";
  printList(sortedHead);

  return 0;
}