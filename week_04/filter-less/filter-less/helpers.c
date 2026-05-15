#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int sum = 0;
            sum += image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            int average = round(sum/3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int sepiaRed = round(0.393 * image[i][j].rgbtRed) + round(0.769 * image[i][j].rgbtGreen) + round(0.189 * image[i][j].rgbtBlue);
            if(sepiaRed > 255){
                sepiaRed = 255;
            }

            int sepiaGreen = round(0.349 * image[i][j].rgbtRed) + round(0.686 * image[i][j].rgbtGreen) + round(0.168 * image[i][j].rgbtBlue);
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }

            int sepiaBlue  = round(0.272 * image[i][j].rgbtRed) + round(0.534 * image[i][j].rgbtGreen) + round(0.131 * image[i][j].rgbtBlue);
            if(sepiaBlue  > 255){
                sepiaBlue  = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
for(int i = 0; i < height; i++){
    for (int j = 0; j< (width)/2; j++){
        RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width -(j+1)];
            image[i][width - (j+1)] = temp;

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            float counter = 0;
            for(int h = -1; h <=1; h++){
                if (i-h >= 0 && i+h < height){
                    for (int w = 1; w <=1; w++){
                        if (j-1 >=0 && j+w < width){
                            sum_red+= copy[i+h][j+w].rgbtRed;
                            sum_green += copy[i+h][j+w].rgbtGreen;
                            sum_blue+= copy[i+h][j+w].rgbtBlue;
                            counter+=1;


                        }
                    }

                }
            }
            sum_red = round(sum_red/counter);
            sum_green = round(sum_green/counter);
            sum_blue = round(sum_blue/counter);
            image[i][j].rgbtRed = sum_red;
            image[i][j].rgbtGreen = sum_green;
            image[i][j].rgbtBlue = sum_blue;


        }
    }


}
