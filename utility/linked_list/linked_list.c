/**
 * @author Pham Phi Long
 * 
 */

#include "global_def.h" 
#include "linked_list.h"
#include <stdlib.h>

/** MACROS, DEFS *************************************************************/
typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
    Node            *next_node;
    Node            *prev_node;
    void            *data;
    unsigned int    data_size;
};

struct LinkedList {
    Node            *head_node;
    Node            *tail_node;
    unsigned int    node_number;
    Comparable  comparable;
};

/** FUNCS DECL ***************************************************************/
static void* create_linked_list(void);
static void* clone_linked_list(const void* instance);
static char is_empty(const void* instance);
static int get_size(const void* instance);
static int get(const void* instance, unsigned int position, void **element, unsigned int* element_size);
static int add(void* instance, unsigned int position, void *element, unsigned int element_size);
static int remove(void* instance, unsigned int position);
static int delete_linked_list(void** instance);
static int stack_push(void* instance, void *element, unsigned int element_size);
static int stack_peek(const void* instance, void **element, unsigned int* element_size);
static int stack_pop(void* instance, void **element, unsigned int* element_size);
static int queue_get_front(const void* instance, void **element, unsigned int* element_size);
static int queue_dequeue(void* instance, void **element, unsigned int* element_size);
static void* create_priority_queue(Comparable comparable);
static int priority_queue_enqueue(void* instance, void *element, unsigned int element_size);
static Node* get_node_at_position(LinkedList *lnk_list, unsigned int position);
static void* copy_memory(void *destination, const void *source, unsigned int size);

/** GLOBAL VARIABLES *********************************************************/
static const List list_interface = {
                                    create_linked_list,     /* create_list */
                                    clone_linked_list,      /* clone       */
                                    is_empty,               /* is_empty    */
                                    get_size,               /* get_size    */
                                    get,                    /* get         */
                                    add,                    /* add         */
                                    remove,                 /* remove      */
                                    delete_linked_list      /* delete_list */
                                   };
                                    
static const Queue queue_interface = {
                                      create_linked_list,   /* create_queue */
                                      clone_linked_list,    /* clone        */
                                      is_empty,             /* is_empty     */
                                      get_size,             /* get_size     */
                                      queue_get_front,      /* get_front    */
                                      stack_push,           /* enqueue      */                           
                                      queue_dequeue,        /* dequeue      */
                                      delete_linked_list    /* delete_queue */
                                     };

static const Stack stack_interface = {
                                      create_linked_list,   /* create_stack */
                                      clone_linked_list,    /* clone        */
                                      is_empty,             /* is_empty     */
                                      get_size,             /* get_depth    */
                                      stack_peek,           /* peek         */
                                      stack_push,           /* push         */                             
                                      stack_pop,            /* pop          */
                                      delete_linked_list    /* delete_stack */
                                     };

static const Priority_Queue priority_queue_interface = {
                                                        create_priority_queue,   /* create_priority_queue */
                                                        clone_linked_list,       /* clone                 */
                                                        is_empty,                /* is_empty              */
                                                        get_size,                /* get_size              */
                                                        queue_get_front,         /* get_front             */
                                                        priority_queue_enqueue,  /* enqueue               */                           
                                                        queue_dequeue,           /* dequeue               */
                                                        delete_linked_list       /* delete_priority_queue */
                                                       };  
                                   
/** APIS DEF *****************************************************************/

/**
 *  @brief API for List interface
 */
List linked_list_get_list_interface(void)
{
    return list_interface;
}

/**
 *  @brief API for Queue interface
 */
Queue linked_list_get_queue_interface(void)
{
    return queue_interface;
}

/**
 *  @brief API for Stack interface
 */
Stack linked_list_get_stack_interface(void)
{
    return stack_interface;
}

/**
 *  @brief API for Priority Queue interface
 */
Priority_Queue linked_list_get_priority_queue_interface(void)
{
    return priority_queue_interface;
}

/** INTERNAL FUNC DEF ********************************************************/

static void* create_linked_list(void)
{
    LinkedList    *lnk_list = malloc(sizeof(*lnk_list));
    
    /* Check input parameters */
    if (lnk_list) {        
        lnk_list->head_node   = NULL;
        lnk_list->tail_node   = NULL;
        lnk_list->node_number = 0;
        lnk_list->comparable.compare  = NULL;
    } 
    
    return lnk_list;
}

