#include <stdio.h>
#include <stdlib.h>
#define MAX_VERT 1000

struct node {
	int V;
	struct node *next;
};

struct stack{ 
	int top;
	int size;
	int *st;
};

void stackinit(int msize, struct stack *p) {
	p->top=0;
	p->size=msize;
	p->st = (int *)malloc((msize+5)*sizeof(int));
}

void push(int value,struct stack *p) {
	p->st[p->top]=value;
	p->top++;
}

int pop(struct stack *p) {
	p->top--;
	return p->st[p->top];
}

void print_stack(struct stack *p) {
	int i=0;
	for(i=0;i<p->top;i++) {
		printf("%d ",p->st[i]);
	}
	printf("\n");
}
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

int stackempty(struct stack *p) {
	if(p->top ==0) {
		return 1;
	} else {
		return 0;
	}
}
void visit(int k,struct node *adj[],int id, int *val, struct stack *p) { 
	printf("Pushed %d onto stack\n",k);
	push(k,p);
	struct node *t;
	while(!stackempty(p)) {
		k=pop(p);
		printf("Popped %d from stack\n",k);
//		printf("Visting node %d\n",k);
		val[k]=id; //set which component node is in
		for(t=adj[k];t!=t->next;t=t->next) {
//			printf("Visiting node %d starting at node %d\n",t->V,k);
			if(val[t->V]==0) {
				push(t->V,p);
				printf("Pushed %d onto stack\n",t->V);
				val[t->V]=-1; 
			}
		}
//		printf("Finished visiting node %d\n",k);
	}
}
		
int dfs(struct node *adj[],int V) {
	int k=0;
	int id=1;
	int *val;
	struct stack *p;
	p=(struct stack*)malloc(sizeof(*p));
	stackinit(V,p);
	val=(int *)malloc((V+2)*sizeof(int));
	for(k=1;k<=V;k++) {
		if(val[k]==0) {
			visit(k,adj,id,val,p);
			id++;
		}
	}
	id--;
	return id;
}


int main() {
	struct node *END;
	int A,B;
	int c1,c2;
	struct node *adj[MAX_VERT+5];
	struct node *t;
	int i;
	int *val;
	int NV,NE;
	scanf("%d %d",&NV,&NE);
	END=(struct node*)malloc(sizeof(*END));
	END->next=END;
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
	i=dfs(adj,NV);
	printf("Number of connected components\n");
	printf("%d\n",i);

	return 0;
}
