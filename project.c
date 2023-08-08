/*
    Title: ENCRYPTION AND DECRYPTION USING CAESAR CIPHER
    Description: This program takes in plane text and 
    Usage : please enter a plain text you want to encrypt: You Are Perfect
            The ciphred text is (key shift is generated randomly lets say 3 ): Brx Duh Shuihfw
            Decrypted text is :You Are Perfect

    How it works:   Suppose letter a=0, b=1, c=2, and so on.
                    key=3
                    ((int)letter + key +26  )mod 26 ==> return the ciphered letter as a number , cipherValue
                                                ==> (char)cipherValue = '[some letter]'
                    display ciphered text

                    for decryption:
                    ((int)letter -key + 26 )mod 26 ==> return the decrypted letter as a number , decryptValue
                                                ==> (char)decryptValue = '[some letter]'
                    display decrypted text                             

*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


void encrypt(char text[], int key );
void decrypt(char text[], int key);
 
 
 //Global variables
 char text[100];
int key;

//main function
void main()
{
    
    
    // Prompt the user to enter a message
    printf("Enter a message to Encrypt:\t");
    
    // Read the message  from the user (stdin refers to standard input i.e. input from keyboard)
    fgets(text, sizeof(text), stdin);
    
    // Getting a non zero random key.
   while(1){ 
       key= rand()%25;
       if(key!=0)
       break;
   }

    // Encrypting the message
    encrypt(text, key);

    // Printing the encrypted message.
    printf("Encrypted message: %s \t", text);

    
    
    // Decrypting the message
    decrypt(text, key);

    // Printing the decrypted message.
    printf("Decrypted message: %s \t", text);
	
	getch();
}


// Function to encrypt message.
void encrypt (char text[], int shift){
    int i;
    char ch;

    //Loop to operate each character in the text
    for( i=0 ; text[i]!='\0';i++){
        ch= text[i];

        // if the current character is capital 
        if(ch>='A' && ch<='Z') 
        {
            //Apply encryption for upper case 
            text[i] = (ch -'A' + key )%26 +'A';
        }  


        // if the current character is small
        else if(ch>='a' && ch<='z') 
        {
            //Apply encryption for lower case 
            text[i] = (ch -'a' + key )%26 +'a';
        }  

        // If the charecter is not a letter, it remains unchanged (I.E. Only letters are encrypted)
    }
}


// Function to decrypt message
void decrypt (char text[], int shift)
{
    int i;
    char ch;

    //Loop to operate each character in the text
    for( i=0 ; text[i]!='\0';i++)
	{
        ch= text[i];

        // if the current character is capital 
        if(ch>='A' && ch<='Z') 
        {
            //Apply decryption for upper case 
            text[i] = (ch -'A' +26 - key )%26 +'A';
        }  


        // if the current character is small
        else if(ch>='a' && ch<='z') 
        {
            //Apply decryption for lower case 
            text[i] = (ch -'a' +26 - key )%26 +'a';
        }  
    }
}

