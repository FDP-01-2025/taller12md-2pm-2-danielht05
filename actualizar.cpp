#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante
{
    string nombre;
    string carnet;
    int edad;
};

// Función para agregar estudiante (CREATE)
void agregarEstudiante()
{
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open())
    {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    }
    else
    {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes()
{
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open())
    {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad)
        {
            cout << "Nombre: " << e.nombre
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo.\n";
    }
}

// -----------------------------
// 👇 TU TAREA: Completa esta función (UPDATE)
void modificarEstudiante()
{
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;

    cout << "Ingrese carnet a actualizar: ";
    cin >> buscado;
    cin.ignore();

    if (archivo.is_open() && temp.is_open())
    {
        while (archivo >> e.nombre >> e.carnet >> e.edad)
        {
            if (e.carnet == buscado)
            {
                // Se ingresan los nuevos datos del estudiante
                cout << "Digite los nuevos datos del estudiante \n";
                Estudiante e;
                cout << "Nombre (sin espacios): ";
                cin >> e.nombre;
                cout << "Carnet: ";
                cin >> e.carnet;
                cout << "Edad: ";
                cin >> e.edad;
                ofstream archivo("estudiantes.txt", ios::app);
                if (archivo.is_open())
                {
                    archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
                    archivo.close();
                    cout << "Estudiante actualizado correctamente.\n";
                }
                else
                {
                    cout << "Error al abrir el archivo.\n";
                }
            }
            else
            {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        // Remueve el estudiante y agrega los nuevos datos ingresados
        remove("Estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");
    }
    // Debes permitir actualizar nombre, carnet y/o edad
    // de un estudiante identificado por su carnet.
    // Puedes usar o no manejo de archivos.
    // Si lo implementas con archivos correctamente, obtendrás **2 puntos extra**.
}
// -----------------------------

// Función para eliminar estudiante (DELETE)
void eliminarEstudiante()
{
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool eliminado = false;

    cout << "Ingrese carnet a eliminar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open())
    {
        while (archivo >> e.nombre >> e.carnet >> e.edad)
        {
            if (e.carnet == buscado)
            {
                eliminado = true; // No se copia: se “borra”
            }
            else
            {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("Estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado)
            cout << "Estudiante eliminado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    }
    else
    {
        cout << "Error abriendo los archivos.\n";
    }
}

// Menú principal
int main()
{
    int opcion;
    do
    {
        cout << "\n=== CRUD de Estudiantes ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarEstudiante();
            break;
        case 2:
            mostrarEstudiantes();
            break;
        case 3:
            modificarEstudiante();
            break; // 👉 Completa aquí
        case 4:
            eliminarEstudiante();
            break;
        case 5:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}