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


//prints out the topological sorting of a DAG
void top_sort(struct node *adj[], struct order *values,int NV) {
	int i;
	int max=0;
	int max_node;
	struct node *t,*s;
	//find largest post node, which is our source
	for(i=1;i<=NV;i++) {
		if(values[i].post>max) { 
			max=values[i].post;
			max_node=i;
		}
	}
	printf("%d ",max_node);
//	printf("Max node is %d, post %d\n",max_node,max);
	i=max_node;
	//DAG must always have a sink
	while(adj[i]->next!=adj[i]) {
//		printf("Searching node %d\n",i);
		t=adj[i];
		max=0;
		while(t->next!=t) {
			if(values[t->V].post>max) { 
				max=values[t->V].post;
				max_node=t->V;
			}
			t=t->next;
		}
		i=max_node;
		printf("%d ",max_node);
//		printf("Max node is %d, post %d\n",max_node,max);
}
	printf("\n");
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
	print_adj(adj,NV);
	values=pre_post(adj,NV);
	for(i=1;i<=NV;i++) {
		printf("%2d ",i);
	}
	printf("\n");
	for(i=1;i<=NV;i++) {
		printf("%2d ",values[i].pre);
	}
	printf("\n");
	for(i=1;i<=NV;i++) {
		printf("%2d ",values[i].post);
	}
	printf("\n");
	top_sort(adj,values,NV);
	return 0;
}
