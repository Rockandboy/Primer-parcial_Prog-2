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
    cout << "1- Buscar Viajes asciados a una tarjeta" << "\n" << endl;
    cout << "2- Buscar el viaje con menor importe en el a�o" << "\n" <<  endl;
    cout << "3- Buscar el mes con mayor recaudacion por viajes en subte" << "\n" <<  endl;
    cout << "4- Buscar la cantidad de viajes realizados en colectivos el mes de mayo" << "\n" <<  endl;
    cout << "5- Buscar El numero viaje con mayor importe" << "\n" <<  endl;
    cout << "6- Buscar el importe total gastado de las tarjetas activas" << "\n" <<  endl;
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
                        }
                        mostrarViaje(buscar);
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
//3) -----------------------------------------------------
void mayorRecaudacionSubteMes()
{
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
            if (buscar.medioTransporte == 2)
            {
                mayorRecaudacion[buscar.mesViaje-1] += buscar.importeViaje;
            }
        }
        for (int mes=1; mes<=12; mes++)
        {
            if (mayorRecaudacionMes<mayorRecaudacion[mes-1])
            {
                mayorMes = mes;
                mayorRecaudacionMes = mayorRecaudacion[mes-1];
            }
        }
        fclose(archivo);
        cout << "La mayor recaudacion en servicios de subte fue en el mes: " << mayorMes << ", Con un total de: $" << mayorRecaudacionMes << endl;
    }
    system("pause");
    system("cls");
}

//4) -----------------------------------------------------
void contarViajes_Colectivos_Mayo()
{
    FILE* archivo;
    Viajes buscar;
    int viajesTotales=0;
    ///abro el archivo
    archivo = fopen(ARCHIVO_VIAJES,"rb");
    ///compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        ///Leo
        while(fread(&buscar,sizeof(Viajes),1,archivo)==1)
        {
            if ((buscar.mesViaje == 4) && (buscar.medioTransporte == 1))
            {
                viajesTotales++;
                cout << "La tarjeta: " << buscar.numeroTarjeta << " realizo un viaje en el mes de mayo" << endl;
                cout << "Numero de viaje: " << buscar.numeroViaje << endl;
            }
        }
        if (viajesTotales==0)
        {
            cout << "No se realizaron viajes en colectivo en el mes de MAYO" << endl;
        }
        else
        {
            cout << "En el mes de MAYO se realizaron un total de: " << viajesTotales << " viajes en colectivo" <<  endl;
        }
    }
    system("pause");
    system("cls");
    fclose(archivo);
}
//5) -----------------------------------------------------
void mayorImporteViaje()
{
    FILE* archivo;
    Viajes buscar;
    Tarjetas retorno;
    float mayorViaje=0;
    char codigoTarjeta[6],codigoViaje[5];
    ///abro el archivo
    archivo = fopen(ARCHIVO_VIAJES,"rb");
    ///compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        /// leo el archivo
        while(fread(&buscar,sizeof(Viajes),1,archivo)==1)
        {
            ///busco el mayor
            if (mayorViaje < buscar.importeViaje)
            {
                ///reemplazo si cumple
                mayorViaje = buscar.importeViaje;
                strcpy(codigoTarjeta,buscar.numeroTarjeta);
                strcpy(codigoViaje,buscar.numeroViaje);
            }
        }
        ///verifico si existe tal codigo
        if (existeTarjeta(codigoTarjeta)==true)
        {
            ///busco el registro
            retorno = obtenerRegTarjeta(codigoTarjeta);
            ///lo saco por consola
            cout << "El numero de viaje: " << codigoViaje << endl;
            cout << "El Numero de tarjeta: " << retorno.numeroTarjeta << endl;
            cout << "DNI del due�o: " << retorno.dniDuenio << endl;
        }
    }
    system("pause");
    system("cls");
    fclose(archivo);
}

//6) -----------------------------------------------------
void mostrarGastosTarjetas()
{
    const int tam = contarRegistrosTarjetas();
    FILE *a_viajes,*a_tarjetas;
    Tarjetas v_tarjetas[tam];
    Viajes buscar;
    float gastosTarjeta=0;
    ///abro el archivo tarjetas
    a_tarjetas = fopen(ARCHIVO_TARJETAS,"rb");
    ///compruebo
    if(a_tarjetas==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        /// cargo el vector y verifico q haya cargado bien
        if (fread(v_tarjetas,sizeof(Tarjetas),tam,a_tarjetas)==tam)
        {
            /// aca mediante el for hago que pase las tarjetas guardadas 1 por 1
            /// y pasan por los siguientes procesos.
            for (int i=0; i<tam; i++)
            {
                /// verifico si la tarjeta esta en estado activo
                if (v_tarjetas[i].estado==1)
                {
                    ///abro el archivo viajes
                    a_viajes = fopen(ARCHIVO_VIAJES,"rb");
                    ///compruebo
                    if(a_viajes==NULL)
                    {
                        cout << "ERROR: Archivo No Existente" << endl;
                    }
                    else
                    {
                        /// busco los viajes que se realizaron con la tarjeta
                        /// (este ciclo no termina hasta que lea todo el archivo de viajes)
                        while(fread(&buscar,sizeof(Viajes),1,a_viajes)==1)
                        {
                            /// si detecta que el viaje se realizo con la tarjeta, acumulo el importe gastado en ese viaje
                            if (strcmp(v_tarjetas[i].numeroTarjeta,buscar.numeroTarjeta)==0)
                            {
                                gastosTarjeta += buscar.importeViaje;
                            }
                        }
                        fclose(a_viajes);
                    }
                    if (gastosTarjeta!=0)
                    {
                        cout << "La tarjeta Nro: " <<  v_tarjetas[i].numeroTarjeta << ", tubo un gasto total de: $" << gastosTarjeta << "\n" << endl;
                        gastosTarjeta=0;
                    }
                    else
                    {
                        cout << "La tarjeta Nro: " <<  v_tarjetas[i].numeroTarjeta << " no efectuo viajes" << "\n" << endl;
                    }
                }
            }
        }
        else
        {
            cout << "error carga del vector de tarjetas" << endl;
        }
        system("pause");
        system("cls");
        fclose(a_tarjetas);
    }
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

int contarRegistrosTarjetas()
{
    FILE* archivo;
    int tam=0;
    Tarjetas contar;
    ///abrir
    archivo = fopen(ARCHIVO_TARJETAS,"rb");
    ///compruebo
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        ///leo
        while(fread(&contar,sizeof(Tarjetas),1,archivo)==1)
        {
            tam++;
        }
        ///cierro el archivo
        fclose(archivo);
        return tam;
    }
}


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

/// Funcion complementaria
struct Tarjetas obtenerRegTarjeta(char *tarjeta)
{
    FILE* archivo;
    Tarjetas retorno;
    ///abro el archivo
    archivo = fopen(ARCHIVO_TARJETAS,"rb");
    ///Verifico
    if(archivo==NULL)
    {
        cout << "ERROR: Archivo No Existente" << endl;
    }
    else
    {
        while(fread(&retorno,sizeof(Tarjetas),1,archivo)==1)
        {
            if(strcmp(tarjeta,retorno.numeroTarjeta)==0)
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
