/* Easy Publish and Consume Library
 * Copyright (C) 2007, 2008  Openismus GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors:
 *      Mathias Hasselmann
 */
#ifndef __EPC_PASSWORD_DIALOG_H__
#define __EPC_PASSWORD_DIALOG_H__

#include <gtk/gtk.h>
#include <libepc/consumer.h>

G_BEGIN_DECLS

#define EPC_TYPE_PASSWORD_DIALOG           (epc_password_dialog_get_type())
#define EPC_PASSWORD_DIALOG(obj)           (G_TYPE_CHECK_INSTANCE_CAST(obj, EPC_TYPE_PASSWORD_DIALOG, EpcPasswordDialog))
#define EPC_PASSWORD_DIALOG_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST(klass, EPC_TYPE_PASSWORD_DIALOG, EpcPasswordDialogClass))
#define EPC_IS_PASSWORD_DIALOG(obj)        (G_TYPE_CHECK_INSTANCE_TYPE(obj, EPC_TYPE_PASSWORD_DIALOG))
#define EPC_IS_PASSWORD_DIALOG_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE(obj, EPC_TYPE_PASSWORD_DIALOG))
#define EPC_PASSWORD_DIALOG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), EPC_TYPE_PASSWORD_DIALOG, EpcPasswordDialogClass))

typedef struct _EpcPasswordDialog        EpcPasswordDialog;
typedef struct _EpcPasswordDialogClass   EpcPasswordDialogClass;
typedef struct _EpcPasswordDialogPrivate EpcPasswordDialogPrivate;

/**
 * EpcPasswordDialog:
 *
 * Public fields of the #EpcPasswordDialog class.
 */
struct _EpcPasswordDialog
{
  /*< private >*/
  GtkDialog parent_instance;
  EpcPasswordDialogPrivate *priv;

  /*< public >*/
};

/**
 * EpcPasswordDialogClass:
 *
 * Virtual methods of the #EpcPasswordDialog class.
 */
struct _EpcPasswordDialogClass
{
  /*< private >*/
  GtkDialogClass parent_class;

  /*< public >*/
};

GType                 epc_password_dialog_get_type              (void) G_GNUC_CONST;
GtkWidget*            epc_password_dialog_new                   (const gchar       *title,
                                                                 GtkWindow         *parent,
                                                                 const gchar       *realm,
                                                                 const gchar       *first_button_text,
                                                                 ...) G_GNUC_NULL_TERMINATED;

void                  epc_password_dialog_set_anonymous_allowed (EpcPasswordDialog *dialog,
                                                                 gboolean           allowed);
gboolean              epc_password_dialog_get_anonymous_allowed (EpcPasswordDialog *dialog);

void                  epc_password_dialog_set_anonymous         (EpcPasswordDialog *dialog,
                                                                 gboolean           anonymous);
gboolean              epc_password_dialog_is_anonymous          (EpcPasswordDialog *dialog);

void                  epc_password_dialog_set_username          (EpcPasswordDialog *dialog,
                                                                 const gchar       *username);
const gchar* epc_password_dialog_get_username          (EpcPasswordDialog *dialog);

void                  epc_password_dialog_set_password          (EpcPasswordDialog *dialog,
                                                                 const gchar       *password);
const gchar* epc_password_dialog_get_password          (EpcPasswordDialog *dialog);

void                  epc_password_dialog_set_realm             (EpcPasswordDialog *dialog,
                                                                 const gchar       *realm);
const gchar* epc_password_dialog_get_realm             (EpcPasswordDialog *dialog);

void                  epc_password_dialog_attach                (EpcPasswordDialog *dialog,
                                                                 EpcConsumer       *consumer);
G_END_DECLS

#endif /* __EPC_PASSWORD_DIALOG_H__ */
