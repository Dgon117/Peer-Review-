#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMBER_CHOICES 25
#define CHOICE_lENGTH 25


main(void)
//struct Names
{
    int pick = 1;
   union Data{
       int i;
       int e; };
    // need to put bellow arrays into a text file and have program work the same
    // read into files, and never need to recompile
    char Vowel[NUMBER_CHOICES][CHOICE_lENGTH];

    // Mix words
    char Vowel2[NUMBER_CHOICES][CHOICE_lENGTH];

    // Adds letter in front of word

    FILE *fp;
    fp = fopen("Vowel.txt","r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        return -1;
    }
    char buffer[CHOICE_lENGTH];
    // Looping each line of file
    for (int i = 0; i < NUMBER_CHOICES;i++)
    {
        // gets contents
        fgets(buffer,sizeof(buffer),fp);
        // strip new line at the end
        buffer[strcspn(buffer, "\n")] = 0;
        // Copy buffer into vowel array
        strncpy(Vowel[i], buffer, CHOICE_lENGTH);
    }
    fclose(fp);

    fp = fopen("Vowel2.txt","r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        return -1;
    }
    // Looping each line of file
    for (int i = 0; i < NUMBER_CHOICES;i++)
    {
        // gets contents
        fgets(buffer,sizeof(buffer),fp);
        // strip new line at the end
        buffer[strcspn(buffer, "\n")] = 0;
        // Copy buffer into vowel array
        strncpy(Vowel2[i], buffer, CHOICE_lENGTH);
    }
    fclose(fp);

// Struct with file pointers, put input points vowel and letter and output pointers all file IO struct
    FILE *myfile;
    myfile = fopen("output.txt", "w");
    if(myfile==NULL)
    {
        printf("error in opening file");
        return 1;
        exit(1);
    }

    // Showing Names to be combined
    union Data d1;
    d1.i = 10;
    d1.e = 20;
    printf("%d\n", d1.i);
    printf("%d", d1.e);

    printf("NameComplier\n");
    // assigned variable
    for (int i = 0; i < 25; i++)
        printf("%s\n", Vowel[i]);
    printf("\n");
    // loop adds names together
    while (pick == 1) {
        //Random Name Listed
        printf("Randome Name \n");
        srand(time(0));

        //Combined 2 names to make 1
        ////// writing in file
        // could have struct for bottom hash
        char randomletter = 'A' + (rand() % 26);
        fprintf(myfile,"%c\n", randomletter);
        fprintf(myfile,"%s\n", Vowel[rand() % 10]);
        fprintf(myfile,"%s\n", Vowel[rand() % 10]);
        fprintf(myfile,"%s\n", Vowel2[rand() % 10]);
        fprintf(myfile,"%s\n", Vowel2[rand() % 10]);
        printf("File written successfully");
        // Generate another name
        printf("\nYou want to generate another name(1: yes, 2: no): ");
        scanf("%d", &pick);
    }
    fclose(myfile);
    return 0;
}
