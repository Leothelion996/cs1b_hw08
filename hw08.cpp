#include "hw08.h"

int main() 
{
    bankAccount acctOne;

    acctOne.set_balance(500.01);
    acctOne.print_statement();
    acctOne.make_deposit(30.99);
    acctOne.print_statement();
    acctOne.make_withdrawl(500);
    acctOne.print_statement();
}