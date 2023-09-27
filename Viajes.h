#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED


struct Viajes
{
    char numeroViaje[5];
    char numeroTarjeta[6];
    int medioTransporte;
    int mesViaje;
    float importeViaje;
};

void mostrarViaje(Viajes );
struct Viajes obtenerRegViaje(char *);

//const char *ARCHIVO_VIAJES = "Viajes.dat";
//const char *ARCHIVO_TARJETAS = "Tarjetas.dat";


#endif // VIAJES_H_INCLUDED
