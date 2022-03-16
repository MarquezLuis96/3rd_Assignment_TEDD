//LIBRERIAS
#include <iostream>
#include <string>
constexpr auto StringLength = 50;
//DECLARANDO NOMBRES DE ESPACIO
using namespace std;

//CLASE NODO
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

//CLASE LISTA DOBLE
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

	void incrementNElements() {
		nElements += 1;
	}

	int getNElements() {
		return nElements; 
	}

	void addNode(Node<dataType>* toAdd) {
		toAdd->setNext(sentinel->getNext());
		sentinel->getNext()->setPrevious(toAdd);
		sentinel->setNext(toAdd);
		toAdd->setPrevious(sentinel);
		nElements = nElements + 1;
	}

	Node<dataType>* getSentinel() {
		return sentinel;
	}

	void printListInverse() {
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
};

class CursoEstudiante {
	private:
		char nombreCurso[StringLength];
		int evalRealiz;
		int notas[3];
		int notaFinal;
		bool cursoTerminado;
		bool certificado;

		void calcularNotaFinal() {
			int sumatoria = 0;
			float promedio = (float) 0;
			float parte_entera = 0;
			float parte_decimal = 0;

			for (int i = 0; i < 3; i++) {
				sumatoria += notas[i];
			}

			promedio = (float) sumatoria / 3;

			parte_entera = floor(promedio);
			parte_decimal = promedio - parte_entera;

			if (parte_decimal > 0.5) {
				promedio = ceil(promedio);
			}
			else {
				promedio = floor(promedio);
			}

			if (promedio >= 4.5) {
				cursoTerminado = true;
				certificado = true;
				notaFinal = (int) promedio;
			}
			else {
				cursoTerminado = true;
				certificado = false;
				notaFinal = (int) promedio;
			}
		}

		void terminarCurso() {
			if (evalRealiz != 3) {
				cerr << "Error: El curso todavia no ha terminado." << endl;
			}
			else {
				calcularNotaFinal();
			}
		}

	public:

		CursoEstudiante() {
			strcpy_s(nombreCurso, "NO-NAME-COURSE");
			evalRealiz = 0;

			/*INICIALIZANDO EN VALORES INVALIDOS(NOTAS < 0) PARA QUE NO HAYA BASURA
			* SINO VALORES QUE INDIQUEN NOTAS NO CARGADAS
			*/
			for (int i = 0; i < 3; i++) {
				notas[i] = -1;
			}

			notaFinal = -1;

			cursoTerminado = false;
			certificado = false;
		}

		CursoEstudiante(string name) {
			strcpy_s(nombreCurso, name.c_str());
			evalRealiz = 0;

			/*INICIALIZANDO EN VALORES INVALIDOS(NOTAS < 0) PARA QUE NO HAYA BASURA
			* SINO VALORES QUE INDIQUEN NOTAS NO CARGADAS
			*/
			for (int i = 0; i < 3; i++) {
				notas[i] = -1;
			}

			notaFinal = -1;

			cursoTerminado = false;
			certificado = false;
		}

		void setNombreCurso(string str) {
			strcpy_s(nombreCurso, str.c_str());
		}

		void setEvalRealiz(int i) {
			evalRealiz = i;
		}

		void setNotas(int arrNotas[]) {
			for (int i = 0; i < 3; i++) {
				notas[i] = arrNotas[i];
			}
		}

		void setNotaFinal(int i) {
			notaFinal = i;
		}

		void setCursoTerminado(bool booleano) {
			cursoTerminado = booleano;
		}

		void setCertificado(bool booleano) {
			certificado = booleano;
		}

		char* getNombreCurso() {
			return nombreCurso;
		}

		int getEvalRealiz() {
			return evalRealiz;
		}

		int* getNotas() {
			return notas;
		}

		int getNotaFinal() {
			return notaFinal;
		}

		bool getCursoTerminado() {
			return cursoTerminado;
		}

		bool getCertificado() {
			return certificado;
		}

		bool cargarNota(int nuevaNota) {
			if (evalRealiz == 3) {
				cerr << "Error: No se puede cargar nota ya que el curso ha finalizado." << endl;
				return false;
			}
			else {
				notas[evalRealiz] = nuevaNota;
				evalRealiz++;
				
				if (evalRealiz == 3) {
					terminarCurso();
				}
			}
		}
};

//FUNCION PRINCIPAL
int main(int args, char* argsv[]) {
	
	cout << "Hola Mundo" << endl;

	return 0;
}