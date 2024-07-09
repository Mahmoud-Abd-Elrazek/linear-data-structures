#include <iostream>
using namespace std;
/**
  @brief A stack implementation using a fixed-size array , The stack has a maximum size of 'MAX_SIZE == 100 ' elements , It supports pushing and popping elements, as well as peeking at the top element.The stack can be checked for emptiness and fullness.

     * - push(item): Add an item to the top of the stack.
     * - pop(): Remove and return the item at the top of the stack.
     * - peek(): Return the item at the top of the stack without removing it.
     * - is_empty(): Check if the stack is empty.
     * - is_full(): Check if the stack is full.
     * - getSize(): return number of items inside the stack
 */
const int MAX_SIZE = 100; 
template<class T>
class stack {
	T items[MAX_SIZE];
	int top , size;
public:
	stack() { top = -1;size = 0; }
	void push(T data) {
		if (isFull()) return; 
		else items[++top] = data;
		size++; 
	}
	void pop() {
		if (isEmpty()) return; 
        --top;
        --size; 
	}
	T peek() {if (!isEmpty()) return items[top];}
	bool isEmpty() {
		bool isEmptySatck = (top == -1 || size == 0);
		return isEmptySatck;
	}
	bool isFull() {
		bool isFullSatck = (top == MAX_SIZE - 1);
		return isFullSatck; 
	}
	int getSize() { return size; }
};
/**
 * Overloads the << operator to print the contents of a stack to an output stream.
 *
 * @param COUT The output stream to write the stack contents to.
 * @param st The stack to print.
 * @return The output stream after writing the stack contents.
 */
template<class Type>
ostream& operator << (ostream&COUT , stack<Type> st) { 
    while (st.isEmpty() == 0) {
        COUT << st.peek() << ' ' ;
        st.pop() ; 
    }
    return COUT ; 
}
int main() {
    stack<int> st ; 
    
    int i = {} ; 
    do
    {   st.push(i) ; 
        ++i ; 
    } while (i <= 6);

    cout << st << '\n' ; 
}