#include "HashTable.h"

struct HashTable hash_table_malloc(void *(*first_hash)(void *value),
																	void *(*second_hash)(void *value),
																	int (*value_compare)(void *key))
{
	struct HashTable *head;
	head = (struct HashTable *)malloc(sizeof(struct HashTable));
	
	if (NULL == head) {
		exit(-1);
	}

	LIST_HEAD(&head->table_head);
	head->first_hash = first_hash;
	head->second_hash = second_hash;
	head->value_compare = value_compare;
	
	return head;
}

struct Node node_malloc()
{
	struct Node *node;
	
	node = (struct Node *)malloc(sizeof(struct Node));
	
	if(NULL == node) {
		exit(-1);
	}

	LIST_HEAD(&node->node);
	LIST_HEAD(&node->child);
	node->data = NULL;
	node->key = NULL;
	
	return node;
}

void hash_table_free(struct HashTable *hash_table)
{
	
	if(list_empty(&hash_table->table_head)){
		list_del(&hash_table->table_head);
	}else{
		struct Node *tmp, ptr;
		list_for_each_entry_safe(ptr, tmp, &hash_table->table_head, table_head){
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
	struct Node *ptr;
	if(!list_empty(node->child)) {
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
	node = NULL:
}





