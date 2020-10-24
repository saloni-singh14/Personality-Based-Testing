/* additional files:user.dat;t.dat;test11.txt and test2.txt*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
char y;long pos,pos1;
int forward,q=0;
int udel=0;
fstream fx;
/*void welcome()
{
 int gdriver=DETECT , gmode;
 initgraph(&gdriver,&gmode,"C:/TC/bgi");
 setbkcolor(12);
 setcolor(9);
 settextstyle(4,0,6);
 outtextxy(140,10,"WELCOME TO");
 settextstyle(1,0,10);
 setcolor(200);
 outtextxy(210,80,"PFT");
 settextstyle(1,0,1);
 outtextxy(180,220,"PERSONALITY FACTOR TESTING");
 setcolor(23);
 outtextxy(215,300,"MORE THAN IQ MATTERS....");
 setcolor(21);
 settextstyle(2,0,6);
 outtextxy(201,400,"PRESS ENTER TO CONTINUE");

 getch();
 closegraph();
}*/


void welcome1()
{


	cout<<"\n\n\n\n";
	cout<<"\t\t********   \t********   \t*********";cout<<endl;delay(120);
	cout<<"\t\t*      *   \t*          \t    *    ";cout<<endl;delay(120);
	cout<<"\t\t*      *   \t*          \t    *    ";cout<<endl;delay(120);
	cout<<"\t\t********   \t********   \t    *    ";cout<<endl;delay(120);
	cout<<"\t\t*          \t*          \t    *    ";cout<<endl;delay(120);
	cout<<"\t\t*          \t*          \t    *    ";cout<<endl;delay(120);
	cout<<"\t\t*          \t*          \t    *    ";cout<<endl;delay(120);
	cout<<"\t\t*          \t*          \t    *    ";cout<<endl;delay(120);

	cout<<"\n\n\n\t\t\tPERSONALITY FACTOR TESTING";

	cout<<"\n\n\t\t\t choose your option"<<endl;
	cout<<"\n\t\t\t\t1.admin login"<<endl;
	cout<<"\n\t\t\t\t2.signup"<<endl;
	cout<<"\n\t\t\t\t3.user login"<<endl;
	cout<<"\n\t\t\t\t4.exit program"<<endl;

}


//admin options functions
void admin_menu();
void seemembers();
void adel();

//user options functions
void user_menu();
void del();
//void taketests
//void editpassword(user,char*)
//void see_reports(user xx);
char* gen_type(int);
char* gen_type2(int);

class admin
{
	char ausername[10];
	char apassword[10];
public:
	admin()
	{strcpy(ausername,"saloni");
	 strcpy(apassword,"salsi");
	}

	int match(char *a,char *b)
	{
		if(strcmp(a,ausername)==0 && strcmp(b,apassword)==0)
			{cout<<"\n\n login successful";
			 return 1;
			}
		else
		{cout<<"\n\n\n\n\t wrong username or password. press enter to continue";
		 getch();return 0;
		}
	}

}ad;


class user
{
	char username[20];
	char password[21];
	int test_taken1,test_taken2;
	int t1,t2;                  //no. of a's in each test
	char f1[30],f2[30];         //personality type|personality factor
	int checkusern(char *nm);

public:
	void seedata()
	{
		cout<<" username:"<<username;
		cout<<"\n password:"<<password<<endl;
		cout<<"\n testtaken1:"<<test_taken1<<"\n testtaken2:"<<test_taken2<<endl;
		cout<<"\n t1:"<<t1<<"\t t2=:"<<t2;
		cout<<f1<<"\n ::"<<f2;
	}

	void createpassword();

	char* retpassword(){return password;}
	char* retusername(){return username;}
	char* rettype1(){return f1;}
	char* rettype2(){return f2;}
	int rett1(){return t1;}
	int rett2(){return t2;}
	int ret_testtaken1(){return test_taken1;}
	int ret_testtaken2(){return test_taken2;}

	void inctesttaken1()
	{if(test_taken1==0)test_taken1++;}

