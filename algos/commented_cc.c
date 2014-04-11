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
//		if(adj[i]->next != adj[i]) {
			printf("%d -> ",i);
			t=adj[i];
			while(t->next != t) {
				printf("%d ",t->V);
				t=t->next;
			}
			printf("%p\n",adj[i]);
//			printf("\n");
//		}
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
	//	printf("Greetings from node %d\n",k);
	//	printf("%d\n",++(*id));
	push(k,p);
	printf("Put node %d on the stack \n",k);
	struct node *t;
	while(!stackempty(p)) {
		k=pop(p);
	
		printf("Popped node %d off the stack \n",k);
		val[k]=id;
//		print_stack(p);
		for(t=adj[k];t!=t->next;t=t->next) {
			if(val[t->V]==0) {
				push(t->V,p);
				printf("Put node %d on the stack \n",t->V);
				val[t->V]=-1; 
			}
			//		printf("\n");
		}
	}
}
		
int dfs(struct node *adj[],int V) {
	int k=0;
	int id=0;
	int *val;
	struct stack *p;
	p=(struct stack*)malloc(sizeof(*p));
	stackinit(V,p);
	val=(int *)malloc((V+2)*sizeof(int));
	for(k=1;k<=V;k++) {
		printf("%d ",val[k]);
	}
	printf("\n");
	id=1;
	for(k=1;k<=V;k++) {
		if(val[k]==0) {
			printf("Beginning visit of node %d\n",k);
			printf("This is the start of a connected component\n");
			visit(k,adj,id,val,p);
			id++;
		}
	}
	for(k=1;k<=V;k++) {
		printf("%d ",k);
	}
	printf("\n");
	for(k=1;k<=V;k++) {
		printf("%d ",val[k]);
	}
	printf("\n");
	id--;
	printf("%d\n",id);
	return id;
}


int main() {
	struct node *END;
	int A,B;
	int c1,c2;
	//adjaceny graph
	struct node *adj[MAX_VERT+5];
	struct node *t;
	int i;
	int *val;
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
	print_adj(adj,NV);
	printf("%d\n",dfs(adj,NV));
	return 0;
}
