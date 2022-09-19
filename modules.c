#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> 
#include "modules.h"

Module load_module(char* id, char* name)
{
	char filename[100];
	snprintf(filename, 100, "modules/%s.so", id);
	void* handle = dlopen(filename, RTLD_LAZY);
	if( !handle )
    {
        fprintf( stderr, "dlopen() %s\n", dlerror() );
        exit( 1 );
    }  dlerror();

    GtkWidget* (*function)(void);
    function = (GtkWidget* (*)()) dlsym(handle, id);
    Module module = {name, id, function()};
    dlclose( handle );
    return module;
}
