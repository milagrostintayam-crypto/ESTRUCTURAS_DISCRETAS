#include <iostream>
#include "CuentaBancaria.h"
#include "SistemaBancario.h"

using namespace std;

int main() {
    CuentaBancaria cuenta1("Juan Perez", 1234, 1000, true);
    CuentaBancaria cuenta2("Maria Lopez", 4321, 500, true);

    cout << "MINI BANCO - VERIFICACION FORMAL BASICA\n";

    cuenta1.mostrar();
    cuenta2.mostrar();

    if (cuenta1.iniciarSesion(1234)) {
        cuenta1.depositar(200);
        cuenta1.retirar(150);
        cuenta1.transferir(cuenta2, 300);
    }

    cout << "\n[SALDOS FINALES]\n";
    cuenta1.mostrar();
    cuenta2.mostrar();

    SistemaBancario sistema;
    sistema.tablaRetiro();

    return 0;
}