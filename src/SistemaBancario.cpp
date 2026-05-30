#include <iostream>
#include <iomanip>
#include "SistemaBancario.h"
#include "VerificadorLogico.h"

using namespace std;

SistemaBancario::SistemaBancario()
    : cuenta1("Cuenta 1 - Diana", 1234, 500.0, true),
      cuenta2("Cuenta 2 - Maria", 2222, 300.0, true) {
    sesionIniciada = false;
}

void SistemaBancario::menu() {
    int opcion;

    do {
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "1. Iniciar sesion\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Transferir\n";
        cout << "5. Ver saldos\n";
        cout << "6. Ejecutar verificacion formal\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                iniciarSesion();
                break;

            case 2:
                depositar();
                break;

            case 3:
                retirar();
                break;

            case 4:
                transferir();
                break;

            case 5:
                verSaldos();
                break;

            case 6:
                ejecutarVerificacionFormal();
                break;

            case 7:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 7);
}

void SistemaBancario::iniciarSesion() {
    int pin;

    cout << "\n===== INICIO DE SESION =====\n";
    cout << "Ingrese PIN de la Cuenta 1: ";
    cin >> pin;

    sesionIniciada = cuenta1.iniciarSesion(pin);

    if (sesionIniciada) {
        cout << "Sesion iniciada correctamente.\n";
    } else {
        cout << "Error: PIN incorrecto o cuenta inactiva.\n";
    }
}

void SistemaBancario::depositar() {
    double monto;

    if (!sesionIniciada) {
        cout << "\nDebe iniciar sesion primero.\n";
        return;
    }

    cout << "\n===== DEPOSITO =====\n";
    cout << "Saldo antes del deposito: S/ " << cuenta1.obtenerSaldo() << endl;
    cout << "Ingrese monto a depositar: ";
    cin >> monto;

    bool resultado = cuenta1.depositar(monto);

    if (resultado) {
        cout << "Deposito realizado correctamente.\n";
    } else {
        cout << "Deposito denegado. Verifique que el monto sea positivo.\n";
    }

    cout << "Saldo despues del deposito: S/ " << cuenta1.obtenerSaldo() << endl;
}

void SistemaBancario::retirar() {
    double monto;

    if (!sesionIniciada) {
        cout << "\nDebe iniciar sesion primero.\n";
        return;
    }

    cout << "\n===== RETIRO =====\n";
    cout << "Saldo antes del retiro: S/ " << cuenta1.obtenerSaldo() << endl;
    cout << "Ingrese monto a retirar: ";
    cin >> monto;

    double saldoInicial = cuenta1.obtenerSaldo();
    bool resultado = cuenta1.retirar(monto);
    double saldoFinal = cuenta1.obtenerSaldo();

    if (resultado) {
        cout << "Retiro realizado correctamente.\n";

        bool postcondicion = (saldoFinal == saldoInicial - monto) && (saldoFinal >= 0);

        cout << "Postcondicion: saldoFinal = saldoInicial - monto y saldoFinal >= 0 -> "
             << VerificadorLogico::v(postcondicion) << endl;
    } else {
        cout << "Retiro denegado. Verifique cuenta activa, monto positivo o fondos suficientes.\n";
    }

    cout << "Saldo despues del retiro: S/ " << saldoFinal << endl;
}

void SistemaBancario::transferir() {
    double monto;

    if (!sesionIniciada) {
        cout << "\nDebe iniciar sesion primero.\n";
        return;
    }

    cout << "\n===== TRANSFERENCIA =====\n";
    cout << "Saldo Cuenta 1 antes: S/ " << cuenta1.obtenerSaldo() << endl;
    cout << "Saldo Cuenta 2 antes: S/ " << cuenta2.obtenerSaldo() << endl;

    cout << "Ingrese monto a transferir de Cuenta 1 a Cuenta 2: ";
    cin >> monto;

    bool resultado = cuenta1.transferir(cuenta2, monto);

    if (resultado) {
        cout << "Transferencia realizada correctamente.\n";
    } else {
        cout << "Transferencia denegada. Verifique condiciones.\n";
    }

    cout << "Saldo Cuenta 1 despues: S/ " << cuenta1.obtenerSaldo() << endl;
    cout << "Saldo Cuenta 2 despues: S/ " << cuenta2.obtenerSaldo() << endl;
}

void SistemaBancario::verSaldos() {
    cout << "\n===== SALDOS =====\n";
    cuenta1.mostrar();
    cuenta2.mostrar();
}

void SistemaBancario::ejecutarVerificacionFormal() {
    int casosPosibles = 0;
    int casosCorrectos = 0;
    int casosFallidos = 0;

    cout << "\nTABLA DE VERDAD - VERIFICACION FORMAL DEL RETIRO\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Caso | A | M | F | A^M^F | R esperado | R obtenido | Cumple\n";
    cout << "--------------------------------------------------------------------------------\n";

    for (int a = 0; a <= 1; a++) {
        for (int m = 0; m <= 1; m++) {
            for (int f = 0; f <= 1; f++) {

                bool A = a;
                bool M = m;
                bool F = f;

                casosPosibles++;

                double saldoInicial;
                double monto;

                if (F) {
                    saldoInicial = 500.0;
                } else {
                    saldoInicial = 50.0;
                }

                if (M) {
                    monto = 100.0;
                } else {
                    monto = -100.0;
                }

                CuentaBancaria cuentaPrueba("Cuenta de prueba", 1234, saldoInicial, A);

                double saldoAntes = cuentaPrueba.obtenerSaldo();

                bool R_obtenido = cuentaPrueba.retirar(monto);

                double saldoDespues = cuentaPrueba.obtenerSaldo();

                bool R_esperado = A && M && F;

                bool cumple = (R_esperado == R_obtenido);

                if (cumple) {
                    casosCorrectos++;
                } else {
                    casosFallidos++;
                }

                cout << setw(4) << casosPosibles << " | "
                     << VerificadorLogico::v(A) << " | "
                     << VerificadorLogico::v(M) << " | "
                     << VerificadorLogico::v(F) << " | "
                     << setw(5) << VerificadorLogico::v(A && M && F) << " | "
                     << setw(10) << VerificadorLogico::v(R_esperado) << " | "
                     << setw(10) << VerificadorLogico::v(R_obtenido) << " | "
                     << (cumple ? "Si" : "No") << endl;

                if (R_obtenido) {
                    bool postcondicion = (saldoDespues == saldoAntes - monto) && (saldoDespues >= 0);

                    cout << "      Postcondicion: saldoFinal = saldoInicial - monto -> "
                         << VerificadorLogico::v(postcondicion) << endl;
                }
            }
        }
    }

    double cobertura = (static_cast<double>(casosPosibles) / 8.0) * 100.0;
    double cumplimiento = (static_cast<double>(casosCorrectos) / casosPosibles) * 100.0;

    cout << "\nMETRICAS DE VERIFICACION\n";
    cout << "Casos posibles: " << casosPosibles << endl;
    cout << "Casos evaluados: " << casosPosibles << endl;
    cout << "Casos correctos: " << casosCorrectos << endl;
    cout << "Casos fallidos: " << casosFallidos << endl;
    cout << "Cobertura logica: " << cobertura << " %" << endl;
    cout << "Cumplimiento de especificacion: " << cumplimiento << " %" << endl;
}