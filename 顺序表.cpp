#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define SQLIST_INIT_SIZE 10 //初始化顺序表的数组长度
#define INCREMENTSIZE 10 //动态分配内存的增量

typedef int ElemType;
typedef struct {
	ElemType *sqList;//数据数组初始地址
	int length;//顺序表的长度
	int ListSize;//当前顺序表的最大长度
}SqList;

void InitList(SqList *L){//初始化顺序表
	L->sqList = (ElemType*)malloc(SQLIST_INIT_SIZE*sizeof(ElemType));//连续内存分配
	if(!L->sqList)
		exit(-1);
	L->length = 0;
	L->ListSize = SQLIST_INIT_SIZE;
	for(int i=0;i<10;i++){//初始化顺序表元素为1-10
		*(L->sqList+i) = i+1;	
		L->length++;
	}
	printf("\t\t the list is inited.\n");
}

void IsExist(SqList *L){//判断顺序表是否存在
	if(L->sqList == NULL){
		printf("\t\t this list is not exist.\n");
		exit(-1);
	}
}

void DestoryList(SqList *L){//销毁顺序表
	IsExist(L);
	free(L->sqList);
	L->ListSize = NULL;
	L->length = 0;
	L->ListSize = 0;
	printf("\t\t the list is destoryed.\n");
}

bool IsEmpty(SqList *L){//判断是否为空
	IsExist(L);
	if(L->length != 0)
		return false;
	else
		return true;
}

int ListLength(SqList *L){//返回表长
	IsExist(L);
	return(L->length);
}

ElemType GetElem(SqList *L,int i){//获取在顺序表中位置为i的数据元素
	IsExist(L);
	if(i<=0 || i>L->length)
		printf("\t\t the parameter is not legal.\n");
	ElemType *e;
	e = L->sqList + i - 1;
	return(*e);
}

bool compare(ElemType a,ElemType b){//比较数据元素的函数
	if(a == b)
		return true;
	else
		return false;
}

int LocateElem(SqList *L, ElemType e){//返回第一个值为e的数据元素的位置
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

ElemType PriorElem(SqList *L,ElemType e){//返回前驱数据元素
	IsExist(L);
	if(e==*(L->sqList)){//第一个元素无前驱数据元素
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

ElemType NextElem(SqList *L,ElemType e){//返回后继数据元素
	IsExist(L);
	if(e==*(L->sqList+L->length-1)){//最后一个元素没有后继元素
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

void ClearList(SqList *L){//置空顺序表
	IsExist(L);
	L->length = 0;
	printf("\t\t the list is cleared.\n");
}

void ListInsert(SqList *L,int i,ElemType e){//向第i个位置插入一个值为e的数据元素
	IsExist(L);
	if(i<=0 || i>=L->length+1){
		printf("\t\t the parameter is not legal.\n");
		return;

	}
	if(L->length == L->ListSize){//判断顺序表的内存空间是否已满
		printf("\t\t run out of memory,is reallocating.\n");
		ElemType *newBase;
		newBase = (ElemType *)realloc(L->sqList,(SQLIST_INIT_SIZE+INCREMENTSIZE)*sizeof(ElemType));//动态增加内存空间
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

ElemType ListDelete(SqList *L,int i){//删除第i个位置的数据元素
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

void ListTraverse(SqList *L){//遍历顺序表
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
	printf("\t\t-----------------顺序表--------------------------\n");
	printf("\t\t--------------1.构造顺序表-----------------------\n");
	printf("\t\t--------------2.销毁顺序表-----------------------\n");
	printf("\t\t--------------3.判断是否为空表-------------------\n");
	printf("\t\t--------------4.返回顺序表表长-------------------\n");
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
		
	printf("\t\t-----------------顺序表--------------------------\n");
	printf("\t\t--------------1.构造顺序表-----------------------\n");
	printf("\t\t--------------2.销毁顺序表-----------------------\n");
	printf("\t\t--------------3.判断是否为空表-------------------\n");
	printf("\t\t--------------4.返回顺序表表长-------------------\n");
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