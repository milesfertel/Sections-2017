// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

#define BASEDUR 8
#define A4_FREQ 440

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    return numerator * BASEDUR / denominator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char n[3];
    int octave = 0;
    if (strlen(note) == 2)
    {
        n[0] = note[0];
        n[1] = '\0';
        octave = note[1] - '0';
    }
    else if (strlen(note) == 3)
    {
        n[0] = note[0];
        n[1] = note[1];
        n[2] = '\0';
        octave = note[2] - '0';
    }
    // Invalid input
    else
    {
        return 0;
    }

    // Determine how many semitones away to move
    int semitones = 0;
    switch (toupper((unsigned char) n[0]))
    {
        case 'A':
            break;
        case 'B':
            semitones = 2;
            break;
        case 'C':
            semitones = -9;
            break;
        case 'D':
            semitones = -7;
            break;
        case 'E':
            semitones = -5;
            break;
        case 'F':
            semitones = -4;
            break;
        case 'G':
            semitones = -2;
            break;
        // Invalid input
        default:
            return 0;
    }

    // Adjust for sharps and flats
    if (n[1] == '#')
    {
        semitones++;
    }
    else if (n[1] == 'b')
    {
        semitones--;
    }

    // Adds or subtracts an octave's worth of semitones for octave distance
    semitones += (octave - 4) * 12;

    // Compute the final frequency
    return round(A4_FREQ * pow(2.0, semitones / 12.0));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    return false;
}