#include <stdio.h>
#include <stdlib.h>
#define MAX_VERT 1000
struct node {
	int V;
	struct node *next;
};

struct order {
	int pre;
	int post;
};
void print_adj(struct node *adj[] ,int n) {
	int i=0;
	struct node *t;
	for(i=1;i<=n;i++) {
		printf("%d -> ",i);
		t=adj[i];
		while(t->next != t) {
			printf("%d ",t->V);
			t=t->next;
		}
		printf("\n");
	}
}
//explore all the nodes connected to node V using a recursive-DFS
void explore(int V, int* visited, struct node *adj[],struct order *vals,int *count,int colour,int *c,int parent,int *isbi) {
	struct node *t;
	//state what connected component the node is in
	visited[V]=1;
	vals[V].pre=*count;
//	printf("Node %d color %d\t parent %d, colour: %d\n",V,colour,parent,c[parent]);
	(*count)++;
	//visit all nodes connected to node V
	c[V]=colour;
	colour=!colour;
	for(t=adj[V];t!=t->next;t=t->next) {
		if(visited[t->V]==0) {
//			printf("Exploring edge %d %d\n",V,t->V);
			explore(t->V,visited,adj,vals,count,colour,c,V,isbi);
		} else if(c[t->V]==c[V]) {
//			printf("Node %d and Node %d share colour\n",t->V,V);
			*isbi=0;
		}
	}	
	vals[V].post=*count;
	(*count)++;
	return;
}

//computes the number of connected components
struct order* pre_post(struct node *adj[], int NV) {
	int k;
	int *visited;
	struct order* values;
	int *c;
	int count=1;
	int colour=0;
	int isbi=1;
	values=(struct order*)malloc((NV+1)*sizeof(*values));
	visited=(int *)malloc((NV+1)*sizeof(int));
	c=(int *)malloc((NV+1)*sizeof(int));
	//iterate over all nodes
	for(k=1;k<=NV;k++) {
		//if we haven't visited node yet, explore it
		if(visited[k]==0) {
			c[k]=-1;
			//explore all nodes connected to node k
			explore(k,visited,adj,values,&count,colour,c,k,&isbi);
		}
	}
	if(isbi==0)  
		printf("-1 ");
	else 
		printf("1 ");
	//we overcounted 
	return values;
}
int main() {
	struct node *END;
	int A,B;
	int c1,c2;
	//adjaceny graph
	struct node *adj[MAX_VERT+5];
	struct node *t;
	struct order *values;
	int i,j;
	int *visited;
	int NV,NE;
	int ncases;
	scanf("%d",&ncases);
	while(ncases) {
		scanf("%d %d",&NV,&NE);
		END=(struct node*)malloc(sizeof(*END));
		END->next=END;
		//points each node to the END node
		for(i=0;i<=NV;i++) {
			adj[i]=END;
		}
		for(i=0;i<NE;i++) {
			scanf("%d %d",&A,&B); 
			c1=A;c2=B;
			t=(struct node*)malloc(sizeof(*t));	
			t->V=c2;t->next=adj[c1];adj[c1]=t;
			t=(struct node*)malloc(sizeof(*t));	
			t->V=c1;t->next=adj[c2];adj[c2]=t;
		}
		//	print_adj(adj,NV);
		values=pre_post(adj,NV);
//		printf("\n");
		ncases--;
	}	
	printf("\n");
	return 0;
}
