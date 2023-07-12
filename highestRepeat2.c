#include <stdio.h>
#include<string.h>

// max occured alphabet in a sentence
int main()
{
    char str[100];
    int freq[255]={0}; 
    int i = 0, max=0;
    int ascii;

    printf("Enter any string: ");
    gets(str);

    // Finds frequency of each characters 
    
    while(str[i] != '\0')
    {
        ascii = (int)str[i];
        freq[ascii]++;
        i++;
    }


    //Finds maximum frequency 
    
    for(i=0; i<255; i++)
    {
        if(freq[i] > freq[max])
            max = i;
    }


    printf("Maximum occurring character is '%c' = %d times.", max, freq[max]);

    return 0;
}