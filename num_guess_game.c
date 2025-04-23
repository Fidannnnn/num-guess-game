/*-----------------------Number Guessing Game--------------------*/
/*Team members: Asiman Ismayilova, Fidan Alizada, Gunay Ashrafova, Madina Jafarzade*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void computer_is_guessing(void);
void user_is_guessing(void);
int random_number(int low, int high);

int main()
{
    //  welcome message 
    printf("Welcome to Number Guessing Game !\n");
    printf("-----------------------------------\n");

    // Declare and initialize variable to store user choice
    char player;

    // Declare and initialize variable to store user's response to play again
    char reply;

    // Game loop to allow user to play multiple times
    do
    {
        // Prompt user to choose who is guessing (computer or user)
        printf("\nWho is guessing? For computer enter c, for user enter u: ");
        scanf(" %c", &player);

        // Validate user input
        while (player != 'c' && player != 'u') 
        {
            // Print error message and prompt user to enter valid input
            printf("Invalid input. Please try again (c/u): ");
            scanf(" %c", &player);
        }

        // Call function based on user's choice
        if (player == 'c') 
        {
            computer_is_guessing();
        } 
        else 
        {
            user_is_guessing();
        }

        // Prompt user to play again
        printf("\nDo you want to play again?(y/n): ");
        scanf(" %c", &reply);
    } while (reply == 'y' || reply == 'Y');

    return 0;
}

// Generates a random number between the given range and returns it
int random_number(int low, int high)
{
    // Seed the random number generator using the current time
    srand(time(NULL));

    // Calculate and return a random number within the given range
    int num = rand() % (high - low + 1) + low;
    return num;
}

// Function which deals with computer guessing part
void computer_is_guessing(void)
{
    // Print game rules for computer guessing
    printf("\n******************\n");
    printf("\nRule: s-means smaller than the number, b-means bigger than the number, f-means found\n");
    printf("\n******************\n");

    // Declare and initialize variable to store number of attempts
    int tries = 0;

    // Declare and initialize variable to store user's number
    int user_num;

    // Prompt user to enter a number between 1 and 999
    printf("Enter a number between 1 and 999 that you want computer to guess: ");
    scanf("%d", &user_num);

    // Validate user input
    while (user_num < 1 || user_num > 999)
    {
        // Print error message and prompt user to enter valid input
        printf("Input is not valid ! Try again: ");
        scanf("%d", &user_num);
    }

    // Declare and initialize variable to store computer's guess
    int comp_guess;

    // Initialize upper and lower bounds of range
    int small_border = 1;
    int big_border = 999;

    // Loop until computer finds user's number
    do 
    {
        // Calculate the middle of the search range for decreasing attempts
        comp_guess = (small_border + big_border) / 2;

        // Print computer's guess
        printf("\nComputer guess: %d", comp_guess);

        // Increment number of attempts
        tries++;

        // Declare and initialize variable to store user's response
        char answer;

        // Prompt user to respond with 's', 'b', or 'f'
        printf("\nIs this your number? enter 's', 'b', 'f': ");
        scanf(" %c", &answer);

        // Handle user's response
        if (small_border == big_border) 
        {
            // Print error message if user gave wrong prompts
            printf("You gave wrong prompt about whether num is small, or big. You lied!");
            break;
        }

        if (answer == 'g' || answer == 'G')
        {
            if (user_num == comp_guess)
            {
                printf("Your last input is wrong. Number is found. Game over!");
                break;
            }

            // Update the upper bound of the range
            big_border = comp_guess;
        }
        else if (answer == 's' || answer == 'S')
        {
            if (user_num == comp_guess)
            {
                printf("Your last input is wrong. Number is found. Game over!");
                break;
            }

            // Update the lower bound of the range
            small_border = comp_guess;
        }

        else if (answer == 'f')
        {
            if (comp_guess != user_num)
            {
                printf("This is not user guess. You lied. ");
                break;
            }

            //Exit the loop if user's number is found
            break;
        }

        else
        {
            printf("Invalid input. Try again.");
        }

    } while (1);

    // Print final message
    printf("\nComputer found the number in %d attempts.", tries);
}

// Function which deals with user guessing part
void user_is_guessing(void)
{
    // Print game rules for user guessing
    printf("\n******************\n");
    printf("\nRule: s-means smaller than the number, b-means bigger than the number, f-means found\n");
    printf("\n******************\n");

    // Declare and initialize variable to store computer's number
    int comp_num = random_number(1, 999);

    // Declare and initialize variable to store number of attempts
    int tries = 0;

    // Declare and initialize variable to store user's guess
    int user_guess;

    // Loop until user finds the computer's number
            do
            {
                // Print prompt for user to enter a guess
                printf("\nYou have to guess a number between 1 and 999: ");
                scanf("%d", &user_guess);

                // Increment number of attempts
                tries++;

                // Handle user's guess
                if (user_guess < comp_num)
                {
                    // Print message if user's guess is smaller than computer's number
                    printf("Your guess is smaller than the number.\n");
                }
                else if (user_guess > comp_num)
                {
                    // Print message if user's guess is bigger than computer's number
                    printf("Your guess is bigger than the number.\n");
                }
                else
                {
                    // Exit the loop if user's guess is equal to computer's number
                    break;
                }
            } while (1);

    // Print final message
    printf("\nYou found the number in %d attempts.", tries);
}
