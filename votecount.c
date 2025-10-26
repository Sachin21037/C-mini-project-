#include <stdio.h>
#include <string.h>

void votecount()
{
    FILE *ptr;
    char votecount[50];
    
    char *ca1p1 = "candidate 1 of party 1:1";
    char *ca2p1 = "candidate 2 of party 1:1";
    char *ca3p1 = "candidate 3 of party 1:1";
    char *ca4p1 = "candidate 4 of party 1:1";
    char *ca5p1 = "candidate 5 of party 1:1";

    char *ca1p2 = "candidate 1 of party 2:1";
    char *ca2p2 = "candidate 2 of party 2:1";
    char *ca3p2 = "candidate 3 of party 2:1";
    char *ca4p2 = "candidate 4 of party 2:1";
    char *ca5p2 = "candidate 5 of party 2:1";

    char *ca1p3 = "candidate 1 of party 3:1";
    char *ca2p3 = "candidate 2 of party 3:1";
    char *ca3p3 = "candidate 3 of party 3:1";
    char *ca4p3 = "candidate 4 of party 3:1";
    char *ca5p3 = "candidate 5 of party 3:1";

    char *ca1p4 = "candidate 1 of party 4:1";
    char *ca2p4 = "candidate 2 of party 4:1";
    char *ca3p4 = "candidate 3 of party 4:1";
    char *ca4p4 = "candidate 4 of party 4:1";
    char *ca5p4 = "candidate 5 of party 4:1";

    char *ca1p5 = "candidate 1 of party 5:1";
    char *ca2p5 = "candidate 2 of party 5:1";
    char *ca3p5 = "candidate 3 of party 5:1";
    char *ca4p5 = "candidate 4 of party 5:1";
    char *ca5p5 = "candidate 5 of party 5:1";

    int p1c1 = 0, p1c2 = 0, p1c3 = 0, p1c4 = 0, p1c5 = 0;
    int p2c1 = 0, p2c2 = 0, p2c3 = 0, p2c4 = 0, p2c5 = 0;
    int p3c1 = 0, p3c2 = 0, p3c3 = 0, p3c4 = 0, p3c5 = 0;
    int p4c1 = 0, p4c2 = 0, p4c3 = 0, p4c4 = 0, p4c5 = 0;
    int p5c1 = 0, p5c2 = 0, p5c3 = 0, p5c4 = 0, p5c5 = 0;

    ptr = fopen("votecount.txt", "r"); // File Open
    // check file pointer NULL
    if (ptr == NULL)
    {
        printf("File Not Found");
        return;
    }
    while (fgets(votecount, sizeof(votecount), ptr) != NULL)
    {
        // Remove newline if present
        votecount[strcspn(votecount, "\n")] = '\0';

        if (strcmp(votecount, ca1p1) == 0)
        {
            p1c1 += 1;
        }
        else if (strcmp(votecount, ca2p1) == 0)
        {
            p1c2 += 1;
        }
        else if (strcmp(votecount, ca3p1) == 0)
        {
            p1c3 += 1;
        }
        else if (strcmp(votecount, ca4p1) == 0)
        {
            p1c4 += 1;
        }
        else if (strcmp(votecount, ca5p1) == 0)
        {
            p1c5 += 1;
        }
        else if (strcmp(votecount, ca1p2) == 0)
        {
            p2c1 += 1;
        }
        else if (strcmp(votecount, ca2p2) == 0)
        {
            p2c2 += 1;
        }
        else if (strcmp(votecount, ca3p2) == 0)
        {
            p2c3 += 1;
        }
        else if (strcmp(votecount, ca4p2) == 0)
        {
            p2c4 += 1;
        }
        else if (strcmp(votecount, ca5p2) == 0)
        {
            p2c5 += 1;
        }
        else if (strcmp(votecount, ca1p3) == 0)
        {
            p3c1 += 1;
        }
        else if (strcmp(votecount, ca2p3) == 0)
        {
            p3c2 += 1;
        }
        else if (strcmp(votecount, ca3p3) == 0)
        {
            p3c3 += 1;
        }
        else if (strcmp(votecount, ca4p3) == 0)
        {
            p3c4 += 1;
        }
        else if (strcmp(votecount, ca5p3) == 0)
        {
            p3c5 += 1;
        }
        else if (strcmp(votecount, ca1p4) == 0)
        {
            p4c1 += 1;
        }
        else if (strcmp(votecount, ca2p4) == 0)
        {
            p4c2 += 1;
        }
        else if (strcmp(votecount, ca3p4) == 0)
        {
            p4c3 += 1;
        }
        else if (strcmp(votecount, ca4p4) == 0)
        {
            p4c4 += 1;
        }
        else if (strcmp(votecount, ca5p4) == 0)
        {
            p4c5 += 1;
        }
        else if (strcmp(votecount, ca1p5) == 0)
        {
            p5c1 += 1;
        }
        else if (strcmp(votecount, ca2p5) == 0)
        {
            p5c2 += 1;
        }
        else if (strcmp(votecount, ca3p5) == 0)
        {
            p5c3 += 1;
        }
        else if (strcmp(votecount, ca4p5) == 0)
        {
            p5c4 += 1;
        }
        else if (strcmp(votecount, ca5p5) == 0)
        {
            p5c5 += 1;
        }
    }
    fclose(ptr);

    printf("--|Party 1 Vote Count|--\n");
    printf("candidate 1 of party 1:%d\n", p1c1);
    printf("candidate 2 of party 1:%d\n", p1c2);
    printf("candidate 3 of party 1:%d\n", p1c3);
    printf("candidate 4 of party 1:%d\n", p1c4);
    printf("candidate 5 of party 1:%d\n\n", p1c5);

    printf("--|Party 2 Vote Count|--\n");
    printf("candidate 1 of party 2:%d\n", p2c1);
    printf("candidate 2 of party 2:%d\n", p2c2);
    printf("candidate 3 of party 2:%d\n", p2c3);
    printf("candidate 4 of party 2:%d\n", p2c4);
    printf("candidate 5 of party 2:%d\n\n", p2c5);

    printf("--|Party 3 Vote Count|--\n");
    printf("candidate 1 of party 3:%d\n", p3c1);
    printf("candidate 2 of party 3:%d\n", p3c2);
    printf("candidate 3 of party 3:%d\n", p3c3);
    printf("candidate 4 of party 3:%d\n", p3c4);
    printf("candidate 5 of party 3:%d\n\n", p3c5);

    printf("--|Party 4 Vote Count|--\n");
    printf("candidate 1 of party 4:%d\n", p4c1);
    printf("candidate 2 of party 4:%d\n", p4c2);
    printf("candidate 3 of party 4:%d\n", p4c3);
    printf("candidate 4 of party 4:%d\n", p4c4);
    printf("candidate 5 of party 4:%d\n\n", p4c5);

    printf("--|Party 5 Vote Count|--\n");
    printf("candidate 1 of party 5:%d\n", p5c1);
    printf("candidate 2 of party 5:%d\n", p5c2);
    printf("candidate 3 of party 5:%d\n", p5c3);
    printf("candidate 4 of party 5:%d\n", p5c4);
    printf("candidate 5 of party 5:%d\n", p5c5);
}