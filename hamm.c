#include <stdio.h>
#define MAX_LEN 1000

int main() {
	char a;
	char base[MAX_LEN];
	int i=0;
	int j;
	int tot=0;
	a=getchar();
	while(a!='\n') {
		base[i]=a;
		a=getchar();
		i++;
	}
	a=getchar();
	i=0;
	while(a!='\n') {
		if(a!=base[i]) tot++;
		a=getchar();
		i++;
	}
	printf("%d\n",tot);
	return 0;
}
