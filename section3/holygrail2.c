#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // open file "party.txt" in append mode
    FILE* out = fopen("party.txt", "a");

        // always make sure fopen() doesn't return NULL!
    if(out == NULL)
    {
        return 1;
    }

    string name = get_string("What is your name?\n");
    string quest = get_string("What is your quest?\n");
    string answer = get_string("What is the air-speed velocity of an unladen swallow?\n");

    // write answers to output file
    fprintf(out, "Name: %s, Quest: %s, Answer: %s\n", name, quest, answer);

    // close files to avoid memory leaks!
    fclose(out);
}