
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct cita {

	string nombre;
	int num_cita = 1;
	string Hora = ""; //le asignamos "" para que no se guarde basura en la variable
	string tratamiento = ""; //se guardara el tratamiento seleccionado por el paciente
	float precio = 0;
	float preciounitario = 0;
	int Ctratamientos = 0;
	cita* anterior = nullptr;
	cita* siguiente = nullptr;
};

cita* primer_cita = nullptr;
cita* ultima_cita = nullptr;
cita* cita_auxiliar = nullptr;
int cita_actual = 0;
int opcion_citamodificar = 0;

int leer_txt();

void imprimir_cita() {
	cita_auxiliar = primer_cita;

	if (!cita_auxiliar) {
		cout << "No se han registrado citas." << endl;
	}
	else {
		while (cita_auxiliar) {
			cout << "Numero de cita: " << cita_auxiliar->num_cita << endl;
			cout << "\n-----------------\n";
			cout << "Nombre del paciente: " << cita_auxiliar->nombre << endl;
			cout << "\nTratamiento seleccionado: " << cita_auxiliar->tratamiento << endl;
			cout << "\nHora programada para la cita: " << cita_auxiliar->Hora << " horas" << endl;
			cout << "\nPrecio unitario: " << cita_auxiliar->preciounitario << endl;
			cout << "\nCantidad de tratamientos: " << cita_auxiliar->Ctratamientos << endl;
			cout << "\nTotal a pagar: " << cita_auxiliar->precio << endl;
			cout << "\n-----------------\n";
			if (cita_auxiliar->anterior) {
				cout << "cita anterior: " << cita_auxiliar->anterior->nombre << endl;

			}
			if (cita_auxiliar->siguiente) {
				cout << "cita siguiente: " << cita_auxiliar->siguiente->nombre << endl;
			}

			cita_auxiliar = cita_auxiliar->siguiente;
		}

	}
	system("pause");
}

void registrar_txt();




