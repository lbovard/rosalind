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
void previsit(int V) {
}
void postvisit(int V) {
}
//explore all the nodes connected to node V using a recursive-DFS
void explore(int V, int* visited, struct node *adj[],int id) {
	struct node *t;
	//state what connected component the node is in
	visited[V]=id;
	previsit(V); 
	//visit all nodes connected to node V
	for(t=adj[V];t!=t->next;t=t->next) {
		if(visited[t->V]==0) {
			explore(t->V,visited,adj,id);
		}
	}	
	postvisit(V);
}


//computes the number of connected components
int numConnected(struct node *adj[], int NV) {
	int k;
	int *visited;
	int connected_component_id=1;
	visited=(int *)malloc((NV+1)*sizeof(int));
	//iterate over all nodes
	for(k=1;k<=NV;k++) {
		//if we haven't visited node yet, explore it
		if(visited[k]==0) {
			//explore all nodes connected to node k
			explore(k,visited,adj,connected_component_id);
			//we have visited all nodes in this connected component
			//increase the number of connected components
			connected_component_id++;
		}
	}
	//we overcounted 
	connected_component_id--;
	return connected_component_id;
}
int main() {
	struct node *END;
	int A,B;
	int c1,c2;
	//adjaceny graph
	struct node *adj[MAX_VERT+5];
	struct node *t;
	int i,j;
	int *visited;
	int NV,NE;
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
	printf("%d\n",numConnected(adj,NV));
	
	return 0;
}
