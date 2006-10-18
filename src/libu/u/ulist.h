/*******************************************************************************
* Copyright (C) 2006 Intel Corp. All rights reserved.
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
 * @author Denis Sadykov
 */

#ifndef ULIST_H
#define ULIST_H

#include "libu_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct u_list {
	void		*data;
	struct u_list	*next;
	struct u_list	*prev;
} u_list_t;

u_list_t* u_list_alloc(void);
void u_list_free(u_list_t *list);
u_list_t* u_list_first(u_list_t *list);
u_list_t* u_list_last(u_list_t *list);
u_list_t* u_list_next(u_list_t *list);
u_list_t* u_list_previous(u_list_t *list);
u_list_t* u_list_append(u_list_t *list, void *data);
u_list_t* u_list_prepend(u_list_t *list, void *data);
u_list_t* u_list_find(u_list_t *list, void *data);
unsigned int u_list_position(u_list_t *list, u_list_t *link);
u_list_t* u_list_remove_link(u_list_t *list, u_list_t *link);
u_list_t* u_list_delete_link(u_list_t *list, u_list_t *link);
unsigned int u_list_length(u_list_t *list);
u_list_t* u_list_concat(u_list_t *list1, u_list_t *list2);

#ifdef __cplusplus
}
#endif

#endif /* ULIST_H */