#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
};

// Function to add a book
void addBook() {
    FILE *fp = fopen("books.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar(); // clear buffer
    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';
    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("Enter Price: ");
    scanf("%f", &b.price);

    fwrite(&b, sizeof(struct Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    FILE *fp = fopen("books.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    struct Book b;
    printf("\n--- Book Records ---\n");
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\n\n",
               b.id, b.title, b.author, b.price);
    }
    fclose(fp);
}

// Function to search a book by ID
void searchBook() {
    FILE *fp = fopen("books.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    struct Book b;
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\n",
                   b.id, b.title, b.author, b.price);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Book not found!\n");
    fclose(fp);
}

// Function to update a book record
void updateBook() {
    FILE *fp = fopen("books.dat", "rb+");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    int id, found = 0;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);
    struct Book b;
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            printf("Enter new Title: ");
            getchar();
            fgets(b.title, sizeof(b.title), stdin);
            b.title[strcspn(b.title, "\n")] = '\0';
            printf("Enter new Author: ");
            fgets(b.author, sizeof(b.author), stdin);
            b.author[strcspn(b.author, "\n")] = '\0';
            printf("Enter new Price: ");
            scanf("%f", &b.price);

            fseek(fp, -sizeof(struct Book), SEEK_CUR);
            fwrite(&b, sizeof(struct Book), 1, fp);
            printf("Book updated successfully!\n");
            break;
        }
    }
    if (!found)
        printf("Book not found!\n");
    fclose(fp);
}

// Function to delete a book record
void deleteBook() {
    FILE *fp = fopen("books.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    int id, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    struct Book b;
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&b, sizeof(struct Book), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("books.dat");
    rename("temp.dat", "books.dat");
    if (found)
        printf("Book deleted successfully!\n");
    else
        printf("Book not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}