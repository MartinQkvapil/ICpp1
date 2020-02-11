#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>
#include <iostream>


/*SingleLinkedList<KompleniCislo>* temp = new SingleLinkedList<KompleniCislo>();
temp->insertEnd(KompleniCislo(20, 1));
temp->insertEnd(KompleniCislo(21, 1));
temp->insertEnd(KompleniCislo(22, 1));
temp->insertEnd(KompleniCislo(23, 1));
temp->printAll();*/
// delete temp;


template<typename T>
class SingleLinkedList
{
public:
	SingleLinkedList() {
		first = nullptr;
		size = 0;
	}
	~SingleLinkedList();

	
	struct SLinkNode {
		SLinkNode* _next;
		T _data;
		SLinkNode() {
			_data = nullptr;
			_next = nullptr;
		};
		SLinkNode(T data)  {
			this->_data = data;
			this->_next = nullptr;
		};
		~SLinkNode() {};

		T getData() {
			return this->_data;
		}
	};

	void insertEnd(T  data) {
		if (size == 0) {
			first = new SLinkNode(data);
			size++;
		}
		else {
			SLinkNode* temp = first;
			while (temp->_next != nullptr) {
				temp = temp->_next;
			}
			temp->_next = new SLinkNode(data);
			size++;
		}
	}

	void printAll() {
		SLinkNode* temp = first;
		while (temp != nullptr) {
			std::cout << "Node " << temp->_data << std::endl;
			temp = temp->_next;
		}
	
	}
private:
	SLinkNode* first;
	int size;

};

#endif

template<typename T>
inline SingleLinkedList<T>::~SingleLinkedList()
{
	SLinkNode* temp = first;
	SLinkNode* tempx;
		while (temp->_next != nullptr) {
			tempx = temp;
			temp = temp->_next;
			delete tempx;
		}
	delete first;
}
