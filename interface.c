#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void adminlog();
void registerpartie();
void candidate_reg();
void votecast();
void voterreg();
void votecount();

void main()
{
    adminlog();
    return;
}

void adminlog()
{
    FILE *admlog;
    char password[20];
    char adminpass[20];
    char adpass[20];
    char line[100];
    int choice;
    printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\tWelcome to Sri Lankan Parliament Election Voting System\n");
    printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t** ADMIN login **\n\n");

    admlog = fopen("admin.txt", "r");

    printf("\t\tenter admin password:");
    scanf("\t\t%s", adpass);
    FILE *adminfile;
    adminfile = fopen("admin.txt", "r");
    if (adminfile == NULL)
    {
        printf("Error: Could not open admin.txt!! \ncheck admin details are saved.\n");
        return;
    }
    fgets(line, sizeof(line), admlog); // 1st line
    fgets(line, sizeof(line), admlog); // 2nd line
    fscanf(admlog, "%s", adminpass);
    if ((strcmp(adminpass, adpass)) == 0)
    

    {
        system("cls");
        printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\tWelcome to Sri Lankan Parliament Election Voting System\n");
        printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t** ADMIN PANEL  **\n\n");

        printf("\t\t\t\t\t\t\tAccess Granted!\n");
        do
        {
            printf("\t\t\t\t\t\t\tChose your number:\n\n");

            printf("\t\t\t\t\t\t\t1: open party registration\n");
            printf("\t\t\t\t\t\t\t2: open candidate registration\n");
            printf("\t\t\t\t\t\t\t3: start voter registration\n");

            printf("\t\t\t\t\t\t\t4: start vote cast\n");
            printf("\t\t\t\t\t\t\t5: start vote counting\n");
            printf("\t\t\t\t\t\t\t6: exit admin panel\n");

            printf("\n\t\tPlease Enter Your Number:");

            scanf(" %d", &choice);

            switch (choice)
            {
            case 1:
                registerpartie();
                system("cls");
                 printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
                break;
            case 2:
                candidate_reg();
                system("cls");
                 printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
                break;
            case 3:
                voterreg();
                system("cls");
                 printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
                break;
            case 4:
                votecast();
                system("cls");
                 printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
                break;

            case 5:
                votecount();

            case 6:
                printf("Exiting Admin Panel. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! enter again!!!\n");
            }
            

        } while (choice != 6);
    }
    else
    {
        printf("Access Denied! Incorrect Password.\n");
    }
}
