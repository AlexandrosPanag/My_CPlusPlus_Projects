//This code was designed by Alexandros Panagiotakopoulos


#define CATCH_CONFIG_MAIN
#include "C:\Users\<yourusernamehere>\Desktop/catch.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class account
{
private:
    string name;
    double balance;

public:
    account(string n)
    {
        name=n;
        balance=0.0;
    }

    account(string n, double initial_balance)
    {
        name=n;
        balance=initial_balance;
    }

    string get_name() const
    {
        cout<<"\n\n---------------------------"<<endl;
        cout<<name<<endl;
        return name;
    }

    double get_balance() const
    {
        if(balance!=0)
        {
        cout<<"\n*REQUESTED BALANCE:\n  >balance is:"<<balance<<endl;
        }
        else if(balance==0){
        }
        return balance;
    }

    void deposit(double amount)
    {
        balance+=amount;
    }

    void withdraw(double amount)
    {
        if(amount<balance)
        {
            balance=balance-amount;
            cout<<"*REQUESTED WITHDRAWAL:\n  >balance after withdrawal:"<<balance<<endl;
        }
        else if(amount==balance)
        {
            balance=balance-amount;
        }
        else
        {
            cout<<"*REQUESTED WITHDRAWAL:\n  >!!!ERROR:invalid amount requested: "<<amount<<" current balance is: "<<balance<<endl;
        }
        cout<<"\n------------------------------\n";
    }
};

class bank
{
private:
    vector<account> accounts;

public:
    void add_account(const account &acct)
    {
       accounts.push_back(acct);
    }

    double get_balance(string name) const
    {
            for(int i=0;i<accounts.size();i++)
            {
                if(accounts[i].get_name()==name)
                return accounts[i].get_balance();
            }
        return -1.0;
    }

    void print_accounts() const
    {
        for(int i=0;i<accounts.size();i++) 
        {
            cout<<accounts[i].get_name()<<" "<<accounts[i].get_balance()<<endl;
        }
    }

    void deposit(string name, double amount)
    {
     for(int i=0;i<accounts.size();i++)
        {
        if(accounts[i].get_name()==name)
         {
            accounts[i].deposit(amount);
         }
        }
    }

    void withdraw(string name, double amount)
    {
        for(int i=0;i<accounts.size();i++)
        {
        if(accounts[i].get_name()==name)
         {
            accounts[i].withdraw(amount);
         }
        }
        
    }

    void add_interest(double rate)
    {
        for(int i=0;i<accounts.size();i++)
        {
            accounts[i].deposit(+rate);
        }
    }
};

TEST_CASE("account class test 1", "[account]")
{
    account acct("Christos");
    REQUIRE(acct.get_name() == "Christos");
    REQUIRE(acct.get_balance() == 0.0);
    acct.deposit(50.0);
    REQUIRE(acct.get_balance() == 50.0);
}

TEST_CASE("account class test 2", "[account]")
{
    account acct("Vasilis", 100.0);
    REQUIRE(acct.get_name() == "Vasilis");
    REQUIRE(acct.get_balance() == 100.0);
    acct.withdraw(50.0);
    REQUIRE(acct.get_balance() == 50.0);
    acct.withdraw(70.0);
    REQUIRE(acct.get_balance() == 50.0);
}


TEST_CASE("bank class test", "[bank]")
{
    bank a_bank;
    for (int i = 0; i < 100; i++)
    {
        account acct("customer" + to_string(i), 100.0);
        a_bank.add_account(acct);
    }
    a_bank.deposit("customer42", 50.0);
    a_bank.withdraw("customer42", 10.0);
    REQUIRE(a_bank.get_balance("customer42") == 140.0);
    a_bank.add_interest(1.5);
    REQUIRE(a_bank.get_balance("customer46") == 101.5);
}

// int main()
// {
//   bank a_bank;
//
//     account chr("Christos");
//     account vas("Vasilis", 50.0);
//     a_bank.add_account(chr);
//     a_bank.add_account(vas);
//     a_bank.print_accounts();
//
//     a_bank.deposit("Christos", 10.0);
//     a_bank.deposit("Vasilis", 10.0);
//     a_bank.print_accounts();
//
//     a_bank.add_interest(5.5);
//     a_bank.print_accounts();
//
//     return 0;
// }
