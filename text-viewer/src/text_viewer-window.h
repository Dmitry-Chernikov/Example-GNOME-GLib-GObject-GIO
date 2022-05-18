/* text_viewer-window.h
 *
 * Copyright 2022 chda
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define TEXT_VIEWER_TYPE_WINDOW (text_viewer_window_get_type())

G_DECLARE_FINAL_TYPE (TextViewerWindow, text_viewer_window, TEXT_VIEWER, WINDOW, GtkApplicationWindow)

static void
text_viewer_window_open_file_dialog (GAction           *action G_GNUC_UNUSED,
                                     GVariant          *parameter G_GNUC_UNUSED,
                                     TextViewerWindow  *self);

static void
on_open_response (GtkNativeDialog  *native,
                  int               response,
                  TextViewerWindow *self);

static void
open_file (TextViewerWindow *self,
           GFile            *file);

static void
open_file_complete (GObject          *source_object,
                    GAsyncResult     *result,
                    TextViewerWindow *self);

static void
text_viewer_window_update_cursor_position (GtkTextBuffer    *buffer,
                                           GParamSpec       *pspec G_GNUC_UNUSED,
                                           TextViewerWindow *self);

static void
text_viewer_window_save_file_dialog (GAction           *action G_GNUC_UNUSED,
                                     GVariant          *param G_GNUC_UNUSED,
                                     TextViewerWindow  *self);

static void
on_save_response (GtkNative        *native,
                  int               response,
                  TextViewerWindow *self);

static void
save_file (TextViewerWindow *self,
           GFile            *file);

static void
save_file_complete (GObject      *source_object,
                    GAsyncResult *result,
                    TextViewerWindow *self);

static void
text_viewer_window_finalize (GObject *gobject);

G_END_DECLS
