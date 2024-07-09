#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include<iostream>
#include<string.h>

using namespace std ;

// Start Node
template<class T> // Node type
struct Node {
   T info ;
   Node<T>* link ;
};
// End Node

//****** START-Linked list iterator ***************
template<class T>
class linkedListIterator { //linkedListIterator
private:
   Node<T> *current; //pointer to point to the current
public:
   linkedListIterator();
   linkedListIterator(Node<T>*);
   T operator* ();
   linkedListIterator<T> operator++(int);
   linkedListIterator<T> operator++();

   bool operator==(const linkedListIterator<T>&) const;
   bool operator!=(const linkedListIterator<T>&) const;
};

template<class T>
linkedListIterator<T>::linkedListIterator(){
   current = NULL ;
}

template<class T>
linkedListIterator<T>::linkedListIterator(Node<T>*ptrNode){
   current = ptrNode ;
}

template<class T>
T linkedListIterator<T>::operator*(){
   return current->info;
}


// post increment
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(int){
   linkedListIterator it = this->current ;
   // ++(*this) ;
   current = current->link;
   return it ;
}
// pre increment
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(){
   current = current->link;
   return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
   return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const{
return (current != right.current);
}
// ******END-linked list iterator ***************

//  * Strat Class lnked list as ADT

/*
This class specifies the members to implement the basic
properties of a linked list. This is an abstract class.
We cannot instantiate an object of this class.
*/
template< class T>
class linkedlistType {
public:
   bool isEmpty() const ; // O(1)
   linkedlistType() ; // O(1)
   void destroyList() ; // O(N)
   void initializeList() ; // O(N)
   void print() ; // O(N)
   void print(void(*pf)(T)) ; // O(N)

   int length() const ; // O(1)
   T front() const ; // O(1)
   T back() const ; // O(1)

   linkedListIterator<T> begin() const ;
   linkedListIterator<T> end() const ;

   // void copyList(const linkedlistType<T>&); // O(N)
   ~linkedlistType();
   linkedlistType(const linkedlistType<T>&);

protected: /*will derive the classes
unorderedLinkedList and orderedLinkedList from the class linkedListType.*/
   int count ;
   Node<T>* first , *last ;
private:
   void copyList(const linkedlistType<T>&);
};

template<class T>
bool linkedlistType<T>::isEmpty()const{
   return !this->first ;
}
template<class T>
linkedlistType<T>::linkedlistType(){
   this->first = nullptr ;
   this->last = nullptr ;
   count = 0 ;
}
template<class T>
void linkedlistType<T>::destroyList() {
   Node<T>* delNode = this->first ;

   while(this->first) {
      delNode = this->first ;
      this->first = this->first->link ;
      delete delNode ;
   }
   this->last = nullptr ;

   count = 0 ;
}
/*
The function initializeList uses the function destroyList, which is of O(n).
Therefore, the function initializeList is of O(n)*/

/*The function initializeList initializes the list to an empty state. Note that the default
constructor or the copy constructor has already initialized the list when the list object was
declared. This operation, in fact, reinitializes the list to an empty state, and so it must delete
the nodes (if any) from the list.
*/

template<class T>
void linkedlistType<T>::initializeList(){
   this->destroyList() ; // /if the list has any nodes, delete them
}

template<class T>
void linkedlistType<T>::print() {
   Node<T>* go = this->first ;
   while(go) {
      cout << go->info << ' ' ;
      go = go->link ;
   }
}

template<class T>
void linkedlistType<T>::print(void(*pf)(T)) {
   Node<T>* go = this->first ;
   while(go) {
      pf(go->info) ;
      go = go->link ;
   }
}

template<class T>
int linkedlistType<T>::length() const {
   return count ;
}

template<class T>
T linkedlistType<T>::front() const {
   assert(!isEmpty()); // if true go on else terminate
   return this->first->info ; //return the info of the first node
// Notice that if the list is empty, the assert statement terminates the program.
}

template<class T>
T linkedlistType<T>::back() const {
   assert(this->last != NULL);
   return this->last->info ;
}

// Begine and End
/*The function begin returns an iterator to the first node in the linked list and the function
end returns an iterator to the last node in the linked list. Their definitions are as follows:*/
template<class T>
linkedListIterator<T> linkedlistType<T>::begin() const {
   linkedListIterator<T> it(this->first);
   return it ;
}
template<class T>
linkedListIterator<T> linkedlistType<T>::end() const {
   linkedListIterator<T> it(nullptr);
   return it ;
}

template<class T>
void linkedlistType<T>::copyList(const linkedlistType<T>&otherList) {

   if(!this->isEmpty())
      destroyList() ;

   if(otherList.isEmpty()){
      this->first = nullptr ;
      this->last = nullptr ;
      this->count = 0 ;
   }
   else { // copy all nodes inot this list

      Node<T>* current = otherList.first ; // current pointer node to traversing list
      // now current points to the list to be copied

      this->first = new Node<T> ;
      this->first->info = current->info ;
      this->first->link = nullptr ;

      this->last = this->first ;

      current = current->link ; // one step forward


      // copying remaining list
      Node<T>* newNode = new Node<T> ;
      while(current) {
         newNode->info = current->info;
         newNode->link = nullptr ;

         last->link = newNode;
         last = newNode ;

         current = current->link ; // one step forward
      } // End While

   } // end eles
}

template<class T>
linkedlistType<T>::~linkedlistType() {
   this->destroyList() ;
}

template<class T>
linkedlistType<T>::linkedlistType(const linkedlistType<T>&list) {
   this->first = nullptr ;
   this->copyList(list);
}
//  * End Class lnked list as ADT

// Start unorderedLinkedList
template<class T>
class unorderedLinkedList : public linkedlistType<T> {
public:
   bool search(const T& );
   void insertFirst(const T&);
   void insertLast(const T&);
   void deleteNode(const T&);
};

template<class T>
bool unorderedLinkedList<T>::search(const T&searchItem){

   Node<T>* go = this->first ;

   while(go) {
      if(go->info == searchItem)
         return 1 ;
      go = go->link ;
   }
   return 0 ;

}

template<class T>
void unorderedLinkedList<T>::insertFirst(const T&newItem){

   Node<T>* newNode = new Node<T> ;
   newNode->info = newItem ;

   newNode->link = this->first ;
   this->first = newNode ;

   if(!this->last)
      this->last = newNode ;

   this->count++ ;
}

template<class T>
void unorderedLinkedList<T>::insertLast(const T&newItem) {

   Node<T>* newNode = new Node<T> ;
   newNode->link = nullptr ;
   newNode->info = newItem ;

   if(this->isEmpty())
      this->first = newNode ;
   else
      this->last->link = newNode ;

   this->last = newNode ;
   this->count++ ;
}

template<class T>
void unorderedLinkedList<T>::deleteNode(const T&delItem) {
   if( this->isEmpty() || !this->search(delItem) )
		return ;

	Node<T>* current; //pointer to traverse the list
	Node<T> *trailCurrent; //pointer just before current

	if(this->first->info == delItem){
		current = this->first ;
		this->first = this->first->link ;

		if(!this->first)
			this->last = nullptr ;

		delete current ;
	}
	else {
		bool found = 0 ;
		trailCurrent = this->first ;
		current = this->first->link;

		while( current && !found ) {

			if(current->info != delItem ){
				current = current->link ;
				trailCurrent = trailCurrent->link ;
			}else found = 1 ;

			if(found){
				trailCurrent->link = current->link ;

				if(this->last == current) { // node to be deleted was the last one
					this->last = trailCurrent ;
				}
				delete current ;

			}
			else return ; // item not found

		}
	}
	this->count--;
}


// ****************************************************************
template<class T >
class orderedLinkedList : public linkedlistType<T> {
public:
   bool search(const T&) ;
   void insert(const T&);
   void insertFirst(const T&);
   void insertLast(const T&);
   void deleteNode(const T&);
} ;
template<class T >
bool orderedLinkedList<T>::search(const T&searchItem) {
   Node<T>* go = this->first ;
   while(go) {
      if( go->info >= searchItem)
         break;
      go = go->link ;
   }
   if(!go)
      return 0 ;
   return (go->info == searchItem) ;
}
template<class T >
void orderedLinkedList<T>::insert(const T&val) {

   Node<T>* newNode; //pointer to create a node
   newNode = new Node<T> ;
   newNode->info = val ;
   newNode->link = nullptr ;

   if(this->isEmpty()) {
      this->first = newNode ;
      this->last = this->first ;
      this->count++;
      return ;
   }

   if (this->first->info >= newNode->info ) { // insertion in  fisrt
      newNode->link = this->first ;
      this->first = newNode ;

      this->count++;
      return ;
   }

   Node<T>* current; //pointer to traverse the list
   Node<T>* trailCurrent; //pointer just before current

   trailCurrent = this->first ;

   current = trailCurrent->link ;
   while(current) {
      if(current->info >= newNode->info)
         break ;
      current = current->link ;
      trailCurrent = trailCurrent->link ;
   }

   newNode->link = trailCurrent->link ;
   trailCurrent->link = newNode;
   this->count++;

   if(trailCurrent == this->last)
      this->last = newNode ;
}
template<class T>
void orderedLinkedList<T>::insertFirst(const T&val) {
   this->insert(val) ;
}

template<class T>
void orderedLinkedList<T>::insertLast(const T&val) {
   this->insert(val) ;
}

template<class T>
void orderedLinkedList<T>::deleteNode(const T&val) {
   if(this->isEmpty()) return ;

   Node<T> *current; //pointer to traverse the list
   Node<T> *trailCurrent; //pointer just before current
   bool found ;

   current = this->first ;
   found = 0 ;

   while(current && !found){
      if(current->info >= val) {
         found = 1 ;
      }
      else {
         trailCurrent = current ;
         current = current->link ;
      }
   }

   if(!current) // this element s not found in tour linked list
      return ;


   if(current->info == val) {
      // i found it
      if(this->first == current) { // i'll delete the first element in our linked list
         this->first = this->first->link ; // one step forward
         if(this->first == nullptr)  // our linked list has one element
            this->last = nullptr ;

         delete current ;
      }
      else {
         trailCurrent->link = current->link ;
         if(current == this->last) // this mean , this is the last node in our linked list
            this->last = trailCurrent ;

         delete current;
      }
      this->count-- ;
   }

   return ;

}
#endif // BOOK_H_INCLUDED