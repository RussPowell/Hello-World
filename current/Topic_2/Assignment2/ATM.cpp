/*
 * Name        : ATM.cpp, assignment 2
 * Author      : Russell Powell
 * Description : This is the access point to all the Bank and,
 *               all accounts therein.
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BankAccounts.h"
#include "Checking.h"
#include "Savings.h"
#include "Credit_Card.h"


// To Test for Correct Header Guards

TEST_CASE("Accounts Class") 
{
  SECTION("Default Constructor") 
  {
    Accounts accounts;
    CHECK(accounts.balance() == 0);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.ToString() == "0.00, 0.00, 0.00");
  }

  SECTION("Overloaded Constructor") 
  {
    Accounts accounts(10000, 500, 1500);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 500);
    CHECK(accounts.withdrawl() == 1500);
    CHECK(accounts.ToString() == "10000.00, 500.00, 1500.00");
  }

}

TEST_CASE("Checking Class") 
{
  SECTION("Default Constructor") 
  {
    Checking accounts;
    CHECK(accounts.balance() == 0);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.fees() == 3);
    CHECK(accounts.ToString() == "0.00, 0.00, 0.00, 3.00");
  }

  SECTION("Overloaded Constructor(10000, 0, 500)") 
  {
    Checking accounts(10000, 0, 500);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 500);
    CHECK(accounts.fees() == 3);
    CHECK(accounts.ToString() == "10000.00, 0.00, 500.00, 3.00");
  }
  
SECTION("Overloaded Constructor(10000, 1500, 0)") 
  {
    Checking accounts(10000, 1500, 0);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 1500);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.fees() == 3);
    CHECK(accounts.ToString() == "10000.00, 1500.00, 0.00, 3.00");
  }

}

TEST_CASE("Credit_Card Class") 
{
  SECTION("Default Constructor") 
  {
    Credit_Card accounts;
    CHECK(accounts.balance() == 0);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.interest() == 16);
    CHECK(accounts.ToString() == "0.00, 0.00, 0.00, 16.00");
  }

  SECTION("Overloaded Constructor(10000, 0, 500)") 
  {
    Credit_Card accounts(10000, 0, 500);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 500);
    CHECK(accounts.interest() == 16);
    CHECK(accounts.ToString() == "10000.00, 0.00, 500.00, 16.00");
  }
  
  SECTION("Overloaded Constructor(10000, 1500, 0)") 
  {
    Credit_Card accounts(10000, 1500, 0);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 1500);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.interest() == 16);
    CHECK(accounts.ToString() == "10000.00, 1500.00, 0.00, 16.00");
  }

}

TEST_CASE("Savings Class") 
{
  SECTION("Default Constructor") 
  {
    Savings accounts;
    CHECK(accounts.balance() == 0);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.interest() == 2);
    CHECK(accounts.ToString() == "0.00, 0.00, 0.00, 2.00");
  }

  SECTION("Overloaded Constructor(10000, 0, 500)") 
  {
    Savings accounts(10000, 0, 500);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 0);
    CHECK(accounts.withdrawl() == 500);
    CHECK(accounts.interest() == 2);
    CHECK(accounts.ToString() == "10000.00, 0.00, 500.00, 2.00");
  }
  
  SECTION("Overloaded Constructor(10000, 1500, 0)") 
  {
    Savings accounts(10000, 1500, 0);
    CHECK(accounts.balance() == 10000);
    CHECK(accounts.deposit() == 1500);
    CHECK(accounts.withdrawl() == 0);
    CHECK(accounts.interest() == 2);
    CHECK(accounts.ToString() == "10000.00, 1500.00, 0.00, 2.00");
  }

}