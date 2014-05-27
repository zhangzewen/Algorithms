#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "list.h"

int rehash(HashTable *table);
HashTable* hashtable_create(HashTableOpt *opt, int initsize)
{
	HashTable *new = NULL;;
	int tablesize = 0;
	int i = 0;
	new	= (HashTable *)calloc(1, sizeof(HashTable));

	if (NULL == new) {
		perror("hashtable calloc error!\n");
		return NULL;
	}

	tablesize = (initsize > DEFAULTTABLESIZE) ? initsize : DEFAULTTABLESIZE;
	new->table = (struct list_head *)calloc(tablesize, sizeof(struct list_head));

	if (NULL == new->table) {
		free(new);
		return NULL;
	}

	for (i = 0; i < tablesize; i++) {
		INIT_LIST_HEAD(&new->table[i]);
	}	

	new->mask = tablesize - 1;
	new->table_size = tablesize;
	new->opt = opt;
	return new;
}

Node *node_new(HashTable *hashtable, void *key, void *data)
{
	Node *node;
	node = (Node *)calloc(1, sizeof(Node));
	
	if(NULL == node) {
		return NULL;
	}

	INIT_LIST_HEAD(&node->list);
	node->data = data;
	node->key = key;
	node->hashtable = hashtable;
	
	return node;
}

void hashtable_free(HashTable **table)
{
	if (NULL == *table) {
		return ;
	}
	
	if (NULL != (*table)->table) {
		int i = 0;
		Node *node = NULL;
		Node *tmp = NULL;
		for (i = 0; i < (*table)->table_size; i++) {
			if (list_empty(&(*table)->table[i])) {
				continue;
			}
			list_for_each_entry_safe(node, tmp, &(*table)->table[i], list) {
				//list_del(&node->list);
				node_free(&node);
			}
		}	
	}	
	free((*table)->table);	
	free(*table);
	*table = NULL;
}



void node_free(Node **node)
{
	list_del(&(*node)->list);	
	
	if((*node)->key && NULL != (*node)->hashtable->opt->key_free){
		(*node)->hashtable->opt->key_free(&(*node)->key);
	}
	
	if((*node)->data && NULL != (*node)->hashtable->opt->value_free) {
		(*node)->hashtable->opt->value_free(&(*node)->data);
	}
	free(*node);
	*node = NULL;
}



Node *find_record(HashTable *table, void *key, int *index)
{
	Node *ptr = NULL;
	unsigned int hash_val = 0;
	
	if (NULL == table) {
		return NULL;
	}

	hash_val = table->opt->hash(key);	
	*index = hash_val & table->mask;

	if (list_empty(&(table->table[*index]))) {
		return NULL;
	}

	list_for_each_entry(ptr, &(table->table[*index]), list) {
		if(table->opt->key_compare(key, ptr->key) == 0)	{
			return ptr;
		}
	}
	return NULL;
}

int add_record(HashTable *table, void *key, void *data)
{
	Node *node = NULL;
	int index = 0;

	if(NULL == table || NULL == key || NULL == data)	{
		return -1;
	}	

	node = find_record(table, key, &index);

	if( NULL == node)	{
		table->use++;
		if (table->use >= (table->table_size / 2)) {
				//rehashtable
				rehash(table);
		}
		node = node_new(table, key,data);

		if (NULL == node) {
			return -1;
		}

		list_add_tail(&node->list, &(table->table[index]));
		return 0;
	}

	if(NULL != node){
		node->hits++;
	}

	return -1;
}



int del_record(HashTable *table, void *key)
{
	Node *node = NULL;
	int index = 0;

	if(NULL == table){
		return -1;
	}

	node = find_record(table, key, &index);

	if(NULL == node) {
		fprintf(stderr, "record not found!\n");
		return -1;	
	}

	if(NULL != node) {
		//list_del(&node->list);
		node_free(&node);
		return 0;
	}

	return -1;
}

void hashtable_dump(HashTable *table, void (*visit)(void *data))
{
	int i = 0;
	Node *node = NULL;
	if (NULL == table || NULL == table->table) {
		return ;
	}

	for (i = 0; i < table->table_size; i++) {
		if (list_empty(&(table->table[i]))) {
			continue;
		}
		fprintf(stderr, "[%d]:\n", i);
		list_for_each_entry(node, &(table->table[i]), list) {
			visit(node->data);
		}
	}	

	return ;
}

int update_record(HashTable *table, void *key, void *data)
{
	Node *node = NULL;
	int index = 0;

	if(NULL == table){
		return -1;
	}

	node = find_record(table, key, &index);

	if(NULL == node) {
		fprintf(stderr, "record not found!\n");
		return -1;	
	}

	if(NULL != node) {
		node->data = data;
		return 0;
	}
	return -1;
}

int rehash(HashTable *table)
{
	struct list_head *tmp = NULL;
	int tablesize = table->table_size * 2;
	int mask = tablesize - 1;
	int i = 0;
	
	tmp = (struct list_head *)calloc(tablesize, sizeof(struct list_head));
	
	if (NULL == tmp) {
		return -1;
	}

	

	for (i = 0; i < table->table_size; i++) {
		Node *node = NULL;
		Node *ptr = NULL;
		if (list_empty(&(table->table[i]))) {
			continue;
		}
		list_for_each_entry_safe(node, ptr, &(table->table[i]), list) {
			unsigned int hash_val = 0;
			int index = 0;

			hash_val = table->opt->hash(node->key);	
			index = hash_val & mask;
			list_del(&node->list);
			list_add_tail(&node->list, &tmp[index]);
		}
	}	

	free(table->table);
	table->table = tmp;
	table->table_size = tablesize;
	table->mask = mask;
	return 0;
}
