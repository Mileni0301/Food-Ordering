#include <iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
/* 1. Access modifiers
   2.Constructor (types-default,parameterized,copy)
   3.Constructor overloading
   4.function
   5.Polymorphism -overloading,overriding
   6.virtual function 
   7.classes and objects
   8.Switch case 
   9.loops- for,while
   10.pointer
   11.scope resolution operators
   12 Inheritance (single, multiple, multi level)
   13.Pure virtual function and Abstract class
   14.keywords - this, break
   15.conditional statements- if else
   16.arrays and strings
   17.increment decrement operators
   18.Datatypes-long long,int,char*/
 static int Order_num=0;  
class customer
{
    private: //access modifiers
   	string n;
	public:
	string name;
    int total;
    vector<string> order;
	long long int num;
	customer()
	{
	n=name;
	}
	customer(char* x,long long num)//construtor overloading
	{
		name =x;
		this->num=num;//use of this keyword
	}
	customer(customer &t)//copy constructor 
	{
		name=t.name;
		num=t.num;
		total=t.total;
		order=t.order;
	}
	void getdetails()//to get the details of customer
	{   
		cout<<"Enter details:\n";
		cout<<"NAME           - ";
		cin>>name;
		cout<<"(enter a valid 10 digit contact number else the order wont be accepted)\nCONTACT NUMBER -  ";
		cin>>num;
		ifv(num);
		total=0;
	}
	void getdetails(int)//function overloading
	{
		cout<<"function overloading";
	}
	void showdetails()//to display customers info
	{
		long long j;
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		cout<<endl<<"Hello, "<<name<<" Welcome to FOODISTA !"<<endl;
	}
	virtual vector<string> order1()//virtual function - function overriding
	{
	cout<<"Since it is virtual it wont be called";	
	}
    void ifv(long long x);
	friend string show(customer c);//friend function	
};
void customer::ifv(long long j)//use of scope resolution operator
{
	int k=0;
		while(j!=0)
		{
			j=j/10;
			k++;
		}
		if(k==10)
		cout<<"Number entered is valid";
		else {
		cout<<"invalid contact number in input\nEnter contact number again :";
		long long newN;
		cin>>newN;
		int k=0;
		while(newN!=0)
		{
			newN=newN/10;
			k++;
		}
		if(k==10)
		cout<<"Number entered is valid";
		else {
			cout<<"Invalid Input";
			exit(1);
		}
		}

};



string show(customer t)//definition of friend function
		{
			string nam=t.name;
			for(int i=0;i<nam.length();i++)
			toupper(nam[i]);
			return(nam+" \n");//concatenation of string
		};

 
class abstract  //abstract class - object can never be created, contains pure virtual function, child class should defin the pure virtual function
{
	public:
    virtual	void fun()=0; //pure virtual function
};



class order :public customer,public abstract //multiple inheritance
{
   public:
   vector<string> tor;
   int q[9];vector<int> a;
   int ch,x;
   public:
   	vector<string> order1()
   	{
    cout<<"\n----------------------VEG----------------------          ----------------------DESERT----------------------\n"<<"\n";
    cout<<"1.--------------CHHOLE BHATURE----------Rs.60           6.------------------GULAB JAMUN-------------Rs.30\n";
    cout<<"2. ---------------- PAV BHAJI-----------Rs.50           7.--------------------RASGULLA--------------Rs.10\n";
    cout<<"3.---------------MASALA DOSA------------Rs.50           8.--------------------SANDESH---------------Rs.100\n";
    cout<<"4.--------------CHHOLE TIKIYA-----------Rs.40           9. ------------------RAS-MALAI--------------Rs.50\n";
    cout<<"5.-----------------PANI PURI------------Rs.20           10.--------------------JALEBI---------------Rs.30\n";	
   cout<<"\nEnter the number of dishes you want to order:\n                                                            ";	
   cin>>x;
   cout<<"Enter the serial numbers associated with the dishes to add your dish\n";
   
   while(x>0)
   {
   	cin>>ch;
   	a.push_back(ch);
   switch(ch) //switch case
   {
   case 1: {
   	        cout<<"Quantity -";
   	        cin>>q[0];
            tor.push_back("CHHOLE BHATURE    RS.60 * "+to_string(q[0]));
            total=total+60*q[0];
          x=x-q[0]; 
          break; //break keyword to exit the switch
           }
   case 2:{
   	cout<<"Quantity - ";
   	        cin>>q[1];
           tor.push_back("PAV BHAJI         RS.50 * "+to_string(q[1]));
           total=total+q[1]*50;
          x=x-q[1]; 
          break;
          }
   case 3:{cout<<"Quantity - ";
   	        cin>>q[2];
	      tor.push_back("MASALA DOSA       RS.50 * "+to_string(q[2]));
          total=total+50*q[2];
          x=x-q[2]; 
          break;
          }
   case 4:{cout<<"Quantity - ";
   	        cin>>q[3];
	      tor.push_back("CHHOLE TIKIYA     RS.40 * "+to_string(q[3]));
          total=total+40*q[3];
          x=x-q[3]; 
          break;
         }
   case 5:{
   	      cout<<"Quantity - ";
   	        cin>>q[4];
          tor.push_back("PANI PURI         RS.20 * "+to_string(q[4]));
          total=total+20*q[4];x=x-q[4];
		  break;
          }
   case 6:{
            cout<<"Quantity - ";
   	        cin>>q[5];
          tor.push_back("GULAB JAMUN(2pc)  RS.15 * "+to_string(q[5]));
          total=total+q[5]*15;x=x-q[5];
		  break;
	      }
   case 7:{cout<<"Quantity - ";
   	        cin>>q[6];
          tor.push_back("RASGULLA          RS.15 * "+to_string(q[6]));
          total=total+q[6]*15;x=x-q[6];
		  break;
	      }
   case 8:{
   	    cout<<"Quantity - ";
   	        cin>>q[7];
          tor.push_back("SANDESH           RS.20 * "+to_string(q[7]));
          total=total+q[7]*20;x=x-q[7];
		  break;
	      }
    case 9:{
    	cout<<"Quantity - ";
   	        cin>>q[8];
          tor.push_back("RAS MALAI         RS.20 * "+to_string(q[8]));
          total=total+q[8]*20;x=x-q[8];
		  break;
		  }
    case 10:{
    	cout<<"Quantity - ";
   	        cin>>q[9];
          tor.push_back("JALEBI            RS.30 * "+to_string(q[9]));
          total=total+q[9]*20;x=x-q[9];
		  break;		  
	      }	      
   default: cout<<"Not available";
    }
}
 return tor;
}
  void fun()//pure virtual function definition
  { }    
};



