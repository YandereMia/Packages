#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomRange(int min, int max);
int main(void) {
    printf("Random Motivational Quote of the Terminal Startup\n");
    srand( (unsigned int)time ( NULL ) );
    const int size = 20;
    char *msgs[] = {"Do small things with great love.", "Mistakes are proof that you are trying.", "Progress, not perfection.", "Dream big, start small.", "You are capable of amazing things.", "The best time to start was yesterday. The next best time is now.",\
        "Stay humble, work hard, be kind.", "Believe you can and youre halfway there.", "Focus on what you can control.", "Small steps every day lead to big results.", "Dont watch the clock; do what it does—keep going.",\
        "Challenges are what make life interesting.", "Success is the sum of small efforts repeated daily.", "Your only limit is your mind.", "Push yourself, because no one else is going to do it for you.", "Fall seven times, stand up eight.",\
        "Keep going. Everything you need will come to you at the perfect time.", "Dont be afraid to start over. Its a chance to rebuild stronger.", "Hard work beats talent when talent doesnt work hard.", "Be stronger than your strongest excuse."};
        printf("%s\n", msgs[randomRange(0, size - 1)]);
}

int randomRange(int min, int max)
{
    return ( rand() % ( max - min + 1 ) ) + min;
}