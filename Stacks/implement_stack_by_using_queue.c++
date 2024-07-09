// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
queue<int> sk;
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> tem;
        tem.push(x);
        while(!sk.empty()) {
            tem.push(sk.front());
            sk.pop();
        }
        sk = tem;
    }
    int pop() {
        int ret = sk.front() ; 
        sk.pop(); 
        return ret ; 
    }
    int top() {
        return sk.front() ;    
    }
    
    bool empty() {
        return sk.empty() ; 
    }
};

int main () { 
    MyStack st ; 
    st.push(5) ; 
    st.push(6) ; 
    st.push(7) ; 
    st.push(8) ; 
    st.push(9) ;
    while (st.empty() == false) { 
        cout << st.pop() << '\n' ; 
    } 

}