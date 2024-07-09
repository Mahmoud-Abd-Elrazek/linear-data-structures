// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>

using namespace std;
/**
 * @brief A generic stack data structure implemented using a linked list.
 *
 * This class provides a stack data structure that can store elements of any
 * type `T`. It supports the basic stack operations of pushing, popping, and
 * checking the top element. The stack is implemented using a linked list of
 * `StackNode` objects, where each node holds an element of type `T` and a
 * pointer to the next node in the list.
 */
template<class T> // T is the type of the data stored in the stack
class Stack {
    class StackNode { 
        public:
            T data ;
            StackNode *Next ;
            StackNode() : data(0), Next(nullptr) {} 
            StackNode(const T&data) : data(data), Next(nullptr) {}
    } ; 
    StackNode*TOP;
    int SIZE ;
public:
    Stack() : SIZE(0) , TOP(NULL) {} 
    void push (const T&data) { 
        StackNode* newNode = new StackNode(data) ; 
        if (empty()) TOP = newNode; 
        else newNode->Next = TOP , TOP = newNode ; 
        ++SIZE; 
    }
    void pop () { 
        if (empty() == false) { 
            StackNode* delNode = TOP ;
            TOP = TOP->Next ;
            --SIZE ;   
            delete delNode ; 
        }
    }
    bool empty () { 
        bool empty_stack = (TOP == NULL) ; 
        return  empty_stack ; 
    }
    int size () { 
        return SIZE ; 
    }
    T top () { 
        if(empty() == 0) return TOP->data ; 
    }
} ; 

template<class T>
class MyQueue {
    Stack<T> qu; 
public:
    void push(T x) {
        Stack<T> tmp; 
        while (!qu.empty()) { 
            tmp.push(qu.top()) ; 
            qu.pop() ; 
        }
        qu.push(x) ; 

        while (!tmp.empty()) { 
            qu.push(tmp.top()) ; 
            tmp.pop() ; 
        }
    }
    T pop() {
        T ret = qu.top() ; 
        qu.pop(); 
        return ret ; 
    }
    T peek() { return qu.top() ;}
    bool empty() {return qu.size() == 0 ;}
};

int main() {
    MyQueue<string> names ; 
    names.push("KOKO") ; 
    names.push("TEMON") ; 
    names.push("BOMBA") ; 
    names.push("SKAR") ; 
    names.push("HAZOKA") ; 
    names.pop() ; // now KOKO popped from queue

    // print queue
    while (!names.empty()) { 
        cout << names.peek() << " | " ; 
        names.pop() ; 
    }
    // output => TEMON | BOMBA | SKAR | HAZOKA |
}
