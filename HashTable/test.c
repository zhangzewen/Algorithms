#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "HashTable.h"

struct data{
	char name[32];
	unsigned int age;
	char address[64];
};






void *first_hash(void *data)
{
	struct data *person	 = (struct data *)data;
	int *key;
	key = (int *)malloc(sizeof(int));
	if(NULL == key){
		return NULL;
	}
	
	int i = 0;
	int sum = 0;
	for(i = 0; i < strlen(person->name); i++){
		*key += person->name[i] * 1;	
	}
	
	return (void *)key;	
}


int key_compare(void *dest_key, void *src_key)
{
	int key_1 = *((int *)dest_key);
	int key_2 = *((int *)src_key);
	
	if(key_1 > key_2){
		return 1;
	}else if(key_1 < key_2){
		return -1;
	}
	return 0;
}


int data_compare(void *dest_data, void *src_data)
{
	struct data *data_1 = (struct data *)dest_data;
	struct data *data_2 = (struct data *)src_data;
	return strcmp(data_1->name, data_2->name);	
}


void print(struct HashTable *table)
{
	struct Node *outer;
	struct Node *inner;
	struct data *person;
	list_for_each_entry(outer, &table->table_head, node){
			
			
			if(!list_empty(&outer->child)) {
				printf("key===>%d ||| \n", *((int *)outer->key));
				list_for_each_entry(inner, &outer->child, node){
					person =(struct data *) inner->data;
					printf("\t\t-------key===>%d ||| Person: name==>%s, age==>%d, address==>%s, hit==>%d\n", *((int *)inner->key), person->name, person->age, person->address, inner->hit);
					
				}
			}
			person =(struct data *) outer->data;

			
			printf("key===>%d ||| Person: name==>%s, age==>%d, address==>%s, hit==>%d\n", *((int *)outer->key), person->name, person->age, person->address, outer->hit);
	}
	
}


int main(int argc, char *argv[])
{
	struct data child;
	struct data child_1;
	struct data child_2;
	struct data child_3;
	struct data child_4;
	struct data child_5;
	struct data child_6;
	void *token;
/***********child*****************/
	strcpy(child.name, "zhangjie");
	child.age = 10;
	strcpy(child.address, "changjiang rode 13");	
/***********child_1*****************/
	strcpy(child_1.name, "huajie");
	child_1.age = 11;
	strcpy(child_1.address, "changjiang rode 14");	
/***********child_2*****************/
	strcpy(child_2.name, "lijie");
	child_2.age = 12;
	strcpy(child_2.address, "changjiang rode 16");	
/***********child_3*****************/
	strcpy(child_3.name, "lihua");
	child_3.age = 13;
	strcpy(child_3.address, "changjiang rode 15");	
/***********child_4*****************/
	strcpy(child_4.name, "zhangsan");
	child_4.age = 14;
	strcpy(child_4.address, "changjiang rode 20");	
/***********child_5*****************/
	strcpy(child_5.name, "zhanhua");
	child_5.age = 15;
	strcpy(child_5.address, "changjiang rode 1");	
/**********child_6**************************/
	strcpy(child_6.name, "zhanhua");
	child_6.age = 15;
	strcpy(child_6.address, "changjiang rode 1");	
/***********child_4*****************/
	strcpy(child_4.name, "lihua");
	child_4.age = 13;
	strcpy(child_4.address, "changjiang rode 15");	
#if 0
	token = first_hash((void *)&child_1);
	printf("the key is %d\n", *((int *)token));
#endif

	struct HashTable *table;
	
	table = hash_table_malloc(first_hash, NULL, data_compare, key_compare);
	add_record_to_hash_table(table, (void *)(&child));
	add_record_to_hash_table(table, (void *)(&child_1));
	add_record_to_hash_table(table, (void *)(&child_2));
	add_record_to_hash_table(table, (void *)(&child_3));
	add_record_to_hash_table(table, (void *)(&child_4));
	add_record_to_hash_table(table, (void *)(&child_5));
	add_record_to_hash_table(table, (void *)(&child_6));
	print(table);	
	return 0;
}

