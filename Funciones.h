#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menu();
//1) -----------------------------------------------------
void buscarViaje(); //1- pido la cadeta tarjeta. 2- Corroboro que existe la tarjeta. 3- busco los registros adjuntos a esa tarjeta (strcmp)
//2) -----------------------------------------------------
void buscarMenorImporteViaje(); //1- cargo los viajes en un vector. 2- comparo.
//3) -----------------------------------------------------
void mayorRecaudacionSubteMes();
//4) -----------------------------------------------------
void contarViajes_Colectivos_Mayo();
//5) -----------------------------------------------------
void mayorImporteViaje();
//6) -----------------------------------------------------
void mostrarGastosTarjetas();

/// Funciones complementarias
bool existeTarjeta(char *);
int contarRegistrosViajes();
int contarRegistrosTarjetas();
bool salirFuncion();

#endif // FUNCIONES_H_INCLUDED
