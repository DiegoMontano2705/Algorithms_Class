#include<iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList{
	public:
		LinkedList();
		LinkedList(const LinkedList<T> &nextList);
		//destructor necesario para liberar datos dinamicos aka head
		~LinkedList();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int pos);
		void deleteFirst();
		bool isEmpty();
		void del(int pos);
		void deleteLast();
		int getSize();
		int deleteAll();
		T get(int position);
		T set(int position, T val);
		bool change(int p1, int p2);
		void print();
		void reverse();
		void operator+=(T dato);
		void operator+=(const LinkedList<T> &nextList);
		void operator=(const LinkedList<T> &nextList);
		bool operator==(const LinkedList<T> &nextList);

	private:
		Node<T> *head;
		int size;
		void deleteHelper();
};

template <class T>
LinkedList<T>::LinkedList(){
	this->head = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &nextList){
	Node<T> *currentNextList = nextList.head;
	if(currentNextList != NULL){
		head = new Node<T>(currentNextList->getData());
		Node<T> *current = head;
		currentNextList = currentNextList->getNext();
		while(currentNextList != NULL){
			current->setNext(new Node <T>(currentNextList->getData()));
			current = current->getNext();
			currentNextList = currentNextList->getNext();
		}
	}
}

template <class T>
LinkedList<T>::~LinkedList(){
	deleteHelper();
}

template <class T>
void LinkedList<T>::addFirst(T data){
	head = new Node<T>(data, this->head);
	size++;
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return (head == NULL);
}

template <class T>
void LinkedList<T>::addLast(T data){
	if(head == NULL)
		addFirst(data);
	else{
		Node<T> *current = head;
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		current->setNext(new Node<T>(data));
		size ++;
	}
}

template <class T>
void LinkedList<T>::deleteFirst(){
	if(head == NULL)
		return;
	else{
		Node<T> *actual = head;
		head = head->getNext();
		delete actual;
		size --;
	}
}

template <class T>
void LinkedList<T>::deleteLast(){
	if(head == NULL)
		return;
	if(size == 1){
		deleteFirst();
	}
	else{
		Node<T> *current = head;
		Node<T> *toDelete;
		while(current->getNext()->getNext() != NULL){
			current = current->getNext();
		}
		toDelete = current->getNext();
		current->setNext(NULL);
		delete toDelete;
		size --;
	}
}

template <class T>
int LinkedList<T>::getSize(){
	return size;
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
	if(pos > size)
		return false;
	if(pos == size)
		addLast(data);
	else{
		Node<T> *current = head;
		for(int i = 1; i < pos; i++){
			current = current->getNext();
		}
		current->setNext(new Node<T>(data, current->getNext()));
		size++;
	}
	return true;
}

template <class T>
void LinkedList<T>::del(int pos){
	if (pos == 0 || pos ==  size - 1)
		deleteFirst();
	else{
		Node<T> *current = head;
		Node<T> *toDelete;
		for(int i = 0; i < pos -1; i++){
			current = current->getNext();
		}
		toDelete = current->getNext();
		current->setNext(current->getNext()->getNext());
		delete toDelete;
		size --;
	}
}


template <class T>
int LinkedList<T>::deleteAll(){
	int beforeSize = size;
	size = 0;
	deleteHelper();
	return beforeSize;
}


template <class T>
void LinkedList<T>::deleteHelper(){
	Node<T> *current = head;
	while(current != NULL){
		Node<T> *prev = current;
		current = current->getNext();
		delete prev;
	}
	head = NULL;
}

template <class T>
T LinkedList<T>::get(int position){
	Node<T> *current = head;
	for(int i = 0; i < position ; i++){
		current = current->getNext();
	}
	return current->getData();
}

template <class T>
T LinkedList<T>::set(int position, T data){
	Node<T> *current = head;
	for(int i = 0; i < position; i++){
		current = current->getNext();
	}
	T retData = current->getData();
	current->setData(data);
	return retData;
}

