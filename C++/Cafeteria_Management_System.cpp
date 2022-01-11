#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;
//the header file

class CoffeeType	//base class
{
public:

    void take_order();//to  take_order
    void delete_order(); //to delete the order
    void modify(); //to modify the order
	void order_list(); //to display the order_list
	void daily_summary(); //to display daily_summary
	void exit();  //function to exit system
	CoffeeType();//constuctor

};

 CoffeeType::CoffeeType ()
{

}		//constructor for class CarType


struct node //constract node
{
	int receipt_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"Cold"};
	int x, menu2[10];
    double amount[10];
	string coffeeName[10]={"Cafe Latte","Cappuccino","Espresso","Cafe Mocha","Cafe Chai","Cafe Chocolate","Cafe Coffee","Coffee Americano","Cafe Smoothie","Iced Mocha"};
	double coffee[10] = {40.00,30.00,45.00,44.00,36.00,52.00,37.00,23.00,35.00,51.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				//pointer declaration 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()	// Main function
{

	system("COLOR 0");		//Color to change background
	CoffeeType coffee;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Cafeteria Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new coffee order \t\t ||\n";
		cout<<"\t\t||\t2. Delete latest coffee order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				coffee.take_order();	//function add
				break;
			}	//end case 1
		
		
		case 2:
			{
				coffee.delete_order();	//function delete
				system("PAUSE");
				break;
			}	//end case 2
			
		case 3:
			{
				coffee.modify();	//function modify
				system("PAUSE");
				break;
			}	//end case 3

		case 4:
			{
				coffee.order_list();	//function order
				system("PAUSE");
				break;
			}	//end case 4
		case 5:
			{
				coffee.daily_summary();	//function daily_summary
				system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				coffee.exit();	//function exit
				goto a;
				break;
			}	//end case 6

		
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}while(menu!=6);//end do
	a://goto
	cout<<"thank you"<<endl;
	system ("PAUSE");
	return 0;
}//end  main function


void CoffeeType::take_order()		//function to take_order
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"**************************************************************************\n";
				cout<<"Coffee ID"<<"\tCOFFEE TYPE"<<"   \t\tCOFFEE NAME"<<"\t         COFFEE PRICE($)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0101"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cafe Latte"<<"			$ 40.00"<<endl;
                cout<<"0102"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cappuccino"<<"		    	$ 30.00"<<endl;
                cout<<"0103"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Espresso"<<"	     		$ 45.00"<<endl;
                cout<<"0104"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cafe Mocha"<<"		    	$ 44.00"<<endl;
                cout<<"0105"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cafe Chai"<<"	 	    	$ 36.00"<<endl;
                cout<<"0106"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cafe Chocolate"<<" 		$ 52.00"<<endl;
                cout<<"0107"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cafe Coffee"<<"		    	$ 37.00"<<endl;
                cout<<"0108"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Coffee Americano"<<"		$ 23.00"<<endl;//1353fn
                cout<<"0109"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Cafe Smoothie"<<"		$ 35.00"<<endl;
                cout<<"0110"<<"\t"<<"\tCold"<<"\t\t"<<"\t    Iced Mocha"<<"		    	$ 51.00"<<endl;
                cout<<" "<<endl;
				// string coffeeName[10]=["Cafe Latte","Cappuccino","Espresso","Cafe Mocha","Cafe Chai","Cafe Chocolate","Cafe Coffee","Coffee Americano","Cafe Smoothie","Iced Mocha"]
	// double coffee[10] = {40.00,30.00,45.00,44.00,36.00,52.00,37.00,23.00,35.00,51.00};
    
	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->receipt_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many coffee would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The coffee you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "coffee Name: " <<temp->coffeeName[temp->menu2[i]-1]<<endl;
        cout << "How many coffee do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->coffee[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" $"<<endl;
        system("PAUSE");
                      
	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order


void CoffeeType::order_list()		//Function to display receipt
{
	int i, num, num2;	
	bool found;			//variable to search 
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n"; 
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->receipt_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"Reciept Number : "<<temp->receipt_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		cout << "===============================================================================" << endl;
		cout << "|  Coffee Type |     Coffee Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->coffeeName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" $"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}	//End function order_list


void CoffeeType::delete_order()	//function to delete_order
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->receipt_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Receipt is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->receipt_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
}	//End function delete_order



void CoffeeType::modify()		//function to modify order
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->receipt_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->receipt_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New coffee would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The coffee you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change coffee Name: " <<temp->coffeeName[temp->menu2[i]-1]<<endl;
        cout << "How many New coffee do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->coffee[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" $"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->receipt_number != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}		//End modify function



void CoffeeType::daily_summary()		//Function to display Daily Summary
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{
		
				cout <<"Reciept Number : "<<temp->receipt_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;
				
				cout<<"Order Date : "<<temp->date<<endl;
				
				cout<<"____________________________________________________________________________"<<endl;
			
				cout << "==========================================================================" << endl;
				cout << "|  Coffee Type |   Coffee Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->coffeeName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" $"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}		//End daily summary
void CoffeeType::exit() //Function to exit
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	//end function exit


////////////////////////////THE END OF PROGRAM//////////////////////////////////////////
