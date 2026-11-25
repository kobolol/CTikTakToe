#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_FIELD_SIZE 8
#define MIN_FIELD_SIZE 3

typedef enum {
    LEER = 0,
    SPIELER_X = 1,
    SPIELER_O = 2
} FeldZustand;

static void boolQuestion(bool* pBool, char* question);
static int intQuestion(char* question, int includedMin, int includedMax);
static void greetings(char* gameName);
static void mainLoop(FeldZustand* gameField, int height, int width);

int main() {
    bool endGame = false;
    FeldZustand* pGameField;

    // Game Loop
    while (!endGame) {
        greetings("Tik Tak Toe");

        int height = intQuestion("Spielfeldhoehe", MIN_FIELD_SIZE, MAX_FIELD_SIZE);
        int width = intQuestion("Spielfeldbreite", MIN_FIELD_SIZE, MAX_FIELD_SIZE);

        pGameField = calloc(height * width, sizeof(FeldZustand));
        if (pGameField == NULL) {
            return 20;
        }

        mainLoop(pGameField, height, width);
        
        //free(pGameField);
        boolQuestion(&endGame, "Willst du das Spiel beenden?");
    }
}


static void mainLoop(FeldZustand* gameField, int height, int width) {

}

static void boolQuestion(bool* pBool, char* question) {
    char input;
    do {
        printf("%s (Y / N): ", question);
        scanf(" %c", &input);
    } while (input != 'Y' && input != 'N');

    if (input == 'Y') {
        *pBool = true;
    }
}

static int intQuestion(char* question, int includedMin, int includedMax) {
    int input;

    do {
        printf("%s (Muss innerhalb von %d und %d liegen): ", question, includedMin, includedMax);
    } while (scanf(" %d", &input) != 1 || input < includedMin || input > includedMax);

    return input;
}

static void greetings(char* gameName) {
    printf("\033[2J\033[H");

    printf("------- %s -------\n", gameName);
}