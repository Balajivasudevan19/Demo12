#include <iostream>
using namespace std;

class Atm {
private:
  double balance;

public:
  Atm(double initialBalance) : balance(initialBalance) {
      cout<<"Atm pin Matched"<<endl;
  }

  double getBalance() 
  {
      return balance; 
      
  }

  void deposit(double amount) {
    if (amount <= 0) {
      throw ("Invalid deposit amount!");
    }
    balance += amount;
  }

  void withdraw(double amount) {
    if (amount <= 0) {
      throw ("Invalid withdrawal amount!");
    } else if (amount > balance) {
      throw ("Insufficient funds!");
    }
    balance -= amount;
  }
};

int main() {
  Atm myAtm(100.00);

  try {
    myAtm.deposit(50.00);
    cout << "Balance after deposit: " << myAtm.getBalance() << endl;

    myAtm.withdraw(20.00);
    cout << "Balance after withdrawal: " << myAtm.getBalance() << endl;

    
    myAtm.deposit(10.00);
    myAtm.withdraw(-20.00);
    
  } 
   catch (const char* e) {
    cout << "Unexpected error: " << e << endl;
  }

  return 0;
}
