#include "node.h"
#include "../../global_definition/global_def.h"

struct Node {

	/* n.STATE: the state in the state space to which the node corresponds; */
	void* state;

	// n.PARENT: the node in the search tree that generated this node;
	Node* parent;

	// n.ACTION: the action that was applied to the parent to generate the node;
	Action action;

	// n.PATH-COST: the cost, traditionally denoted by g(n), of the path from
	// the initial state to the node, as indicated by the parent pointers.
	double path_cost;
};

Err_Code node_create_node_1(Node **node, void *state);
{
    Err_Code err_code = ERR_CODE_UNKNOWN_ERROR;
    
    if (!node) {
        err_code = ERR_CODE_INVALID_PARAM;
        goto Lb_Exit;
    }
    
    if (*node = malloc(sizeof **node)) {
    	(*node)->state    = state;
        (*node)->parent   = NULL;
		(*node)->action   = NULL;
        (*node)->path_cost = 0.0;
        
        err_code = ERR_CODE_SUCCESS;
    } else {
        *node = NULL;
        
        err_code = ERR_CODE_NOT_ENOUGH_MEMORY;
    }

Lb_Exit:
    return err_code;
}

Err_Code node_create_node_2(Node **node, void *state, Node *parent, Action action, double step_cost)
{
    Err_Code err_code = ERR_CODE_UNKNOWN_ERROR;
    
    if (!node) {
        err_code = ERR_CODE_INVALID_PARAM;
        goto Lb_Exit;
    }
    
    if (*node = malloc(sizeof **node)) {
    	(*node)->state = state;
        (*node)->parent = parent;
		(*node)->action = action;
		(*node)->path_cost = parent->pathCost + stepCost;
        
        err_code = ERR_CODE_SUCCESS;
    } else {
        *node = NULL;
        
        err_code = ERR_CODE_NOT_ENOUGH_MEMORY;
    }

Lb_Exit:    
    return err_code;
}

void* node_get_state(Node *node)
{
    return (node) ? node->state : NULL;
}

Node* node_get_parent(Node *node)
{
    return (node) ? node->parent : NULL;
}

Action node_get_action(Node *node)
{
    return (node) ? node->action : (Action)0;
}

double node_get_path_cost(Node *node)
{
    return (node) ? node->path_cost : -1;
}

char node_is_root_node(Node *node);
{
    if (!node) {
        return -1;
    } else {
        return (NULL == node->parent);
    }
}
    
List* node_get_path_from_root(Node *node)
{
    
}
	public List<Node> getPathFromRoot() {
		List<Node> path = new ArrayList<Node>();
		Node current = this;
		while (!current.isRootNode()) {
			path.add(0, current);
			current = current.getParent();
		}
		// ensure the root node is added
		path.add(0, current);
		return path;
	}
    
void node_clear_path_from_root(List* list)
{

}

void node_delete(void)
{

}