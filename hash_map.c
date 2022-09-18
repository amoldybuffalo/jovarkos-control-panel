#include <gtk/gtk.h>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "hash_map.h"

void hash_init(hash_element* hash_map, int size)
{	
	hash_map->add = &hash_add;
	hash_map->modify = &hash_modify;
	hash_map->find = &hash_find;
	hash_map->exists = &hash_exists;
	for(int i = 0; i < size; i++)
	{
		if(i == size - 1) hash_map[i].key[0] = '\n';
		else hash_map[i].key[0] = '\0';		
		hash_map[i].value = NULL;
	}
}

GtkWidget* hash_find(hash_element* hash_map, char* key)
{
	if(key[0] == '\0') { fprintf(stderr, "Error: empty string is not a valid key.\n"); return NULL; }
	if(key[0] == '\n') { fprintf(stderr, "Error: newline is not a valid key.\n"); return NULL; }
	
	for(int i = 0; !hash_map_end(hash_map, i); i++)
	{	
		if(strcmp(hash_map[i].key, key) == 0)
		{	
			return hash_map[i].value;
		}
	}
	return NULL;
}

int hash_add(hash_element* hash_map, char* key, GtkWidget* value)
{
	if(key[0] == '\0') { fprintf(stderr, "Error: empty string is not a valid key.\n"); return -1; }
	if(key[0] == '\n') { fprintf(stderr, "Error: newline is not a valid key.\n"); return -1; }
	for(int i = 0; i < (int) strlen(key); i++)
	{
		if(key[i] == '\n') {fprintf(stderr, "Errror: no newlines in keys. \n"); return -1;}
	}
	for(int i = 0; !hash_map_end(hash_map, i); i++)
	{
		if(hash_map[i].key[0] == '\0')
		{
			strcpy(hash_map[i].key, key);
		    	hash_map[i].value = value;
			return 0;
		}
	}
	return -1;	
}

int hash_modify(hash_element* hash_map, char* key, GtkWidget* value)
{
	for(int i = 0; !hash_map_end(hash_map, i); i++)
	{
				if(strcmp(key, hash_map[i].key) == 0)
				{
				 	hash_map[i].value = value;
					return 0;
				}
	}
	return -1;		
}

int hash_exists(hash_element* hash_map, char* key)
{
	for(int i = 0; !hash_map_end(hash_map, i); i++)
	{
			if(strcmp(key, hash_map[i].key) == 0)
			{
				return 1;
			}
	}
	return 0;
	
}

