
// Headers file

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<ctype.h>
#include<unistd.h>
#include"dbfile.h"


// It helps us to use standard objects.

using namespace std;


// Global Variables.

int i,j,k;

string username = "username";
string password = "password";


// Prototype Declaration of function's used.

void time();

void a1();
void a2();
void a3();
void a4();
void a5();
void a6();
void a7();

void front_info();

int login(int *count_1);
void login_info();

void menu();
void menu_info();

void order_billing();
void product_list();
void check_quantity();
void search_product();
void update_product_list();
void purchase_details();
void sale_details();
void delete_all_data();
void developer_info();


// fetch the current time from the system and display.

void time()
{
	time_t my_time = time(NULL);

	char *current_time = ctime(&my_time);

	cout<<current_time<<endl;
}

// Small function's from 'a1' to 'a7' helps to display GEU. 

void a1()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=50 || j>=56 && j<=61 || j>=67 && j<=69 || j>=73 && j<=75)
				{
					cout<<"**";
				}
				else if(j>=70 && j<=72)
				{
					cout<<"  ";
				}

				
			}
			cout<<endl;
				sleep(1);
}

void a2()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=47 || j>=56 && j<=57 || j>=67 && j<=69 || j>=73 && j<=75)
				{
					cout<<"**";
				}
				else if(j>=48 && j<=50 || j>=58 && j<=61 || j>=70 && j<=72)
				{
					cout<<"  ";
				}
				
			}
			cout<<endl;
			sleep(1); 
}

void a3()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=47 || j>=56 && j<=61 || j>=67 && j<=69 || j>=73 && j<=75)
				{
					cout<<"**";
				}
				else if(j>=48 && j<=50 || j>=70 && j<=72)
				{
					cout<<"  ";
				}
				
			}
			cout<<endl;
			sleep(1);
}

void a4()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=47 || j>=49 && j<=50 || j>=56 && j<=61 || j>=67 && j<=69 || j>=73 && j<=75)
				{
					cout<<"**";
				}
				else if(j==48 || j>=70 && j<=72)
				{
					cout<<"  ";
				}

			}
			cout<<endl;
			sleep(1);
}

void a5()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=47 || j==50 || j>=56 && j<=57 || j>=67 && j<=69 || j>=73 && j<=75)
				{
					cout<<"**";
				}
				else if(j==48||j==49 || j>=58 && j<=61 || j>=70 && j<=72)
				{
					cout<<"  ";
				}

			}
			cout<<endl;
				sleep(1);
}

void a6()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=50 || j>=56 && j<=61 || j>=67 && j<=75)
				{
					cout<<"**";
				}
				
			}
			cout<<endl;
			sleep(1);
}

void a7()
{
	for(j=1;j<=75;j++)
			{
				if(j>=1 && j<=45 || j>=51 && j<=55 || j>=62 && j<=66)
				{
					cout<<" ";
				}
				else if(j>=46 && j<=50 || j>=56 && j<=61)
				{
					cout<<"**";
				}
				else if(j>=67 && j<=69 || j>=73 && j<=75)
				{
					cout<<"  ";
				}
				else if(j>=70 && j<=72)
				{
					cout<<"**";
				}

			}
			cout<<endl;
			sleep(1);
}


// 'front_info()' function assembles the code to display time and GEU. 

void front_info()
{
	cout<<"\n\n\n";
	sleep(1);	// calling 'sleep()' function. It will make system sleep for 1 sec.
	
	time();		// calling 'time()' function.
	
	cout<<"\n\n\n\n\n";

	sleep(1);
	cout<<"\n\t\t\t\t\t\t\t\" ----- WELCOME TO ----- \"\t\t\t\t\t\t\t\n\n";

	sleep(1);

	for(i=1;i<=10;i++)
	{
		if(i==1 || i==2)
		{
			a1();	// calling 'a1()' function.
		}

		else if(i==3 || i==4)
		{
			a2();	// calling 'a2()' function.
		}

		else if(i==5)
		{
			a3();	// calling 'a3()' function.
		}

		else if(i==6)
		{
			a4();	// calling 'a4()' function.
		}

		else if(i==7 || i==8)
		{
			a5();	// calling 'a5()' function.
		}

		else if(i==9)
		{
			a6();	// calling 'a6()' function.
		}

		else
		{
			a7();	// calling 'a7()' function.
		}

	}


	cout<<"\n\n\t\t\t\t\t\t\t\" ~ CANTEEN MANAGEMENT SYSTEM ~ \"\t\t\t\t\t\t\t\n\n\n";

	sleep(2);

}


