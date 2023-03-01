#include <gtk/gtk.h>
#include "gamewindow.h"

struct _GliGameWindow
{
   GtkWindow parent;

   GtkWidget* header;
   GtkWidget* button;
   GtkWidget* box;
};

G_DEFINE_TYPE( GliGameWindow, gli_game_window, GTK_TYPE_WINDOW );

static void gli_game_window_init( GliGameWindow* gw )
{
   gtk_window_set_title( GTK_WINDOW( gw ), "GLines" );

   gtk_window_set_default_size( GTK_WINDOW( gw ), 600, 400 );

   gw->header = gtk_header_bar_new();

   gw->button = gtk_button_new_from_icon_name( "mail-send-receive-symbolic" );
   gtk_header_bar_pack_end( GTK_HEADER_BAR( gw->header ), gw->button );

   gw->box = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0 );
   gtk_widget_add_css_class( gw->box, "linked" );
   gw->button = gtk_button_new_from_icon_name( "go-previous-symbolic" );
   gtk_box_append( GTK_BOX( gw->box ), gw->button );
   gw->button = gtk_button_new_from_icon_name( "go-next-symbolic" );
   gtk_box_append( GTK_BOX( gw->box ), gw->button );

   gtk_header_bar_pack_start( GTK_HEADER_BAR( gw->header ), gw->box );
   gtk_header_bar_pack_start( GTK_HEADER_BAR( gw->header ), gtk_switch_new() );

   gtk_window_set_titlebar( GTK_WINDOW( gw ), gw->header );

   gtk_window_set_child( GTK_WINDOW( gw ), gtk_text_view_new() );

   if( !gtk_widget_get_visible( GTK_WIDGET( gw ) ) ) gtk_widget_show( GTK_WIDGET( gw ) );
   else gtk_window_destroy( GTK_WINDOW( gw ) );
}

static void gli_game_window_class_init( GliGameWindowClass*  )
{
}

GtkWidget* gli_game_window_new()
{
   return GTK_WIDGET( g_object_new( GLI_TYPE_GAME_WINDOW, NULL ) );
}
