GtkApplication *app; 
GtkWidget* window; //main window.
GtkWidget* main_box; //the child of the main window. Good when you want to put more than one thing there.
GtkWidget* viewing_window; //where the actual settings stuff goes.
GtkWidget* side_panel; //where the settings switcher panel goes.
#define SIDE_PANEL_WIDTH 100
typedef struct Category
{
	char* markup;
	char* id;
} Category; //makes up the basis of each settings page

hash_element categories[30]; //hold each settings module. 30 or fewer is just a safe assumption for now. Increase if necessary
