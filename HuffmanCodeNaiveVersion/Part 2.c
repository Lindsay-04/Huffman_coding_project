#include "Part 2.h"

LinkedList* create_element(char new_character){

    LinkedList *new_element;
    new_element = malloc(1 * sizeof(LinkedList));

    if (new_element == NULL){

        printf("Dynamic allocation not possible : malloc() error.\n");
    }

    new_element->character = new_character;
    new_element->next = NULL;

    return new_element;
}

LinkedList* add_element_start(LinkedList* start_list, LinkedList* new_element){

    new_element->next = start_list;
    start_list = new_element;

    return start_list;
}

int position(const LinkedList* linkedList, const char x){

    int i = 0;

    while (linkedList != NULL){

        if (linkedList->character == x){

            return i + 1;
        }

        linkedList = linkedList->next;
        i++;
    }

    return -1;

}

int number_of_occurrences_file(const char* name_file, char searched_character){

    FILE* file = NULL;

    int current_character = 0;
    int counter = 0;

    // Opening the file in "r" mode (read only)
    file = fopen(name_file, "r");

    if (file != NULL){

        while (current_character != EOF){

            current_character = fgetc(file);

            if (current_character == searched_character){

                counter++;
            }

        }

        fclose(file);
    }

    else{

        return -1;

    }

    return counter;
}

LinkedList* characters_occurrences_text(LinkedList* linkedList, LinkedList* new_element, const char* name_file){

    FILE* file = NULL;
    int current_character = 0;

    // Opening the file in "r" mode (read only)
    file = fopen(name_file, "r");

    if (file != NULL){

        current_character = fgetc(file);

        while (current_character != EOF){

            // If the character read is not yet in the list
            if (position(linkedList, current_character) == - 1){

                // We add it to the list
                new_element = create_element(current_character);
                linkedList = add_element_start(linkedList, new_element);

                // We give the number of occurrences
                linkedList->number_of_occurrences = number_of_occurrences_file(name_file, current_character);

            }

            current_character = fgetc(file);

        }

        // Close the file
        fclose(file);
    }

    else{

        printf("Cannot open the file .txt\n");
    }

    return linkedList;
}

void display_list(const LinkedList* linkedList){

    if (linkedList != NULL){

        printf("%c ", linkedList->character);
        display_list(linkedList->next);
    }
}

void display_occurrences(LinkedList* linkedList){

    LinkedList* tmp = linkedList;

    if (tmp == NULL){

        printf("The list is empty.\n");

    }

    while (tmp != NULL){

        printf("Occurrences of %c : %d\n", tmp->character, tmp->number_of_occurrences);
        tmp = tmp->next;
    }
}

void free_list(LinkedList* linkedList){

    if (linkedList != NULL){

        free(linkedList->next);
        linkedList->character = 0;
        linkedList->next = NULL;

    }
}

Node* create_node(char value){

    Node* new_element = (Node *) malloc(sizeof(Node));
    new_element->character = value;
    new_element->left = NULL;
    new_element->right = NULL;

    return new_element;

}

void add_node(Node** tree, char value){

    if (*tree == NULL){

        *tree = create_node(value);
    }
    else{

        if ((*tree)->character > value){

            add_node(&((*tree)->left), value);

        }

        else if ((*tree)->character < value){

            add_node(&((*tree)->right), value);

        }

    }

}

void display_tree(Node* tree){

    if (tree != NULL){

        printf("%c ", tree->character);
        display_tree(tree->left);
        display_tree(tree->right);
    }

}

void free_tree(Node* tree){

    if (tree != NULL){

        free(tree->left);
        free(tree->right);
        free(tree);
    }
}

Queue* create_queue(){

    // Dynamic allocation of the queue
    Queue* q = (Queue *) malloc(sizeof(Queue));

    // What is in the stack is null
    q->data_queue = NULL;

    return q;
}

int is_empty_queue(Queue* q){

    // Case where the queue is empty
    if (q->data_queue == NULL){

        return 1;

    }

    else{

        return 0;
    }

}

void enqueue(Queue* q, Node* value){
    
    //Add at the end
    if (value != NULL){

        Element* new_element = (Element*)malloc(sizeof(Element));
        new_element->data = value;
        new_element->next = NULL;

        if (is_empty_queue(q) == 1){

            q->data_queue = new_element;

        }

        else{

            Element* tmp = q->data_queue;

            while (tmp->next != NULL){

                tmp = tmp->next;

            }

            tmp->next = new_element;
        }
    }
}

Node* dequeue(Queue* q){

     //Remove at the beginning
    if (is_empty_queue(q) == 1){

        return NULL;

    }

    else{

        Element* old = q->data_queue;
        q->data_queue = q->data_queue->next;
        Node* tmp = old->data;
        free(old);
        return tmp;
    }
}

void display_queue(Queue* q){

    // Case where the queue is empty
    if (is_empty_queue(q) == 1){

        printf("Nothing to display, the queue is empty.\n\n");
    }

    // While the queue isn't empty
    while (is_empty_queue(q) == 0){

        printf("[%c] ", q->data_queue->data->character);
        q->data_queue = q->data_queue->next;

    }

    printf("\n");
}

LinkedList* delete_element_linkedlist(LinkedList* linkedList, const char x){

    LinkedList* tmp;

    while (linkedList != NULL){


        if (linkedList->character == x){

                tmp = linkedList->next;
                free(linkedList);
                tmp = delete_element_linkedlist(tmp, x);

                return tmp;

        }

        else{

            linkedList->next = delete_element_linkedlist(linkedList->next, x);
            return linkedList;
        }

    }

    return linkedList;

}

LinkedList* min_list(LinkedList* linkedList){

    LinkedList* tmp = linkedList;

    while (linkedList != NULL){

        if (linkedList->number_of_occurrences < tmp->number_of_occurrences){

            tmp = linkedList;

        }

        linkedList = linkedList->next;
    }

    return tmp;
}

Node* create_Huffman_tree(LinkedList* linkedList){

   Queue* q = create_queue();

   LinkedList* tmp = linkedList;
   LinkedList* minimum_value = NULL;

   Node* tree = NULL;

   while (tmp != NULL){

         minimum_value = min_list(linkedList);
         printf("The minimum in the list is the character %c that appears %d times\n", minimum_value->character, minimum_value->number_of_occurrences);
         tree = create_node(minimum_value->character);

         enqueue(q, tree);
         linkedList = delete_element_linkedlist(linkedList, minimum_value->character);

         tmp = tmp->next;

    }

     display_queue(q);

return tree;

}

Node* Huffman_dictionary (const char* name_file, const char string_array[]){

    return NULL;

}

void translate_file_dictionary(const char* name_source_file, const char* name_destination_file){



}

void compress_file(const char* name_source_file, const char* name_destination_file){



}

void decompress_file(const char* name_source_file, const char* dico, const char* name_destination_file){


}
