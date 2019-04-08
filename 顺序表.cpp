#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define SQLIST_INIT_SIZE 10 //��ʼ��˳�������鳤��
#define INCREMENTSIZE 10 //��̬�����ڴ������

typedef int ElemType;
typedef struct {
	ElemType *sqList;//���������ʼ��ַ
	int length;//˳���ĳ���
	int ListSize;//��ǰ˳������󳤶�
}SqList;

void InitList(SqList *L){//��ʼ��˳���
	L->sqList = (ElemType*)malloc(SQLIST_INIT_SIZE*sizeof(ElemType));//�����ڴ����
	if(!L->sqList)
		exit(-1);
	L->length = 0;
	L->ListSize = SQLIST_INIT_SIZE;
	for(int i=0;i<10;i++){//��ʼ��˳���Ԫ��Ϊ1-10
		*(L->sqList+i) = i+1;	
		L->length++;
	}
	printf("\t\t the list is inited.\n");
}

void IsExist(SqList *L){//�ж�˳����Ƿ����
	if(L->sqList == NULL){
		printf("\t\t this list is not exist.\n");
		exit(-1);
	}
}

void DestoryList(SqList *L){//����˳���
	IsExist(L);
	free(L->sqList);
	L->ListSize = NULL;
	L->length = 0;
	L->ListSize = 0;
	printf("\t\t the list is destoryed.\n");
}

bool IsEmpty(SqList *L){//�ж��Ƿ�Ϊ��
	IsExist(L);
	if(L->length != 0)
		return false;
	else
		return true;
}

int ListLength(SqList *L){//���ر�
	IsExist(L);
	return(L->length);
}

ElemType GetElem(SqList *L,int i){//��ȡ��˳�����λ��Ϊi������Ԫ��
	IsExist(L);
	if(i<=0 || i>L->length)
		printf("\t\t the parameter is not legal.\n");
	ElemType *e;
	e = L->sqList + i - 1;
	return(*e);
}

bool compare(ElemType a,ElemType b){//�Ƚ�����Ԫ�صĺ���
	if(a == b)
		return true;
	else
		return false;
}

int LocateElem(SqList *L, ElemType e){//���ص�һ��ֵΪe������Ԫ�ص�λ��
	IsExist(L);
	ElemType *x = L->sqList;
	int i = 0;
	while(i<=L->length){
		i++;
		if(compare(*x,e)){
			return i;
		}
		else
			x = L->sqList + i;
		
	}
	return -1;
}

ElemType PriorElem(SqList *L,ElemType e){//����ǰ������Ԫ��
	IsExist(L);
	if(e==*(L->sqList)){//��һ��Ԫ����ǰ������Ԫ��
		printf("\t\t this value is the first, it do not have the prior elem.\n");
		return NULL;
	}
	int result = LocateElem(L,e);
	if(result != -1){
		ElemType *pre_e = L->sqList + result - 2;
		return(*pre_e);
	}
	else{
		printf("\t\t the list is do not exist this value.\n");
		return NULL;
	}
}

ElemType NextElem(SqList *L,ElemType e){//���غ������Ԫ��
	IsExist(L);
	if(e==*(L->sqList+L->length-1)){//���һ��Ԫ��û�к��Ԫ��
		printf("\t\t this value is the last, it do not hava the next elem.\n");
		return NULL;
	}

	int result = LocateElem(L,e);
	if(result != -1){
		ElemType *next_e = L->sqList +result;
		return(*next_e);
	}
	else{
		printf("\t\t the list is do not exist the value!\n");
		return NULL;
	}
}

void ClearList(SqList *L){//�ÿ�˳���
	IsExist(L);
	L->length = 0;
	printf("\t\t the list is cleared.\n");
}

void ListInsert(SqList *L,int i,ElemType e){//���i��λ�ò���һ��ֵΪe������Ԫ��
	IsExist(L);
	if(i<=0 || i>=L->length+1){
		printf("\t\t the parameter is not legal.\n");
		return;

	}
	if(L->length == L->ListSize){//�ж�˳�����ڴ�ռ��Ƿ�����
		printf("\t\t run out of memory,is reallocating.\n");
		ElemType *newBase;
		newBase = (ElemType *)realloc(L->sqList,(SQLIST_INIT_SIZE+INCREMENTSIZE)*sizeof(ElemType));//��̬�����ڴ�ռ�
		L->sqList = newBase;
		printf("\t\t the memory reallocate successfully!\n");
	}
	int j = L->length;
	while(j!=i){
		*(L->sqList+j) = *(L->sqList+j-1);
		j--;
	}
	*(L->sqList+i-1) = e;
	++L->length;
	printf("\t\t insert successfully!\n");
}

