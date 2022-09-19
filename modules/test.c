#include <gtk/gtk.h>
GtkWidget* test()
{
	GtkWidget* button = gtk_button_new_with_label("Button from module");
	return button;
}
