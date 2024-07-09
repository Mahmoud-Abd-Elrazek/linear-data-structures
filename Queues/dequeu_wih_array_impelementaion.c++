// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
template <class T> 
class deque { 
   // private data attributes
   T items[MAX_SIZE] ;
   int size , front , back ;
   // private methods
   void reset_deque() {
      size = 0 ;
      front = back = -1 ;
   }
public:
   deque() { reset_deque() ;}
   void push_front(T data) {
      if (isFull()) 
         return ;
      else if (isEmpty()) 
         front = back = 0 ; 
      else 
         front = front ? front - 1 : MAX_SIZE - 1 ;
      items[front] = data ;
      ++size;
   }
   void push_back(T data) {
      if (isFull()) return ;
      else if(isEmpty())
         front = back = 0 ;
      else 
         back = (back+1)%MAX_SIZE;
      items[back] = data ;
      ++size ;
   }
   T pop_front() { 
      bool deque_has_one_item = (front == back) ;
      if (deque_has_one_item) { 
         reset_deque() ; 
      }
      else if (!isEmpty()) { 
         T retVal = items[back] ;
         front = (front+1)%MAX_SIZE ;
         --size ;
         return retVal ; 
      }
   }
   T pop_back() {
      bool deque_has_one_item = (front == back) ;
      if (deque_has_one_item) { 
         reset_deque() ; 
      }
      else if (!isEmpty()) {
         T retVal = items[back] ;
         back = back ? back-1 :  MAX_SIZE-1 ;
         --size ;
         return retVal ;
      }
   }
   bool isEmpty () { 
      bool is_empty_condtion = (front == -1 and back == -1) ;
      return is_empty_condtion ;
   }
   bool isFull() {
      bool full_condition_1 = (front == back + 1 ) ;
      bool full_condition_2 = (front == 0 && back == MAX_SIZE-1) ;
      return full_condition_1 or full_condition_2 ;
   }
   int getSize () { 
      return size ;
   }
   void display() { 
      int tmp = front ;
      while (tmp != back) {
         cout << items[tmp] << " " ;
         tmp = (tmp+1) % MAX_SIZE ;
      }
      cout << items[back] << "\n" ;
   }
} ; 

int main() {
   // io() ;

}