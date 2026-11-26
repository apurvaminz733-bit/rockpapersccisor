#include <stdio.h>
#include <stdlib.h>   // rand(), srand()
#include <time.h>     // time()

// Turns a number (1, 2, 3) into its name
const char *choiceName(int choice) {
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    return "Scissors";
}

int main(void) {
    int user, computer, result;
    int userScore = 0, computerScore = 0;

    // Seed the random generator so the computer plays differently each run
    srand(time(NULL));

    printf("=== ROCK PAPER SCISSORS ===\n");

    while (1) {
        printf("\n1. Rock\n2. Paper\n3. Scissors\n0. Quit\n");
        printf("Enter your choice: ");

        result = scanf("%d", &user);

        if (result == EOF) {
            break;                      // no more input
        }
        if (result != 1) {
            user = -1;                  // the user typed something that is not a number
        }

        // Throw away anything left on the line
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        if (user == 0) {
            break;
        }
        if (user < 1 || user > 3) {
            printf("Invalid choice! Please enter 0, 1, 2 or 3.\n");
            continue;
        }

        computer = rand() % 3 + 1;      // random number from 1 to 3

        printf("You chose: %s\n", choiceName(user));
        printf("Computer chose: %s\n", choiceName(computer));

        if (user == computer) {
            printf("It's a draw!\n");
        } else if ((user == 1 && computer == 3) ||
                   (user == 2 && computer == 1) ||
                   (user == 3 && computer == 2)) {
            printf("You win!\n");
            userScore++;
        } else {
            printf("Computer wins!\n");
            computerScore++;
        }

        printf("Score -> You: %d | Computer: %d\n", userScore, computerScore);
    }

    printf("\nFinal score -> You: %d | Computer: %d\n", userScore, computerScore);
    printf("Thanks for playing!\n");

    return 0;
}