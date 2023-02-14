#include <iostream>
#include <windows.h>
#include <sstream>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;

int adminPassword = 1234;
int staffPassword = 5678;
int accNumStart = 1001;


struct Account {
    string name;
    int account_number;
    char gender;
    int pin;
    string history[20];
    float account_balance;
    int index = 0;
    struct Account* next;
};
Account* head = NULL;
void adminPanel();
void staffPanel();
void mobilePanel(int acc);

void createAccount();
void deleteAccount();
void searchAccount();
void showAllAccount();
void editAccount();
void showAccountLog();

void deposit();
void withdraw();
void transfer();

void mobileCheckBalance(int acc);
void mobileTransfer(int acc);
void payUtility(int acc);
void mobileCheckHistory(int acc);

void addAcc(string name, int accNum, char gen, int p, float bl);
bool checkAdminLogin();
bool checkStaffLogin();
int checkMobileLogin();

int main(){
 //   addAcc("someone", 3000, 'M', 123 , 5000);
 //   addAcc("agdagg", 3001, 'M', 123 , 5000);
 //   addAcc("dfadffe", 3002, 'M', 123 , 5000);


    bool exit = false;

    while(!exit){
        int choice;
        system("cls");
        system("Color B");
        cout<<"\n\n\n                                               ##################################################\n"
            <<"                                               #############    Banking System     ##############\n"
            <<"                                               ##################################################\n"
            <<"                                               ########   1, Admin Login              ###########\n"
            <<"                                               ########   2, Staff Login              ###########\n"
            <<"                                               ########   3, Mobile Banking           ###########\n"
            <<"                                               ########   4, Exit                     ###########\n"
            <<"                                               ##################################################\n"
            <<"                                                    Enter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1: {
                if(checkAdminLogin()){
                adminPanel();
                }
                break;
            }
            case 2: {
                if(checkStaffLogin()){
                staffPanel();
                }
                break;
            }
            case 3: {
                int acc = checkMobileLogin();
                if(acc != -1){
                    mobilePanel(acc);
                }
                break;
            }
            case 4: exit = true;
        }
    }


return 0;
}


