
// Header file's

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<ctype.h>
#include<unistd.h>
#include<sqlite3.h>

// It helps us to use standard objects.

using namespace std;

// Prototype Declaration of function's used.

void open_database();
void close_database();
void create_table();

void show_data();
void insertData();
void deleteRow();
void below_threshold();
void out_of_stock();
void search();
void update_name();
void update_price();
void update_quantity();
void order();
void sale_table();
void billing_table();
void print_billing();
void delete_billing_data();
void print_sale();
void delete_all_sale_data();
void delete_all_product_data();
void purchase_table();
void delete_all_purchase_data();
void purchase_ED();
void insert_sale_details();

// class

class database
{

// Private members

private:

	sqlite3 *db;				// Pointer to Sqlite3 connection
	int rc;						// Taking response 
	string sql,sql_1,sql_2;		// Contain the sql statements
	char *errormsg;				// for containing error message
   	sqlite3_stmt *stmt;			// sqlite statements

// Public members

public:

	
	// open database

	void open_database()
	{
		rc = sqlite3_open("canteen.db",&db);

		if(rc)
		{
			cout<<"Error Occur : "<<sqlite3_errmsg(db);
			close_database();
		}
	
	}

	// close database

	void close_database()
	{

		sqlite3_close(db);

	}


	// create table

