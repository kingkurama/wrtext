#include "editor_file.h"
#include <gtk/gtk.h>

/*!
	@file gui_edit.h
	@brief The files gui_edit.h and gui_edit.c contain the code responsible for managing file tabs and
	the main text area of the application
*/


/*!
	@brief Initializes the main application window responsible for allowing the user to edit
	the code

	@param app Pointer to the GTK application
*/
GtkWidget *gui_edit_init(GtkApplication *app,int cmd_files_num, char **cmd_files_str);

/*!
	@brief Updates statusbar text with the data from the file passed as a parameter
	@param f Pointer to file
*/
void gui_edit_statusbar_update(editor_file *f); // Might be a bad design decision to make this accessible to other modules

/*!
	@brief This function interates through every open file and updates it's title on the notebook based on whether there are unsaved changes. (Shows the asterisk in case)
*/
void gui_edit_update_titles();

/*!
	@brief Adds a file to the list of opened file so that the user may edit it
	@param f Pointer to the file
	@return Returns the ID of the file added, -1 in case of error
*/
editor_file_id gui_edit_add_file(editor_file *f);

/*!
	@brief Function that closes an opened file
	@param id ID of the file to be closed
*/
int gui_edit_close_file(editor_file_id id);


void gui_edit_cleanup();

/*!
	@brief Just a debug function to add a file with random contets
*/
void gui_edit_add_random_file(GSimpleAction *action, GVariant *parameter, gpointer user_data);

editor_file *gui_edit_get_selected_file();

void gui_edit_set_wrap(int b);

void gui_edit_set_line_numbers(int b);