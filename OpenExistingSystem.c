/**********************************************/
// Auther : Alaa Saleh  date: 2022-05-10
/*IMT BANK System*/
/* Updated version 
/**********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct clientaccount
{
  char full_name[150];
  char full_address[150];
  // char National_id[15];
  int National_id;
  char guardian_National_id[15];
  int age;
  int account_number;
  int account_passowrd;
  char status[15];
  int balance;

} clientaccount;

int clnt_id;

typedef struct ClientNode
{
  clientaccount *data;
  struct ClientNode *Next;
} ClientNode;

typedef struct List
{
  int Size;
  ClientNode *head;
} List;

/**********************************************/
/**************Function ProtoTypes ************/
/**********************************************/

void create_new_account();
void Open_Existing_Account();
void Make_Transaction(clientaccount *clnt, List *pl);
clientaccount *Change_Account_Status(clientaccount *clnt, List *pl);
clientaccount *Get_Cash(clientaccount *clnt, List *pl);
clientaccount *Deposit_in_Account(clientaccount *clnt);
void admin_main_menu(List *pl);
void Return_to_admin_main_menu(List *pl);
void List_voidInit(List *pl);
void List_voidInsertList(int pos, List *pl, ClientNode *val);
clientaccount *List_voidRetriveList(int pos, List *pl, clientaccount *clnt);
clientaccount *get_pointer_to_clint_by_ID(int id);
void print_client_acc(clientaccount *c);
void create_new_account();
void main_menu();
void ExitAdmin();

List *pl;
int main(char *argv[])
{


  pl = malloc(sizeof(ClientNode) * 2);

  List_voidInit(pl);

  clientaccount *asma;
  asma = malloc(sizeof(clientaccount));
  strcpy(asma->full_address, "ASmaa saaed sadd");
  asma->age = 20;
  asma->balance = 9000;
  asma->National_id = 90;
  strcpy(asma->status, "Active");

  ClientNode *newn;
  newn = malloc(sizeof(ClientNode));

  newn->data = asma;
  newn->Next = NULL;
  List_voidInsertList(0, pl, newn);

  clientaccount *fatma;
  fatma = malloc(sizeof(clientaccount));
  strcpy(fatma->full_address, "alaa wi fatima");
  fatma->age = 20;
  fatma->balance = 12000;
  fatma->National_id = 80;
  strcpy(fatma->status, "Active");

  ClientNode *newf;
  newf = malloc(sizeof(ClientNode));

  newf->data = fatma;
  newf->Next = NULL;
  List_voidInsertList(0, pl, newf);

  main_menu();
  return 0;
}

/**********************************************/
/**********************************************/
clientaccount *clnt;

void Open_Existing_Account(int rgst, List *pl)
{

  int feat_no;

  // if (rgst == 0)
  // {
  printf("Welcome! pls enter your Bank Account ID:..\n");
  scanf("%d", &clnt_id);
  // printf("clinnnn %d",clnt_id);
  clnt = List_voidRetriveList(clnt_id, pl, clnt);
  // }
  //  should verify this id
  printf("\n1- Make Transaction\n ");

  printf("2- Change Account Status\n ");
  printf("3- Get Cash\n ");

  printf("4- Deposit in Account\n ");
  printf("5- Return to main menu\n ");

  printf("Thank you -_-, pls choose the feature you want! ");

  scanf("%d", &feat_no);

  switch (feat_no)
  {
  case 1:
    Make_Transaction(clnt, pl);
    break;
  case 2:
    clnt = Change_Account_Status(clnt, pl);
    break;
  case 3:
    clnt = Get_Cash(clnt, pl);
    break;

  case 4:
    Deposit_in_Account(clnt);
    break;
  case 5:
    Return_to_admin_main_menu(pl);
    break;
  default:
    printf("please enter valid number");
    break;
  }
  Open_Existing_Account(1, pl);
}

/**********************************************/
/**********************************************/

clientaccount *rcv;
void Make_Transaction(clientaccount *clnt, List *pl)
{

  int to_id;
  int mny_amnt;
  printf("Welcome! pls enter the Bank Account ID you want to transfer money to:..");
  scanf("%d", &to_id);

  rcv = List_voidRetriveList(to_id, pl, rcv);

  //  should verify this id

  printf("Thank you -_-, pls enter amount of money to transfer it to the this account ! ");
  scanf("%d", &mny_amnt);

  printf("%s", rcv->status);
  // You have to make sure that both accounts are Active.
  if (strcmp(clnt->status, "Active") == 0 & strcmp(rcv->status, "Active") == 0)
  {
    if (clnt->balance > mny_amnt)
    {
      clnt->balance -= mny_amnt;
      rcv->balance += mny_amnt;
      printf("Done!");
    }
    else
    {
      printf("You don't have enough money, the transaction won’t be completed :(");
    }
  }
  else
  {
    printf("the accounts are not active please activate them to complete this action:(");
  }
}

