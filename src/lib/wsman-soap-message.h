/*******************************************************************************
 * Copyright (C) 2004-2006 Intel Corp. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  - Neither the name of Intel Corp. nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/

/**
 * @author Anas Nashif
 */

#ifndef WSMAN_SOAP_MESSAGE_H_
#define WSMAN_SOAP_MESSAGE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "u/libu.h"

#define FLAG_IDENTIFY_REQUEST    1

struct _WsmanAuth {
    char *username;
    char *password;
};
typedef struct _WsmanAuth WsmanAuth;

struct _WsmanStatus {
  WsmanFaultCodeType fault_code;
  WsmanFaultDetailType fault_detail_code;
  char *fault_msg;
};
typedef struct _WsmanStatus WsmanStatus;


struct _WsmanMessage {
  const char          *method;
  WsmanStatus         status;
  u_buf_t     *request;
  u_buf_t     *response;
  WsXmlDocH           in_doc;
  WsmanKnownStatusCode http_code;
  WsmanAuth           auth_data;
  unsigned int        flags;
};
typedef struct _WsmanMessage WsmanMessage;

void wsman_set_message_flags(WsmanMessage *msg, unsigned int flag);

WsmanMessage *wsman_soap_message_new(void);
void wsman_soap_message_destroy(WsmanMessage* wsman_msg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
