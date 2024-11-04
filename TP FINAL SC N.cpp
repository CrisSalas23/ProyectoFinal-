#include <iostream> // Para operaciones de entrada y salida, como cout y cin
#include <string> // Para manejar cadenas de texto
#include <cstdlib> // Para la funcion rand() y exit()
#include <ctime> // Para la funcion time() (semilla para rand())
#include <windows.h> // Para cambiar colores en la consola (solo en Windows)
#include <fstream> // Para manejar archivos (leer y escribir)
#include "membrete.h" // Archivo de cabecera personalizado

using namespace std; // Usar el espacio de nombres estandar para evitar prefijos

// Funcion para cambiar el color del texto en la consola
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// Funcion para crear un archivo
void crearArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str()); 
    if (archivo.is_open()) {
        cout << "Archivo creado exitosamente: " << nombreArchivo << endl; // Mensaje de �xito
        archivo.close(); // Cierra el archivo
    } else {
        cout << "Error al crear el archivo." << endl; // Mensaje de error
    }
}

// Funcion para leer un archivo existente
void leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str()); 
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) { // Lee l�nea por l�nea
            cout << linea << endl; // Muestra cada l�nea en consola
        }
        archivo.close(); // Cierra el archivo
    } else {
        cout << "No se puede abrir el archivo para lectura." << endl; // Mensaje de error
    }
}

// Funcion para escribir en un archivo
void escribirDatos(const string& nombreArchivo, const string& datos) {
    ofstream archivo(nombreArchivo.c_str(), ios::app); // Abre el archivo en modo append
    if (archivo.is_open()) {
        archivo << datos << endl; // Escribe los datos
        archivo.close(); // Cierra el archivo
        cout << "Datos escritos exitosamente en " << nombreArchivo << endl; // Mensaje de �xito
    } else {
        cout << "No se puede abrir el archivo para escribir." << endl; // Mensaje de error
    }
}

// Funcion para copiar un archivo
void copiarArchivo(const string& origen, const string& destino) {
    ifstream archivoOrigen(origen.c_str(), ios::binary); 
    ofstream archivoDestino(destino.c_str(), ios::binary); 
    if (archivoOrigen.is_open() && archivoDestino.is_open()) {
        archivoDestino << archivoOrigen.rdbuf(); // Copia el contenido del archivo de origen al destino
        archivoOrigen.close(); // Cierra el archivo de origen
        archivoDestino.close(); // Cierra el archivo de destino
        cout << "Archivo copiado exitosamente de " << origen << " a " << destino << endl; // Mensaje de �xito
    } else {
        cout << "Error al abrir los archivos." << endl; // Mensaje de error
    }
}

// Funcion para mover un archivo
void moverArchivo(const string& origen, const string& destino) {
    copiarArchivo(origen, destino); // Copia el archivo de origen a destino
    remove(origen.c_str()); // Elimina el archivo de origen
}

// Funcion para guardar las comidas de la semana en un archivo
void guardarComidas(const string comidas[7]) {
    ofstream archivo("Texto.txt", ios::out); // Abre el archivo en modo escritura
    if (archivo.fail()) {
        cout << "No se puede abrir el archivo"; 
        exit(1); // Termina el programa si no se puede abrir
    }

    archivo << "Comidas de la semana:\n"; // Escribe encabezado
    string dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    for (int i = 0; i < 7; i++) {
        archivo << dias[i] << ": " << comidas[i] << endl; // Guarda cada comida del d�a
    }

    archivo.close(); // Cierra el archivo
}

// Funcion para mostrar las comidas en consola
void mostrarComidas(const string comidas[7]) {
    string dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    for (int i = 0; i < 7; i++) {
        cout << dias[i] << ": " << comidas[i] << endl; // Muestra cada comida en consola
    }
}

