/**
 * @author Pham Phi Long
 * 
 */
 
 #ifndef STACK
 #define STACK

 typedef struct Stack {
    /**
     * @brief         Create a Stack
     *
     * @return        A pointer named "instance" pointing to ADT of the module that implements  
     *                this Stack interface   
     */
    void*  (*create_stack)(void);
 
 
    /**
     * @brief         Clone a new Stack from an existing one
     *
     * @param[in]     instance: pointer to ADT of the module that implements this List interface
     * @return        A pointer named "instance" pointing to ADT of the module that implements  
     *                this List interface   
     */
    void*  (*clone)(const void* instance);
    
    
    /**
     * @brief         Check whether a specific Stack is empty.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this Stack interface
     * @return        Returns 1 if this list is empty, otherwise returns 0
     */
    char  (*is_empty)(const void* instance);

    
    /**
     * @brief         Get the quantity of elements in a specific Stack.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this Stack interface
     * @return        The number of current elements in this Stack or -1 for error  
     */
    int   (*get_depth)(const void* instance);     
    
    
    /**
     * @brief         Return the element at the top of a Stack. This function
     *                doesn't remove that element from the Stack.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this Stack interface
     * @param[out]    element : address of the void* pointer variable that will be pointed to
     *                          the corresponding element in Stack
     * @param[out]    element_size: address of the integer variable that will be set equal to the 
     *                              size of corresponding element     
     * @return         0: success
     *                -1: error(input pointer is null, etc.) 
     */
    int   (*peek)(const void* instance, void **element, unsigned int* element_size);
    
    
    /**
     * @brief         Insert an element at the top of a Stack.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this Stack interface
     * @param[in]     element : pointer to the element that you want to add to the Stack
     * @param[in]     element_size: size of the element     
     * @return         0: success
     *                -1: error(input pointer is null, etc.) 
     */
    int   (*push)(void* instance, void *element, unsigned int element_size);    
    
    
    /**
     * @brief         Retrieve and remove the top element of a Stack.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this Stack interface 
     * @return         0: success
     *                -1: error(input pointer is null, etc.) 
     */
    int   (*pop)(void* instance, void **element, unsigned int* element_size);
    
    
    /**
     * @brief         Delete a Stack and all it elements
     *
     * @param[inout]  instance: address of pointer to ADT of the module that implements 
     *                          this Stack interface. This pointer will be set to null
     */
    int  (*delete_stack)(void** instance);    
} Stack;
 
 #endif