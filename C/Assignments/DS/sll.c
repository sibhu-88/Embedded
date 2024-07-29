//SINGLE LINKED LIST
#include<stdio.h>
#include<stdlib.h>

typedef struct ds{
	int data;
	struct ds *nxt;
} DS;

void add_begin(DS **);
void add_middle(DS **);
void add_end(DS **);
void delete(DS **,int);
void print(DS *);
void save(DS *);

int main()
{
    char op;
    DS *hptr = 0;
	system("clear");
    do
    {
//        add_begin(&hptr);
//        add_end(&hptr);
        add_middle(&hptr);

       printf("Do you want enter the data again Yes(y or Y) or No(n or N) :");
        scanf(" %c", &op);
    } while ((op == 'y') | (op == 'Y'));

    print(hptr);
    save(hptr);

	int n;
printf("Enter the delete num : ");
scanf("%d",&n);
    delete(&hptr,n);
    print(hptr);
}

void add_begin(DS **ptr){
	DS *temp =(DS *)malloc(sizeof(DS));
	printf("Enter the data : ");
	scanf("%d",&temp->data);

	temp->nxt=*ptr;
	*ptr=temp;
}

void add_middle(DS **ptr){
	DS *temp =(DS *)malloc(sizeof(DS));
	printf("Enter the data : ");
	scanf("%d",&temp->data);

	DS *last =*ptr;
	if((*ptr==0) || (temp->data < (*ptr)->data)){
		temp->nxt=*ptr;
		*ptr=temp;
	}else{
		while((last->nxt!=0)&&((last->nxt->data) < temp->data)) last=last->nxt;
		temp->nxt=last->nxt;
		last->nxt=temp;
        }
}

void add_end(DS **ptr){
	DS *temp =(DS *)malloc(sizeof(DS));
	printf("Enter the data : ");
	scanf("%d",&temp->data);

	DS *last =*ptr;
	if(*ptr==0){
		temp->nxt=*ptr;
		*ptr=temp;
	}else{
		while(last->nxt!=0) last=last->nxt;
		temp->nxt=last->nxt;
		last->nxt=temp;
        }
}

void delete(DS **ptr,int n){
	DS *prv,*temp=*ptr;

	while(temp!=0){
		if(temp->data==n){
		if(temp==*ptr) *ptr=temp->nxt;
		else prv->nxt=temp->nxt;

		free(temp);
		temp=NULL; return;
		}else{
			prv=temp;
			temp=temp->nxt;
		}
	}
	printf("the data doesn't match\n");

}

void print(DS *ptr){
	int i=0;
	while(ptr!=NULL){
		printf("%d -> %d\n",i++,ptr->data);
		ptr=ptr->nxt;
	}
}

void save(DS *ptr){
	FILE *fp = fopen("data.txt","w");
	while(ptr != 0){
		fprintf(fp,"%p -> %d\n",ptr,ptr->data);
		ptr=ptr->nxt;
	}
}
