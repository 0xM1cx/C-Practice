#include <iostream>
using namespace std;
#include <string>

int main(){
	// Variables used
	double balance;
	double amount;
	string option;
	
	// Menu
	cout<<"1 Deposit money"<<"\n2 Withdraw money"<<"\n3 Check balance"<<"\n4 Exit"<<"\n\nChoose an option from the menu: ";

	getline(cin, option); // User input

	while ((option != "Exit") || (option != "exit")){
		if (option=="1"){
		  do{
		  	if (balance==3.90312e-322){
				//to avoid printing out 3.90312e-322
				cout<<"\nYour balance is 0";
			} else{
				cout<<"\nCurrent balance: "<<balance;
			}

			cout<<"\nEnter an amount: ";
			cin>>amount;
			balance=balance+amount;
			if (balance==3.90312e-322){
				//to avoid printing out 3.90312e-322
				cout<<"\nYour new balance is 0";
			    }
		    else{
				cout<<"\nNew balance: "<<balance;
			}
			cout<<"\n\n1 Deposit money"<<"\n2 Withdraw money"<<"\n3 Check balance"<<"\n4 Exit"<<"\n\nChoose an option from the menu: ";
			cin>>option;
		  }while ((option=="Deposit money") || (option=="deposit money") || (option=="Deposit") || (option=="deposit") || (option=="1"));
	    }
	
 	    else if ((option=="Withdraw money") || (option=="withdraw money") || (option=="Withdraw") || (option=="withdraw") || (option=="2")){
		  do{
		  	if (balance==3.90312e-322){
				//to avoid printing out 3.90312e-322 and so that the user can see how much money they can withdraw
				cout<<"\nYour balance is 0";
			    }
		    else{
				cout<<"\nCurrent balance: "<<balance;
			}
			cout<<"\nEnter the amount of money you want to withdraw : ";
			cin>>amount;
			if (amount<=balance){
				balance=balance-amount;
				if (balance==3.90312e-322){
				//to avoid printing out 3.90312e-322
				cout<<"\nYour new balance is 0";
			    }
			    else{
				  cout<<"\nNew balance: "<<balance;
			    }
			}
			else{
				cout<<"\nError. Insufficient balance.";
				cout<<"\nBalance: "<<balance;
			}
			cout<<"\n\n1 Deposit money"<<"\n2 Withdraw money"<<"\n3 Check balance"<<"\n4 Exit"<<"\n\nChoose an option from the menu: ";
			cin>>option;
		  }while ((option=="Withdraw money") || (option=="withdraw money") || (option=="Withdraw") || (option=="withdraw") || (option=="2"));
	    }
	
	    else if ((option=="Check balance") || (option=="check balance") || (option=="Balance") || (option=="balance") || (option=="Check") || (option=="check") || (option=="3")){
		  do{
			
			if (balance==3.90312e-322){
				//to avoid printing out 3.90312e-322
				cout<<"\nYour balance is 0";
			}
			else{
				cout<<"\nYour balance is: "<<balance;
			}
			cout<<"\n\n1 Deposit money"<<"\n2 Withdraw money"<<"\n3 Check balance"<<"\n4 Exit"<<"\n\nChoose an option from the menu: ";
			cin>>option;
		  }while ((option=="Check balance") || (option=="check balance") || (option=="Balance") || (option=="balance") || (option=="Check") || (option=="check") || (option=="3"));
	    }
	    else if ((option=="Exit") || (option=="exit") || (option=="4")){
	    	cout<<"\nThank you";
	    	return 0;
		}
	}
	return 0;
}
