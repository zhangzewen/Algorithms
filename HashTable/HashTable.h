#ifndef __HASHTABLE_H_INCLUDED
#define __HASHTABLE_H_INCLUDED
struct HashTable{
	struct list_head table_head;
	unsigned int master_key_maker(const char *value);
	unsigned int second_key_maker(unsigned int value);
}

struct Node{
	struct list_head list;
	unsigned long int key;
	char value[64]; 
	struct list_head child;
		
};

struct HashTable *create_hashtable(unsigned int (*master_key_maker)(const char *value), unsigned int (*second_key_maker)(unsigned int value))
{
	struct HashTable *hash;
	
	hash = (struct HashTable *)malloc(sizeof (struct HashTable));
	
	if (NULL == hash) {
		perror("malloc error!\n");
		return (struct HashTable *) -1;
	}

	INIT_LIST_HEAD(&hash->list);
	
	hash->master_key_maker = master_key_maker;
	hash->second_key_maker = second_key_maker;

	return hash;
}



struct Node *create_node( void )
{
	struct Node *node;
	
	node = (struct Node *)malloc(sizeof(struct Node));
	
	if (NULL == node) {
		perror("malloc error!\n");
		return (struct Node *) -1;
	}

	node->key = 0;
	node->value[0] = 0;
	INIT_LIST_HEAD(&node->list);
	INIT_LIST_HEAD(&node->child);
	return node;
	
}

void add_value_to_table(struct HashTable *hash, const char *value)
{
		
}









#endif
