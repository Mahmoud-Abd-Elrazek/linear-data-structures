

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>
using namespace std;

template<class T>
class _stack {
   T *entry ; 
   int maxSize , go ; 
   
private:
   void initialize(const int&sz = 1){
      go = -1 ; 
      maxSize = sz ;  
      entry = new T[maxSize]; 
   }
   void X2(){
      T *tmpEntry = new T[maxSize] ;
      for(int i = 0 ; i < maxSize ; i++)
         tmpEntry[i] = entry[i] ;
      
       
      entry = new T[maxSize*2] ;

      for(int i = 0 ; i < maxSize ; i++)
         entry[i] = tmpEntry[i] ;
      
      delete [] tmpEntry ;

      maxSize*=2 ; 
   }
public: 
   _stack(){ initialize() ; }
   _stack(const int&sz){
      initialize(sz) ; 
      entry = new T[sz] ; // allocate sz entries 
   }
   int retMaxSize(){ return maxSize ; } 
   void push(const T& val) {
      if(go+1 == maxSize) X2() ; // resize 
      entry[++go] = val ; 
   }
   int size()const {return go+1 ; }
   bool empty()const{return go == -1 ;}
   void pop(){--go;}
   T top(){return entry[go] ; } 
};
template<class T>
ostream&operator<<(ostream&out,_stack<T>st){
   while(st.size()) { 
      out << st.top() << ' ' ; 
      st.pop(); 
   }
   return out ; 
} 
#endif // STACK_H_INCLUDED



