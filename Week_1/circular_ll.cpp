#include<iostream>
using namespace std;


class Node {
  public:
    int data;
    Node* next;

    Node (int data) {
      this->data = data;
      this->next = nullptr;
    }

    // insert at beginning
    Node* insertAtBeginning(Node* &head, int data) {
      if (head == NULL) {
        return;
      }

      Node* newHead = new Node(data);
      newHead->next = head;
      head->next = newHead;
      head = newHead;
    }

};

int main () {
  // Initialization of circular linked list.
  Node* head = new Node(10);
  head->next = head;

  
  return 0;
}