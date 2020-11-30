/*****************************************************************//**
 * \file   Part 1.h
 * \brief  Header of the library allowing the management of Part 1.
 *
 * \author Lindsay REBEAU lindsay.rebeau@efrei.net
 * \date   November 2020
 *********************************************************************/

#ifndef PART_1_H_INCLUDED
#define PART_1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Function to read a text in a file (source_file), and to translate it to its 0 and 1 equivalent in another file (destination_file).
 * \param name_source_file, a string to define the input file.
 * \param name_destination_file, a string to define the output file.
 */
extern void  read_translate_file               (const char* name_source_file, const char* name_destination_file);

/**
 * \brief Function to count the number of characters in a text file.
 * \param name_file, a string to define the text file.
 * \return \c -1 if it's impossible to open the text file.
 * \return \c the number of characters present in the text file.
 */
extern int   number_of_characters_file         (const char* name_file);

/**
 * \brief Function to display the number of characters in a text file.
 * \param name_file, a string to define the text file.
 */
extern void  display_number_of_characters_file (const char* name_file);

#endif // PART_1_H_INCLUDED
