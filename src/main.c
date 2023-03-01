#include <gtk/gtk.h>

#include "config.h"
#include "gamewindow.h"

static void app_activate( GApplication* app )
{
   GtkWindow* win = GTK_WINDOW( gli_game_window_new() );

   gtk_window_set_application( GTK_WINDOW( win ), GTK_APPLICATION( app ) );
   gtk_window_present( GTK_WINDOW( win ) );
}

int main( int argc, char** argv )
{
   GtkApplication* app;
   int stat;

   app = gtk_application_new( APP_ID, G_APPLICATION_FLAGS_NONE );
   g_signal_connect( app, "activate", G_CALLBACK( app_activate ), NULL );
   stat = g_application_run( G_APPLICATION( app ), argc, argv );
   g_object_unref( app );
   return stat;
}


