#include <iostream>
#include <fstream>
#include <string>

int const MAXCHAR = 25;

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
	/*static*/ int nElements;
	Node<dataType>* sentinel;

public:

	DoubleLinkedList() {
		sentinel = new Node<dataType>;
		sentinel->setNext(sentinel);
		sentinel->setPrevious(sentinel);
		nElements = 0;
	}

	void incrementNElements() { nElements += 1; }

	int getNElements() { return nElements; }

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
/*template <class dataType>
int DoubleLinkedList<dataType>::nElements = 0;*/

//Declaracion de clases
class Instructor;
class Curso;
class CursoEstudiante;
class CursoProfesor;
class Estudiante;
class moduloMonitoreo;

class Instructor {
	private:
		int id;
		char nombre[MAXCHAR];
		char apellido[MAXCHAR];
		DoubleLinkedList<CursoProfesor> cursosDictados;

	public:
		void setId(int i) {
			id = i;
		}

		void setNombre(string str) {
			strcpy_s(nombre, str.c_str());
		}

		void setApellido(string str) {
			strcpy_s(apellido, str.c_str());
		}

		void setCursosDictados(DoubleLinkedList<CursoProfesor> lista) {
			cursosDictados = lista;
		}

		int getId() {
			return id;
		}

		char* getNombre() {
			return nombre;
		}

		char* getApellido() {
			return apellido;
		}

		DoubleLinkedList<CursoProfesor> getCursosDictados() {
			return cursosDictados;
		}
};

class Curso {
	private:
		int id;
		char nombre[MAXCHAR];
		char instructor[MAXCHAR];
		DoubleLinkedList<Estudiante> listadoEstudiantes;

	public:
		void setId(int i) {
			id = i;
		}

		void setNombre(string str) {
			strcpy_s(nombre, str.c_str());
		}

		void setInstructor(string inst) {
			strcpy_s(instructor, inst.c_str());
		}

		void setListadoEstudiantes(DoubleLinkedList<Estudiante> lista) {
			listadoEstudiantes = lista;
		}

		int getId() {
			return id;
		}

		string getNombre() {
			return nombre;
		}

		char* getInstructor() {
			return instructor;
		}

		DoubleLinkedList<Estudiante> getListadoEstudiantes() {
			return listadoEstudiantes;
		}
};

class CursoProfesor {
	private:
		char nombreCurso[MAXCHAR];

	public:
		void setNombreCurso(string str) {
			strcpy_s(nombreCurso, str.c_str());
		}

		char* getNombreCurso() {
			return nombreCurso;
		}
};

class CursoEstudiante {
	private:
		char nombreCurso[MAXCHAR];
		/*static*/ int notaFinal = 0;
		/*static*/ int notasParciales[3] = {-1, -1, -1};
		/*static*/ bool terminado = false;
		/*static*/ bool aprobado = false;

	public:
		void setNombreCurso(string str) {
			strcpy_s(nombreCurso, str.c_str());
		}

		void setNotaFinal(int i) {
			notaFinal = i;
		}

		void setNotasParciales(int notas[]) {
			for (int i = 0; i < 3; i++) {
				notasParciales[i] = notas[i];
			}
		}

		void setAprobado(bool certificado) {
			aprobado = certificado;
		}

		int getNotaFinal() {
			return notaFinal;
		}

		int* getNotasParciales() {
			return notasParciales;
		}

		bool getAprobado() {
			return aprobado;
		}

		string getNombre() {
			return nombreCurso;
		}

		void calculaCertificado() {
			int sumatoria = 0;

			for (int i = 0; i < 3; i++) {
				sumatoria += notasParciales[i];
			}

			if (sumatoria >= 5) {
				aprobado = true;
				terminado = true;
				cout << "Este estudiante ha aprobado el curso" << endl;
			}
			else {
				aprobado = false;
				terminado = true;
				cout << "Este estudiante no ha aprobado el curso" << endl;
			}
		}

		void cargarNota(int notaACargar) {
			int i = 0;

			while (notasParciales[i] != -1) {
				i++;
			}
			if (i == 2 && notasParciales[i] != -1) {
				cerr << "ERROR: Ya han sido cargadas todas las notas de esta materia a este estudiante." << endl;
			}
			else {
				if (i == 2) {
					calculaCertificado();
				}
				else {
					notasParciales[i] = notaACargar;
				}
			}
		}
};
/*int CursoEstudiante::notaFinal = 0;
int CursoEstudiante::notasParciales[3] = { -1, -1, -1 };
bool CursoEstudiante::terminado = false;
bool CursoEstudiante::aprobado = false;*/

