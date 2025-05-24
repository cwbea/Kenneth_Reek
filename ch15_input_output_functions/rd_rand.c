/*
** This program reads a specific record from a binary file containing student information.
** The function `read_random_record` retrieves a record based on its index.
*/

#include <stdio.h>      // Standard I/O functions like fopen, fread, fseek
#include <stdlib.h>     // For exit and EXIT_FAILURE
#include <string.h>     // For strcpy, used in sample data

// Assuming studinfo.h looks like this:
typedef struct {
    int id;
    char name[50];
    float gpa;
} StudentInfo;

/*
** Function: read_random_record
** ----------------------------
** Reads a specific record (by index) from the given binary file.
**
** Parameters:
** - FILE *f: Pointer to the file stream opened in binary mode.
** - size_t rec_number: The index (starting from 0) of the record to be read.
** - StudentInfo *buffer: Pointer to where the read record will be stored.
**
** Returns:
** - 1 if the record is successfully read.
** - 0 if it fails (e.g., index out of bounds or file read error).
*/
int read_random_record(FILE *f, size_t rec_number, StudentInfo *buffer) {
    // Move file pointer to the start of the specified record
    fseek(f, (long)rec_number * sizeof(StudentInfo), SEEK_SET);

    // Read one record into buffer; returns 1 on success, 0 on failure
    return fread(buffer, sizeof(StudentInfo), 1, f);
}

/*
** Main function to demonstrate reading a random record.
*/
int main() {
    FILE *fp;
    StudentInfo buffer;

    // Create a binary file with sample data for demonstration
    fp = fopen("students.dat", "wb");
    if (!fp) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    // Write sample student records to the file
    StudentInfo students[] = {
        {101, "Alice Johnson", 3.9},
        {102, "Bob Smith", 3.5},
        {103, "Charlie Brown", 3.7}
    };
    fwrite(students, sizeof(StudentInfo), 3, fp);
    fclose(fp);  // Close after writing

    // Open the file for reading
    fp = fopen("students.dat", "rb");
    if (!fp) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Prompt user for the record number to read
    size_t record_num;
    printf("Enter record number to read (0-2): ");
    scanf("%zu", &record_num);

    // Read the record from the file
    if (read_random_record(fp, record_num, &buffer)) {
        // Display the record
        printf("Record #%zu:\n", record_num);
        printf("ID: %d\n", buffer.id);
        printf("Name: %s\n", buffer.name);
        printf("GPA: %.2f\n", buffer.gpa);
    } else {
        fprintf(stderr, "Failed to read record #%zu\n", record_num);
    }

    fclose(fp);  // Always close the file
    return 0;
}

