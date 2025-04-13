/*
-Structures-

Structures are user-defined data types that can store multiple data types
- They cannot contain functions and are not dynamically allocated
- They can contain arrays and other structures
- You can assign a struct to another if it is the same type, will copy all values
Out of scope of this course:
- Between data types the compiler adds padding in the memory to align the data types

Basic Syntax:

struct StructName {
    dataType member1;
    dataType member2; //more members can follow as well
};

Example:

struct Person { 
    char name[50];
    int age;
    float height;
}; 

typedef:
- typedef is used to create an alias for an existing data type
- typdef struct person means the same thing as Person
typedef <existing_data_type> <new_data_type_name>;

Example:
typedef char* string;
- Now we can use string instead of char* in our code

*/

// Typedef struct example
#include <stdio.h> 

typedef struct person {
    char name[50];
    int age;
    float height;
} Person;

void updatePerson(Person *p, const char *name, int age, float height_cm) {
    strcpy(p->name, name);
    p->age = age;
    p->height = height_cm;
}

int main(void) {
    Person person1;

    strcpy(person1.name, "John");
    person1.age = 30;
    person1.height = 171.2;
}