	void create_table()
	{
	
		sql = "CREATE TABLE IF NOT EXISTS CANTEEN_DATABASE("
				"PRODUCT_ID INTEGER PRIMARY KEY NOT NULL,"
				"PRODUCT_NAME TEXT NOT NULL,"
				"PRODUCT_PRICE REAL NOT NULL,"
				"PRODUCT_QUANTITY INT NOT NULL);";
			
		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);

		}
			
	}

	// show below threshhold product list

	void below_threshold()
	{

		int id,quantity;
		double price;
		const unsigned char *name;

	cout<<"\n\n\n\t\t\t\t\t\" ---------- PRODUCT LIST'S WHICH ARE BELOW THRESHOLD ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n";


		sql = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM CANTEEN_DATABASE WHERE PRODUCT_QUANTITY>0 AND PRODUCT_QUANTITY<=5;";
    	
    cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";

    	  sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;

    		}
	
	}

	// show out of stock product list

	void out_of_stock()
	{

		int id,quantity;
		double price;
		const unsigned char *name;

	cout<<"\n\n\n\t\t\t\t\t\" ---------- PRODUCT LIST'S WHICH ARE OUT OF STOCK ---------- \"\t\t\t\t\t\t\t\n\n\n\n\n";


		sql = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM CANTEEN_DATABASE WHERE PRODUCT_QUANTITY=0;";
    	
    	cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";

   	    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;

    		}
	
	}

	// select entire data

	void show_data()
	{

		int id,quantity;
		double price;
		const unsigned char *name;

		sql = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM CANTEEN_DATABASE;";
    	
    	cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";

   			// Run the SQL
    	sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;

    		}

	}

	// insert table

	void insertData() 
	{
		
		int id,quantity;
		string name;
		double price;

		cout<<"\nPlease Enter The Unique PRODUCT_ID:\n";
		cin>>id;
		cout<<"\nPlease Enter Full PRODUCT_NAME:\n";
		cin.ignore();
		getline(cin,name);
		cout<<"\nPlease Enter PRODUCT_PRICE:\n";
		cin>>price;
		cout<<"\nPlease Enter PRODUCT_QUANTITY:\n";
		cin>>quantity;

	
	sql = "INSERT INTO CANTEEN_DATABASE (PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY) VALUES (" + to_string(id) + ", '" + name + "', " + to_string(price) +", " + to_string(quantity) +")";
	
		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Record Inserted Successfully ~~~ \"\n\n";

			sql_1 = "INSERT INTO PURCHASE_DATABASE (PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY) VALUES (" + to_string(id) + ", '" + name + "', " + to_string(price) +", " + to_string(quantity) +")";
		
		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}

		}


	}


	// delete row

	void deleteRow() 
	{
		int id;

		cout<<"\nPlease Enter The Existing PRODUCT_ID:\n";
		cin>>id;
		
		sql = "DELETE FROM CANTEEN_DATABASE WHERE PRODUCT_ID == '" + to_string(id) + "'";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Record Deleted Successfully ~~~ \"\n\n";
		}

	}

	// search products

	void search()
	{

		int id,quantity;
		double price;
		const unsigned char *name;	

		cout<<"\n\nPlease Enter The Existing PRODUCT_ID To Search:\n";
		cin>>id;
		cout<<"\n\n";

	sql = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM CANTEEN_DATABASE WHERE PRODUCT_ID = '" + to_string(id) + "';";

		cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";

   	    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;

    		}
	
	}

	// update product name

	void update_name()
	{
		int id;
		string name;

		cout<<"\n\nPlease Enter The Existing PRODUCT_ID\n";
		cin>>id;
		cout<<"\n\nPlease Enter The Name You Want To Insert\n";
		cin.ignore();
		getline(cin,name);

		sql = "UPDATE CANTEEN_DATABASE SET PRODUCT_NAME = '" + name + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Name Updated Successfully ~~~ \"\n\n";

			sql_1 = "UPDATE PURCHASE_DATABASE SET PRODUCT_NAME = '" + name + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}

		}

	}

	// update product price 

	void update_price()
	{
		int id;
		double price;

		cout<<"\n\nPlease Enter The Existing PRODUCT_ID\n";
		cin>>id;
		cout<<"\n\nPlease Enter The Price You Want To Insert\n";
		cin>>price;

		sql = "UPDATE CANTEEN_DATABASE SET PRODUCT_PRICE = '" + to_string(price) + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Price Updated Successfully ~~~ \"\n\n";

			sql_1 = "UPDATE PURCHASE_DATABASE SET PRODUCT_PRICE = '" + to_string(price) + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}

		}


	}	

	// upadte product quantity

	void update_quantity()
	{
		int id,quantity;

		cout<<"\n\nPlease Enter The Existing PRODUCT_ID\n";
		cin>>id;
		cout<<"\n\nPlease Enter The Quantity You Want To Insert\n";
		cin>>quantity;

		sql = "UPDATE CANTEEN_DATABASE SET PRODUCT_QUANTITY = '" + to_string(quantity) + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Quantity Updated Successfully ~~~ \"\n\n";


		sql_1 = "UPDATE PURCHASE_DATABASE SET PRODUCT_QUANTITY = '" + to_string(quantity) + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}

		}


	}


	// billing table

	void billing_table()
    {
    	sql_1 = "CREATE TABLE IF NOT EXISTS BILLING_DATABASE("
    			"PRODUCT_ID INT NOT NULL,"
				"PRODUCT_NAME TEXT NOT NULL,"
				"PRODUCT_PRICE REAL NOT NULL,"
				"PRODUCT_QUANTITY INT NOT NULL);";
			
		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);

    	}
    }	

    // sale table

	void sale_table()
    {
    	sql_1 = "CREATE TABLE IF NOT EXISTS SALE_DATABASE("
    			"PRODUCT_ID INT NOT NULL,"
				"PRODUCT_NAME TEXT NOT NULL,"
				"PRODUCT_PRICE REAL NOT NULL,"
				"PRODUCT_QUANTITY INT NOT NULL);";
			
		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);

    	}
    }	

    // purchase table

   	void purchase_table()
    {
    	sql_1 = "CREATE TABLE IF NOT EXISTS PURCHASE_DATABASE("
    			"PRODUCT_ID INT NOT NULL,"
				"PRODUCT_NAME TEXT NOT NULL,"
				"PRODUCT_PRICE REAL NOT NULL,"
				"PRODUCT_QUANTITY INT NOT NULL);";
			
		rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);

    	}
    }	


    // delete all purchase data

    void delete_all_purchase_data()
	{

		sql = "DELETE FROM PURCHASE_DATABASE;";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Delete Process Successfull ~~~ \"\n\n";
		}	

	}


	// delete billing table data

	void delete_billing_data() 
	{
		
		sql = "DELETE FROM BILLING_DATABASE;";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}	

	}

	// delete all the sale details

	void delete_all_sale_data()
	{

		sql = "DELETE FROM SALE_DATABASE;";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Delete Process Successfull ~~~ \"\n\n";
		}	

	}

	// delete all the product details

	void delete_all_product_data()
	{

		sql = "DELETE FROM CANTEEN_DATABASE;";

		rc = sqlite3_exec(db,sql.c_str(),NULL,NULL,&errormsg);

		if(rc!=SQLITE_OK)
		{
			cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
			sqlite3_free(errormsg);
		}
		else
		{
			cout<<"\n\n\" ~~~ Delete Process Successfull ~~~ \"\n\n";
		}	

	}

   	// print billing

   	void print_billing()
   	{

   		int id,quantity;
		double price;
		const unsigned char *name;

		int amount=0;

		sql_1 = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM BILLING_DATABASE;";

		cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";


   			// Run the SQL
    	sqlite3_prepare_v2(db, sql_1.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{

    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;


    		}


   	}

   	// print sale database

   	void print_sale()
   	{

   		int id,quantity;
		double price;
		const unsigned char *name;

		sql_1 = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM SALE_DATABASE;";

		cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";


   			// Run the SQL
    	sqlite3_prepare_v2(db, sql_1.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    			
    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;


    		}

   	}

   	// purchase

   	void purchase_ED()
   	{

		int id,quantity;
		double price;
		const unsigned char *name;

		sql_1 = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE,PRODUCT_QUANTITY FROM PURCHASE_DATABASE;";

		cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";


   			// Run the SQL
    	sqlite3_prepare_v2(db, sql_1.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    			
    			id = sqlite3_column_int(stmt,0);
    			name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    			quantity = sqlite3_column_int(stmt,3);

    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;

    		}
			
   	}

   	// insert sale details

   	void insert_sale_details()
   	{

   		sql_1 = "INSERT INTO SALE_DATABASE SELECT *FROM BILLING_DATABASE;";

				rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

				if(rc!=SQLITE_OK)
				{
					cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
					sqlite3_free(errormsg);
				}

   	}

  
	// order and billing

	void order()
	{

		int id,quantity;
		double price;
		const unsigned char *name;

		cout<<"\n\n\nPlease Enter The Existing PRODUCT_ID\n";
		cin>>id;
		cout<<"\nPlease Enter The Quantity You Want\n";
		cin>>quantity;

		sql = "SELECT PRODUCT_ID,PRODUCT_NAME,PRODUCT_PRICE FROM CANTEEN_DATABASE WHERE PRODUCT_ID = '" + to_string(id) + "';";

		cout<<"PRODUCT_ID"<<"\t\t"<<"PRODUCT_NAME"<<"\t\t\t"<<"PRODUCT_PRICE"<<"\t\t"<<"PRODUCT_QUANTITY"<<"\n\n";

   	    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    		while(sqlite3_step(stmt)!=SQLITE_DONE)
    		{
    		
    			id = sqlite3_column_int(stmt,0);
   				name = sqlite3_column_text(stmt,1);
    			price = sqlite3_column_double(stmt,2);
    	
    			cout<<id<<"\t\t\t"<<name<<"\t\t\t"<<price<<"\t\t\t"<<quantity<<endl;

    			sql_1 = "UPDATE CANTEEN_DATABASE SET PRODUCT_QUANTITY = (PRODUCT_QUANTITY - '" + to_string(quantity) + "') WHERE PRODUCT_ID = '" + to_string(id) + "';";

    			rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

				if(rc!=SQLITE_OK)
				{
					cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
					sqlite3_free(errormsg);
				}


    			sql_1 = "INSERT INTO BILLING_DATABASE SELECT *FROM CANTEEN_DATABASE WHERE PRODUCT_ID = '" + to_string(id) + "';";

    			rc = sqlite3_exec(db,sql_1.c_str(),NULL,NULL,&errormsg);

				if(rc!=SQLITE_OK)
				{
					cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
					sqlite3_free(errormsg);
				}

				sql_2 = "UPDATE BILLING_DATABASE SET PRODUCT_QUANTITY = '" + to_string(quantity) + "' WHERE PRODUCT_ID = '" + to_string(id) + "';";

				rc = sqlite3_exec(db,sql_2.c_str(),NULL,NULL,&errormsg);

				if(rc!=SQLITE_OK)
				{
					cout<<"\nError :"<<sqlite3_errmsg(db)<<endl;
					sqlite3_free(errormsg);
				}
				
				
   			}

	}


}; // end of class
