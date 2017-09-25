#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    string quest = get_string("What is your quest?\n");
    string answer = get_string("What is the air-speed velocity of an unladen swallow?\n");

    printf("Name: %s, Quest: %s, Answer: %s\n", name, quest, answer);
}