#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for contact
struct Contact {
  char name[50];
  char phone[15];
};

void addContact();
void viewContacts();
void searchContact();
void deleteContact();
void editContact();

int main() {
  int choice;

  while (1) {
    printf("\n===== Phonebook Application =====\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Edit Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // clear newline

    switch (choice) {
      case 1: addContact(); break;
      case 2: viewContacts(); break;
      case 3: searchContact(); break;
      case 4: editContact(); break;
      case 5: deleteContact(); break;
      case 6: exit(0);
      default: printf("Invalid choice! Try again.\n");
    }
    }
    return 0;
}

// Function to add a contact
void addContact() {
  FILE *fp = fopen("phonebook.dat", "ab");
  struct Contact c;

  printf("Enter name: ");
  fgets(c.name, sizeof(c.name), stdin);
  c.name[strcspn(c.name, "\n")] = 0;

  printf("Enter phone number: ");
  fgets(c.phone, sizeof(c.phone), stdin);
  c.phone[strcspn(c.phone, "\n")] = 0;

  fwrite(&c, sizeof(c), 1, fp);
  fclose(fp);

  printf("✅ Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts() {
  FILE *fp = fopen("phonebook.dat", "rb");
  struct Contact c;

  if (fp == NULL) {
    printf("No contacts found.\n");
    return;
    }

    printf("\n--- Contact List ---\n");
    while (fread(&c, sizeof(c), 1, fp)) {
        printf("Name: %s | Phone: %s\n", c.name, c.phone);
    }
    fclose(fp);
}

// Function to search a contact
void searchContact() {
    FILE *fp = fopen("phonebook.dat", "rb");
    struct Contact c;
    char name[50];
    int found = 0;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            printf("✅ Found: %s | Phone: %s\n", c.name, c.phone);
            found = 1;
            break;
        }
    }
    if (!found) printf("❌ Contact not found.\n");

    fclose(fp);
}

// Function to delete a contact
void deleteContact() {
    FILE *fp = fopen("phonebook.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Contact c;
    char name[50];
    int found = 0;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    printf("Enter name to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) != 0) {
            fwrite(&c, sizeof(c), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);

    remove("phonebook.dat");
    rename("temp.dat", "phonebook.dat");

    if (found)
        printf("✅ Contact deleted successfully.\n");
    else
        printf("❌ Contact not found.\n");
}

// Function to edit a contact
void editContact() {
    FILE *fp = fopen("phonebook.dat", "rb+");
    struct Contact c;
    char name[50];
    int found = 0;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    printf("Enter name to edit: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            printf("Enter new name: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Enter new phone: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            fseek(fp, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(c), 1, fp);
            found = 1;
            printf("✅ Contact updated successfully!\n");
            break;
        }
    }
    if (!found) printf("❌ Contact not found.\n");

    fclose(fp);
}
