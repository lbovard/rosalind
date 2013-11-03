#include <stdio.h>
#include <string.h>

//naive quadratic search
//could use KMP but max size
//is 1k so no point
int main() {
	char s[1000+1];
	char t[1000+1];
	int ss,ts;
	int i,j;
	scanf("%s",s);
	scanf("%s",t);
	ss=strlen(s);
	ts=strlen(t);
	for(i=0;i<(ss-ts);i++) {
		j=0;
		while(t[j]==s[i+j] && j<ts) {
			j++;
		}
		//+1 because array indexing starts at 0	
		if(j==ts) printf("%d ",i+1);
	}
		
	printf("\n");
	
	return 0;
}
