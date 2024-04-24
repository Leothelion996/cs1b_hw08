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
    return interestRate / 100;
  }
  double getBalance()
  {
    return balance;
  };
  std::string get_name()
  {
    return name;
  }
  double get_account_number()
  {
    return accountNumber;
  }


  virtual double make_deposit(double deposit)
  {
    balance = balance + deposit;
    std::cout << "making a deposit of $" << deposit <<"\n";
    return balance;
  }

  virtual double make_withdrawl(double withdrawl)
  {
    std::cout << "making a withdrawl of $" << withdrawl << "\n";
    balance = balance - withdrawl;
    return balance;
  }

  void print_statement()
  {
    std::cout << "***********\nACCOUNT STATEMENT\n***********\n";
    std::cout << "Account Name: " << name << ".\n";
    std::cout << "Account numer: " << accountNumber << ".\n";
    std::cout << "Your balance is: $" << balance << ".\n";
    if(interestRate > 0)
    {
      std::cout <<  "Your interest rate is: " << interestRate << "%.\n";
    } else
    {
      std::cout << "this account does not accrude interest.\n";
    }
    // std::cout << "************End**********\n\n";
  }

  virtual void calculate_interest(int month)
  {
    double interestRate = bankAccount::get_interest_rate();
    double monthlyRate = interestRate / 12;
    double principal = getBalance();
    double temp = (principal * (1 + (monthlyRate * month)) - principal);

    if(interestRate > 0)
    {
      

      std::cout << "If you store your money for " << month;
      std::cout << " months you will accumulate $" << temp << ". For a total of $";
      std::cout << principal + temp << ".\n";
    }
    else
    {
      std::cout << "There is no interest on this account.\n";
    }
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

  double writeCheckMax = 5;
  double monthlyServiceCharge;
  double minBalance;
  double minBalanceFee;

  void set_check_max(double ammount)
  {
    writeCheckMax = ammount;
  }

  double get_Check_Max()
  {
    return writeCheckMax;
  }

  void writeCheck(double checkAmmount)
  {
    std::cout << "attempting to write a check for $" << checkAmmount << ".\n";
    double balance = checkingAccount::getBalance();
    balance -= checkAmmount;

    if(writeCheckMax > 0)
    {
      if(balance > minBalance)
      {
        balance -= minBalanceFee;
        std::cout << "\n successfully wrote a check for $" << checkAmmount << "\n";
        checkingAccount::set_balance(balance);
      } else
      {
        balance -= minBalanceFee;
        std::cout << "Balance fell below the minimum of $" << minBalance << ".\nMin balance Fee of $";
        std::cout << minBalanceFee << " charged.\nYour new balance is $" << balance << ".\n";
        checkingAccount::set_balance(balance);
      }
      writeCheckMax--;
    } else 
    {
      std::cout << "You have reached your monthly check maximum\nTransaction failed\n";
    }
  }

  void set_min_balance_fee(double ammount)
  {
    minBalanceFee = ammount;
  }

  void set_service_charge(double ammount)
  {
    monthlyServiceCharge = ammount;
  }

  double get_service_charge()
  {
    return monthlyServiceCharge;
  }

   void print_statement()
  {
    bankAccount::print_statement();
    
    // double interestRate = get_interest_rate();
    int checkMax = get_Check_Max();
    if(checkMax > 50)
    std::cout << "This acount can write unlimited checks.\n";
    else
    {
    std::cout << "Available Checks this month: " << checkMax << ".\n";
    }
    std::cout << "This account has a balance minimum of $" << minBalance << ".\n";
    if(monthlyServiceCharge > 0)
    {
      std::cout << "This account has a service charge of $" << monthlyServiceCharge << ".\n";
    } else 
    {
      std::cout << "This account does not have a monthly Service charge.\n";
    }
  }
};

/*

Certification of Deposit

*/
class certificateOfDeposit : public bankAccount
{
  private:
  double penalty;
  int months = 12;
  int currentMonth;

  public:
    void set_penalty(double ammount)
    {
      // double principal = bankAccount::getBalance();
      penalty = ammount / 100;
    }

    void set_months_to_mature(int matureMonths)
    {
      months = matureMonths;
    }

    void set_current_month(double ammount)
    {
      currentMonth = ammount;
    }

    double make_withdrawl(double withdrawl)
    {
      bankAccount::make_withdrawl(withdrawl);
      double principal = bankAccount::getBalance();
      double temp = principal - (principal * penalty);

      if(currentMonth < months)
      {
        std::cout << "Penalty for early withdrawl will be " << penalty << "%. Which comes out to $";
        std::cout << principal * penalty << ".\n";
        principal = temp;
        return principal;
      } else 
      {
        std::cout << "Withdrew without penalty.\n";
        temp = calculateInterest(months);
        principal = principal + temp;
        return principal;
      }
    }
    
    double calculateInterest(int month) 
  {
    double interestRate = bankAccount::get_interest_rate();
    double monthlyRate = interestRate / 12;
    double principal = getBalance();
    double temp = (principal * (1 + (monthlyRate * month)) - principal);

    if(interestRate > 0)
    {
      return temp;
    }
    else
    {
      return principal;
    }
  }

    void print_statement()
    {
      bankAccount::print_statement();
      double addedTotal = calculateInterest(months);

      //penalty, maturity, current month
      std::cout << "The penalty for early withdral onthis account is: " << penalty << "%\n";
      std::cout << "This account will take " << months << " months to mature.\n";
      if(currentMonth < months)
      {
        std::cout << "You have " << (months - currentMonth) << " months left until maturity.\n";
      } else
      {
        std::cout <<"This account has matured and is ready to pay out $" << addedTotal << ".\n";
        double total = getBalance() + addedTotal;
        set_balance(total);
        std::cout << "your new total is $" << getBalance() << ".\n";
      }
    }
};

/*

Savings Account

*/
class savingsAccount : public bankAccount
{
  private: 
  double minBalance;
  int month;

  public:

  void set_month(int ammount)
  {
    month = ammount;
  }

  void set_min_balance(double ammount)
  {
    minBalance = ammount;
  }

  void print_statement()
  {
    double interestRate = bankAccount::get_interest_rate();
    double interest = bankAccount::get_interest_rate();
    bankAccount::print_statement();
    if(minBalance > 0)
    {
      std::cout << "Account minimum is: $" << minBalance << ".\n";
    } else 
    {
      std::cout << "This account has no Minimum.\n";
    }

    bankAccount::calculate_interest(month);
  }

  
};

#endif