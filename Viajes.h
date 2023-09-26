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

void mostrarViaje(Viajes);

#endif // VIAJES_H_INCLUDED
