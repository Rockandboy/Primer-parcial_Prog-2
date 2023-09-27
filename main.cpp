#include <iostream>
#include <locale.h>
#include "Funciones.h"

using namespace std;
/*1. Informar para un número de tarjeta que se ingresa por teclado la
cantidad de viajes realizados en cada uno de los medios de transporte.

2. El viaje con menor importe. Mostrar todo el registro.

3. El mes de mayor recaudación por viajes en subte entre todos los viajes.

4. Informar para CADA número de tarjeta la cantidad de viajes realizados
en colectivos el mes de mayo.

5. El numero viaje con mayor importe. Mostrar el número de tarjeta y el DNI
del dueño. Debe mostrar los tres datos solicitados.

6. Informar para cada una de las tarjetas activas el importe total gastado
por TODOS viajes realizados.

*/
int main()
{
    setlocale(LC_ALL, "");
    bool salir = false;
    char opc;
    while (salir==false)
    {
        menu();

        cout << "\nINGRESE UNA OPCION" << endl;
        cin >> opc;
        cin.ignore();
        system("cls");
        switch (opc)
        {
        case '1':
        {
            buscarViaje();
            break;
        }
        case '2':
        {
            buscarMenorImporteViaje();
            break;
        }
        case '3':
            {
                mayorRecaudacionSubteMes();
                break;
            }
        case '0':
        {
            salir = true;
            break;
        }
        default:
            cout << "Error: Opcion invalida\n" << endl;
            break;
        }
    }
}
