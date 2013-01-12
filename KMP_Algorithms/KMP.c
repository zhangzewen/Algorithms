#include<stdio.h>
#include<stdlib.h>
#include "KMP.h"

void StrAssign(HString T,char *chars)
{
	
}
int StrLength(HString S)
{
	
}

int StrCompare(HString S,HString L)
{	
	
}


void ClearString(HString &S ,HString A,HString B)
{
}

HString SubString(HString S,int pos,int len)
{
}
int Index(HString S,HString T,int pos
{
	
}

void get_next(HString T,int next[])
{
	int i=1;
	next[1]=0;
	int j=0;
	while(i<T[0])
	{
		if(j==0||T[i] ==0){++i;++j;next[i]=j;}
		else j=next[j];
	}
}

void get_nextval(HString T,int nextval[])
{
	int i=0;
	nextval[1]=0;
	int j=0;
	while(i<T[0])
	{
		if(j==0||T[0] ==T[j])
		{
			++i;
			++j;
			if(T[i]!=T[j])  nextval[i]=j;
			else nextval[i] =nextval[j];
		}else
		{
			j=nextval[j];
		}
	}
}
