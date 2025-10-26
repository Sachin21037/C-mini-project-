#include <stdio.h>
#include <string.h>

void voterreg()
{
    FILE *voters;
    char name[50];
    char address[100];
    char nic[20];
    int age, year;
    int current_year = 2025;

    while (1)
    { // Infinite Loop
        printf("\t\t---------------------------------------------------------------------------------------------------\n");
        printf("\t\t\tWelcome to Sri Lankan Parliament Election Voting System\n");
        printf("\t\t---------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t** VOTER REGISTRATION **\n\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ; // clear input buffer

        printf("Enter Your Full Name :");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Enter Your Address: ");
        fgets(address, sizeof(address), stdin);
        address[strcspn(address, "\n")] = 0;

        printf("Enter Your Birth Year :");
        scanf("%d", &year);
        getchar();

        age = current_year - year;

        if (age < 18)
        {
            printf("...Sorry, you are not eligible to register....\n\n");
            continue;
        }

        printf("Enter your NIC number: ");
        scanf("%s", nic);
        getchar();

        int len = strlen(nic); // Validate NIC Lenth
        if (len != 10 && len != 12)
        {
            printf("\nInvalid NIC Number. Registration Failed.\n\n");
            continue;
        }

        voters = fopen("voters.txt", "a"); // Open file to append data
        if (voters == NULL)
        {
            printf("Could not open file.\n");
            return;
        }

        fprintf(voters, "Name:\n %s", name); // Write details to file
        fprintf(voters, "Address:\n %s", address);
        fprintf(voters, "Birth year: %d\n", year);
        fprintf(voters, "Age: %d\n", age);
        fprintf(voters, "NIC: \n%s\n", nic);

        fclose(voters);

        printf("\n Registration Successful!!\n");
        printf("Your details have been saved to voters.txt\n\n\n");

        char choice;
        printf("\nDo you want to register another voter? (y/n): ");
        scanf(" %c", &choice);
        getchar();

        if (choice == 'n' || choice == 'N')
        {
            printf("Exiting voter registration system...\n");
            break; // Exit the infinite loop
        }
    }
}