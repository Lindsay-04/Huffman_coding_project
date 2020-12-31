/*****************************************************************//**
 * \file   Part 3.h
 * \brief  Header of the library allowing the management of Part 3.
 *
 * \author Lindsay REBEAU lindsay.rebeau@efrei.net
 * \date   November 2020
 *********************************************************************/

#ifndef PART_3_H_INCLUDED
#define PART_3_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Part 2.h"

/**
 * \typedef struct Dico_Node
 * \brief The dictionary.
 */
typedef struct Dico_Node{

    char character;
    char *code;
    struct Dico_Node* left;
    struct Dico_Node* right;

}Dico_Node;

// Declaration of function prototypes

extern void    optimization_occurrences         (Node* nodes_array[]);

extern void    sort_array_occurrences           ();

extern Node*   optimization_create_Huffman_tree (Node** sorted_node_array[], int n);

extern void    organize_nodes_AVL               ();

extern void    optimization_compress_file       (const char* name_source_file, const char* name_destination_file);

extern void    optimization_decompress_file     (const char* name_source_file, const char* dictionary_file, const char* name_destination_file);

extern void    free_dico_tree                   (Dico_Node* tree);

#endif // PART_3_H_INCLUDED
