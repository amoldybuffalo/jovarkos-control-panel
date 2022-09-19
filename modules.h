typedef struct Module
{
	char* name;
	char* id;
	GtkWidget* box;
} Module;

Module load_module(char* id, char* name);
