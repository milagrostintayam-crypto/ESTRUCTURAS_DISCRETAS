#ifndef SISTEMABANCARIO_H
#define SISTEMABANCARIO_H

#include "CuentaBancaria.h"

class SistemaBancario {
private:
    CuentaBancaria cuenta1;
    CuentaBancaria cuenta2;
    bool sesionIniciada;

public:
    SistemaBancario();

    void menu();
    void iniciarSesion();
    void depositar();
    void retirar();
    void transferir();
    void verSaldos();
    void ejecutarVerificacionFormal();
};

#endif