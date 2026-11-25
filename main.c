#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static void boolQuestion(bool* pBool, char* question);
static int intQuestion(char* question);
static void greetings(char* gameName);
static void mainLoop(bool* gameField);

int main() {
    bool endGame = false;
    static bool gameField[3][3];
    memset(gameField, 0, sizeof(gameField));

    // Game Loop
    while (!endGame) {
        greetings("Tik Tak Toe");



        boolQuestion(&endGame, "Willst du das Spiel beenden?");
    }
}

static void boolQuestion(bool* pBool, char* question) {
    char input;
    do {
        printf("%s (Y / N)\n", question);
        scanf(" %c", &input);
    } while (input != 'Y' && input != 'N');

    if (input == 'Y') {
        *pBool = true;
    }
}

static int intQuestion(char* question) {
    int input;

    do {
        printf("%s: ", question);
    } while (scanf(" %s", &input) != 1);

    return input;
}

static void greetings(char* gameName) {
    printf("\033[2J\033[H");

    printf("------- %s -------\n", gameName);
}

static void mainLoop(bool* gameField) {

}