	void inctesttaken2()
	{if(test_taken2==0)test_taken2++;}

	user()
	{t1=0;t2=0;test_taken1=0;test_taken2=0;}

	void setfort1(){t1=0;}

	void setfort2(){t2=0;}


	void showpassword()
	{
		char c;
		cout<<"\n\n DO YOU WISH TO SEE YOUR PASSWORD?ENTER 'y' else enter 'n':";
		cin>>c;
		if(c=='y'){cout<<"\n YOUR CURRENT PASSWORD:"<<password<<endl;getch();}
		else
			cout<<"\n";
	}

	void newpsw(char* p)
	{strcpy(password,p);}

	void get_f1(char* f)
	{strcpy(f1,f);}

	void get_f2(char* f)
	{strcpy(f2,f);}

	void seedetails()
	{

		cout<<"\n 1.USERNAME:"<<username;
		cout<<"\n 2.PASSWORD:"<<password;
		cout<<"test1= "<<test_taken1<<"test2= "<<test_taken2<<endl;
		if(test_taken1==1)
		{cout<<"\n FROM TEST 1, YOU MUST BE:"<<f1<<endl;
		 cout<<"\n t1="<<t1;}

		if(test_taken2==1)
			{cout<<"\n AND FROM TEST 2:"<<f2<<endl;
			cout<<"\n t2="<<t2<<endl;
			}
		getch();
	}

	void getdata();


	void inct1(char a)
	{
		if(a=='a')
			t1++;
	}

	void inct2(char a)
	{
		if(a=='b')
			t2++;
	}



}xx;

void user::getdata()
	{
		test_taken1=0;test_taken2=0;
		char c;t1=0;t2=0;
		int ocnt,icnt;

		do
		{
			cout<<"\n ENTER:"<<"\n1.USERNAME:"<<endl;gets(username);
			ocnt=checkusern(username);
		}while(ocnt!=0);

		cout<<"\n\n2.CREATE YOUR PASSWORD(NO SPACES,TABS,ENTER), MAX 19 CHARACTERS:"<<endl;

		createpassword();

		cout<<"\n\n\tDO YOU WISH TO SEE YOUR PASSWORD?ENTER 'y' else enter 'n':";
		cin>>c;
		if(c=='y'){cout<<"\n\t "<<password<<endl;getch();}
		else
			cout<<"\n";
	}

void taketests(user);
void editpassword();
void see_report1();
void see_report2();

void signup()
{
		clrscr();
		fstream fp;
		user u;
		fp.open("user.dat",ios::out|ios::binary|ios::app);
		u.getdata();
		fp.write((char*)&u,sizeof(user));
		fp.close();forward=0;

		cout<<"\n\n\t\t THANK YOU FOR REGISTERING.\n\n";
		cout<<" \n\n\t\tYOU CAN TAKE YOUR TESTS AFTER LOGGING IN";
		cout<<"\n\n\t\tPRESS ENTER TO CONTINUE";getch();
}
int countusers()
{
	int cnt=0;
	fstream fp;
	user u;
	fp.open("user.dat",ios::binary|ios::in);
	while( fp.read((char*)&u,sizeof(user)) )
		{cnt++;
		}
	fp.close();
	return cnt;
}



int login(char *nm, char*psw)
{
	clrscr();
	fstream fp;
	int q=0;
	fp.open("user.dat",ios::in|ios::binary);
	while( (fp.read((char*)&xx,sizeof(user))) && q==0 )
	{
		if(strcmp(nm,xx.retusername())==0 && strcmp(psw,xx.retpassword())==0)
			{q++;pos=fp.tellg();cout<<"\n pos="<<pos;
			cout<<"\n\n\n\n\t\t\t login successful"<<endl;
			clrscr();
			cout<<"\n\n\n\n\n\n\n\t\t\t\t   LOADING......";delay(1000);
			return 2;
			}
	}
	if(q==0)
	{cout<<"\n\n\n\n\t\tINCORRECT USERNAME OR PASSWORD";getch();}
	fp.close();
	return 0;
}


