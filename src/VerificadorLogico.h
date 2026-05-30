#ifndef VERIFICADORLOGICO_H
#define VERIFICADORLOGICO_H

#include <string>
using namespace std;

class VerificadorLogico {
public:
    static bool implica(bool antecedente, bool consecuente);
    static string v(bool dato);
};

#endif