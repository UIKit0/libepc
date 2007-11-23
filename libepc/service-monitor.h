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

#ifndef __EPC_SERVICE_MONITOR_H__
#define __EPC_SERVICE_MONITOR_H__

#include <glib-object.h>
#include <libepc/protocol.h>

G_BEGIN_DECLS

#define EPC_TYPE_SERVICE_MONITOR           (epc_service_monitor_get_type())
#define EPC_SERVICE_MONITOR(obj)           (G_TYPE_CHECK_INSTANCE_CAST(obj, EPC_TYPE_SERVICE_MONITOR, EpcServiceMonitor))
#define EPC_SERVICE_MONITOR_CLASS(cls)     (G_TYPE_CHECK_CLASS_CAST(cls, EPC_TYPE_SERVICE_MONITOR, EpcServiceMonitorClass))
#define EPC_IS_SERVICE_MONITOR(obj)        (G_TYPE_CHECK_INSTANCE_TYPE(obj, EPC_TYPE_SERVICE_MONITOR))
#define EPC_IS_SERVICE_MONITOR_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE(obj, EPC_TYPE_SERVICE_MONITOR))
#define EPC_SERVICE_MONITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), EPC_TYPE_SERVICE_MONITOR, EpcServiceMonitorClass))

typedef struct _EpcServiceMonitor        EpcServiceMonitor;
typedef struct _EpcServiceMonitorClass   EpcServiceMonitorClass;
typedef struct _EpcServiceMonitorPrivate EpcServiceMonitorPrivate;

/**
 * EpcServiceMonitor:
 *
 * Public fields of the #EpcServiceMonitor class.
 */
struct _EpcServiceMonitor
{
  /*< private >*/
  GObject parent_instance;
  EpcServiceMonitorPrivate *priv;

  /*< public >*/
};

/**
 * EpcServiceMonitorClass:
 * @service_found: virtual method of the #EpcServiceMonitor::service-found signal
 * @service_removed: virtual method of the #EpcServiceMonitor::service-removed signal
 * @done: virtual method of the #EpcServiceMonitor::done signal
 *
 * Virtual methods of the #EpcServiceMonitor class.
 */
struct _EpcServiceMonitorClass
{
  /*< private >*/
  GObjectClass parent_class;

  /*< public >*/
  void (*service_found)   (EpcServiceMonitor *monitor,
                           const gchar       *type,
                           const gchar       *name,
                           const gchar       *host,
                           guint              port);
  void (*service_removed) (EpcServiceMonitor *monitor,
                           const gchar       *type,
                           const gchar       *name);
  void (*done)            (EpcServiceMonitor *monitor,
                           const gchar       *type);
};

GType              epc_service_monitor_get_type      (void) G_GNUC_CONST;

EpcServiceMonitor* epc_service_monitor_new           (const gchar *application,
                                                      const gchar *domain,
                                                      EpcProtocol  first_protocol,
                                                                   ...);
EpcServiceMonitor* epc_service_monitor_new_for_types (const gchar *domain,
                                                      const gchar *first_service_type,
                                                                   ...)
                                                      G_GNUC_NULL_TERMINATED;

G_END_DECLS

#endif /* __EPC_SERVICE_MONITOR_H__ */ 
