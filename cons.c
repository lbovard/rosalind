#include <stdio.h>

//ALWAYS INCLUDE EOF!!
//simple code that simply loops over all characters
// and outputs matrix
int main() {
	int profile[1000][4];
	char a;
	char bases[4]={'A','C','G','T'};
	int i,j,length,k,max,index;
	a=getchar();	
	//get characters
	for(i=0;i<1000;i++) {
		for(j=0;j<4;j++) {
			profile[i][j]=0;
		}
	}
	for(i=0;i<10;i++) {
		if(a=='>') { while(getchar()!='\n'); }
		a=getchar();
		k=0;
		while(a!='>' && a!=EOF) {
			if(a=='\n' || a==EOF) { 
				a=getchar();
		  }
 			else {
				if(a=='A') { profile[k][0]++;}
				if(a=='C') { profile[k][1]++;}
				if(a=='G') { profile[k][2]++;}
				if(a=='T') { profile[k][3]++;}
				k++;
				a=getchar();
			}
		}
		length=k;
		a='>';
	}
	// find each maximum
	for(i=0;i<length;i++) {
		max=0;
		for(j=0;j<4;j++) {
			if(profile[i][j]>max) {
				max=profile[i][j];
				index=j;
			}
		}
		printf("%c",bases[index]);
	}
	printf("\n");
	//print matrix
	for(i=0;i<4;i++) {
		printf("%c: ",bases[i]);
		for(j=0;j<length;j++) {
			printf("%d ",profile[j][i]);
		}
		printf("\n");
	}
	return 0;
}
