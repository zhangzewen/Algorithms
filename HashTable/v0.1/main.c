#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "hash.h"

struct st{
	char key[256];
	char value[256];
};
void visit(void *data)
{
	struct st *v = (struct st *)data;
	fprintf(stderr, "-----[key: %s][value: %s]\n", v->key, v->value);
}

unsigned int hash(void *key)
{

  int i = 0;
	char *val_1 = (char *)key;
	unsigned int hash_val = 0;
  for(i = 0; i < strlen(val_1); i++){
    hash_val += (unsigned int)(val_1[i] * i);  
  }
  
	fprintf(stderr, "%s hash values is %u\n", val_1, hash_val);
	return hash_val;

}

int key_compare(void *dest_key, void *src_key)
{
	char *val_1 = (char *)dest_key;
	char *val_2 = (char *)src_key;
	return strcmp(val_1, val_2);
}

HashTableOpt opt = {.hash = hash, .key_compare = key_compare, .key_free = NULL, .value_free = NULL};



struct st v_1 = {.key = "zhangjie", .value = "rodeadfasfdasfdas"};
struct st v_2 = {.key = "zhangxxx", .value = "rodeadfasfdasfdas"};
struct st v_3 = {.key = "zhersdfqwrjie", .value = "rodeadfasfdasfdas"};
struct st v_4 = {.key = "awersdfgjie", .value = "rodeadfasfdasfdas"};
struct st v_5 = {.key = "asdftfwerie", .value = "rodeadfasfdasfdas"};
struct st v_6 = {.key = "asdftfwerie", .value = "xxxxxxxxxxxxxxxrodeadfasfdasfdas"};



int main(int argc, char *argv[])
{

	HashTable *table;
	table = hashtable_create(&opt, 1024);
	add_record(table, (void *)v_1.key, (void *)&v_1 );
	add_record(table, (void *)v_2.key, (void *)&v_2 );
	add_record(table, (void *)v_3.key, (void *)&v_3 );
	add_record(table, (void *)v_4.key, (void *)&v_4 );
	add_record(table, (void *)v_5.key, (void *)&v_5 );
	hashtable_dump(table, visit);
	del_record(table, (void *)v_4.key);
	hashtable_dump(table, visit);
	update_record(table, (void *)v_5.key, (void *)&v_6);
	hashtable_dump(table, visit);
	hashtable_free(&table);
	return 0;
}
