//
//  main.h
//  HangMan V2
//
//  Created by Aya Ait on 6/27/20.
//  Copyright © 2020 Aya Ait. All rights reserved.
//

#ifndef main_h
#define main_h
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void cryptWord(char* word,char *wordCrypted);
char inputLetters(void);
int testInputLetters(char letter,char* word, char* crypted);
void loadWord(char *word);
int nbRandom(int nombreMax);
void hangManDraw(int attempts);
void mainGame(int mode);
void menu(void);
#endif /* main_h */
