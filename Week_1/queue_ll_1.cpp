#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node (int data) {
      this->data = data;
      this->next = NULL;
    }
};

class queue {
  private :
    Node* head;
    Node* tail;
    int size;
  
  public:
    queue() {
      head = nullptr,tail=nullptr,size = 0;
    }

    void enqueue(int data) {
      Node* newHead = new Node(data);
      if (tail == nullptr) {
        head = tail = newHead;
      } else {
        tail->next = head;
        tail = newHead; 
      }
      size++;
    }

    int dequeue() {
      if (tail == nullptr){
        cout<<"Queue is empty";
        return -1; 
      }
      int data = head->data;
      head = head->next;
      delete head;
      size -= 1;
      return data;
    }

    int size_queue() {
      return size;
    }
};

int main() {
  queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout << "Size of queue is " << q.size_queue();
  cout<< "Removed element"<< q.dequeue()<<endl;
  cout << "Size of queue is " << q.size_queue();
  return 0;
}