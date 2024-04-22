#include "hw08.h"

int main() 
{
    bankAccount acctOne;
    
    double temp;
    std::string name;

    acctOne.set_balance(500.01);
    acctOne.make_deposit(30.99);
    acctOne.make_withdrawl(500);
    acctOne.print_statement();

    checkingAccount acctTwo;
    std::cout << "account 2\n";
    acctTwo.minBalance = 150;
    acctTwo.set_service_charge(7.99);
    acctTwo.set_balance(200);
    acctTwo.print_statement();
    acctTwo.writeCheck(60);
    acctTwo.print_statement();

    savingsAccount acctThree;
    std::cout << "account 3\nwhat is the name of this account?\n";
    getline(std::cin, name);
    acctThree.set_name(name);
    acctThree.set_acct_num(550003);
    acctThree.set_balance(600);
    acctThree.set_interest_rate(6);
    acctThree.calculate_interest(12);
    acctThree.print_statement();



    // std::cout << "\nwhat is the name of this account?\n";
    // std::cin >> name;    

}