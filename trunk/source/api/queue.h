#ifndef __CTK_QUEUE_H__
#define __CTK_QUEUE_H__


// MACRO DEFINITIONS
#define CTK_NO_QUEUE        -1
#define CTK_EMPTY_QUEUE     -2
#define CTK_FULL_QUEUE      -3


// TYPE DEFINITIONS
typedef struct CTK_QUEUE {
    void *data;
    struct CTK_QUEUE *next;
} ctk_queue_node;

typedef struct CTK_QUEUE_HEAD {
    int len, maxlen;
    struct CTK_QUEUE *head, *tail;
} ctk_queue;


// PUBLIC FUNCTION PROTOTYPES
ctk_queue     *ctk_queue_create  (int maxlen);
int            ctk_queue_push    (ctk_queue *q, void *data);
void          *ctk_queue_peep    (ctk_queue *q);
int            ctk_queue_pop     (ctk_queue *q);
int            ctk_queue_size    (ctk_queue *q);
int            ctk_queue_isempty (ctk_queue *q);
int            ctk_queue_delete  (ctk_queue *q);


#endif // __CTK_QUEUE_H__
