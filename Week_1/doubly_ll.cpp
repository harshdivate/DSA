#include<iostream>
using namespace std;


class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
      this->data = data;
      this->prev = NULL;
      this->next = NULL;
    }

    void traverseDoublyLLHead(Node* head) {
      Node* currHead = head;

      while (currHead != NULL) {
        cout<<currHead->data<<" ";
        currHead = currHead->next;
      }
    }

    void traverseDoublyLLTail(Node* tail) {
      Node* currTail = tail;

      while (currTail != NULL) {
        cout<<currTail->data<<" ";
        currTail = currTail->prev;
      }
    }

    // search in dll
    bool seachElementInDLL(Node* head, int target) {
      Node* currHead = head;

      while (currHead != NULL) {
        int data = currHead->data;
        currHead = currHead->next;
        if (data == target) {
          return true;
        }
      }
      return false;
    }

    // length of dll
    
    // insert at start
    Node* insertAtStart(Node* head, int data) {
      Node* newHead = new Node(data);

      if (head == NULL) {
        return newHead;
      }
      
      newHead->next = head;
      head->prev = newHead;
      head = newHead;
      return newHead;
    }

    // insert at end
    Node* insertAtEnd(Node* &head, int data) {
      Node* newHead = new Node(data);
      Node* currHead = head;

      while(currHead->next != NULL) {
        currHead = currHead->next;
      }
      // now we are last position
      currHead->next = newHead;
      newHead->prev = currHead;
      head = newHead;
      return head;
    }

    // insert at specific position
    void insertAtSpecificPosition(Node* head, int data, int pos) {
      int size = lengthOfDLL(head);

      if (size < 0 || size >= pos) {
        return;
      }
      if (pos == 0) {
        head = insertAtStart(head,data);
        return;
      }
      if (pos == size -1) {
        head = insertAtEnd(head, data);
      }
      Node* currHead = head;
      while(pos-1 > 0) {
        currHead = currHead->next;
        pos -= 1;
      }
      // now we are at pos - 1 position and need to enter element at pos
      Node* newInsert = new Node(data);
      Node* currentHeadNextNode = currHead->next;
      currentHeadNextNode->prev = newInsert;
      newInsert->next = currentHeadNextNode;
      currHead->next = newInsert;
      newInsert->prev = currHead; 
    }

    int lengthOfDLL(Node* head) {
    int length = 0;
    if (head == NULL) {
      return length;
    }

    Node* currHead = head;
    while (currHead != NULL) {
      length++;
      currHead = currHead->next;
    }
    return length;
  }

  // delete at beginning
  void deleteAtBeginning(Node* &head) {
    if (head == NULL) {
      return;
    }

    Node* nextHead = head->next;
    nextHead->prev = NULL;
    head->next = NULL;
    delete head;
    head = nextHead;
  }

  // delete at end
  void deleteAtEnd(Node* &head) {
    if (head == NULL) {
      return;
    }
    Node* currHead = head;
    while(currHead->next->next !=  NULL) {
      currHead = currHead->next;
    }

    // now we are at second last position
    Node* lastHead = currHead->next;
    lastHead->prev = NULL;
    currHead->next = NULL;
    delete lastHead;
  }

  // delete at specific position
  void deleteAtSpecificPosition(Node* &head, int position) {
    if (head == NULL) {
      return;
    }
    int size = lengthOfDLL(head);

    if (position == 0) {
      deleteAtBeginning(head);
      return;
    }
    if (position == size -1 ) {
      deleteAtEnd(head);
      return;
    }

    // else it is at a middle function
    Node* currHead = head;
    while(position-1 > 1) { 
      currHead = currHead->next;
      position -= 1;
    }

    // now we are at pos -1 position
    Node* deleteNode = currHead->next;
    currHead->next = deleteNode->next;
    deleteNode->next->prev = currHead;
    deleteNode->next = NULL;
    deleteNode->prev = NULL;
    delete deleteNode;
  }

};




int main() {

  Node* head = new Node(5);
  // head = head->insertAtEnd(head, 20);
  // head = head->insertAtEnd(head, 30);
  // cout<<head->lengthOfDLL(head)<<endl;
  Node listManager(0);
  head = listManager.insertAtStart(head,10);
  head = listManager.insertAtStart(head,20);
  head = listManager.insertAtStart(head,30);

  int length = listManager.lengthOfDLL(head);
  cout<< "Length of dll is " << length << " "<<endl;
  listManager.traverseDoublyLLHead(head);
  listManager.deleteAtSpecificPosition(head, 2);
  cout<<endl;
  listManager.traverseDoublyLLHead(head);
  // head->insertAtSpecificPosition(head, 25, 2);

  // head->traverseDoublyLLHead(head);


  return 0;
}