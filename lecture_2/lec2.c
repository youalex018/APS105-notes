/*
Memory (RAM - main memory):
- programs always access memory

1 byte = 8 bits
- can have 256 values
- using n bits, can represent 2^n values
- each byte has its own address which are unique
- CPU can read and write bytes

Prefixes:
Kilo (KB) - 2^10 bytes (1024 B)
Mega (MB) - 2^20 bytes (1024 KB)
Giga (GB) - 2^30 bytes (1024 MB)
Tera (TB) - 2^40 bytes (1024 GB)

Data types:
Primitive - built-in

int - positive or negative integer (leftmost bit is sign bit)
- 4 bytes
- if not initialized, will be a random integer

char - character that can be whitespace, punctuation
- 1 byte
- write in inside single quotes ''
- stored as numbers in memory

bool (boolean) - two values, 0 false or 1 true
- 1 byte

float - decimal number
- 4 bytes

double - decimal number with more precision
- 8 bytes

Escape sequences for char:
\t - tab
\n - newline
\\ - backslash
\' - singleQuote
\0 - null character
*/

#include <stdio.h>

int main(void) {
    printf("bruh\n");
    return 0;
}