/*
		static char nombreCurso[MAXCHAR];
		static int notaFinal = 0;
		static int notasParciales[3] = {-1, -1, -1};
		static bool terminado = false;
		static bool aprobado = false;
*/
class Estudiante {
	private:
		int id;
		char nombre[MAXCHAR];
		char apellido[MAXCHAR];
		DoubleLinkedList<CursoEstudiante> cursos;

	public:
		void setId(int newid) {
			id = newid;
		}

		void setNombre(string str) {
			strcpy_s(nombre, str.c_str());
		}

		void setApellido(string str) {
			strcpy_s(apellido, str.c_str());
		}

		void setCursos(DoubleLinkedList<CursoEstudiante> lista) {
			cursos = lista;
		}

		int getId() {
			return id;
		}

		char* getNombre() {
			return nombre;
		}
		
		char* getApellido() {
			return apellido;
		}

		DoubleLinkedList<CursoEstudiante> getCursos() {
			return cursos;
		}
};

class ModuloMonitoreo {
	private:
		DoubleLinkedList<Instructor> listadoInstructores;
		DoubleLinkedList<Curso> listadoCursos;
		DoubleLinkedList<Estudiante> listadoEstudiantes;

	public:
		void setListadoInstructores(DoubleLinkedList<Instructor> listado) {
			listadoInstructores = listado;
		}

		void setListadoCursos(DoubleLinkedList<Curso> listado) {
			listadoCursos = listado;
		}

		void setListadoEstudiantes(DoubleLinkedList<Estudiante> listado) {
			listadoEstudiantes = listado;
		}

		DoubleLinkedList<Instructor> getListadoInstructores() {
			return listadoInstructores;
		}

		DoubleLinkedList<Curso> getListadoCurso() {
			return listadoCursos;
		}

		DoubleLinkedList<Estudiante> getListadoEstudiantes() {
			return listadoEstudiantes;
		}

		void imprimirCursosDisp() {
			if (listadoCursos.getNElements() == 0) {
				cout << "No hay cursos Disponibles" << endl;
			}
			else {
				Node<Curso>* currentCourse;
				Node<Curso>* sentinel;

				sentinel = listadoCursos.getSentinel();
				currentCourse = sentinel->getPrevious();
				cout << "Cursos disponibles: " << endl;
				while (currentCourse != sentinel) {
					
					cout << "Nombre Curso: " << currentCourse->getKey().getNombre() << endl;
					cout << "ID: " << currentCourse->getKey().getId() << endl << endl;
					
					currentCourse = currentCourse->getPrevious();
				}
			}
		}

		Node<Estudiante>* buscarEstudiante(int id) {
			if (listadoCursos.getNElements() == 0) {
				cout << "No hay estudiantes" << endl;
			}
			else {
				Node<Estudiante>* currentEst;
				Node<Estudiante>* sentinel;

				sentinel = listadoEstudiantes.getSentinel();
				currentEst = sentinel->getPrevious();
				while (currentEst != sentinel) {
					if (currentEst->getKey().getId() == id) {
						return currentEst;
					}
					currentEst = currentEst->getPrevious();
				}
			}
			cout << "Estudiante no encontrado" << endl;
			return NULL;
		}

		Node<Curso>* buscarCurso(int id) {
			if (listadoCursos.getNElements() == 0) {
				cout << "No hay cursos Disponibles" << endl;
			}
			else {
				Node<Curso>* currentCourse;
				Node<Curso>* sentinel;

				sentinel = listadoCursos.getSentinel();
				currentCourse = sentinel->getPrevious();
				while (currentCourse != sentinel) {
					if (currentCourse->getKey().getId() == id) {
						return currentCourse;
					}
					currentCourse = currentCourse->getPrevious();
				}
			}
			cout << "Curso no encontrado" << endl;
			return NULL;
		}

		Node<Instructor>* buscarProfesorAgregarCurso(int id) {
			if (listadoInstructores.getNElements() == 0) {
				cout << "No hay profesores disponibles" << endl;
			}
			else {
				Node<Instructor>* currentProfesor;
				Node<Instructor>* sentinel;

				sentinel = listadoInstructores.getSentinel();
				currentProfesor = sentinel->getPrevious();

				while (currentProfesor != sentinel) {
					
					if (currentProfesor->getKey().getId() == id) {
						return currentProfesor;
					}

					currentProfesor = currentProfesor->getPrevious();
				}
			}
			return NULL;
		}

