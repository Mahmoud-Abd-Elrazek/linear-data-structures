#include <iostream>
using namespace std ; 

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    // Constructor to initialize a node
    Node(int val = 0) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up all nodes in the list
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert a node at the front of the list
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert a node at the end of the list
    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a node from the front of the list
    void deleteFront() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Delete a node from the end of the list
    void deleteRear() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Display the list from the front to the rear
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // Display the list from the rear to the front
    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << "\n";
    }
};
int main() {
    DoublyLinkedList list;
    
    list.insertFront(10);
    list.insertRear(20);
    list.insertFront(5);
    list.insertRear(25);
    
    cout << "List (forward): ";
    list.displayForward();
    
    cout << "List (backward): ";
    list.displayBackward();
    
    list.deleteFront();
    cout << "After deleting front element, list (forward): ";
    list.displayForward();
    
    list.deleteRear();
    cout << "After deleting rear element, list (forward): ";
    list.displayForward();

    return 0;
}
