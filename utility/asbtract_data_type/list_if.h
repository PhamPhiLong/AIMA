/**
 * @author Pham Phi Long
 * 
 */
 
 #ifndef LIST
 #define LIST

 typedef struct List {
    /**
     * @brief         Create a List
     *
     * @return        A pointer named "instance" pointing to ADT of the module that implements  
     *                this List interface   
     */
    void*  (*create_list)(void);
    
    
    /**
     * @brief         Clone a new List from an existing one
     *
     * @param[in]     instance: pointer to ADT of the module that implements this List interface
     * @return        A pointer named "instance" pointing to ADT of the module that implements  
     *                this List interface   
     */
    void*  (*clone)(const void* instance);
    
    
    /**
     * @brief         Check whether a specific List is empty.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this List interface
     * @return        Returns 1 if this list is empty, otherwise returns 0
     */
    char  (*is_empty)(const void* instance);

    
    /**
     * @brief         Get the quantity of elements in a specific List.
     *
     * @param[in]     instance: pointer to ADT of the module that implements this List interface
     * @return        The number of current elements in this List or -1 for error  
     */
    int   (*get_size)(const void* instance); 

    
    /**
     * @brief         Get an element at specific position in a List. This function
     *                doesn't remove that element from the List.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this List interface
     * @param[in]     position: the position in List which you want to get element 
     * @param[out]    element : address of the void* pointer variable that will be pointed to
     *                          the corresponding element in List
     * @param[out]    element_size: address of the integer variable that will be set equal to the 
     *                              size of corresponding element     
     * @return         0: success
     *                -1: error(negative position, out of bound position, input pointer is null, etc.) 
     */
    int   (*get)(const void* instance, unsigned int position, void **element, unsigned int* element_size);
    
    
    /**
     * @brief         Add an element at specific position to a List.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this List interface
     * @param[in]     position: the position in List which you want to add element 
     * @param[in]     element : pointer to the element that you want to add to the List
     * @param[in]     element_size: size of the element     
     * @return         0: success
     *                -1: error(negative position, out of bound position, input pointer is null, etc.) 
     */
    int   (*add)(void* instance, unsigned int position, const void *element, unsigned int element_size);
    
    
    /**
     * @brief         Remove an element in a specific position in a List.
     *
     * @param[inout]  instance: pointer to ADT of the module that implements this List interface
     * @param[in]     position: the position in List which you want to remove element    
     * @return         0: success
     *                -1: error(negative position, out of bound position, input pointer is null, etc.) 
     */
    int   (*remove)(void* instance, unsigned int position);
    
    
    /**
     * @brief         Delete a List and all it elements
     *
     * @param[inout]  instance: address of pointer to ADT of the module that implements 
     *                          this List interface. This pointer will be set to null
     */
    int  (*delete_list)(void** instance);    
} List;
 
 #endif