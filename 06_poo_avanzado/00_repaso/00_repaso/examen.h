#ifndef EXAMEN_H
#define EXAMEN_H
#include <cstring>

class Examen
{
private:
    int nota;
    char fecha[20];
public:
    Examen();
    Examen(float n, const char *f);
    float getNota();
};

#endif // EXAMEN_H
