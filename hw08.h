/**********************************************************
 * Leonardo Herrera * CS1B TTH 7:30 - 9:40 * Assignment 6 *
 * hw06 * Due : Tuesday , March 25th, 2024                *
 *********************************************************/

#ifndef _H_
#define _H_

/**********************************************************
 *program name and description                            *
 **********************************************************/

#include <iostream>
#include <string>
#include <fstream>

class bankAccount 
{
  private:

  std::string name;
  double accountNumber;
  double balance;

  public:

  void set_name(std::string userName)
  {
    name = userName;
  }
  void set_acct_num(double acctNum)
  {
    accountNumber = acctNum;
  }
  void set_balance(double ammount)
  {
    balance = ammount;
  }

  double make_deposit(double deposit)
  {
    balance = balance + deposit;
    return balance;
  }

  double make_withdrawl(double withdrawl)
  {
    balance = balance - withdrawl;
    return balance;
  }

  void print_statement()
  {
    std::cout << "Your balance is: " << balance << ".\n";
  }
};

class checkingAccount : public bankAccount
{
  public:
  
  
}



#endif