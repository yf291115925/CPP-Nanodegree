// Example solution for creating a BankAccount class
#include <iostream>
#include <string>

class BankAccount
{
  private:
      // Class attributes:
      
      long int number;
      std::string owner;
      float amount;

  public:
      // Set  methods:
      void setNumber(long int number);
      void setOwner(std::string owner);
      void setAmount(float amount);
      // Get methods:
      long int getNumber() const;
      std::string getOwner() const;
      float getAmount() const;
};

// Implementation of Set methods:
void BankAccount::setNumber(long int number) {
    // Changing attribute to incoming value
    BankAccount::number = number;
}

void BankAccount::setOwner(std::string owner) {
    BankAccount::owner = owner;
}

void BankAccount::setAmount(float amount) {
    BankAccount::amount = amount;
}

// Implementation of Get methods:
long int BankAccount::getNumber() const {
    // Getting specified attribute
    return BankAccount::number;
}

std::string BankAccount::getOwner() const {
    return BankAccount::owner;
}

float BankAccount::getAmount() const {
    return BankAccount::amount;
}

// main function
int main(){
  BankAccount ba;
  ba.setAmount(100);

  std::cout << ba.getAmount() << std::endl;
}