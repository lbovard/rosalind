#include <stdio.h>

int main() {
	//store DNA string in array
	char string[1000];
	char base;
	int i=0;
	int length=0;
	base=getchar();
	while(base != '\n') {
		length++;
		//replace the base with the proper compliment
		if(base=='A') string[i]='T';
		if(base=='T') string[i]='A';
		if(base=='C') string[i]='G';
		if(base=='G') string[i]='C';
		base=getchar();
		i++;
	}
	for(i=length-1;i>=0;i--) {
		printf("%c",string[i]);
	}
	printf("\n");
	return 0;
}
	
				
	
	
