#ifndef __HASHTABLE_H_INCLUDED
#define __HASHTABLE_H_INCLUDED

struct HashTable{
	struct list_head table_head;
	void master_key_maker(void *value, void *key);
	void second_key_maker(void *value, void *key);
}

struct Table{
	struct list_head list;
	unsigned long int 
		
};

#endif
