#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define pi 3.1415926

//the weight of part of body
double* calweight(double w){
	double weight[7];
	string mark[] = {"HNT(头颈躯干):", "BUA(双上臂):", "BFO(双前臂):", "BH(双手):", "BUL(双大腿):", "BLL(双小腿):", "BF(双脚):"};
	weight[0] = 0.47 * w + 12;
	weight[1] = 0.08 * w - 2.9;
	weight[2] = 0.04 * w - 0.5;
	weight[3] = 0.01 * w + 0.7;
	weight[4] = 0.18 * w + 3.2;
	weight[5] = 0.11 * w - 0.9;
	weight[6] = 0.02 * w +1.5;
    for (int i = 0; i < 7; ++i)
    {
    	cout<<mark[i]<<weight[i]<<endl;
    }
    return weight;
}

//head
//para[]={STAT, SHLDH, HEADC, W}
double* head(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "SW(质量):", "DELTA(比重):"};
	double conseq[5];
	conseq[0] = yita * (para[0] - para[1]);
	conseq[1] = para[2]/(2*pi);
	conseq[2] = para[0] - para[1];
	conseq[3] = 0.079 * para[3];
	conseq[4] = conseq[3]/(4*conseq[0]*conseq[1]*conseq[1]);
	for (int i = 0; i < 5; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//upper torso
//para[]={CHESB, CHESD, WAISD, SHLDH, SUBH,HNT,SW1,hipb,waisd,buttd}
double* uppt(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "DELTA(比重):", "SW(质量):"};
	double conseq[5];
	conseq[0] = yita * para[0];
	conseq[1] = 0.25*(para[1]+para[2]);
	conseq[2] = para[3] - para[4];
	conseq[3] = (para[5]-para[6])/(pi*conseq[0]*conseq[1]*conseq[2]+0.9783*pi*para[7]*conseq[2]*0.25*(para[8]+para[9]));
	conseq[4] = conseq[3]/(pi*conseq[0]*conseq[1]*conseq[2]);
	for (int i = 0; i < 5; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//lower torso
//para[]={HIPB,WAISD,BUTTD,HNT,SW1,SW2}
double* lowt(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SW(质量):", "DELTA(比重):"};
	double conseq[4];
	conseq[0] = yita * para[0];
	conseq[1] = 0.25*(para[1]+para[2]);
	conseq[2] = para[3]-para[4]-para[5];
	conseq[3] = conseq[2]/(pi*para[7]*conseq[2]*0.25*(para[8]+para[9]));
	for (int i = 0; i < 4; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//hand
//para[]={FISTD, BH}
double* hand(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "SW(质量):", "DELTA(比重):"};
	double conseq[5];
	conseq[0] = para[0]/(2*pi);
	conseq[1] = conseq[0];
	conseq[2] = 2*conseq[0];
	conseq[3] = 0.5*para[1];
	conseq[4] = 3*conseq[3]/(4*pi*conseq[0]*conseq[0]);
	for (int i = 0; i < 5; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//upper arm
//para[]={AXILC, ELBC,UPARL,BUA}
double* uppar(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "SW(质量):"};
	double conseq[4];
	conseq[0] = para[0]/(2*pi);
	conseq[1] = para[1]/(2*pi);
	conseq[2] = para[2];
	conseq[3] = 0.5*para[3];
	for (int i = 0; i < 4; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//forearm
//para[]={ELBC, WRISC, FOARL, BFO}
double* forear(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "SW(质量):"};
	double conseq[4];
	conseq[0] = para[0];
	conseq[1] = para[1]/(2*pi);
	conseq[2] = para[2];
	conseq[3] = 0.5*para[3];
	for (int i = 0; i < 4; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//upper leg
//para[]={THIHC,GKNEC,STAT,SITH,TIBH,TROCH,BUL}
double* upple(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "DELTA(比重):", "SW(质量):"};
	double conseq[5];
	conseq[0] = para[0]/(2*pi);
	conseq[1] = para[1]/(2*pi);
	conseq[2] = para[2]-para[3]-para[4];
	conseq[3] = para[3]-para[4]+para[5];
	conseq[4] = 0.5*para[6];
	for (int i = 0; i < 4; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//lower leg
//para[]={GKNEC, ANKC, TIBH, SPHYH, BLL}
double* lowle(double* para){
	double yita = 0.5;
	string mark[] = {"R(长轴):", "RR(短轴):", "SL(质心):", "SW(质量):"};
	double conseq[4];
	conseq[0] = para[0]/(2*pi);
	conseq[1] = para[1]/(2*pi);
	conseq[2] = para[2]-para[3];
	conseq[3] = 0.5*para[4];
	for (int i = 0; i < 4; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}

//foot
//para[]={SPHYH, FOOTL, BF}
double* foot(double* para){
	string mark[] = {"R(长轴):", "SL(质心):", "SW(质量):"};
	double conseq[3];
	conseq[0] = para[0]*0.5;
	conseq[1] = para[1];
	conseq[2] = 0.5*para[2];
	for (int i = 0; i < 3; ++i)
	{
		cout<<mark[i]<<conseq[i]<<endl;
	}
	return conseq;
}