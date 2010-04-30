/*
 * Copyright (C) 2010 Canonical Ltd.
 * Author: Robert Ancell <robert.ancell@canonical.com>
 * 
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

#ifndef _GREETER_H_
#define _GREETER_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define GREETER_TYPE (greeter_get_type())
#define GREETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GREETER_TYPE, Greeter));

typedef struct GreeterPrivate GreeterPrivate;

typedef struct
{
    GObject         parent_instance;
    GreeterPrivate *priv;
} Greeter;

typedef struct
{
    GObjectClass parent_class;
  
    void (*show_prompt)(Greeter *greeter, const gchar *text);
    void (*show_message)(Greeter *greeter, const gchar *text);
    void (*show_error)(Greeter *greeter, const gchar *text);
    void (*authentication_complete)(Greeter *greeter);
} GreeterClass;

GType greeter_get_type (void);

Greeter *greeter_new (void);

void greeter_start_authentication (Greeter *greeter, const char *username);

void greeter_provide_secret (Greeter *greeter, const gchar *secret);

void greeter_cancel_authentication (Greeter *greeter);

gboolean greeter_get_is_authenticated (Greeter *greeter);

G_END_DECLS

#endif /* _GREETER_H_ */
