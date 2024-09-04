#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  // Function traverse a linked list

  // Function Searchers for an element in sll
  bool searchLinkedList(Node *head, int target)
  {
    Node *currHead = head;

    if (head == NULL)
    {
      return false;
    }

    while (currHead != NULL)
    {
      int data = currHead->data;
      if (data == target)
      {
        return true;
      }
      currHead = currHead->next;
    }
    return false;
  }

  // Function finds the length of sll
  int findLengthofSingleLinkedList(Node *head)
  {
    int length = 0;
    if (head == NULL)
    {
      return length;
    }
    Node *currHead = head;

    while (currHead != NULL)
    {
      length += 1;
      currHead = currHead->next;
    }
    return length;
  }

  // Insertion a beginning
  Node *insertDatainBeginning(Node *head, int data)
  {
    if (head == NULL)
    {
      Node *head = new Node(data);
      return head;
    }
    Node *newHead = new Node(data);
    newHead->next = head;
    head = newHead;
    return head;
  }

  // Insert at end of sll
  Node *insertAtEnd(Node *head, int data)
  {
    if (head == NULL)
    {
      Node *head = new Node(data);
      return head;
    }

    Node *newEndNode = new Node(data);
    Node *currHead = head;

    while (currHead->next != NULL)
    {
      currHead = currHead->next;
    }

    // Here we are the end of linked list
    currHead->next = newEndNode;
    return newEndNode;
  }

  void insertAtSpecificPosition(Node *head, int data, int pos)
  {
    int size = findLengthofSingleLinkedList(head);
    if (pos < 0 || pos > size + 1)
    {
      return;
    }
    Node *currHead = head;
    // here we know that position is within our range of size
    if (pos == 0)
    {
      head = insertDatainBeginning(head, data);
    }
    else
    {
      for (int i = 0; i < pos; i++)
      {
        currHead = currHead->next;
      }
      // now we are at pos -1 position
      Node *insertingItem = new Node(data);
      insertingItem->next = currHead->next;
      currHead->next = insertingItem;
    }
  }

  Node *deleteAtBeginning(Node *&head)
  {
    if (head == NULL)
    {
      return head;
    }

    Node *nextHead = head->next;
    head->next = NULL;
    Node *returnHead = head;
    delete head;
    head = nextHead;
    return returnHead;
  }

  void deleteAtEnd(Node *&head)
  {
    if (head == NULL)
    {
      return;
    }

    Node *currHead = head;
    while (currHead->next->next != NULL)
    {
      currHead = currHead->next;
    }

    // Now i am at the last but 1 position of sll
    Node *lastNode = currHead->next;
    currHead->next = NULL;
    delete lastNode;
  }

  void deleteAtSpecificPosition(Node *&head, int pos)
  {
    int size = findLengthofSingleLinkedList(head);

    if (pos < 0 || pos >= size)
    {
      return;
    }

    if (pos == 0)
    {
      deleteAtBeginning(head);
      return;
    }

    if (pos == size - 1)
    {
      deleteAtEnd(head);
      return;
    }

    Node *currHead = head;
    while (pos - 1 > 0)
    {
      currHead = currHead->next;
      pos--;
    }

    // now i am at pos-1 position and should delete the element on pos
    Node *deleteElement = currHead->next;
    currHead->next = deleteElement->next;
    deleteElement->next = NULL;
    delete deleteElement;
  }
};

void traverseLinkedList(Node *head)
{
  Node *tempHead = head;

  while (tempHead != nullptr)
  {
    cout << tempHead->data << " ";
    tempHead = tempHead->next;
  }
}

class queue
{
public:
  Node *head = NULL;
  Node *tail = NULL;

  void enqueue(int data)
  {
    // this receives the data
    tail = head->insertAtEnd(head, data);
    if (head == NULL)
    {
      head = tail;
    }
  }

  void dequeue()
  {
    Node *deletedNode = head->deleteAtBeginning(head);
    cout << "Deleted data is " << deletedNode->data;
  }

  void traverse()
  {
    traverseLinkedList(head);
  }

  int size_queue()
  {
    return head->findLengthofSingleLinkedList(head);
  }
};

int main()
{
  queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.traverse();
  cout << "Size of queue is " << q.size_queue();
  return 0;
}