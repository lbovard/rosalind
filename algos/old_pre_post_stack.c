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

struct order {
	int pre;
	int post;
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
void visit(int k,struct node *adj[],int id, int *val, struct stack *p,int V) { 
	struct stack *dp;
	struct order *values;
  struct stack *tempstack;
  tempstack=(struct stack*)malloc(sizeof(*tempstack));
	values=(struct order*)malloc((V+1)*sizeof(*values));
	dp=(struct stack*)malloc(sizeof(*dp));
	stackinit(V,dp);
  stackinit(V,tempstack);
	push(k,p);
	int nodes_to_explore=0;
	int *nc;
	int count=1;
	int i;
	nc=(int *)malloc((V+1)*sizeof(int));
	struct node *t;
	while(!stackempty(p)) {
		k=pop(p);
		nodes_to_explore=0;
		printf("Exploring node %d\n",k);
		val[k]=id;
		for(t=adj[k];t!=t->next;t=t->next) {
			if(val[t->V]==0) {
				printf("Added node %d\n",t->V);
        push(t->V,tempstack);
//				push(t->V,p);
				val[t->V]=1; 
				nodes_to_explore++;
			}
		}
    while(!stackempty(tempstack)) {
      push(pop(tempstack),p);
    }
		printf("There are %d nodes to explore\n",nodes_to_explore);	
		nc[k]=nodes_to_explore;
//	for(i=1;i<=V;i++){
//		printf("%d ",i);
//	}
//	printf("\n");
//	for(i=1;i<=V;i++) {
//		printf("%d ",nc[i]);
//	}
//	printf("\n");
//	printf("\n");
		if(nc[k]>0) {
			push(k,dp);
			values[k].pre=count;
			printf("pre at node %d is %d\n",k,count);
			count++;
		} else {
			printf("pre at node %d is %d\n",k,count);
			values[k].pre=count;
			printf("Reached an end point: node %d with ncount=%d\n",k,nc[k]);
  		printf("Moving back up to previous split\n");
			push(k,dp);
//			print_stack(dp);
			count++;
			while(nc[k]<2 && k>=1) { 
				k=pop(dp);
				printf("Moved up node %d\n",k);
				printf("post at node %d is %d\n",k,count);
				values[k].post=count;
				count++;
			}
			printf("\n");
			printf("Now stopping at node %d\n",k);
			push(k,dp);
//			print_stack(dp);
			nc[k]--;
			count--;
		}
			
	}
	printf("Pre and post arrays are:\n");
	for(k=1;k<=V;k++){
		printf("%d\t",k);
	}
	printf("\n");
	for(k=1;k<=V;k++) {
		printf("%d\t",values[k].pre);
	}
	printf("\n");
	for(k=1;k<=V;k++) {
		printf("%d\t",values[k].post);
	}
	printf("\n");
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
			visit(k,adj,id,val,p,V);
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
//		t=(struct node*)malloc(sizeof(*t));	
//		t->V=c1;t->next=adj[c2];adj[c2]=t;
	}
	printf("%d\n",dfs(adj,NV));

	return 0;
}
