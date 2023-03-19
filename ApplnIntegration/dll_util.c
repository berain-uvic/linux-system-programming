#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

/*More functions*/
int  /*return 0 on success and -1 on failure*/
remove_data_from_dll_by_data_ptr (dll_t *dll, void *data){
    if(!dll || dll->head == NULL || !data) return -1;

    dll_node_t *curr_node = dll->head;
    while(curr_node->data != data) {
        curr_node = curr_node->right;
    }
    // Check if gone past end of list
    if(curr_node == NULL) {
        return -1;
    }
    // Check if only node
    if(curr_node->left == NULL && curr_node->right == NULL) {
        dll->head = NULL;
        free(curr_node);
        return 0;
    }
    // Check if head node
    if(curr_node->left == NULL) {
        curr_node->right->left = NULL;
        dll->head = curr_node->right;
        free(curr_node);
        return 0;
    }
    // Check if last node
    if(curr_node->right == NULL) {
        curr_node->left->right = NULL;
        free(curr_node);
        return 0;
    }
    // Check if not only or last node
    curr_node->left->right = curr_node->right;
    curr_node->right->left = curr_node->left;
    free(curr_node);

    return 0;
}

/*return 0 if empty, -1 if not empty*/
int
is_dll_empty (dll_t *dll){
    if(dll->head == NULL) {
        return 0;
    }
    
    return -1;
}

/* delete all nodes from a dll, but do not free appln data*/
void
drain_dll (dll_t *dll){


}

