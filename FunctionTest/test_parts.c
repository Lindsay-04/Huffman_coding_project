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

     return OK;

}

Status test_function_E(){

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
