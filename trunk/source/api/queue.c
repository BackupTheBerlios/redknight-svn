/********************************************************/
/*  api/queue.c - A queueing implementation for the     */
/*                Cavalier ToolKit Project.             */
/********************************************************/

// FILE INCLUSIONS
#include <stdio.h>
#include <SDL_types.h>
#include "queue.h"


// MACRO DEFINITIONS
#define __ctk_queue_exists(q) \
     if(q == NULL) { return CTK_NO_QUEUE; }
#define __ctk_queue_isntempty(q) \
     if(q->len <= 0) { return CTK_EMPTY_QUEUE; }
#define __ctk_queue_hasspace(q) \
     if(q->len >= q->maxlen) { return CTK_FULL_QUEUE; }
     
#define __ctk_queue_exists_cast(q,cast) \
     if(q == NULL) { return (cast *)CTK_NO_QUEUE; }
#define __ctk_queue_isntempty_cast(q,cast) \
     if(q->len <= 0) { return (cast *)CTK_EMPTY_QUEUE; }
#define __ctk_queue_hasspace_cast(q,cast) \
     if(q->len >= q->maxlen) { return (cast *)CTK_FULL_QUEUE; }


// PUBLIC FUNCTIONS

ctk_queue *ctk_queue_create(int maxlen)
{
     ctk_queue *q = (ctk_queue *)malloc(sizeof(ctk_queue));
     
     q->len = 0;
     q->maxlen = maxlen;
     q->head = q->tail = NULL;
     
     return q;
}

int ctk_queue_push(ctk_queue *q, void *data)
{
    ctk_queue_node *qn;
    
    __ctk_queue_exists(q);
    __ctk_queue_hasspace(q);
    
    qn = (ctk_queue_node *)malloc(sizeof(ctk_queue_node));
    qn->data = data;     // Assign data to a new pointer, but we need a size.
    q->tail->next = NULL;           // In case q->len gets messed up
    
    if(q->len == 0)
    {
        q->tail = qn;
        q->head = qn;
    } else {
        q->tail->next = qn;
        q->tail = qn;
    }
    
    return ++q->len;
}

void *ctk_queue_peep(ctk_queue *q)
{
     __ctk_queue_exists_cast(q,void);
     __ctk_queue_isntempty_cast(q,void);
     
     return q->head->data;
}

int ctk_queue_pop(ctk_queue *q)
{
     ctk_queue_node *f;
     
     __ctk_queue_exists(q);
     __ctk_queue_isntempty(q);
     
     f = q->head;
     q->head = f->next;
     
     free(f);          // We'll assume f->data hasn't been malloc'd for us.
                       // We need to change this to use it's own memory in the
                       //     future.
     
     return --q->len;
}

int ctk_queue_size(ctk_queue *q)
{
     __ctk_queue_exists(q);
     
     return q->len;
}

int ctk_queue_isempty(ctk_queue *q)
{
     __ctk_queue_exists(q);
     
     return (q->len > 0) ? 1 : 0;
}

int ctk_queue_delete(ctk_queue *q)
{
     ctk_queue_node *f, *n;
    
     __ctk_queue_exists(q);
     
     // Delete all of the nodes
     // This has slight speed improvements over using
     // ctk_queue_pop until q->len == 0
     n = q->head;
     
     while(n->next != NULL) {
          f = n;
          n = n->next;
          free(f);          // Assume we aren't storing malloc'd data.
     }
     
     // Free the remaining node, and the header
     free(n);
     free(q);
     
     return 0;
}
