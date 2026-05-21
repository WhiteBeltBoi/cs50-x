#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
 
int main(int argc, char *argv[])
{
    if (argc !=2){
        printf("Usage: ./recover filename\n");
        return 1;
    }

    FILE *data = fopen(argv[1], "r");
    if (data == NULL){
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    uint8_t signature[512];

    while(fread(signature,512,1,data)==1);

}