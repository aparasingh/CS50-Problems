#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            double average =
                round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Convert to red, blue and green sepia value
            double sepiaRed =
                round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) +
                      (0.189 * image[i][j].rgbtBlue));
            double sepiaGreen =
                round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) +
                      (0.168 * image[i][j].rgbtBlue));
            double sepiaBlue =
                round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) +
                      (0.131 * image[i][j].rgbtBlue));
            // Update original pixel values
            if (sepiaRed > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = sepiaRed;
            if (sepiaBlue > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = sepiaBlue;
            if (sepiaGreen > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width / 2.0); j++)
        {
            // Swap pixels
            RGBTRIPLE tempPixel = image[i][j];
            int mirrorY = width - 1 - j;
            image[i][j] = image[i][mirrorY];
            image[i][mirrorY] = tempPixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
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
        int aboveRow = i - 1;
        int belowRow = i + 1;
        for (int j = 0; j < width; j++)
        {
            int leftCol = j - 1;
            int rightCol = j + 1;
            double sumRed = copy[i][j].rgbtRed;
            double sumGreen = copy[i][j].rgbtGreen;
            double sumBlue = copy[i][j].rgbtBlue;
            int count = 1;
            // Above Row
            if (aboveRow >= 0)
            {
                sumRed += copy[aboveRow][j].rgbtRed;
                sumBlue += copy[aboveRow][j].rgbtBlue;
                sumGreen += copy[aboveRow][j].rgbtGreen;
                count++;
                if (leftCol >= 0)
                {
                    sumRed += copy[aboveRow][leftCol].rgbtRed;
                    sumBlue += copy[aboveRow][leftCol].rgbtBlue;
                    sumGreen += copy[aboveRow][leftCol].rgbtGreen;
                    count++;
                }
                if (rightCol < width)
                {
                    sumRed += copy[aboveRow][rightCol].rgbtRed;
                    sumBlue += copy[aboveRow][rightCol].rgbtBlue;
                    sumGreen += copy[aboveRow][rightCol].rgbtGreen;
                    count++;
                }
            }
            // Current Row
            if (leftCol >= 0)
            {
                sumRed += copy[i][leftCol].rgbtRed;
                sumBlue += copy[i][leftCol].rgbtBlue;
                sumGreen += copy[i][leftCol].rgbtGreen;
                count++;
            }
            if (rightCol < width)
            {
                sumRed += copy[i][rightCol].rgbtRed;
                sumBlue += copy[i][rightCol].rgbtBlue;
                sumGreen += copy[i][rightCol].rgbtGreen;
                count++;
            }
            // Below Row
            if (belowRow < height)
            {
                sumRed += copy[belowRow][j].rgbtRed;
                sumBlue += copy[belowRow][j].rgbtBlue;
                sumGreen += copy[belowRow][j].rgbtGreen;
                count++;
                if (leftCol >= 0)
                {
                    sumRed += copy[belowRow][leftCol].rgbtRed;
                    sumBlue += copy[belowRow][leftCol].rgbtBlue;
                    sumGreen += copy[belowRow][leftCol].rgbtGreen;
                    count++;
                }
                if (rightCol < width)
                {
                    sumRed += copy[belowRow][rightCol].rgbtRed;
                    sumBlue += copy[belowRow][rightCol].rgbtBlue;
                    sumGreen += copy[belowRow][rightCol].rgbtGreen;
                    count++;
                }
            }
            image[i][j].rgbtRed = round(sumRed / (float) count);
            image[i][j].rgbtBlue = round(sumBlue / (float) count);
            image[i][j].rgbtGreen = round(sumGreen / (float) count);
        }
    }
    return;
}
