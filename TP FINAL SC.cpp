#include <iostream> // Para operaciones de entrada y salida, como cout y cin
#include <string> // Para manejar cadenas de texto
#include <cstdlib> // Para la función rand() y exit()
#include <ctime> // Para la función time() (semilla para rand())
#include <windows.h> // Para cambiar colores en la consola (solo en Windows)
#include <fstream> // Para manejar archivos (leer y escribir)
#include "membrete.h" // Archivo de cabecera personalizado

using namespace std; // Usar el espacio de nombres estándar para evitar prefijos

// Función para cambiar el color del texto en la consola
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// Función para guardar las comidas de la semana en un archivo
void guardarComidas(const string comidas[7]) {
    ofstream archivo; // Objeto para manejar archivos de salida
    archivo.open("Texto.txt", ios::out); // Abre el archivo en modo escritura
    if (archivo.fail()) {
        cout << "No se puede abrir el archivo"; // Mensaje de error si falla
        exit(1); // Termina el programa
    }

    archivo << "Comidas de la semana:\n"; // Escribe el encabezado
    string dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    for (int i = 0; i < 7; i++) {
        archivo << dias[i] << ": " << comidas[i] << endl; // Guarda cada comida del día
    }

    archivo.close(); // Cierra el archivo
}

// Función para mostrar las comidas en consola
void mostrarComidas(const string comidas[7]) {
    string dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    for (int i = 0; i < 7; i++) {
        cout << dias[i] << ": " << comidas[i] << endl; // Muestra cada comida
    }
}

// Función para generar y mostrar comidas livianas
void mostrarComidasLivianas() {
	setColor(02, 00); // Cambia el color del texto
    string comidasLivianas[] = {
        "Ensaladas variadas",
        "Pescado al horno o a la parrilla",
        "Pollo a la plancha con verduras",
        "Sandwich integral de verdura",
        "Huevos revueltos con vegetales",
        "Sopa de verduras",
        "Tacos de pescado o camarones",
        "Pimientos rellenos",
        "Ensalada de garbanzos",
        "Tortitas de avena y platano",
        "Pavo al horno con batatas",
        "Tortilla de zapallito",
    };

    string comidas[7]; // Array para las comidas de la semana
    for (int i = 0; i < 7; i++) {
        comidas[i] = comidasLivianas[rand() % (sizeof(comidasLivianas) / sizeof(string))]; // Elige aleatoriamente
    }

    mostrarComidas(comidas); // Muestra las comidas
    guardarComidas(comidas); // Guarda las comidas en el archivo
}

// Función para generar y mostrar comidas normales
void mostrarComidasNormales() {
	setColor(03, 00); // Cambia el color del texto
    string comidasNormales[] = {
        "Pollo asado",
        "Noquis",
        "Guiso de arroz con pollo",
        "Guiso de fideos monito",
        "Filete de pollo con arroz",
        "Filete de pollo con ensalada de tomate",
        "Filete de pollo con fideos",
        "Medallon con fideos",
        "Milanesa de soja con ensalada de tomate y cebolla",
        "Hamburguesa",
        "Pizza",
        "Empanadas",
        "Puchero de pollo",
        "Puchero de carne",
        "Milanesa con pure",
        "Milanesa con arroz",
        "Milanesa con fideos",
        "Suprema de pollo con arroz",
        "Suprema de pollo con fideos",
        "Suprema de pollo con ensalada",
        "Filete con papas fritas",
        "Lasana con arroz",
        "Polenta con salsa",
        "Fideos con salsa",
        "Pizzeta",
        "Milanesa napolitana"
    };
    //Se minimiza las opciones para poder tomar la captura
    string comidas[7]; // Array para las comidas de la semana
    for (int i = 0; i < 7; i++) {
        comidas[i] = comidasNormales[rand() % (sizeof(comidasNormales) / sizeof(string))]; // Elige aleatoriamente
    }

    mostrarComidas(comidas); // Muestra las comidas
    guardarComidas(comidas); // Guarda las comidas en el archivo
}

// Función para mostrar opciones de comida para el domingo
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

int main() {
    int opcion;
    srand(time(0)); // Inicializa la semilla para rand()

    do {
    	comidas();
        setColor(02, 00); // Cambia el color del texto
        cout << "\nCOMIDAS PARA ESTA SEMANA" << endl;
        setColor(07, 45); // Cambia el color del texto
        cout << "\n*Elija una opcion*" << endl;
        setColor(01, 0); // Cambia el color del texto
        cout << "\nLiviano -----> presione 1" << endl;
        cout << "Normal ----- presione 2" << endl;
        cout << "Opciones para un domingo -----> presione 3" << endl;
        cout << "Limpiar pantalla -----> presione 4" << endl;
        cout << "Salir -----> presione 5" << endl;
        cout << "\033[0m"; // Resetea el color
        cin >> opcion; // Lee la opción del usuario

        switch (opcion) {
            case 1: { // Opción de comidas livianas
                int subOpcion;
                do {
                    setColor(06, 00); // Cambia el color del texto
                    cout << "\nSubmenu: Opciones de Comidas Livianas" << endl;
                    cout << "1. Ver comidas livianas" << endl;
                    cout << "2. Volver al menu principal" << endl;
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
            case 2: { // Opción de comidas normales
                int subOpcion;
                do {
                    setColor(06, 00); // Cambia el color del texto
                    cout << "\nSubmenu: Opciones de Comidas Normales" << endl;
                    cout << "1. Ver comidas normales" << endl;
                    cout << "2. Volver al menu principal" << endl;
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
            case 3: { // Opción de comidas para domingo
                int subOpcion;
                do {
                    setColor(06, 00); // Cambia el color del texto
                    cout << "\nSubmenu: Opciones para Domingo" << endl;
                    cout << "1. Ver opciones para domingo" << endl;
                    cout << "2. Volver al menu principal" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subOpcion;

                    if (subOpcion == 1) {
                        mostrarOpcionesDomingo(); // Muestra las opciones de domingo
                    } else if (subOpcion != 2) {
                        setColor(04, 0); // Cambia el color del texto
                        cout << "Opcion no valida. Intente de nuevo." << endl; // Mensaje de error
                    }
                } while (subOpcion != 2); // Vuelve hasta que elija salir
                break;
            }
            case 4: { // Opción para limpiar pantalla
                system("cls"); // Limpia la consola
                break;
            }
            case 5: { // Opción para salir
                cout << "Presione Enter para finalizar" << endl; // Mensaje de despedida
                break;
            }
            default: { // Opción no válida
                setColor(04, 0); // Cambia el color del texto
                cout << "La opcion seleccionada no existe. Por favor, ingrese una opcion entre (1-5)." << endl; // Mensaje de error
                break;
            }
        }
    } while (opcion != 5); // Repite hasta que el usuario elija salir

    return 0; // Fin del programa
}