		void crearProfesor() {
			int id;
			string str;
			Instructor profesorClave;
			Node<Instructor>* ProfesorNodo = NULL;

			cout << "Ingrese la CI del profesor: ";
			cin >> id; cout << endl;
			profesorClave.setId(id);

			cout << "Ingrese el nombre del profesor: ";
			cin >> str; cout << endl;
			profesorClave.setNombre(str);

			cout << "Ingrese el apellido del profesor: ";
			cin >> str; cout << endl;
			profesorClave.setApellido(str);

			ProfesorNodo = new Node<Instructor>;
			ProfesorNodo->setKey(profesorClave);

			listadoInstructores.addNode(ProfesorNodo);

			cout << "Profesor agregado exitosamente" << endl;

		}

		void crearCurso() {
			int id;
			string str;
			Curso cursoClave;
			Node<Curso>* cursoNode = NULL;

			cout << "Ingrese el ID del curso: ";
			cin >> id; cout << endl;
			cursoClave.setId(id);

			cout << "Ingrese el nombre del curso: ";
			cin >> str; cout << endl;
			cursoClave.setNombre(str);

			cursoNode = new Node<Curso>;
			cursoNode->setKey(cursoClave);

			listadoCursos.addNode(cursoNode);

			cout << "Curso creado con exito" << endl;
		}

		void agregarCursoProfesor(int idCurso, int idProf) {
			Node<Curso>* curso;
			Node<Instructor>* profesor;
			curso = buscarCurso(idCurso);
			profesor = buscarProfesorAgregarCurso(idProf);

			Instructor profesorAux;

			Node<CursoProfesor>* cursoProfNodo = NULL;
			CursoProfesor cursoProfKey;

			cursoProfKey.setNombreCurso(curso->getKey().getNombre());
			cursoProfNodo = new Node<CursoProfesor>;
			cursoProfNodo->setKey(cursoProfKey);

			profesor->getKey().getCursosDictados().addNode(cursoProfNodo);
			Instructor proobj = profesor->getKey();
			
			Curso cursoaux = curso->getKey();
			cursoaux.setInstructor(proobj.getNombre());
			curso->setKey(cursoaux);

			cout << "nElementos = " << profesor->getKey().getCursosDictados().getNElements() << endl;

			cout << "Agregado curso a prof y prof a curso" << endl;

		}

		void crearEstudiante() {
			int idCurso;
			if (listadoCursos.getNElements() == 0) {
				cout << "No se puede agregar estudiante ya que no existen cursos." << endl;
				cout << "Primero cree un curso, agregue instructor y luego agregue el estudiante." << endl;
			}
			else {
				cout << "Listado de cursos disponibles: " << endl;
				imprimirCursosDisp();

				cout << "Ingrese el ID del curso al cual desea agregar al estudiante: ";
				cin >> idCurso; cout << endl;
			}

			int id;
			string str;
			Estudiante estudianteClave;
			Node<Estudiante>* estudianteNode = NULL;
			Node<Curso>* cursoAgregar = NULL;
			CursoEstudiante cursoObjeto;
			Node<CursoEstudiante>* cursoEstudianteNode = NULL;

			cursoAgregar = buscarCurso(idCurso);

			cout << "Ingrese CI del estudiante: ";
			cin >> id; cout << endl;
			estudianteClave.setId(id);

			cout << "Ingrese el nombre del estudiante: ";
			cin >> str; cout << endl;
			estudianteClave.setNombre(str);

			cout << "Ingrese el apellido del estudiante: ";
			cin >> str; cout << endl;
			estudianteClave.setApellido(str);

			cursoObjeto.setNombreCurso(cursoAgregar->getKey().getNombre());

			cursoEstudianteNode = new Node<CursoEstudiante>;
			cursoEstudianteNode->setKey(cursoObjeto);

			estudianteClave.getCursos().addNode(cursoEstudianteNode);

			estudianteNode = new Node<Estudiante>;
			estudianteNode->setKey(estudianteClave);

			cursoAgregar->getKey().getListadoEstudiantes().addNode(estudianteNode);

			listadoEstudiantes.addNode(estudianteNode);

			cout << "Estudiante Inscrito Exitosamente... " << endl;
		}

