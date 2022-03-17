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

class Curso {
private:
	int id;
	char nombreCurso[StringLength];
	char nombreProfesor[StringLength];

public:
	Curso() {
		id = 0;
		strcpy_s(nombreCurso, "NO-NAME-COURSE");
		strcpy_s(nombreProfesor, "NO-NAME-PROFESOR");
	}

	Curso(string str) {
		id = 0;
		strcpy_s(nombreCurso, str.c_str());
	}

	Curso(string curso, string profe) {
		id = 0;
		strcpy_s(nombreCurso, curso.c_str());
		strcpy_s(nombreProfesor, profe.c_str());
	}

	void setID(int i) {
		id = i;
	}

	void setNombreCurso(string str) {
		strcpy_s(nombreCurso, str.c_str());
	}

	void setNombreProfesor(string str) {
		strcpy_s(nombreProfesor, str.c_str());
	}

	int getID() {
		return id;
	}

	char* getNombreCurso() {
		return nombreCurso;
	}

	char* getNombreProfesor() {
		return nombreProfesor;
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

class Estudiante {
	private:
		int id;
		char nombreEstudiante[StringLength];
		DoubleLinkedList<CursoEstudiante> listaCursos;

	public:
		Estudiante() {
			id = 0;
			strcpy_s(nombreEstudiante, "NO-NAME-STUDENT");
		}

		Estudiante(string str) {
			id = 0;
			strcpy_s(nombreEstudiante, str.c_str());
		}

		void setID(int i) {
			id = i;
		}

		void setNombreEstudiante(string str) {
			strcpy_s(nombreEstudiante, str.c_str());
		}

		void setListaCursos(DoubleLinkedList<CursoEstudiante> newList) {
			listaCursos = newList;
		}

		int getID() {
			return id;
		}

		char* getNombreEstudiante() {
			return nombreEstudiante;
		}

		DoubleLinkedList<CursoEstudiante> getListaCursos() {
			return listaCursos;
		}
};

class CursoProfesor {
	private:
		char nombreCurso[StringLength];

	public:
		CursoProfesor() {
			strcpy_s(nombreCurso, "NO-NAME-COURSE");
		}

		CursoProfesor(string str) {
			strcpy_s(nombreCurso, str.c_str());
		}

		void setNombreCurso(string str) {
			strcpy_s(nombreCurso, str.c_str());
		}

		char* getNombreCurso() {
			return nombreCurso;
		}
};

class Profesor {
	private:
		int id;
		char nombreProf[StringLength];
		DoubleLinkedList<CursoProfesor> listaCursos;

	public:
		Profesor() {
			strcpy_s(nombreProf, "NO-NAME-PROF");
		}

		Profesor(string str) {
			strcpy_s(nombreProf, str.c_str());
		}

		void setID(int i) {
			id = i;
		}

		void setNombreProf(string str) {
			strcpy_s(nombreProf, str.c_str());
		}

		void setListaCursos(DoubleLinkedList<CursoProfesor> newList) {
			listaCursos = newList;
		}

		int getID() {
			return id;
		}

		char* getNombreProf() {
			return nombreProf;
		}

		DoubleLinkedList<CursoProfesor> getListaCursos() {
			return listaCursos;
		}
};

class ModuloMonitoreo {
	private:
		DoubleLinkedList<Curso> listadoCursos;
		DoubleLinkedList<Estudiante> listadoEstudiantes;
		DoubleLinkedList<Profesor> listadoProfesores;

	public:
		void setListadoCursos(DoubleLinkedList<Curso> data) {
			listadoCursos = data;
		}

		void setListadoEstudiantes(DoubleLinkedList<Estudiante> data) {
			listadoEstudiantes = data;
		}

		void setListadoProfesores(DoubleLinkedList<Profesor> data) {
			listadoProfesores = data;
		}

		DoubleLinkedList<Curso> getListadoCursos() {
			return listadoCursos;
		}

		DoubleLinkedList<Estudiante> getListadoEstudiantes() {
			return listadoEstudiantes;
		}

		DoubleLinkedList<Profesor> getListadoProfesores() {
			return listadoProfesores;
		}

		void imprimirCursosDisponiblesAProfesores() {
			bool disponible = false;
			Node<Curso>* sentinel = listadoCursos.getSentinel();
			Node<Curso>* current = sentinel->getPrevious();
			cout << "Cursos disponibles (Sin profesor agregado): " << endl << endl;

				while (current != sentinel) {
					if ((string)current->getKey().getNombreProfesor() == (string)"NO-NAME-PROFESOR") {
						cout << "Nombre Curso: " << current->getKey().getNombreCurso() << "Codigo Curso: ";
						cout << current->getKey().getID() << endl;
						disponible = true;
					}

					current = current->getPrevious();
				}

				if (current == sentinel && disponible == false) {
					cerr << "Error: No hay cursos disponibles, ingrese -1 para salir." << endl;
				}
		}

		void imprimirCursosDisponiblesAEstudiantes() {
			bool disponible = false;
			Node<Curso>* sentinel = listadoCursos.getSentinel();
			Node<Curso>* current = sentinel->getPrevious();
			cout << "Cursos disponibles: " << endl << endl;

			while (current != sentinel) {
				if ((string)current->getKey().getNombreProfesor() != (string)"NO-NAME-PROFESOR" && (string)current->getKey().getNombreCurso() != (string)"NO-NAME-COURSE") {
					cout << "Nombre Curso: " << current->getKey().getNombreCurso() << "\tCodigo Curso : ";
					cout << current->getKey().getID() << endl;
					disponible = true;
				}

				current = current->getPrevious();
			}

			if (current == sentinel && disponible == false) {
				cerr << "Error: No hay cursos disponibles, ingrese -1 para salir." << endl;
			}
		}

		void imprimirListaProfs() {
			Node<Profesor>* sentinel = listadoProfesores.getSentinel();
			Node<Profesor>* current = sentinel->getPrevious();

			while (current != sentinel) {
				
				cout << "Nombre: " << current->getKey().getNombreProf() << "\t C.I: " << current->getKey().getID() << endl;

				current = current->getPrevious();
			}
		}

		Node<Curso>* buscarCurso(int id) {
			Node<Curso>* sentinel = listadoCursos.getSentinel();
			Node<Curso>* current = sentinel->getPrevious();

			while (current != sentinel) {

				if (current->getKey().getID() == id) {
					return current;
				}

				current = current->getPrevious();
				
				if (current == sentinel) {
					cerr << "Error: El id ingresado no se encuentra en la lista." << endl;
					return NULL;
				}
			}
		}

		Node<Profesor>* buscarProfesor(int id) {
			Node<Profesor>* sentinel = listadoProfesores.getSentinel();
			Node<Profesor>* current = sentinel->getPrevious();

			while (current != sentinel) {

				if (current->getKey().getID() == id) {
					return current;
				}

				current = current->getPrevious();

				if (current == sentinel) {
					cerr << "Error: El id ingresado no se encuentra en la lista." << endl;
					return NULL;
				}
			}
		}

		void crearCurso() {
			int intaux;
			char straux[StringLength];
			Curso nuevoCurso;
			Node<Curso>* nodeCurso = NULL;

			cout << "Ingese el codigo del curso: ";
			cin >> intaux; cout << endl;

			nuevoCurso.setID(intaux);

			cout << "Ingrese nombre del curso: ";
			cin.ignore();
			cin.getline(straux, StringLength, '\n');
			cout << endl;

			nuevoCurso.setNombreCurso(straux);

			nodeCurso = new Node<Curso>;
			nodeCurso->setKey(nuevoCurso);

			listadoCursos.addNode(nodeCurso);
		}

		void crearProfesor() {
			int intaux;
			char straux[StringLength];
			Profesor nuevoProfesor;
			Node<Profesor>* nodeProfesor = NULL;

			cout << "Ingese CI del profesor: ";
			cin >> intaux; cout << endl;

			nuevoProfesor.setID(intaux);

			cout << "Ingrese nombre del profesor en el formato (Nombre Apellido): ";
			cin.ignore();
			cin.getline(straux, StringLength, '\n');
			cout << endl;

			nuevoProfesor.setNombreProf(straux);

			Node<Curso>* searchResult = NULL;
			do {
				imprimirCursosDisponiblesAProfesores();
				cout << endl;
				cout << "Ingrese el codigo de la materia que desea agregar al profesor " << nuevoProfesor.getNombreProf() << endl;
				cout << "Codigo: ";
				cin >> intaux; cout << endl;

				if (intaux == -1) {
					return;
				}

				searchResult = buscarCurso(intaux);
				if (searchResult == NULL) {
					continue;
				}
				else {
					break;
				}

			} while (true);

			Node<CursoProfesor>* nodeCursoProf = NULL;
			CursoProfesor cursoProf;

			cursoProf.setNombreCurso(searchResult->getKey().getNombreCurso());

			nodeCursoProf = new Node<CursoProfesor>;
			nodeCursoProf->setKey(cursoProf);
			nuevoProfesor.getListaCursos().addNode(nodeCursoProf);
			nuevoProfesor.getListaCursos().incrementNElements();

			DoubleLinkedList<CursoProfesor> listaCursoProfAux = nuevoProfesor.getListaCursos();
			listaCursoProfAux.incrementNElements();
			nuevoProfesor.setListaCursos(listaCursoProfAux);

			Curso auxiliarKey = searchResult->getKey();
			auxiliarKey.setNombreProfesor(nuevoProfesor.getNombreProf());
			searchResult->setKey(auxiliarKey);



			nodeProfesor = new Node<Profesor>;
			nodeProfesor->setKey(nuevoProfesor);

			listadoProfesores.addNode(nodeProfesor);
		}

		void crearEstudiante() {
			
			char straux[StringLength];
			int intaux;
			Node<Estudiante>* nodeNuevoEstudiante = NULL;
			Estudiante nuevoEstudiante;

			cout << "Ingese CI del Estudiante: ";
			cin >> intaux; cout << endl;

			nuevoEstudiante.setID(intaux);

			cout << "Ingrese nombre del estudiante en el formato (Nombre Apellido): ";
			cin.ignore();
			cin.getline(straux, StringLength, '\n');
			cout << endl;

			nuevoEstudiante.setNombreEstudiante(straux);

			Node<Curso>* searchResult = NULL;
			do {
				imprimirCursosDisponiblesAEstudiantes();
				cout << endl;
				cout << "Ingrese el codigo de la materia que desea inscribir al estudiante " << nuevoEstudiante.getNombreEstudiante() << endl;
				cout << "Codigo: ";
				cin >> intaux; cout << endl;

				if (intaux == -1) {
					return;
				}

				searchResult = buscarCurso(intaux);
				if (searchResult == NULL) {
					continue;
				}
				else {
					break;
				}

			} while (true);

			
			Node<CursoEstudiante>* nodeCursoEstudiante;
			CursoEstudiante cursoEstudiante;

			nodeCursoEstudiante = new Node<CursoEstudiante>;
			cursoEstudiante.setNombreCurso(searchResult->getKey().getNombreCurso());
			nodeCursoEstudiante->setKey(cursoEstudiante);

			nuevoEstudiante.getListaCursos().addNode(nodeCursoEstudiante);
			DoubleLinkedList<CursoEstudiante> listaCursoEstudianteAux = nuevoEstudiante.getListaCursos();
			listaCursoEstudianteAux.incrementNElements();
			nuevoEstudiante.setListaCursos(listaCursoEstudianteAux);


			nodeNuevoEstudiante = new Node<Estudiante>;
			nodeNuevoEstudiante->setKey(nuevoEstudiante);
			listadoEstudiantes.addNode(nodeNuevoEstudiante);
		}

		void agregarCursoAProf() {
			int intaux;
			Node<Curso>* searchResultCurso = NULL;
			Node<Profesor>* searchResultProfesor = NULL;

			do {
				imprimirCursosDisponiblesAProfesores();
				cout << "Ingrese codigo del curso a agregar: ";
				cin >> intaux; cout << endl;
				
				if (intaux == -1) {
					return;
				}

				searchResultCurso = buscarCurso(intaux);
				if (searchResultCurso == NULL) {
					continue;
				}
				else {
					break;
				}

			} while (true);

			do {
				cout << "Profesores disponibles para agregar cursos: " << endl;
				imprimirListaProfs();
				cout << "Ingrese C.I: del profesor al que va a agegar el curso: ";
				cin >> intaux; cout << endl;
				
				if (intaux == -1) {
					return;
				}

				searchResultProfesor = buscarProfesor(intaux);
				if (searchResultProfesor == NULL) {
					continue;
				}
				else {
					break;
				}
			} while (true);

			Profesor profesorModificable = searchResultProfesor->getKey();
			Curso cursoModificable = searchResultCurso->getKey();

			Node<CursoProfesor>* nodeNuevoCurso = NULL;
			CursoProfesor nuevoCurso;

			nuevoCurso.setNombreCurso(cursoModificable.getNombreCurso());
			nodeNuevoCurso = new Node<CursoProfesor>;
			nodeNuevoCurso->setKey(nuevoCurso);
			profesorModificable.getListaCursos().addNode(nodeNuevoCurso);

			DoubleLinkedList<CursoProfesor> nuevaLista = profesorModificable.getListaCursos();
			nuevaLista.incrementNElements();
			profesorModificable.setListaCursos(nuevaLista);

			searchResultProfesor->setKey(profesorModificable);

			cursoModificable.setNombreProfesor(profesorModificable.getNombreProf());
			searchResultCurso->setKey(cursoModificable);

			cout << "Curso agregado a profesor... " << endl;
		}

		void agregarCursoAEstu() {}
};

//FUNCION PRINCIPAL
int main(int args, char* argsv[]) {
	
	ModuloMonitoreo moduloPrueba;

	moduloPrueba.crearCurso();
	moduloPrueba.crearCurso();
	moduloPrueba.crearCurso();
	moduloPrueba.crearCurso();

	moduloPrueba.crearProfesor();
	moduloPrueba.crearProfesor();

	moduloPrueba.crearEstudiante();
	moduloPrueba.crearEstudiante();

	moduloPrueba.agregarCursoAProf();
	moduloPrueba.agregarCursoAProf();

	return 0;
}