void enterpassword(char* psw)
{
	char z;
		for(int i=0;i<20;)
		{
			z=getch();

			if(z=='\b')
				{cout<<"\b";clreol();--i;
					if(i<0)
						{i=0;}
				}
			else if(z=='\t' || z==' ')
				{}
			else if(int(z)==13)
				{psw[i]='\0';break;}
			else
				{psw[i]=z;cout<<"*";++i;}

		}
}

void user::createpassword()
{
		cout<<"\n";
		char z;
		for(int i=0;i<20;)
		{
			z=getch();

			if(z=='\b')
				{cout<<"\b";clreol();--i;
					if(i<0)
						{i=0;}
				}
			else if(z=='\t' || z==' ')
				{}
			else if(int(z)==13 )
				{if(i!=0)
					{password[i]='\0';break;}
				else if(i==0){}
				}
			else
				{password[i]=z;cout<<"*";++i;}
			if(i==20)cout<<"\n\n\t\t\t\\\\\limit over!!!!/////";

		}




}


int user::checkusern(char * nm)
{
	int cnt=0;
	fstream fp;
	user v;
	fp.open("user.dat",ios::in|ios::binary);
	fp.read((char*)&v,sizeof(user));
	while(!fp.eof())
	{

		if(strcmp(v.retusername(),nm)==0 || strcmp(username,"\r")==-13  || strcmp(username,"\t")==0 || strcmp(username," ")==0)
			{cnt++;}
		fp.read((char*)&v,sizeof(user));


	}
	if(cnt!=0)
		cout<<"\n\n\t\t username already in use or invalid.Enter again";
		fp.close();
return cnt;
}

//main starts
void main()
{

	//welcome();
	char c,nm[20],psw[21];//for logins
	int q;//for going to actions after login
do{
	clrscr();
	welcome1();

	cout<<"\n\n\t\t\t enter your choice number:";
	cin>>c;
	switch(c)
	{
		case '1':clrscr();
       /*outtext()*/	 cout<<"\n\t\t\t\t ADMIN LOGIN";

			 cout<<"\n\n\n\n\t\t enter username:"<<endl<<"\t\t\t";gets(nm);
			 cout<<"\n\n\n\n\t\t enter password"<<endl<<"\t\t\t";enterpassword(psw);
			 forward=ad.match(nm,psw);cout<<"\n forward:"<<forward;
			 break;

		case '2':cout<<"\n\t\t\t USER SIGNUP";
			 signup();break;

		case '3':clrscr();
			 cout<<"\n\n\n\t\t\t enter username:"<<endl<<"\t\t\t";gets(nm);
			 cout<<"\n\n\n\t\t\t enter password"<<endl;
			 cout<<"\t\t\t";enterpassword(psw);
			 forward=login(nm,psw);
			 cout<<"\n forward:"<<forward;
			 break;

		case '4':cout<<"\n\n press enter";getch();exit(0);

		default:cout<<"\n wrong choice";break;



	}

	switch(forward)
	{
		case 0:break;
		case 1:admin_menu();break;
		case 2:udel=0;user_menu();forward=0;
		       break;
		default:;
	}
	y='y';
	}while(y=='y' || y=='Y');
	getch();
} //....main over....


void seeusers()         //for admin_menu
	{
		user u;
		fstream fp;
		fp.open("user.dat",ios::binary|ios::in);
		while( fp.read((char*)&u,sizeof(user)) )
		{q++;u.seedetails();
		 cout<<"\n\t\t************"<<endl;
		}
		fp.close();
		if(countusers()==0)cout<<"\n\t\tempty";getch();clrscr();
	}

