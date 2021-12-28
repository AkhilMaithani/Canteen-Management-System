# Canteen-Management-System

* It is a canteen management system. 
* This project is made up of using c++ and sqlite3 .
* In this project sqlite3 is embedded with c++.

&nbsp;

___
## Dependencies

* You can run this code after installing the sqlite3 software library in your system from the bellow link -: [Click Here to move to the link page](https://www.sqlite.org/download.html "https://www.sqlite.org/download.html")

### How to Download in linux(Ubuntu)
* As, I made this project in *Linux (Ubuntu)*, so for installing in ubuntu you can follow the bellow commands -:

###### Download sqlite3 software library :

```bash
 sudo apt update
```
```bash
 sudo apt install sqlite3
```

###### Checking successfull install :

1. Open the terminal and write **sqlite3** , if it is successfully install it will opens the sqlite3 terminal otherwise not.

&nbsp;

___
## Project Details
* This Project consist of three files :

1. CMS.cpp file    i.e main code file
2. dbfile.h        i.e user defined header file
3. canteen.db      i.e database file

&nbsp;

___
## Username And Password to Run The project

1. USERNAME : username
2. PASSWORD : password

&nbsp;

___
## In order to run the project in terminal in your system follow the command *in linux*

```bash
 g++ CMS.cpp -l sqlite3
```

* Don't forget to add *-l sqlite3* otherwise it will show error.
