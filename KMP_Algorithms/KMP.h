#include<stdio.h>
#include<stdlib.h>
typedef struct SString {
	char * ch;
	int length;
}*HString;

void StrAssign(HString T,char *chars);

int StrLength(HString S);

int StrCompare(HString S,HString L);

void ClearString(HString S);

void Concat(HString S ,HString A,HString B);

HString SubString(HString S,int pos,int len);

int Index(HString S,HString T,int pos);
void get_next(HString T,int next[]);
void get_nextval(HString S,int nextval[]);
