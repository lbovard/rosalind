#include <stdio.h>

int main() {
	//reverse RNA Codon table
	int table[26]=
	{4,1,2,2,2,2,4,2,3,1,2,6,
	 1,2,1,4,2,6,6,4,1,4,1,1,2,1};
	char a;
	//start with end codon
	int total=3;
	a=getchar();
	while(a!='\n') {
		total=(table[a-65]*total)%1000000;
		a=getchar();
	}
	printf("%d\n",total);
	return 0;
}
