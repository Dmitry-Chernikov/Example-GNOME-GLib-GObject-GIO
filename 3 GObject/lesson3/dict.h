#ifndef __DICT_H__
#define __DICT_H__

//#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

typedef struct {
	gchar* key;
	gchar* value;
} dict_t;

dict_t* dict_new(gchar* key, gchar* value);
dict_t* dict_push(dict_t* dic, gchar* key, gchar* value);
dict_t* dict_next(dict_t* dic);
dict_t* dict_prev(dict_t* dic);
gint dict_count(dict_t* dic);

G_END_DECLS
#endif
