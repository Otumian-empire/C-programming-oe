#include <ctype.h>
#include "../../cs50.h"
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }

    printf("\n");
}

int compute_score(string word)
{
    // Compute and return score for string
    int score = 0;
    const int A_VAL = 65, Z_VAL = 82;

    for (int i = 0; i < strlen(word); i++)
    {
        int cint_val = toupper(word[i]);

        if (A_VAL <= cint_val && cint_val <= Z_VAL)
        {
            score += POINTS[cint_val - A_VAL];
        }
    }

    return score;
}
