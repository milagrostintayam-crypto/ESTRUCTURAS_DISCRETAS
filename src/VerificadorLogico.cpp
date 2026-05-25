#include "VerificadorLogico.h"

bool VerificadorLogico::implica(bool p, bool q) {
    return (!p) || q;
}

string VerificadorLogico::v(bool dato) {
    return dato ? "V" : "F";
}