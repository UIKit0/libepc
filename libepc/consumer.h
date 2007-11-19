/* Easy Publish and Consume Library
 * Copyright (C) 2007  Openismus GmbH
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
#ifndef __EPC_CONSUMER_H__
#define __EPC_CONSUMER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define EPC_TYPE_CONSUMER           (epc_consumer_get_type())
#define EPC_CONSUMER(obj)           (G_TYPE_CHECK_INSTANCE_CAST(obj, EPC_TYPE_CONSUMER, EpcConsumer))
#define EPC_CONSUMER_CLASS(cls)     (G_TYPE_CHECK_CLASS_CAST(cls, EPC_TYPE_CONSUMER, EpcConsumerClass))
#define EPC_IS_CONSUMER(obj)        (G_TYPE_CHECK_INSTANCE_TYPE(obj, EPC_TYPE_CONSUMER))
#define EPC_IS_CONSUMER_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE(obj, EPC_TYPE_CONSUMER))
#define EPC_CONSUMER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), EPC_TYPE_CONSUMER, EpcConsumerClass))

typedef struct _EpcConsumer        EpcConsumer;
typedef struct _EpcConsumerClass   EpcConsumerClass;
typedef struct _EpcConsumerPrivate EpcConsumerPrivate;

/**
 * EpcConsumer:
 *
 * Public fields of the #EpcConsumer class.
 */
struct _EpcConsumer
{
  /*< private >*/
  GObject parent_instance;
  EpcConsumerPrivate *priv;
};

/**
 * EpcConsumerClass:
 * @parent_class: virtual methods of the base class
 * @authenticate: virtual method of the "authenticate" signal
 *
 * Virtual methods of the #EpcConsumer class.
 */
struct _EpcConsumerClass
{
  /*< private >*/
  GObjectClass parent_class;

  /*< public >*/
  void (*authenticate) (EpcConsumer  *consumer,
                        const gchar  *realm,
                        gchar       **username,
                        gchar       **password);
};

GType        epc_consumer_get_type          (void) G_GNUC_CONST;

EpcConsumer* epc_consumer_new               (const gchar *host,
                                             guint16      port);
EpcConsumer* epc_consumer_new_for_name      (const gchar *name);
EpcConsumer* epc_consumer_new_for_name_full (const gchar *name,
                                             const gchar *service,
                                             const gchar *domain);

gchar*       epc_consumer_lookup            (EpcConsumer *consumer,
                                             const gchar *key,
                                             gsize       *length);

G_END_DECLS

#endif /* __EPC_CONSUMER_H__ */
