/* 
Compute probability using basic laws
*/
#include <stdio.h>

double dom[3][3]={ 
	{1.0,1.0,1.0},
	{1.0,0.75,0.5},
	{1.0,0.5,0.0}};
int main() {
	double prob[3][3];
	double a,b,c;
	double tprob=0;
	int i,j;
	scanf("%lf %lf %lf",&a,&b,&c);
	prob[0][0]=a*(a-1);
	prob[0][1]=a*b;
	prob[0][2]=a*c;
	prob[1][0]=a*b;
	prob[1][1]=b*(b-1);
	prob[1][2]=b*c;
	prob[2][0]=c*a;
	prob[2][1]=c*b;
	prob[2][2]=c*(c-1);
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			prob[i][j]=prob[i][j]/((a+b+c)*(a+b+c-1));
		}
	}
	for(i=0;i<3;i++) {
		for(j=0;j<3;j++) {
			tprob+=prob[i][j]*dom[i][j];
		}
	}
	printf("%lf\n",tprob);
	return 0;
}
	
