//stack implimentation using circular Queue 

#include<stdio.h>
#define max 5
int en,f1=0,r1=0,c1=0,f2=0,r2=0,c2=0,*f,*r,*c,val;
int que1[max],que2[max],stk[max];
int enq(),deq(),isE(),isF(),pop(),push();
int main(){
	int z,i;
	printf("1-pop\n2-push\n");
	while(1){
		printf("enter your choice: ");
		scanf("%d",&z);
		switch(z){
			case 1:
				//pop
				printf("pop val: %d\n",pop());
				break;
			case 2:
				//push
				printf("enter value to push: ");
				scanf("%d",&val);
				push(val);
				break;
			case 3:
				printf("size is : c%d f%d r%d\n",c1,f1,r1);
				printf("size is : c%d f%d r%d\n",c2,f2,r2);
				for(i=0;i<c1;i++){
					printf(" %d ",que1[i]);
				}
				for(i=0;i<c2;i++){
					printf(" _%d ",que2[i]);
				}
				break;
		}
	}
/*	printf("1-enqueue\n2-dequeue\n3-peek\n4-size\n5-isEmpty\n6-isFull\n\n");
	int z;
	while(1){
		printf("enter your choice: ");
		scanf("%d",&z);
		switch(z){
			case 1:
				printf("enter number to enqueue: ");
				scanf("%d",&en);
				enq(en,&que1,&f1,&r1,&c1);
				break;
			case 2:
				printf("val = %d\n",deq(&que1,&f1,&r1,&c1));
				break;
			case 3:
//				printf("front value: %d\n",front());
				break;
			case 4:
				printf("size is : c%d f%d r%d\n",c1,f1,r1);
				break;
			case 5:
				if(isE(&c1)){
					printf("queue is empty\n");
				}
				else{
					printf("queue is not empty\n");
				}
				break;
			case 6:
				if(isF(&c1)){
					printf("queue is full\n");
				}
				else{
					printf("queue is not full\n");
				}
				
				break;			
		}
	}
*/

	return 0;
}
int pop(){
	int i,temp,tempc;
	if(!isE(&c1)){
	//	printf("queue is not empty\n");
		tempc=c1;
		for(i=1;i<tempc;i++){
			temp = deq(&que1,&f1,&r1,&c1);
			enq(temp,&que2,&f2,&r2,&c2);
	//		printf("\n%d q1 f %d, r %d, c %d\t q2 f %d, r %d, c %d\n",i,f1,r1,c1,f2,r2,c2);
		}
		temp = deq(&que1,&f1,&r1,&c1);
		return temp;
	}
	else if(!isE(&c2)){
	//	printf("queue is not empty\n");
		tempc=c2;
		for(i=1;i<tempc;i++){
			temp = deq(&que2,&f2,&r2,&c2);
			enq(temp,&que1,&f1,&r1,&c1);
	//		printf("\n%d q1 f %d, r %d, c %d\t q2 f %d, r %d, c %d\n",i,f1,r1,c1,f2,r2,c2);
		}
		temp = deq(&que2,&f2,&r2,&c2);
	
		return temp;
	}
	else{
		printf("stack is empty\n");
		return 0;
	}
}
int push(int val){
	if(isE(&c1)){
	//	printf("queue is empty\n");
		enq(val,&que2,&f2,&r2,&c2);
	}
	else{
	//	printf("queue is not empty\n");
		enq(val,&que1,&f1,&r1,&c1);
	}

}


int isF(int *c){
	if (*c==max){
		return 1;
	}
	else{
		return 0;
	}
}
int isE(int *c){
	if (*c==0){
		return 1;
	}
	else{
		return 0;
	}
}

int enq(int en,int *que,int *f,int *r,int *c){
	if(isF(c)){
		printf("que is full\n");
	}
	else{
		que[*r]=en;
		*r=(*r+1)%max;
		*c=*c+1;
	}	
}
int deq(int *que,int *f,int *r,int *c){

	if(isE(c)){
		printf("queue is empty\n");
	}
	else{
		int x=que[*f];
		*f=(*f+1)%max;
		*c=*c-1;
		return  x;
	}
}

