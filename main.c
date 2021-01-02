//
//  main.c
//  HangMan V2
//
//  Created by Aya Ait on 6/27/20.
//  Copyright © 2020 Aya Ait. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    int choice;
    do{
        menu();
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                system("clear");
                mainGame(1);
                break;
            case 2:
                system("clear");
                mainGame(0);
                break;
            case 3: break;
            default:
                printf("\nChoice unknown!");
        }
    }while(choice!=3);
    return 0;
}
void menu(){
    printf("\t*** Hang Man ***\n");
    printf("Can you guess the word before the man gets hanged?\n");
    hangManDraw(0);
    printf("\n1. Single player");
    printf("\n2. Multiplayer");
    printf("\n3. Quit");
    printf("\nWhat do you want to do? : ");
}
void cryptWord(char* word,char *wordCrypted){
    while (*word != '\0'){
        *wordCrypted = '*';
        wordCrypted++;
        word++;
    }
    *wordCrypted='\0';
}
char inputLetters(){
    char character;
    fflush(stdin);
    character=getchar();
    character=toupper(character);
    while(getchar()!='\n');
    return character;
}
int testInputLetters(char letter,char* word, char* crypted){
    int lettersLeft=0;
    while(*word != '\0'){
        if (*word == letter)*crypted = letter;
        else if (*crypted == '*') lettersLeft++;
        word++;
        crypted++;
    }
    return lettersLeft;
}
void loadWord(char *word){
    FILE *fptr = fopen("../HangManV2/WordDictionary.txt", "r");
    if(fptr==NULL) printf("Error : Words dictionary cannot be loaded!\n");
    char ch;
    int numWords=0,randomChoice;
    while ((ch=fgetc(fptr))!=EOF){
        if(ch=='\n') numWords++;
    }
    rewind(fptr);
    randomChoice=nbRandom(numWords);
    while (randomChoice>0) {
        ch = fgetc(fptr);
        if (ch == '\n') randomChoice--;
    }
    fgets(word, 50, fptr);
    word[strlen(word) - 1] = '\0';
    fclose(fptr);
}
int nbRandom(int nombreMax){
    srand((unsigned int)time(NULL));
    return rand()%nombreMax;
}
void hangManDraw(int attempts){
    if(attempts<=9) printf("    ––––––––––––––");
    printf("\n");
    if (attempts<=8) printf("    |           |\n");
    else printf("    |\n");
    if (attempts<=7) printf("    |          ( )\n");
    else printf("    |\n");
    if (attempts<=6) {
        if(attempts<=5){
            if(attempts<=4) printf("    |        ---|---\n");
            else printf("    |        --- ---\n");
        }else{
            printf("    |        ---\n");
        }
    }else printf("    |\n");
    if (attempts<=3) printf("    |           |\n");
    else printf("    |\n");
    if (attempts<=2) printf("    |           |\n");
    else printf("    |\n");
    if(attempts<=1){
        if(attempts==0) printf("    |          / \\n");
        else printf("    |          /  \n");
    }else printf("    |\n");
    printf("    |\n");
    printf("____|_____________\n");
}
void mainGame(int mode){
    int attempts, lettersLeft=0,test;
    char word[50],retry;
    char *wordCrypted = NULL;
    do{
        attempts=10;
        if(mode==1){
            loadWord(word);
        }else{
            int i;
            printf("Player 1 > Enter a word : ");
            fflush(stdin);
            fgets(word, 50, stdin);
            strtok(word, "\n");
            for(i=0;i<strlen(word);i++){
                word[i]=toupper(word[i]);
            }
            system("clear");
        }
        wordCrypted=(char*)malloc(sizeof(char)*strlen(word));
        cryptWord(word,wordCrypted);
        do{
            test=lettersLeft;
            hangManDraw(attempts);
            printf("\n%d attempts left\n",attempts);
            printf("Guess the word : ");
            puts(wordCrypted);
            printf("Input a charactere : ");
            lettersLeft=testInputLetters(inputLetters(),word,wordCrypted);
            if(test==lettersLeft)attempts--;
            system("clear");
        }while (attempts!=0 && lettersLeft!=0);
        hangManDraw(attempts);
        if (lettersLeft==0) printf("\nThe word is %s\nYou win, congratulations!\n",word);
        else if (attempts==0) printf("\nSorry, you're dead!\n");
        free(wordCrypted);
        printf("\nDo you wanna replay? (yes:Y,no:any button)");
        retry=inputLetters();
        system("clear");
    }while(retry=='Y');
}
