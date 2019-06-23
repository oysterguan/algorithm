#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef union Elem{
	ElemType data;
	int length;
}Elem;
typedef struct LNode{
	Elem *e;
	struct LNode *next;
}LNode;

LNode* InitList(){
	LNode *head,*n,*p;
	head = (LNode *)malloc(sizeof(LNode));
	head->e = (Elem *)malloc(sizeof(LNode));
	head->e->length = 0;
	head->next = NULL;
	p = head;
	ElemType value;
	printf("\t\t please input the value you want to store and end by '#':");
	getchar();
	while((value=getchar())!='#'){
		n = (LNode*)malloc(sizeof(LNode));
		n->e = (Elem *)malloc(sizeof(LNode));
		n->e->data = value;
		head->e->length++;
		n->next = NULL;
		p->next = n;
		p = p->next;
	}
	printf("\t\t the linked list is initialized!\n");
	return head;
}

void IsExist(LNode *head){
	if(head==NULL){
		printf("\t\t the linked list is not exist!\n");
		exit(1);
	}
}

void DestoryList(LNode *head){
	IsExist(head);
	LNode *p;
	while(head->next != NULL){
		p = head->next;
		head->next = p->next;
		free(p->e);
		free(p);
	}
	free(head->e);
	free(head);
	printf("\t\t the linked is destoryed!\n");
}

void ClearList(LNode *head){
	IsExist(head);
	LNode *p;
	while(head->next != NULL){
		p = head->next;
		head->next = p->next;
		free(p->e);
		free(p);
	}
	head->e->length = 0;
	printf("\t\t the linked list is cleared");
}

bool ListEmpty(LNode *head){
	if(!head->next)
		return true;
	else
		return false;
}

int ListLength(LNode *head){
	IsExist(head);
	return head->e->length;
}

ElemType GetElem(LNode *head,int i){
	IsExist(head);
	ElemType e;
	LNode *p = head;
	if(i<=0 || i>head->e->length){
		printf("\t\t the parameter is not legal!\n");
		return NULL;
	}
	int j=0;
	while(j<i){
		p = p->next;
		j++;
	}
	e = p->e->data;
	return(e);
}

int LocateElem(LNode *head,ElemType x){
	IsExist(head);
	int i = 0;
	LNode *p = head;
	while(p->e->data != x && p->next != NULL){
		p = p->next;
		i++;
	}
	if(p->next){
		return i;
	}
	else{
		printf("\t\t the linked list do not have the value!\n");
		return 0;
	}
}

LNode* PriorElem(LNode *head,ElemType cur_e){
	IsExist(head);
	LNode *p = head;
	if(p->next->e->data == cur_e){
		printf("\t\t it is the first node, it don not have the prior node!\n");
		return NULL;
	}
	int Loc = LocateElem(head,cur_e)-1;
	if(Loc != 0){
		while(Loc != 0){
			p = p->next;
			Loc--;
		}1
		return p;
	}
	else{
		printf("\t\t the list do not have this value!\n");
		return NULL;
	}
}

LNode* NextElem(LNode *head,ElemType Next_e){
	IsExist(head);
	LNode *p = head;
	int Loc = LocateElem(head,Next_e)+1;
	if(Loc != 0){
		while(Loc != 0){
			p = p->next;
			Loc--;
		}
		return p;
	}
	else if(Loc == head->e->length){
		printf("\t\t it is the last node, it don not have the next node!\n");
		return NULL;
	}
	else{
		printf("\t\t the list do not have this value!\n");
		return NULL;
	}
}

void ListInsert(LNode *head,int i,ElemType e){
	IsExist(head);
	LNode *p = head->next;
	if(i<=0 || i>head->e->length){
		printf("\t\t the parameter is not legal!\n");
	}
	int j = 0;
	while(j<i){
		p = p->next;
	}
	LNode *Nnode;
	Nnode = (LNode*)malloc(sizeof(LNode));
	Nnode->next = p->next;
	p->next = Nnode;
	printf("\t\t the value insert successfully!\n");
}

ElemType ListDelete(LNode *head,int i){
	IsExist(head);
	LNode *p = head->next;
	if(i<=0 || i>head->e->length){
		printf("\t\t the parameter is not legal!\n");
	}
	int j = 0;
	while(j<i){
		p = p->next;
	}
	LNode *Dnode;
	ElemType e ;
	Dnode = p->next;
	e = Dnode->e->data;
	p->next = p->next->next;
	free(Dnode);
	printf("\t\t the value delete successfully!\n");
	return e;
}

