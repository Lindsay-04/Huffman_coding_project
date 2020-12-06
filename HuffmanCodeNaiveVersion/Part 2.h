/*****************************************************************//**
 * \file   Part 2.h
 * \brief  Header of the library allowing the management of Part 2.
 *
 * \author Lindsay REBEAU lindsay.rebeau@efrei.net
 * \date   November 2020
 *********************************************************************/

#ifndef PART_2_H_INCLUDED
#define PART_2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * \typedef struct LinkedList
 * \brief Element of the simple linked list, it owns one pointer : next.
 */
typedef struct LinkedList{

    char character;
    int number_of_occurrences;
    struct LinkedList* next; /**< the next element of the list */

}LinkedList;

/**
 * \typedef struct Node
 * \brief Node of a tree, it owns two pointers : left and right.
 */
typedef struct Node{

    char character;
    int frequency;
    struct Node* left;
    struct Node* right;

}Node;

/**
 * \typedef struct Element
 * \brief List to store data in the queue.
 */
typedef struct Element{

    Node* data;
    int number_of_occurrences;
    struct Element* next;

}Element;

/**
 * \typedef struct Queue
 * \brief Queue to store data, it owns one pointer: data_queue.
 */
typedef struct Queue{

    Element* data_queue;

}Queue;

/**
 * \brief Function to create an element in a linked list.
 * \param new_character, a string to define a new character.
 * \return the created element.
 */
extern LinkedList*    create_element              (char new_character);

/**
 * \brief Function to add an element at the start of the linked list.
 * \param start_list, the first element in the linked list.
 * \param new_element, the element to add to the linked list.
 * \return the linked list.
 */
extern LinkedList*    add_element_start           (LinkedList* start_list, LinkedList* new_element);

/**
 * \brief Function to partially browse a linked list.
 * \param linkedList, the linked list to browse.
 * \param x, the searched element.
 * \return \c - 1 if the element is not in the list.
 * \return the position of an element given as an argument in a linked list.
 */
extern int            position                    (const LinkedList* linkedList, const char x);

/**
 * \brief Function to count the number of occurrences of a character in a file.
 * \param name_file, a string to define the text file.
 * \param searched_character, the searched element.
 * \return the number of occurrences of the searched character.
 */
extern int            number_of_occurrences_file  (const char* name_file, const char searched_character);

/**
 * \brief Function to obtain the correspondence between character and occurrences.
 * \param linkedList, the linked list to return.
 * \param new_element, the element to add to the linked list if it's not in it yet.
 * \param name_file, a string to define the text file.
 * \return a list containing each character present in the text and the number of occurrences of this character.
 */
extern LinkedList*    characters_occurrences_text (LinkedList* linkedList, LinkedList* new_element, const char* name_file);

/**
 * \brief Function to display a linked list.
 * \param linkedList, the linked list to display.
 */
extern void           display_list                (const LinkedList* linkedList);

/**
 * \brief Function to display the number of occurrences of each character present in a text.
 * \param linkedList, the linked list to browse.
 */
extern void           display_occurrences         (LinkedList* linkedList);

/**
 * \brief Function to free the memory of a linked list.
 * \param linkedList, the linked list to free.
 */
extern void           free_list                   (LinkedList* linkedList);

/**
 * \brief Function to create a node in a tree.
 * \param character, a string to define the letter of the node.
 * \param frequency, an integer to define the number of occurrences of the node.
 * \return the node created.
 */
 extern Node*         create_node                 (char character, int frequency);

/**
 * \brief Function to create a internal node in a tree.
 * \param frequency, an integer to define the number of occurrences of the internal node.
 * \return the internal node created.
 */
extern Node*          create_empty_node           (int frequency);

/**
 * \brief Function to add a node to a tree.
 * \param tree, the tree receiving nodes.
 * \param value, a string to define the value of the node to add.
 */
extern void           add_node                    (Node** tree, int value);