// 'login()' function is for checking and entering ---> [ username and password ].

int login(int *count_1)
{
	string user_1;
	string pass_1;


	cout<<"\nPlease Enter the username:"<<endl;
	cin.ignore();  // it will discard the buffer.
	cin>>user_1;
	cout<<"\nPlease Enter the password:"<<endl;
	cin.ignore();
	cin>>pass_1;

	if(username==user_1 && password==pass_1)
	{
		return 1;
	}
	else
	{
		*count_1+=1;	// increasing the 'count_1' variable.
		return 0;

	}
}

// 'login_info()' function consist the main code part for login system.

void login_info()
{
		int count_1 = 0,ot = 0;

		l_2:

		cout<<"\n\nPlease Press 1 to \" Login Into The System \" and Press 0 to \" Exit The Application \".\n\n";

		char choice_1;

		cin>>choice_1;

		switch(choice_1)
		{
			case '1':
					l_1:
					sleep(1);
					system("clear"); // It clears the previous screen content.
					ot = login(&count_1);	// calling 'login()' function.
					if(ot==1)
					{
						sleep(1);
						cout<<"\n\n\" ~~~ Accessed successful ~~~ \"\n\n";
						sleep(1);
						system("clear");
					}
					else
					{
						sleep(1);
						cout<<"\n\n\" ~~~ Access Denied ~~~ \"\n\n";
						sleep(1);
						system("clear");
						while(count_1<3)
						{
							goto l_1;	// using 'goto statement'. It will jump to it's label. 

						}
						if(count_1==3)
						{
							string key;
							sleep(1);
							cout<<"\n\n\" ~~~ You Have Came To Maximum Count, So Try Re-Login Again. ~~~ \"\n\n";
							sleep(1);
							cout<<"\n\n\" ~~~ Please Press Enter To Continue. ~~~ \"\n\n";
							cin.ignore();
							getline(cin,key);
							system("clear");
							login_info();	// calling 'login_info()' function again.
						}
						
					}

					break;
			case '0': sleep(1);
					system("clear");

					char key_1;
					h_3:

					cout<<"\n\n ~~ Do You Want To Continue [y/n] ~~ \n\n";
					cin>>key_1;

					if(islower(key_1))
					{
						key_1 = toupper(key_1);
					}

					switch(key_1)
					{
						case 'Y':	system("clear");
									sleep(1);
									cout<<"\n\n\t\t\t\t\t\t\t\" ~~~ ThankYou For Using The Service ~~~ \"\t\t\t\t\t\t\t\n\n";
									exit(0);	// calling 'exit()' function. It will terminate or end the program.
									
						case 'N':	system("clear");
									goto l_2;
									break;

						default:	sleep(1);
									cout<<"\n\n\" ~~ Please Enter A Valid Choice ~~ \"\n\n";
									sleep(1);
									system("clear");
									goto h_3;
 
					}

					break;
					
			default:sleep(1);
					cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
					sleep(1);
					system("clear");
					goto l_2;				
		}
	
}



// order and billing take place in this function .

void order_billing()
{
		mn:
		database dbobj;
		string x_1;

		cout<<"\n\n\n\t\t\t\t\t\t\" ---------- ORDER AND BILLING ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n\n";

		cout<<"\nPress 1 To Place an Order\n";
		cout<<"\nPress 2 For Billing\n";
		cout<<"\nPress 3 To Get-Back To Main Menu\n";

		char mq;

		cout<<"\n\nPlease Enter Your Choice\n";
		cin>>mq;

		switch(mq)
		{
			case '1':vv:
					system("clear");
					sleep(1);
					dbobj.open_database();
					dbobj.billing_table();
					dbobj.sale_table();
					cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- PRODUCT LIST'S ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n\n";
					dbobj.show_data();

					dbobj.order();
					dbobj.close_database();
					sleep(1);
				char key_13;
				h_12:

				cout<<"\n\n ~~ Do You Want To Order Again [y/n] ~~ \n\n";
				cin>>key_13;

				if(islower(key_13))
				{
					key_13 = toupper(key_13);
				}

				switch(key_13)
				{
					case 'Y':	system("clear");
								goto vv;
								break;
					case 'N':	sleep(1);
								system("clear");
								goto mn;
								break;
					default:	sleep(1);
								cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
								goto h_12;

				}	
				break;

		case '2':system("clear");
				sleep(1);
				dbobj.open_database();
				dbobj.billing_table();
				dbobj.sale_table();	
				cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- BILLING ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n\n";
				dbobj.print_billing();
				dbobj.insert_sale_details();
				dbobj.delete_billing_data();
				dbobj.close_database(); 
				sleep(1);
				cout<<"\n\n\"~~ Please Press Enter To Get-Back ~~\"\n\n";
				cin.ignore();
				getline(cin,x_1);
				system("clear");
				sleep(1);
				goto mn;
				break;
		case '3':sleep(1);
				system("clear");
				sleep(1);
				menu();
				break;
		default:sleep(1);
				cout<<"\n\n\" ~~ Please Enter A Valid Choice ~~ \"\n\n";
				sleep(1);
				system("clear");
				goto mn;		
		

		}


}

