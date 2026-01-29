#include "editor_file.h"
#include <gtk/gtk.h>

/*!
	@file gui_edit_menu.h
	@brief The files gui_edit_menu.h and gui_edit_menu.c contains the code related to the menubar in the edit window
*/


/*!
	@brief Initializes the menu bar of the edit window
	@param app Pointer to the GTK application
*/
GtkWidget *gui_edit_menu_init(GtkApplication *app);

/*!
	@brief This functions starts the whole process of opening a file. It receives the file path, it reads the 
	file from the filesystem, it create the editor_file and loads it on the GUI
	@param file_path Path to the file to load (PATH IS FREED BY THIS FUNCTION!)
*/
void gui_edit_menu_open_file(char *file_path);

void gui_edit_menu_enable_saving(gboolean b);

