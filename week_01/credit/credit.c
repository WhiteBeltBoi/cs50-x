#include <stdio.h>
int card_sum(long);
char *card_type(long);
int digit_checker(long);

int main(void) {
    long card_number;
    printf("Number: ");
    scanf("%ld",&card_number);

    if (card_sum(card_number)){
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
    return digit_sum % 10;

}

int digit_checker(long n){
    int digits = 0;
    while (n > 0){
        n /= 10;
        digits += 1;
    }
    return digits;
}

char *card_type(long n){
        while (n > 100){
            n/=10;
        }
        if(n == 34 || n ==37){
            if (digit_checker(n) ==15){
                return "AMEX";
            }
            else{
                return "INVALID";
            }
        
        }
        else if (n >= 51 && n <= 55){
            if (digit_checker(n) ==16){
                return "MASTERCARD";
            }
            else{
                return "INVALID";
            }
        }
        else if (n/10 == 4){
            if (digit_checker(n) ==13 || digit_checker(n) == 16){
                return "VISA";
            }
            else{
                return "INVALID";
            }
        }
        else{
            return "INVALID";
        }
    }