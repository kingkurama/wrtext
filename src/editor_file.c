#include "editor_file.h"
#include "logger.h"
#include <string.h>

#ifdef _WIN32
#define PATH_DIVIDER '\\'
#else
#define PATH_DIVIDER '/'
#endif

int
editor_file_delete(editor_file *f)
{

	if(f->file_name == NULL || f->file_path == NULL || f->contents == NULL) {
		log_err(__FILE__, "Received corrupt file");
		return -1;
	}

	free(f->file_name);

	free(f->file_path);

	free(f->contents);

	if(f->buffer) {
		g_clear_object(&f->buffer);
	}

	free(f);

	return 0;
}

int
editor_file_update_lines(editor_file *f)
{
	// simple newline counter
	unsigned long lines = 0;
	for(unsigned long i = 0; i < f->size; i++) {
		if(*(f->contents + i) == '\n') {
			lines++;
		}
	}
	f->lines = lines;

	return 0;
}

int
editor_file_update_size(editor_file *f)
{

	return 0;
}

int
editor_file_update_name(editor_file *f)
{
	char *ls = f->file_path; // last slash
	char *c = f->file_path;
	int nl = 0;
	while(*c != '\0') {
		c++;
		nl++;
		if(*c == PATH_DIVIDER) {
			ls = c + 1;
			nl = 0;
		}
	}
	// log_info(__FILE__, "length: %d, name:%s\n",nl,ls);
	f->file_name = calloc(1, nl + 1);
	strcpy(f->file_name, ls);
	return 0;
}

int
editor_file_update_content(editor_file *f)
{
	GtkTextIter start, end;
	gtk_text_buffer_get_start_iter(f->buffer, &start);
	gtk_text_buffer_get_end_iter(f->buffer, &end);

	char *text = gtk_text_buffer_get_text(f->buffer, &start, &end, FALSE);

	g_free(f->contents);
	f->contents = text;
	f->size = strlen(text);
	return 0;
}
