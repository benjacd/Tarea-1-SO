#pragma once
#include "job.h"
#include <iostream>
#include<string>
using namespace std;
class job
{
private:
	char ID;
	float TLL, TR, RR;
	bool ver = 1;
public:
	void crearjob();
	void mostrarjob();
	bool getver() { return ver; };
	void setver(bool verr) { ver = verr; };
	float getTLL() { return TLL; };
	char getID() { return ID; };
};

