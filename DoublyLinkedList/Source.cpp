#include <iostream>

using namespace std;

template <class dataType>
struct Node {
private:
	Node* previous;
	Node* next;
	dataType key;
public:
	Node() {
		previous = next = NULL;
	}

	void setKey(dataType newKey) {
		key = newKey;
	}

	dataType getKey() {
		return key;
	}

	void setPrevious(Node<dataType>* previousNode) {
		previous = previousNode;
	}

	Node<dataType>* getPrevious() {
		return previous;
	}

	void setNext(Node<dataType>* nextNode) {
		next = nextNode;
	}

	Node<dataType>* getNext() {
		return next;
	}
};

template <class dataType>
class DoubleLinkedList {
private:
	Node<dataType>* sentinel;
public:
	DoubleLinkedList() {
		sentinel = new Node<dataType>;
		sentinel->setNext(sentinel);
		sentinel->setPrevious(sentinel);
	}

	void addNode(Node<dataType>* toAdd) {
		toAdd->setNext(sentinel->getNext());
		sentinel->getNext()->setPrevious(toAdd);
		sentinel->setNext(toAdd);
		toAdd->setPrevious(sentinel);
	}

	Node<dataType>* getSentinel() {
		return sentinel;
	}

	void printList() {
		int i = 0;
		Node<dataType>* currentNode = sentinel->getNext();
		while (currentNode != sentinel) {
			cout << "N" << ++i << " = " << currentNode->getKey() << endl;
			currentNode = currentNode->getNext();
		}

	}

	void printListOrdered() {
		int i = 0;
		Node<dataType>* currentNode = sentinel->getPrevious();
		while (currentNode != sentinel) {
			cout << "N" << ++i << " = " << currentNode->getKey() << endl;
			currentNode = currentNode->getPrevious();
		}

	}

	void printListOrderedInline() {
		int i = 0;
		Node<dataType>* currentNode = sentinel->getPrevious();
		while (currentNode != sentinel) {
			cout << currentNode->getKey();
			currentNode = currentNode->getPrevious();
		}
		cout << endl;
	}

	void agregarNodo(int i) {
		struct Node<int>* p;
		p = (Node<int>*) malloc(sizeof(struct Node<int>));
		p->setKey(i);
		p->setNext(sentinel);
		p->setPrevious(sentinel->getPrevious());
		sentinel->getPrevious()->setNext(p);
		sentinel->setPrevious(p);
	}

	void transformStrToList() {
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			int key = (str[i] - '0');
			agregarNodo(key);
		}
	}

	int contarDigitos() {
		int i = 0;
		Node<dataType>* currentNode = sentinel->getPrevious();
		while (currentNode != sentinel) {
			++i;
			currentNode = currentNode->getPrevious();
		}
		return i;
	}

};

int main(int args, char* argsv[]) {

	return 0;
}