#pragma once
#include "job.h"
#include <iostream>
#include<string>
using namespace std;
class job
{
private:
	char ID;
	float TLL, TR, RR,RRS;
	bool ver = false;
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
	void setRR(float RRR) { RR=RRR; };
	float getRR() { return RR; };
	void setID(char idd) { ID = idd; };
	void setRRS(float RRR) { RRS = RRR; };
	float getRRS() { return RRS; };

};


