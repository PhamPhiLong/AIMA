/**
 * Artificial Intelligence A Modern Approach (3rd Edition): page 92.
 * 
 * The evaluation function is construed as a cost estimate, so the node with the lowest evaluation 
 * is expanded first.
 */

/**
 * @author Pham Phi Long
 * 
 */

 #ifndef EVALUATION_FUNCTION
 #define EVALUATION_FUNCTION
 
 typedef struct EvaluationFunction {
	double (*f)(Node *n);
} EvaluationFunction;

#endif
