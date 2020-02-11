#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Podminka.h"

//try {
//	DoublyLindedList<std::string>* temp = new DoublyLindedList<std::string>();
//	temp->insertEnd("Ahoj");
//	temp->insertEnd("Hero1");
//	temp->insertEnd("Hero2");
//	temp->insertEnd("Hero3");
//	temp->insertEnd("Adolf");
//	temp->printAll();
//
//	temp->findNode("Herffo3");
//
//	delete temp;
//}
//catch (Podminka podminka) {
//	std::cout << podminka.GetMsg() << std::endl;
//}


template <typename T> struct DLNode {
	DLNode* _next;
	DLNode* _prev;
	T _data;
	DLNode() : _next(nullptr), _prev(nullptr) {};
	~DLNode() {};
};

template <typename T>
class DoublyLindedList
{
public:
	DoublyLindedList() {
		_first = nullptr;
		_last = nullptr;
		_size = 0;

	};

	void findNode(T data) {
		DLNode<T>* temp = _first;
		for (int i = 0; i < _size; i++)
		{
			if (temp->_data == data) {
				std::cout << "Nalezl jsem" << std::endl;
				return;
			}
			temp = temp->_next;
		}
		throw Podminka("Prvek nenalezen!!!");
	}

	void insertEnd(T data) {
		if (_first == nullptr)
		{
			DLNode<T>* new_node = new DLNode<T>();
			new_node->_data = data;
			new_node->_next = new_node->_prev = new_node;
			_first = new_node;
			_size++;
			return;
		}

		// If list is not empty 

		/* Find last node */
		DLNode<T>* _last = _first->_prev;

		// Create Node dynamically 
		DLNode<T>* new_node = new DLNode<T>();
		new_node->_data = data;

		// Start is going to be next of new_node 
		new_node->_next = _first;

		// Make new node previous of start 
		_first->_prev = new_node;

		// Make last preivous of new node 
		new_node->_prev = _last;

		// Make new node next of old last 
		_last->_next = new_node;
		_size++;
	}


	void printAll() {
		DLNode<T>* temp = _first;
		for (int i = 0; i < _size; i++)
		{
			std::cout << temp->_data << std::endl;
			temp = temp->_next;
		}
	}

	void printAllEndToStart() {
		DLNode<T>* temp = _last;
		for (int i = 0; i < _size; i++)
		{
			std::cout << temp->_data << std::endl;
			temp = temp->_prev;
		}
	}
private:
	DLNode<T>* _first;
	DLNode<T>* _last;
	int _size;
};



#endif // !DOUBLYLINKEDLIST_H

