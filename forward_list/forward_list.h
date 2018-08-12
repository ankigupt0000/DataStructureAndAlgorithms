/**
 * @brief Implementation of forward_list
 * @author Ankit Gupta
 * @version 0.1
 * @date 10 Aug 2018
 * 
 * @details Header file as interface for forward_list
 */

/**
 * @brief structure for forward_list node
 * @typedef node_t NODE 
 */
typedef struct node_t{
   void* data;                    /**< @var data pointer to void generic data holder */
   struct node_t* next_node;      /**< @var next_node pointer to next node */
} NODE;

/**
 * @brief returns address of pointer to first node.
 * 
 * @return NODE**
 */
NODE** before_begin();

/**
 * @brief Construct a new push front object
 * 
 * @param val 
 */
int push_front(void* val);
