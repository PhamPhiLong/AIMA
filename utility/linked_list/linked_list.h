/**
 * @author Pham Phi Long
 * 
 */
 
#ifndef LINKED_LIST
#define LINKED_LIST

#include "list_if.h"
#include "queue_if.h"
#include "stack_if.h"
#include "priority_queue_if.h"

/**
 *  @brief API for List interface
 */
extern List linked_list_get_list_interface(void);

/**
 *  @brief API for Queue interface
 */
extern Queue linked_list_get_queue_interface(void);

/**
 *  @brief API for Stack interface
 */
extern Stack linked_list_get_stack_interface(void);

/**
 *  @brief API for Priority Queue interface
 */
extern Priority_Queue linked_list_get_priority_queue_interface(void);

#endif