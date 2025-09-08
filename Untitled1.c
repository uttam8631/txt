#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    int cl;
    int eng, nep, sci;
    int tot;
    float per;
}s[200];

int main()
{
    int i, n;
    FILE *fp;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i+1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);  // full name with spaces

        printf("Class: ");
        scanf("%d", &s[i].cl);

        // Asking marks separately
        printf("Enter the marks of English: ");
        scanf("%d", &s[i].eng);

        printf("Enter the marks of Nepali: ");
        scanf("%d", &s[i].nep);

        printf("Enter the marks of Science: ");
        scanf("%d", &s[i].sci);

        s[i].tot = s[i].eng + s[i].nep + s[i].sci;
        s[i].per = s[i].tot / 3.0;
    }

    // Print to console
    printf("\nRoll\tName\t\tClass\tEng\tNep\tSci\tTotal\tPercent\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%-15s\t%d\t%d\t%d\t%d\t%d\t%.2f\n",
               s[i].roll, s[i].name, s[i].cl,
               s[i].eng, s[i].nep, s[i].sci,
               s[i].tot, s[i].per);
    }
    printf("---------------------------------------------------------------------------------------------\n");
    // Save to file
    fp = fopen("students.txt", "w");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
     fprintf(fp, "---------------------------------------------------------------------------------\n");
    fprintf(fp, "Roll\tName\t\tClass\tEng\tNep\tSci\tTotal\tPercent\n");
     fprintf(fp, "---------------------------------------------------------------------------------\n");
    for(i = 0; i < n; i++)
    {
        fprintf(fp, "%d\t%-15s\t%d\t%d\t%d\t%d\t%d\t%.2f\n",
                s[i].roll, s[i].name, s[i].cl,
                s[i].eng, s[i].nep, s[i].sci,
                s[i].tot, s[i].per);
                 fprintf(fp, "---------------------------------------------------------------------------------\n");
    }

    fclose(fp);
    printf("\nStudent details saved to students.txt\n");
    return 0;
}
