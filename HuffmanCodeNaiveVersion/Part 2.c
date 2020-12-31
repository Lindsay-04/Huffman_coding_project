#include "Part 2.h"

LinkedList* create_element(char new_character){

    LinkedList* new_element;
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

int number_of_occurrences_file(const char* name_file, const char searched_character){

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

Node* create_node(char character, int frequency){

    Node* new_element = (Node *) malloc(sizeof(Node));
    new_element->character = character;
    new_element->frequency = frequency;
    new_element->left = NULL;
    new_element->right = NULL;

    return new_element;

}

Node* create_empty_node(int frequency){

    Node* new_element = (Node *) malloc(sizeof(Node));
    new_element->frequency = frequency;
    new_element->left = NULL;
    new_element->right = NULL;

    return new_element;

}

void add_node(Node** tree, int value){

    if (*tree == NULL){

        *tree = create_empty_node(value);
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

void add_leaf_node(Node** tree, char character, int frequency){

    if (*tree == NULL){

        *tree = create_node(character, frequency);
    }
    else{

        if ((*tree)->character > frequency){

            add_leaf_node(&((*tree)->left), character, frequency);

        }

        else if ((*tree)->character < frequency){

            add_leaf_node(&((*tree)->right), character, frequency);

        }

    }

}

Node* add_left(Node* root, char character, int frequency){

    root->left = create_node(character, frequency);

    return root->left;

}

Node* add_right(Node* root, char character, int frequency){

    root->right = create_node(character, frequency);

    return root->right;

}

void display_tree(Node* tree){

    if (tree != NULL){

        // Display of a leaf node
        if (isalpha(tree->character) != 0){

            printf("(%d | %c) ", tree->frequency, tree->character);
            display_tree(tree->left);
            display_tree(tree->right);
        }

        // Display of an internal node
        else{

            printf("(%d) ", tree->frequency);
            display_tree(tree->left);
            display_tree(tree->right);
        }
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

        // Display of a character in the queue
        if (isalpha(q->data_queue->data->character) != 0){

            printf("[%c] ", q->data_queue->data->character);
            q->data_queue = q->data_queue->next;
        }

        // Display of an internal node in the queue
        else{

            printf("[%d] ", q->data_queue->data->frequency);
            q->data_queue = q->data_queue->next;
        }

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

LinkedList* min_linkedlist(LinkedList* linkedList){

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
   Node* left = NULL;
   Node* right = NULL;
   Node* empty_node = NULL;

   Node* Huffman_tree = NULL;
   Node* temp = NULL;
   Node* temp2 = NULL;

   Node* left2 = NULL;
   Node* right2 = NULL;
   Node* empty_node2 = NULL;
   Node* Huffman_tree2 = NULL;

   Node* left3 = NULL;
   Node* right3 = NULL;
   Node* empty_node3 = NULL;
   Node* Huffman_tree3 = NULL;

   Node* Huffman_tree_final = NULL;

   int sum_frequency = 0;
   int sum_frequency2 = 0;
   int sum_frequency3 = 0;

   while (tmp != NULL){

         minimum_value = min_linkedlist(linkedList);

         tree = create_node(minimum_value->character, minimum_value->number_of_occurrences);

         enqueue(q, tree);

         q->data_queue->number_of_occurrences = minimum_value->number_of_occurrences;

         linkedList = delete_element_linkedlist(linkedList, minimum_value->character);

         tmp = tmp->next;

        // If the list contains only one element
        if (linkedList->next == NULL){

            minimum_value = linkedList;
            tree = create_node(minimum_value->character, minimum_value->number_of_occurrences);
            enqueue(q, tree);
            q->data_queue->number_of_occurrences = linkedList->number_of_occurrences;

        }


    }

        printf("\n----------------------------------------------------------\n");

        left = dequeue(q);
        right = dequeue(q);

        empty_node = create_empty_node(left->frequency + right->frequency);
        empty_node->left = left;
        empty_node->right = right;

        sum_frequency = left->frequency + right->frequency;
        empty_node->frequency = sum_frequency;

        add_node(&Huffman_tree, sum_frequency);
        add_left(Huffman_tree, left->character, left->frequency);
        add_right(Huffman_tree, right->character, right->frequency);

        printf("Display subtree (prefix order) : ");
        display_tree(Huffman_tree);

        printf("\n----------------------------------------------------------");

        temp = q->data_queue->data;

        q->data_queue = q->data_queue->next;
        temp2 = q->data_queue->data;
        dequeue(q);

        enqueue(q, empty_node);
        enqueue(q, temp);
        enqueue(q, temp2);

        right2 = dequeue(q);
        left2 = dequeue(q);

        empty_node2 = create_empty_node(left2->frequency + right2->frequency);
        empty_node2->left = left2;
        empty_node2->right = right2;

        sum_frequency2 = left2->frequency + right2->frequency;
        empty_node2->frequency = sum_frequency2;

        add_node(&Huffman_tree2, sum_frequency2);

        add_left(Huffman_tree2, left2->character, left2->frequency);
        add_right(Huffman_tree2, right2->character, right2->frequency);

        printf("\nDisplay subtree (prefix order) : ");
        display_tree(Huffman_tree2);

        printf("\n----------------------------------------------------------");

        enqueue(q, empty_node2);

        left3 = dequeue(q);
        right3 = dequeue(q);

        empty_node3 = create_empty_node(left3->frequency + right3->frequency);
        empty_node3->left = left3;
        empty_node3->right = right3;

        sum_frequency3 = left3->frequency + right3->frequency;
        empty_node3->frequency = sum_frequency3;

        add_node(&Huffman_tree3, sum_frequency3);
        add_left(Huffman_tree3, left3->character, left3->frequency);
        add_right(Huffman_tree3, right3->character, right3->frequency);

        printf("\nDisplay subtree (prefix order) : ");
        display_tree(Huffman_tree3);

        printf("\n----------------------------------------------------------\n");

        add_node(&Huffman_tree_final, sum_frequency3);
        add_leaf_node(&Huffman_tree_final, left3->character, left3->frequency);
        add_node(&Huffman_tree_final, right3->frequency);
        add_leaf_node(&Huffman_tree_final, left2->character, left2->frequency);
        add_node(&Huffman_tree_final, right2->frequency);
        add_leaf_node(&Huffman_tree_final, left->character, left->frequency);
        add_leaf_node(&Huffman_tree_final, right->character, right->frequency);

    return Huffman_tree_final;

}

void Huffman_dictionary(const char* name_source_file, const char* name_destination_file, const char *dico){



}

void translate_file_dictionary(const char* name_source_file, const char* name_destination_file){



}

void compress_file(const char* name_source_file, const char* name_destination_file){



}

void decompress_file(const char* name_source_file, const char* dico, const char* name_destination_file){


}
