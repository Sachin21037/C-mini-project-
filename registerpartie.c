#include<stdio.h>
#include<string.h>

void registerpartie()
{
    FILE *fp;
    char filename[20];
    char partyName[30];
    char like[5];

    fp = fopen("temppartie.txt", "w+");
    if (fp == NULL)
    {
        printf("File is not open\n");
        return;
    }
    fprintf(fp, "\t\t\t\t\tTemporary party registration file.\n");
    fclose(fp);

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\t\tWelcome to Sri Lankan Parliament Election Voting System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t**PARTIES REGISTRATION**\n\n");

    for (int i = 1; i <= 5; i++)
    {
        sprintf(filename, "partie%d.txt", i);

        while (1)
        {
            printf("Would you like to register with this party? %d (yes/no): ", i);
            scanf("%s", like);

            for (int j = 0; like[j]; j++)
            {
                if (like[j] >= 'A' && like[j] <= 'Z')
                    like[j] += 32;
            }

            if (strcmp(like, "yes") == 0)
            {
                fp = fopen(filename, "w");
                if (fp == NULL)
                {
                    printf("File %d is not open\n", i);
                    return;
                }

                printf("Enter the name of party %d: ", i);
                scanf(" %[^\n]", partyName);

                fprintf(fp, "\t\t\t\t\tParty %d Details\n", i);
                fprintf(fp, "Party Name: %s\n", partyName);
                fclose(fp);

                printf("Party %d successfully registered.\n\n", i);
                break;
            }
            else if (strcmp(like, "no") == 0)
            {
                printf("Party %d skipped.\n\n", i);
                break;
            }
            else
            {
                printf("Invalid input! Please type only 'yes' or 'no'.\n");
            }
        }
    }

    printf("\nSuccessfully registered all parties.\n");
}