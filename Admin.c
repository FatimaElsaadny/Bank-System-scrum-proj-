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
long long genAccID();
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
    int National_id;
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

    long long nid = 98050700000179;
    validNationalID(nid);

    printf("\n Account Id: %d", genAccID());
    printf("\n Account password: %d", genAccpass());
    // account_Status = Active
    STATUS status = Closed;
    printf("\nStatus: %d", status);
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
long long genAccID()
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
    person p;
}

// ******************************
