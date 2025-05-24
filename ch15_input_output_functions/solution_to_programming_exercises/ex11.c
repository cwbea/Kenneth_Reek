#include <stdio.h>      // Includes standard input/output functions (e.g., printf, scanf)
#include <stdlib.h>     // Includes standard library functions (e.g., exit)
#include <string.h>     // Includes string manipulation functions (e.g., strcpy, memset)

#define MAX_DESC 20      // Defines maximum number of characters allowed for a part description (20 characters)
#define MAX_PARTS 1000   // Defines maximum number of parts allowed in the inventory (1000 parts)

// Define a structure to hold data about a single inventory part
typedef struct {
    char description[MAX_DESC + 1]; // Character array to store description (up to 20 chars + 1 for null terminator)
    int quantity;                   // Integer to store quantity of items in stock
    float total_value;             // Float to store total monetary value of the stock of this part
} Part;

// Function to open (or create) the inventory file
// @param filename: name of the inventory file to open
// @return FILE pointer to the opened file
FILE *open_inventory(const char *filename) {
    FILE *file = fopen(filename, "r+b"); // Try to open file for reading and writing in binary mode

    if (!file) { // If file doesn't exist or couldn't be opened
        file = fopen(filename, "w+b"); // Create a new file in write+binary mode
        if (!file) { // If creation also fails
            perror("Failed to create inventory file"); // Print error message
            exit(EXIT_FAILURE); // Exit program with failure status
        }

        // Initialize inventory with empty parts
        Part empty = {"", 0, 0.0}; // Create a part with empty description and zero quantity and value
        for (int i = 0; i < MAX_PARTS; i++) {
            fwrite(&empty, sizeof(Part), 1, file); // Write empty part to file
        }
    }
    return file; // Return the file pointer
}

// Function to find the first available (empty) slot in the inventory
// @param file: pointer to the open inventory file
// @return index (0-based) of the first empty slot, or -1 if none found
int find_free_slot(FILE *file) {
    rewind(file); // Move file position to the beginning
    Part part;    // Temporary variable to store parts as we read them

    for (int i = 0; i < MAX_PARTS; i++) {
        fread(&part, sizeof(Part), 1, file); // Read one part from file
        if (part.description[0] == '\0') {  // If description is empty (first character is null terminator)
            return i; // Return this index as a free slot
        }
    }
    return -1; // Return -1 if no free slot found
}

// Function to load a specific part from the file
// @param file: pointer to the inventory file
// @param part_number: the 1-based index of the part to load
// @param part: pointer to a Part variable where the data will be loaded
// @return 1 if successful, 0 if the part number is invalid
int load_part(FILE *file, int part_number, Part *part) {
    if (part_number < 1 || part_number > MAX_PARTS) return 0; // Check if part number is valid

    fseek(file, (part_number - 1) * sizeof(Part), SEEK_SET); // Move file pointer to the desired part
    fread(part, sizeof(Part), 1, file); // Read the part from file into the provided structure
    return 1; // Return success
}

// Function to save (write) a Part structure into the inventory file at a given position
// @param file: pointer to the inventory file
// @param part_number: 1-based index where the part will be saved
// @param part: pointer to the Part to write into the file
void save_part(FILE *file, int part_number, Part *part) {
    fseek(file, (part_number - 1) * sizeof(Part), SEEK_SET); // Move file pointer to the correct part position
    fwrite(part, sizeof(Part), 1, file); // Write the part into the file
}

// Function to add a new part to the inventory (user provides description, quantity, and cost)
// @param file: pointer to the inventory file
void transaction_new(FILE *file) {
    char desc[MAX_DESC + 1]; // Variable to hold user input for description
    int quantity;            // Variable to hold user input for quantity
    float cost;              // Variable to hold user input for cost per item

    printf("Enter description: ");
    scanf(" %20[^\n]", desc); // Read up to 20 characters including spaces until newline

    printf("Enter quantity: ");
    scanf("%d", &quantity); // Read integer for quantity

    printf("Enter cost per item: ");
    scanf("%f", &cost); // Read float for cost

    if (quantity < 0 || cost < 0) { // Check for valid non-negative inputs
        printf("Error: Quantity and cost must be non-negative.\n");
        return;
    }

    int index = find_free_slot(file); // Find the first available slot
    if (index == -1) { // If no slot is free
        printf("Inventory is full.\n");
        return;
    }

    // Create a new part with entered data
    Part new_part;
    strncpy(new_part.description, desc, MAX_DESC); // Copy description safely
    new_part.description[MAX_DESC] = '\0'; // Ensure null termination
    new_part.quantity = quantity; // Set quantity
    new_part.total_value = quantity * cost; // Calculate total value

    save_part(file, index + 1, &new_part); // Save part to file (convert to 1-based index)
    printf("Part added with part number %d.\n", index + 1); // Confirm to user
}

// Function to increase the stock of an existing part
// @param file: pointer to the inventory file
void transaction_buy(FILE *file) {
    int part_num;   // Variable to hold part number
    int quantity;   // Variable to hold how many items to add
    float cost;     // Variable to hold cost per item

    printf("Enter part number: ");
    scanf("%d", &part_num); // Get the part number from the user

    printf("Enter quantity to buy: ");
    scanf("%d", &quantity); // Get the quantity to add

    printf("Enter cost per item: ");
    scanf("%f", &cost); // Get the cost per item

    Part part;
    if (!load_part(file, part_num, &part) || part.description[0] == '\0') {
        printf("Invalid part number.\n"); // If part doesn't exist, show error
        return;
    }

    // Update total value and quantity
    part.total_value += quantity * cost; // Increase total value
    part.quantity += quantity; // Increase quantity

    save_part(file, part_num, &part); // Save changes back to file
    printf("Updated part %d.\n", part_num); // Notify user
}

