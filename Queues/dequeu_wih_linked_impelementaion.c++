// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
using namespace std ; 
/**
 * @brief 
 * @param
*/
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    ~Deque() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (isEmpty())  return;
        Node* temp = front;
        front = front->next;
        if (front != nullptr)     
            front->prev = nullptr;
        else 
            rear = nullptr;
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) { return;}
        Node* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) rear->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }
    int getRear() {
        if (isEmpty()) return -1;
        return rear->data;
    }
};

int main() {
    Deque dq;
    
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(25);
    
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;
    
    dq.deleteFront();
    cout << "After deleting front element, front: " << dq.getFront() << endl;
    
    dq.deleteRear();
    cout << "After deleting rear element, rear: " << dq.getRear() << endl;

    return 0;
}