static void* clone_linked_list(const void* instance)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    LinkedList    *cloned_lnk_list;
    Node          *node;
	Node          *next_node;
    Node          **p_cloned_node;
    unsigned int  i;
    
    /* Check input parameters */
    if (!lnk_list) {        
        return NULL;
    } 
    
	/* Create a new LinkedList */
    cloned_lnk_list = malloc(sizeof(*clone_linked_list));
    if (!lnk_list) {
        goto LbErr;
    } else {
        cloned_lnk_list->head_node   = NULL;
        cloned_lnk_list->tail_node   = NULL;
        cloned_lnk_list->node_number = lnk_list->node_number;
        cloned_lnk_list->comparable  = lnk_list->comparable;
    }
    
	/* Create and copy Node by Node from existing LinkedList to the cloned one */
    for (i = 0; i < lnk_list->node_number; i++) {        
        if (!i) {		/* Head node */
            cloned_lnk_list->head_node = malloc(sizeof(*cloned_lnk_list->head_node));
            node = lnk_list->head_node;            
            if (!cloned_lnk_list->head_node || !node) {
                goto LbFreeCloList;
            }
			
            p_cloned_node = &cloned_lnk_list->head_node;
        } else {            
            node = node->next_node;
            if (!(*p_cloned_node)->next_node || !node) {
                goto LbFreeNode;
            }
			
            (*p_cloned_node)->next_node = malloc(sizeof(*cloned_lnk_list->head_node));
			if (!(*p_cloned_node)->next_node || !node) {
                goto LbFreeNode;
            }
			
			p_cloned_node = &(*p_cloned_node)->next_node;		
        }
		
		(*p_cloned_node)->data = malloc(node->data_size);
		if (!(*p_cloned_node)->data) {
			goto LbFreeNode;
		}
		
		(*p_cloned_node)->data_size = node->data_size;       
    }
	
	cloned_lnk_list->tail_node = *p_cloned_node;
    goto LbSuccess;
	
LbFreeNode:
	node = cloned_lnk_list->head_node;
	
	while (node) {
		next_node = node->next_node;
		free(node->data);
		free(node);
		node = next_node;
	}
    
LbFreeCloList:
	free(cloned_lnk_list);
	
LbErr:
    return NULL;
	
LbSuccess:
    return cloned_lnk_list;
}

static char is_empty(const void* instance)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    
    /* Check input parameters */
    if (!lnk_list) {
        return TRUE;
    } 
    
    return (lnk_list->node_number) ? TRUE : FALSE;
}

static int get_size(const void* instance)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    
    /* Check input parameters */
    if (!lnk_list) {
        return -1;
    }    
    
    return lnk_list->node_number;
}

static int get(const void* instance, unsigned int position, void **element, unsigned int* element_size)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    Node          *node;
    
    /* Check input parameters */
    if (!instance || (position > lnk_list->node_number - 1) || !element || !element_size) {
        return -1;
    }
    
    node = get_node_at_position(lnk_list, position);
    
    *element      = node->data;
    *element_size = node->data_size;
    
    return 0;
}

static int add(void* instance, unsigned int position, void *element, unsigned int element_size)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    Node          *new_node;
    Node          *node;
    Node          *next_node;    
    
    /* Check input parameters */
    if (!instance || (position > lnk_list->node_number) || !element || !element_size) {
        return -1;
    }
    
    new_node = malloc(sizeof(*new_node));
    if (new_node) {
        new_node->data = malloc(element_size);
        if (new_node->data) {
            new_node->data_size = element_size;
            copy_memory(new_node->data, element, element_size); /* Copy data to the new node */
        } else {
            free(new_node);
            return -1;
        }
    } else {
        return -1;
    }
    
    /* Append new node to List */
    if (!position) {         /* Append to root */
        new_node->next_node = lnk_list->head_node;
        new_node->prev_node = NULL;
        lnk_list->head_node->prev_node = new_node;        
        lnk_list->head_node = new_node;           
    } else if (position == lnk_list->node_number) {     /* Append to tail */
        new_node->prev_node = lnk_list->tail_node;
        new_node->next_node = NULL;
        lnk_list->tail_node->next_node = new_node;
        lnk_list->tail_node = new_node;
    } else {                /* Append to middle of List */
        /* Find the (position - 1) node */    
        node = get_node_at_position(lnk_list, position - 1);
        
        /* Find the (position) node */
        next_node = node->next_node;
        
        /* Append the new node */
        new_node->prev_node  = node; 
        new_node->next_node  = next_node;
        node->next_node      = new_node;        
        next_node->prev_node = new_node;
    }
    
    lnk_list->node_number++; 
    
    return 0;
}

