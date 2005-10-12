#ifndef __HOOKS_H__
#define __HOOKS_H__

typedef struct CTK_HOOK {
       int (*func)();
       struct CTK_HOOK *prev, *next;
} ctk_hook;

typedef struct CTK_HOOK_HEAD {
        int no_hooks;
        struct CTK_HOOK *first;
} ctk_hook_head;

int ctk_hook_add (ctk_hook_head *hook_group, Uint8 (*func)());
int ctk_hook_remove (ctk_hook_head *hook_group, Uint8 (*func)());


// NOTE: EACH HANDLER NEEDS IT'S OWN HOOK HANDLER, FOR REASONS
//       INVOLVING PASSING ARGUMENTS.
//       THIS HOOKS API ONLY HANDLES ADDITION AND REMOVAL.

#endif // __HOOKS_H__
