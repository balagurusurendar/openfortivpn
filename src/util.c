/*
 *  Copyright (C) 2015 Adrien Vergé
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "util.h"
#include "log.h"

#include <stdlib.h>
#include <string.h>

char **string_split(char *str, const char *delimiters)
{
    char *token;
    char **tokenArray;
    char *copy = (char *)calloc(strlen(str)+1, sizeof(char));
    strcpy(copy,str);
    int count = 0;
    token = (char *)strtok(copy, delimiters); // Get the first token
    tokenArray = (char **)malloc(1 * sizeof(char *));
    tokenArray[0] = NULL;
    if (!token)
    {
        return tokenArray;
    }
    while (token != NULL)
    { // While valid tokens are returned
        tokenArray[count] = (char *)strdup(token);
        //printf ("%s", tokenArray[count]);
        count++;
        tokenArray = (char **)realloc(tokenArray, sizeof(char *) * (count + 1));
        token = (char *)strtok(NULL, delimiters); // Get the next token
    }
    tokenArray[count] = NULL; /* Terminate the array */
    free(copy);
    return tokenArray;
}

char *string_join(char **str, const char *delimiters)
{
    char *joinedStr;
    int i = 1;
    joinedStr = realloc(NULL, strlen(str[0]) + 1);
    strcpy(joinedStr, str[0]);
    if (str[0] == NULL)
    {
        return joinedStr;
    }
    while (str[i] != NULL)
    {
        joinedStr = (char *)realloc(joinedStr, strlen(joinedStr) + strlen(str[i]) + strlen(delimiters) + 1);
        strcat(joinedStr, delimiters);
        strcat(joinedStr, str[i]);
        i++;
    }
    return joinedStr;
}

void string_prepend(char *s, const char *t)
{
    size_t len = strlen(t);
    memmove(s + len, s, strlen(s) + 1);
    memcpy(s, t, len);
}

void free_custom_string_array(char **array)
{
    if (array == NULL)
    {
        return;
    }
    int i = 0;
    //considering last element is NULL
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }

    free(array);
}

int get_size_custom_string_array(char **array)
{
    int size = 0;
    while (array[size] != NULL)
    {
        size++;
    }
    return size;
}

char **merge_custom_string_array(char **array1, char **array2)
{
    if (array2 == NULL)
    {
        return array1;
    }
    if (array1 == NULL)
    {
        array1 = (char **)malloc(1 * sizeof(char *));
        array1[0] = NULL;
    }
    int array1_size = get_size_custom_string_array(array1);
    int array2_size = get_size_custom_string_array(array2);
    int flag = 0;
    for (int i = 0; i < array2_size; i++)
    {

        char *element = array2[i];
        flag = 0;
        for (int j = 0; j < array1_size; j++)
        {
            if (strcmp(array1[j], element) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            array1[array1_size] = (char *)strdup(element);
            array1_size++;
            array1 = (char **)realloc(array1, sizeof(char *) * (array1_size + 1)); //+1 for extra NULL
        }
    }
    array1[array1_size] = NULL;
    return array1;
}