#include <iostream>
#include <vector>
using namespace std;

// Definition of a node in the doubly linked list
struct Node
{
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

// Function to insert node at the end of DLL
void insertAtEnd(Node *&head, int data)
{
  Node *newNode = new Node(data);
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

// Function to find tail of the list
Node *findTail(Node *head)
{
  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  return temp;
}

// Function to find all pairs with sum k
vector<pair<int, int>> findPairs(Node *head, int k)
{
  vector<pair<int, int>> ans;
  Node *left = head;
  Node *right = findTail(head);

  while (left && right && left->data < right->data)
  {
    int sum = left->data + right->data;
    if (sum == k)
    {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    }
    else if (sum < k)
    {
      left = left->next;
    }
    else
    {
      right = right->prev;
    }
  }

  return ans;
}

// Utility function to print pairs
void printPairs(const vector<pair<int, int>> &pairs)
{
  for (const auto &p : pairs)
  {
    cout << "(" << p.first << ", " << p.second << ")\n";
  }
}

// Main function
int main()
{
  Node *head = nullptr;

  // Example input: sorted doubly linked list
  insertAtEnd(head, 1);
  insertAtEnd(head, 2);
  insertAtEnd(head, 3);
  insertAtEnd(head, 4);
  insertAtEnd(head, 6);
  insertAtEnd(head, 8);
  insertAtEnd(head, 9);

  int k = 10;

  vector<pair<int, int>> result = findPairs(head, k);
  printPairs(result);

  return 0;
}
