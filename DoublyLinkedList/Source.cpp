#include <iostream>
#include <fstream>

int const posiciones_maximas = 50;

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
	int nElements;
	Node<dataType>* sentinel;
public:
	DoubleLinkedList() {
		sentinel = new Node<dataType>;
		sentinel->setNext(sentinel);
		sentinel->setPrevious(sentinel);
		nElements = 0;
	}

	int getNElements() { return nElements; }

	void addNode(Node<dataType>* toAdd) {
		toAdd->setNext(sentinel->getNext());
		sentinel->getNext()->setPrevious(toAdd);
		sentinel->setNext(toAdd);
		toAdd->setPrevious(sentinel);
		nElements++;
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

struct Curso {
	public:
	//private:
		int codigoCurso;
		char nombre[posiciones_maximas];
		char instructor[posiciones_maximas];
	
	//public:
		//
};

struct Estudiante {
	public:
		int id;
		char nombre[posiciones_maximas];
		char apellido[posiciones_maximas];
		DoubleLinkedList<Curso> listaCursos;
	//public:
		//
};

int main(int args, char* argsv[]) {
	
	/*Curso c1, c2, c3, c4, c5;
	string str;

	c1.codigoCurso = 1;
	str = "Estructuras de Datos";
	strcpy_s(c1.nombre, str.c_str());
	str = "Gabriela Veracierta";
	strcpy_s(c1.instructor, str.c_str());

	c2.codigoCurso = 2;
	str = "Taller de Estructuras de Datos";
	strcpy_s(c2.nombre, str.c_str());
	str = "Pedro Dorta";
	strcpy_s(c2.instructor, str.c_str());

	c3.codigoCurso = 3;
	str = "Sistemas de Microprocesamiento";
	strcpy_s(c3.nombre, str.c_str());
	str = "Julima Anato";
	strcpy_s(c3.instructor, str.c_str());

	c4.codigoCurso = 4;
	str = "Laboratorio de Disenio Logico";
	strcpy_s(c4.nombre, str.c_str());
	str = "Julima Anato";
	strcpy_s(c4.instructor, str.c_str());

	c5.codigoCurso = 5;
	str = "Seguridad en Sistemas Computacionales";
	strcpy_s(c5.nombre, str.c_str());
	str = "Pedro Dorta";
	strcpy_s(c5.instructor, str.c_str());
	
	Curso arrayCursos[] = { c1, c2, c3, c4, c5 };

	Node<Curso>* auxCurso = nullptr;
	Estudiante luisito;
	int cont = 0;

	while (cont < 5) {

		auxCurso = new Node<Curso>;
		auxCurso->setKey(arrayCursos[cont]);

		luisito.listaCursos.addNode(auxCurso);

		cont++;
	}

	luisito.id = 25687494;
	str = "Luis Marquez";
	strcpy_s(luisito.nombre, str.c_str());
	str = "Marquez Castro";
	strcpy_s(luisito.apellido, str.c_str());

	fstream archivo("try.bin", ios::binary | ios::out);

	archivo.write(reinterpret_cast<char*> (&luisito), sizeof(Estudiante));
	
	int n = luisito.listaCursos.getNElements();
	
	archivo.write(reinterpret_cast<char*> (&n), sizeof(int));

	Node<Curso>* sentinela = luisito.listaCursos.getSentinel();
	Node<Curso>* storeCurse = luisito.listaCursos.getSentinel()->getPrevious();

	while (storeCurse != sentinela) {
		Curso store = storeCurse->getKey();
		archivo.write(reinterpret_cast<char*> (&store), sizeof(Curso));
		
		storeCurse = storeCurse->getPrevious();
	}

	archivo.close();*/
	
	Node<Curso>* storeCurse;
	Estudiante estudianteLeido;
	storeCurse = NULL;

	
	fstream archivo("try.bin", ios::binary | ios::in);
	//archivo.open("try.bin", ios::binary | ios::in);
	archivo.read(reinterpret_cast<char*> (&estudianteLeido), sizeof(Estudiante));
	int cantReg;
	archivo.read(reinterpret_cast<char*> (&cantReg), sizeof(int));
	
	Curso cursoleido;

	DoubleLinkedList<Curso> listaauxiliar;

	while (cantReg > 0) {
		archivo.read(reinterpret_cast<char*> (&cursoleido), sizeof(Curso));
		storeCurse = new Node<Curso>;
		storeCurse->setKey(cursoleido);
		listaauxiliar.addNode(storeCurse);
		cantReg--;
	}

	estudianteLeido.listaCursos = listaauxiliar;

	estudianteLeido;
	//delete auxCurso;
	delete storeCurse;

	archivo.close();

	return 0;
}