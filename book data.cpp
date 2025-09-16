#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book {  // Structure for book
    char name[50];
    char author[50];
    float price;
};

int main() {
    FILE *fp;
    struct Book b;
    int n, i;

    
    fp = fopen("book.txt", "w"); // Open file in write mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter the number of books (max 200): ");
    scanf("%d", &n);
    getchar(); // consume newline

    // Write table header
    fprintf(fp, "%-30s %-30s %-10s\n", "Book Name", "Author Name", "Price");
    fprintf(fp, "--------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("\nEnter details for book %d:\n", i + 1);

        printf("Book Name: ");
        fgets(b.name, sizeof(b.name), stdin);
        b.name[strcspn(b.name, "\n")] = 0; // remove newline

        printf("Author Name: ");
        fgets(b.author, sizeof(b.author), stdin);
        b.author[strcspn(b.author, "\n")] = 0; // remove newline

        printf("Price: ");
        scanf("%f", &b.price);
        getchar(); // consume newline

        // Write data to file in table format
        fprintf(fp, "%-30s %-30s %-10.2f\n", b.name, b.author, b.price);
    }

    fclose(fp);

   
    fp = fopen("book.txt", "r") ; // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\n----- Book Records -----\n\n");
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}

