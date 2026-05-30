#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    int pin;
    double saldo;
    bool activa;

public:
    CuentaBancaria(string titular, int pin, double saldo, bool activa);

    bool estaActiva();
    bool pinCorrecto(int pinIngresado);
    bool montoPositivo(double monto);
    bool fondosSuficientes(double monto);

    bool iniciarSesion(int pinIngresado);
    bool depositar(double monto);
    bool retirar(double monto);
    bool transferir(CuentaBancaria& destino, double monto);

    double obtenerSaldo();
    string obtenerTitular();

    void mostrar();
};

#endif