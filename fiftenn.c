// 15. Write a program to sort an array of structures using 
// bubble sort using function pointers as call back

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
};

int compareByAge(const void *a,const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;

    if (studentA->age < studentB->age)
        return -1;  
    else if (studentA->age > studentB->age)
        return 1;   
    else
        return 0;   
}

void bubbleSort(void *arr, int n, size_t size, int (*compare)(const void *, const void *)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            void *a = (char *)arr + j * size;
            void *b = (char *)arr + (j + 1) * size;
            
            if (compare(a, b) > 0) {
                char temp[size];
                memcpy(temp, a, size);
                memcpy(a, b, size);
                memcpy(b, temp, size);
            }
        }
    }
}

void printStudents(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s Age: %d\n", students[i].name, students[i].age);
    }
}

int main() {
    struct Student students[] = {
        {"AA", 22},
        {"BB", 21},
        {"CC", 24},
        {"DD", 20}
    };
    int n = sizeof(students) / sizeof(students[0]);

    printf("Before Sorting:\n");
    printStudents(students, n);
   
    bubbleSort(students, n, sizeof(struct Student), compareByAge);
    
    printf("\nAfter Sorting by Age:\n");
    printStudents(students, n);

    return 0;
}
