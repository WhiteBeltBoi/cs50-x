#include <stdio.h>
int card_sum(long);
char *card_type(long);

int main(void) {
    long card_number;
    printf("Number: ");
    scanf("%ld",&card_number);

    int my_sum = card_sum(card_number);
    
    if (my_sum % 10 == 0){
        char *str = card_type(card_number);
        printf("%s\n", str);

    }
    else{
        printf("INVALID\n");
    }

   

}   
int card_sum(long n){
    int digit_sum = 0;
    while (n > 0){
        int last = n % 10;
        digit_sum += n % 10;
        n /= 10;
        int second_last = (n % 10) *2 ;
        if (second_last > 10){
            int temp = second_last % 10;
            temp += (second_last /10) % 10;
            second_last = temp;
        }
        digit_sum += second_last;
        n /= 10;
    }
    return digit_sum;
    
}

char *card_type(long n){
        while (n > 10){
            n/=10;
        }
        int first_digit = n % 10;
        if (first_digit == 4){
            return "Visa";
        }
        else if(first_digit == 3){
            return "American Express";
        }
        else if(first_digit == 5){
            return "MasterCard";
        }
        else{
            return "INVALID";
        }
    }