#include "menu.h"
#include "test_parts.h"

void menu(){

    int part = 0;
    char function;

    printf("\t----------------------\n");
    printf("\tHuffman coding project\n");
    printf("\t----------------------\n");

    printf("\nMenu\n\n");

    printf("1 : From letter to bit\n");
    printf("2 : Naive version of Huffman code\n");
    printf("3 : Optimization\n\n");

    printf("Enter your choice (number) : ");
    scanf("%d", &part);

    switch(part){

        case 1:
            printf("\nYou have chosen part 1 : From letter to bit.\n\n");
            printf("A : Function that reads a text in a file, and translates it to its 0 and 1 equivalent in another file.\n");
            printf("B : Function that displays the number of characters in a txt file.\n\n");

            printf("Enter A or B : ");
            scanf(" %c", &function);

                switch(function){

                    case 'A':
                        printf("\nYou have chosen function A.\n\n");
                        test_function_A();
                        break;

                    case 'B':
                        printf("\nYou have chosen function B.\n\n");
                        test_function_B();
                        break;

                    default:
                        printf("\nIncorrect choice.\n\n");
                        break;
                }
        break;

        case 2:
            printf("\nYou have chosen part 2 : The naive version of the Huffman code.\n\n");
            printf("C : Function that returns a list containing each character present in the text, and the number of occurrences of this character.\n");
            printf("D : Function that returns a Huffman tree, from a list of occurrences.\n");
            printf("E : Function that stores the dictionary from the Huffman tree in a txt file.\n");
            printf("F : Function that translates a text into a binary sequence based on a Huffman dictionary.\n");
            printf("G : Function that compresses a text file.\n");
            printf("H : Function that decompresses a text file from a Huffman tree.\n\n");

            printf("Enter C, D, E, F, G or H : ");
            scanf(" %c", &function);

            switch(function){

                    case 'C':
                        printf("\nYou have chosen function C.\n");
                        test_function_C();
                        break;

                    case 'D':
                        printf("\nYou have chosen function D.\n\n");
                        test_function_D();
                        break;

                    case 'E':
                        printf("\nYou have chosen function E.\n\n");
                        test_function_E();
                        break;

                    case 'F':
                        printf("\nYou have chosen function F.\n\n");
                        test_function_F();
                        break;

                    case 'G':
                        printf("\nYou have chosen function G.\n\n");
                        test_function_G();
                        break;

                    case 'H':
                        printf("\nYou have chosen function H.\n\n");
                        test_function_H();
                        break;

                    default:
                        printf("\nIncorrect choice.\n\n");
                        break;
               }
           break;

        case 3:
            printf("\nYou have chosen part 3 : Optimization.\n\n");
            printf("I : Function which, by dichotomous search, adds to an occurrence to an array of nodes when the character has already been found, or which adds the node of the character otherwise.\n");
            printf("J : Function that sorts an array of nodes based on occurrences.\n");
            printf("K : Function which, using two queues, creates the Huffman tree from an array of nodes sorted by occurrences.\n");
            printf("L : Function that organizes the nodes in an AVL according to the order of the characters present.\n");
            printf("M : Function that optimally compresses a text file.\n");
            printf("N : Function that decompresses a text file from a Huffman dictionary file.\n\n");

            printf("Enter I, J, K, L, M or N : ");
            scanf(" %c", &function);

            switch(function){

                    case 'I':
                        printf("\nYou have chosen function I.\n");
                        test_function_I();
                        break;

                    case 'J':
                        printf("\nYou have chosen function J.\n\n");
                        test_function_J();
                        break;

                    case 'K':
                        printf("\nYou have chosen function K.\n\n");
                        test_function_K();
                        break;

                    case 'L':
                        printf("\nYou have chosen function L.\n\n");
                        test_function_L();
                        break;

                    case 'M':
                        printf("\nYou have chosen function M.\n\n");
                        test_function_M();
                        break;

                    case 'N':
                        printf("\nYou have chosen function N.\n\n");
                        test_function_N();
                        break;

                    default:
                        printf("\nIncorrect choice.\n\n");
                        break;
               }
           break;

           default:
                printf("\nIncorrect choice.\n");
                break;
    }

}