		void cargarNotas() {

			int id;

			imprimirCursosDisp();

			cout << "Ingrese ID de la materia a la cual cargar notas: ";
			cin >> id; cout << endl;

			Node<Curso>* cursoCargarNotas = NULL;
			cursoCargarNotas = buscarCurso(id);

			Node<Estudiante>* EstudianteSentinelCurso = NULL;
			EstudianteSentinelCurso = cursoCargarNotas->getKey().getListadoEstudiantes().getSentinel();

			Node<Estudiante>* EstudianteActualCurso = NULL;
			EstudianteActualCurso = EstudianteSentinelCurso->getPrevious();

			while (EstudianteActualCurso != EstudianteSentinelCurso) {
				Node<Estudiante>* EstudianteEnListado = NULL;
				EstudianteEnListado = buscarEstudiante(EstudianteActualCurso->getKey().getId());
				
				int nota = 0;
				cout << "Estudiante: " << EstudianteEnListado->getKey().getNombre() << endl;
				cout << "Ingrese la nota del examen a cargar: ";
				cin >> nota; cout << endl;

				Node<CursoEstudiante>* sentinelCursoListado = NULL;
				sentinelCursoListado = EstudianteEnListado->getKey().getCursos().getSentinel();

				Node<CursoEstudiante>* currentCursoListado = NULL;
				currentCursoListado = sentinelCursoListado->getPrevious();

				while (currentCursoListado != sentinelCursoListado) {
					if (currentCursoListado->getKey().getNombre() == cursoCargarNotas->getKey().getNombre()) {
						currentCursoListado->getKey().cargarNota(nota);
						break;
					}
					if (currentCursoListado->getPrevious() == sentinelCursoListado) {
						break;
					}
					else {
						currentCursoListado = currentCursoListado->getPrevious();
					}
				}

				if (EstudianteActualCurso->getPrevious() == EstudianteSentinelCurso || EstudianteActualCurso->getPrevious()->getKey().getId() < 0) {
					break;
				}
				else {
					EstudianteActualCurso = EstudianteActualCurso->getPrevious();
				}
			}

		}

		void verificarnotasloly() {
			Node<Estudiante>* current = listadoEstudiantes.getSentinel()->getPrevious();

			cout << "PrimeraNota: " << endl;
			cout << "EST: " << current->getKey().getNombre() << endl;
			cout << "NOTA:" << current->getKey().getCursos().getSentinel()->getPrevious()->getKey().getNotasParciales()[0] << endl;
		}

		void verificarnotasmary() {
			Node<Estudiante>* current = listadoEstudiantes.getSentinel()->getPrevious()->getPrevious();

			cout << "PrimeraNota: " << endl;
			cout << "EST: " << current->getKey().getNombre() << endl;
			cout << "NOTA:" << current->getKey().getCursos().getSentinel()->getPrevious()->getKey().getNotasParciales()[0] << endl;
		}

		void verificarnotassofi() {
			Node<Estudiante>* current = listadoEstudiantes.getSentinel()->getPrevious()->getPrevious()->getPrevious();

			cout << "PrimeraNota: " << endl;
			cout << "EST: " << current->getKey().getNombre() << endl;
			cout << "NOTA:" << current->getKey().getCursos().getSentinel()->getPrevious()->getKey().getNotasParciales()[0] << endl;
		}

};

int main(int args, char* argsv[]) {

	ModuloMonitoreo monitoreo;

	monitoreo.crearCurso();
	monitoreo.crearProfesor();
	monitoreo.agregarCursoProfesor(1, 25687494);
	monitoreo.crearEstudiante();
	monitoreo.crearEstudiante();
	monitoreo.crearEstudiante();
	monitoreo.cargarNotas();
	monitoreo.verificarnotasloly();
	monitoreo.verificarnotasmary();
	monitoreo.verificarnotassofi();
	/*fstream archivo("objeto.bin", ios::out | ios::binary);


	estudiante est;

	est.setid(25687494);
	est.setnombre("Luis Antonio");
	est.setapellido("Marquez Castro");

	archivo.write(reinterpret_cast<char*> (&est), sizeof(estudiante));
	archivo.close();
	
	est.setid(0);
	est.setnombre("");
	est.setapellido("");

	archivo.open("objeto.bin", ios::in | ios::binary);

	archivo.read(reinterpret_cast<char*> (&est), sizeof(estudiante));

	archivo.close();
	*/

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

//======================================================READ==================================================	
/*
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
*/

	return 0;
}