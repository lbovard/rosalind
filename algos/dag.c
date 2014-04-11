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
void explore(int V, int* visited, struct node *adj[],struct order *vals,int *count) {
	struct node *t;
	//state what connected component the node is in
	visited[V]=1;
	vals[V].pre=*count;
	(*count)++;
	//visit all nodes connected to node V
	for(t=adj[V];t!=t->next;t=t->next) {
		if(visited[t->V]==0) {
			explore(t->V,visited,adj,vals,count);
		}
	}	
	vals[V].post=*count;
	(*count)++;
}

//using pre,post ordering, determine whether there is a back edge
int isAcyclic(struct node *adj[],struct order *vals,int NV) {
	int i=0;
	int pre_u,pre_v,post_u,post_v;
	struct node *t;
	for(i=1;i<=NV;i++) {
		t=adj[i];
		pre_u=vals[i].pre;
		post_u=vals[i].post;
		pre_v=vals[t->V].pre;
		post_v=vals[t->V].post;
		while(t->next != t) {
//			printf("Checking nodes %d and %d\n",i,t->V);
//			printf("u:(%d,%d) \t v:(%u,%u)\n",pre_u,post_u,pre_v,post_v);
			//the condition for a back edge
			if(pre_v< pre_u && post_u < post_v) {
//				printf("Back edge found. Graph is cyclic.\n");
				return 0;
			}
			t=t->next;
			pre_v=vals[t->V].pre;
			post_v=vals[t->V].post;
		}
	}
	return 1;	
}

//computes the number of connected components
struct order* pre_post(struct node *adj[], int NV) {
	int k;
	int *visited;
	struct order* values;
	int count=1;
	values=(struct order*)malloc((NV+1)*sizeof(*values));
	visited=(int *)malloc((NV+1)*sizeof(int));
	//iterate over all nodes
	for(k=1;k<=NV;k++) {
		//if we haven't visited node yet, explore it
		if(visited[k]==0) {
			//explore all nodes connected to node k
			explore(k,visited,adj,values,&count);
		}
	}
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
		}
		//	print_adj(adj,NV);
		values=pre_post(adj,NV);
//		for(i=1;i<=NV;i++) {
//			printf("%2d ",i);
//		}
//		printf("\n");
//		for(i=1;i<=NV;i++) {
//			printf("%2d ",values[i].pre);
//		}
//		printf("\n");
//		for(i=1;i<=NV;i++) {
//			printf("%2d ",values[i].post);
//		}
//		printf("\n");

//		printf("Checking cyclic\n");
		if(isAcyclic(adj,values,NV)) {
			printf("1 ");
		} else {
			printf("-1 ");
		}
//		printf("\n");
		ncases--;
	}	
	printf("\n");
	return 0;
}
