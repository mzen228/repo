// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
        cout.precision(2);
        cout << fixed;

        // Account frank{"Frank", 5000};         // should not compile
// cout << frank << endl;

        Checking_Account frank{ "Frank", 5000 };
        cout << frank << endl;

        Account* trust = new Trust_Account("James");
        cout << *trust << endl;

        Account* p1 = new Checking_Account("Larry", 10000);
        Account* p2 = new Savings_Account("Moe", 1000);
        Account* p3 = new Trust_Account("Curly");

        std::vector<Account*> accounts{ p1,p2,p3 };

        display(accounts);
        deposit(accounts, 1000);
        withdraw(accounts, 2000);

        display(accounts);

        delete p1;
        delete p2;
        delete p3;
        return 0;

    //Checking_Account c; 
    //std::cout << c << std::endl;

    //Savings_Account s("Frank", 5000, 2.6);
    //std::cout << s << std::endl;

    //s.deposit(10000);

    //std::cout << s << std::endl;

    //s.withdraw(10000);

    //std::cout << s << std::endl;

    //Account* ptr = new Trust_Account("Leo", 10000, 2.6);

    //std::cout << *ptr << std::endl;
   
    /*
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);*/
    
    // Savings 
    
    //std::vector<Account*> sav_accounts;

    //Account* s1 = new Savings_Account();
    //Account* s2 = new Savings_Account("Superman");
    //Account* s3 = new Savings_Account("Batman", 2000);
    //Account* s4 = new Savings_Account("Wonder", 5000, 5.0);

    //sav_accounts.push_back(s1);
    //sav_accounts.push_back(s2);
    //sav_accounts.push_back(s3);
    //sav_accounts.push_back(s4); 

    
    //vector<Account*> sav_accounts;

    //Savings_Account s1();
    //Savings_Account s2("Superman");
    //Savings_Account s3("Batman", 2000);
    //Savings_Account s4("Wonder", 5000, 5.0); 

    ////sav_accounts.push_back(&s1);
    //sav_accounts.push_back(&s2); 
    //sav_accounts.push_back(&s3);
    //sav_accounts.push_back(&s4);

  /*  sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );*/

    //display(sav_accounts);
    //deposit(sav_accounts, 1000);
    //withdraw(sav_accounts,2000);
   
   // Checking
   /*
    std::vector<Account*> check_accounts;

    Account* c1 = new Checking_Account();
    Account* c2 = new Checking_Account("Kirk");
    Account* c3 = new Checking_Account("Spock", 2000);
    Account* c4 = new Checking_Account("Bones", 5000);

    check_accounts.push_back(c1);
    check_accounts.push_back(c2);
    check_accounts.push_back(c3);
    check_accounts.push_back(c4); 


    //vector<Checking_Account> check_accounts;
    //check_accounts.push_back(Checking_Account {} );
    //check_accounts.push_back(Checking_Account {"Kirk"} );
    //check_accounts.push_back(Checking_Account {"Spock", 2000} );
    //check_accounts.push_back(Checking_Account {"Bones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);*/
    
    // Trust
    
    //vector<Trust_Account*> trust_accounts;
    //trust_accounts.push_back(Trust_Account {} );
    //trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0} );
    //trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0} );
    //trust_accounts.push_back(Trust_Account {"Aramis", 30000} );

    /*std::vector<Account*> trust_accounts;

    Account* p1 = new Trust_Account();
    Account* p2 = new Trust_Account("Athos", 10000, 5.0);
    Account* p3 = new Trust_Account("Porthos", 2000, 4.0);
    Account* p4 = new Trust_Account("Aramis", 30000);

    trust_accounts.push_back(p1); 
    trust_accounts.push_back(p2); 
    trust_accounts.push_back(p3);
    trust_accounts.push_back(p4); 

    display(trust_accounts);*/
    //deposit(trust_accounts, 1000);
    //withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    //for (int i=1; i<=5; i++)
        //withdraw(trust_accounts, 1000);
    
    
    
    //return 0;
}

