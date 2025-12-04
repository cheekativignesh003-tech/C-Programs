#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define LINEBUF 256

typedef struct Book {
	int id;
	char title[100];
	char author[100];
} Book;

static Book library[MAX_BOOKS];
static int book_count = 0;
static int next_id = 1; /* unique ID generator */

/* helper: read a trimmed line into dst (size bytes) */
static void read_line(char *dst, size_t size) {
	if (!fgets(dst, (int)size, stdin)) {
		dst[0] = '\0';
		return;
	}
	/* remove trailing newline */
	size_t len = strlen(dst);
	if (len > 0 && dst[len - 1] == '\n') dst[len - 1] = '\0';
}

void add_book(void) {
	if (book_count >= MAX_BOOKS) {
		printf("Library is full!\n");
		return;
	}
	Book b;
	b.id = next_id++;
	printf("Enter book title: ");
	read_line(b.title, sizeof b.title);
	if (b.title[0] == '\0') {
		printf("Title cannot be empty. Aborting add.\n");
		return;
	}
	printf("Enter author name: ");
	read_line(b.author, sizeof b.author);
	if (b.author[0] == '\0') strncpy(b.author, "Unknown", sizeof b.author - 1);
	library[book_count++] = b;
	printf("Book added successfully! ID=%d\n", b.id);
}

/* case-insensitive compare for ASCII only; fallback for portability */
static int ascii_casecmp(const char *a, const char *b) {
	while (*a && *b) {
		char ca = *a >= 'A' && *a <= 'Z' ? *a + ('a' - 'A') : *a;
		char cb = *b >= 'A' && *b <= 'Z' ? *b + ('a' - 'A') : *b;
		if (ca != cb) return (unsigned char)ca - (unsigned char)cb;
		a++; b++;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

void search_book(void) {
	char search_title[100];
	printf("Enter book title to search: ");
	read_line(search_title, sizeof search_title);
	if (search_title[0] == '\0') {
		printf("Search title empty.\n");
		return;
	}
	for (int i = 0; i < book_count; i++) {
		if (ascii_casecmp(library[i].title, search_title) == 0) {
			printf("Book found! ID: %d, Title: %s, Author: %s\n",
				   library[i].id, library[i].title, library[i].author);
			return;
		}
	}
	printf("Book not found!\n");
}

void delete_book(void) {
	char line[LINEBUF];
	printf("Enter book ID to delete: ");
	read_line(line, sizeof line);
	char *endptr;
	long del_id = strtol(line, &endptr, 10);
	if (line[0] == '\0' || *endptr != '\0') {
		printf("Invalid ID input.\n");
		return;
	}
	int found = 0;
	for (int i = 0; i < book_count; i++) {
		if (library[i].id == (int)del_id) {
			found = 1;
			for (int j = i; j < book_count - 1; j++) {
				library[j] = library[j + 1];
			}
			book_count--;
			printf("Book deleted successfully!\n");
			break;
		}
	}
	if (!found) printf("Book ID not found!\n");
}

void list_books(void) {
	if (book_count == 0) {
		printf("No books in library.\n");
		return;
	}
	printf("\nLibrary Books:\n");
	for (int i = 0; i < book_count; i++) {
		printf("ID: %d, Title: %s, Author: %s\n",
			   library[i].id, library[i].title, library[i].author);
	}
}

int main(void) {
	char line[LINEBUF];
	while (1) {
		printf("\nLibrary Management System\n");
		printf("1. Add Book\n");
		printf("2. Search Book\n");
		printf("3. Delete Book\n");
		printf("4. List Books\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		read_line(line, sizeof line);
		int choice = (int)strtol(line, NULL, 10);
		switch (choice) {
			case 1: add_book(); break;
			case 2: search_book(); break;
			case 3: delete_book(); break;
			case 4: list_books(); break;
			case 5: return 0;
			default: printf("Invalid choice!\n");
		}
	}
	return 0;
}
