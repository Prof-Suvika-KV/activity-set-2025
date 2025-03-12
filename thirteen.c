//13. Write a C program to read a text file into memory, append lines, insert lines, delete lines
//and update lines in memory and write back into file.
#include <stdio.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LENGTH 256
// Function Prototypes
int read_from_file(const char *filename, char lines[MAX_LINES][MAX_LENGTH], int *line_count);
int add_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count, const char *new_line);
int insert_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count, int position, const char *new_line);
int delete_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count, int position);
int update_line(char lines[MAX_LINES][MAX_LENGTH], int line_number, const char *new_content);
int write_to_file(const char *filename, char lines[MAX_LINES][MAX_LENGTH], int line_count);
int main() {
    char filename[] = "sample.txt";
    char lines[MAX_LINES][MAX_LENGTH];
    int line_count = 0;   
    if (read_from_file(filename, lines, &line_count) != 0) {
        printf("Error reading from file.\n");
        return 1;
    }
    int choice, position;
    char new_line[MAX_LENGTH];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Append Line\n2. Insert Line\n3. Delete Line\n4. Update Line\n5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter new line to append: ");
                fgets(new_line, MAX_LENGTH, stdin);
                new_line[strcspn(new_line, "\n")] = 0; // Remove newline character
                add_line(lines, &line_count, new_line);
                break;
            case 2:
                printf("Enter position to insert (1-based index): ");
                scanf("%d", &position);
                getchar(); // Clear buffer
                printf("Enter new line: ");
                fgets(new_line, MAX_LENGTH, stdin);
                new_line[strcspn(new_line, "\n")] = 0;
                insert_line(lines, &line_count, position - 1, new_line);
                break;
            case 3:
                printf("Enter line number to delete: ");
                scanf("%d", &position);
                delete_line(lines, &line_count, position - 1);
                break;
            case 4:
                printf("Enter line number to update: ");
                scanf("%d", &position);
                getchar(); // Clear buffer
                printf("Enter new content: ");
                fgets(new_line, MAX_LENGTH, stdin);
                new_line[strcspn(new_line, "\n")] = 0;
                update_line(lines, position - 1, new_line);
                break;
            case 5:
                write_to_file(filename, lines, line_count);
                printf("Changes saved to file. Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
int read_from_file(const char *filename, char lines[MAX_LINES][MAX_LENGTH], int *line_count) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;
    *line_count = 0;
    while (fgets(lines[*line_count], MAX_LENGTH, file) && *line_count < MAX_LINES) {
        lines[*line_count][strcspn(lines[*line_count], "\n")] = 0; // Remove newline
        (*line_count)++;
    }
    fclose(file);
    return 0;
}
// Function to append a new line at the end
int add_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count, const char *new_line) {
    if (*line_count >= MAX_LINES) return -1;
    strcpy(lines[*line_count], new_line);
    (*line_count)++;
    return 0;
}
// Function to insert a new line at a specific position
int insert_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count, int position, const char *new_line) {
    if (*line_count >= MAX_LINES || position < 0 || position > *line_count) return -1;
    for (int i = *line_count; i > position; i--) {
        strcpy(lines[i], lines[i - 1]);
    }
    strcpy(lines[position], new_line);
    (*line_count)++;
    return 0;
}
// Function to delete a line at a specific position
int delete_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count, int position) {
    if (position < 0 || position >= *line_count) return -1;
    for (int i = position; i < *line_count - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }
    (*line_count)--;
    return 0;
}
// Function to update a specific line
int update_line(char lines[MAX_LINES][MAX_LENGTH], int line_number, const char *new_content) {
    if (line_number < 0 || line_number >= MAX_LINES) return -1;
    strcpy(lines[line_number], new_content);
    return 0;
}
// Function to write updated content back to the file
int write_to_file(const char *filename, char lines[MAX_LINES][MAX_LENGTH], int line_count) {
    FILE *file = fopen(filename, "w");
    if (!file) return -1;
    for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
    return 0;
}