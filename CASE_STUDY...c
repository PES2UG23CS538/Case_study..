#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    float price;
    int quantity;
};

struct Item inventory[MAX_ITEMS];
int numItems = 0;

void addProducts() {
    int numProducts;
    printf("Enter the number of products to add: ");
    scanf("%d", &numProducts);

    if (numItems + numProducts <= MAX_ITEMS) {
        for (int i = 0; i < numProducts; i++) {
            printf("Enter product details for product %d:\n", i + 1);
            printf("Name: ");
            scanf("%s", inventory[numItems].name);
            printf("Price: ");
            scanf("%f", &inventory[numItems].price);
            printf("Quantity: ");
            scanf("%d", &inventory[numItems].quantity);
            numItems++;
        }
        printf("Products added successfully.\n");
    } else {
        printf("Not enough space in inventory to add %d products.\n", numProducts);
    }
}

void generateBill() {
    char itemName[50];
    int quantityNeeded;
    float total = 0.0;
    int found = 0;

    printf("Enter the number of products to buy: ");
    scanf("%d", &quantityNeeded);

    printf("\n-------------------BILL-------------------\n");
    printf("%-20s %-10s %-10s\n", "Item", "Price", "Quantity");
    printf("------------------------------------------\n");

    for (int i = 0; i < quantityNeeded; i++) {
        printf("Enter the product you need: ");
        scanf("%s", itemName);
        
        found = 0;
        for (int j = 0; j < numItems; j++) {
            if (strcmp(itemName, inventory[j].name) == 0) {
                found = 1;
                if (inventory[j].quantity > 0) {
                    printf("%-20s %-10.2f %-10d\n", inventory[j].name, inventory[j].price, 1);
                    total += inventory[j].price;
                    inventory[j].quantity--;
                } else {
                    printf("Insufficient quantity available for %s.\n", itemName);
                    break;
                }
            }
        }

        if (!found) {
            printf("Product %s not available.\n", itemName);
        }
    }

    printf("------------------------------------------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    int choice;
    do {
        printf("\nWelcome to Smart Bazaar!\n");
        printf("1. Customer\n");
        printf("2. Shop Owner\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateBill();
                break;
            case 2:
                addProducts();
                break;
            case 3:
                printf("Exiting...\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (1); // Infinite loop until choice 3 is selected

    return 0;
}