void adel()
{
	if(countusers()==0){cout<<"\n\n\t\t no users";return;}
	fstream fp,fp1,fp3;
	user u,u1;int flag=0;
	char n[30],ch='n',cnt;


	fp.open("user.dat",ios::binary|ios::in|ios::out);
	cout<<"\n ENTER USERNAME TO BE DELETED:";gets(n);
		fp.read((char*)&u,sizeof(user));
		while(!fp.eof() && flag==0 )
		{if(strcmp(n,u.retusername())==0)
			{flag++;cout<<"\n user details:";u.seedetails();
			 cout<<"\n ARE YOU SURE YOU WANT TO DELETE THIS ACCOUNT?";
			 cout<<"\n ENTER Y/y TO DELETE ACCOUNT ELSE ENTER ANY CHARACTER: ";
			 cin>>ch;
			}
		fp.read((char*)&u,sizeof(user));
		}
	fp.close();
	if(ch=='y')
	{
		cout<<"\n matching:";
		fp1.open("t.dat",ios::out|ios::binary);
		fp3.open("user.dat",ios::out | ios::in| ios::binary);
		fp3.read((char*)&u1,sizeof(user));
		while(!fp3.eof())
		{
			cout<<u1.retusername()<<" | "<<n<<" <<>> ";getch();

			if(strcmp(u1.retusername(),n)!=0)
			{
				fp1.write((char*)&u1,sizeof(user));

			}
			fp3.read((char*)&u1,sizeof(user));

		}
		remove("user.dat");
		rename("t.dat","user.dat");
	}

	else if(flag==0)
		{cout<<"\n\n NAME NOT FOUND";}


fp1.close();fp3.close();

}

void admin_menu()
{	clrscr();
	char y,ch;
do
{

	cout<<"\n\nwhat do you wish to do?"<<endl;
	cout<<"1.see members list"<<endl;
	cout<<"2.delete member's account"<<endl;
	cout<<"3.logout"<<endl;
	cout<<"\n enter choice number:";cin>>ch;

	switch(ch)
	{
		case '1':seeusers();
			 break;
		case '2':adel();break;
		case '3':forward=0;return;
		default:cout<<"\n wrong choice"<<endl;
	}
	y='y';
}while(y=='y' || y=='Y');
clrscr();
}


//user functions

void user_menu()
{
	clrscr();
	char y,ch;
	user u;
do{
	y='y';
	cout<<"\n";
	cout<<"1.take tests"<<endl;
	cout<<"2.see test 1 report"<<endl;
	cout<<"3.see test 2 report"<<endl;
	cout<<"4.change password"<<endl;
	cout<<"5.delete account"<<endl;
	cout<<"6.logout"<<endl;
	cout<<"enter choice number:";cin>>ch;
	switch(ch)
	{
		case '1':taketests(xx);
			 break;
		case '2':see_report1();
			 break;
		case '3':see_report2();
			 break;
		case '4':editpassword();
			 break;
		case '5':del();break;
		case '6':return;
		default:cout<<"\n WRONG CHOICE";
	}
	if(udel!=0)
		{clrscr();return;}
}while(y=='y' || y=='Y');
clrscr();
}

