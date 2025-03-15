#include <stdio.h>

typedef struct _book{
    
    int id;
    char title[100];
    char author[100];
    int publication_year;
    int quantity;

} libro_t;

typedef struct _member{

    int id;
    char name[100];
    int bookIssued;

} member_t;

void addBook()
{
    printf("Añadiendo un libro\n");
}

void displayBook()
{

}

int main()
{
    int choice = 0;

    do{
        printf("Menu de manejo de Biblioteca\n");
        printf("1.- Agregar un Libro\n");
        printf("2.- ");
        printf("3.- ");
        printf("4.- ");
        printf("5.- ");
        printf("");


    }while();

}