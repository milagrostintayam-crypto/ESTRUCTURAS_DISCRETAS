#ifndef VERIFICADOR_LOGICO_H
#define VERIFICADOR_LOGICO_H

#include <string>
using namespace std;

class VerificadorLogico {
public:
    static bool implica(bool p, bool q);
    static string v(bool dato);
};

#endif