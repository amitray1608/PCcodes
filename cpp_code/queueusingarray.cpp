#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100;
int queuee[MAXN], rear = -1, front = -1;

void dequeue() {
  if(rear == -1 or rear <= front) {
    front = rear = -1;
    cout << "Queue is empty." << endl;
  } else {
    cout << "Element poped from the queue: ";
    cout << queuee[++front] << endl; 
  }
}

void enqueue(int v) {
  if(rear == MAXN - 1) {
    cout << "Queue is full." << endl;
  } else {
    cout << "Element pushed in the queue." << endl; 
    queuee[++rear] = v;
  }
}

void display() {
  if(rear == -1 or rear <= front) {
    cout << "Queue is empty." << endl; 
  } else {
    int r = rear, f = front;
    cout << "Elements in the queue are : " << endl;
    while(f < r) {
      cout << queuee[++f] << ' ';
    }
    cout << endl;
  }
}

int main(){
    cout << "Enter 1 for inserting into the queue." << endl;
    cout << "Enter 2 for  pop from the queue." << endl;
    cout << "Enter 3 for displaying the queue." << endl;
    cout << "Enter 4 to exit." << endl;
  while(true) {
    cout << "Enter Choice : ";
    int tp;
    cin >> tp;
    switch(tp) {
      case 1:
        int x;
        cout << "Enter value: ";
        cin >> x;
        enqueue(x);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        cout << "Program exited." << endl;
        exit(0);
        break;
      default:
        cout << "Wrong Choice." << endl;
    }
  }
  return 0;
}

