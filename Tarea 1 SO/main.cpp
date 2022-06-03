#include <iostream>
#include<string>
#include <stdlib.h>
#include "job.h"

/* 

    Integrantes:
    - Renato Soto
    - Benjamín Castro
    - José Aynaya


*/
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
int buscarmenor(job j1[], int n)
{
    int pos = 0;
    float aux = 10000;
    for (int i = 0; i < n; i++)
    {
        if (j1[i].getRR() < aux && j1[i].getver() != true ) { aux = j1[i].getRR(); pos = i; }
    }
    return pos;
}
void SJFNA(job j2[] , int n)
{
    job* j1; j1 = new job[n]; j1 = j2;
    job jaux;
    Tlista lista = NULL;
    int ver = 1,complete = n,pos=0;
    float cr = 0,tsaux;
    cout << j1[0].getta() << "|" << j1[0].getID() << "|";
    while (complete != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (j1[i].getver() == false && j1[i].getRR() < j1[pos].getRR())//Verifica si hay alguno con rafaga menor
            {
                tsaux = j1[i].getTLL(); cr = j1[pos].getRR() - (tsaux - j1[pos].getta());
                if (j1[i].getRR() < cr) // Rafaga del entrante es menor a rafaga remanente del actual
                {
                    j1[pos].setts(tsaux);  j1[i].setta(tsaux); 
                    insertarFinal(lista, j1[pos]); j1[pos].setRR(cr);
                    if (j1[pos].getRR() == 0) { complete--; j1[pos].setver(true); }
                    pos = i;
                }
            }
        }
        if (j1[pos].getver() == false)
        {
            tsaux = j1[pos].getta() + j1[pos].getRR(); j1[pos].setts(tsaux); j1[pos].setver(true);
            insertarFinal(lista, j1[pos]);
            j1[pos].setRR(0); complete--; 
            pos = buscarmenor(j1, n);
        }
    }
    int nn = numelem(lista); job* j3; j3 = new job[n];     Tlista q = lista;
    for (int i = 0; q != NULL; i++)
    {
        j3[i] = q->jobs;
        q = q->sgte;
    }
    cout << j3[0].getts();
    
    for (int i = 1; i < nn; i++)           //ordena correctamente los ts y ta
    {
        j3[i].setta(j3[i - 1].getts()); 
        if (j3[i].getRR() != 0) { j3[i].setts(j3[i].getta() + j3[i].getRR()); }
        else
        {j3[i].setts(j3[i].getta() + j3[i].getTR());}
    }
    
    for (int i = 1; i < nn; i++) //imprime correctamente los ts y ta
    {
        cout << "|" << j3[i].getID() << "|" << j3[i].getts();
    }
    cout << endl;
    for (int i = 0; i < nn; i++) //imprime tt y wt
    {
        if(j3[i].getver()==true)
        cout << "|" << j3[i].getID() << " | tt = " << j3[i].getts() - j3[i].getTLL() << "| wt = " << j3[i].getta() - j3[i].getTLL() << "|" << endl;
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