/*
-Files in C-

Open a file:
FILE fopen(const char pathname, const char *mode);
- pathname: string of name of the file to open
- mode: string representing the file operation mode

Example:
FILE *file = fopen("filename.txt", "mode");
- mode: "r" (read), "w" (write, creates/truncates), "a" (append)
- If the file does not exist, fopen() will create it if the mode is "w" or "a"
- Returns a pointer to the file, check for NULL if it fails

Close a file:
int fclose(FILE *stream);
- stream: pointer to the file to close returned by fopen()
- Returns 0 on success, EOF on error
- Closes the file and flushes the buffer

Read a line from a file:
ssize_t getline(char **bufferp, size_t *sizep, FILE *stream);
- bufferp: pointer to a buffer to store the line
- sizep: pointer to a variable that stores the size of the buffer
- stream: pointer returned by fopen() 

- Dynamically allocates memory and resizes it as needed
- Reads an entire line including whitespace and newline
- Returns number of characters read including null byte, or -1 on failure/end of file

CSV file - Comma Separated Values

Rooted trees:
- A rooted tree is a tree in which one node is designated as the root
- The root node is the topmost node in the tree
- All other nodes are descendants of the root node
- Each node in the tree can have zero or more child nodes

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 100

// Function to calculate the average of an array of integers
double average(int grades[], int count) {
    if (count == 0) {
        return 0.0; // Avoid division by zero
    }
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (double)sum / count;
}

int main() {
    char *filename = "grades.csv";
    FILE *file = fopen(filename, "r");
    
    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Read each line from the CSV file
    while ((nread = getline(&line, &len, file)) != -1) {
        char name[MAX_NAME_LENGTH]; 
        int grades[50]; // Assuming a maximum of 50 grades per student
        int gradeCount = 0;

        // Tokenize the line using comma as a delimiter
        char *token = strtok(line, ",");
        // The first token is the name
        while (token != NULL) {
            strncpy(name, token, MAX_NAME_LENGTH);
            name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        }

        // Process grades
        while ((token = strtok(NULL, ",")) != NULL) {
            grades[gradeCount++] = atoi(token); // atoi turns a string to an integer
        }

        // Calculate and print average
        double avg = average(grades, gradeCount);
        printf("%s's average grade: %.2f\n", name, avg);
    }

    // Free allocated memory
    free(line);
    fclose(file);

    return 0;
}