/**********************************************/
/**********************************************/

clientaccount *Change_Account_Status(clientaccount *clnt, List *pl)
{
  printf("PLS choose the number of the Bank Account Status, you want for this account\n");
  printf("1- Set Account to Active State\n 2- Set Account to Restricted State\n 3- Set Account to Closed\n");
  int st;
  scanf("%d", &st);
  switch (st)
  {
  case 1:
    strcpy(clnt->status, "Active");
    break;
  case 2:
    strcpy(clnt->status, "Restricted");

    break;
  case 3:
    strcpy(clnt->status, "Closed");
    break;
  default:
    printf("please enter valid status");
    break;
  }
  return clnt;
}

/**********************************************/
/**********************************************/

clientaccount *Get_Cash(clientaccount *clnt, List *pl)
{
  int mny_amnt;

  printf("pls enter amount of money you want from this account\n");
  scanf("%d", &mny_amnt);
  printf("Your current balance is %d", clnt->balance);

  if (clnt->balance > mny_amnt)
  {
    clnt->balance -= mny_amnt;
    printf("Done! Your current balance now is %d\n", clnt->balance);
  }
  else
  {
    printf("You don't have enough money, the transaction won’t be completed :(");
  }
  return clnt;
  // getchar();
  // Open_Existing_Account(1, pl);
}

/**********************************************/
/**********************************************/

clientaccount *Deposit_in_Account(clientaccount *clnt)
{

  int mny_amnt;
  printf("Your current balance is %d", clnt->balance);

  printf("pls enter amount of money you want to add to this account.");

  scanf("%d", &mny_amnt);
  clnt->balance += mny_amnt;
  printf("Done! Your current balance now is %d\n", clnt->balance);

  return clnt;
}

/**********************************************/
/**********************************************/
void admin_main_menu(List *pl)
{
  int current_feature = 0;
  printf("\t\t**************System Main Menu*****************\t\t\n");
  printf("1- Create New Account\n");
  printf("2- Open Existing Account\n");
  printf("3- Exit the System\n");
  printf("Please choose the feature you need!:... ");
  scanf("%d", &current_feature);
  // if (current_feature == 1)
  // {
  //   create_new_account(pl);
  // }
  if (current_feature == 2)
  {
    Open_Existing_Account(0, pl);
  }
     else if (current_feature == 3)
    {
        ExitAdmin();
    }
}


/**********************************************/
/**********************************************/

void Return_to_admin_main_menu(List *pl)
{
  admin_main_menu(pl);
}

/**********************************************/
/**********************************************/

void List_voidInit(List *pl)
{
  pl->head = malloc(sizeof(ClientNode));
  pl->head = NULL;
  pl->Size = 0;
}
// // fatama task1 create new account

void List_voidInsertList(int pos, List *pl, ClientNode *val)
{

  ClientNode *pn;
  pn = val;
  // // pn->Next = NULL;
  if (pos == 0)
  {

    
    ClientNode *tmp;
    tmp = pl->head;
    pl->head = pn;
    pl->head->Next = tmp;
  }

  (pl->Size)++;
}

clientaccount *List_voidRetriveList(int pos, List *pl, clientaccount *clnt)
{

  ClientNode *tmp = malloc(sizeof(ClientNode));

  tmp = pl->head;

  while (tmp->data->National_id != pos)
  {
    tmp = tmp->Next;
  }
  clnt = tmp->data;
  return clnt;
}
void print_client_acc(clientaccount *c)
{
  printf("%d", c->balance);
  printf("%s", c->full_name);
  printf("%d", c->National_id);
}

void ExitAdmin()
{
    main_menu();
};



void main_menu()
{
    printf("\t\t************** Welcome To IMT Bank *****************\t\t\n");

    printf("1-USER Menu \n");

    printf("2-ADMIN Menu \n");
    printf("Please choose the menu you need!:... ");
    char arr[14];
    int y;
    int x;
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        //   user menu --> DOING

        break;
    case 2:
        printf("Please Enter user name  ..! ");
        scanf("%s", arr);
        // scanf("%d",&y);
        printf("\nPlease Enter password  ..! ");

        scanf("%d", &x);
        

        admin_main_menu(pl);

        break;

    default:
        printf("=======");
        break;
    }}