// Function to sell (reduce) stock of an existing part
// @param file: pointer to the inventory file
void transaction_sell(FILE *file) {
    int part_num;   // Variable for part number to sell
    int quantity;   // Quantity to sell
    float price;    // Selling price per item

    printf("Enter part number: ");
    scanf("%d", &part_num);

    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    printf("Enter selling price per item: ");
    scanf("%f", &price);

    Part part;
    if (!load_part(file, part_num, &part) || part.description[0] == '\0') {
        printf("Invalid part number.\n"); // Error if part not found
        return;
    }

    if (quantity > part.quantity) {
        printf("Not enough stock to sell.\n"); // Can't sell more than available
        return;
    }

    float unit_cost = part.total_value / part.quantity; // Calculate cost per item
    float profit = (price - unit_cost) * quantity;      // Calculate profit

    part.quantity -= quantity; // Reduce quantity
    part.total_value -= unit_cost * quantity; // Adjust total value

    save_part(file, part_num, &part); // Save changes
    printf("Sold %d units. Profit: $%.2f\n", quantity, profit); // Show result
}

// Function to delete a part from inventory
// @param file: pointer to the inventory file
void transaction_delete(FILE *file) {
    int part_num; // Variable to hold part number

    printf("Enter part number to delete: ");
    scanf("%d", &part_num);

    Part part;
    if (!load_part(file, part_num, &part) || part.description[0] == '\0') {
        printf("Invalid part number.\n");
        return;
    }

    memset(&part, 0, sizeof(Part)); // Clear the memory of this part (set to empty)
    save_part(file, part_num, &part); // Save the cleared part to file
    printf("Part %d deleted.\n", part_num); // Notify user
}

// Function to print details of a single part
// @param file: pointer to the inventory file
void transaction_print(FILE *file) {
    int part_num; // Part number to print

    printf("Enter part number to print: ");
    scanf("%d", &part_num);

    Part part;
    if (!load_part(file, part_num, &part) || part.description[0] == '\0') {
        printf("Part not found.\n");
        return;
    }

    printf("Part %d: %-20s | Qty: %d | Total: $%.2f\n",
           part_num, part.description, part.quantity, part.total_value); // Print part info
}

// Function to print all existing parts in the inventory
// @param file: pointer to the inventory file
void transaction_print_all(FILE *file) {
    rewind(file); // Go to beginning of file
    Part part;

    // Print table header
    printf("\n%-6s | %-20s | %-8s | %s\n", "Part#", "Description", "Quantity", "Total Value");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < MAX_PARTS; i++) {
        fread(&part, sizeof(Part), 1, file); // Read each part
        if (part.description[0] != '\0') { // If not empty
            printf("%-6d | %-20s | %-8d | $%10.2f\n",
                   i + 1, part.description, part.quantity, part.total_value); // Print part info
        }
    }
}

// Function to calculate and print the total value of all parts
// @param file: pointer to the inventory file
void transaction_total(FILE *file) {
    rewind(file); // Go to start of file
    Part part;    // Temp part for reading
    float total = 0.0; // Variable to accumulate total value

    for (int i = 0; i < MAX_PARTS; i++) {
        fread(&part, sizeof(Part), 1, file);
        if (part.description[0] != '\0') { // If part exists
            total += part.total_value; // Add its value to total
        }
    }

    printf("Total inventory value: $%.2f\n", total); // Print total value
}

// Function to display the main menu options to the user
void show_menu() {
    printf("\n========== Inventory Menu ==========");
    printf("\n1. Add New Part");
    printf("\n2. Buy (Add Stock)");
    printf("\n3. Sell (Reduce Stock)");
    printf("\n4. Delete Part");
    printf("\n5. Print One Part");
    printf("\n6. Print All Parts");
    printf("\n7. Total Inventory Value");
    printf("\n8. Exit\n");
    printf("Select an option (1-8): ");
}

// Main function - entry point of the program
// @param argc: argument count (should be 2)
// @param argv: argument vector (argv[1] is inventory file name)
int main(int argc, char *argv[]) {
    if (argc != 2) { // Check if user provided exactly one argument (file name)
        printf("Usage: %s inventory-file\n", argv[0]); // Show usage message
        return 1; // Exit with error code
    }

    FILE *file = open_inventory(argv[1]); // Open the inventory file
    int choice; // Variable to store user's menu choice

    do {
        show_menu(); // Display menu to user
        scanf("%d", &choice); // Get user's choice
        getchar(); // Remove newline character from input buffer

        // Perform action based on user choice
        switch (choice) {
            case 1: transaction_new(file); break;
            case 2: transaction_buy(file); break;
            case 3: transaction_sell(file); break;
            case 4: transaction_delete(file); break;
            case 5: transaction_print(file); break;
            case 6: transaction_print_all(file); break;
            case 7: transaction_total(file); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }
    } while (choice != 8); // Repeat until user chooses to exit

    fclose(file); // Close the inventory file before exiting
    return 0; // Indicate successful program termination
}

