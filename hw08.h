/**********************************************************
 * Leonardo Herrera * CS1B TTH 7:30 - 9:40 * Assignment 8 *
 * hw08 * Due : Tuesday , April 23rd, 2024                *
 *********************************************************/

#ifndef _H_
#define _H_

/**********************************************************
 *program name and description                            *
 **********************************************************/

#include <iostream>
#include <string>
#include <fstream>

#include "hw08.h"

/*

Base Class

*/
class bankAccount
{
  public:

  void set_name(const std::string userName)
  {
    name = userName;
  }
  void set_acct_num(const double acctNum)
  {
    accountNumber = acctNum;
  }
  void set_balance(double ammount)
  {
    balance = ammount;
  }
  void set_interest_rate(double ammount)
  {
    interestRate = ammount / 100;
  }
  double get_interest_rate()
  {
    return interestRate;
  }

  virtual double make_deposit(double deposit)
  {
    balance = balance + deposit;
    return balance;
  }

  virtual double make_withdrawl(double withdrawl)
  {
    balance = balance - withdrawl;
    return balance;
  }

  virtual void print_statement()
  {
    std::cout << "***********\nACCOUNT STATEMENT\n***********\n";
    std::cout << "The name of this ammount is: " << name << ".\n";
    std::cout << "Account numer: " << accountNumber << ".\n";
    std::cout << "Your balance is: $" << balance << ".\n";
  }

  virtual double getBalance()
  {
    return balance;
  };

  void calculate_interest(int month)
  {
    double interestRate = bankAccount::get_interest_rate();
    double temp = getBalance() * (interestRate/12) * month;

    std::cout << "your interest rate is ";
    std::cout << interestRate << ".\nIf you store your money for " << month;
    std::cout << " months you will accumulate $" << temp << ".\n";

  }

  private:
  
  double balance;
  std::string name;
  double accountNumber;
  double interestRate;
};

/*

Checking bank account

*/
class checkingAccount : public bankAccount
{
  public:

  double writeCheckMax;
  double monthlyServiceCharge;
  double minBalance;
  double minBalanceFee;
  

  void writeCheck(double checkAmmount)
  {
    double balance = checkingAccount::getBalance();
    balance -= checkAmmount;

    if(balance > minBalance)
    {
      std::cout << "\nworked.\n";
      checkingAccount::set_balance(balance);
      // return balance;
    } else
    {
      balance -= minBalanceFee;
      std::cout << "Balance is now below minimum.\nBelow min balance Fee of $";
      std::cout << minBalanceFee << " charged.\nYour new balance is $" << balance << ".\n";
      checkingAccount::set_balance(balance);
      // return balance;
    }
  }

  void set_service_charge(double ammount)
  {
    minBalanceFee = ammount;
  }
};




class certificateOfDeposit : public bankAccount
{
  private:
  double penalty;
  int months = 6;

};




class savingsAccount : public bankAccount
{
  private: 
  double minBalance;
  int month;


  public:
  void set_min_balance(double ammount)
  {
    minBalance = ammount;
  }

  void print_statement() override
  {
    bankAccount::print_statement();
    std::cout << "Your interest rate is: " << bankAccount::get_interest_rate() << "%\n";
  }

  
};

#endif