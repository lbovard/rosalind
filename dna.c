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
		if(base=='A') ntimes[0]++;
		if(base=='C') ntimes[1]++;
		if(base=='G') ntimes[2]++;
		if(base=='T') ntimes[3]++;
		base=getchar();
	}
	printf("%d %d %d %d\n",ntimes[0],ntimes[1],ntimes[2],ntimes[3]);
	return 0;
}
