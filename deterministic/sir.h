#pragma once
#include<iostream>
#include<cmath>

using namespace std;

class SIR{
private:

double t,S,I,R,Pop[3];
double dPop[3],step;

double beta, gamma;
double tmax;
public:

SIR();
SIR(double beta0, double gamma0, double step0, double S00, \
          double I00, double tmax0);
~SIR();

void Diff(double Pop[3]);
void Runge_Kutta();

void output();
};

SIR::SIR(double beta0, double gamma0, double step0,double S00, \
       double I00, double tmax0)
{

beta = beta0;
gamma =gamma0;
step = step0;

S =S00;
I = I00;
R = 1 - S - I;

tmax = tmax0;
}
SIR::~SIR(){

}

void SIR::Diff(double Pop[3])
{

// The differential equations


dPop[0] = - beta*Pop[0]*Pop[1];              // dS/dt

  dPop[1] = beta*Pop[0]*Pop[1] - gamma*Pop[1];   // dI/dt

  dPop[2] = gamma*Pop[1];                    // dR/dt

}

void SIR::Runge_Kutta(){
int i;
double dPop1[3], dPop2[3], dPop3[3], dPop4[3];

double tmpPop[3], initialPop[3];

initialPop[0]=S; initialPop[1]=I; initialPop[2]=R;

Diff(initialPop);
for(i=0;i<3;i++)
{

dPop1[i]=dPop[i];
tmpPop[i]=initialPop[i]+step*dPop1[i]/2;
}

Diff(tmpPop);
for(i=0;i<3;i++)
{


dPop2[i]=dPop[i];
tmpPop[i]=initialPop[i]+step*dPop2[i]/2;
}

Diff(tmpPop);
for(i=0;i<3;i++)
{

dPop3[i]=dPop[i];
tmpPop[i]=initialPop[i]+step*dPop3[i];
}

Diff(tmpPop);

for(i=0;i<3;i++)
{

dPop4[i]=dPop[i];
tmpPop[i]=initialPop[i]+(dPop1[i]/6 + dPop2[i]/3 + dPop3[i]/3 + dPop4[i]/6)*step;
}


S=tmpPop[0]; I=tmpPop[1]; R=tmpPop[2];


}

void SIR::output(){
t=0;
cout <<"	t			S			I			R"<<endl;

do
{
Runge_Kutta();
t+=step;
cout<<t<<"   		"<<S<<" 		  "<<I<<"	  		 "<<R<<"		   "<<endl;
}

while(t<tmax);

}
//#endif // GUARD_SIR