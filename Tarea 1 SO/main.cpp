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
void mostrarlista(Tlista& lista)
{
    Tlista q = lista;
    while (q != NULL)
    {
        q->jobs.mostrarjob();
        q = q->sgte;
    }
}
void insertarFinal(Tlista& lista, job valor) //inserta un elemento al final de la lista
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
int numelem(Tlista& lista) //determina el numero de elementos de la lista t
{
    Tlista q = lista;
    int i = 0;
    while (q != NULL)
    {
        q = q->sgte;
        i++;
    }
    return i;
}
void imprimir_resultados(job j1[], int n) //imprime los resultados
{
    for (int i = 1; i < n; i++)
    {
        j1[i].setta(j1[i - 1].getts()); j1[i].setts(j1[i].getta() + j1[i].getTR());
        cout << "|" << j1[i].getID() << "|" << j1[i].getts();
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|" << j1[i].getID() << " | tt = " << j1[i].getts() - j1[i].getTLL() << "| wt = " << j1[i].getta() - j1[i].getTLL() << "|" << endl;
    }
}
void ordenaTLL(job j1[], int n)
{
    job x;
    for (int i = 0; i < n; i++)   //ordena por tiempo de llegada
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j1[i].getTLL() > j1[j].getTLL())
            {
                x = j1[i];
                j1[i] = j1[j];
                j1[j] = x;
            }
        }
    }
}
void ordenaTRR(job j1[], int n)
{
    job x;
    for (int i = 1; i < n; i++)               //ordena por rafaga se salta el primero ya que es el primero que llega
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j1[i].getTR() > j1[j].getTR())
            {
                x = j1[i];
                j1[i] = j1[j];
                j1[j] = x;
            }
        }
    }
}

void FCFS(job j2[], int n)
{
    job* j1; j1 = new job[n]; j1 = j2;
    j1[0].setts(j1[0].getta() + j1[0].getTR());
    cout << j1[0].getta() << "|" << j1[0].getID() << "|" << j1[0].getts();

    imprimir_resultados(j1, n);
}
void SJFA(job j2[], int n)
{
    job* j1; j1 = new job[n]; j1 = j2;
    j1[0].setts(j1[0].getta() + j1[0].getTR());
    cout << j1[0].getta() << "|" << j1[0].getID() << "|" << j1[0].getts();
    ordenaTRR(j1, n);
    imprimir_resultados(j1, n);
}

void SJFNA(job j2[], int n)
{
    job* j1; j1 = new job[n]; j1 = j2;
    job jaux;
    Tlista lista = NULL;
    int ver = 1,complete = n,pos=0;
    float cr = 0,tsaux;
    cout << j1[0].getta() << "|" << j1[0].getID() << "|";
    ordenaTRR(j1, n);
    while (complete != 0)
    {
        for (int i = 0; i < n; i++)
        {

        }

    }
}
int main()
{
    Tlista lista = NULL;
    job t1;
    int ver = 1, i = 65;
    while (ver == 1)
    {
        t1.setID(i); i++;
        t1.crearjob();
        insertarFinal(lista, t1);
        cout << "Desea seguir ingresando datos? 1 = Si, 0 = No" << endl; cin >> ver;
    }

    int n = numelem(lista);
    job *j1, x;
    j1 = new job[n];
    Tlista q = lista;
    for (int i = 0; q != NULL; i++)
    {
        j1[i] = q->jobs;
        q = q->sgte;
    }
    ordenaTLL(j1, n);
    SJFNA(j1, n);
}