#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
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
char bookingID[6][21] = {"Messi2","Ronaldo0"};
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
int isOfAge(int day, int month,int year) {
    //takes the day,month,and year of someone's birth and returns 1 if they are 18+, and 0 if they aren't.
    //It'll look like Sylva did this but this is a modification of some work by Hugo

    time_t t = time(NULL);
    struct tm tm = *localtime(&t); //i have no idea what dark wizardry this is but it's how i get the current date

    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;
    int currentYear = tm.tm_year + 1900;
    int ageYears;

    ageYears = currentYear - year; //assuming your birthday has already occurred, your age is just the difference between the year you were born and the current year
    if (currentMonth == month) {
        if (currentDay < day) {
            ageYears = ageYears - 1; //compensates for if your birthday hasn't happened this year
        }
    }
    if (currentMonth < month) {
        ageYears=ageYears-1; //compensates for if your birthday hasn't happened this year
    }
    return(ageYears>17);
}
int getUserInput(int roomNumber){
    //this function takes a room number, asks the user for all of the data necessary for the booking, validates the data, then, if the user confirms, saves this data into the appropriate spaces for it.
    //roomNumber will be an array index, so if you want room 1, you should pass 0 into this function.
    // PLEASE ensure that the roomNumber is that of an empty room, or else someone's booking data may be deleted,
    // this function outputs 1 if the booking was made, and 0 if it wasn't
    const char poundSign = -100; // the £ symbol seems to behave questionably when directly typed in a string, so this is my alternative
    char tempFirstName[40];
    char tempSecondName[40];
    int wasValid = 2; // the while loops for validation all use this variable. 2 means the user hasn't inputted yet, 0 means the user inputted something invalid, and 1 means it's ok.
    while (wasValid!=1) {
        if (wasValid!=2) {
            printf("please re-enter your name \n");
        }
        wasValid=1;
        printf("Please enter your first name, it must be less than 19 characters: \n");
        scanf("%s",&tempFirstName);
        fflush(stdin);
        printf("Please enter your second name it must be less than 19 characters: \n");
        scanf("%s",&tempSecondName);
        fflush(stdin);
        printf("You entered your name to be %s %s. \n",tempFirstName,tempSecondName);
        if (strlen(tempFirstName) > 19 || strlen(tempSecondName )> 19) { // the max size is completely arbitrary, and can be increased if we want.
            printf("Neither name can be longer than 19 characters \n");
            wasValid = 0;
        }
        else {
            printf("Type \"c\" to confirm this is OK, or anything else to redo. \n"); //this confirmation box gets copied a lot. it just asks the user to enter "confirm", and if they don't, claims the input is invalid.
            char confirmation[20];
            scanf("%s",confirmation);
            if (strcmp(confirmation,"c")!=0) {
                wasValid = 0;
            }
        }

    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t); //i have no idea what dark wizardry this is but it's how i get the current date
    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;
    int currentYear = tm.tm_year + 1900;

    wasValid=2;
    int yearOfBirth;
    int monthOfBirth;
    int dayOfBirth;
    while (wasValid!=1) {
        if (wasValid != 2) { //occurs all times except first loop.
            printf("please re-enter your date of birth. \n");
        }
        wasValid = 1;


        int isLeapYear = (currentYear%4 == 0) - (currentYear%100 == 0) + (currentYear%400 == 0); //this is to prevent someone claiming to be born on nonexistant dates like 29/2/2005
        int daysInMonths[12] = {31,28+isLeapYear,31,30,31,30,31,31,30,31,30,31}; //this stores how many days there are in each month of the year, eg: the first item being 31 means there are 31 days in january

        printf("Please enter the year you were born: \n");
        scanf("%d",&yearOfBirth);
        printf("Please enter the month you were born, enter a number, and not a word. for example, enter \"8\" instead of august. \n");
        scanf("%d",&monthOfBirth);
        printf("Please enter the day of the month you were born: \n");
        scanf("%d",&dayOfBirth);

        printf("you entered %d/%d/%d \n", dayOfBirth, monthOfBirth, yearOfBirth);

        if (monthOfBirth < 1 || monthOfBirth > 12) {
            printf("you didn't enter a valid month. \n");
            wasValid = 0;
        }
        else if ((dayOfBirth > daysInMonths[monthOfBirth-1]) || dayOfBirth < 1 ) { //the day must be between 1 and the max days in the month
            printf("you didn't enter a valid day of the month. \n");
            wasValid = 0;
        }
        else if ((yearOfBirth > currentYear) || (yearOfBirth == currentYear) && (monthOfBirth > currentMonth || dayOfBirth > currentDay && monthOfBirth == currentMonth) ){
            printf("The date you entered is in the future. No time travellers allowed in the Kashyyyk hotel! \n");
            wasValid = 0;
        }
        else if (!isOfAge(dayOfBirth, monthOfBirth, yearOfBirth)) {
            printf("you are not 18 or over! Only adults are allowed to book rooms at Kashyyyk Hotel! \n");
            wasValid = 0;
        }
        else {
            printf("Type \"c\" to confirm this is OK, or anything else to redo. \n");
            char confirmation[20];
            scanf("%s",confirmation);
            if (strcmp(confirmation,"c")!=0) {
                wasValid = 0;
            }
        }
    }

    int tempNumChildren;
    int tempNumAdults;
    wasValid = 2;
    while (wasValid!=1) {
        if (wasValid!=2) {
            printf("please re-enter the number of children and adults: \n");
        }
        wasValid = 1;
        printf("please enter how many children will be with you on your stay. (for our purposes, a child is anybody under 16) \n");
        scanf("%d",&tempNumChildren);
        printf("please enter how many adults will be with you on your stay (this includes yourself). \n");
        scanf("%d",&tempNumAdults);
        printf("you entered %d adults and %d children \n",tempNumAdults,tempNumChildren);
        if (tempNumChildren < 0 || tempNumAdults < 0) {
            printf("you cannot have a negative number of children or adults. \n");
            wasValid = 0;
        }
        else if (tempNumAdults == 0) {
            printf("there must be at least 1 adult on your stay. \n");
            wasValid = 0;
        }
        else if (tempNumAdults+tempNumChildren > 4) {
            printf("the maximum capacity of any room is 4. \n");
            wasValid = 0;
        }
        else {
            printf("Type \"c\" to confirm this is OK, or anything else to redo. \n");
            char confirmation[20];
            scanf("%s",confirmation);
            if (strcmp(confirmation,"c")!=0) {
                wasValid = 0;
            }
        }
    }

    char tempBoardType[3];
    wasValid = 2;
    while (wasValid != 1) {
        if (wasValid!=2) {
            printf("invalid board type, please re-enter your board type \n");
        }
        printf("enter your board type. It must be either FB for full board, HB for half board, or BB for bed & breakfast \n");
        scanf("%s",tempBoardType);
        wasValid = 1;
        if (strcmp(tempBoardType,"FB")==0) {
            printf("you selected Full Board, which costs %c20 per person per day. \n",poundSign);
        }
        else if (strcmp(tempBoardType,"HB")==0) {
            printf("you selected Half Board, which costs %c15 per person per day. \n",poundSign);
        }
        else if (strcmp(tempBoardType,"BB")==0) {
            printf("you selected Bed and Breakfast, which costs %c5 per person per day. \n",poundSign);
        }
        else {
            wasValid = 0;
        }
        if (wasValid) {
            printf("Type \"c\" to confirm this is OK, or anything else to redo. \n");
            char confirmation[20];
            scanf("%s",confirmation);
            if (strcmp(confirmation,"c")!=0) {
                wasValid = 0;
            }
        }
    }


    int tempStayLength;
    wasValid = 2;
    while (wasValid!=1) {
        if (wasValid != 2) { //occurs all times except first loop.
            printf("please re-enter your stay length. \n");
        }
        wasValid = 1;
        printf("Enter your stay length, it should be a whole number \n");
        scanf("%d",&tempStayLength);
        printf("You entered a stay length of %d days \n",tempStayLength);
        if (tempStayLength < 1) { //prevents negative or 0 stay lengths. At the moment there is no stay length maximum
            printf("you must stay for at least one day! \n");
            wasValid = 0;
        }
        else {
            printf("Type \"c\" to confirm this is OK, or anything else to redo. \n");
            char confirmation[20];
            scanf("%s",confirmation);
            if (strcmp(confirmation,"c")!=0) {
                wasValid = 0;
            }
        }
    }


    int tempNewspaperChoice;
    wasValid = 2;
    while (wasValid) {
        printf("enter \"newspaper\" if you would like a daily newspaper, or anything else to decline.\nThis will make your booking cost %c5.50 extra: \n",poundSign); //see the top of the function for explanation on poundSign
        char response[20];
        scanf("%s",&response);
        tempNewspaperChoice = (strcmp(response,"newspaper")==0);
        if (tempNewspaperChoice){
            printf("you selected that you would like a newspaper. type \"c\" to confirm this is OK, or anything else to redo. \n");
        }
        else {
            printf("you selected that you would not like a newspaper. type \"c\" to confirm this is OK, or anything else to redo. \n");
        }
        char confirmation[20];
        scanf("%s",confirmation);
        if (strcmp(confirmation,"confirm")!=0) {
            wasValid = 0;
        }
    }


    printf("The data you entered is as follows:\n");
    printf("First name: %s\n",tempFirstName);
    printf("Second name: %s\n",tempSecondName);
    printf("Date of birth: %d/%d/%d\n",dayOfBirth,monthOfBirth,yearOfBirth);
    printf("Number of children: %d\n",tempNumChildren);
    printf("Number of adults: %d\n",tempNumAdults);
    printf("For a total of %d people in the booking\n",tempNumAdults+tempNumChildren);
    printf("Board type: %s\n",tempBoardType);
    printf("A stay length of %d\n",tempStayLength);
    if (tempNewspaperChoice) {
        printf("Yes to the daily newspaper \n");
    }
    else {
        printf("No to the daily newspaper \n");
    }
    // now is the option to cancel the booking.

    char input[20];
    wasValid = 2;
    while (wasValid!=1) {
        if (wasValid != 2) {
            printf("You did not enter either book, or cancel \n");
        }
        wasValid = 1;
        //this confirmation looks slightly different because instead of the absence of something meaning cancel,
        // which has the potential for a user to make a typo and lose all their progress, the user has to type "cancel"
        printf("Would you like to book using these details for room number %d? Enter \"book\" to book or \"cancel\" to cancel \n",roomNumber+1);
        scanf("%s",input);
        if (strcmp(input,"cancel")==0) {
            printf("cancelling the booking \n");
            return(0); //exits the function without storing anything
        }
        else if (strcmp(input,"book")!=0) {
            wasValid = 0;
        }
    }
    printf("booking for room number %d \n",roomNumber+1);
    // from this point on, the program is allowed to write to global variables.

    strcpy(firstName[roomNumber],tempFirstName); //copies the string in tempFirstName to the roomNumber'th index in firstName
    strcpy(secondName[roomNumber],tempSecondName);
    // this is where I convert the 3 numbers to a single date of birth string
    int tempIntDOB = dayOfBirth*1000000 + monthOfBirth*10000 + yearOfBirth;
    char tempDOB[9];
    if (dayOfBirth>9) {
        sprintf(tempDOB,"%d",tempIntDOB); //sprintf is like printf, but instead of outputting the string on the screen, it saves the string to tempDOB
    }
    else {
        sprintf(tempDOB,"0%d",tempIntDOB); //if dayOfBirth is a single-digit number, then a leading 0 must be added.
    }
    strcpy(DoB[roomNumber],tempDOB);
    numChildren[roomNumber] = tempNumChildren;
    numAdults[roomNumber] = tempNumAdults;
    strcpy(boardType[roomNumber],tempBoardType);
    stayLength[roomNumber] = tempStayLength;
    newspaperChoice[roomNumber] = tempNewspaperChoice;
    return(1); //1 means successful booking
}
void createBookingID(int roomNumber) {
    int wasInvalid = 1;
    char tempBookingID[21];
    while (wasInvalid) {
        srand(time(NULL));

        sprintf(tempBookingID,"%s%d",secondName[roomNumber],(rand()%10));
        wasInvalid = 0;
        int i;
        for (i=0;i<6;i++) {
            if (bookingID[i]==tempBookingID) {
                wasInvalid = 1; //ensures there are no repeats
            }
        }
    }
    strcpy(bookingID[roomNumber],tempBookingID);
}
int checkin() {
    int selectedRoomNumber;
    selectedRoomNumber = samswork(); // sam needs to write a function that shows the room prices and asks the user to input the room they want, and passes it back
    int wasSuccessful = getUserInput(selectedRoomNumber);
    if (wasSuccessful) {
        createBookingID(selectedRoomNumber);
        return(1);
    }
    return(0);
}
int main() {
    //createBooking()
    createBookingID(1);
    printf("%s",bookingID[1]);
}