////////////////// panel functions
void adminPanel(){
    bool exit = false;
    while(!exit){
        system("cls");
        cout << "                                       ########################################"<< endl;
        cout << "                                       ##########    ADMIN|||PANEL   ##########"<< endl;
        cout << "                                       ########################################"<< endl;
        cout << "                                       ##  1, To Create Account              ##" << endl;
        cout << "                                       ##  2, To Delete Account              ##" << endl;
        cout << "                                       ##  3, To Search Account              ##" << endl;
        cout << "                                       ##  4, To Show List of All Accout     ##" << endl;
        cout << "                                       ##  5, To Edit Information            ##" << endl;
        cout << "                                       ##  6, To Show Logs of Account        ##" << endl;
        cout << "                                       ##  7, To Go Back to Main Menu        ##" << endl;
        cout << "                                       ########################################" << endl;
        cout << "                                       Enter an Option : ";
        int option, op;
        cin>>option;
        switch(option){
            case 1: {
                ca:
                system("cls");
                createAccount();
                cout<<"\n                                               Enter 1 to create another account  :   ";
                cin>>op;
                if(op == 1) goto ca;
                break;
            }
            case 2:  {
                da:
                system("cls");
                deleteAccount();
                cout<<"\n                                               Enter 2 to delete another account  :   ";
                cin>>op;
                if(op == 2) goto da;
                break;
            }
            case 3:   {
                sa:
                system("cls");
                searchAccount();
                cout<<"\n                                               Enter 3 to search another account  :   ";
                cin>>op;
                if(op == 3) goto sa;
                break;
            }
            case 4:  {
                saa:
                system("cls");
                showAllAccount();
                cout<<"\n                                               Enter 4 to show  all account";
                cin>>op;
                if(op == 4) goto saa;
                break;
            }
            case 5:  {
                ea:
                editAccount();
                cout<<"\n                                               Enter 5 to edit another account  :   ";
                cin>>op;
                if(op == 5) goto ea;
                break;
            }
            case 6:  {
                sl:
                system("cls");
                showAccountLog();
                cout<<"\n                                               Enter 6 to show another account log  :   ";
                cin>>op;
                if(op == 6) goto sl;
                break;
            }
            case 7: exit = true;
        }

    }
return;
}
void staffPanel(){
    bool exit = false;
    while(!exit){
        system("cls");
        system("Color C");
        cout<<"                                                ***************************************\n"
            <<"                                               *************STAFF|||PANEL************* \n"
            <<"                                               ***************************************\n"
            <<"                                               *  Press 1 To Check Account Info      *\n"
            <<"                                               *  Press 2 To Deposit Cash            *\n"
            <<"                                               *  Press 3 To Withdraw Cash           *\n"
            <<"                                               *  Press 4 To Transfer Cash           *\n"
            <<"                                               *  Press 5 To Check Logs of User      *\n"
            <<"                                               *  Press 6 To Go Back to Main Menu    *\n"
            <<"                                               ***************************************\n"
            <<"                                                  Enter your choice :   ";
        int choice,op;
        cin>>choice;
        switch(choice) {
        case 1: {
                ca:
                system("cls");
                searchAccount();
                cout<<"\n                                               Enter 1 to show another account  :   ";
                cin>>op;
                if(op == 1) goto ca;
                break;
            }
            case 2:  {
                da:
                system("cls");
                deposit();
                cout<<"\n                                               Enter 2 to deposit again  :   ";
                cin>>op;
                if(op == 2) goto da;
                break;
            }
            case 3:   {
                sa:
                system("cls");
                withdraw();
                cout<<"\n                                               Enter 3 to withdraw again  :   ";
                cin>>op;
                if(op == 3) goto sa;
                break;
            }
            case 4: {
                tr:
                system("cls");
                transfer();
                cout<<"\n                                               Enter 4 to transfer again  :   ";
                cin>>op;
                if(op == 4) goto tr;
                break;
            }
            case 5:  {
                sl:
                system("cls");
                showAccountLog();
                cout<<"\n                                               Enter 5 to show another account log  :   ";
                cin>>op;
                if(op == 5) goto sl;
                break;
            }
            case 6:  exit = true;
        }
    }
}
void mobilePanel(int acc){
    bool exit = false;
    while(!exit){
        cout<<"\n                                             +++++++++++++++++++++++++++++++++++\n"
            <<"                                               +++++++++ MOBILE PANEL ++++++++++++\n"
            <<"                                               +++++++++++++++++++++++++++++++++++\n"
            <<"                                               ++ 1. Check Balance             +++\n"
            <<"                                               ++ 2. transfer                  +++\n"
            <<"                                               ++ 3. pay for utility           +++\n"
            <<"                                               ++ 4. check history             +++\n"
            <<"                                               ++ 3. exit                      +++\n"
            <<"                                               +++++++++++++++++++++++++++++++++++\n"
            <<"                                                   Enter your choice   :     ";
        int choice;
        cin>>choice;
        switch(choice) {
        case 1: {
                system("cls");
                mobileCheckBalance(acc);
                break;
            }
            case 2:  {
                system("cls");
                mobileTransfer(acc);
                break;
            }
            case 3: {
                system("cls");
                payUtility(acc);
                break;
            }
            case 4: {
                system("cls");
                mobileCheckHistory(acc);
                break;
            }
            case 5: exit = true;
        }
    }
}





/////////////// main functions

