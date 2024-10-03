#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100

// Structure to represent a person
typedef struct {
    char name[50];
    int age;
} Person;

// Global array to hold people
Person people[MAX_PEOPLE];
int count = 0;

// Function prototypes
void createPerson();
void readPeople();
void updatePerson();
void deletePerson();

int main() {
    int choice;

    while (1) {
        printf("\nSimple CRUD Application\n");
        printf("1. Create Person\n");
        printf("2. Read People\n");
        printf("3. Update Person\n");
        printf("4. Delete Person\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                createPerson();
                break;
            case 2:
                readPeople();
                break;
            case 3:
                updatePerson();
                break;
            case 4:
                deletePerson();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to create a new person
void createPerson() {
    if (count >= MAX_PEOPLE) {
        printf("Cannot add more people. List is full.\n");
        return;
    }
    printf("Enter name: ");
    fgets(people[count].name, sizeof(people[count].name), stdin);
    people[count].name[strcspn(people[count].name, "\n")] = 0; // Remove newline
    printf("Enter age: ");
    scanf("%d", &people[count].age);
    getchar(); // Consume newline

    count++;
    printf("Person added: %s, Age: %d\n", people[count - 1].name, people[count - 1].age);
}

// Function to read and display all people
void readPeople() {
    printf("\nList of People:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

// Function to update an existing person
void updatePerson() {
    char name[50];
    printf("Enter the name of the person to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Enter new name: ");
            fgets(people[i].name, sizeof(people[i].name), stdin);
            people[i].name[strcspn(people[i].name, "\n")] = 0; // Remove newline
            printf("Enter new age: ");
            scanf("%d", &people[i].age);
            getchar(); // Consume newline
            printf("Person updated: %s, Age: %d\n", people[i].name, people[i].age);
            return;
        }
    }
    printf("Person not found.\n");
}

// Function to delete a person
void deletePerson() {
    char name[50];
    printf("Enter the name of the person to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                people[j] = people[j + 1]; // Shift left
            }
            count--;
            printf("Person deleted: %s\n", name);
            return;
        }
    }
    printf("Person not found.\n");
}