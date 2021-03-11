/*Program description. This code is a simple encryption programme that store inputs,generate random code,
encrypt,decrypt and compare input code with the pre-encrypted code.
The access code is 4523.The user first has the option to enter their own code in four parts
or randomly generate a code.
Next the user can encrypt the code,this algorithm looks like
 -Swap the 1st number with the 3rd number.
- Swap the 2nd number with the 4th number.
- Add 1 to each number.
- If any number has a value equal to 10, change this value to 0. 
Then the user can check if their entered or generated code matchs the pre-encryped code,4523(access_code).
If it is a match then you will be told "Correct",if it is an incorrect match you will be called "Wrong".
I couldnt get the option to see correct/wrong inputs to function with this code so it is blank.
Lastly, the final option to close the program offer you a choice to close or return to menu.
Author:Katie Crowley
Complier:Borland
Date started:29/4/2020
Date last modified:14/5/2020
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void entercode(int*);
void encrypt(int*);
void match(int*, int*);
void decrypt(int*);
void result();
void end();


int main() //menu
{
    int loop = 1; //endless loop
    int code[4]; //stores users entered code
    int access_code[4] = {4,5,2,3}; //pre-encrypted code array
    
    printf("Security authorisation.\n"); //name of program
    
    int response;
    while(loop == 1) //This loops the menu.
    {
        printf("(1. Input a code or generate a random code \n"); 
        printf("(2. Encrypt code\n");
        printf("(3. Check if the encrypted code matches the default authorised access code\n");
        printf("(4. Decrypt code\n");
        printf("(5. Display the number of times the encrypted code is:i. Correct ii. Wrong\n");
        printf("(6. Exit Program\n");
 
        scanf("%d", &response);//waits for an input for 1, 2, 3 ,4 ,5 or 6

        switch (response)//calls the functions
        {
            case 1:
            {
                entercode(code);
                break;
            }
            case 2:
            {
                encrypt(code);
                break;
            }
            case 3:
            {
                match(code, access_code);
                break;
            }
            case 4:
            {
                decrypt(code);
                break;
            }
            case 5:
            {
                result();
                break;
            }
            case 6:
            {
                end();
                break;
            }
            default:
            {
                printf("invalid entry");
            }
        }
    }

}

void entercode(int* code)
{
    int option,i;
   
 
    printf("Press 1 to enter your own code or press 2 to randomly generate one\n");
    scanf("%d",&option); //scans for users input 

    if (option == 1)
    {
        
        for(i=0;i<4;i++)  //Repeats 4 times to get the 4 numbers needed for the code array
        {   
            printf("Input number %d of 4 numbers\n", i+1); 
            scanf("%d", &*(code+i));
        }
        printf("Your code is \n "); //Allows user to see their inputted code
        
        for(i=0;i<4;i++) 
        {
            printf("%d", *(code+i));
        }
        
    }//end if
    else if (option == 2)
    {
        for(i=0;i<4;i++) 
        {
            *(code+i) = (rand() % 10) + 1; //randomly generates number in the range 1 to 10
        }
        
        printf("Here is your random code\n");//allows user to see random code
        
        for(i=0;i<4;i++) 
        {
            printf("%d", *(code+i)); //prints
        }
    }
    
    
    
}

void encrypt(int* code) //Encryption function 
{
    
    int i;
    int temp;
    // swaps first and third element in the array
    temp = *(code+0);
    *(code+0) = *(code+2);
    *(code+2) = temp;
    //swaps second and third element in the array
    temp = *(code+1);
    *(code+1) = *(code+3);
    *(code+3) = temp;

    for(i = 0; i<4; i++)
    {
        *(code+i) = *(code+i) + 1; //adds one to every element in the array
       
        if(*(code+i) == 10)//checks if any number is equal to 10 
        {
            *(code+i) == 0; //sets it to 0
        }//end if
    }
}

void match(int* code, int* access_code)//Function that checks if users code matchs pre-encrypted code
{
    int i;
    int count = 0;
    
   
    for(i=0; i<4; i++)
    {
        if(*(code+i) == *(access_code+i)) //checks if the users code is equal to access code
        {
            count++;
        }//end if
    }
    
    if(count == 4)//if the code matchs 4523
    {
        printf("Code correct!.\n"); //code is match
	}//end if
    else
    {
        printf("Code incorrect :( .\n");//code is not a match
    }//end else

}

void decrypt(int* code)//Function called for decryption of entered or generated code after checking for a match
{
    
    int i;
    int temp;
    
    for(i = 0; i<4; i++)
    {
        *(code+i) = *(code+i) - 1; //takes the user encrypted code and subtrack 1
        
        if(*(code+i) == -1) // if a number is negative 1...
        {
            *(code+i) == 9; //...set it to 9
        }
    }
     // swaps first and third element in the array
    temp = *(code+0);
    *(code+0) = *(code+2);
    *(code+2) = temp;
    //swaps second and third element in the array
    temp = *(code+1);
    *(code+1) = *(code+3);
    *(code+3) = temp;

    for(i=0;i<4;i++) 
        {
            printf("%d", *(code+i)); //prints the decrypted code
        }
}

void result()//Couldnt get the structure to work
{
    
}

void end()//function that allows gracefully termination of program
{
    int answer;
    //asks user if they want to exit
    printf("Do you really want to exit?\n");
    printf("Please enter 1 for Yes\n");
    printf("Please enter 0 for No\n");
    scanf("%d", &answer);

    if(answer == 1)  //if they enter 1...
    {
        exit(0); //....progam shuts
    }//end if
    else if(answer == 0) //otherwise program menu returns
    {
        
    }
}
    