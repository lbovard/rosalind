#include <stdio.h>

//recurrence is
// t(n) = t(n-1)+t(n-2) - t(n-k-1)
// where k is the numbers of months they die
// note that if n=k+1 then we should define t(0) =1
int main() {
	int n,m;
	unsigned long int rabbits[100+1];
	scanf("%d %d",&n,&m);
	int i;
	//easier to define 0 to be 1 not 0
	rabbits[0]=1;
	rabbits[1]=1;
	rabbits[2]=1;	
	for(i=3;i<m+1;i++) {
//		printf("%d %d %d\n",i,i-1,i-2);
		rabbits[i]=rabbits[i-1]+rabbits[i-2];
	}
	for(i=m+1;i<=n;i++) {
//		printf("%d %d %d %d\n",i,i-1,i-2,i-m-1);
		rabbits[i]=rabbits[i-1]+rabbits[i-2] - rabbits[i-m-1];
	}
	for(i=1;i<=n;i++) {
		printf("%lu ",rabbits[i]);
	}
	printf("\n");
	return 0;
}