/**
 * \brief Function to add a leaf node to a tree.
 * \param tree, the tree receiving nodes.
 * \param character, a string to define the letter of the node to add.
 * \param frequency, an integer to define the number of occurrences of the node to add.
 */
extern void           add_leaf_node               (Node** tree, char character, int frequency);

/**
 * \brief Function to add a node at the left.
 * \param root, the root node.
 * \param character, a string to define the letter of the node to add.
 * \param frequency, an integer to define the number of occurrences of the node to add.
 */
extern Node*          add_left                    (Node* root, char character, int frequency);

/**
 * \brief Function to add a node at the right.
 * \param root, the root node .
 * \param character, a string to define the letter of the node to add.
 * \param frequency, an integer to define the number of occurrences of the node to add.
 */
extern Node*          add_right                    (Node* root, char character, int frequency);

/**
 * \brief Function to display a tree.
 * \param tree, the tree to display.
 */
extern void           display_tree                (Node* tree);

/**
 * \brief Function to free the memory of a tree.
 * \param tree, the tree to free.
 */
extern void           free_tree                   (Node* tree);

/**
 * \brief Function to create a queue.
 * \return the queue created.
 */
extern Queue*         create_queue                ();

/**
 * \brief Function to test if the queue is empty.
 * \param q, the queue to browse.
 * \return \c 1, if the queue is empty.
 * \return \c 0, otherwise.
 */
extern int            is_empty_queue              (Queue* q);

/**
 * \brief Function to add a node at the end of the queue.
 * \param q, the queue receiving nodes.
 * \param value, a string to define the value of the node to add.
 */
extern void           enqueue                     (Queue* q, Node* value);

/**
 * \brief Function to delete a node at the start of the queue.
 * \param q, the queue to browse.
 * \return \c NULL, if the queue is empty.
 * \return \c the elements of the queue, otherwise.
 */
extern Node*          dequeue                     (Queue* q);

/**
 * \brief Function to to display a queue.
 * \param q, the queue to display.
 */
extern void           display_queue               (Queue* q);

/**
 * \brief Function to remove an element from a linked list.
 * \param linkedList, the linkedList to browse.
 * \param x, a string to define the element to remove.
 * \return the linked list without the deleted element.
 */
extern LinkedList*    delete_element_linkedlist   (LinkedList* linkedList, const char x);

/**
 * \brief Function to isolate the smallest element of a linked list.
 * \param linkedList, the linkedList to browse.
 * \return the smallest element of the linked list.
 */
extern LinkedList*    min_linkedlist              (LinkedList* linkedList);

/**
 * \brief Function to create an Huffman tree from a list of occurrences.
 * \param linkedList, the list of occurrences.
 * \return the Huffman tree.
 */
extern Node*          create_Huffman_tree         (LinkedList* linkedList);

/**
 * \brief Function to stores the dictionary from the Huffman tree in a text file.
 * \param name_source_file, a string to define the input file.
 * \param name_destination_file, a string to define the output file.
 * \param dico, a string to define the dictionary file.
 */
 extern void          Huffman_dictionary           (const char* name_source_file, const char* name_destination_file, const char *dico);

/**
 * \brief Function to translate a text into a binary sequence based on a Huffman dictionary.
 * \param name_source_file, a string to define the input file.
 * \param name_destination_file, a string to define the output file.
 */
extern void           translate_file_dictionary   (const char* name_source_file, const char* name_destination_file);

/**
 * \brief Function to compress a text file.
 * \param name_source_file, a string to define the input file.
 * \param name_destination_file, a string to define the output file.
 */
extern void           compress_file               (const char* name_source_file, const char* name_destination_file);

/**
 * \brief Function to decompress a text file.
 * \param name_source_file, a string to define the input file.
 * \param dico, a string to define the dictionary file.
 * \param name_destination_file, a string to define the output file.
 */
extern void           decompress_file             (const char* name_source_file, const char* dico, const char* name_destination_file);

#endif // PART_2_H_INCLUDED

