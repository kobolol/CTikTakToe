#include <stdio.h>
static void boolQuestion(bool* pBool, char* question);
static char charQuestion(char* question);

int main() {
    bool endGame = false;

    while (!endGame) {
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

static char charQuestion(char* question) {

}