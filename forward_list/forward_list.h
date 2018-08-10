/*!
 * @author Ankit Gupta
 * @version 0.1
 * @date 10 Aug 2018
 * @brief Implementation of forward_list
 * @details Header file as interface for forward_list
 */
/*!
 * @typedef node_t NODE includes a generic data element and pointer to next node
 */
typedef struct node_t{
   void* data;           //!> @var data pointer to void generic data holder
   NODE* next_node;      //!> @var next_node pointer to next node
} NODE;