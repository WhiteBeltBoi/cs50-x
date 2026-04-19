#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int grader(string);
int main(void){
    string my_sentence = get_string("Type it here: ");
    int index = grader(my_sentence);
    if(index < 1){
        printf("Before Grade 1\n");
    }
    else if (index > 16){
        printf("Grade 16+\n");
    }
    else{
    printf("Grade %i\n", index);
    }
  
  
}
    
int grader(string my_sentence){
    int letter_counter = 0;
    int sentence_counter = 0;
    int word_counter = 0;
    for (int i = 0, n = strlen(my_sentence); i < n; i++){
        if (isalpha(my_sentence[i])){
            letter_counter += 1;
        }
        else if (my_sentence[i] == ' '){
            word_counter += 1;
        }
        else if (my_sentence[i] == '.'|| my_sentence[i] == '!' || my_sentence[i] == '?'){
            sentence_counter += 1;
        }
    }

  float L = ((float) letter_counter / word_counter) * 100;
  float S = ((float) sentence_counter / word_counter) * 100;
  return  (int) round(0.0588 * L - 0.296 * S - 15.8);

}

