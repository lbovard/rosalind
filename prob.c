#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	char c;
	int i,j;
	int ntrials=18;
	int BP[4]={0,0,0,0};
	double content;
	double cp[4];
	double prob=0.0;
	double cont_arr[20];
	
	c=getchar();
	while(c!='\n') {
		if(c=='A') BP[0]++;
		if(c=='C') BP[1]++;
		if(c=='G') BP[2]++;
		if(c=='T') BP[3]++;
		c=getchar();
	}
	for(i=0;i<ntrials;i++) {
		scanf("%lf",&cont_arr[i]);
	}
	for(i=0;i<ntrials;i++) {
		content=cont_arr[i];
		prob=0;
		cp[0]=log10((1.0-content)*0.5);
		cp[1]=log10(content*0.5);
		cp[2]=cp[1];
		cp[3]=cp[0];
		for(j=0;j<4;j++) {
			prob+=(double)BP[j]*cp[j];
		}
		printf("%1.3lf ",prob);
	}
	printf("\n");
	return 0;
}

		
