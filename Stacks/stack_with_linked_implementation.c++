// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
using namespace std;

class ListNode {
public: 
    ListNode* Next ; 
    int val ;
    ListNode () { 
        Next = NULL ;
        val = 0 ;  
    }
    ListNode(int x) { 
        Next = NULL ;
        val = x ; 
    }
} ; 

class LinkedStack{ 
    ListNode* TOP ;
    int SIZE;
public:
    LinkedStack() { 
        TOP = NULL ; 
        SIZE = 0 ; 
    }
    void push (int v) { 
        ListNode* newNode = new ListNode(v); 
        newNode->Next = TOP ; 
        TOP = newNode ; 
        ++SIZE ; 
    } 
    bool empty () { 
        bool empty_list = (TOP == NULL) ; 
        return empty_list ; 
    }
    int peek () { 
        if (empty() != true) { 
            return TOP->val ; 
        } 
        else {
            return -1 ; 
        }
    }
    void pop () { 
        if (empty() == 0) { 
            ListNode* delNode = TOP ; 
            TOP = TOP->Next ; 
            delete delNode ; 
        }
    }
    int size () { 
        return SIZE ; 
    }

} ; 
int main() {
    
    // ========== Linked list teasting  
    LinkedStack l; 
    l.push(5) ; 
    l.push(6) ; 
    l.push(7) ; 
    l.push(8) ; 
    l.push(9) ;

    
    while (l.empty() == 0 ) { 
        cout << l.peek() << ' ' ; 
        l.pop() ; 
    }    


}