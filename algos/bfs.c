#include <stdio.h>
#define MQUEUE 1000

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
int main() { 
	struct Queue my_queue;
	queue_init(&my_queue); 
	
	return 0;
}
