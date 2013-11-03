#include <stdio.h>

int main() {
	// the base DNA element
	char base;
	// stores number of times of A C G T
	int ntimes[4]={0};
	base =getchar();
	// single array, just loop over until done
	while(base != '\n') {
		//this could be replaced with something faster
		//that accesses an array based on character but whatever
		// this code is so fast it doesn't matter
		if(base=='A') printf("A");
		if(base=='C') printf("C");
		if(base=='G') printf("G");
		if(base=='T') printf("U");
		base=getchar();
	}
	printf("\n");
	return 0;
}
