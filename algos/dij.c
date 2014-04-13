#include <stdio.h>
#include <stdlib.h>
#define MQUEUE 1000
#define MAX_VERT 1000

struct node {
	int V;
	struct node *next;
  int value;
};
struct Queue {
	int head;
	int tail;
	int list[MQUEUE];
};

void put(struct Queue *q,int f){
	q->list[q->tail]=f;
	q->tail++;
	if(q->tail >= MQUEUE) q->tail =0;
}

int get(struct Queue *q) {
	int t=q->list[q->head];
	q->head++;
	if(q->head >= MQUEUE) q->head =0;
	return t;
}

void queue_init(struct Queue *q) {
	q->head=0;	
	q->tail=0;
}

int queueempty(struct Queue *q) {
	return q->head == q->tail;
}	

void print_queue(struct Queue *q) {
	int i=q->head;
	if(i>q->tail) {
		for(i;i<MQUEUE;i++) {
			printf("%d ",q->list[i]);
		}
		for(i=0;i<q->tail;i++) {
			printf("%d ",q->list[i]);
		}
	} else if(q->tail == q->head) {
		printf("-");
	} else {
		for(i;i<q->tail;i++) {
			printf("%d ",q->list[i]);
		}
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
			printf("%d (%d),  ",t->V,t->value);
			t=t->next;
		}
		printf("\n");
	}
}
void bfs(struct node *adj[], int V,int k) {
  struct node *t;
  struct Queue *q;
  int *dist;
  int i;
  dist=(int *)malloc((V+1)*sizeof(int));
  q=(struct Queue*)malloc(sizeof(*q));
  for(i=0;i<=V;i++) dist[i]=-1;
  queue_init(q);
  put(q,k);
  dist[k]=0;
  while(!queueempty(q)) {
    k=get(q); 
    for(t=adj[k];t!=t->next;t=t->next) { 
      if(dist[t->V]==-1) {
        put(q,t->V);
        dist[t->V]=dist[k]+1;
      }
    }
  } 

  for(i=1;i<=V;i++) {
    printf("%d ",dist[i]);
  }
  printf("\n");
}
int main() {
  struct node *END,*t;
  int A,B,C;
  struct node *adj[MAX_VERT+5];
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
    scanf("%d %d %d",&A,&B,&C); 
    t=(struct node*)malloc(sizeof(*t));	
    t->V=B;t->next=adj[A];t->value=C;
    adj[A]=t;
  }
  print_adj(adj,NV);
  bfs(adj,NV,1);
  return 0;
}
