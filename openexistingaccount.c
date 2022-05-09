/**********************************************/
// Auther : asmaa saeed date: 2022-05-09
/*IMT BANK System*/
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

List *pl;

/**********************************************/
/**************Function ProtoTypes ************/
/**********************************************/

void create_new_account();
void Open_Existing_Account();
void Make_Transaction(clientaccount *clnt);
void Change_Account_Status(clientaccount *clnt);
void Get_Cash(clientaccount *clnt);

void Deposit_in_Account(clientaccount *clnt);

void admin_main_menu();
void Return_to_admin_main_menu();

void List_voidInit(List *pl);
void List_voidInsertList(int pos, List *pl, ClientNode *val);
void List_voidRetriveList(int pos, List *pl, clientaccount *clnt);
clientaccount *get_pointer_to_clint_by_ID(int id);

void create_new_account();

int main()
{

  List_voidInit(pl);
  admin_main_menu();
  return 0;
}

void Open_Existing_Account(int rgst)
{

  int feat_no;
  clientaccount clnt;
  if (rgst == 0)
  {
    printf("Welcome! pls enter your Bank Account ID:..");
    scanf("%d", &clnt_id);
    List_voidRetriveList(clnt_id, pl, &clnt);
  }
  //  should verify this id
  printf("Thank you -_-, pls choose the feature you want! ");
  scanf("%d", &feat_no);
  switch (feat_no)
  {
  case 1:
    Make_Transaction(&clnt);
    break;
  case 2:
    Change_Account_Status(&clnt);
    break;
  case 3:
    Get_Cash(&clnt);
  case 4:
    Deposit_in_Account(&clnt);
    break;
  case 5:
    Return_to_admin_main_menu();
    break;
  default:
    printf("please enter valid number");
    break;
  }
}

void Make_Transaction(clientaccount *clnt)
{
  int to_id;
  int mny_amnt;
  printf("Welcome! pls enter the Bank Account ID you want to transfer money to:..");
  scanf("%d", &to_id);
  clientaccount *rcv;
  //  should verify this id

  printf("Thank you -_-, pls enter amount of money to transfer it to the this account ! ");
  scanf("%d", &mny_amnt);

  // You have to make sure that both accounts are Active.
  if (clnt->status == "Active" && rcv->status == "Active")
  {
    if (clnt->balance < mny_amnt)
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
  getchar();
  Open_Existing_Account(1);
}

void Change_Account_Status(clientaccount *clnt)
{
  printf("PLS choose the number of the Bank Account Status, you want for this account");
  printf("1- Set Account to Active State\nSet Account to Restricted State\n 3- Set Account to Closed\n");
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
  getchar();
  Open_Existing_Account(1);
}

void Get_Cash(clientaccount *clnt)
{
  int mny_amnt;

  printf("pls enter amount of money you want from this account");
  scanf("%d", &mny_amnt);
  if (clnt->balance < mny_amnt)
  {
    clnt->balance -= mny_amnt;
    printf("Done!");
  }
  else
  {
    printf("You don't have enough money, the transaction won’t be completed :(");
  }
}

void Deposit_in_Account(clientaccount *clnt)
{

  int mny_amnt;

  printf("pls enter amount of money you want to add to this account.");
  scanf("%d", &mny_amnt);
  clnt->balance += mny_amnt;
  printf("Done!");
}

void admin_main_menu()
{
  int current_feature = 0;
  printf("\t\t\tSystem Main Menu\t\t\t");
  printf("1- Create New Account");
  printf("2- Open Existing Account");
  printf("3- Exit the System");
  printf("Please choose the feature you need!:... ");
  scanf("%d", &current_feature);
  if (current_feature == 1)
  {
    create_new_account(&pl);
  }
  else if (current_feature == 2)
  {
    Open_Existing_Account(0);
  }
}

void Return_to_admin_main_menu()
{
  admin_main_menu();
}

clientaccount *get_pointer_to_clint_by_ID(int id)
{
}

void List_voidInit(List *pl)
{
  pl->head = NULL;
  pl->Size = 0;
}
// fatama task1 create new account

void List_voidInsertList(int pos, List *pl, ClientNode *val)
{

  ClientNode *pn;
  pn= val;
  // pn->Next = NULL;
  if (pos == 0)
  {
    ClientNode *tmp = pl->head;
    pl->head = pn;
    pl->head->Next = tmp;
  }
  else
  {
    ClientNode *tmp = pl->head;
    for (int i = 0; i < pos - 1; i++)
    {
      tmp = tmp->Next;
    }
    pn->Next = tmp->Next;
    tmp->Next = pn;
  }
  (pl->Size)++;
}

void List_voidRetriveList(int pos, List *pl, clientaccount *clnt)
{
  ClientNode *tmp = pl->head;
  // for (int i = 0; i < pos; i++)
  while (tmp->data->National_id != pos)
  {
    tmp = tmp->Next;
  }
  clnt = tmp->data;
}

void create_new_account(List *pl)
{

  clientaccount *newclientacc;
  printf("Pls enter your fullName:   ");
  scanf("%c", newclientacc->full_name);
  printf("Pls enter your address:   ");
  scanf("%c", newclientacc->full_address);

  printf("Pls enter your nationID:   ");
  scanf("%d", &(newclientacc->National_id));

  printf("Pls enter your Age:   ");
  scanf("%d", &(newclientacc->age));

  if (newclientacc->age < 21)
  {
    printf("Pls enter your Guardian:   ");
    scanf("%c", newclientacc->guardian_National_id);
  }
  printf("Pls enter your Status:   ");

  scanf("%c", newclientacc->status);

  newclientacc->balance = 0;
  newclientacc->account_passowrd = rand();

  ClientNode *newnode;
  newnode->data = newclientacc;
  newnode->Next = NULL;
  List_voidInsertList(0, pl, newnode);
}
