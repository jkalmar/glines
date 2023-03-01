#pragma once

#include <gtk/gtk.h>

#define GLI_TYPE_GAME_WINDOW gli_game_window_get_type()
G_DECLARE_FINAL_TYPE( GliGameWindow, gli_game_window, GLI, GAME_WINDOW, GtkWindow )

GtkWidget* gli_game_window_new( void );
