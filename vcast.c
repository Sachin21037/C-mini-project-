#include <stdio.h>
#include <string.h>


void votecast()
{
    FILE *vcast;
    FILE *party1;
    FILE *party2;
    FILE *party3;
    FILE *party4;
    FILE *party5;
    FILE *votecount;

    char nic[20], name[50], age[10];
    char line[100];
    char input_nic[20];
    int found = 0;
    char partyname[50];
    int vote;
    int totalVotes = 0;
    int cvote;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int v = 3;
    char adverify;
    char adpass[20];
    char adminpass[20];
    char adminchoice[10];

    char voteagain;
    do
    {
        printf("\t\t---------------------------------------------------------------------------------------------------\n");
        printf("\t\t\tWelcome to Sri Lankan Parliament Election Voting System\n");
        printf("\t\t---------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t** VOTE CASTING **\n\n");

        printf("Enter your NIC: ");
        scanf(" %[^\n]", input_nic);

        vcast = fopen("voters.txt", "r");
        if (vcast == NULL)
        {
            printf("Error: Could not open voters.txt\n");
            return;
        }

        // Read file line by line
        while (fgets(line, sizeof(line), vcast) != NULL)
        {
            if (strncmp(line, "Name:", 5) == 0)
            {
                fgets(name, sizeof(name), vcast); // read name line
                fgets(line, sizeof(line), vcast); // skip "Age:" label
                fgets(age, sizeof(age), vcast);   // read age
                fgets(line, sizeof(line), vcast); // skip "NIC:" label
                fgets(nic, sizeof(nic), vcast);   // read nic

                // Remove newline characters
                name[strcspn(name, "\n")] = 0;
                age[strcspn(age, "\n")] = 0;
                nic[strcspn(nic, "\n")] = 0;

                if (strcmp(nic, input_nic) == 0)
                {
                    found = 1;
                    printf("\nVoter Found!\n");
                    printf("Name: %s\n", name);
                    printf("Age: %s\n", age);
                    printf("NIC: %s\n\n", nic);
                    break;
                }
            }
        }

        if (!found)
        {
            printf("\nNo voter found with NIC: %s\n", input_nic);
            break;
        }

        fclose(vcast);

        //--------------------------voting part--------------------------
        votecount = fopen("votecount.txt", "w");
        party1 = fopen("partie1.txt", "r");
        party2 = fopen("partie2.txt", "r");
        party3 = fopen("partie3.txt", "r");
        party4 = fopen("partie4.txt", "r");
        party5 = fopen("partie5.txt", "r");

        
        votecount = fopen("votecount.txt", "w");

        FILE *parties[5];
        char filename[20];
        char line[200], partyname[100];

        for (int i = 0; i < 5; i++)
        {
            sprintf(filename, "partie%d.txt", i + 1);
            parties[i] = fopen(filename, "r");

            if (parties[i] == NULL)
            {
                printf("Error opening %s\n", filename);
                continue;
            }

            // Skip the first line
            fgets(line, sizeof(line), parties[i]);

            // Read the party name (2nd line)
            if (fgets(partyname, sizeof(partyname), parties[i]) != NULL)
            {
                partyname[strcspn(partyname, "\n")] = '\0'; // remove newline
                printf("%d. %s\n", i + 1, partyname);
            }
        }

        

        int lineNumber = 0;

        printf("\nparty 1 candidates:\n");
        if (party1 == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        while (fgets(line, sizeof(line), party1))
        {
            lineNumber++;
            if (lineNumber == 2) // skip only the second line (Party 1 Details)
                continue;

            printf("%s", line);
        }

        printf("\nparty 2 candidates:\n");

        if (party2 == NULL)
        {
            printf("Error opening file!\n");
            return;
        }
        
        while (fgets(line, sizeof(line), party2))
        {
         lineNumber++;
            if (lineNumber == 2) // skip only the second line (Party 1 Details)
                continue;

            printf("%s", line);
        }
        printf("\nparty 3 candidates:\n");
        if (party3 == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        while (fgets(line, sizeof(line), party3))
        {
            lineNumber++;
            if (lineNumber == 2) // skip only the second line (Party 1 Details)
                continue;

            printf("%s", line);
        }
        printf("\nparty 4 candidates:\n");
        if (party4 == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        while (fgets(line, sizeof(line), party4))
        {
            lineNumber++;
            if (lineNumber == 1) // skip only the second line (Party 1 Details)
                continue;

            printf("%s", line);
        }
        printf("\nparty 5 candidates:\n");
        if (party5 == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        while (fgets(line, sizeof(line), party5))
        {
            lineNumber++;
            if (lineNumber == 1) // skip only the second line (Party 1 Details)
                continue;

            printf("%s", line);
        }

        printf("\nselect a party to vote for: ");
        scanf("%d", &vote);

        fclose(party1);
        fclose(party2);
        fclose(party3);
        fclose(party4);
        fclose(party5);

        switch (vote)
        {
        case 1:
            printf("you selcted party 1\n");
            do
            {
                printf("select a candidate to vote for:\n");
                scanf("%d", &cvote);
                switch (cvote)
                {

                case 1:
                    printf("you voted for candidate 1 of party 1\n");
                    a = a + 1;

                    fprintf(votecount, "candidate 1 of party 1:%d\n", a);
                    break;
                case 2:
                    printf("you voted for candidate 2 of party 1\n");

                    b = b + 1;
                    fprintf(votecount, "candidate 2 of party 1:%d\n", b);
                    break;
                case 3:
                    printf("you voted for candidate 3 of party 1\n");
                    c = c + 1;
                    fprintf(votecount, "candidate 3 of party 1:%d\n", c);
                    break;
                case 4:
                    printf("you voted for candidate 4 of party 1\n");

                    d = d + 1;
                    fprintf(votecount, "candidate 4 of party 1:%d\n", d);
                    break;
                case 5:
                    printf("you voted for candidate 5 of party 1\n");

                    e = e + 1;
                    fprintf(votecount, "candidate 5 of party 1:%d\n", e);
                    break;
                default:
                    printf("invalid candidate number\n");
                }
                v = --v;
                printf("done!!!\ndo you want to vote again?(y/n)(you have %d votes left)\n", v);

                scanf(" %c", &voteagain);

            } while ((v > 0) && (voteagain == 'y' || voteagain == 'Y'));

            break;

        case 2:
            printf("You voted for party 2\n");
            do
            {
                printf("select a candidate to vote for:\n");
                scanf("%d", &cvote);
                switch (cvote)
                {

                case 1:
                    printf("you voted for candidate 1 of party 2\n");
                    a = a + 1;

                    fprintf(votecount, "candidate 1 of party 2:%d\n", a);
                    break;
                case 2:
                    printf("you voted for candidate 2 of party 2\n");

                    b = b + 1;
                    fprintf(votecount, "candidate 2 of party 2:%d\n", b);
                    break;
                case 3:
                    printf("you voted for candidate 3 of party 2\n");
                    c = c + 1;
                    fprintf(votecount, "candidate 3 of party 2:%d\n", c);
                    break;
                case 4:
                    printf("you voted for candidate 4 of party 2\n");

                    d = d + 1;
                    fprintf(votecount, "candidate 4 of party 2:%d\n", d);
                    break;
                case 5:
                    printf("you voted for candidate 5 of party 2\n");

                    e = e + 1;
                    fprintf(votecount, "candidate 5 of party 2:%d\n", e);
                    break;
                default:
                    printf("invalid candidate number\n");
                }
                v = --v;
                printf("done!!!\ndo you want to vote again?(y/n)(you have %d votes left)\n", v);

                scanf(" %c", &voteagain);

            } while ((v > 0) && (voteagain == 'y' || voteagain == 'Y'));

            break;
        case 3:
            printf("You voted for party 3\n");
            do
            {
                printf("select a candidate to vote for:\n");
                scanf("%d", &cvote);
                switch (cvote)
                {

                case 1:
                    printf("you voted for candidate 1 of party 3\n");
                    a = a + 1;

                    fprintf(votecount, "candidate 1 of party 3:%d\n", a);
                    break;
                case 2:
                    printf("you voted for candidate 2 of party 3\n");

                    b = b + 1;
                    fprintf(votecount, "candidate 2 of party 3:%d\n", b);
                    break;
                case 3:
                    printf("you voted for candidate 3 of party 3\n");
                    c = c + 1;
                    fprintf(votecount, "candidate 3 of party 3:%d\n", c);
                    break;
                case 4:
                    printf("you voted for candidate 4 of party 3\n");

                    d = d + 1;
                    fprintf(votecount, "candidate 4 of party 3:%d\n", d);
                    break;
                case 5:
                    printf("you voted for candidate 5 of party 3\n");

                    e = e + 1;
                    fprintf(votecount, "candidate 5 of party 3:%d\n", e);
                    break;
                default:
                    printf("invalid candidate number\n");
                }
                v = --v;
                printf("done!!!\ndo you want to vote again?(y/n)(you have %d votes left)\n", v);

                scanf(" %c", &voteagain);

            } while ((v > 0) && (voteagain == 'y' || voteagain == 'Y'));

            break;
        case 4:
            printf("You voted for party 4\n");
            do
            {
                printf("select a candidate to vote for:\n");
                scanf("%d", &cvote);
                switch (cvote)
                {

                case 1:
                    printf("you voted for candidate 1 of party 4\n");
                    a = a + 1;

                    fprintf(votecount, "candidate 1 of party 4:%d\n", a);
                    break;
                case 2:
                    printf("you voted for candidate 2 of party 4\n");

                    b = b + 1;
                    fprintf(votecount, "candidate 2 of party 4:%d\n", b);
                    break;
                case 3:
                    printf("you voted for candidate 3 of party 4\n");
                    c = c + 1;
                    fprintf(votecount, "candidate 3 of party 4:%d\n", c);
                    break;
                case 4:
                    printf("you voted for candidate 4 of party 4\n");

                    d = d + 1;
                    fprintf(votecount, "candidate 4 of party 4:%d\n", d);
                    break;
                case 5:
                    printf("you voted for candidate 5 of party 4\n");

                    e = e + 1;
                    fprintf(votecount, "candidate 5 of party 4:%d\n", e);
                    break;
                default:
                    printf("invalid candidate number\n");
                }
                v = --v;
                printf("done!!!\ndo you want to vote again?(y/n)(you have %d votes left)\n", v);

                scanf(" %c", &voteagain);

            } while ((v > 0) && (voteagain == 'y' || voteagain == 'Y'));

            break;
        case 5:
            printf("You voted for party 5\n");
            do
            {
                printf("select a candidate to vote for:\n");
                scanf("%d", &cvote);
                switch (cvote)
                {

                case 1:
                    printf("you voted for candidate 1 of party 5\n");
                    a = a + 1;

                    fprintf(votecount, "candidate 1 of party 5:%d\n", a);
                    break;
                case 2:
                    printf("you voted for candidate 2 of party 5\n");

                    b = b + 1;
                    fprintf(votecount, "candidate 2 of party 5:%d\n", b);
                    break;
                case 3:
                    printf("you voted for candidate 3 of party 5\n");
                    c = c + 1;
                    fprintf(votecount, "candidate 3 of party 5:%d\n", c);
                    break;
                case 4:
                    printf("you voted for candidate 4 of party 5\n");

                    d = d + 1;
                    fprintf(votecount, "candidate 4 of party 5:%d\n", d);
                    break;
                case 5:
                    printf("you voted for candidate 5 of party 5\n");

                    e = e + 1;
                    fprintf(votecount, "candidate 5 of party 5:%d\n", e);
                    break;
                default:
                    printf("invalid candidate number\n");
                }
                v = --v;
                printf("done!!!\ndo you want to vote again?(y/n)(you have %d votes left)\n", v);

                scanf(" %c", &voteagain);

            } while ((v > 0) && (voteagain == 'y' || voteagain == 'Y'));

            break;
        default:
            printf("Invalid party number\n");
        }
        printf("are you an admin?(y/n): ");
        scanf(" %c", &adverify);
        if (adverify == 'y' || adverify == 'Y')
        {
            printf("enter admin password:");
            scanf("%s", adpass);
            FILE *adminfile;
            adminfile = fopen("admin.txt", "r");
            fgets(line, sizeof(line), adminfile); // 1st line
            fgets(line, sizeof(line), adminfile); // 2nd line
            fscanf(adminfile, "%s", adminpass);
            if ((strcmp(adminpass, adpass)) == 0)
                ;
            {
                printf("admin verified\n");
                printf("do you want to end the voting?(type 'd' to end): ");
                scanf(" %s", &adminchoice);
            }
        }

    } while ((strcmp(adminchoice, "d") != 0) || (adverify != 'y' && adverify != 'Y'));
    fclose(votecount);
    printf("voting ended successfully\n");
}
