#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);

int main(void)
{
    // Get input word from user
    string str_1 = get_string("Player1: ");
    string str_2 = get_string("Player2: ");
    int score_1 = compute_score(str_1);
    int score_2 = compute_score(str_2);
    
    if (score_1 > score_2){
        printf("Player 1 wins!\n");
    }
    else if (score_2 > score_1){
        printf("Player 2 wins!\n");
    }
    else{
        printf("Tie!\n");
    }
}

int compute_score(string word){
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++){
        char letter = toupper(word[i]);
        if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P' ){
            sum+= 3;

        }
        else if (letter == 'D' || letter == 'G'){
            sum += 2;
        }
        else if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter =='Y'){
            sum+= 4;
        }
        else if (letter == 'K'){
            sum+= 5;
        }
        else if(letter == 'J' || letter == 'X'){
            sum += 8;
        }
        else if (letter == 'Q' || letter == 'Z'){
            sum += 10;
        }
        else if (isalpha(letter)){
            sum += 1;
        }
    }
    return sum;
}