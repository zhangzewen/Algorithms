#ifndef __HASHTABLE_H_INCLUDED
#define __HASHTABLE_H_INCLUDED

struct HashTable{
	struct list_head table_head;
	void *first_hash(void *hash);
	void *second_hash(void *hash);
	int value_compare(void *dest_data, void *src_data);
	int key_compare(void *dest_key, void *src_data);
};

struct Node{
	struct list_head node;
	struct list_head child;
	void *data;
	void *key;
	int hit;
};


struct HashTable *hash_table_malloc(void *(*first_hash)(void *value),
																	void *(*second_hash)(void *value),
																	int (*value_compare)(void *key));

struct Node *node_malloc();

void hash_table_free(struct HashTable *hash_table);

void node_free(struct Node *node);
int add_data_to_hash_table(struct HashTable *table_head, void *data);

#endif
