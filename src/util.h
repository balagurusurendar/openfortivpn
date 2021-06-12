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


#ifndef OPENFORTIVPN_UTIL_H
#define OPENFORTIVPN_UTIL_H


char **string_split(char *str, const char *delimiters);

char* string_join(char **str, const char *delimiters);

void free_custom_string_array(char **array);

char **merge_custom_string_array(char **array1, char **array2);

int get_size_custom_string_array(char **array);

void string_prepend(char* s, const char* t);

#endif