#include <iostream>
#include "CuentaBancaria.h"
#include "VerificadorLogico.h"

using namespace std;

//Constructor e implementacion de los metodos de la clase CuentaBancaria
CuentaBancaria::CuentaBancaria(string titular, int pin, double saldo, bool activa) {
    this->titular = titular;
    this->pin = pin;
    this->saldo = saldo;
    this->activa = activa;
}

bool CuentaBancaria::estaActiva() {
    return activa;
}

bool CuentaBancaria::pinCorrecto(int pinIngresado) {
    return pinIngresado == pin;
}

bool CuentaBancaria::montoPositivo(double monto) {
    return monto > 0;
}

bool CuentaBancaria::fondosSuficientes(double monto) {
    return saldo >= monto;
}

bool CuentaBancaria::iniciarSesion(int pinIngresado) {
    bool P = pinCorrecto(pinIngresado);
    bool A = estaActiva();
    bool L = P && A;

    cout << "\n[LOGIN]\n";
    cout << "(P and A) entonces L = "
         << VerificadorLogico::v(VerificadorLogico::implica(P && A, L))
         << endl;

    return L;
}

bool CuentaBancaria::depositar(double monto) {
    bool A = estaActiva();
    bool M = montoPositivo(monto);
    bool D = false;

    if (A && M) {
        saldo += monto;
        D = true;
    }

    cout << "\n[DEPOSITO]\n";
    cout << "(A and M) entonces D = "
         << VerificadorLogico::v(VerificadorLogico::implica(A && M, D))
         << endl;

    return D;
}

bool CuentaBancaria::retirar(double monto) {
    bool A = estaActiva();
    bool M = montoPositivo(monto);
    bool F = fondosSuficientes(monto);
    bool R = false;

    double saldoInicial = saldo;

    if (A && M && F) {
        saldo -= monto;
        R = true;
    }

    bool formula = VerificadorLogico::implica(A && M && F, R);
    bool postcondicion = true;

    if (R) {
        postcondicion = (saldo == saldoInicial - monto) && (saldo >= 0);
    }

    cout << "\n[RETIRO]\n";
    cout << "A: " << VerificadorLogico::v(A)
         << " | M: " << VerificadorLogico::v(M)
         << " | F: " << VerificadorLogico::v(F)
         << " | R: " << VerificadorLogico::v(R) << endl;

    cout << "(A and M and F) entonces R = "
         << VerificadorLogico::v(formula) << endl;

    cout << "Postcondicion saldo valido = "
         << VerificadorLogico::v(postcondicion) << endl;

    return R;
}

bool CuentaBancaria::transferir(CuentaBancaria& destino, double monto) {
    bool A = estaActiva();
    bool AD = destino.estaActiva();
    bool M = montoPositivo(monto);
    bool F = fondosSuficientes(monto);
    bool T = false;

    if (A && AD && M && F) {
        saldo -= monto;
        destino.saldo += monto;
        T = true;
    }

    cout << "\n[TRANSFERENCIA]\n";
    cout << "A: " << VerificadorLogico::v(A)
         << " | AD: " << VerificadorLogico::v(AD)
         << " | M: " << VerificadorLogico::v(M)
         << " | F: " << VerificadorLogico::v(F)
         << " | T: " << VerificadorLogico::v(T) << endl;

    cout << "(A and AD and M and F) entonces T = "
         << VerificadorLogico::v(
                VerificadorLogico::implica(A && AD && M && F, T)
            )
         << endl;

    return T;
}

void CuentaBancaria::mostrar() {
    cout << titular << " | Saldo: S/ " << saldo
         << " | Activa: " << VerificadorLogico::v(activa) << endl;
}