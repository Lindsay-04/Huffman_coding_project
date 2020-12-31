#include "Part 1.h"

void read_translate_file(const char* name_source_file, const char* name_destination_file){

    FILE* source_file = NULL;
    FILE* destination_file = NULL;

    int current_character = 0;
    int i = 1;
    int j = 0;
    int quotient = 0;

    /* Initialization of an integer array to store the rest
    of successive divisions and form the binary representation */
    int current_character_binary[BUFSIZ] = {0};

    // Opening the source_file in "r" mode (read only)
    source_file = fopen(name_source_file, "r");

    // Opening the destination_file in "w" mode (write only)
    destination_file = fopen(name_destination_file, "w");

    if (source_file != NULL){

       current_character = fgetc(source_file);

       while (current_character != EOF){

            i = 1;
            j = 0;
            quotient = 0;

            if (destination_file != NULL){

                quotient = current_character;

                while(quotient != 0){

                    current_character_binary[i] = quotient % 2;
                    quotient = quotient / 2;
                    i++;

                }

                // Display on the file
                for (j = 8; j > 0; j--){

                    fprintf(destination_file, "%d", current_character_binary[j]);

                }

                current_character = fgetc(source_file);

            }


            else{

                printf("Cannot open the destination file\n");

            }
        }

        // Close the files
        fclose(source_file);
        fclose(destination_file);
    }

    else{

        printf("Cannot open the source file\n");
    }

}

int number_of_characters_file(const char* name_file){

    FILE* file = NULL;

    int current_character = 0;
    int counter = 0;

    // Opening the file in "r" mode (read only)
    file = fopen(name_file, "r");

    if (file != NULL){

        current_character = fgetc(file);

        while (current_character != EOF){

            current_character = fgetc(file);
            counter++;
        }

        fclose(file);
    }

    else{

        return -1;

    }

    return counter;
}

void display_number_of_characters_file(const char* name_file){

    FILE* file = NULL;

    int result = 0;

    // Opening the file in "r" mode (read only)
    file = fopen(name_file, "r");

    if (file != NULL){

        result = number_of_characters_file(name_file);

        printf("Number of characters in the file : %d\n", result);

        // Close the file
        fclose(file);

    }

    else{

        printf("Cannot open the file\n");
    }

}

