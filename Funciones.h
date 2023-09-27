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
//5) -----------------------------------------------------
//6) -----------------------------------------------------

/// Funciones complementarias
bool existeTarjeta(char *);
int contarRegistrosViajes();
struct Tarjetas obtenerRegTarjeta(char *);
bool salirFuncion();

#endif // FUNCIONES_H_INCLUDED
