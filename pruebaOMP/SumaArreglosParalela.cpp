// pruebaOMP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    srand((unsigned)time(NULL));

    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++) {
            a[i] = (rand() % 1000) + 1;
            b[i] = (rand() % 1000) + 1;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
    std::cout << "Primeros " << mostrar << "valores del arreglo a: | ";
    imprimeArreglo(a);
    std::cout << "Primeros " << mostrar << "valores del arreglo b: | ";
    imprimeArreglo(b);
    std::cout << "Primeros " << mostrar << "valores del arreglo c: | ";
    imprimeArreglo(c);

}

void imprimeArreglo(float* d) {
    for (int x = 0 < mostrar; x++;) {
            std::cout << d[x] << "|-|";
    }
    std::cout << std::endl;
}