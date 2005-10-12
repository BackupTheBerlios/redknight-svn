/**************************************************/
/*    Hooks.c - Generic Hook Implementation       */
/*              Basic structure; Linked list of   */
/*              handlers, returning, 1 (success)  */
/*              or 0 (failure)                    */
/**************************************************/

#include "stdio.h"
#include "SDL_types.h"
#include "hooks.h"

int ctk_hook_add (ctk_hook_head *hook_group, int (*func)())
{
    ctk_hook *new_hook, *temp;
    
    if (hook_group == NULL) return -1;
    
    // Allocate a new hook
    new_hook = (ctk_hook *)calloc(1, sizeof(ctk_hook));
    new_hook->func = func;
    new_hook->next = NULL;
    
    if(hook_group->first == NULL)
    {
         hook_group->first = new_hook;
         new_hook->prev = NULL;
    } else {
         temp = hook_group->first;
         while(temp->next != NULL) temp = temp->next;
         temp->next = new_hook;
         new_hook->prev = temp;
    }
    
    return ++hook_group->no_hooks;
}

int ctk_hook_remove (ctk_hook_head *hook_group, Uint8 (*func)())
{
    ctk_hook *temp;
    
    if (hook_group == NULL || hook_group->no_hooks < 1) return -1;
    
    // Find the correct hook
    for(temp = hook_group->first; temp->func != func; temp = temp->next) {
        if (temp->next == NULL) return 0;
    }

    // Re-allocate and free it
    if (temp->prev == NULL)
    {
         // First hook
         if(temp->next == NULL)
         {
               hook_group->first = NULL;
         } else {
               hook_group->first = temp->next;
               hook_group->first->prev = NULL;
         }
    } else {
         if(temp->next == NULL)
         {
               temp->prev->next = NULL;
         } else {
               temp->prev->next = temp->next;
               temp->next->prev = temp->prev;
         }
    }
    
    free(temp);
    
    return 1;
}

int ctk_hook_remove_all (ctk_hook_head *hook_group)
{
    ctk_hook *temp, *f;

    if (hook_group == NULL) return -1;
    
    for(temp = hook_group->first; temp != NULL;) {
         f = temp;
         temp = temp->next;
         free(f);
    }
    
    free(hook_group);
    
    return 1;
}