void createAccount(){
    //Account *acc = new Account;
    int pin,acc;
    float balance;
    string name;
    char sex;

    cout<<"\n                                               Enter Name :   ";
    getline(cin>>ws, name);
    cout<<"\n                                               Enter sex  :   ";
    cin>>sex;
    cout<<"\n                                               Enter pin :   ";
    cin>>pin;
    dep:
    cout<<"\n                                               Account starter deposit amount(min 25) :   ";
    cin>>balance;
    if(balance< 25) {goto dep;}
    acc = accNumStart++;
    cout<<"\n\n                                               Account successfully created. your account number is "<<acc<<"\n\n";

    addAcc(name, acc, sex, pin, balance);
}
void deleteAccount(){
    cout<<"\n                                               Enter Account number to be deleted   :    ";
    int acc;
    Account *temp1;
    Account *temp2;
    bool deleted = false;
    cin>>acc;
    if(head->account_number == acc){
        temp1 = head;
        head = temp1->next;
        deleted = true;
    } else {
        temp1 = head->next;
        temp2 = head;
    }

    while(temp1 != NULL && !deleted){
        if(temp1->account_number == acc){
            temp2->next = temp1->next;
            deleted = true;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if(deleted){
        cout<<"\n                                               Account deleted successfully \n";
    } else cout<<"\n                                               Account not found \n";

}
void searchAccount(){
    Account *temp = new Account;
    temp = head;
    if(head == NULL){
        cout<<"\n                                               There is no data ! ";
        return;
    }
    int acn;
    cout<<"\n                                               Enter the account number you are searching for :   ";
    cin>>acn;
    while(temp != NULL){
        if(temp->account_number == acn){
            cout<<"\t                                               Name \t\t AccNum   \tGender \t Balance \n";
            cout<<"\t                                               "<<temp->name<<"\t\t"<<temp->account_number<<"\t\t"<<temp->gender<<"\t\t"<<temp->account_balance<<endl;
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\n                                               Account doesn't exist! \n";
    }
}
void showAllAccount(){
    Account *temp = head;
    if(head == NULL){
        cout<<"\n                                               No account data! \n";
    } else {
        cout<<"\t\t                                               Name \t\t AccNum   \tGender \t Balance \n";
        int i = 1;
        while(temp != NULL){
            cout<<"\t                                               "<<i<<", "<<temp->name<<"\t\t"<<temp->account_number<<"\t\t"<<temp->gender<<"\t\t"<<temp->account_balance<<endl;
            temp = temp->next;
            i++;
        }
        cout<<endl<<endl;
    }
    delete temp;
}
void editAccount(){
    Account *temp = new Account;
    temp = head;
    if(head == NULL){
        cout<<"\n                                               There is no data! \n";
        return;
    }
    int acn;
    cout<<"\n                                               Enter the account number you wanted to edit:   ";
    cin>>acn;
    while(temp != NULL){
        if(temp->account_number == acn){
                cout<<"\n                                               Enter Name :   ";
                getline(cin>>ws, temp->name);
                cout<<"\n                                               Enter sex  :   ";
                cin>>temp->gender;
                cout<<"\n                                               Enter pin :   ";
                cin>>temp->pin;
                cout<<"\n                                               Account data successfully updated! \n";
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\n                                               Account doesn't exist! \n";
    }
}
void showAccountLog(){
    Account *temp = new Account;
    temp = head;
    if(head == NULL){
        cout<<"\n                                               There is no data! \n";
        return;
    }
    int acn;
    cout<<"\n                                               Enter the account number you wanted to show log info:   ";
    cin>>acn;
    while(temp != NULL){
        if(temp->account_number == acn){
                for(int i=0; i<= temp->index; i++){
                    cout<<temp->history[i]<<endl;
                }
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\n                                               Account doesn't exist! \n";
    }
}


void deposit(){
    Account *temp = new Account;
    temp = head;
    if(head == NULL){
        cout<<"\n                                               There is no data ! ";
        return;
    }
    int acn;
    cout<<"\n                                               Enter the account number you want to deposit for :   ";
    cin>>acn;
    while(temp != NULL){
        if(temp->account_number == acn){
            cout<<"\n                                               Enter the amount   :   ";
            float dep;
            cin>>dep;
            temp->account_balance += dep;
            temp->history[temp->index++] = to_string(dep) + " birr deposited";
            cout<<"\n                                               Successfully deposited ";
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\n                                               Account doesn't exist! \n";
    }
}
void withdraw(){
    Account *temp = new Account;
    temp = head;
    if(head == NULL){
        cout<<"\n                                               There is no data ! ";
        return;
    }
    int acn;
    cout<<"\n                                               Enter the account number you want to withdraw from :   ";
    cin>>acn;
    while(temp != NULL){
        if(temp->account_number == acn){
            cout<<"\n                                               Enter the amount   :   ";
            float withd;
            cin>>withd;
            if(temp->account_balance >= withd){
                temp->account_balance -= withd;
                temp->history[temp->index++] = to_string(withd) + " birr credited";
                cout<<"\n                                               Successfully credited ";
            } else {
                cout<<"\n                                               The account doesn't have enough money \n";
            }
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\n                                               Account doesn't exist! \n";
    }
}
void transfer(){
    Account *temp = new Account;
    Account *t = new Account;
    temp = head;
    t = head;
    if(head == NULL){
        cout<<"\n                                               There is no data ! ";
        return;
    }
    int acn;
    cout<<"\n                                               Enter the account number you want to transfer from :   ";
    cin>>acn;
    while(temp != NULL){
        if(temp->account_number == acn){
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"\n                                               Account doesn't exist! \n";
        return;
    }
    int acn2;
    cout<<"\n                                               Enter the receiver's account number    :   ";
    cin>>acn2;
    if(acn == acn2) {
        cout<<"\n                                               You can't transfer for your own account\n";
        return;
    }
    while(t != NULL){
        if(t->account_number == acn2){
            break;
        }
        t = t->next;
    }
    if(t == NULL){
        cout<<"\n                                               Receiver account doesn't exist \n";
        return;
    }
    cout<<"\n                                               Enter the amount you want to transfer  :   ";
    float amount;
    cin>>amount;
    if(temp->account_balance >= amount){
        temp->account_balance -= amount;
        t->account_balance += amount;
        temp->history[temp->index++] = to_string(amount) + " birr transferred to account " + to_string(acn2);
        t->history[t->index++] = to_string(amount) + " birr received from account " + to_string(acn);
        cout<<"\n                                               Successfully transferred ";
    } else {
        cout<<"\n                                               The account doesn't have enough money for transfer \n";
    }
}


/////////// helper functions
void addAcc(string name, int accNum, char gen, int p, float bl){
    Account *acc = new Account;
    acc->name = name;
    acc->account_number = accNum;
    acc->gender = gen;
    acc->pin = p;
    acc->account_balance = bl;
    acc->history[acc->index++] = to_string(bl) + " birr deposited";

    acc->next = NULL;
    if(head == NULL){
        head = acc;
    } else {
        acc->next = head;
        head = acc;
    }
}

bool checkAdminLogin(){
    cout<<"\n                                               Enter password    :   ";
    int pass;
    cin>>pass;
    return pass == adminPassword;
}
bool checkStaffLogin(){
    cout<<"\n                                               Enter password    :    ";
    int pass;
    cin>>pass;
    return pass == staffPassword;
}


void mobileCheckBalance(int acc){
    Account *temp = new Account;
    temp = head;
    while(temp != NULL){
        if(temp->account_number == acc){
            cout<<"\n                                               Your account balance is "<<temp->account_balance<<" birr \n";
            break;
        }
        temp = temp->next;
    }
}
void mobileTransfer(int acc){
    Account *temp = new Account;
    Account *t = new Account;
    temp = head;
    t = head;
    while(temp != NULL){
        if(temp->account_number == acc){
            break;
        }
        temp = temp->next;
    }
    int acn2;
    cout<<"\n                                               Enter the receiver's account number    :   ";
    cin>>acn2;
    if(acc == acn2) {
        cout<<"\n                                               You can't transfer for your own account\n";
        return;
    }
    while(t != NULL){
        if(t->account_number == acn2){
            break;
        }
        t = t->next;
    }
    if(t == NULL){
        cout<<"\n                                               Receiver account doesn't exist \n";
        return;
    }
    cout<<"\n                                               Enter the amount you want to transfer  :   ";
    float amount;
    cin>>amount;
    if(temp->account_balance >= amount){
        temp->account_balance -= amount;
        t->account_balance += amount;
        temp->history[temp->index++] = to_string(amount) + " birr transferred to account " + to_string(acn2);
        t->history[t->index++] = to_string(amount) + " birr received from account " + to_string(acc);
        cout<<"\n                                               Successfully transferred ";
    } else {
        cout<<"\n                                               The account doesn't have enough money for transfer \n";
    }
}
void payUtility(int acc){
    cout<<"\n                                               Enter the till number  :   ";
    int till;
    float amount;
    cin>>till;
    cout<<"\n                                               Enter amount   :   ";
    cin>>amount;
    Account *temp = new Account;
    temp = head;
    while(temp != NULL){
        if(temp->account_number == acc){
            if(temp->account_balance > amount){
                temp->account_balance -= amount;
                temp->history[temp->index++] = to_string(amount) + " birr payed to till number code " + to_string(till);
                cout<<"\n                                               Successfully paid \n";
            }
            break;
        }
        temp = temp->next;
    }


}
void mobileCheckHistory(int acc){
    Account *temp = new Account;
    temp = head;
    while(temp != NULL){
        if(temp->account_number == acc){
          for(int i=0; i<= temp->index; i++)
              cout<<temp->history[i]<<endl;
         break;
        }
        temp = temp->next;
    }
}

int checkMobileLogin(){
    cout<<"\n                                               Enter Account number   :   ";
    int acNum,paswd;
    cin>>acNum;
    cout<<"\n                                               Enter Password     :   ";
    cin>>paswd;
    Account *temp = new Account;
    temp = head;
    while(temp != NULL){
        if(temp->account_number == acNum){
            if(temp->pin == paswd){
                return acNum;
            } else {
                return -1;
            }
        }
        temp = temp->next;
    }
    return -1;
}
