/**
 * Artificial Intelligence A Modern Approach (3rd Edition): page 67.
 * 
 * The goal test, which determines whether a given state is a goal state.
 */

/**
 * @author Pham Phi Long
 * 
 */
 
#ifndef GOAL_TEST
#define GOAL_TEST

typedef struct GoalTest {
	char (*is_goal_state)(void* state);
} GoalTest;

#endif