static int remove(void* instance, unsigned int position)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    Node          *prev_node;
    Node          *node;
    Node          *next_node;
    
    /* Check input parameters */
    if (!instance || (position > lnk_list->node_number - 1)) {
        return -1;
    }
    
    /* Remove node from List */
    if (!position) {         /* Remove at root */
        next_node = lnk_list->head_node->next_node;
        next_node-> prev_node = NULL;        
        /* Free dynamic memory in Node */
        free(lnk_list->head_node->data);
        free(lnk_list->head_node);
        /* Assign Root node to the right after node */
        lnk_list->head_node = next_node;
    } else if (position == lnk_list->node_number - 1) {     /* Remove from tail */
        prev_node = lnk_list->tail_node->prev_node;
        prev_node->next_node = NULL;
        /* Free dynamic memory in Node */
        free(lnk_list->tail_node->data);
        free(lnk_list->tail_node);
        /* Assign Root node to the right before node */
        lnk_list->tail_node = prev_node;        
    } else {                /* Remove from middle of List */         
        node = get_node_at_position(lnk_list, position);
        
        /* Find the (position - 1) node */
        prev_node = node->prev_node;
        
        /* Find the (position + 1) node */
        next_node = node->next_node;
        
        /* Update */
        prev_node->next_node = next_node;
        next_node->prev_node = prev_node;
        
        /* Free dynamic memory in Node */
        free(node->data);
        free(node);
    }
    
    lnk_list->node_number--; 
    
    return 0;
}

static int delete_linked_list(void** instance)
{
    LinkedList    *lnk_list;;
    Node          *node;
    Node          *next_node;
    unsigned int  i;
    
    /* Check input parameters */
    if (!instance) {
        return -1;
    }
    
    lnk_list = *(LinkedList**)instance;
    
    node = lnk_list->head_node;    
    for (i = 0; (i < lnk_list->node_number - 1); i++) {
        next_node = node->next_node;
        free(node->data);
        free(node);
        node = next_node;
    }
    
    free(lnk_list);
    *(LinkedList**)instance = NULL;
    
    return 0;
}

static int stack_push(void* instance, void *element, unsigned int element_size)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
        
    /* Check input parameters */
    if (!lnk_list) {
        return -1;
    }
        
    return add(instance, lnk_list->node_number, element, element_size);
}

static int stack_peek(const void* instance, void **element, unsigned int* element_size)
{
    LinkedList *lnk_list = (LinkedList*)instance;
        
    /* Check input parameters */
    if (!lnk_list) {
        return -1;
    }
    
    return get(instance, lnk_list->node_number - 1, element, element_size);
}

static int stack_pop(void* instance, void **element, unsigned int* element_size)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
        
    /* Check input parameters */
    if (!lnk_list) {
        return -1;
    }
    
    get(instance, lnk_list->node_number - 1, element, element_size);
    
    return remove(instance, lnk_list->node_number - 1);
}

static int queue_get_front(const void* instance, void **element, unsigned int* element_size)
{
    return get(instance, 0U, element, element_size);
}

static int queue_dequeue(void* instance, void **element, unsigned int* element_size)
{
    get(instance, 0U, element, element_size);
    
    return remove(instance, 0U);
}

static void* create_priority_queue(Comparable comparable)
{
    LinkedList    *lnk_list = create_linked_list();
    
    if (lnk_list) {
        lnk_list->comparable = comparable;
    }
    
    return lnk_list;
}

static int priority_queue_enqueue(void* instance, void *element, unsigned int element_size)
{
    LinkedList    *lnk_list = (LinkedList*)instance;
    Node          *node;    
    int           queue_size;
    unsigned int  i;
    
    queue_size = get_size(instance);
    if (-1 == queue_size) {
        return -1;
    }
    
    for (i = 0U; (i < (unsigned int)queue_size); i++) {
        node = get_node_at_position(lnk_list, i);
        
        if (lnk_list->comparable.compare(element, node->data) > 0) {
            return add(instance, i, element, element_size);
        }
    }
    
    /** All the elements in this list have priority greater or equal to 
     *  the new added one, thus should add it to the tail. 
     */
    return add(instance, queue_size, element, element_size);
}

static Node* get_node_at_position(LinkedList *lnk_list, unsigned int position)
{
    unsigned int i;
    
    Node *node = lnk_list->head_node;    
    for (i = 0; (i < position); i++) {
        node = node->next_node;
    }
    
    return node;
}

static void* copy_memory(void *destination, const void *source, unsigned int size)     
{             
    char         *dst = destination;
    const char   *src = source;    
    unsigned int i;
    
    for (i = 0; (i < size); dst[i] = src[i], i++) ; 
    
    return destination;
}