/**
 * Artificial Intelligence A Modern Approach (3rd Edition): page 92.
 * 
 * a heuristic function, denoted h(n):<br>
 *   h(n) = estimated cost of the cheapest path from the state at node n to a goal state.<br>
 * 
 * Notice that h(n) takes a node as input, but, unlike g(n) it depends only on the state at that node.
 */

/**
 * @author Pham Phi Long
 * 
 */

#ifndef HEURISTIC_FUNCTION
#define HEURISTIC_FUNCTION
 
typedef struct HeuristicFunction {
	double (*h)(void* state);
} HeuristicFunction;

#endif