// Funcion para generar y mostrar comidas livianas
void mostrarComidasLivianas() {
    setColor(02, 00); // Cambia el color del texto
    string comidasLivianas[] = {
        "Ensaladas variadas", "Pescado al horno", "Pollo a la plancha", "Sandwich integral", 
        "Huevos revueltos", "Sopa de verduras", "Tacos de pescado"
    };

    string comidas[7]; // Array para las comidas de la semana
    for (int i = 0; i < 7; i++) {
        comidas[i] = comidasLivianas[rand() % (sizeof(comidasLivianas) / sizeof(string))]; // Elige aleatoriamente
    }

    mostrarComidas(comidas); // Muestra las comidas
    guardarComidas(comidas); // Guarda las comidas en el archivo
}

// Funcion para generar y mostrar comidas normales
void mostrarComidasNormales() {
    setColor(03, 00); // Cambia el color del texto
    string comidasNormales[] = {
        "Pollo asado", "Noquis", "Guiso de arroz", "Filete de pollo", 
        "Milanesa", "Pizza", "Empanadas"
    };

    string comidas[7]; // Array para las comidas de la semana
    for (int i = 0; i < 7; i++) {
        comidas[i] = comidasNormales[rand() % (sizeof(comidasNormales) / sizeof(string))]; // Elige aleatoriamente
    }

    mostrarComidas(comidas); // Muestra las comidas
    guardarComidas(comidas); // Guarda las comidas en el archivo
}

// Funcion para mostrar opciones de comida para el domingo
void mostrarOpcionesDomingo() {
    setColor(04, 0); // Cambia el color del texto
    cout << "\nOpciones de comida para un Domingo" << endl;
    cout << "1. Asado" << endl;
    cout << "2. Tacos de pollo" << endl;
    cout << "3. Tacos de carne" << endl;
    cout << "4. Pizza" << endl;
    cout << "5. Locro" << endl;
    cout << "6. Humita" << endl;
    cout << "7. Tamales" << endl;
    cout << "8. Choripan" << endl;
}

