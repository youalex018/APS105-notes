/*
-Strings Part II-

Standard String Functions:
You need to include <string.h> for these functions
C strings are arrays of characters terminated by a null character \0

The strlen function is used to calculate the length of a null-terminated string (excluding the null character \0 at the end)
Function prototype: size_t strlen(const char *s)
- Returns the number of characters in s, up to maxlen, excluding the terminating null character
- Return type is size_t (unsigned integer type)
- If s is null strlen will cause undefined behavior

The strcpy function is used to copy a null-terminated string from one location to another. It is declared in the <string.h> library
Function prototype: char *strcpy(char *dest, const char *src) 
dest: Pointer to the destination buffer where the string will be copied 
src: Pointer to the source null-terminated string 

Return value
- Returns a pointer to dest (the destination buffer.)

The strcat function appends (concatenates) a string to a previous string

The strstr function searches for the first occurence of a substring needle in a string haystack

atoi function converts a string to an integer
*/