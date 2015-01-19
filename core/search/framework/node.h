/**
 * Artificial Intelligence A Modern Approach (3rd Edition): Figure 3.10, page 79.<br>
 * 
 * Figure 3.10 Nodes are the data structures from which the search tree is constructed. Each
 * has a parent, a state, and various bookkeeping fields. Arrows point from child to parent.<br>
 * <br>
 * Search algorithms require a data structure to keep track of the search tree that is being
 * constructed. For each node n of the tree, we have a structure that contains four components:
 * <ul>
 * <li>n.STATE: the state in the state space to which the node corresponds;</li>
 * <li>n.PARENT: the node in the search tree that generated this node;</li>
 * <li>n.ACTION: the action that was applied to the parent to generate the node;</li>
 * <li>n.PATH-COST: the cost, traditionally denoted by g(n), of the path from the initial state
 * to the node, as indicated by the parent pointers.</li>
 * </ul>
 */

/**
 * @author Pham Phi Long
 *
 */

#ifndef NODE
#define NODE

#include "../../agent/action_if.h"

typedef struct Node Node;
 
extern Err_Code node_create_node_1(Node **node, void *state);

extern Err_Code node_create_node_2(Node **node, void *state, Node *parent, Action action, double step_cost);

extern void* node_get_state(Node *node);

extern Node* node_get_parent(Node *node);  

extern Action node_get_action(Node *node);

extern double node_get_path_cost(Node *node);   

extern char node_is_root_node(Node *node);

extern List* node_get_path_from_root(Node *node);
    
extern void node_clear_path_from_root(List* list);

extern void node_delete(void);

#endif
