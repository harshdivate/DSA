#include<iostream>
using namespace std;

class queue {
  public:
    static const int size = 1000; 
    int arr[size];
    int front = 0,rear = 0;


    void enqueue(int data) {
      // check if queue is full
      if (rear == size -1) {
        cout<<"Queue is full"<<endl;
        return;
      }

      // if queue has values then add
      arr[rear] = data;
      rear++;
    }

    void dequeue() {
      if (front == rear) {
        cout<<"Queue is empty";
        return;
      }

      arr[front] = -1;
      front++;
      if (front == rear) {
        front = 0, rear = 0;
      }
    }

    bool isEmpty() {
      if (front == rear) {
        return true;
      }
      return false;
    }

    int si_ze() {
      if (rear == 0) {
        return 0;
      }
      return rear;
    }

    void traverseQueue() {
      if (isEmpty()) return;

      for (int i = front; i < rear; i++) {
        cout<<arr[i]<< " ";
      }
    }

};


int main() {
  queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout<<q.si_ze()<<endl;
  q.traverseQueue();
  return 0;
}