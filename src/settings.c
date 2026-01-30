#include "settings.h"
#include "gui_edit.h"
#include "logger.h"
#include <string.h>

// Actual application settings, safely encapsulated.
settings_state t;

settings_state
settings_get()
{
	return t;
}

void
settings_set(settings_state *s)
{
	t.darkmode = s->darkmode;
	t.font_family[0] = 0;
	strcpy(t.font_family, s->font_family);
	t.font_size = s->font_size;
	t.linenums = s->linenums;
	t.textwrap = s->textwrap;
	t.whitespace = s->whitespace;
}

void
settings_apply()
{
	settings_state s = settings_get();
	// Apply wrap
	gui_edit_set_wrap(s.textwrap);
	// Apply line numbers
	gui_edit_set_line_numbers(s.linenums);

	// Apply whitespace
	gui_edit_set_whitespace(s.whitespace);

	// Apply dark mode preference
	// GtkSettings *gtk_settings = gtk_settings_get_default();
	// g_object_set(gtk_settings, "gtk-application-prefer-dark-theme", s.darkmode, NULL);

	// log_info(__FILE__, "Applying font family [%s] with sizee [%d]\n",
	// s.font_family,s.font_size);

	// Apply font and theme colors
	GtkCssProvider *provider = NULL;
	int provider_added = 0;

	if(!provider)
		provider = gtk_css_provider_new();

	// Construct CSS string with colors
	char css[516];
	if(s.darkmode) {
		snprintf(css, sizeof(css),
				 "textview { font-family: '%s'; font-size: %dpt; background-color: #1e1e1e; "
				 "color: #d4d4d4; }"											// background
				 "textview text { background-color: #1e1e1e; color: #d4d4d4; }" // text
				 "window { background-color: #1e1e1e; color: #d4d4d4; }",		// windows
				 s.font_family, s.font_size);
	} else {
		snprintf(css, sizeof(css),
				 "textview { font-family: '%s'; font-size: %dpt; background-color: #ffffff; "
				 "color: #000000; }"
				 "textview text { background-color: #ffffff; color: #000000; }"
				 "window { background-color: #ffffff; color: #000000; }",
				 s.font_family, s.font_size);
	}

	// Load CSS into the provider
	gtk_css_provider_load_from_data(provider, css, -1);

	if(!provider_added) {
		// Apply provider to the display (affects all widgets of this type)
		gtk_style_context_add_provider_for_display(gdk_display_get_default(),
												   GTK_STYLE_PROVIDER(provider),
												   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
		provider_added = 1;
	}
}