int main() {
	//una interfaz interesante:)
	system("color A");
	cout << "\nBienvenido a nuestro programa de citas dentales\n" << endl;
	cout << "Esperamos que el servicio proporcionado sea de su agrado.\n" << endl;
	system("pause");
	system("cls");

	cita_actual = leer_txt();
	if (cita_actual != 0) {
		cout << "Citas cargadas correctamente\n";
		system("pause");
		system("cls");
	}
	int menu = 0; //declaramos la variable como tipo entero para que su valor pueda ser numérico

	float Plimpieza = 100, PDiagnostico = 0, PBrackets = 1500, PAjuste = 390, PImplante = 20000;

	int Numtratamiento;
	int modificar_cita = 0;
	int cantidadcitas = 0;
	system("color 8F");
	int i = 0;
	while (menu != 6)
	{
		system("cls");
		cout << "______________________________" << endl;
		cout << "Bienvenido al Menu de opciones" << endl; //esto es para imprimir el menú y dar la lista de opciones al usuario
		cout << "______________________________" << endl;
		cout << "1. Agendar Cita" << endl;
		cout << "2. Modificar Cita" << endl;
		cout << "3. Eliminar Cita" << endl;
		cout << "4. Lista de Citas Vigentes" << endl;
		cout << "5. Limpiar Pantalla" << endl;
		cout << "6. Salir" << endl;
		cout << "______________________________" << endl;
		cout << "Que numero de opcion desea elegir?" << endl;

		cin >> menu; //se pide el valor de menú para poder evaluarlo en el switch

		switch (menu) //se va a evaluar menú y de acuerdo al dato introducido es lo que se realizará
		{
		case 1:  //si el valor de menú es 1, se realizará lo siguiente
		{

			system("cls"); //Limpiar pantalla
			cita* nueva_cita = new cita;

			cout << "------------" << endl; //esto es estético:)
			cout << "Agendar Cita" << endl;
			cout << "------------" << endl;
			cout << "Nombre del paciente: ";
			cin.ignore();
			getline(cin, nueva_cita->nombre);
			cout << "Hora del tratamiento (formato 24 horas, Ejemplo: 09:30) : ";
			cin >> nueva_cita->Hora;
			cout << "\nTenemos la siguiente lista de tratamientos: " << endl;
			cout << "-------------------------------------------" << endl;
			cout << "1. Limpieza" << endl;
			cout << "2. Diagnostico" << endl;
			cout << "3. Brackets" << endl;
			cout << "4. Ajuste de Brackets" << endl;
			cout << "5. Implante" << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Que tratamiento desea adquirir? ";
			cin >> Numtratamiento;
			if (Numtratamiento >= 6) {
				delete nueva_cita;
			}
			// como se seleccionó la opión de agendar cita, es importante que los punteros conozcan cuál es su cita anterior y su siguiente


			switch (Numtratamiento) //switch para evaluar qué tratamiento eligió y dar una descripción y precio sobre este
			{
			case 1:
			{
				cout << "\nDescripcion: La limpieza dental consiste en un tratamiento con anestesia local que duerme la encia y permite limpiar las bolsas periodontales, un espacio entre la encia y el diente en donde se acumulan el sarro y las bacterias causantes de la periodontitis";
				nueva_cita->tratamiento = "\nLimpieza dental: La limpieza dental consiste en un tratamiento con anestesia local que duerme la encia y permite limpiar las bolsas periodontales, un espacio entre la encia y el diente en donde se acumulan el sarro y las bacterias causantes de la periodontitis";
				cout << "\n Precio unitario: " << Plimpieza;
				nueva_cita->preciounitario = Plimpieza;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> nueva_cita->Ctratamientos;
				nueva_cita->precio = (nueva_cita->Ctratamientos * Plimpieza);
				cout << "\ El costo total es de " << nueva_cita->precio << " pesos";
				cout << "\n El paciente " << nueva_cita->nombre << " tiene una cita programada a las " << nueva_cita->Hora << " horas" << endl;
				i++;
				system("pause");
				break;
			}
			case 2:
			{
				cout << "\n Descripcion: Es el procedimiento que consiste en aceptar a un paciente, reconocer que tiene un problema y descubrir la causa de este, e idear un plan de tratamiento que resolverá y aliviara tal problema.";
				nueva_cita->tratamiento = "\nDiagnostico: Es el procedimiento que consiste en aceptar a un paciente, reconocer que tiene un problema y descubrir la causa de este, e idear un plan de tratamiento que resolverá y aliviara tal problema. ";
				cout << "\n Precio unitario: " << PDiagnostico;
				nueva_cita->preciounitario = PDiagnostico;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> nueva_cita->Ctratamientos;
				nueva_cita->precio = (nueva_cita->Ctratamientos * PDiagnostico);
				cout << "\ El costo total es de " << nueva_cita->precio << " pesos";
				cout << "\n El paciente " << nueva_cita->nombre << " tiene una cita programada a las " << nueva_cita->Hora << " horas" << endl;
				i++;
				system("pause");
				break;
			}
			case 3:
			{
				cout << "\n Descripcion: Los brackets y la ortodoncia se utilizan para corregir la mordedura deficiente u oclusion dental defectuosa cuando los dientes están amontonados o torcidos. En algunos casos, los dientes estan derechos, pero la mandibula superior y la inferior no encajan correctamente.";
				nueva_cita->tratamiento = "\nBrackets: Los brackets y la ortodoncia se utilizan para corregir la mordedura deficiente u oclusion dental defectuosa cuando los dientes están amontonados o torcidos. En algunos casos, los dientes estan derechos, pero la mandibula superior y la inferior no encajan correctamente. ";
				cout << "\n Precio unitario: " << PBrackets;
				nueva_cita->preciounitario = PBrackets;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> nueva_cita->Ctratamientos;
				nueva_cita->precio = (nueva_cita->Ctratamientos * PBrackets);
				cout << "\n El costo total es de " << nueva_cita->precio << " pesos";
				cout << "\n El paciente " << nueva_cita->nombre << " tiene una cita programada a las " << nueva_cita->Hora << " horas" << endl;
				i++;
				system("pause");
				break;
			}
			case 4:
			{
				cout << "\n Las sesiones de seguimiento o los ajustes frecuentes son necesarios para cambiar bandas elasticas desgastadas, comprobar como evoluciona la dentadura y efectuar correcciones en los alambres para asegurar que los dientes se muevan en la direccion correcta.";
				nueva_cita->tratamiento = "\nAjuste de Brackets: Las sesiones de seguimiento o los ajustes frecuentes son necesarios para cambiar bandas elasticas desgastadas, comprobar como evoluciona la dentadura y efectuar correcciones en los alambres para asegurar que los dientes se muevan en la direccion correcta. ";
				cout << "\n Precio unitariO: " << PAjuste;
				nueva_cita->preciounitario = PAjuste;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> nueva_cita->Ctratamientos;
				nueva_cita->precio = (nueva_cita->Ctratamientos * PAjuste);
				cout << "\n El costo total es de " << nueva_cita->precio << " pesos";
				cout << "\n El paciente " << nueva_cita->nombre << " tiene una cita programada a las " << nueva_cita->Hora << " horas" << endl;
				i++;
				system("pause");
				break;
			}
			case 5:
			{
				cout << "\n Descripcion: Es un procedimiento que reemplaza las raices de los dientes con pernos metalicos que parecen tornillos y reemplaza el diente faltante, o dañado, con un diente artificial que tiene el mismo aspecto y que cumple la misma funcion que los dientes reales.";
				nueva_cita->tratamiento = "\nImplante: Es un procedimiento que reemplaza las raices de los dientes con pernos metalicos que parecen tornillos y reemplaza el diente faltante, o dañado, con un diente artificial que tiene el mismo aspecto y que cumple la misma funcion que los dientes reales. ";
				cout << "\n Precio unitario: " << PImplante;
				nueva_cita->preciounitario = PImplante;
				cout << "\n Cuantos tratamientos desea adquirir? ";
				cin >> nueva_cita->Ctratamientos;
				nueva_cita->precio = (nueva_cita->Ctratamientos * PImplante);
				cout << "\n El costo total es de " << nueva_cita->precio << " pesos";
				cout << "\n El paciente " << nueva_cita->nombre << " tiene una cita programada a las " << nueva_cita->Hora << " horas" << endl;
				i++;
				system("pause");
				break;
			}

			default: //Por si el usuario elige una opción que no es adecuada

				cout << "Elija una opcion correcta" << endl;
				system("pause");
				break;
			}

			cita_actual++;
			if (cita_actual == 1) {
				primer_cita = nueva_cita;
				ultima_cita = nueva_cita;
			}
			else {
				nueva_cita->anterior = ultima_cita;
				ultima_cita->siguiente = nueva_cita;
				nueva_cita->num_cita = ultima_cita->num_cita + 1;
				ultima_cita = nueva_cita;
			}
			break;

		}
		case 2: //si el valor de menú es 2, se realizará lo siguiente
		{
			system("cls"); //Limpiar pantalla
			cout << "--------------" << endl;
			cout << "Modificar Cita" << endl;
			cout << "--------------" << endl;
			if (cita_actual == 0) {
				cout << "No se han registrado citas por el momento\n";
				system("pause");
				system("cls");
				break;
			}
			imprimir_cita();

			cout << "Que cita quiere modificar? " << endl;
			cin >> modificar_cita;

			cita_auxiliar = primer_cita;
			while (cita_auxiliar) {
				if (modificar_cita == cita_auxiliar->num_cita) {

					cout << "se modificara la siguiente cita: " << endl;
					cout << "Numero de cita: " << cita_auxiliar->num_cita << endl;
					cout << "\n-----------------\n";
					cout << "Nombre del paciente: " << cita_auxiliar->nombre << endl;
					cout << "\nTratamiento seleccionado: " << cita_auxiliar->tratamiento << endl;
					cout << "\nHora programada para la cita: " << cita_auxiliar->Hora << " horas" << endl;
					cout << "\nPrecio unitario: " << cita_auxiliar->preciounitario << endl;
					cout << "\nCantidad de tratamientos: " << cita_auxiliar->Ctratamientos << endl;
					cout << "\nTotal a pagar: " << cita_auxiliar->precio << endl;
					cout << "\n-----------------\n";

					system("pause");
					system("cls");

					cout << "\nTenemos la siguiente lista de tratamientos: " << endl;
					cout << "-------------------------------------------" << endl;
					cout << "1. Limpieza" << endl;
					cout << "2. Diagnostico" << endl;
					cout << "3. Brackets" << endl;
					cout << "4. Ajuste de Brackets" << endl;
					cout << "5. Implante" << endl;
					cout << "-------------------------------------------" << endl;
					cout << "Que tratamiento desea adquirir? ";
					cin >> Numtratamiento;
					switch (Numtratamiento)
					{
					case 1:
					{
						cout << "\nDescripcion: La limpieza dental consiste en un tratamiento con anestesia local que duerme la encia y permite limpiar las bolsas periodontales, un espacio entre la encia y el diente en donde se acumulan el sarro y las bacterias causantes de la periodontitis";
						cita_auxiliar->tratamiento = "\nLimpieza dental: La limpieza dental consiste en un tratamiento con anestesia local que duerme la encia y permite limpiar las bolsas periodontales, un espacio entre la encia y el diente en donde se acumulan el sarro y las bacterias causantes de la periodontitis";
						cout << "\n Precio unitario: " << Plimpieza;
						cita_auxiliar->preciounitario = Plimpieza;
						cout << "\n Cuantos tratamientos desea adquirir? ";
						cin >> cita_auxiliar->Ctratamientos;
						cita_auxiliar->precio = (cita_auxiliar->Ctratamientos * Plimpieza);
						cout << "\ El costo total es de " << cita_auxiliar->precio << " pesos" << endl;


						system("pause");
						break;
					}
					case 2:
					{
						cout << "\n Descripcion: Es el procedimiento que consiste en aceptar a un paciente, reconocer que tiene un problema y descubrir la causa de este, e idear un plan de tratamiento que resolverá y aliviara tal problema.";
						cita_auxiliar->tratamiento = "\nDiagnostico: Es el procedimiento que consiste en aceptar a un paciente, reconocer que tiene un problema y descubrir la causa de este, e idear un plan de tratamiento que resolverá y aliviara tal problema. ";
						cout << "\n Precio unitario: " << PDiagnostico;
						cita_auxiliar->preciounitario = PDiagnostico;
						cout << "\n Cuantos tratamientos desea adquirir? ";
						cin >> cita_auxiliar->Ctratamientos;
						cita_auxiliar->precio = (cita_auxiliar->Ctratamientos * PDiagnostico);
						cout << "\ El costo total es de " << cita_auxiliar->precio << " pesos" << endl;


						system("pause");
						break;
					}
					case 3:
					{
						cout << "\n Descripcion: Los brackets y la ortodoncia se utilizan para corregir la mordedura deficiente u oclusion dental defectuosa cuando los dientes están amontonados o torcidos. En algunos casos, los dientes estan derechos, pero la mandibula superior y la inferior no encajan correctamente.";
						cita_auxiliar->tratamiento = "\nBrackets: Los brackets y la ortodoncia se utilizan para corregir la mordedura deficiente u oclusion dental defectuosa cuando los dientes están amontonados o torcidos. En algunos casos, los dientes estan derechos, pero la mandibula superior y la inferior no encajan correctamente. ";
						cout << "\n Precio unitario: " << PBrackets;
						cita_auxiliar->preciounitario = PBrackets;
						cout << "\n Cuantos tratamientos desea adquirir? ";
						cin >> cita_auxiliar->Ctratamientos;
						cita_auxiliar->precio = (cita_auxiliar->Ctratamientos * PBrackets);
						cout << "\n El costo total es de " << cita_auxiliar->precio << " pesos" << endl;


						system("pause");
						break;
					}
					case 4:
					{
						cout << "\n Las sesiones de seguimiento o los ajustes frecuentes son necesarios para cambiar bandas elasticas desgastadas, comprobar como evoluciona la dentadura y efectuar correcciones en los alambres para asegurar que los dientes se muevan en la direccion correcta.";
						cita_auxiliar->tratamiento = "\nAjuste de Brackets: Las sesiones de seguimiento o los ajustes frecuentes son necesarios para cambiar bandas elasticas desgastadas, comprobar como evoluciona la dentadura y efectuar correcciones en los alambres para asegurar que los dientes se muevan en la direccion correcta. ";
						cout << "\n Precio unitariO: " << PAjuste;
						cita_auxiliar->preciounitario = PAjuste;
						cout << "\n Cuantos tratamientos desea adquirir? ";
						cin >> cita_auxiliar->Ctratamientos;
						cita_auxiliar->precio = (cita_auxiliar->Ctratamientos * PAjuste);
						cout << "\n El costo total es de " << cita_auxiliar->precio << " pesos" << endl;


						system("pause");
						break;
					}
					case 5:
					{
						cout << "\n Descripcion: Es un procedimiento que reemplaza las raices de los dientes con pernos metalicos que parecen tornillos y reemplaza el diente faltante, o dañado, con un diente artificial que tiene el mismo aspecto y que cumple la misma funcion que los dientes reales.";
						cita_auxiliar->tratamiento = "\nImplante: Es un procedimiento que reemplaza las raices de los dientes con pernos metalicos que parecen tornillos y reemplaza el diente faltante, o dañado, con un diente artificial que tiene el mismo aspecto y que cumple la misma funcion que los dientes reales. ";
						cout << "\n Precio unitario: " << PImplante;
						cita_auxiliar->preciounitario = PImplante;
						cout << "\n Cuantos tratamientos desea adquirir? ";
						cin >> cita_auxiliar->Ctratamientos;
						cita_auxiliar->precio = (cita_auxiliar->Ctratamientos * PImplante);
						cout << "\n El costo total es de " << cita_auxiliar->precio << " pesos" << endl;


						system("pause");
						break;
					}

					default: //Por si el usuario elige una opción que no es adecuada

						cout << "Elija una opcion correcta" << endl;
						system("pause");
						break;
					}
					cout << "\n Modificacion del nombre " << endl;
					cin.ignore();
					getline(cin, cita_auxiliar->nombre);

					if (cita_auxiliar->anterior) {
						cita_auxiliar->anterior->siguiente->nombre = cita_auxiliar->nombre;
					}

					cout << "\tModificacion de la hora: " << endl;;
					cin >> cita_auxiliar->Hora;

					system("cls");
					cout << "La cita ha sido modificada\n";
					cout << "\nEl paciente " << cita_auxiliar->nombre << " tiene una cita programada a las " << cita_auxiliar->Hora << " horas" << endl;
					system("pause");
					system("cls");

				}
				cita_auxiliar = cita_auxiliar->siguiente;

			}
			system("cls");
			break;
		case 3: //si el valor de menú es 3, se realizará lo siguiente
		{
			system("cls"); //Limpiar pantalla
			cout << "--------------" << endl;
			cout << "Eliminar Cita" << endl;
			cout << "--------------" << endl;
			system("pause");
			imprimir_cita();
			if (cita_actual == 0) {
				cout << "No se han registrado citas por el momento.\n";
				system("pause");
				system("cls");
				break;
			}
			cout << "Ingrese el numero de cita que desea eliminar:\n";
			cin >> modificar_cita;
			cita_auxiliar = primer_cita;

			do {

				if (modificar_cita == cita_auxiliar->num_cita) {

					cout << "Esta cita esta a punto de ser eliminada " << endl;
					cout << "Numero de cita: " << cita_auxiliar->num_cita << endl;
					cout << "\n-----------------\n";
					cout << "Nombre del paciente: " << cita_auxiliar->nombre << endl;
					cout << "\nTratamiento seleccionado: " << cita_auxiliar->tratamiento << endl;
					cout << "\nHora programada para la cita: " << cita_auxiliar->Hora << " horas" << endl;
					cout << "\nPrecio unitario: " << cita_auxiliar->preciounitario << endl;
					cout << "\nCantidad de tratamientos: " << cita_auxiliar->Ctratamientos << endl;
					cout << "\nTotal a pagar: " << cita_auxiliar->precio << endl;
					cout << "\n-----------------\n";
					system("cls");
					// primer cita
					if (cita_auxiliar->num_cita == 1) {

						primer_cita = primer_cita->siguiente;
						cita_auxiliar = nullptr;
					}
					else {

						if (cita_auxiliar->anterior) {

							if (cita_auxiliar->siguiente) {
								cita_auxiliar->anterior->siguiente = cita_auxiliar->siguiente;
								cita_auxiliar->siguiente->anterior = cita_auxiliar->anterior;

							}
							else { // ultima cita

								ultima_cita = cita_auxiliar->anterior;
								cita_auxiliar->anterior->siguiente = nullptr;
							}
						}
					}
					cita_auxiliar = nullptr;
					cout << "La cita #" << modificar_cita << " se ha ELIMINADO con exito\n";
					system("pause");
					cita_actual--;

				}
				else {
					cita_auxiliar = cita_auxiliar->siguiente;
				}

			} while (cita_auxiliar != nullptr);

			system("cls");
			break;
		}
		case 4: //si el valor de menú es 4, se realizará lo siguiente
		{
			system("cls");

			if (cita_actual == 0) {

				cout << "\nNo se han registrado citas aun." << endl;
				system("pause");
			}
			else {
				
				cout << "\nLista de citas dentales\n";
				cout << "-------------------------\n";
				cout << "Las citas agendadas son:\n";
				cout << "-------------------------\n";
				imprimir_cita();
			}
			system("cls");
			break;
		}

		case 5:
		{
			system("cls"); //Limpiar pantalla
			cout << "-----------------" << endl;
			cout << "Limpiar pantalla" << endl;
			cout << "-----------------" << endl;

			system("pause");
			break;
		}
		case 6:
		{
			registrar_txt();
			system("pause");
			system("cls");
			cout << "\nHasta pronto:)" << endl;
			return(0);
			break;

		}

		default: //por si el usuario introduce un valor incorrecto o no válido

			cout << "Elija una opcion correcta" << endl;
			system("pause");
			break;
		}
		}

	};
}


