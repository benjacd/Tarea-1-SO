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
        q = q->sgte;
        i++;
    }
    return i;
}
void FCFS(job j1[], int n)
{
    int pos,ver=0;
    float taux, tsaux;
    for (int i = 0; i < n; i++)
    {
        float aux = 10000;
        for (int i = 0; i < n; i++)
        {
          if (j1[i].getTLL() < aux && j1[i].getver() != 0) { aux = j1[i].getTLL(); pos = i; }
        }
        if (ver == 0) {
        taux = j1[pos].getta(); cout << taux; 
        cout << "|" << j1[pos].getID(); tsaux = taux + j1[pos].getTR(); j1[pos].setts(tsaux);
        cout << "|" << tsaux; ver = 1;
        }
        else
        { 
            taux = tsaux; j1[pos].setta(taux);  tsaux = taux + j1[pos].getTR(); j1[pos].setts(tsaux);
            cout << "|" << j1[pos].getID();  cout << "|" << tsaux;
        }
        j1[pos].setver(0);
    }
    cout << endl; 
    for (int i = 0; i < n; i++)
    {
        cout << j1[i].getID()<<" | tt = "<<j1[i].getts()-j1[i].getTLL()<<"| wt = "<<j1[i].getta()-j1[i].getTLL()<<"|"<<endl;
    }
}
void SJFA(job j1[], int n)
{
    int pos, ver = 0,ver2 = 0;
    float taux, tsaux=0,tllaux;
    for (int i = 0; i < n; i++)
    {
        float aux = 10000,aux2=10000;
        for (int i = 0; i < n; i++)
        {
            if (j1[i].getTLL() < aux && j1[i].getver() != 0 && ver2 == 0) { aux = j1[i].getTLL(); pos = i; ver2 == 1; }
            else if (j1[i].getTLL() < tsaux && j1[i].getTR() <= aux2 && j1[i].getver() != 0 && ver2!=0) 
            {
                if (j1[i].getTR() == aux2)
                {
                    if (j1[i].getTLL() < tllaux){ aux2 = j1[i].getTR(); pos = i; tllaux = j1[i].getTLL(); }
                }
                else 
                {
                    aux2 = j1[i].getTR(); pos = i; tllaux = j1[i].getTLL();
                }
                
            }
        }
        if (ver == 0) {
            taux = j1[pos].getta(); cout << taux;
            cout << "|" << j1[pos].getID(); tsaux = taux + j1[pos].getTR(); j1[pos].setts(tsaux);
            cout << "|" << tsaux; ver = 1;
        }
        else
        {
            taux = tsaux; j1[pos].setta(taux);  tsaux = taux + j1[pos].getTR(); j1[pos].setts(tsaux);
            cout << "|" << j1[pos].getID();  cout << "|" << tsaux;
        }
        j1[pos].setver(0);
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << j1[i].getID() << " | tt = " << j1[i].getts() - j1[i].getTLL() << "| wt = " << j1[i].getta() - j1[i].getTLL() << "|" << endl;
    }
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

    int n = numelem(lista);
    job *j1;
    j1 = new job[n];
    Tlista q = lista;
    for (int i = 0; q != NULL; i++)
    {
        j1[i] = q->jobs;
        q = q->sgte;
    }
    SJFA(j1, n);
}