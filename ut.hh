#pragma once

#include<chrono>
#include<random>
#include"en.hh"

double point_direction(double,double,double,double);
double point_distance (double,double,double,double);
double degtorad(double);
double radtodeg(double);
int    sign(double);
int    arb(int);
in*    instance_create(en&,string,double,double);
void   instance_destroy(in*);

using namespace std;
