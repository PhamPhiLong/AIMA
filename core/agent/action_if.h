/**
 * Describes an Action that can or has been taken by an Agent via one of its Actuators. 
 */

/**
 * @author Ciaran O'Reilly
 */
 
#ifndef ACTION
#define ACTION
 
typedef struct Action {

	/**
	 * Indicates whether or not this Action is a 'No Operation'.<br>
	 * Note: AIMA3e - NoOp, or no operation, is the name of an assembly
	 * language instruction that does nothing.
	 * 
	 * @return true if this is a NoOp Action.
	 */
	char (*is_no_op)(void);
} Action;

#endif
