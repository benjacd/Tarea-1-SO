#include <iostream>
#include<string>
#include <stdlib.h>
#include "job.h"
using namespace std;

struct nodo {
	job jobs;
	struct nodo* sgte;
};
typedef struct nodo* Tlista;
void insertarFinal(Tlista& lista, job valor)
{
    Tlista t, q = new(struct nodo);

    q->jobs = valor;
    q->sgte = NULL;

    if (lista == NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while (t->sgte != NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }

}
void mostrarlista(Tlista& lista)
{
    Tlista q = lista;
    while (q != NULL)
    {
        q->jobs.mostrarjob();
       // q->jobs.setTLL(100);
        q = q->sgte;
    }
}
int numelem(Tlista& lista)
{
    Tlista q = lista;
    int i = 0;
    while (q != NULL)
    {
        q->jobs.mostrarjob();
        q = q->sgte;
        i++;
    }
    return i;
}
int main()
{
    Tlista lista = NULL;
    job t1;
    int ver = 1;
    while (ver == 1)
    {
        t1.crearjob();
        insertarFinal(lista, t1);
        cout << "Desea seguir ingresando datos? 1 = Si, 0 = No" << endl; cin >> ver;
    }
    cout << "el numero de trabajos es: " << numelem(lista);
}