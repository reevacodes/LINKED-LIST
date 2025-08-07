#include <iostream>
using namespace std;

/*
 * Definition for linked list.
 */
struct Node
{
  int data;
  Node *next;
  Node *child;

  Node() : data(0), next(nullptr), child(nullptr) {}
  Node(int x) : data(x), next(nullptr), child(nullptr) {}
  Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Merges two sorted child-linked lists
Node *merge(Node *list1, Node *list2)
{
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;

  while (list1 && list2)
  {
    if (list1->data < list2->data)
    {
      res->child = list1;
      res = list1;
      list1 = list1->child;
    }
    else
    {
      res->child = list2;
      res = list2;
      list2 = list2->child;
    }
    res->next = nullptr; // ensure 'next' is cleaned
  }

  if (list1)
    res->child = list1;
  else
    res->child = list2;

  return dummyNode->child;
}

// Flattens the multilevel linked list
Node *flattenLinkedList(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *flattenedRest = flattenLinkedList(head->next);
  head = merge(head, flattenedRest);
  return head;
}

// Helper to print flattened list (via child pointers)
void printFlattened(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->child;
  }
  cout << endl;
}

// Test driver
int main()
{
  // Creating sample list manually:
  // 5 -> 10 -> 19 -> 28
  // |     |     |     |
  // V     V     V     V
  // 7     20    22    35
  // |           |     |
  // V           V     V
  // 8           50    40
  // |                 |
  // V                 V
  // 30                45

  Node *head = new Node(5);
  head->child = new Node(7);
  head->child->child = new Node(8);
  head->child->child->child = new Node(30);

  head->next = new Node(10);
  head->next->child = new Node(20);

  head->next->next = new Node(19);
  head->next->next->child = new Node(22);
  head->next->next->child->child = new Node(50);

  head->next->next->next = new Node(28);
  head->next->next->next->child = new Node(35);
  head->next->next->next->child->child = new Node(40);
  head->next->next->next->child->child->child = new Node(45);

  // Flatten and print
  Node *flatHead = flattenLinkedList(head);
  cout << "Flattened Linked List (sorted by child pointers):\n";
  printFlattened(flatHead);

  return 0;
}
