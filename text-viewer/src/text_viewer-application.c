/* text_viewer-application.c
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

#include "text_viewer-application.h"
#include "text_viewer-window.h"

struct _TextViewerApplication
{
  GtkApplication parent_instance;

  GSettings *settings;
};

G_DEFINE_TYPE (TextViewerApplication, text_viewer_application, ADW_TYPE_APPLICATION)

TextViewerApplication *
text_viewer_application_new (gchar *application_id, GApplicationFlags  flags)
{
  return g_object_new (TEXT_VIEWER_TYPE_APPLICATION, "application-id", application_id,"flags", flags, NULL);
}

static void
text_viewer_application_finalize (GObject *object)
{
  TextViewerApplication *self = (TextViewerApplication *)object;

  G_OBJECT_CLASS (text_viewer_application_parent_class)->finalize (object);
}

static void
text_viewer_application_dispose (GObject *gobject)
{
  //Очистить экземпляр GSettings при удалении экземпляра TextViewerApplication

  TextViewerApplication *self = TEXT_VIEWER_APPLICATION (gobject);

  g_clear_object (&self->settings);

  G_OBJECT_CLASS (text_viewer_application_parent_class)->dispose (gobject);
}

static void
text_viewer_application_activate (GApplication *app)
{
  GtkWindow *window;

  /* It's good practice to check your parameters at the beginning of the
   * function. It helps catch errors early and in development instead of
   * by your users.
   */
  g_assert (GTK_IS_APPLICATION (app));

  /* Get the current window or create one if necessary. */
  window = gtk_application_get_active_window (GTK_APPLICATION (app));
  if (window == NULL)
    window = g_object_new (TEXT_VIEWER_TYPE_WINDOW,
                           "application", app,
                           NULL);

  /* Ask the window manager/compositor to present the window. */
  gtk_window_present (window);
}


static void
text_viewer_application_class_init (TextViewerApplicationClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  object_class->finalize = text_viewer_application_finalize;

  gobject_class->dispose = text_viewer_application_dispose;

  /*
   * We connect to the activate callback to create a window when the application
   * has been launched. Additionally, this callback notifies us when the user
   * tries to launch a "second instance" of the application. When they try
   * to do that, we'll just present any existing window.
   */
  app_class->activate = text_viewer_application_activate;
}

static void
text_viewer_application_show_about (GSimpleAction *action,
                                    GVariant      *parameter,
                                    gpointer       user_data)
{
  TextViewerApplication *self = TEXT_VIEWER_APPLICATION (user_data);
  GtkWindow *window = NULL;
  const gchar *authors[] = {"chda", NULL};

  g_return_if_fail (TEXT_VIEWER_IS_APPLICATION (self));

  window = gtk_application_get_active_window (GTK_APPLICATION (self));

  gtk_show_about_dialog (window,
                         "program-name", "text-viewer",
                         "authors", authors,
                         "version", "0.1.0",
                         NULL);
}


static void
text_viewer_application_init (TextViewerApplication *self)
{
  // Инициализируйте экземпляр GSettings вместе с остальной частью TextViewerApplication
  self->settings = g_settings_new ("com.example.TextViewer");

  g_autoptr (GSimpleAction) quit_action = g_simple_action_new ("quit", NULL);
  g_signal_connect_swapped (quit_action, "activate", G_CALLBACK (g_application_quit), self);
  g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (quit_action));

  g_autoptr (GSimpleAction) about_action = g_simple_action_new ("about", NULL);
  g_signal_connect (about_action, "activate", G_CALLBACK (text_viewer_application_show_about), self);
  g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (about_action));

  // Установите начальное состояние для цветовой схемы
  // Получить значение ключа GSettings в темном режиме
  gboolean dark_mode = g_settings_get_boolean (self->settings, "dark-mode");
  AdwStyleManager *style_manager = adw_style_manager_get_default ();
  // Установить цветовую схему, используя значение ключа
  if (dark_mode)
    adw_style_manager_set_color_scheme (style_manager, ADW_COLOR_SCHEME_FORCE_DARK);
  else
    adw_style_manager_set_color_scheme (style_manager, ADW_COLOR_SCHEME_DEFAULT);

  // Инициализировать состояние действия в темном режиме со значением ключа
  g_autoptr (GSimpleAction) dark_action = g_simple_action_new_stateful ("dark-mode", NULL, g_variant_new_boolean (dark_mode));
  /* Действие с отслеживанием состояния в темном режиме и подключение к его сигналам activate и change-state */
  /* g_autoptr (GSimpleAction) dark_action = g_simple_action_new_stateful ("dark-mode",NULL,g_variant_new_boolean (FALSE)); */

  g_signal_connect (dark_action, "activate", G_CALLBACK (toggle_dark_mode), self);
  g_signal_connect (dark_action, "change-state", G_CALLBACK (change_color_scheme), self);
  g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (dark_action));

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "app.quit",
                                         (const char *[]) {
                                           "<primary>q",
                                           NULL,
                                         });

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "win.open",
                                         (const char *[]) {
                                           "<Ctrl>o",
                                           NULL,
                                         });

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "win.save-as",
                                         (const char *[]) {
                                           "<Ctrl><Shift>s",
                                           NULL,
                                         });
}

static void // это обратный вызов переключает состояние действия в темном режиме между «истинным» и «ложным»
toggle_dark_mode (GSimpleAction               *action,
                  GVariant                    *parameter G_GNUC_UNUSED,
                  TextViewerApplication       *self G_GNUC_UNUSED)
{
  GVariant *state = g_action_get_state (G_ACTION (action));
  gboolean old_state = g_variant_get_boolean (state);
  gboolean new_state = !old_state;

  g_action_change_state (G_ACTION (action), g_variant_new_boolean (new_state));

  g_variant_unref (state);
}

static void // этот обратный вызов отвечает за переключение цветовой схемы приложения с помощью AdwStyleManager API
change_color_scheme (GSimpleAction         *action,
                     GVariant              *new_state,
                     TextViewerApplication *self)
{
  gboolean dark_mode = g_variant_get_boolean (new_state);

  AdwStyleManager *style_manager = adw_style_manager_get_default ();

  if (dark_mode)
    adw_style_manager_set_color_scheme (style_manager, ADW_COLOR_SCHEME_FORCE_DARK);
  else
    adw_style_manager_set_color_scheme (style_manager, ADW_COLOR_SCHEME_DEFAULT);

  g_simple_action_set_state (action, new_state);

  g_settings_set_boolean (self->settings, "dark-mode", dark_mode);
}
