#include <iostream>
#include "Viajes.h"

using namespace std;


void mostrarViaje(Viajes v){

    cout << "NUMERO VIAJE: " << v.numeroViaje << endl;

    cout << "NUMERO TARJETA: " << v.numeroTarjeta << endl;

    cout << "NUMERO MEDIO TRANSPORTE: " << v.medioTransporte << endl;

    cout << "MES DE VIAJE: " << v.mesViaje << endl;

    cout << "IMPORTE VIAJE: " << v.importeViaje << endl;

    cout << "-*-*-*-*-*-*-*-*-" << endl;
}
