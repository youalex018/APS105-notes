/*
-Dynamic Memory Allocation-

- valgrind is a tool that helps find memory problems in C
- First compile then with debugging info then run using valgrind

Stack - any variables in a function are allocated in the stack
Heap - unrelated to the current running function

malloc:
void* malloc(size, t_size);
- returns a pointer to a starting address, can then use size contiguous bytes
- size is how many contiguous bytes to allocate
- t_size is a positive integer and sizeof(t_size) depends on the machine
- if there is no more room in heap, malloc returns NULL

Leaking memory:
- Not deallocating memory is called a memory leak
- If program runs for a long time, memory might run out and will slow other programs
- free allocated memory using the free function
void free(void *ptr);
- pointer (ptr) argument needs to be the address returned from malloc
- memory pointed to by ptr cannot be used afterwards, if value of ptr is NULL free does nothing

exit:
- immediately ends the program
void exit(int status);

Check for allocation failure (malloc returns NULL)
Avoid use-after-free/dangling pointer by setting the pointer to null after free()
Another mistake is calling free twice on the same pointer

*/

#include <stdio.h>
#include <stdlib.h>

int *foo() {
    int *p = malloc(sizeof(int)); // allocate memory for one integer
    if (p == NULL) { // ensure allocation was successful, abort if p is null
        exit(1);
    }
    *p = 1; // store the value 1 in the allocated memory
    return p; // return the pointer to the allocated memory
}

int main(void) {
    int *p = foo(); // get the allocated pointer
    printf("%d\n", *p); // dereference the pointer to print value
    free(p); // free allocated memory to avoid memory leaks

    int arrayLength = 0;

    do {
        printf("Enter the size of the array: ");
        scanf("%d", &arrayLength);
    } while (arrayLength <= 0);

    int *array = malloc(sizeof(int) * arrayLength);
    if (array == NULL) {
        return EXIT_FAILURE;
    }

    // use array here

    free(array);
    array = NULL;

    return 0;
}