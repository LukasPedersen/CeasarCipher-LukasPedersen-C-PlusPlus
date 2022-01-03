#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

#define ALPHABETICALMAXVAL 26

void encrypt();
void decrypt();

int main(int numArgs, char* args[])
{
    string mode = args[1];
    string plainText = args[2];
    int shiftvalue = atoi(args[3]);

    char encryptedText[strlen(plainText)];
    char decryptedText[strlen(plainText)];

    if(numArgs == 4 && !strcmp(mode, "encrypt")) //Encrypt message
    {
        encrypt(plainText, encryptedText, shiftvalue);
        printf("%s\n", encryptedText);
    }
    else if(numArgs == 4 && !strcmp(mode, "decrypt")) //Decrypt message
    {
        decrypt(plainText, decryptedText, shiftvalue);
        printf("%s\n", decryptedText);
    }
    else
    {
        printf("Invalid command please input the command in the following format: CeasarCipher encrypt/decrypt message(string) shiftvalue(int)\n");
    }

    return 0;
}

void encrypt(string messageIn, char encryptedText[], int shiftValue)
{
    for(int i = 0; i < strlen(messageIn); i++)
    {
        if(messageIn[i] >= 'a' && messageIn[i] <= 'z')
        {
            encryptedText[i] = (((messageIn[i] - 'a') + shiftValue) % ALPHABETICALMAXVAL) + 'a';
        }
        else if(messageIn[i] >= 'A' && messageIn[i] <= 'Z')
        {
            encryptedText[i] = (((messageIn[i] - 'A') + shiftValue) % ALPHABETICALMAXVAL) + 'A';
        }
        else
        {
            encryptedText[i] = messageIn[i];
        }
    }
}

void decrypt(string messageIn, char decryptedText[], int shiftValue)
{
    for(int i = 0; i < strlen(messageIn); i++)
    {
        if(messageIn[i] >= 'a' && messageIn[i] <= 'z')
        {
            decryptedText[i] = (((messageIn[i] - 'a') - shiftValue + ALPHABETICALMAXVAL) % ALPHABETICALMAXVAL) + 'a';
        }
        else if(messageIn[i] >= 'A' && messageIn[i] <= 'Z')
        {
            decryptedText[i] = (((messageIn[i] - 'A') - shiftValue + ALPHABETICALMAXVAL) % ALPHABETICALMAXVAL) + 'A';
        }
        else
        {
            decryptedText[i] = messageIn[i];
        }
    }
}