// It shows all the product details .

void product_list()
{

	database dbobj;

	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- PRODUCT LIST'S ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n\n";

	dbobj.open_database();
	dbobj.create_table();
	dbobj.billing_table();
	dbobj.sale_table();
	dbobj.purchase_table();			
	dbobj.show_data();
	dbobj.delete_billing_data();
	dbobj.close_database();

	string x_1;
	sleep(1);

	cout<<"\n\n\"~~ Please Press Enter To Get-Back To Main Menu ~~\"\n\n";
	cin.ignore();
	getline(cin,x_1);

	system("clear");
	sleep(1);
	menu();

}

// It tells us about threshold product or out of stock product .

void check_quantity()
{
	
	database dbobj;
	string x_1;
	bb:
	cout<<"\n\n\n\t\t\t\t\t\" ---------- PRODUCT LIST'S WHICH ARE BELOW THRESHOLD OR OUT OF STOCK ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n";

	char V_1;

	cout<<"\nPress 1 To See Product List's Which Are Below Threshold\n";
	cout<<"\nPress 2 To See Product List's Which Are Out Of Stock\n";
	cout<<"\nPress 3 To Get-Back To Main Menu\n";

		
		cout<<"\n\nPlease Enter Your Choice\n";
		cin>>V_1;

		switch(V_1)
		{
			case '1':	system("clear");
						sleep(1);
						dbobj.open_database();
						dbobj.below_threshold();
						dbobj.close_database();
						sleep(1);
						cout<<"\n\n\"~~ Please Press Enter To Get-Back ~~\"\n\n";
						cin.ignore();
						getline(cin,x_1);
						system("clear");
						sleep(1);
						check_quantity();
						break;
			case '2':	system("clear");
						sleep(1);
						dbobj.open_database();
						dbobj.out_of_stock();
						dbobj.close_database();
						sleep(1);
						cout<<"\n\n\"~~ Please Press Enter To Get-Back ~~\"\n\n";
						cin.ignore();
						getline(cin,x_1);
						system("clear");
						sleep(1);
						check_quantity();
						break;
			case '3':	system("clear");
						sleep(1);
						menu();
						break;
			default:	sleep(1);
						cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
						sleep(1);
						system("clear");
						goto bb;

		}

}

// Here you can search any product from the product list .

void search_product()
{
	ll:
	database dbobj;
	string x_1;

	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- SEARCH PRODUCT ---------- \"\t\t\t\t\t\t\t\n\n\n";

	dbobj.open_database();
	dbobj.search();
	dbobj.close_database();

	sleep(1);

	char key_4;
	h_2:

	cout<<"\n\n ~~ Do You Want To Search Again [y/n] ~~ \n\n";
	cin>>key_4;

	if(islower(key_4))
	{
		key_4 = toupper(key_4);
	}

	switch(key_4)
	{
		case 'Y':	system("clear");
					goto ll;
					break;
		case 'N':	sleep(1);
					cout<<"\n\n\"~~ Please Press Enter To Get-Back To Main Menu ~~\"\n\n";
					cin.ignore();
					getline(cin,x_1);
					system("clear");
					sleep(1);
					menu();
		default:	sleep(1);
					cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
					goto h_2;

	}	
	

}

// It will update various aspect of product list . 

