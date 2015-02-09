/**
 * @author Pham Phi Long
 * 
 */
 
 #ifndef QUEUE
 #define QUEUE

 typedef struct Queue {
    /**
     * @brief         Create a Queue
     *
     * @return        A pointer named "instance" pointing to ADT of the module that implements  
     *                this Queue interface   
     */
    void*  (*create_queue)(void);
 

    /**
     * @brief         Clone a new Queue from an existing one
     *
     * @param[in]     instance: pointer to ADT of the module that implements this List interface
     * @return        A pointer named "instance" pointing to ADT of the module that implements  
     *                this List interface   
     */
    void*  (*clone)(const void* instance);
    
    
    /**
     * @brief         Check whether a specific Queue is empty.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this Queue interface
     * @return        Returns 1 if this list is empty, otherwise returns 0
     */
    char  (*is_empty)(const void* instance);

    
    /**
     * @brief         Get the quantity of elements in a specific Queue.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this Queue interface
     * @return        The number of current elements in this Queue or -1 for error  
     */
    int   (*get_size)(const void* instance); 

    
    /**
     * @brief         Return the head element of a Queue. This function
     *                doesn't remove that element from the Queue.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this Queue interface
     * @param[out]    element : address of the void* pointer variable that will be pointed to
     *                          the corresponding element in Queue
     * @param[out]    element_size: address of the integer variable that will be set equal to the 
     *                              size of corresponding element     
     * @return         0: success
     *                -1: error(input pointer is null, etc.) 
     */
    int   (*get_front)(const void* instance, void **element, unsigned int* element_size);
    
    
    /**
     * @brief         Add an element at the back of a Queue.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this Queue interface
     * @param[in]     element : pointer to the element that you want to add to the Queue
     * @param[in]     element_size: size of the element     
     * @return         0: success
     *                -1: error(input pointer is null, etc.) 
     */
    int   (*enqueue)(void* instance, const void *element, unsigned int element_size);
    
    
    /**
     * @brief         Retrieve and Remove the head element of a Queue.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this Queue interface
     * @return         0: success
     *                -1: error(input pointer is null, etc.) 
     */
    int   (*dequeue)(void* instance, void **element, unsigned int* element_size);
    
    
    /**
     * @brief         Delete a Queue and all it elements
     *
     * @param[inout]  instance: address of pointer to ADT of the module that implements 
     *                          this Queue interface. This pointer will be set to null
     */
    int  (*delete_queue)(void** instance);    
} Queue;
 
 #endif