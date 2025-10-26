#include <stdio.h>
#include <string.h>

void candidate_reg()
{
    FILE *fp;
    FILE *party;
    char name[50];
    char nic[20];
    char partyName[50];
    int Number;

    printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\tWelcome to Sri Lankan Parliament Election Voting System\n");
    printf("\t\t\t\t---------------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t\t** CANDIDATE REGISTRATION **\n\n");

    // Display party names
    for (int i = 1; i <= 5; i++)
    {
        char filename[20];
        sprintf(filename, "partie%d.txt", i);
        party = fopen(filename, "r");

        if (party == NULL)
        {
            printf("\t\t%d. [File not found]\n", i);
            continue;
        }
        // skip first 2 line
        for (int j = 1; j <= 1; j++)
        {
            if (fgets(partyName, sizeof(partyName), party) == NULL)
            {
                printf("File has fewer then 2 lines\n");
                fclose(party);
                break;
            }
        }
        // read 3rd line
        if (fgets(partyName, sizeof(partyName), party) != NULL)
        {
            printf("\t\t%d. %s\n", i, partyName);
        }
        else
        {
            printf("Erroe");
        }
        fclose(party);
    }

    printf("\t\t\nSelect Your Party Number: ");
    scanf("%d", &Number);

    switch (Number)
    {
    case 1:
        int count1 = 1;
        char n1;
        do
        {
            // Give Candidate Name
            printf("\t\tEnter your full name : ");
            scanf(" %[^\n]", name); // Get name with spaces

            // Give Candidate Nic
            printf("\t\tEnter your NIC No : ");
            scanf("%s", nic);

            int nicLength = strlen(nic);
            if (nicLength != 10 && nicLength != 12)
            {
                printf("\n---Invalid NIC Number. Registration Failed---\n");

                return;
            }

            printf("Do you Want Another Candidate Register(y/n):");
            scanf(" %c", &n1);
            count1++;

            party = fopen("partie1.txt", "a");
            if (fp == NULL)
            {
                printf("Cannot write Data into the file!!!");
            }
            fprintf(party, "\n%s\n %s\n", name, nic);
            fclose(party);

        } while (((n1 == 'Y' || n1 == 'y') && (count1 <= 5)));
        printf("All Candidates are registered!!!!");
        break;
    case 2:
        int count2 = 1;
        char n2;
        do
        {
            // Give Candidate Name
            printf("\t\tEnter your full name : ");
            scanf(" %[^\n]", name); // Get name with spaces

            // Give Candidate Nic
            printf("\n\t\tEnter your NIC No : ");
            scanf(" %s", nic);

            int nicLength = strlen(nic);
            if (nicLength != 10 && nicLength != 12)
            {
                printf("\n---Invalid NIC Number. Registration Failed---\n");

                return;
            }

            printf("Do you Want Another Candidate Register(y/n):");
            scanf(" %c", &n2);
            count2++;

            party = fopen("partie2.txt", "a");
            if (party == NULL)
            {
                printf("Cannot write Data into the file!!!");
            }
            fprintf(fp, "\n%s\n %s\n", name, nic);
            fclose(fp);

        } while (((n2 == 'Y' || n2 == 'y') && (count2 <= 5)));
        printf("All Candidates are registered!!!!");
        break;
    case 3:
        int count3 = 1;
        char n3;
        do
        {
            // Give Candidate Name
            printf("\t\tEnter your full name : ");
            scanf(" %[^\n]", name); // Get name with spaces

            // Give Candidate Nic
            printf("\n\t\tEnter your NIC No : ");
            scanf("%s", nic);

            int nicLength = strlen(nic);
            if (nicLength != 10 && nicLength != 12)
            {
                printf("\n---Invalid NIC Number. Registration Failed---\n");

                return;
            }

            printf("Do you Want Another Candidate Register(y/n):");
            scanf(" %c", &n3);
            count3++;

            party = fopen("partie3.txt", "a");
            if (party == NULL)
            {
                printf("Cannot write Data into the file!!!");
            }
            fprintf(party, "\n%s\n %s\n", name, nic);
            fclose(party);

        } while (((n3 == 'Y' || n3 == 'y') && (count3 <= 5)));
        printf("All Candidates are registered!!!!");
        break;
    case 4:
        int count4 = 1;
        char n4;
        do
        {
            // Give Candidate Name
            printf("\t\tEnter your full name : ");
            scanf(" %[^\n]", name); // Get name with spaces

            // Give Candidate Nic
            printf("\n\t\tEnter your NIC No : ");
            scanf("%s", nic);

            int nicLength = strlen(nic);
            if (nicLength != 10 && nicLength != 12)
            {
                printf("\n---Invalid NIC Number. Registration Failed---\n");

                return;
            }

            printf("Do you Want Another Candidate Register(y/n):");
            scanf(" %c", &n4);
            count4++;

            party = fopen("partie4.txt", "a");
            if (party == NULL)
            {
                printf("Cannot write Data into the file!!!");
            }
            fprintf(party, "\n%s\n %s\n", name, nic);
            fclose(party);

        } while (((n4 == 'Y' || n4 == 'y') && (count4 <= 5)));
        printf("All Candidates are registered!!!!");
        break;
    case 5:
        int count5 = 1;
        char n5;
        do
        {
            // Give Candidate Name
            printf("\t\tEnter your full name : ");
            scanf(" %[^\n]", name); // Get name with spaces

            // Give Candidate Nic
            printf("\n\t\tEnter your NIC No : ");
            scanf("%s", nic);

            int nicLength = strlen(nic);
            if (nicLength != 10 && nicLength != 12)
            {
                printf("\n---Invalid NIC Number. Registration Failed---\n");

                return;
            }

            printf("Do you Want Another Candidate Register(y/n):");
            scanf(" %c", &n5);
            count5++;

            party = fopen("partie5.txt", "a");
            if (party == NULL)
            {
                printf("Cannot write Data into the file!!!");
            }
            fprintf(party, "\n%s\n %s\n", name, nic);
            fclose(party);

        } while (((n5 == 'Y' || n5 == 'y') && (count5 <= 5)));
        printf("All Candidates are registered!!!!");
        break;
    default:
        printf("Invalid Party Number!!!");
    }
}
