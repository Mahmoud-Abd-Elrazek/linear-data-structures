

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include<iostream>
using namespace std;

template<class T> 
class queue{
   int size , mxSize; 
   T *entry ; 
   int front , back ; 
   void reset(){
      front = 0 ; 
      back = -1 ;
      size = 0 ;  
   }
   bool isFull(){ return size+1 == mxSize ; }
public:
   queue () { reset() ; }
   queue (const int&size) {
      reset() ; 
      mxSize = size ;
      entry = new T[size];
   } 
   void push(const T&val){
      if(!isFull()) 
         entry[(++back)%this->mxSize] = val ;
      this->size++;  
   }
   void pop() { 
      if(!empty()) 
         this->front++;
      this->size--;
   } 
   bool empty() const{ return back == -1 || !size; }
   T Front() const { return this->entry[this->front] ; }
   int Size() { return this->size ; }
};

#endif // QUEUE_H_INCLUDED



