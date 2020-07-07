#include<string>
#include<iostream>
#include "Customer.h"
#include "Branch.h"
class Account
{
private:
   
public:
    Account(std::string customerName_, std::string accountNumber_, std::string customerCpf_ , std::string branchNumber_);
    std::string number;
    Customer customer;
    Branch branch;
    float balance;
    float limit;
    void withdraw(float amount);
    void deposit(float amount);
    void transfer(Account &account, float amount);
};
