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
- Returns a pointer to dest (the destination buffer) and also copies the null character

The strncpy function does the same as strcpy but copies the first n characters or until it observes \0
- It will put \0 for the remaining characters to be copied into src
- It does not add any \0 to the end of dest by default
Function prototype: char* strncpy(char *dest, const char *src, size_t n);

The strcat function appends (concatenates) the src string to the end of the dest string
- Overrides the null character of the dest string by the first character of src
- This assumes the dest string has enough space to hold the concatenated string
Function prototype: char *strcat(char *dest, const char *src)

The strncat function concatenates the first n characters or until it observes \0
- Assumes the dest string has enough space to hold the n characters
- It will not put in extra \0 if n is larger than src and dest has enough space
Function prototype: char* strncat(char *dest, const char *src, size_t n);

The strcmp function compares two strings lexicographically (dictionary order)
- Comparison stops when characters are not matching or when a null character is encountered
- Returns < 0 if s1 is before s2
- Returns 0 if s1 is identical to s2
- Returns > 0 if s1 is after s2
Function prototype: int strcmp(const char *s1, const char *s2)

The strncmp function compares at most the first n characters of two strings
Function prototype: int strncmp(const char *s1, const char *s2, size_t n);

The srchr function searches for the first occurence of a character c in a string s
- Returns a pointer to the first occurence
- Returns null if c is not found in s
Function prototype: char *strchr(const char *s, int c)

The strstr function searches for a substring s2 in a string s1
- Returns the first occurence of s2 in s1, returns null if s2 is not in s1
Function prototype: char *strstr(const char *s1, const char *s2);

atoi function converts a string to an integer
*/