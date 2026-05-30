#include "VerificadorLogico.h"

bool VerificadorLogico::implica(bool antecedente, bool consecuente) {
    return (!antecedente) || consecuente;
}

string VerificadorLogico::v(bool dato) {
    return dato ? "V" : "F";
}