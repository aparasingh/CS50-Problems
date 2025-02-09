#include <cs50.h>
#include <stdio.h>

void print_wall(int num_bricks);
void print_spaces(int leading_spaces);
int main(void)
{
    // Get wall height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // Need to create two walls
    int walls = 2;
    for (int i = 1; i <= height; i++)
    {
        // For Rows
        for (int wall_counter = 0; wall_counter < walls; wall_counter++)
        {
            // While loop to create two walls and difference to get the spacing
            int leading_spaces = height - i;
            if (wall_counter == 0)
            {
                // Left wall
                print_spaces(leading_spaces);
                print_wall(i);
                printf("  ");
            }
            else
            {
                // right wall
                print_wall(i);
            }
        }
        printf("\n");
    }
}

void print_wall(int num_bricks)
{
    for (int i = 0; i < num_bricks; i++)
    {
        printf("#");
    }
}

void print_spaces(int leading_spaces)
{
    for (int j = 0; j < leading_spaces; j++)
    {
        printf(" ");
    }
}