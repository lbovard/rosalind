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
void visit(int k,struct node *adj[],int id, int *val, struct stack *p,int V,struct order* values) { 
	struct stack *dp;
	dp=(struct stack*)malloc(sizeof(*dp));
	stackinit(V,dp);
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
		val[k]=id;
		for(t=adj[k];t!=t->next;t=t->next) {
			if(val[t->V]==0) {
				push(t->V,p);
				val[t->V]=1; 
				nodes_to_explore++;
			}
		}
		nc[k]=nodes_to_explore;
		if(nc[k]>0) {
			push(k,dp);
			values[k].pre=count;
			count++;
		} else {
			values[k].pre=count;
			push(k,dp);
			count++;
			while(nc[k]<2 && k>=1) { 
				k=pop(dp);
				values[k].post=count;
				count++;
			}
			push(k,dp);
			nc[k]--;
			count--;
		}

	}
}
		
int dfs(struct node *adj[],int V,struct order *values) {
	int k=0;
	int id=1;
	int *val;
	struct stack *p;
	p=(struct stack*)malloc(sizeof(*p));
	stackinit(V,p);
	val=(int *)malloc((V+2)*sizeof(int));
	for(k=1;k<=V;k++) {
		if(val[k]==0) {
			visit(k,adj,id,val,p,V,values);
			id++;
		}
	}
	id--;
	return id;
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

int main() {
	struct node *END;
	int A,B;
	int c1,c2;
	struct node *adj[MAX_VERT+5];
	struct node *t;
	int i;
	int *val;
	int NV,NE;
	struct order *values;	
	int ncases;
	scanf("%d",&ncases);
	while(ncases) {
		scanf("%d %d",&NV,&NE);
		END=(struct node*)malloc(sizeof(*END));
		values=(struct order*)malloc((NV+1)*sizeof(*values));
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
		print_adj(adj,NV);
		dfs(adj,NV,values);
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

		if(isAcyclic(adj,values,NV)) {
			printf("1 ");
		} else {
			printf("-1 ");
		}
		ncases--;
	}
	printf("\n");
	//	printf("%d\n",dfs(adj,NV));


	return 0;
}
