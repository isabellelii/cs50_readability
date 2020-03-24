#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

// variables to set initial value for counts
    int countletters = 0;
    int countwords = 1;
    int countsentence = 0;

// output string to user
    string textinput = get_string("Text: ");

// calculate count for words, letters and sentences of the text input
    for (int i = 0; i < strlen(textinput); i++)
    {
        if ((textinput[i] >= 'a' && textinput[i] <= 'z') || (textinput[i] >= 'A' && textinput[i] <= 'Z'))
        {
            countletters++;
        }
        else if (textinput[i] == ' ')
        {
            countwords++;
        }
        else if (textinput[i] == '.' || textinput[i] == '?' || textinput[i] == '!')
        {
            countsentence++;
        }
    }

// calcutare the grade of the text input
    float grade = 0.0588 * (100 * (float) countletters / (float) countwords) - 0.296 * (100 * (float) countsentence /
                  (float) countwords) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}
