#include <stdio.h>

int main() {
	int i;
	unsigned int k,n;
	unsigned long int gfib[41];
	scanf("%d %d",&n,&k);
	gfib[0]=0;gfib[1]=1;gfib[2]=1;
	for(i=3;i<=40;i++) {
		gfib[i]=gfib[i-1]+k*gfib[i-2];
	}	
	printf("%ld\n",gfib[n]);
	return 0;
}