// Funcion principal
int main() {
    int opcion; // Variable para la opci�n del men�
    srand(static_cast<unsigned>(time(0))); // Inicializa la semilla para rand()

    do {
    	comidas();
        setColor(02, 00); // Cambia el color del texto
        cout << "\nCOMIDAS PARA ESTA SEMANA" << endl;
        setColor(07, 45); 
        cout << "\n*Elija una opcion*" << endl; // Mensaje de opciones
        setColor(01, 0); // Cambia el color del texto
        cout << "\nLiviano -----> presione 1" << endl; // Opci�n 1
        cout << "Normal ----- presione 2" << endl; // Opci�n 2
        cout << "Opciones para un domingo -----> presione 3" << endl; // Opci�n 3
        cout << "Limpiar pantalla -----> presione 4" << endl; // Opci�n 4
        cout << "Tratamientos de archivos -----> presione 5" << endl; // Opci�n 5
        cout << "Salir -----> presione 6" << endl; // Opci�n 6
        cout << "\033[0m"; // Resetea el color
        cin >> opcion; // Lee la opci�n del usuario

        switch (opcion) {
            case 1: { // Opci�n de comidas livianas
                int subOpcion;
                do {
                    setColor(06, 00); // Cambia el color del texto
                    cout << "\nSubmenu: Opciones de Comidas Livianas" << endl;
                    cout << "1. Ver comidas livianas" << endl; // Opci�n para ver comidas livianas
                    cout << "2. Volver al menu principal" << endl; // Opci�n para volver al men� principal
                    cout << "Seleccione una opcion: ";
                    cin >> subOpcion;

                    if (subOpcion == 1) {
                        mostrarComidasLivianas(); // Muestra las comidas livianas
                    } else if (subOpcion != 2) {
                        setColor(04, 0); // Cambia el color del texto
                        cout << "Opcion no valida. Intente de nuevo." << endl; // Mensaje de error
                    }
                } while (subOpcion != 2); // Vuelve hasta que elija salir
                break;
            }
            case 2: { // Opci�n de comidas normales
                int subOpcion;
                do {
                    setColor(06, 00); // Cambia el color del texto
                    cout << "\nSubmenu: Opciones de Comidas Normales" << endl;
                    cout << "1. Ver comidas normales" << endl; // Opci�n para ver comidas normales
                    cout << "2. Volver al menu principal" << endl; // Opci�n para volver al men� principal
                    cout << "Seleccione una opcion: ";
                    cin >> subOpcion;

                    if (subOpcion == 1) {
                        mostrarComidasNormales(); // Muestra las comidas normales
                    } else if (subOpcion != 2) {
                        setColor(04, 0); // Cambia el color del texto
                        cout << "Opcion no valida. Intente de nuevo." << endl; // Mensaje de error
                    }
                } while (subOpcion != 2); // Vuelve hasta que elija salir
                break;
            }
            case 3: { // Opci�n de comidas para domingo
                mostrarOpcionesDomingo(); // Muestra las opciones de domingo
                break;
            }
            case 4: { // Opci�n para limpiar pantalla
                system("cls"); // Limpia la consola
                break;
            }
            case 5: { // Opci�n para tratamientos de archivos
                int subOpcion;
                do {
                    setColor(06, 00); // Cambia el color del texto
                    cout << "\nSubmenu: Tratamientos de Archivos" << endl;
                    cout << "1. Crear archivo" << endl; // Opci�n para crear archivo
                    cout << "2. Leer archivo" << endl; // Opci�n para leer archivo
                    cout << "3. Escribir en archivo" << endl; // Opci�n para escribir en archivo
                    cout << "4. Copiar archivo" << endl; // Opci�n para copiar archivo
                    cout << "5. Mover archivo" << endl; // Opci�n para mover archivo
                    cout << "6. Volver al menu principal" << endl; // Opci�n para volver al men� principal
                    cout << "Seleccione una opcion: ";
                    cin >> subOpcion;

                    string nombreArchivo, destino, datos;
                    switch (subOpcion) {
                        case 1:
                            cout << "Ingrese el nombre del archivo: ";
                            cin >> nombreArchivo;
                            crearArchivo(nombreArchivo); // Llama a la funci�n para crear archivo
                            break;
                        case 2:
                            cout << "Ingrese el nombre del archivo: ";
                            cin >> nombreArchivo;
                            leerArchivo(nombreArchivo); // Llama a la funci�n para leer archivo
                            break;
                        case 3:
                            cout << "Ingrese el nombre del archivo: ";
                            cin >> nombreArchivo;
                            cout << "Ingrese los datos a escribir: ";
                            cin.ignore(); // Limpia el buffer de entrada
                            getline(cin, datos); // Lee la l�nea completa
                            escribirDatos(nombreArchivo, datos); // Llama a la funci�n para escribir datos
                            break;
                        case 4:
                            cout << "Ingrese el nombre del archivo de origen: ";
                            cin >> nombreArchivo;
                            cout << "Ingrese el nombre del archivo de destino: ";
                            cin >> destino;
                            copiarArchivo(nombreArchivo, destino); // Llama a la funci�n para copiar archivo
                            break;
                        case 5:
                            cout << "Ingrese el nombre del archivo de origen: ";
                            cin >> nombreArchivo;
                            cout << "Ingrese el nombre del archivo de destino: ";
                            cin >> destino;
                            moverArchivo(nombreArchivo, destino); // Llama a la funci�n para mover archivo
                            break;
                        case 6:
                            break; // Volver al menu principal
                        default:
                            cout << "Opcion no valida." << endl; // Mensaje de error para opci�n no v�lida
                    }
                } while (subOpcion != 6); // Repite hasta que elija volver
                break;
            }
            case 6: // Opci�n para salir
                cout << "Saliendo del programa." << endl; // Mensaje de despedida
                break;
            default: // Opci�n no v�lida
                cout << "Opcion no valida." << endl; // Mensaje de error
        }
    } while (opcion != 6); // Repite hasta que el usuario elija salir

    return 0; // Fin del programa
}