template <class T>
bool LinkedList<T>::change(int p1, int p2){
	Node<T> *pointerN1 = NULL;
	Node<T> *pointerN2 = NULL;
	Node<T> *current = head;

	if(p1 == p2)
		return true;

	for(int i = 0; i < size && (pointerN1 == NULL || pointerN2 == NULL); i++){
		if(i == p1)
			pointerN1 = current;
		if(i == p2)
			pointerN2 = current;
		current = current->getNext();
	}
	T auxData = pointerN1->getData();
	pointerN1->setData(pointerN2->getData());
	pointerN2->setData(auxData);
	return true;
}
template <class T>
void LinkedList<T>::print(){
	Node<T> *current = head;
	while(current != NULL){
		cout << current->getData() << " ";
		current = current->getNext();
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::operator+=(T dato){
	addLast(dato);
}

template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &nextList){
	size += nextList.size;
	if(head != NULL){
		//avanzamos la linked list hasta el utlimo elemento
		Node<T> *current = head;
		while(current->getNext() != NULL){
			current = current->getNext();
		}
		//ya que llegamos al ultimo elemento
		Node<T> *currentNextList = nextList.head;
		while(currentNextList != NULL){
			//actualizamos el siguiente del current
			current->setNext(new Node<T>(currentNextList->getData()));
			//actualizamos apuntadores
			currentNextList = currentNextList->getNext();
			current = current->getNext();
		}
	}
	else{
		Node<T> *currentNextList = nextList.head;
		//si existe al menos un elemento en la siguiente lista
		if(currentNextList != NULL){
			//actualizamos el valor de nuestro head
			head = new Node<T>(currentNextList->getData());
			//apuntamos current a head
			Node<T> *current = head;
			//actualizamos nuestro currentNextList
			currentNextList = currentNextList->getNext();
			while(currentNextList != NULL){
				//actualizamos el siguiente del current
				current->setNext(new Node<T>(currentNextList->getData()));
				//actualizamos apuntadores
				currentNextList = currentNextList->getNext();
				current = current->getNext();
			}
		}
	}
}


template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &nextList){
	if(size == nextList.size){
		Node<T> *current = head;
		Node<T> *currentNextList = nextList.head;
		while(current != NULL){
			if(current->getData() != currentNextList->getData())
				return false;
			current = current->getNext();
			currentNextList = currentNextList->getNext();
		}
		return true;
	}
	return false;
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &nextList){
	//asignamos el size
	size = nextList.size;
	Node<T> *currentNextList = nextList.head;

	//si el nodo de currenNextList es nulo borramos todo
	if(currentNextList == NULL)
		deleteAll();
	//debemos copiar
	else{
		//si nuestra lista original esta vacia debemos inicializar el head
		if(head == NULL)
			head = new Node<T>(currentNextList->getData());
		//de lo contrario ponemos el dato del primer elemento.
		else
			head->setData(currentNextList->getData());
		//de cualquier manera actualizamos al siguiente nodo del nextList
		currentNextList = currentNextList->getNext();
		Node<T> *current = head;

		//comenzamos a copiar sobre los ya creados dejando al final un pointer al ultimo elemento en la variable "current"
		while(current->getNext() != NULL && currentNextList != NULL){
			current->getNext()->setData(currentNextList->getData());
			current = current->getNext();
			currentNextList = currentNextList->getNext();
		}

		//en el caso de que nos acabemos los nodos de nuestra next list primero hay que borrar los restantes
		if(current->getNext() != NULL){
			//apuntamos el ultimo a null para que no apunte a basura
			Node<T> *last = current;
			last->setNext(NULL);
			current = current->getNext();
			while(current != NULL){
				Node<T> *prev = current;
				current = current->getNext();
				delete prev;
			}
		}

		//en el caso de que nos acabemos los nodos de nuestra lista comenzamos a crear nuevos
		if(currentNextList != NULL){
			while(currentNextList != NULL){
				current->setNext(new Node<T>(currentNextList->getData()));
				current = current->getNext();
				currentNextList = currentNextList-> getNext();
			}
		}
	}
}


template <class T>
void LinkedList<T>::reverse(){
	// retornamos si no se puede reversear
	if(head == NULL || head->getNext() == NULL)
		return;
	//de lo contrario actuamos
	Node<T> *prev = NULL, *next = head;
	head = NULL;

	while(next != NULL){
		head = next;
		next = next->getNext();
		head->setNext(prev);
		prev = head;
	}

}











/*
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}
*/
ListNode* deleteUnique(ListNode* head) {
  ListNode *aux = head;
  ListNode *auxJump; //Para guardar el nodo que sigue al que se borrara
  ListNode *res; //Nodo que tendra la lista final
  if(aux == NULL){
  return;
  }
  while(aux->next != NULL){
    //Checa si el nodo siguiente tiene el mismo valor
   	if(aux->val != aux->next->val){
    	auxJump = aux->next->next;
      	free(aux->next);
      	aux->next = auxJump;
    } else {
    	if(res == NULL){
    		res = aux;
    		res = res->next;
  		} else {
          res->next = aux;
          res = res->next;
        }
	   aux = aux->next;
  	}

  }
return res;


}





