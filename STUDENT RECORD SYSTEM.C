#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];
    char name[50];
    char department[50];
    char section[20];
    float gpa;
};

int main() {
    struct Student students[100];      
    int count = 0; 
    int choice;

    while (1) { 
        printf("\n=== STUDENT RECORD SYSTEM ===");
        printf("\n1. Add Student");
        printf("\n2. Display All Students");
        printf("\n3. Search Student by ID");
        printf("\n4. Exit");
        printf("\nEnter choice (1-4): "); 
        scanf("%d", &choice);
      
        if (choice == 1) {
            printf("\nEnter ID: ");
            scanf("%s", students[count].id);
            
            printf("Enter Name: ");
            scanf("%s", students[count].name);
            
            printf("Enter Department: ");
            scanf("%s", students[count].department);

            printf("Enter Section: ");
            scanf("%s", students[count].section);

            printf("Enter GPA: ");
            scanf("%f", &students[count].gpa);
            
            count++; 
            printf("Student added successfully!\n");
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo records found!\n");
            } else {
                printf("\n--- ALL STUDENTS ---");
                for (int i = 0; i < count; i++) {
                    printf("\nID: %s | Name: %s | Dept: %s | Section: %s | GPA: %.2f", 
                        students[i].id, students[i].name, students[i].department, students[i].section, students[i].gpa);  
                }
                printf("\n"); 
            }
        }       
        else if (choice == 3) {
            char searchId[20];
            int found = 0;

            printf("\nEnter Student ID to search: ");
            scanf("%s", searchId);

            for (int i = 0; i < count; i++) {
                if (strcmp(students[i].id, searchId) == 0) {
                    printf("\nFound: ID: %s | Name: %s | Dept: %s | Section: %s | GPA: %.2f\n", 
                        students[i].id, students[i].name, students[i].department, students[i].section, students[i].gpa);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Student not found!\n");
            }
        }       
        else if (choice == 4) {
            printf("\nExiting program...\n");
            break;
        }       
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    } 
    
    return 0;
}