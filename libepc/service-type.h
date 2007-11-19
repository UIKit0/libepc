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
#ifndef __EPC_SERVICE_TYPE_H__
#define __EPC_SERVICE_TYPE_H__

#include <glib.h>

/**
 * EPC_SERVICE_TYPE_HTTP:
 *
 * The well-known DNS-SD service type for #EpcPublisher
 * servers providing unencrypted HTTP access.
 */
#define EPC_SERVICE_TYPE_HTTP   "_easy-publish-http._tcp"

/**
 * EPC_SERVICE_TYPE_HTTPS:
 *
 * The well-known DNS-SD service type for #EpcPublisher
 * servers providing encrypted HTTPS access.
 */
#define EPC_SERVICE_TYPE_HTTPS  "_easy-publish-https._tcp"

G_BEGIN_DECLS

typedef enum
{
  EPC_PROTOCOL_UNKNOWN,
  EPC_PROTOCOL_HTTP,
  EPC_PROTOCOL_HTTPS
}
EpcProtocol;

gchar*                epc_service_type_new          (EpcProtocol  protocol,
                                                     const gchar *application);
gchar*                epc_service_type_build_uri    (EpcProtocol  protocol,
                                                     const gchar *hostname,
                                                     guint16      port,
                                                     const gchar *path);

EpcProtocol           epc_service_type_get_protocol (const gchar *service_type) G_GNUC_CONST;
G_CONST_RETURN gchar* epc_protocol_get_service_type (EpcProtocol  protocol) G_GNUC_CONST;
G_CONST_RETURN gchar* epc_protocol_get_uri_scheme   (EpcProtocol  protocol) G_GNUC_CONST;

G_END_DECLS

#endif /* __EPC_SERVICE_TYPE_H__ */