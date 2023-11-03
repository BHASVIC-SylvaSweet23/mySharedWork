#include <stdio.h>
#include <string.h>


// The variables start empty in the actual project, so once we have input/output working we can delete the dummy data and use this commented out code.
/*
char firstName[6][20];  //max length for firstName is 19 letters
char secondName[6][20]; //and same for secondName
char DoB[6][9];         // the first 2 digits are the day, second 2 are the month, last 4 are the year
int numChildren[6];
int numAdults[6];
char boardType[6][3];   //do not put strings more than 2 letters into this
int stayLength[6];
int newspaperChoice[6]; // 0 represents doesn't want newspapers, 1 represents does want newspaper
*/


// you could also use this code for some dummy data for testing,
char firstName[6][20] = {"Lionel","Christiano",};
char secondName[6][20] = {"Messi","Ronaldo"};
char DoB[6][9] = {"24061987", "05021985"};
int numChildren[6] = {3,2};
int numAdults[6] = {2,1};
char boardType[6][3] = {"BB","FB"};
int stayLength[6] = {1,5};
int newspaperChoice[6] = {0,1};
void examplesOfReadingData() {
    char exampleName[15];
    strcpy(exampleName,firstName[1]); //you can use the same process for secondName and any other list of strings to get the whole string
    printf("%s \n",exampleName);

    char exampleDoB[9];
    strcpy(exampleDoB,DoB[0]); //copies the 1st element in DoB into a new string
    char substring[3]= { exampleDoB[2],exampleDoB[3]}; //creates a new string with letter 3 and 4 of the DoB (the month bit)
    int month;
    sscanf(substring,"%d",&month); // sscanf is pretending a user typed substring into a scanf input
    printf("Example month is %d \n",month);

    int exampleNum = numAdults[1]; //arrays of integers don't feel the need to be wacky, just assign them
    printf("Example Adults number %d \n",exampleNum);//do the same thing for other integer lists (numChildren, stayLength and newspaperChoice

}
void createBooking() {
    char tempFirstName[20];
    printf("enter your first name \n");
    scanf("%s",tempFirstName);
    char tempSecondName[20];
    printf("enter your second name \n");
    scanf("%s",tempSecondName);
    // will code DOB readin later
    int tempNumChildren;
    printf("enter a number of children \n");
    scanf("%d",&tempNumChildren);
    int tempNumAdults;
    printf("enter a number of adults \n");
    scanf("%d",&tempNumAdults);
    // need to get and validate FB, HB and BB

    }

int main() {
    createBooking()
}