void ListTraverse(LNode *head){
	IsExist(head);
	LNode *p = head;
	int i = 0;
	printf("\t\t");
	while(p->next != NULL){
		printf("%2c",p->next->e->data);
		p = p->next;
		if(i!=0 && i%6==0)
			printf("\n\t\t");
		++i;
	}
	printf("\t\t\n");
}

void main(){
	LNode *head = NULL;
	int choice;
	int  a;
	ElemType b;
	printf("\t\t-----------------链表--------------------------\n");
	printf("\t\t--------------1.构造单链表-----------------------\n");
	printf("\t\t--------------2.销毁单链表-----------------------\n");
	printf("\t\t--------------3.判断是否为空表-------------------\n");
	printf("\t\t--------------4.返回单链表表长-------------------\n");
	printf("\t\t--------------5.返回第i个数据元素----------------\n");
	printf("\t\t--------------6.返回数值为e的元素位置------------\n");
	printf("\t\t--------------7.返回前驱元素的数据---------------\n");
	printf("\t\t--------------8.返回后驱元素的数据---------------\n");
	printf("\t\t--------------9.将表置为空表---------------------\n");
	printf("\t\t--------------10.向i位置插入数据e----------------\n");
	printf("\t\t--------------11.删除第i个位置的元素-------------\n");
	printf("\t\t--------------12.显示表中的元素------------------\n");
	printf("\t\t please input you choice: ");
	while((scanf("%d",&choice))!=EOF){
		switch(choice){
		case 1:
			head = InitList();
			break;
		case 2:
			DestoryList(head);
			break;
		case 3:
			if(ListEmpty(head))
				printf("\t\t the list is NULL!\n");
			else
				printf("\t\t this list is not NULL!\n");
			break;
		case 4:
			printf("\t\t the length of list is %2d\n",ListLength(head));
			break;
		case 5:
			{
				printf("\t\t please input the location : ");
				scanf("%d",&a);
				printf("\t\t the value is %2c\n",GetElem(head,a));
			}
			break;
		case 6:
			{
				printf("\t\t please input the value of elem: ");
				scanf("%c",&b);
				printf("\t\t the location of the elem is %2d\n",LocateElem(head,b));
			}
			break;
		case 7:
			{
				printf("\t\t please input the elem which you want to get its prior elem: ");
				getchar();
				scanf("%c",&b);
				printf("\t\t the prior elem is %2c\n",PriorElem(head,b)->e->data);
			}
			break;
		case 8:
			{
				printf("\t\t please input the elem which you want to get its next elem: ");
				getchar();
				scanf("%c",&b);
				printf("\t\t the next elem is %2c\n",NextElem(head,a)->e->data);
			}
			break;
		case 9:
			ClearList(head);
			break;
		case 10:
			{
				printf("\t\t please input the location you want to insert: ");
				scanf("%d",&a);
				printf("\t\t please input the value you want to insert: ");
				scanf("%c",&b);
				ListInsert(head,a,b);
			}
			break;
		case 11:
			{
				printf("\t\t please input the location you want to delete: ");
				scanf("%d",&a);
				printf("\t\t the value of deleted is %2d\n",ListDelete(head,a));
			}
			break;
		case 12:
			ListTraverse(head);
			break;
		default:
			printf("\t\t input is not legal! please choose again: ");
		}
		
	printf("\t\t-----------------链表--------------------------\n");
	printf("\t\t--------------1.构造单链表-----------------------\n");
	printf("\t\t--------------2.销毁单链表-----------------------\n");
	printf("\t\t--------------3.判断是否为空表-------------------\n");
	printf("\t\t--------------4.返回单链表表长-------------------\n");
	printf("\t\t--------------5.返回第i个数据元素----------------\n");
	printf("\t\t--------------6.返回数值为e的元素位置------------\n");
	printf("\t\t--------------7.返回前驱元素的数据---------------\n");
	printf("\t\t--------------8.返回后驱元素的数据---------------\n");
	printf("\t\t--------------9.将表置为空表---------------------\n");
	printf("\t\t--------------10.向i位置插入数据e----------------\n");
	printf("\t\t--------------11.删除第i个位置的元素-------------\n");
	printf("\t\t--------------12.显示表中的元素------------------\n");
	printf("\t\t please contunie you choice: ");
	}

}