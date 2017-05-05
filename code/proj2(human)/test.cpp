#include <iostream>
#include "humweight.h"
using namespace std;

int main(int argc, char const *argv[])
{
	double w = 75*2.2;
	//para1[]={STAT, SHLDH, HEADC, W}
	double para1[] = {177.5*0.394, 145.5*0.394, 16.4*pi*0.394, w};
	//para2[]={CHESB, CHESD, WAISD, SHLDH, SUBH,HNT,SW1,hipb,waisd,buttd}
	double para2[] = {31.5*0.394, 24.5*0.394, 23.5*0.394, 145.5*0.394, 130*0.394, 0.47*75*2.2+12, 0.079*75*2.2, 33.4*0.394, 23.5*0.394, 250*0.394};
	//para3[]={HIPB,WAISD,BUTTD,HNT,SW1,SW2}
	double para3[] = {33.4*0.394, 23.5*0.394, 250*0.394, 0.47*75*2.2+12, 0.079*75*2.2, 0};
	//para4[]={FISTD, BH}
	double para4[] = {26*0.394, 0.01*75*2.2+0.7};
	//para5[]={AXILC, ELBC,UPARL,BUA}
	double para5[] = {97*0.394, (469-315-5)/2*0.394, 33.8*0.394, 0.08*75*2.2-2.9};
	//para6[]={ELBC, WRISC, FOARL, BFO}
	double para6[] = {(469-315-5)/2*0.394, 20*0.394, 25.8*0.394, 0.04*75*2.2-0.5};
	//para7[]={THIHC,GKNEC,STAT,SITH,TIBH,TROCH,BUL}
	double para7[] = {85*0.394, 40*0.394, 177.5*0.394, 95.8*0.394, 10*0.394, 80*0.394, 0.18*75*2.2+3.2};
	//para8[]={GKNEC, ANKC, TIBH, SPHYH, BLL}
	double para8[] = {40*0.394, 53.2*0.394, 10*0.394, 0.11*75*2.2-1.9};
	//para9[]={SPHYH, FOOTL, BF}
	double para9[] = {10*0.394, 26.5*0.394, 0.02*75*2.2+1.5};
    
    cout<<"各部分重量："<<endl;
	double* con = calweight(w);
	cout<<endl<<"头部数据："<<endl;
	double* con1 = head(para1);
	cout<<endl<<"上躯干数据："<<endl;
	double* con2 = uppt(para2);
	cout<<endl<<"下躯干数据："<<endl;
	double* con3 = lowt(para3);
	cout<<endl<<"手部数据："<<endl;
	double* con4 = hand(para4);
	cout<<endl<<"上臂数据："<<endl;
	double* con5 = uppar(para5);
	cout<<endl<<"前臂数据："<<endl;
	double* con6 = forear(para6);
	cout<<endl<<"大腿数据："<<endl;
	double* con7 = upple(para7);
	cout<<endl<<"小腿数据："<<endl;
	double* con8 = lowle(para8);
	cout<<endl<<"足部数据："<<endl;
	double* con9 = foot(para9);
	return 0;
}