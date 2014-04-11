#include <stdio.h>
#include <stdlib.h>
#define MAX_VERT 1000

struct node {
	int V;
	struct node *next;
};


void print_adj(struct node *adj[] ,int n) {
	int i=0;
	struct node *t;
	for(i=0;i<=n;i++) {
		if(adj[i]->next != adj[i]) {
			printf("%d -> ",i);
			t=adj[i];
			while(t->next != t) {
				printf("%d ",t->V);
				t=t->next;
			}
			printf("\n");
		}
	}
}

int* deg_count(struct node *adj[],int n) {
	int *deg;
	int count=0;
	int i=0;
	struct node *t;
	deg=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++) {
		if(adj[i]->next != adj[i]) {
			t=adj[i];
			count=0;
			while(t->next != t) {
				t=t->next;
				count++;
			}
			deg[i]=count;
		} else {
			deg[i]=0;
		}
	}
	return deg;
}

int* ddeg_count(struct node *adj[],int *deg,int n) {
	int *ddeg;
	int count=0;
	int i=0;
	struct node *t;
	ddeg=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++) {
		if(adj[i]->next != adj[i]) {
//			printf("%d -> ",i);
			t=adj[i];
			count=0;
			while(t->next != t) {
				count+=deg[t->V];
//				printf("%d ",t->V);
				t=t->next;
			}
			ddeg[i]=count;
		} else {
			ddeg[i]=0;
		}
//		printf("\n");
	}
	return ddeg;
}
int main() {
	struct node *END;
	int A,B;
	int c1,c2;
	//adjaceny graph
	struct node *adj[MAX_VERT+5];
	struct node *t;
	int i,j;
	int *deg;
	int *ddeg;
	int NV,NE;
	scanf("%d %d\n",&NV,&NE);
	END=(struct node*)malloc(sizeof(*END));
	END->next=END;
	//points each node to the END node
	for(i=0;i<=NV;i++) {
		adj[i]=END;
	}
	for(i=0;i<NE;i++) {
		scanf("%d %d\n",&A,&B); 
		c1=A;c2=B;
		t=(struct node*)malloc(sizeof(*t));	
		t->V=c2;t->next=adj[c1];adj[c1]=t;
		t=(struct node*)malloc(sizeof(*t));	
		t->V=c1;t->next=adj[c2];adj[c2]=t;
	}
//	print_adj(adj,NV);
	deg=deg_count(adj,NV);
	ddeg=ddeg_count(adj,deg,NV);
//	for(i=1;i<=NV;i++) {
//		printf("%d ",deg[i]);
//	}
//	printf("\n");
	for(i=1;i<=NV;i++) {
		printf("%d ",ddeg[i]);
	}
	printf("\n");
	return 0;
}
