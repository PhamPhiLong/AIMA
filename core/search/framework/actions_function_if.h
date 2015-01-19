/**
 * Artificial Intelligence A Modern Approach (3rd Edition): page 67.
 * 
 * Given a particular state s, ACTIONS(s) returns the set of actions that can be
 * executed in s. We say that each of these actions is <b>applicable</b> in s.
 */

/**
 * @author Pham Phi Long
 * 
 */

#ifndef ACTIONS_FUNCTION
#define ACTIONS_FUNCTION

typedef struct ActionsFunction {
	/**
	 * Given a particular state s, returns the set of actions that can be
	 * executed in s.
	 * 
	 * @param s
	 *            a particular state.
	 * @return the set of actions that can be executed in s.
	 */
	List* (*actions)(void* s);
    
    void (*clear_actions)(struct List **list);
} ActionsFunction;

#endif