void update_product_list()
{
	mk:

	database dbobj;

	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- UPDATE PRODUCT DETAILS ---------- \"\t\t\t\t\t\t\t\n\n\n";

	char zz;

	cout<<"\nPress 1 To Enter New Values\n";
	cout<<"\nPress 2 To Update Name\n";
	cout<<"\nPress 3 To Update Price\n";
	cout<<"\nPress 4 To Update Quantity\n"; 
	cout<<"\nPress 5 To Delete Record\n";
	cout<<"\nPress 6 To Get-Back To Main Menu\n";

	cout<<"\n\nPlease Enter Your Choice\n";
	cin>>zz;

	switch(zz)
	{
		case '1':ll:
				sleep(1);
				system("clear");
				dbobj.open_database();
				dbobj.create_table();
				dbobj.purchase_table();
				dbobj.insertData();
				dbobj.close_database();
				sleep(1);
				char key_6;
				h_2:

				cout<<"\n\n ~~ Do You Want To Insert Again [y/n] ~~ \n\n";
				cin>>key_6;

				if(islower(key_6))
				{
					key_6 = toupper(key_6);
				}

				switch(key_6)
				{
					case 'Y':	system("clear");
								goto ll;
								break;
					case 'N':	sleep(1);
								system("clear");
								goto mk;
								break;
					default:	sleep(1);
								cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
								goto h_2;

				}	
				break;
				
		case '2': nn:
				sleep(1);
				system("clear");
				dbobj.open_database();
				dbobj.create_table();
				dbobj.purchase_table();
				dbobj.update_name();
				dbobj.close_database();
				sleep(1);
				char key_9;
				h_9:

				cout<<"\n\n ~~ Do You Want To Update Again [y/n] ~~ \n\n";
				cin>>key_9;

				if(islower(key_9))
				{
					key_9 = toupper(key_9);
				}

				switch(key_9)
				{
					case 'Y':	system("clear");
								goto nn;
								break;
					case 'N':	sleep(1);
								system("clear");
								goto mk;
								break;
					default:	sleep(1);
								cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
								goto h_9;

				}	
				break;
		case '3':	ssr:
				sleep(1);
				system("clear");
				dbobj.open_database();
				dbobj.create_table();
				dbobj.purchase_table();
				dbobj.update_price();
				dbobj.close_database();
				sleep(1);
				char key_14;
				h_21:

				cout<<"\n\n ~~ Do You Want To Update Again [y/n] ~~ \n\n";
				cin>>key_14;

				if(islower(key_14))
				{
					key_14 = toupper(key_14);
				}

				switch(key_14)
				{
					case 'Y':	system("clear");
								goto ssr;
								break;
					case 'N':	sleep(1);
								system("clear");
								goto mk;
								break;
					default:	sleep(1);
								cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
								goto h_21;

				}	
				break;
		case '4':	am:
				sleep(1);
				system("clear");
				dbobj.open_database();
				dbobj.create_table();
				dbobj.purchase_table();
				dbobj.update_quantity();
				dbobj.close_database();
				sleep(1);
				char key_41;
				h_27:

				cout<<"\n\n ~~ Do You Want To Update Again [y/n] ~~ \n\n";
				cin>>key_41;

				if(islower(key_41))
				{
					key_41 = toupper(key_41);
				}

				switch(key_41)
				{
					case 'Y':	system("clear");
								goto am;
								break;
					case 'N':	sleep(1);
								system("clear");
								goto mk;
								break;
					default:	sleep(1);
								cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
								goto h_27;

				}	
				break;
		case '5':	ak:
				sleep(1);
				system("clear");
				dbobj.open_database();
				dbobj.create_table();
				dbobj.deleteRow();
				dbobj.close_database();
				sleep(1);
				char key_45;
				h_25:

				cout<<"\n\n ~~ Do You Want To Delete Again [y/n] ~~ \n\n";
				cin>>key_45;

				if(islower(key_45))
				{
					key_45 = toupper(key_45);
				}

				switch(key_45)
				{
					case 'Y':	system("clear");
								goto ak;
								break;
					case 'N':	sleep(1);
								system("clear");
								goto mk;
								break;
					default:	sleep(1);
								cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
								goto h_25;

				}	
				break;
		case '6':sleep(1);
				system("clear");
				sleep(1);
				menu();
				break;
		default:sleep(1);
				cout<<"\n\n\" ~~ Please Enter A Valid Choice ~~ \"\n\n";
				sleep(1);
				system("clear");
				goto mk;		
				
	}
	
}

// It will show the Purchase details . 

void purchase_details()
{

	database dbobj;

	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- PURCHASE DETAILS ---------- \"\t\t\t\t\t\t\t\n\n\n";

	dbobj.open_database();
	dbobj.purchase_table();
	dbobj.purchase_ED();
	dbobj.close_database();

	string x_1;
	sleep(1);

	cout<<"\n\n\"~~ Please Press Enter To Get-Back To Main Menu ~~\"\n\n";
	cin.ignore();
	getline(cin,x_1);

	system("clear");
	sleep(1);
	menu();


}