void taketests(user xx)
{
	clrscr();
	fstream fp,fp1;//fp1 for binary file
	char q[600],ch,m;
	int a=0;
	fp.open("TEST11 (1).TXT",ios::in);

	fp.getline(q,600,'*');
	cout<<"\n\n\n\n\n\n"<<q<<":";cin>>m;
	if(m=='n' || m=='N'){fp.close();clrscr();return;}
	clrscr();
	cout<<"\n\n\n\t\t\t IMPORTANT: \n\n\n\t\t PLEASE ENTER YOUR OPTIONS";
	cout<<" VERY CAREFULLY AS YOU \n\n\t\tHAVE ONLY ONE CHANCE OF ATTEMPTING";
	cout<<" EACH QUESTION.\n\n \t\t\t press enter to continue";getch();
	clrscr();

	xx.inctesttaken1();
	xx.setfort1();


	fp1.open("user.dat",ios::out|ios::binary|ios::in);

	fp1.seekp(pos-sizeof(user),ios::beg);      //PUT POINTER LOCATION

	fp.getline(q,600,'*');
	cout<<q<<endl;getch();

	while(!fp.eof() && a<20)
	{
		clrscr();
		int cont=0;
		fp.getline(q,600,'*');
		cout<<"\n\n\n";
		cout<<q<<endl;
		while(cont==0)
		{
			cout<<"\n ENTER CHOICE:";cin>>ch;
			if(ch=='a' || ch=='b')
				{++cont;xx.inct1(ch);}

			else
				{cout<<"\nWRONG OPTION. ENTER AGAIN."<<endl; }
		}
		++a;
	}

	int e=xx.rett1();
	//cout<<"\n number of a's:"<<e;          //simplifying things........
	char w[30];
	strcpy(w,gen_type(e));
	xx.get_f1(w);
	fp.close();
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t \\\\\\TEST 1 OVER.PRESS ANY KEY//////";getch();
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t \\\\\\TEST 2 BEGINS.PRESS ENTER..//////";getch();
	cout<<"\n\n\n\t\t\tIMPORTANT NOTE:"<<endl;
	cout<<"\n\n\tTAKE CARE OF ENTERING OPTIONS IN TEST2,";
	cout<<"\n\n\tAS ANY OF THE OPTIONS a OR b CAN HAVE 'YES' OR ";;
	cout<<"\n\n\t'NO'AND THE ORDER IS NOT FIXED"<<endl;
	cout<<"\n\n\n\t\t\t press enter to begin";getch();

	//TEST 2

	clrscr();
	fstream fp2;
	int b=0;
	xx.inctesttaken2();
	xx.setfort2();

	fp2.open("test22.txt",ios::in);


	fp2.getline(q,600,'*');
	cout<<q<<endl;getch();

	while(!fp2.eof() && b<29)
	{
		clrscr();
		int cont=0;
		fp2.getline(q,600,'*');
		cout<<q<<endl;
		while(cont==0)
		{
			cout<<"\n ENTER CHOICE:";cin>>ch;
			if(ch=='a' || ch=='b')
				{++cont;xx.inct2(ch);}

			else
				{cout<<"\nWRONG OPTION. ENTER AGAIN."<<endl; }
		}
		++b;

	}

	int E=xx.rett2();
	cout<<"\n number of b's:"<<e;          //simplifying things........
	char o[30];
	strcpy(o,gen_type2(E));
	xx.get_f2(o);
	fp1.write((char*)&xx,sizeof(user));
	fp.close();fp2.close();
	clrscr();
	cout<<"\n\n\n\n\t\t\t THANK YOU FOR TAKING OUR TESTS.";
	cout<<"\n\t\t\t YOU CAN SEE YOUR REPORTS NOW...."<<endl;
	getch();clrscr();
}


char* gen_type(int x)
{
	if(x==20)
		return "EXTREMELY INTROVERTED";
	else if(x==19)
		return "VERY INTROVERTED";
	else if(x==18)
		return "QUITE INTROVERTED";
	else if(x==16 || x==17)
		return "SOMEWHAT INTROVERTED";
	else if(x==14 || x==15)
		return "SLIGHTLY INTROVERTED";
	else if(x==12 || x==13)
		return "A SHADE INTROVERTED";
	else if(x==9 || x==10 || x==11)
		return "AMBIVERT/ AVERAGE";
	else  if(x==7 || x==8)
		return "A SHADE EXTROVERTED";
	else if(x==5 || x==6)
		return "SLIGHTLY EXTROVERTED";
	else if(x==3 || x==4)
		return "SOMEWHAT EXTROVERTED";
	else if(x==2)
		return "QUITE EXTROVERTED";
	else if(x==1)
		return "VERY EXTROVERTED";
	else
		return "EXTREMELY EXTROVERTED";

}

void editpassword()
{
	cout<<"\n\n ENTER PASSWORD";
	user u;
	fstream fp;
	fp.open("user.dat",ios::out|ios::binary|ios::in);
	fp.seekp(pos-sizeof(user),ios::beg);
	fp.read((char*)&u,sizeof(user));
	u.createpassword();u.showpassword();
	fp.seekp(pos-sizeof(user),ios::beg);
	fp.write((char*)&u,sizeof(user));
	fp.close();
}

