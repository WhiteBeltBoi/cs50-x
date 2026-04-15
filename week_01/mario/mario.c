#include <stdio.h>

int main(void){
    int height;
    while (1){
        printf("Height: ");
        scanf("%d", &height);
        if (height >0 && height <9){
            break;
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = height; j >= i; j--){
            printf(" ");
        }
        for (int left = 0; left <= i; left++){
            printf("#");
        }
        printf("  ");
        for (int right = 0; right <= i; right ++){
            printf("#");        
        }
        printf("\n");
    }
}