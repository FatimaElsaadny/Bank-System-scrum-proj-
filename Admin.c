// ***************************************************** //
//*************** Import Libraries ********************* //
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
// ***************************************************** //
//*************** Functions declaration **************** //

void create_new_account();
void trim(char *s);
// int validName(char &name);
int validNationalID(long long nid);
long long genAccNumber();
long long genAccpass();
// ***************************************************** //
//*************** Struct declaration **************** //
typedef enum account_Status
{
    Active = 1,
    Restricted = 0,
    Closed = 0
} STATUS;

typedef struct clientaccount
{
    char full_name[150];
    char *full_address;
    long long National_id;
    char guardian_National_id;
    int age;
    int account_number;
    int account_passowrd;
    STATUS status;
    double balance;

} clientaccount;

typedef struct Person
{
    char full_name[150];
    char full_address[150];
    long National_id;

    char guardian_National_id[15];
    int age;
    int account_number;
    int account_passowrd;
    char status[15];
    int balance;

} person;

// *******************************************  ********** //
//*************** Main Method ********************* //
int main()
{
    char name[] = "fat****ima Massoud";
    printf("%s \n", name);

    create_new_account();
    return 0;
}

// ***************************************************** //
//*************** Functions definition ********************* //

// void trim(char *s)
// {
//     int count = 0;
//     while (s[count] == " " || s[count] == '\n' || s[count] == '\t')
//     {
//         count++;
//     }

//     if (count != 0)
//     {
//         int i = 0;
//         while (s[i + count] != '\0')
//         {
//             s[i] = s[i + count];
//             i++;
//         }
//         s[i] = '\0';
//     }
// }

// int validName(char &name)
// {
//     int nspace = 0;
//     for (int i = 0; i < strlen(name); i++)
//     {
//         if (name[i] == " ")
//         {
//             nspace += 1;
//         }
//     }

//     if (nspace == 3)
//     {
//         printf("validName");
//         return 1;
//     }
//     else
//     {
//         printf("InvalidName:");
//     }
//     return 0;
// }

//************************************
int validNationalID(long long nid)
{
    int count = 0;
    while (nid != 0)
    {
        nid = nid / 10;
        count++;
    }

    if (count == 14)
    {
        printf("Valid National ID");
        return 1;
    }

    printf("InValid National ID!!");
    return 0;
}

//************************************
// Generate Account Id
long long genAccNumber()
{
    long long number;
    long long lower = 1000000000, upper = 9999999999;
    srand(time(NULL));
    number = (rand() % (upper - lower + 1)) + lower;

    return number;
}

//************************************
// Generate Account password
long long genAccpass()
{
    long long number;
    long long lower = 1000, upper = 9999;
    srand(time(NULL));
    number = (rand() % (upper - lower + 1)) + lower;

    return number;
}

//************************************

void create_new_account()
{
    clientaccount newAcc;
    printf("\n\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+");
    printf("\n\t\t\t******Welcome to IMT Bank System******\t\t\n");

    // Read Name
    char name[150];

    printf("Please Enter your Full Name:");
    scanf("%s", name);
    printf("your name is: %s", name);
    // newAcc.full_name = name;
    // printf("From struct your name is: %s", newAcc.full_name);

    // strcpy(newAcc.full_name, name);

    // ####################

    // Read Address
    //  char *name;
    //  scanf("Please Enter your Full Name: %s", name);
    //  newAcc.full_address

    // Read National id
    long long nid;
    do
    {
        printf("\nPlease Enter Valid national Id:");
        scanf("%lld", &nid);
        printf("%lld\n", nid);
    } while (validNationalID(nid) == 0);
    newAcc.National_id = nid;

    // Read Age
    int age;
    printf("\nPlease Enter your Age:");
    scanf("%d", &age);
    newAcc.age = age;

    // Read Guardian nId if age <21
    if (age < 21)
    {
        do
        {
            printf("\nPlease Enter a valid Guardian national Id:");
            scanf("%lld", &nid);

        } while (validNationalID(nid) == 0);
        newAcc.guardian_National_id = nid;
    }

    newAcc.status = Active;
    newAcc.balance = 0;
    newAcc.account_number = genAccNumber();
    newAcc.account_passowrd = genAccpass();

    printf("\n\t\t**********Account created Successfully:)*********");
    printf("\n\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+");
}

// ******************************
