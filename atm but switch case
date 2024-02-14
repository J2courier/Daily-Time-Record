#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define p printf
#define s scanf
#define g gotoxy

void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x - 1; // Adjust for zero-based indexing
  coord.Y = y - 1; // Adjust for zero-based indexing
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main (){
    int ctr = 1, choice, current_bal = 10000, withdraw, deposit;
    char input_pass[50], pass, ans;
    system("cls"); //clrscr();
    loop:
    while (ctr < 4) {
        g(2,2);p("Enter Password: ");
        g(20,2);gets(input_pass);
        pass = strcmp(input_pass, "memeshe"); 
        if (pass == 0){
            ask:
            system("cls"); //clrscr();
            g(15, 3);p("Welcome to Bank ABC");
            g(15, 4);p("Main Menu");
            g(2, 5);p("[1] Balance");
            g(2, 6);p("[2] Withdraw");
            g(2, 7);p("[3] Deposit");
            g(2, 8);p("[4] Exit");
            g(2, 9);p("Enter Choice: ");
            choice:
            g(20, 9);s("%d", &choice);
            if (choice > 0 && choice < 5){
                if (choice == 1){
                    system("cls"); //clrscr();
                    g(15, 2);p("BALANCE");
                    g(2, 3);p("Current Balance: %d", current_bal);
                    g(2, 4);p("Press Enter [Back to Main Menu] ");
                    getch();
                    goto ask;
                }
                else if (choice == 2){
                    system("cls"); //clrscr();
                    g(15, 2);p("WITHDRAW");
                    g(2, 4);p("Enter Amount to Withdraw: ");
                    amount:
                    g(28, 4);s("%d", &withdraw);
                    if (withdraw % 100 == 0){
                        if (current_bal != 500 && withdraw < current_bal){
                                current_bal = current_bal - withdraw;
                                g(2, 5);p("Withdraw Success!");
                                g(2, 6);p("Withdraw Amount: %d", withdraw);
                                g(25, 6);p("Current Balanace: %d", current_bal);
                                g(2, 7);p("Press Enter [Back to Main Menu] ");
                                getch();
                                goto ask;
                            }  
                        else if (withdraw == current_bal){
                            g(2, 3);p("Invalid amount of withdraw! There must be at least PHP 500 left!");  
                        }   
                        else {
                            g(2, 3);p("You can't withdraw the remaining amount");
                            g(2, 4);p("Press Enter [Back to Main Menu] ");
                                getch();
                                goto ask;
                        }
                    }
                    else {
                        g(2, 15);p("Invalid amount");
                        g(28, 4);p("             ");
                        goto amount;
                        }
                }
                else if (choice == 3){
                    system("cls"); //clrscr();
                    g(15, 2);p("Deposit");
                    g(2, 4);p("Enter Amount to Deposit: ");
                     deposit_amount:
                    g(29, 4);s("%d", &deposit);
                    if (deposit % 100 == 0){
                        current_bal = deposit + current_bal;
                        g(2, 5);p("Deposit Success!");
                        g(25, 5);p("Curren Balance: %d", current_bal);
                        g(2, 6);p("Deposit amount: %d", deposit);
                        g(2, 7);p("Press Enter [Back to Main Menu] ");
                        getch();
                        goto ask;
                    }
                    else{
                         g(2, 15);p("Invalid amount");
                        g(28, 4);p("             ");
                        goto amount;
                    }
                    
                }
                else if (choice == 4){
                    system("cls"); //clrscr();
                    g(15, 2);p("EXITED.");
                    exit (0);
                }
            }
            else{
                g(2, 14);p("INVALID INPUT");
            }
        }
        else {
            if (ctr == 1){
                g(2, 3);p("wrong password please try again! ATTEMP: %d", ctr);
                ctr = ctr + 1;
                g(20,2);p("              ");
                goto loop;
            }
             else if (ctr == 2){
                system("cls"); //clrscr();
                g(2, 3);p("WRONG PASSWORD!! ATTEMP: %d", ctr);
                g(2, 4);p("THIS IS YOUR LAST ATTEMP PLEASE TRY AGAIN.");
                ctr = ctr + 1;
                g(20,2);p("              ");
                goto loop;
            }
            else {
                system("cls"); //clrscr();
                g(15, 2);p("EXITED.");
                exit (0);
            }
            
        }

    }
}
