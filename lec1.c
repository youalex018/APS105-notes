/*
About the course:
30% labs
30% midtern
40% final exam
Online textbook: learningc.org

Professor Sadegh Yazdanshenas' office hours PT371

C is used in games, operating systems, and compilers
Is a compile-time language

Source file on disk -> compiler -> compile -> .exe executable -> run
The compilation is the process of converting the source code of the C language into machine code

Computer architecture
- CPU
- Memory (RAM)
- Disk (storage)
- GPU
- Power

Numeral systems:
Decimal (0d) - base-10 positional numerical system
Binary (0b) - what computers use at the lowest level, base-2 numerical system
- involves 0s and 1s

Unicode - includes special characters and emoji
RGB - combination of red, green, and blue
- each one is made up of one byte
- images are collections of RGB values, videos are sequences of images

Compiler - program to create programs
Terminal - program that handles input/output
- text interface that uses keyboard and monitor for I/O

Git is source and version control

Big-O notation - speed of algorithms
- O(n), O(n/2), O(log2n)

Pseudocode - converting instructions into human-readable code
1  Pick up phone book
2  Open to middle of phone book
3  Look at page
4  If person is on page
5      Call person
6  Else if person is earlier in book
7      Open to middle of left half of book
8      Go back to line 3
9  Else if person is later in book
10     Open to middle of right half of book
11     Go back to line 3
12 Else
13     Quit

Abstraction - act of simplifying a problem into smaller problems
*/

// FIRST PROGRAM IN C

#include <stdio.h> // reads the contents of another file, contains the declaration of printf

int main(void) { // defines a function called main which outputs a number
    printf("Hello World!\n"); // calls a function that outputs a string
    return 0; // stop the execution of main and output the value 0 (interpreted as no errors)
}
