#include "job.h"
#include <iostream>
#include<string>
using namespace std;
void job::crearjob()
{
	cout << "Ingrese el id del trabajo: " << endl; cin >> ID;
	cout << "Ingrese el tiempo de llegada: " << endl; cin >> TLL;
	cout << "Ingrese el tiempo de rafaga: " << endl; cin >> TR;
	RR = TR; 
};
void job::mostrarjob()
{
	cout << "El id del trabajo: " << ID <<endl; 
	cout << "El tiempo de llegada: " << TLL <<endl; 
	cout << "El tiempo de rafaga: " << TR <<endl; 
}