ElemType ListDelete(SqList *L,int i){//ɾ����i��λ�õ�����Ԫ��
	IsExist(L);
	if(i<=0 || i>L->length){
		printf("\t\t the parameter is not legal.\n");
		return NULL;
	}
	int j = i;
	ElemType e = *(L->sqList+i-1); 
	while(j!=L->length){
		*(L->sqList+j-1) = *(L->sqList+j);
		j++;
	}
	--L->length;
	printf("\t\t delete sucessfully!\n");
	return e;
}

void ListTraverse(SqList *L){//����˳���
	IsExist(L);
	for(int i=0;i<L->length;i++){
		printf("\t\t%3d",*(L->sqList+i));
		if(i!=0 &&i % 6==0)
			printf("\n");
	}
	printf("\n");
}

void main(){
	int choice;
	int  a,b;
	SqList *L;
	L = (SqList*)malloc(sizeof(SqList));
	printf("\t\t-----------------˳���--------------------------\n");
	printf("\t\t--------------1.����˳���-----------------------\n");
	printf("\t\t--------------2.����˳���-----------------------\n");
	printf("\t\t--------------3.�ж��Ƿ�Ϊ�ձ�-------------------\n");
	printf("\t\t--------------4.����˳����-------------------\n");
	printf("\t\t--------------5.���ص�i������Ԫ��----------------\n");
	printf("\t\t--------------6.������ֵΪe��Ԫ��λ��------------\n");
	printf("\t\t--------------7.����ǰ��Ԫ�ص�����---------------\n");
	printf("\t\t--------------8.���غ���Ԫ�ص�����---------------\n");
	printf("\t\t--------------9.������Ϊ�ձ�---------------------\n");
	printf("\t\t--------------10.��iλ�ò�������e----------------\n");
	printf("\t\t--------------11.ɾ����i��λ�õ�Ԫ��-------------\n");
	printf("\t\t--------------12.��ʾ���е�Ԫ��------------------\n");
	printf("\t\t please input you choice: ");
	while((scanf("%d",&choice))!=EOF){
		switch(choice){
		case 1:
			InitList(L);
			break;
		case 2:
			DestoryList(L);
			break;
		case 3:
			if(IsEmpty(L))
				printf("\t\t the list is NULL!\n");
			else
				printf("\t\t this list is not NULL!\n");
			break;
		case 4:
			printf("\t\t the length of list is %2d\n",ListLength(L));
			break;
		case 5:
			{
				printf("\t\t please input the value of the location: ");
				scanf("%d",&a);
				printf("\t\t the value is %2d\n",GetElem(L,a));
			}
			break;
		case 6:
			{
				printf("\t\t please input the value of elem: ");
				scanf("%d",&a);
				printf("\t\t the location of the elem is %2d\n",LocateElem(L,a));
			}
			break;
		case 7:
			{
				printf("\t\t please input the elem which you want to get its prior elem: ");
				scanf("%d",&a);
				printf("\t\t the prior elem is %2d\n",PriorElem(L,a));
			}
			break;
		case 8:
			{
				printf("\t\t please input the elem which you want to get its next elem: ");
				scanf("%d",&a);
				printf("\t\t the next elem is %2d\n",NextElem(L,a));
			}
			break;
		case 9:
			ClearList(L);
			break;
		case 10:
			{
				printf("\t\t please input the location you want to insert: ");
				scanf("%d",&a);
				printf("\t\t please input the value you want to insert: ");
				scanf("%d",&b);
				ListInsert(L,a,b);
			}
			break;
		case 11:
			{
				printf("\t\t please input the location you want to delete: ");
				scanf("%d",&a);
				printf("\t\t the value of deleted is %2d\n",ListDelete(L,a));
			}
			break;
		case 12:
			ListTraverse(L);
			break;
		default:
			printf("\t\t input is not legal! please choose again: ");
		}
		
	printf("\t\t-----------------˳���--------------------------\n");
	printf("\t\t--------------1.����˳���-----------------------\n");
	printf("\t\t--------------2.����˳���-----------------------\n");
	printf("\t\t--------------3.�ж��Ƿ�Ϊ�ձ�-------------------\n");
	printf("\t\t--------------4.����˳����-------------------\n");
	printf("\t\t--------------5.���ص�i������Ԫ��----------------\n");
	printf("\t\t--------------6.������ֵΪe��Ԫ��λ��------------\n");
	printf("\t\t--------------7.����ǰ��Ԫ�ص�����---------------\n");
	printf("\t\t--------------8.���غ���Ԫ�ص�����---------------\n");
	printf("\t\t--------------9.������Ϊ�ձ�---------------------\n");
	printf("\t\t--------------10.��iλ�ò�������e----------------\n");
	printf("\t\t--------------11.ɾ����i��λ�õ�Ԫ��-------------\n");
	printf("\t\t--------------12.��ʾ���е�Ԫ��------------------\n");
	printf("\t\t please contunie you choice: ");
	}

}