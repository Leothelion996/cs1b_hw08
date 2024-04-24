#include "hw08.h"

int main() 
{
    bankAccount acctOne;
    
    double temp;
    std::string name;

    acctOne.set_name("account One / Base class");
    acctOne.set_acct_num(550001);
    acctOne.set_balance(500.01);
    temp = acctOne.getBalance();
    std::cout << "Balance: $" << temp << "\n";
    acctOne.make_deposit(30.99);
    acctOne.make_withdrawl(500);
    acctOne.print_statement();

    checkingAccount acctTwo;
    acctTwo.set_name("Service Charge / Checking");
    acctTwo.set_acct_num(550002);
    acctTwo.set_balance(200);
    acctTwo.set_min_balance_fee(7.99);
    acctTwo.set_service_charge(2.99);
    acctTwo.set_interest_rate(0);
    temp = acctTwo.get_Check_Max();
    std::cout <<  "Ammount of checks left this month: " << temp << ".\n";

    temp = acctTwo.getBalance();
    std::cout << "Balance: $" << temp << "\n";

    acctTwo.minBalance = 150;
    acctTwo.writeCheck(60);
    acctTwo.print_statement();

    checkingAccount acctThree;
    acctThree.set_name("No Service Charge / Checking");
    acctThree.set_acct_num(550003);
    acctThree.set_balance(400);
    acctThree.set_min_balance_fee(5.99);
    acctThree.set_service_charge(0);
    acctThree.set_interest_rate(2);
    acctThree.set_check_max(100);
    temp = acctThree.get_Check_Max();
    std::cout <<  "Ammount of checks left this month: " << temp << ".\n";

    temp = acctThree.getBalance();
    std::cout << "Balance: $" << temp << "\n";

    acctThree.minBalance = 200;
    acctThree.writeCheck(60);
    acctThree.print_statement();

    savingsAccount acctFour;
    acctFour.set_name("Savings Account");
    acctFour.set_acct_num(550004);
    acctFour.set_balance(600);
    acctFour.set_interest_rate(6);
    acctFour.set_month(8);
    acctFour.set_min_balance(0);
    acctFour.print_statement();
    acctFour.make_withdrawl(50);
    acctFour.make_deposit(150);
    acctFour.print_statement();

    savingsAccount acctFive;
    acctFive.set_name("High interest Savings Account");
    acctFive.set_acct_num(550005);
    acctFive.set_balance(2500);
    acctFive.set_interest_rate(1000);
    acctFive.set_month(6);
    acctFive.set_min_balance(2000);
    acctFive.print_statement();
    acctFive.make_withdrawl(50);
    acctFive.make_deposit(150);
    acctFive.print_statement();

    certificateOfDeposit certOne;
    certOne.set_name("certificate Of Deposit Account");
    certOne.set_acct_num(550006);
    certOne.set_balance(10000);
    certOne.set_interest_rate(4000); //interest is calculated by dividing by 100
    certOne.set_penalty(60);
    certOne.set_current_month(10);
    certOne.print_statement();

    certOne.make_withdrawl(100);
    
    std::cout << "\n\nFast foward to the maturity of CD.\n\n";
    certOne.set_current_month(12);
    certOne.make_withdrawl(200);
    certOne.print_statement();
}