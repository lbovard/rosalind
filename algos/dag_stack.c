#include <stdio.h>
#include <stdlib.h>
#define MAX_VERT 1000

struct node {
	int V;
	struct node *next;
	int pre;
	int post;
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

int head(struct stack *p) {
  int k=p->top;
  return p->st[k-1];
}

int stack_length(struct stack *p) {
  return p->top;
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
		
void pre_post(struct node *adj[],int V) {
	struct stack *dp,*p;
	struct node *t;
	int k=0,id=1,count=1,nodes_to_explore=0;
	int *val,*nc;
	val=(int *)malloc((V+2)*sizeof(int));
	p=(struct stack*)malloc(sizeof(*p));
	dp=(struct stack*)malloc(sizeof(*dp));
	nc=(int *)malloc((V+1)*sizeof(int));
	stackinit(V,p);
	stackinit(V,dp);
	for(k=1;k<=V;k++) {
		if(val[k]==0) {
			push(k,p);
			while(!stackempty(p)) {
				k=pop(p);
				nodes_to_explore=0;
				if(val[k]==0) {
					adj[k]->pre=count;
					val[k]=id; 
					for(t=adj[k];t!=t->next;t=t->next) {
						if(val[t->V]==0) {
							push(t->V,p);
							nodes_to_explore++;
						}

					}
					nc[k]=nodes_to_explore; 
					push(k,dp); 
					count++;
					/*this is black magic! keeps a stack of visited nodes
					keep track of how many nodes are connected
					and backtrack to previous split */
					if(nodes_to_explore==0 && stack_length(dp)>1) { 
						k=pop(dp);
						adj[k]->post=count;
						count++;
						k=pop(dp);
						while(nc[k]<2 && !stackempty(dp)) { 
							adj[k]->post=count;
							count++;
							k=pop(dp);
						}
						push(k,dp);
						nc[k]--;
					}
				}
			}
			while(!stackempty(dp)) {
				adj[head(dp)]->post=count;
				count++;
				k=pop(dp); 
			}
			id++;
		}
	}
	id--;
}

int isAcyclic(struct node *adj[],int NV) {
	int i=0;
	int pre_u,pre_v,post_u,post_v;
	struct node *t;
	for(i=1;i<=NV;i++) {
		t=adj[i];
		pre_u=adj[i]->pre;
		post_u=adj[i]->post;
		pre_v=adj[t->V]->pre;
		post_v=adj[t->V]->post;
		while(t->next != t) {
			if(pre_v< pre_u && post_u < post_v) {
				return 0;
			}
			t=t->next;
			pre_v=adj[t->V]->pre;
			post_v=adj[t->V]->post;
		}
	}
	return 1;	
}

int main() {
  struct node *END,*t;
  int A,B;
  int c1,c2;
  struct node *adj[MAX_VERT+5];
  int i;
  int *val;
  int NV,NE;
  int ncases;
  scanf("%d",&ncases);
  while(ncases) {
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
    }
    pre_post(adj,NV);
    if(isAcyclic(adj,NV)) {
      printf("1 ");
    } else {
      printf("-1 ");

    }
    ncases--;
  }
  printf("\n");
  return 0;
}