class storedata: public order //multi level inheritance
{
	public:
	void write()
	{
		ofstream wrt;
		wrt.open(name+".txt");
		wrt<<"\nName="<<name<<" &\nPrevious orders are &\n";
		for(int i=0;i<tor.size();i++)
            wrt<<tor[i]<<" \n";
        wrt<<"total = "<<total<<"\n";
        wrt.close();
	}
  /* void write()
   {
   	ofstream wrt;
	std::vector<string>::iterator itr;
    wrt.open(name+".txt",ios::out);
    wrt<<"\nName="<<name<<" &\nPrevious orders are &\n" ;
    for(itr=tor.begin();itr<tor.end();itr++)
    wrt<<*itr<<" &";
    wrt<<"total = "<<total<<"&";
    wrt.close();
   }
   void read()
   {
	fstream fin;
	char ch[2];
	fin.open("C:\\Users\\Mileni\\Desktop\\New folder\\name.txt",ios::in);
	if(!fin)
     {
     	cout<<"\nFile not found"<<endl;
	 }
	 else
	 {
    	while(!fin.eof())
	    {
	    cout<<ch;
    	}
    }
    fin.close();  
   }
  void searchdata(string t)
  {
	int count=0;
	char ch,f;
	fstream fin;
	fin.open("C:\\Users\\Mileni\\Desktop\\New folder\\name.txt",ios::in);
	if(!fin)
	{
		cout<<"No previous orders";
	}
	else
	{
		while(!fin.eof())
		{
	    fin<<ch;
	    if(ch=='&')
	    cout<<"\n";
        cout<<ch;	 
        }
        
	} 	
   fin.close();  	
   } */
};


int main() 
{
//order c;
vector<string> ord;
storedata s;
string x;
cout<<"\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
cout<<"-----------------------------------------WELCOME TO THE FOODISTA-------------------------------------------------"<<endl;
cout<<"\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";;
cout<<"******--------------IF YOU ARE NEW TO FOODISTA TRY PROMOCODE ''NEWME'' TO AVAIL 50% DISCOUNT-------------********\n";
cout<<"******--------------USE PROMOCODE  ''FOODIT'' TO AVAIL 10% DISCOUNT (available on any order)-------------********\n\n";
s.getdetails();  //function of child class order being called
system("cls");
s.showdetails(); //function of parent class customer being called through child class order 
ord=s.order1();
cout<<"Your orders are\n";
for (int i=0; i<ord.size();i++)
 {
   cout << "\t\t\t\t" <<  ord[i]  << "\t\n" ; 
 }
 cout<<"Enter Promocode- ";
 cin>>x;
system("cls");
cout<<"\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
cout<<"\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-BILL*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
cout<<"\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
cout<<"\t\t\t\t\t\tOrdered by   "<<show(s)<<endl;
cout<<"\t\t\t\t\t\tContact no.  "<<s.num<<endl;
for(int i=0;i<s.a.size();i++)
{
cout<<"\n\t\t\t\t\t\t"<<ord[i]<<endl;		
}
if(x=="NEWME")
 {
 cout<<"\n\t\t\t\t\t\tTotal Amount      =  "<<s.total;
 cout<<"\n\t\t\t\t\t\tDiscount availed  =  "<<(float)((0.5)*s.total);
 cout<<"\n\t\t\t\t\t\tAmount to be paid =  "<<(float)(s.total-(0.5)*s.total);
}
 else if(x=="FOODIT")
 {
 cout<<"\n\t\t\t\t\t\tTotal Amount      =  "<<s.total;
 cout<<"\n\t\t\t\t\t\tDiscount availed  =  "<<(float)((0.1)*s.total);
 cout<<"\n\t\t\t\t\t\tAmount to be paid =  "<<(float)(s.total-((0.1)*s.total));
}
else cout<<"\n\t\t\t\t\t\tTotal amount = "<<s.total;
cout<<"\n\n\n\t\t\t"<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n";
cout<<"\t\t\t"<<"*-*-*-*-*-*-*-*-*THANK YOU FOR ORDERING, KEEP VISITING*-*-*-*-*-*-*-\n\n";
cout<<"\t\t\t"<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
s.write();
return 0;
}
