#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class VerificadorLogico {
public:
    static bool implica(bool p, bool q) {
        return (!p) || q;
    }

    static string v(bool dato) {
        return dato ? "V" : "F";
    }
};

class CuentaBancaria {
private:
    string titular;
    int pin;
    double saldo;
    bool activa;

public:
    CuentaBancaria(string titular, int pin, double saldo, bool activa) {
        this->titular = titular;
        this->pin = pin;
        this->saldo = saldo;
        this->activa = activa;
    }

    bool estaActiva() {
        return activa;
    }

    bool pinCorrecto(int pinIngresado) {
        return pinIngresado == pin;
    }

    bool montoPositivo(double monto) {
        return monto > 0;
    }

    bool fondosSuficientes(double monto) {
        return saldo >= monto;
    }

    bool iniciarSesion(int pinIngresado) {
        bool P = pinCorrecto(pinIngresado);
        bool A = estaActiva();
        bool L = P && A;

        cout << "\n[LOGIN]\n";
        cout << "(P ∧ A) -> L = "
             << VerificadorLogico::v(VerificadorLogico::implica(P && A, L))
             << endl;

        return L;
    }

    bool depositar(double monto) {
        bool A = estaActiva();
        bool M = montoPositivo(monto);
        bool D = false;

        if (A && M) {
            saldo += monto;
            D = true;
        }

        cout << "\n[DEPOSITO]\n";
        cout << "(A ∧ M) -> D = "
             << VerificadorLogico::v(VerificadorLogico::implica(A && M, D))
             << endl;

        return D;
    }

    bool retirar(double monto) {
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

        cout << "(A ∧ M ∧ F) -> R = "
             << VerificadorLogico::v(formula) << endl;

        cout << "Postcondicion saldo valido = "
             << VerificadorLogico::v(postcondicion) << endl;

        return R;
    }

    bool transferir(CuentaBancaria& destino, double monto) {
        bool A = estaActiva();
        bool M = montoPositivo(monto);
        bool F = fondosSuficientes(monto);
        bool T = false;

        if (A && destino.estaActiva() && M && F) {
            saldo -= monto;
            destino.saldo += monto;
            T = true;
        }

        cout << "\n[TRANSFERENCIA]\n";
        cout << "Transferencia realizada: "
             << VerificadorLogico::v(T) << endl;

        return T;
    }

    void mostrar() {
        cout << titular << " | Saldo: S/ " << saldo
             << " | Activa: " << VerificadorLogico::v(activa) << endl;
    }
};

class SistemaBancario {
public:
    void tablaRetiro() {
        int total = 0;
        int correctos = 0;
        int realizados = 0;
        int denegados = 0;

        cout << "\nTABLA DE VERDAD: (A ∧ M ∧ F) -> R\n\n";

        cout << left << setw(8) << "Caso"
             << setw(8) << "A"
             << setw(8) << "M"
             << setw(8) << "F"
             << setw(10) << "R"
             << setw(10) << "Formula" << endl;

        int caso = 1;

        for (int A = 0; A <= 1; A++) {
            for (int M = 0; M <= 1; M++) {
                for (int F = 0; F <= 1; F++) {
                    bool antecedente = A && M && F;
                    bool R = antecedente;
                    bool formula = VerificadorLogico::implica(antecedente, R);

                    cout << left << setw(8) << caso
                         << setw(8) << VerificadorLogico::v(A)
                         << setw(8) << VerificadorLogico::v(M)
                         << setw(8) << VerificadorLogico::v(F)
                         << setw(10) << VerificadorLogico::v(R)
                         << setw(10) << VerificadorLogico::v(formula)
                         << endl;

                    total++;

                    if (formula) correctos++;
                    if (R) realizados++;
                    else denegados++;

                    caso++;
                }
            }
        }

        cout << "\n[METRICAS]\n";
        cout << "Casos posibles: 8\n";
        cout << "Casos evaluados: " << total << endl;
        cout << "Casos correctos: " << correctos << endl;
        cout << "Casos fallidos: " << total - correctos << endl;
        cout << "Retiros realizados: " << realizados << endl;
        cout << "Retiros denegados: " << denegados << endl;
        cout << "Cobertura logica: " << (total / 8.0) * 100 << "%\n";
    }
};

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