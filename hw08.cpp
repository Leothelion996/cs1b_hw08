#include "hw08.h"

int main() 
{
    bankAccount acctOne;
    
    double temp;
    std::string name;

    acctOne.set_name("account One / Base class");
    acctOne.set_acct_num(550001);
    acctOne.set_balance(500.01);
    acctOne.make_deposit(30.99);
    acctOne.make_withdrawl(500);
    acctOne.print_statement();

    checkingAccount acctTwo;
    acctTwo.set_name("account Two / Checking");
    acctTwo.set_acct_num(50500020);
    acctTwo.set_balance(200);
    acctTwo.set_service_charge(7.99);
    acctTwo.minBalance = 150;
    acctTwo.print_statement();
    acctTwo.writeCheck(60);
    acctTwo.print_statement();

    savingsAccount acctThree;
    acctThree.set_name("Account Three / Savings");
    acctThree.set_acct_num(550003);
    acctThree.set_balance(600);
    acctThree.set_interest_rate(6);
    acctThree.calculate_interest(12);
    acctThree.print_statement();





    // std::cout << "\nwhat is the name of this account?\n";
    // std::cin >> name;    

}