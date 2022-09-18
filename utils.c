#include <gtk/gtk.h>
#include "utils.h"

char* mk_label_text(char* text, char* font)
{
	char* markup = malloc(300); //far too large but gotta be safe
	snprintf(markup, 300, "<span font_desc=\"%s\">%s</span>", font, text);
	return markup;
}