// It will show the sales details .

void sale_details()
{
	
	database dbobj;

	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- SALE DETAILS ---------- \"\t\t\t\t\t\t\t\n\n\n";

	dbobj.open_database();
	dbobj.print_sale();
	dbobj.close_database();

	string x_1;
	sleep(1);

	cout<<"\n\n\"~~ Please Press Enter To Get-Back To Main Menu ~~\"\n\n";
	cin.ignore();
	getline(cin,x_1);

	system("clear");
	sleep(1);
	menu();

}

// It will delete all the data after performing various functions .

void delete_all_data()
{
	bn:
	database dbobj;
	string x_1;

	sleep(1);
	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- DELETE ALL INFORMATION ---------- \"\t\t\t\t\t\t\t\n\n\n";


	cout<<"\nPress 1 To Delete All Product Details\n";
	cout<<"\nPress 2 To Delete All Sale Details\n";
	cout<<"\nPress 3 To Delete All Purchase Details\n";
	cout<<"\nPress 4 To Get-Back To Main Menu\n";

	char dd;

	cout<<"\n\n\nPlease Enter Your Choice\n";
	cin>>dd;

	switch(dd)
		{
			case '1':	system("clear");
						sleep(1);
						dbobj.open_database();
						dbobj.create_table();
						dbobj.purchase_table();
						dbobj.sale_table();
						dbobj.delete_all_product_data();
						dbobj.close_database();
						sleep(1);
						cout<<"\n\n\"~~ Please Press Enter To Get-Back ~~\"\n\n";
						cin.ignore();
						getline(cin,x_1);
						system("clear");
						sleep(1);
						delete_all_data();
						break;
			case '2':	system("clear");
						sleep(1);
						dbobj.open_database();
						dbobj.create_table();
						dbobj.purchase_table();
						dbobj.sale_table();
						dbobj.delete_all_sale_data();
						dbobj.close_database();
						sleep(1);
						cout<<"\n\n\"~~ Please Press Enter To Get-Back ~~\"\n\n";
						cin.ignore();
						getline(cin,x_1);
						system("clear");
						sleep(1);
						delete_all_data();
						break;
			case '3':	system("clear");
						sleep(1);
						dbobj.open_database();
						dbobj.create_table();
						dbobj.purchase_table();
						dbobj.sale_table();
						dbobj.delete_all_purchase_data();
						dbobj.close_database();
						sleep(1);
						cout<<"\n\n\"~~ Please Press Enter To Get-Back ~~\"\n\n";
						cin.ignore();
						getline(cin,x_1);
						system("clear");
						sleep(1);
						delete_all_data();
						break;
			case '4':	system("clear");
						sleep(1);
						menu();
						break;
			default:	sleep(1);
						cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
						sleep(1);
						system("clear");
						goto bn;

		}


}

// It will show my information (^-^) :):);) (^_^)

void developer_info()
{

	cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- DEVELOPER INFORMATION ---------- \"\t\t\t\t\t\t\t\n\n\n";
	sleep(1);

	string name = "AKHIL MAITHANI";
	char section = 'H';
	long int student_id = 190111182;
	long int university_roll_no = 1918172;
	string email_id = "akhilmaithani1303@gmail.com";
	string university = "GRAPHIC ERA HILL UNIVERSITY , DEHRADUN";
	string course = "B.TECH";
	string branch = "CSE";

	cout<<"\n\n\n";

	cout<<"\nNAME : "<<name<<"\n\n";
	cout<<"\nSECTION : "<<section<<"\n\n";
	cout<<"\nUNIVERSITY NAME : "<<university<<"\n\n";
	cout<<"\nCOURSE : "<<course<<"\n\n";
	cout<<"\nBRANCH : "<<branch<<"\n\n";
	cout<<"\nSTUDENT ID : "<<student_id<<"\n\n";
	cout<<"\nUNIVERSITY ROLL_NO. : "<<university_roll_no<<"\n\n";
	cout<<"\nEMAIL-ID : "<<email_id<<"\n\n";

	string x_1;
	sleep(1);

	cout<<"\n\n\"~~ Please Press Enter To Get-Back To Main Menu ~~\"\n\n";
	cin.ignore();
	getline(cin,x_1);

	system("clear");
	sleep(1);
	menu();

}


// 'menu()' function consist all the menu options.

