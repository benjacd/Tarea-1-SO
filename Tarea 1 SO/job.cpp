#include "job.h"
#include <iostream>
#include<string>
using namespace std;
void job::crearjob()
{
	cout << "Para el trabajo [" << ID << "] Ingrese el:" << endl;
	cout << "tiempo de llegada y el de rafaga formato x y (separados por un espacio): " << endl; cin >> TLL >> TR;
	RR = TR; 
	ta = TLL;
};
void job::mostrarjob()
{
	cout << "El id del trabajo: " << ID <<endl; 
	cout << "El tiempo de llegada: " << TLL <<endl; 
	cout << "El tiempo de rafaga: " << TR <<endl; 
}
