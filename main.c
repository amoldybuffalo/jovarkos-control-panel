#include <stdio.h>
#include <gtk/gtk.h>
#include "hash_map.h"
#include "utils.h"
#include "modules.h"
#include "main.h"

//temporary for testing delete when unnecesary
//............................................


void on_category_button_click(GtkWidget* widget, gpointer data)
{
	char* id = (char*) data;

	GtkWidget* interface = categories->find(categories, id); //grab the gtk_box identified by id
	categories->modify(categories, id, g_object_ref(interface)); //necessary if we want to keep our object reference

	//TODO: turn this into a function
	GList* children = gtk_container_get_children(GTK_CONTAINER(viewing_window));
	GList* elem;
	for(elem = children; elem; elem = elem->next) {

		if(elem -> data) gtk_container_remove(GTK_CONTAINER (viewing_window), elem->data);
		
	}
	
	gtk_container_add(GTK_CONTAINER (viewing_window), (GtkWidget*) interface);	
	gtk_widget_show_all(GTK_WIDGET(window));
	
}

void on_resize(GtkWidget* widget, gpointer data)
{
	int window_width;
	int window_height;
	//gtk_window_get_size(GTK_WINDOW(window), &window_width, &window_height);
	//gtk_widget_set_size_request(side_panel, SIDE_PANEL_WIDTH, -1);
    //gtk_scrolled_window_set_min_content_width (GTK_SCROLLED_WINDOW(viewing_window), (window_width) - (SIDE_PANEL_WIDTH + 150));
	
}

Category generate_category(Module m)
{
	char* markup = mk_label_text(m.name, "Sans 15");
	categories->add(categories, m.id, m.box);
	Category category = {markup, m.id};	
	return category;
}

void load_category(Category category)
{
	GtkWidget* button = gtk_button_new();
	GtkWidget* label = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label), category.markup);
	gtk_container_add(GTK_CONTAINER(button), label );
	gtk_box_pack_start(GTK_BOX(side_panel), button, 0, 1, 1);
	g_signal_connect(GTK_BUTTON(button), "clicked", G_CALLBACK(on_category_button_click), category.id);
	gtk_widget_show_all(GTK_WIDGET(window));
	
}

void make_basic_structure()
{	
	window = gtk_application_window_new( GTK_APPLICATION ( app ) );
	gtk_window_set_title (GTK_WINDOW (window), "JovarkOS Control Panel");
	//gtk_window_set_icon_from_file(GTK_WINDOW(window), "assets/window-icon.png", NULL);
	gtk_window_set_default_size (GTK_WINDOW (window), 640, 480);
	
	main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
	side_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	viewing_window =  gtk_scrolled_window_new(NULL, NULL);

	gtk_widget_set_size_request(GTK_WIDGET(side_panel), 50, 480);
	gtk_widget_set_size_request(GTK_WIDGET(viewing_window), 500, 480);
	
	gtk_box_pack_start(GTK_BOX(main_box), side_panel, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX (main_box), viewing_window, 0, 0, 0);	  
	gtk_container_add(GTK_CONTAINER (window), main_box);
 	gtk_widget_show_all(GTK_WIDGET (window));
}

static void activate (GtkApplication *app, gpointer user_data)
{		

	  make_basic_structure();
	  hash_init(categories, 30);
	  Module m = load_module("test", "Test Module");
	  Category c = generate_category(m);
	  load_category(c);
	   
	  //g_signal_connect(G_OBJECT(window), "configure-event", G_CALLBACK(on_resize), NULL);

}

int main (int argc,char **argv)
{		  
	  
	  int status;
	  app = gtk_application_new ("org.jovarkos.settings", G_APPLICATION_FLAGS_NONE);
	  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	  status = g_application_run (G_APPLICATION (app), argc, argv);
	  g_object_unref (app);

	  return status;
}
