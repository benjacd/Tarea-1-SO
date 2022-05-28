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
	float ta, ts;
public:
	void crearjob();
	void mostrarjob();
	bool getver() { return ver; };
	void setver(bool verr) { ver = verr; };
	float getTLL() { return TLL; };
	char getID() { return ID; };
	void setta(float taa) { ta = taa; };
	float getta() { return ta; };
	void setts(float tss) { ts = tss; };
	float getts() { return ts; };
	float getTR() { return TR; };
};

