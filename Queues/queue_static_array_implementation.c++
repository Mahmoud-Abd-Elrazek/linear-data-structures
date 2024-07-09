#include <iostream>
using namespace std;

const int MAX_QUEUE_SIZE = 100; 
class queue {
	int items[MAX_QUEUE_SIZE]; 
	int front, rear , size;
	void reset_queue() {
		front = rear = -1;
		size = 0; 
	}
public :
	queue() { reset_queue(); }
	void push(int data) {
		if (isFull()) return;
		if (isEmpty()) front = rear = 0; 
		else rear += 1;

		items[rear] = data; 
		++size; 
	}
	void pop() {
		if (isEmpty())
			return; 
		else {
			bool queue_has_one_item = (front == rear); 
			if (queue_has_one_item) reset_queue(); 
			else if(front == MAX_QUEUE_SIZE - 1) front = 0; 
			else ++front;
			--size; 
		}
	}
	
	bool isFull() {
		bool full_queue_case_one = (front == 0 && rear == MAX_QUEUE_SIZE - 1); 
		bool full_queue_case_two = (front == rear + 1 ); 
		return full_queue_case_two || full_queue_case_one; 
	}
	bool isEmpty() {
		bool isEmpty = (front == -1 && rear == -1); 
		return isEmpty; 
	}
	int peek() {
		if (!isEmpty()) { return items[front];}
		return -1 ; 
	}
	
};

int main() {

	queue qu;
	qu.push(5);
	qu.push(6);
	qu.push(7);
	qu.push(8);
	qu.push(9);
	
	//cout << qu.peek() << '\n'; 
	qu.pop(); 
	cout << qu.peek() << '\n'; 

}