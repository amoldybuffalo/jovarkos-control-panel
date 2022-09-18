typedef struct hash_element
{
	char key[500];
	GtkWidget* value;
	int (*add)(struct hash_element*, char*, GtkWidget*);
	int (*modify)(struct hash_element*, char*, GtkWidget*);
	int (*exists)(struct hash_element*, char*);
	GtkWidget* (*find)(struct hash_element*, char*);
} hash_element;

#define hash_map_end(hash_map, i) (hash_map[ i ].key[0] == '\n')

void hash_init(hash_element* hash_map, int size);
GtkWidget* hash_find(hash_element* hash_map, char* key);
int hash_add(hash_element* hash_map, char* key, GtkWidget* value);
int hash_modify(hash_element* hash_map, char* key, GtkWidget* value);
int hash_exists(hash_element* hash_map, char* key);


