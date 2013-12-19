#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
struct HashTable *hash_table_malloc(void *(*first_hash)(void *value),
                                  void *(*second_hash)(void *value),
                                  int (*data_compare)(void *dest_data, void *src_data),
                                  int (*key_compare)(void *dest_key, void *src_key))
{
	struct HashTable *head;
	head = (struct HashTable *)malloc(sizeof(struct HashTable));
	
	if (NULL == head) {
		exit(-1);
	}

	INIT_LIST_HEAD(&head->table_head);
	head->first_hash = first_hash;
	head->second_hash = second_hash;
	head->value_compare = data_compare;
	head->key_compare = key_compare;
	
	return head;
}

struct Node *node_malloc()
{
	struct Node *node;
	
	node = (struct Node *)malloc(sizeof(struct Node));
	
	if(NULL == node) {
		return NULL;
	}

	INIT_LIST_HEAD(&node->node);
	INIT_LIST_HEAD(&node->child);
	node->data = NULL;
	node->key = NULL;
	
	return node;
}

void hash_table_free(struct HashTable *hash_table)
{
	
	if(list_empty(&hash_table->table_head)){
		list_del(&hash_table->table_head);
	}else{
		struct Node *tmp, *ptr;
		list_for_each_entry_safe(ptr, tmp, &hash_table->table_head, node){
			node_free(ptr);
		}
		list_del(&hash_table->table_head);
	}

	hash_table->first_hash = NULL;
	hash_table->second_hash = NULL;
	hash_table->key_compare = NULL;
	
	free(hash_table);
	
	hash_table = NULL;
}



void node_free(struct Node *node)
{
	if(!list_empty(&node->child)) {
		struct Node *tmp, *ptr;
		list_for_each_entry_safe(ptr, tmp, &node->child, child){
			if(ptr->key){
				free(ptr->key);
				ptr->key = NULL;
			}

			if(ptr->data) {
				free(ptr->data);
				ptr->data = NULL;
			}

			list_del(&ptr->child);
			list_del(&ptr->node);
			
			free(ptr);
			ptr = NULL;
		}	
	}
	
	list_del(&node->child);	
	list_del(&node->node);
	
	if(node->key){
		free(node->key);
		node->key = NULL;
	}
	
	if(node->data) {
		free(node->data);
		node->data = NULL;
	}

	
	free(node);
	node = NULL;
}



struct Node *find_key_from_hash_table(struct HashTable *table, void *data)
{
	struct Node *tmp = NULL;
	struct Node *outer = NULL;
	
	if (NULL == table) {
		return NULL;
	}

	list_for_each_entry_safe(outer, tmp, &table->table_head, node) {
		if(table->key_compare(table->first_hash(data), outer->key) == 0)	{
			return outer;
		}
	}

	return NULL;
}

/*
 *struct Node *find_data_from_hash_table(struct HashTable *table, void *data)
 *@table, the Hash Table where zhe @data will be found from
 *@data, the element that will be found
 *return, NULL:found, Not NULL(struct Node *):not found
 */

struct Node *find_data_from_hash_table(struct HashTable *table, void *data)
{
	struct Node *node;
	if(NULL == table){
		return NULL;
	}
	
	node = find_key_from_hash_table(table, data);
	
	if(NULL == node) {
		return NULL;	
	}
	
	if(NULL != node) {
		
		if(list_empty(&node->child)){
			return node;
		}else{
			struct Node *inner, *tmp;
			list_for_each_entry_safe(inner, tmp, &node->child, node) {
				if(table->value_compare(inner->data, data) == 0) {
					return inner;
				}
			}
		}
	}
	
	return NULL;
}
/*
 *int add_data_to_hash_table(struct HashTable *table_head, void *data)
 *@table_head , the Hash Table
 *@data, data to add into Hash Table
 *return, -1:add error, 0:add ok, 1:record exists
 */



int add_record_to_hash_table(struct HashTable *table_head, void *data)
{
	struct Node *node;
	if(NULL == table_head)	{
		return -1;
	}	

	node = find_key_from_hash_table(table_head, data);

	if( NULL == node)	{
		node = node_malloc();

		if(NULL == node)	{
			return -1;
		}

		node->key = table_head->first_hash(data);

		node->data = data;

		node->hit = 0;

		list_add(&node->node, &table_head->table_head);

		return 0;
	}

	if(NULL != node){

		if(list_empty(&node->child)&& table_head->value_compare(node->data, data) != 0)	{
			struct Node *tmp;
			tmp = node_malloc();
			if(NULL == tmp)	{
				return -1;
			}

			tmp->key = node->key;
			tmp->data = node->data; 
			tmp->hit = node->hit;
			list_add(&tmp->node, &node->child);

			node->data = NULL;
			node->hit = 0;

			tmp = NULL;
			tmp = node_malloc();

			if(NULL == tmp)	{
				return -1;
			}

			tmp->key = node->key;
			tmp->data = data;
			tmp->hit = 0;

			list_add(&tmp->node, &node->child);
		
		}else if(list_empty(&node->child)&& table_head->value_compare(node->data, data) == 0) {
			node->hit++;
		}	

		if(!list_empty(&node->child)) {
			struct Node *tmp, *ptr;
			list_for_each_entry_safe(ptr, tmp, &node->child, node)	{
				if(table_head->value_compare(ptr->data, data) == 0) {
					ptr->hit++;
					return 0;
				}
			}

			tmp = NULL;
			tmp = node_malloc();

			if(NULL == tmp)	{
				return -1;
			}

			tmp->key = node->key;
			tmp->data = data;
			tmp->hit = 0;

			list_add(&tmp->node, &node->child);
		}
		return 0;

	}
	
	return -1;
}


/*
 *int del_record_to_hash_table(struct HashTable *table, void *data)
 *@table, the Hash Table
 *@data, a record that will del from Hash Table
 *return, -1: del error; 0:del ok!
 */


int del_record_to_hash_table(struct HashTable *table, void *data)
{
	struct Node *node;
	if(NULL == table){
		return -1;
	}

	node = find_data_from_hash_table(table, data);

	if(NULL == node) {
		return -1;	
	}

	if(NULL != node) {

		list_del(&node->node);
		node_free(node);
		return 0;
	}

	return -1;
}


