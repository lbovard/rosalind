#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct suffix{
	int size;
	int nwords;
	char ar[1005];
};

void print_suffix(struct suffix* tbp) {
	int i=0;
	int size=tbp->size;
	for(i=0;i<size;i++) {
		printf("%c",tbp->ar[i]);
	}
	printf("\n");
}
//lcp array construct
void lcp_construct(char* A,int* pos,int* height, int n) {
	static int rank[1005];
	int i,h,k=0;
	for(i=0;i<=n;i++) {
		rank[pos[i]]=i;
	}
	h=0;
	for(i=0;i<=n;i++) {
		if(rank[i]>0) {
			k=pos[rank[i]-1];
			while(A[i+h]==A[k+h]) {
				h++;
			}
			height[rank[i]]=h;
			if(h>0) {
				h--;
			}
		}
	}
}

int lcp_two(struct suffix* first, struct suffix* second) {
	int i=0;
	while(first->ar[i]==second->ar[i]) {
		i++;
	}
	if(i>0) {
		if(first->ar[i-1]=='$') i--;
	}
	return i;
}
//int cmp(const struct suffix* a,const struct suffix* b) {
inline static int cmp(const void* a,const void* b) {
	const struct suffix* a1=a;
	const struct suffix* b1=b;
	return strcmp(a1->ar,b1->ar) < 0 ? -1 : 1 ;
}

int main() {
	struct suffix suffixes[1005];
	char A[1005];
	int pos[1005],lcp[1005],nw[1005];
	int *group, *group_bool;
	int start,end,min,global_max,global_index;
	int nwords=1,max_words;
	char c;
	int i=0,len=0;
	int j=0,k=0;
	int sum=0;
	nwords=1;
	c=getchar_unlocked();
	while(c!='\n') {
		suffixes[i].size=i+1;
		if(c=='$') nwords++;
		A[i]=c;
		c=getchar_unlocked();
		i++;
	}
	max_words=nwords;
	suffixes[i].size=i+1;
	A[i]='$';
	strcpy(suffixes[i].ar,A); 
	len=i; 
	nwords=1;
	for(j=0;j<=len;j++) {
		for(k=j;k<=len;k++) {
			suffixes[i].ar[k-j]=A[k];
			suffixes[i].nwords=max_words+1-nwords;
		}
		if(suffixes[i].ar[0]=='$') nwords++;
		i--;
	}
	
	qsort(suffixes,len+1,sizeof(struct suffix),cmp);

	for(i=0;i<=len;i++) {
		pos[i]=len+1-suffixes[i].size;
		nw[i]=suffixes[i].nwords;
	}

	group=(int *)malloc((max_words+1)*sizeof(int));
	group_bool=(int *)malloc((max_words+1)*sizeof(int));

	for(i=0;i<=max_words;i++) {
		group[i]=0;
		group_bool[i]=0;
	}
	global_max=0;global_index=0;
	start=max_words;
	end=start;		
	while(start<=len && end<=len) {
		sum=0;
		for(i=1;i<=max_words;i++) {
			sum+=group_bool[i];
		}
		while(sum!=max_words) {
			if(group_bool[nw[end]]==0) {
				group_bool[nw[end]]=1;
				sum++;
			}
			group[nw[end]]++;
			end++;
		}	
		end--;
		min=lcp_two(&suffixes[start],&suffixes[end]);
		if(min>global_max) {
			global_max=min;
			global_index=start;
		}
		while(sum==max_words) {
			group[nw[start]]--;
			if(group[nw[start]]==0) {
				group_bool[nw[start]]=0;
				sum--;
			}
			start++;
			if(sum==max_words) {
				min=lcp_two(&suffixes[start],&suffixes[end]);
				if(min>global_max) {
					global_max=min;
					global_index=start;
				}
			}
		}
		end++;
	}	
	printf("The longest common substring (not unique)\n");
	for(i=0;i<global_max;i++) {
		printf("%c",suffixes[global_index].ar[i]);
	}
	printf("\n");
	return 0;
}
