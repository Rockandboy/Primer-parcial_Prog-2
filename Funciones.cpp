#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Viajes.h"
#include "Tarjetas.h"
#include "Funciones.h"


using namespace std;

const char *ARCHIVO_VIAJES = "Viajes.dat";
const char *ARCHIVO_TARJETAS = "Tarjetas.dat";

void menu()
{
    cout << "1- Buscar Viajes asciados a una tarjeta" << endl;
    cout << "2- Buscar el viaje con menor importe en el año" << endl;
    cout << "3-" << endl;
    cout << "4-" << endl;
    cout << "5-" << endl;
    cout << "6-" << endl;
    cout << "0- Salir del programa" << endl;
}

///1) -----------------------------------------------------
void buscarViaje()
{
    FILE* archivo;
    Viajes buscar;
    char tarjeta[6];
    bool salir = false;
    while(salir==false)
    {
        cout << "INGRESE EL NUMERO DE TARJETA" << endl;
        cin.getline(tarjeta,6);
        if (existeTarjeta(tarjeta)==true)
        {
            system("cls");
            archivo = fopen(ARCHIVO_VIAJES,"rb");
            if(archivo==NULL)
            {
                cout << "ERROR: Archivo No Existente" << endl;
            }
            else
            {
                while(fread(&buscar,sizeof(Viajes),1,archivo)==1)
                {
                    if(strcmp(buscar.numeroTarjeta,tarjeta)==0)
                    {
                        switch (buscar.medioTransporte)
                        {
                        case 1:
                        {
                            cout << "\t----------- Viaje realizado en Colectivo -----------" << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "\t----------- Viaje realizado en subte -----------" << endl;
                            break;
                        }
                        case 3:
                        {
                            cout << "\t----------- Viaje realizado en tren -----------" << endl;
                            break;
                        }
                        mostrarViaje(buscar);
                        }
                    }
                }
                fclose(archivo);
            }
        }
        else
        {
            cout << "ERROR: Numero de tarjeta inexistente" << endl;
        }
        salir = salirFuncion();
        system("cls");
    }
}
///2) -----------------------------------------------------
void buscarMenorImporteViaje()
{
    system("cls");
    //const int tam = contarRegistrosViajes();
    FILE* archivo;
    Viajes buscar;
    bool bandera = false;
    float menorImporte;
    char menorViaje[5];
    ///abro el archivo
    archivo = fopen(ARCHIVO_VIAJES,"rb");
    ///Compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        while(fread(&buscar,sizeof(Viajes),1,archivo)==1)
        {
            if (bandera == false)
            {
                bandera = true;
                menorImporte = buscar.importeViaje;
                strcpy(menorViaje,buscar.numeroViaje);
            }
            else if (menorImporte > buscar.importeViaje)
            {
                menorImporte = buscar.importeViaje;
                strcpy(menorViaje,buscar.numeroViaje);
            }
        }
        buscar = obtenerRegViaje(menorViaje);
        mostrarViaje(buscar);
        }
    system("pause");
    system("cls");
}
/// REVISAR PUNTO 3)
void mayorRecaudacionSubteMes()
{
    bool bandera = false;
    FILE* archivo;
    Viajes buscar;
    float mayorRecaudacion[12],mayorMes=0,mayorRecaudacionMes=0;
    ///inicializo el vector en cero
    for (int i=0; i<12; i++)
    {
        mayorRecaudacion[i]=0;
    }
    ///abro el archivo
    archivo = fopen(ARCHIVO_VIAJES,"rb");
    ///compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        while(fread(&buscar,sizeof(Viajes),1,archivo)==1)
        {
            for (int mes=1; mes<=12; mes++)
            {
                if ((buscar.mesViaje == mes) && (buscar.medioTransporte == 2))
                {
                    mayorRecaudacion[mes-1] =+ buscar.importeViaje;
                }

            }
        }
        fclose(archivo);
        for (int mes=1; mes<=12; mes++)
        {
            if (mayorRecaudacionMes<mayorRecaudacion[mes-1])
            {
                mayorMes = mes;
                mayorRecaudacionMes = mayorRecaudacion[mes-1];
            }
        }
        cout << "La mayor recaudacion en servicios de subte fue en el mes: " << mayorMes << ", Con un total de: $" << mayorRecaudacionMes << endl;
    }
    system("pause");
    system("cls");
}

/// Funcion complementaria
bool existeTarjeta (char *tarjeta)
{
    FILE* archivo;
    Tarjetas existe;
    ///abro el archivo
    archivo = fopen(ARCHIVO_TARJETAS,"rb");
    ///compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        while(fread(&existe,sizeof(Tarjetas),1,archivo)==1)
        {
            if (strcmp(tarjeta,existe.numeroTarjeta)==0)
            {
                fclose(archivo);
                return true;
            }
        }
    }
    fclose(archivo);
    return false;
}


/// Funcion complementaria
/*
int contarRegistrosViajes()
{
    FILE* archivo;
    int tam=0;
    Viajes contar;
    ///abrir
    archivo = fopen(ARCHIVO_VIAJES,"rb");
    ///compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        ///leo
        while(fread(&contar,sizeof(Viajes),1,archivo)==1)
        {
            tam++;
        }
        ///cierro el archivo
        fclose(archivo);
        return tam;
    }
}
*/

/// Funcion complementaria
bool salirFuncion()
{
    int opc;
    cout << endl;
    cout << "1- Continuar en la funcion" << endl;
    cout << "0- Volver al menu principal" << endl;
    cin >> opc;
    cin.ignore();
    switch (opc)
    {
    case 1:
        return false;
        break;
    case 0:
        return true;
        break;
    }
}
/// Funcion complementaria
struct Viajes obtenerRegViaje(char *viaje)
{
    FILE* archivo;
    Viajes retorno;
    ///abro el archivo
    archivo = fopen(ARCHIVO_VIAJES,"rb");
    ///Verifico
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        while(fread(&retorno,sizeof(Viajes),1,archivo)==1)
        {
            if(strcmp(viaje,retorno.numeroViaje)==0)
            {
                fclose(archivo);
                return retorno;
            }
        }
    }

}

/*
if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
*/
