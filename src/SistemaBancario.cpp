#include <iostream>
#include <iomanip>
#include "SistemaBancario.h"
#include "VerificadorLogico.h"

using namespace std;

void SistemaBancario::tablaRetiro() {
    int total = 0;
    int correctos = 0;
    int realizados = 0;
    int denegados = 0;

    cout << "\nTABLA DE VERDAD: (A and M and F) entonces R\n\n";

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