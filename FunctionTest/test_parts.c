#include "test_parts.h"

Status test_function_A(){

    read_translate_file("Alice.txt", "Output.txt");

    printf("Now, the Output.txt file contains the binary representation of the text found in the Alice.txt file.\n");

    return OK;

}

Status test_function_B(){

    printf("File Alice.txt\n");
    display_number_of_characters_file("Alice.txt");

    printf("\nFile Output.txt\n");
    display_number_of_characters_file("Output.txt");

    return OK;

}

Status test_function_C(){

     LinkedList* linkedList = NULL;
     LinkedList* new_element = NULL;

     linkedList = characters_occurrences_text(linkedList, new_element, "Alice.txt");

     printf("\nList display : ");
     display_list(linkedList);

     printf("\n\nDisplay of occurrences\n\n");
     display_occurrences(linkedList);

     free_list(linkedList);

     return OK;

}

Status test_function_D(){

     LinkedList* linkedList = NULL;
     LinkedList* new_element = NULL;
     Node* tree = NULL;

     printf("File Tasses.txt\n");
     display_number_of_characters_file("Tasses.txt");

     linkedList = characters_occurrences_text(linkedList, new_element, "Tasses.txt");
     printf("\nList display : ");
     display_list(linkedList);

     printf("\n\nDisplay of occurrences\n\n");
     display_occurrences(linkedList);

     printf("\nHuffman tree\n");
     tree = create_Huffman_tree(linkedList);

     printf("\nTree display (prefix order) : ");
     display_tree(tree);

     printf("\n");

     free_list(linkedList);
     free_tree(tree);

     return OK;

}

Status test_function_E(){

    LinkedList* linkedList = NULL;
    LinkedList* new_element = NULL;
    Node* tree = NULL;
    int string_array[BUFSIZ] = {0};

    printf("File Tasses.txt\n");
    display_number_of_characters_file("Tasses.txt");

    read_translate_file("Tasses.txt", "Tasses - Output.txt");
    printf("Now, the Tasses - Output.txt file contains the binary representation of the text found in the Tasses.txt file.\n");

    linkedList = characters_occurrences_text(linkedList, new_element, "Tasses.txt");
    printf("\nList display : ");
    display_list(linkedList);

    printf("\n\nDisplay of occurrences\n\n");
    display_occurrences(linkedList);

    printf("\nHuffman tree\n");
    tree = create_Huffman_tree(linkedList);

    printf("\nTree display (prefix order) : ");
    display_tree(tree);

    printf("\n");

    Huffman_dictionary("Tasses.txt", "Tasses - Output.txt", "Dico.txt");

    free_list(linkedList);
    free_tree(tree);

    return OK;

}

Status test_function_F(){

     return OK;

}

Status test_function_G(){

     return OK;

}

Status test_function_H(){

     return OK;

}

Status test_function_I(){

     return OK;

}

Status test_function_J(){

     return OK;

}

Status test_function_K(){

     return OK;

}

Status test_function_L(){

     return OK;

}

Status test_function_M(){

     return OK;

}

Status test_function_N(){

     return OK;

}
