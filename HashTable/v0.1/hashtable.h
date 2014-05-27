#ifndef __UTIL_HASHTABLE_H_INCLUDED__
#define __UTIL_HASHTABLE_H_INCLUDED__

#include "list.h"

#define DEFAULTTABLESIZE 4096 

typedef struct HashTableOpt_st HashTableOpt;
typedef struct HashTable_st HashTable;
typedef struct Node_st Node;

struct HashTableOpt_st{
	unsigned int (*hash)(void *key);
	int (*key_compare)(void *dest_key, void *src_key);
	void (*key_free)(void **key);
	void (*value_free)(void **value);	
};

struct HashTable_st{
	struct list_head *table;
	HashTableOpt *opt;
	int mask;
	int table_size;
	int use;
};


struct Node_st{
	struct list_head list;
	void *data;
	void *key;
	HashTable *hashtable;
	int hits;
};


HashTable *hashtable_create(HashTableOpt *opt, int initsize);

void hashtable_free(HashTable **hashtable);
Node *node_new();
void node_free(Node **node);

Node *find_record(HashTable *table, void *key, int *index);
int add_record(HashTable *table, void *key, void *value);
int del_record(HashTable *table, void *key);
int update_record(HashTable *table, void *key, void *data);
void hashtable_dump(HashTable *table, void (*visit)(void *data));
#endif