void del()
{
	cout<<"\n enter any character if you wish to stay...";
	cout<<" \n else enter 'y' or 'Y' if you want to leave us";
	cin>>y;
	if(y!='y'){return;}
	fstream fp,fp1;
	user u;
	fp.open("user.dat",ios::out | ios::binary |ios::in);
	fp1.open("t.dat",ios::out|ios::binary);
	fp.read((char*)&u,sizeof(user));
	while(!fp.eof())
	{
		//cout<<xx.retusername()<<"|"<<u.retusername();getch();

		if(strcmp(xx.retusername(),u.retusername())!=0)
		{
			fp1.write((char*)&u,sizeof(user));

		}
		fp.read((char*)&u,sizeof(user));

	}
		fp1.close();fp.close();
		remove("user.dat");
		rename("t.dat","user.dat");
		udel++;
		clrscr();

}

char* gen_type2(int x)
{      	if(x==29 )
		return "UNSHAKABLE";
	else if(x==28 || x==27)
		return "IMPERTURABLE";
	else if(x==26 || x==25)
		return "UNFLAPPABLE";
	else if(x==24 || x==23)
		return "CALM";
	else if(x==22 || x==21)
		return "BALANCED";
	else if(x==20 || x==19 || x==18)
		return "STEADY";
	else if(x==17 || x==16 || x==15 || x==14)
		return "AVERAGE";
	else if(x==13 || x==12 ||x==11)
		return "SYMPATHETIC";
	else  if(x==10 || x==9)
		return "SUGGESTIBLE";
	else if(x==8 || x==7)
		return "EMOTIONAL";
	else if(x==6 || x==5)
		return "SENSITIVE";
	else if(x==4 || x==3)
		return "OVERSENSITIVE";
	else if(x==2 || x==1)
		return "NERVOUS";
	else
		return"NEUROTIC";

}

void see_report1()
{
	user u;
	int x=0;
	fstream fp;
	fp.open("user.dat",ios::out|ios::binary|ios::in);
	fp.seekp(pos-sizeof(user),ios::beg);
	fp.read((char*)&u,sizeof(user));
	if(u.ret_testtaken1()==0)
		{cout<<"\n take test first";return;}
	clrscr();
	cout<<"\n\n\n\t\t press enter each time cursor pauses..."<<endl;getch();
	clrscr();
	cout<<"\n\n\t\t YOUR PERSONALITY JUDGED BY TEST 1:"<<u.rettype1();
	cout<<"\n\n\t\t number of a's:"<<u.rett1()<<"\t\t number of b's:"<<20-u.rett1();

	cout<<"\n\n\n";
	fstream fp1;
	char data[400];
	fp1.open("report1.txt",ios::in);
	fp1.getline(data,400,'*');
	while(!fp1.eof())
	{puts(data);getch();fp1.getline(data,400,'*');x++;}

	fp1.close();fp.close();
	cout<<"\n press enter to continue.....";getch();clrscr();
}

void see_report2()
{
	user u;
	fstream fp;
	fp.open("user.dat",ios::out|ios::binary|ios::in);

	fp.seekp(pos-sizeof(user),ios::beg);
	fp.read((char*)&u,sizeof(user));
	if(u.ret_testtaken2()==0)
		{cout<<"\n take test first";return;}
	clrscr();
	cout<<"\n\n\n\t\t press enter each time to continue reading your report...";
	getch();
	clrscr();
	cout<<"\n\n\t\t YOUR PERSONALITY JUDGED BY TEST 1:"<<u.rettype2();
	cout<<"\n\n\t\t NUMBER OF b's:"<<u.rett2()<<"\t\t NUMBER OF a's:"<<29-u.rett2();
	cout<<"\n\n";
	fstream fp1;
	char data[400];
	fp1.open("report2.txt",ios::in);
	fp1.getline(data,400,'*');
	while(!fp1.eof())
	{cout<<data;getch();fp1.getline(data,400,'*');}
	fp1.close();fp.close();
	cout<<"\n press enter to continue.....";getch();clrscr();
}


























