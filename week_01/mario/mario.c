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

    for (int i = 1; i < height+1; i++){
        for (int j = height; j > i; j--){
            printf(" ");
        }
        for (int left = 1; left < i+1; left++){
            printf("#");
        }
        printf("  ");
        for (int right = 1; right < i+1; right ++){
            printf("#");        
        }
        printf("\n");
    }
}