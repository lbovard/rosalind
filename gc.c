#include <stdio.h>
#include <string.h>
#define TITLE 14
//should make this automatic 
#define MAX_PAIRS 10 

//note for this problem storing the base pairs 
// is not needed but might be useful in the future 
// so do it anyway
struct fasta {
	//fasta title
	//always in the form Rosalind_xxxx
	// xxxx is four digit number from 0000 to 9999
	char title[TITLE+1];
	char basep[1000];
	unsigned int length;
	double gc_content;
};

int main() {
	//define array of DNA strings
	struct fasta pairs[10];
	char a;
	int i,j;
	int tots=0;
	double max=0;
	int max_ind;

	//get first >
	a=getchar(); 
	for(j=0;j<MAX_PAIRS;j++){
		tots=0;
		//we have started a new fasta data set
		if(a=='>') {
			i=0;
			//scan in dna string name in fasta format
			scanf("%s",pairs[j].title);
			//remove newline
			getchar();
			
			a=getchar();
			while(a!='>' && a!=EOF) {
				//might be newlines
				if(a=='\n') { 
					a=getchar();
		    } else {
					if(a=='G' || a=='C') tots++;
					pairs[j].basep[i]=a;
					i++;
					a=getchar(); 
				}
			}
			pairs[j].length=i;
		}
		//compute gc content
		pairs[j].gc_content=100.0*(double)tots/(double)i;
	}

	for(j=0;j<MAX_PAIRS;j++) { 
		if(pairs[j].gc_content>max) { 
			max=pairs[j].gc_content;
			max_ind=j;
		}
	}
	printf("%s\n",pairs[max_ind].title);
	printf("%lf\n",pairs[max_ind].gc_content);
		
	return 0;
}
