#ifndef TARJETAS_H_INCLUDED
#define TARJETAS_H_INCLUDED

struct Tarjetas
{
    char numeroTarjeta[6];
    int mesAlta;
    char dniDuenio[9];
    float saldo;
    bool estado;
};

struct Tarjetas obtenerRegTarjeta(char *);

#endif // TARJETAS_H_INCLUDED