void registrar_txt() {

	ofstream archivo("Cita_Dental.txt");

	if (archivo) {

		cita_auxiliar = primer_cita;

		while (cita_auxiliar) {
			archivo << cita_auxiliar->nombre << endl;
			archivo << cita_auxiliar->tratamiento << endl;
			archivo << cita_auxiliar->Ctratamientos << endl;
			archivo << cita_auxiliar->preciounitario << endl;
			archivo << cita_auxiliar->precio << endl;
			archivo << cita_auxiliar->Hora << endl;
			cita_auxiliar = cita_auxiliar->siguiente;
		}
		cout << "Las citas fueron guardadas " << endl;
		archivo.close();
	}
	else {
		cout << "Error al abrir el archivo";
	}

}


int leer_txt() {

	ifstream archivo("Cita_Dental.txt");
	if (archivo) {
		string linea;
		string descripcion_trat;


		cita_auxiliar = new cita;

		while (getline(archivo, linea)) {
			cita_auxiliar->nombre = linea;
			getline(archivo, linea);
			cita_auxiliar->tratamiento = linea;
			getline(archivo, descripcion_trat);
			cita_auxiliar->tratamiento = cita_auxiliar->tratamiento + "\n" + descripcion_trat;
			getline(archivo, linea);
			cita_auxiliar->Ctratamientos = stoi(linea);
			getline(archivo, linea);
			cita_auxiliar->preciounitario = stoi(linea);
			getline(archivo, linea);
			cita_auxiliar->precio = stoi(linea);
			getline(archivo, linea);
			cita_auxiliar->Hora = linea;

			cita_actual++;//asignar siguientes y anteriores
			if (cita_actual == 1) {
				cita_auxiliar->num_cita = 1;
				primer_cita = cita_auxiliar;
				ultima_cita = cita_auxiliar;
			}
			else {
				cita_auxiliar->anterior = ultima_cita;
				ultima_cita->siguiente = cita_auxiliar;
				cita_auxiliar->num_cita = ultima_cita->num_cita + 1;
				ultima_cita = cita_auxiliar;
			}
			cita_auxiliar = new cita;
		}
		cita_auxiliar = nullptr;

		return(cita_actual);
	}
	return(0);
}