void menu()
{
	char choice_3;

		l_4:

		cout<<"\n\n\n\t\t\t\t\t\t\t\" ---------- MAIN MENU ---------- \"\t\t\t\t\t\t\t\n\n\n";

		cout<<"\na. Order and Billing\n";
		cout<<"\nb. Product List's\n";
		cout<<"\nc. Product List's Which Are Below Threshold Or Out Of Stock\n";
		cout<<"\nd. Search Product\n";
		cout<<"\ne. Update Product List's\n";
		cout<<"\nf. Purchase Details\n";
		cout<<"\ng. Sale Details\n";
		cout<<"\nh. Developer Information\n";
		cout<<"\ni. Delete All Existing Data\n";
		cout<<"\nj. Exit The Application\n";

		cout<<"\n\nPlease Enter Your Choice\n\n";
		cin>>choice_3;

		if(isupper(choice_3))
		{
			choice_3 = tolower(choice_3);
		}

		switch(choice_3)
		{
			case 'a':sleep(1);
					system("clear");
					order_billing();
					break;
			case 'b':sleep(1);
					system("clear");
					product_list();
					break;
			case 'c': sleep(1);
					system("clear");
					check_quantity();
					break;
			case 'd': sleep(1);
					system("clear");
					search_product();
					break;
			case 'e': sleep(1);
					system("clear");
					update_product_list();
					break;
			case 'f': sleep(1);
					system("clear");
					purchase_details();
					break;
			case 'g': sleep(1);
					system("clear");
					sale_details();
					break;
			case 'h': sleep(1);
					system("clear");
					developer_info();
					break;
			case 'i':sleep(1);
					system("clear");
					delete_all_data();
					break;
			case 'j': sleep(1);
					system("clear");

					char key_4;
					h_2:

					cout<<"\n\n ~~ Do You Want To Continue [y/n] ~~ \n\n";
					cin>>key_4;

					if(islower(key_4))
					{
						key_4 = toupper(key_4);
					}

					switch(key_4)
					{
						case 'Y':	system("clear");
									cout<<"\n\n\t\t\t\t\t\t\t\" ~~~ ThankYou For Using The Service ~~~ \"\t\t\t\t\t\t\t\n\n";
									exit(0);	// calling 'exit()' function. It will terminate or end the program.
									
						case 'N':	system("clear");
									goto l_4;
									break;

						default:	sleep(1);
									cout<<"\n\n\" ~~ Please Enter A Valid Choice ~~ \"\n\n";
									sleep(1);
									system("clear");
									goto h_2;
					}
					break;

			default:sleep(1);
					cout<<"\n\n\" ~~~ Please Enter A Valid Choice ~~~ \"\n\n";
					sleep(1);
					system("clear");
					goto l_4;
		}

}


// 'menu_info()' function consist the main code part for menu.

void menu_info()
{

	char choice_2;

	l_3:

	cout<<"\nPlease Press 1 for \" MAIN MENU \" and 0 to \" Exit the Application \".\n\n";
	cin>>choice_2;


	switch(choice_2)
	{
		case '1': sleep(1);
				system("clear");
				menu();		// calling 'menu()' function.
				break;
		case '0': sleep(1);
				system("clear");

				char key_3;
				h_1:
					cout<<"\n\n ~~ Do You Want To Continue [y/n] ~~ \n\n";
					cin>>key_3;

					if(islower(key_3))
					{
						key_3 = toupper(key_3);
					}

					switch(key_3)
					{
						case 'Y':	system("clear");
									cout<<"\n\n\t\t\t\t\t\t\t\" ~~~ ThankYou For Using The Service ~~~ \"\t\t\t\t\t\t\t\n\n";
									exit(0);	// calling 'exit()' function. It will terminate or end the program.
									
						case 'N':	system("clear");
									goto l_3;
									break;

						default:	sleep(1);
									cout<<"\n\n\" ~~ Please Enter A Valid Choice ~~ \"\n\n";
									sleep(1);
									system("clear");
									goto h_1;
					}

					break;
					
		default: 
				sleep(1);
				cout<<"\n\n\" ~~ Please Enter A Valid Choice ~~ \"\n\n";
				sleep(1);
				system("clear");
				goto l_3;
	}

}



// Main function.

int main()
{
	system("clear");
	
	front_info(); // calling 'front_info()' function.

	system("clear"); 

	login_info();	// calling 'login_info()' function.

	system("clear");

	menu_info();	// calling 'menu_info()' function.

	return 0;
}
