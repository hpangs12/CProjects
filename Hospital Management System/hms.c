#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>


struct doctor
{
	int docid;
	char name[30];
	char gender[10];
	char add[50];
	char spec[30];
	char phone[30];
	char username[30];
	char  password[30];
}doc;

struct app
{
	char name[30];
	char add[30];
	int dd,mm,yy;
	char doc[30];
}app;
struct user
{
	char name[30];
	char email[100];
	char username[100];
	char password[100];
}pat;

struct ipd
{
	int pid;
	char name[30];
	int age;
	char gen[10];
	float con;
	char doc[30];
	char add[50];
	int room;
	int dd,mm,yy;
	int dd1,mm1,yy1;	
}s;

struct opd
{
	int pid;
	char name[30];
	int age;
	char gen[10];
	float con;
	char doc[30];
	char add[50];
	int dd,mm,yy;			
}op;

struct room
{
	int id;
	char type[30];
	char avail[30];
}room;

struct opbill
{
	int billno;
	int patid;
	char patname[30];
	int age;
	char gender[30];
	int dd,mm,yy;
	float lab,doc,total;
	
}b1;

struct ipbill
{
	int billno;
	int patid;
	char patname[30];
	int age;
	char gender[30];
	int room;
	int dd,mm,yy,dd1,mm1,yy1;
	float lab,doc,roomc,total;
}b2;

struct test
{
	char  name[30];
	char  add[30];
	char type[30];
	int dd,mm,yy;
	char doc[30];	
}t1;

struct labr
{
	char  name[30];
	char  add[30];
	char type[30];
	int dd,mm,yy;
	char doc[30];
	char state[30];
}t2;

struct pres
{
	char doc[30];
	char date[30];
	char patname[30];
	char dob[30];
	char gender[30];
	int age;
	char add[30];
	char pres[300];
	
}p;

struct birth
{
	int sno;
	int dd,mm,yy;
	char time[30];
	char place[30];
	char mother[30];
	char father[30];
	char pcontact[30];
	char sex[30];
}b;

struct death
{
	int sno;
	char name[30];
	int dd,mm,yy,dd1,mm1,yy1;
	char time[30];
	char rcontact[30];
	char sex[30];
}d;

int pasize=sizeof(pat);
int p_size=sizeof(s);
int doc_size=sizeof(doc);
int r_size=sizeof(room);
int app_size=sizeof(app);
int op_size=sizeof(op);
int ob_size=sizeof(b1);
int ib_size=sizeof(b2);
int t_size=sizeof(t1);
int t1_size=sizeof(t2);
int p1_size=sizeof(p);
int b_size=sizeof(b);
int d_size=sizeof(d);

void adddoc();
void viewdoc();
void penapp();
void disdoc();
void ipd();
void opd();
void takeapp();
void addroom();
void docsch();
void disipd();
void disopd();
void mguser();
void mgdocs();
void docrep();
void repo();
void patrep();
void genop();
void genip();
void viewib();
void viewob();
void aplab();
void mglbs();
void vlabs();
void slabs();
void uplabs();
void vlabr();
void uppres();
void vpres();
void modip();
void modop();
void updip();
void updop();
void upddoc();
void delip();
void moddoc();
void modroom();
void delop();
void deldoc();
void updroom();
void delroom();
void mgdbr();
void disroom();
void labrep();
void bdrep();
void birthrep();
void deathrep();
void addb();
void disb();
void delb();
void uvpres();
void ubill();
void addd();
void disd();
void deld();
void roomrep();
void ulabr();

void main()
{

	char a[30],b[30];
	int end;
	int choice=100;
	int i,one,c=0;
	char cont='Y';
	int count;
	const int maxpass=8;
	char uname[20];
    char pass[maxpass+1],pass2[maxpass+1],pass3[maxpass+1];
    char ch;
    FILE *fp;
    main:
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\t\t\t\t\t|   ******  HOSPITAL MANAGEMENT SYSTEM ****** |\n");
   	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\tChoose an option to continue:\n\t\t\t\t");
	printf("1. Login (For Registered Users)\n\t\t\t\t");
	printf("2. Register (For New Users)\n\t\t\t\t");
	scanf("%d",&one);
	switch(one)
	{
		case 1:
		login:	
    	system("cls");
    	printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\t\t\t\t\t|   ******  HOSPITAL MANAGEMENT SYSTEM ****** |\n");
    	printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\t\t\t\t\t\t|   ******  LOGIN PORTAL ****** |\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");

    	printf("\t\t\t\t This is a secure portal, Please Enter Your Credentials:\n\n");
    	printf("\t\t\t\t Enter a type of login to continue:\n");
    	printf("\t\t\t\t> Admin\n\t\t\t\t> Doctor\n\t\t\t\t> Lab Operator\n\t\t\t\t> Patient\n");
		printf("\n\t\t\t\t> Type-  ");
    	scanf("%s",uname);
    	if(strcmp(uname,"Doctor")!=0&&strcmp(uname,"Patient")!=0)
    	{
    		printf("\t\t\t[]Press Space to view password, Tab to continue typing password, Enter to confirm password\n\t\t\t\t> Login Password : ");
			i=0,count=0;
			while(1)
	   		 {
    			ch=getch();
    			tab:
				if(ch==8) //user hits backspace
				{
					if(i>0)
					{
						i--;
						count--;
						pass[i]='\0';
						printf("\b \b");
					}
				}
				else if(ch==9) //user hits tab
				{
					while(i!=0)
					{
						printf("\b \b");
						i--;
					}
					while(i<count)
					{
						printf("*");
						i++;
					}
				}
				else if(ch==32&&i>0) //user hits space
				{
					while(i!=0)
					{
					printf("\b \b");
					i--;
					}
					printf("%s",pass);
					i=count;
					while(1)
					{
						ch=getch();
						if(ch!=9&&ch!=13)
						continue;
						else
						goto tab;
					}
				}
			else if(ch==13) //user hits enter
			{
				while(i!=0)
				{
					printf("\b \b");
					i--;
				}
				while(i<count)
				{
					printf("*");
					i++;
				}
				break;
			}
			else
			{
				if(ch==9)
				{
					continue;
				}
    			if(i<maxpass)
    			{
					pass[i]=ch;
					i++;
					count++;
    				ch='*';
    				printf("%c",ch);
    			}
    			else
    				{
    				printf("Your password exceeds the maximum length\n");
					}
    			}
    		}	
    	}
	if(strcmp(uname,"Admin")==0 && strcasecmp(pass,"abc")==0)
	{	
		printf("\n\n\t\t\t\tLOGIN SUCCESSFUL\n\t\t\t\tPress any key to continue\n\t\t\t\t");
		getch();
		system("cls");		
		while(choice!=0)
		{
			system("cls");
		if(count==1)
		{
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
		}
		adm:
		printf("\t\t\t\t  \t  ****** ADMIN PANEL ****** \t \n");
		count++;
		if(count>1)
		{	
			printf("\t\t\t\t---------------------------------------------\n");
			printf("\t\t\t\t| \t\t MAIN MENU\t\t    |\n");
		}
		printf("\t\t\t\t=============================================\n");
		printf("\t\t\t\t| 1. Add IP Record\t\t\t    |\n");
		printf("\t\t\t\t| 2. Add OP Record\t\t\t    |\n");
		printf("\t\t\t\t| 3. Add Doctor Record\t\t\t    |\n");
		printf("\t\t\t\t| 4. Add Room Record\t\t\t    |\n");
		printf("\t\t\t\t| 5. Manage Doctor Schedule\t\t    |\n");
		printf("\t\t\t\t| 6. Manage Lab Schedule\t\t    |\n");
		printf("\t\t\t\t| 7. Generate IP Bill\t\t\t    |\n");
		printf("\t\t\t\t| 8. Generate OP Bill\t\t\t    |\n");
		printf("\t\t\t\t| 9. View Test Records\t\t\t    |\n");
		printf("\t\t\t\t| 10. View IP records\t\t\t    |\n");
		printf("\t\t\t\t| 11. View OP records\t\t\t    |\n");
		printf("\t\t\t\t| 12. View IP Bill\t\t\t    |\n");	
		printf("\t\t\t\t| 13. View OP Bill\t\t\t    |\n");
		printf("\t\t\t\t| 14. View Doctor Records\t\t    |\n");	
		printf("\t\t\t\t| 15. Modify IP records\t\t\t    |\n");
		printf("\t\t\t\t| 16. Modify OP records\t\t\t    |\n");
		printf("\t\t\t\t| 17. Modify Doctor Records\t\t    |\n");
		printf("\t\t\t\t| 18. Modify Room Records\t\t    |\n");
		printf("\t\t\t\t| 19. Pending Appointments\t\t    |\n");
		printf("\t\t\t\t| 20. Manage User\t\t\t    |\n");
		printf("\t\t\t\t| 21. Reports\t\t\t    |\n");
		printf("\t\t\t\t| 22. Manage Death and Birth Records\t    |\n");	
		printf("\t\t\t\t| 23. Switch User\t\t\t    |\n");
		printf("\t\t\t\t| 0. To exit\t\t\t\t    |\n");
		printf("\t\t\t\t=============================================\n");
		printf("\t\t\t\t>- Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{

   		 case 1:
    		ipd();
     		break;
  		case 2:
        	opd();
        	break;
    	case 3:
    	  	adddoc();
        	break;
    	case 4:
     		addroom();
    	    break;
    	case 5:
        	mgdocs();
        	break;
    	case 6:
        	vlabs();
			break;
    	case 7:
        	genip();
        	break;
    	case 8:
        	genop();
		    break;
   		case 9:
        	vlabr();
		    break;
		case 10:
        	disipd();
       		break;
       	case 11:
        	disopd();
		    break;
		case 12:
        	viewib();
		    break;
		case 13:
        	viewob();
		    break;
		case 14:
        	viewdoc();
		    break;
		case 15:
        	modip();
		    break;
		case 16:
        	modop();
		    break;
		case 17:
        	moddoc();
		    break;
		case 18:
        	modroom();
		    break;
		case 19:
        	penapp();
		    break;
		case 20:
        	mguser();
		    break;
		case 21:
        	repo();
		    break;
   		case 22:
   			mgdbr();
   			break;
   		case 23:
   			goto login;
			break;	
		case 0:
        	printf("\t\t\tThank you..!!");
        	break;
    	default:
        	printf("Enter a valid option\n");
        	system("pause");
       		fflush(stdin);
		}
	}
}
else if(strcmp(uname,"Doctor")==0)
{
		fp=fopen("doc.txt","r");
		if(fp==NULL)
		{
			printf("\n\t\t\t\tCan't Login Right Now!\n\t\t\t\t");
			exit(0);
		}
		while(1)
		{
		fread(&doc,doc_size,1,fp);
		if(feof(fp))
		{
			break;
		}
			system("cls");
			doc1:
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t  \t ****** DOCTOR LOGIN ****** \t \n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\n\t\t\t\t  Enter Username:\n\t\t\t\t  ");
			scanf("%s",uname);
			printf("\n\t\t\t[]Press Space to view password, Tab to continue typing password, Enter to confirm password\n\n\t\t\t\t  Login Password :\n\t\t\t\t  ");
			i=0,count=0;
			while(1)
	   		 {
    			ch=getch();
    			tab1:
				if(ch==8) //user hits backspace
				{
					if(i>0)
					{
						i--;
						count--;
						pass3[i]='\0';
						printf("\b \b");
					}
				}
				else if(ch==9) //user hits tab
				{
					while(i!=0)
					{
						printf("\b \b");
						i--;
					}
					while(i<count)
					{
						printf("*");
						i++;
					}
				}
				else if(ch==32&&i>0) //user hits space
				{
					while(i!=0)
					{
					printf("\b \b");
					i--;
					}
					printf("%s",pass3);
					i=count;
					while(1)
					{
						ch=getch();
						if(ch!=9&&ch!=13)
						continue;
						else
						goto tab1;
					}
				}
			else if(ch==13) //user hits enter
			{
				while(i!=0)
				{
					printf("\b \b");
					i--;
				}
				while(i<count)
				{
					printf("*");
					i++;
				}
				break;
			}
			else
			{
				if(ch==9)
				{
					continue;
				}
    			if(i<maxpass)
    			{
					pass3[i]=ch;
					i++;
					count++;
    				ch='*';
    				printf("%c",ch);
    			}
    			else
    				{
    				printf("Your password exceeds the maximum length\n");
					}
    			}
    		}
		
			if(strcmp(doc.username,uname)==0&&strcasecmp(doc.password,pass3)==0)
			{
			printf("\n\n\t\t\t\tLOGIN SUCCESSFUL\n\t\t\t\tPress any key to continue\n\t\t\t\t");
			getch();
			system("cls");
				while(choice!=0)
				{
				system("cls");
			printf("\t\t\t\t  \t  ****** DOCTOR PANEL ****** \t \n");
			printf("\t\t\t\t-------------------------------------------\n");
			printf("\t\t\t\t| \t\t MAIN MENU\t\t  |\n");
		
			printf("\t\t\t\t===========================================\n");
			printf("\t\t\t\t| 1. View Appointments\t\t\t  |\n");
			printf("\t\t\t\t| 2. Upload Prescriptions\t\t  |\n");	
			printf("\t\t\t\t| 3. Switch User\t\t\t  |\n");		
			printf("\t\t\t\t| 0. To exit\t\t\t\t  |\n");
			printf("\t\t\t\t===========================================\n");
			printf("\t\t\t\t>- Enter choice : ");
			scanf("%d",&choice);
			switch(choice)
			{

   			case 1:
    	   		docsch();
     	 		break;
  			case 2:
        		uppres();
        		break;
    		case 3:
    			goto login;
    			break;
    		case 0:
        		printf("\n\t\t\t \tThank you..!!");
        		break;
    		default:
        		printf("Enter a valid option\n");
        		system("pause");
       			fflush(stdin);
       		}
       	}
   	}
   	else
   	{
   		printf("\n\n\t\t\t\t\tInvalid Username or Password!\n");
		printf("\n\t\t\t Enter 1 to Re-Enter Credentials || Enter Any other key to Exit\n\t\t\t");
		scanf("%d",&end);
		if(end==1)
		{
			goto doc1;
		}
		else
		{
			exit(0);
		}	
	}
}
fclose(fp);
	
}
else if(strcmp(uname,"LabOperator")==0 && strcasecmp(pass,"abc")==0)
{
			printf("\n\n\t\t\t\tLOGIN SUCCESSFUL\n\t\t\t\tPress any key to continue\n\t\t\t\t");
			getch();
			system("cls");
			while(choice!=0)
		{
			system("cls");
			printf("\t\t\t\t  \t  ****** LAB PANEL ****** \t \n");
			printf("\t\t\t\t-------------------------------------------\n");
			printf("\t\t\t\t| \t\t MAIN MENU\t\t  |\n");
		
			printf("\t\t\t\t===========================================\n");
			printf("\t\t\t\t| 1. View Lab Schedule\t\t\t  |\n");
			printf("\t\t\t\t| 2. Upload Lab Reports\t\t\t  |\n");
			printf("\t\t\t\t| 3. View Lab Reports\t\t\t  |\n");
			printf("\t\t\t\t| 4. View Prescriptions\t\t\t  |\n");	
			printf("\t\t\t\t| 5. Switch User\t\t\t  |\n");		
			printf("\t\t\t\t| 0. To exit\t\t\t\t  |\n");
			printf("\t\t\t\t===========================================\n");
			printf("\t\t\t\t>- Enter choice : ");
			scanf("%d",&choice);
			switch(choice)
			{

   			case 1:
    	   		slabs();
     	 		break;
  			case 2:
        		uplabs();
        		break;
    		case 3:
    	  		vlabr();
        		break;
    		case 4:
     			vpres();
    	    	break;
    		case 5:
    			goto login;
    			break;
    		case 0:
        		printf("\n\t\t\t \tThank you..!!");
        		break;
    		default:
        		printf("Enter a valid option\n");
        		system("pause");
       			fflush(stdin);
       		}
       	}
	
}
else if(strcmp(uname,"Patient")==0)
{
		fp=fopen("pat.txt","r");
		pat1:
		rewind(fp);
		system("cls");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t  \t ****** PATIENTS LOGIN ****** \t \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t  Enter Username:\n\t\t\t\t  ");
		scanf("%s",uname);
		printf("\n\n\t\t\t\t  Login Password :\n\t\t\t\t  ");
		scanf("%s",pass2);
		while(1)
		{
		
			fread(&pat,pasize,1,fp);
			if(feof(fp))
			{
				break;
			}
		
			
			if(strcmp(pat.username,uname)==0&&strcasecmp(pat.password,pass2)==0)
			{
			c=1;
			printf("\n\n\t\t\t\tLOGIN SUCCESSFUL\n\t\t\t\tPress any key to continue\n\t\t\t\t");
			getch();
			system("cls");
			while(choice!=0)
			{
			system("cls");
			printf("\t\t\t\t  \t ****** PATIENTS PANEL ****** \t \n");
			printf("\t\t\t\t-------------------------------------------\n");
			printf("\t\t\t\t| \t\t MAIN MENU\t\t  |\n");
		
			printf("\t\t\t\t===========================================\n");
			printf("\t\t\t\t| 1. List of Doctors\t\t\t  |\n");
			printf("\t\t\t\t| 2. Take Appointment\t\t\t  |\n");
			printf("\t\t\t\t| 3. Apply for lab test\t\t\t  |\n");
			printf("\t\t\t\t| 4. View Bill\t\t\t\t  |\n");	
			printf("\t\t\t\t| 5. View Lab Report\t\t\t  |\n");		
			printf("\t\t\t\t| 6. View Prescription from Doctor\t  |\n");				
			printf("\t\t\t\t| 7. Switch User\t\t\t\t  |\n");
			printf("\t\t\t\t| 0. To exit\t\t\t\t  |\n");
			printf("\t\t\t\t===========================================\n");
			printf("\t\t\t\t>- Enter choice : ");
			scanf("%d",&choice);
			switch(choice)
			{

   			case 1:
    	   		disdoc();
     	 		break;
  			case 2:
        		takeapp();
        		break;
    		case 3:
    	  		aplab();
        		break;
    		case 4:
     			ubill();
    	    	break;
    		case 5:
    			ulabr();
    			break;
    		case 6:
    			uvpres();
    			break;
			case 7:
    			goto login;
    			break;
    		case 0:
        		printf("\n\t\t\t \tThank you..!!");
        		break;
    		default:
        		printf("Enter a valid option\n");
        		system("pause");
       			fflush(stdin);
       		}
       	}
      }
     
	  }
	  	if(c==0)
      {
   		printf("\n\n\t\t\t\t\tInvalid Username or Password!\n");
		printf("\n\t\t\t Enter 1 to Re-Enter Credentials || Enter Any other key to Exit\n\t\t\t");
		fflush(stdin);
		scanf("%d",&end);
		if(end==1)
		{
			goto pat1;
		}
		else
		{
			exit(0);
		}	
	}
	fclose(fp);
	
}
else
{
	printf("\n\n\t\t\t\t\tInvalid Username or Password!\n");
	printf("\n\t\t\t Enter 1 to Re-Enter Credentials || Enter Any other key to Exit\n\t\t\t");
		scanf("%d",&end);
		if(end==1)
		{
			goto login;
		}
		else
		{
			exit(0);
		}
}
	break;
	case 2:
	
		fp=fopen("pat.txt","a");
		printf("------------------------------------------------------------------------------------------------------------------------");
		printf("\t\t\t\t\t|   ******  Registration Portal ****** |\n");
    	printf("------------------------------------------------------------------------------------------------------------------------");
    	printf("\n\t\t\t\t\tEnter Name:\n\t\t\t\t\t");
    	fflush(stdin);
		scanf("%[^\n]s",pat.name);
    	printf("\n\t\t\t\t\tEnter E-Mail:\n\t\t\t\t\t");
    	scanf("%s",pat.email);
		printf("\n\t\t\t\t\tEnter a Username:\n\t\t\t\t\t");
    	scanf("%s",pat.username);
    
		printf("\n\t\t\t\t\tEnter a Password (Alphanumeric):\n\t\t\t\t\t");
		scanf("%s",pat.password);
		fwrite(&pat,pasize,1,fp);
		fclose(fp);
		printf("\n\t\t\t\tAccount Created!\n");
		printf("\n\n\t\t\t\tWant To Continue:\n");
		printf("\n\t\t\t\t 1. YES\n\t\t\t\t 2.NO\n\t\t\t");
		scanf("%d",&end);
		if(end==1)
		{
			goto main;
		}
		else
		{
			exit(0);
		}
		break;
		
		default:
			printf("\n\t\t\t\tInvalid choice!\n");
			printf("\t\t\t\tPress any key to try again.\n\t\t\t\t");
			getch();
			goto main;
}
}
void ipd()
{
	FILE *fp,*fp1;
    struct ipd p;
    int c=0,choice;
    char another='Y';
    fp = fopen("ipd.txt","ab");
    fp1=fopen("room.txt","r");
    if(fp==NULL)// null in c is nothing but ((void*)0) ; nullptr for c++
    {
        printf("\nCannot open file\n");
        exit(0);
    }
    	if(fp1==NULL)
	{
		printf("\n\t\t\t\tCan't Open File!\n\t\t\t\t");
		exit(0);
	}
    while(another=='Y')
    {

        system("cls"); //this will clear the entire screen
        printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t| \t\t *** ADD RECORDS ***\t\t  |\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t <> Enter PatientID. = ");
        scanf("%d",&p.pid);
        printf("\n\t\t\t\t <> Enter Name = ");
        fflush(stdin);
        scanf("%[^\n]s",p.name);
        printf("\n\t\t\t\t <> Enter Age = ");
        scanf("%d",&p.age);
        printf("\n\t\t\t\t <> Enter Gender = ");
        fflush(stdin);
        scanf("%s",p.gen);
        printf("\n\t\t\t\t <> Enter contact = ");
        scanf("%f",&p.con);
        printf("\n\t\t\t\t <> Enter Doctor = ");
        scanf("%s",p.doc); 
		printf("\n\t\t\t\t <> Enter Address = ");
        fflush(stdin);
        scanf("%[^\ns]",p.add);
        printf("\n\t\t\t\t <> Enter Room No = ");
        scanf("%d",&p.room);
		printf("\n\t\t\t\t <> Enter Date of Admission = ");
        scanf("%d/%d/%d",&p.dd,&p.mm,&p.yy);
        printf("\n\t\t\t\t <> Enter Date of Discharge = ");
      	scanf("%d/%d/%d",&p.dd1,&p.mm1,&p.yy1);
      	enter:
    	rewind(fp1);
		  while(1)
      	{
      		fread(&room,r_size,1,fp1);
      		if(feof(fp1))
      		{
      			break;
      	    }
		 	if(p.room==room.id)
		 	{
				c++; 
      		if(strcmp(room.avail,"Available")==0)
      		{
	  	 	    fwrite(&p,p_size,1,fp);
    		    printf("\n");	
			    break;
    		}
    		else
    		{
    			printf("\n\t\t\t\tRoom not Available! Enter again:\n\t\t\t\t");
				scanf("%d",&p.room);
			}
		}
 	}
 	if(c==0)
 	{
 		printf("\n\t\t\t\tRoom Record not found\n\t\t\t\t");
		printf("\n\t\t\t\tEnter 1 to enter AgaiN:\n\t\t\t\t");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\n\t\t\t\tEnter Room:\n\t\t\t\t");
			scanf("%d",&p.room);
			goto enter;
		}
		else
		{
			exit(0);
		}
	}
		   printf("\n\t\t\t\t /Want to Enter Another Record (Y/N)? : ");
        	fflush(stdin);// required
        	scanf("%c",&another);
    		system("cls");
	}
    fclose(fp);
    fclose(fp1);
}
void disipd()
{

	FILE *fp;
    struct ipd p1;
    fp = fopen("ipd.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    system("cls");
    printf("\n\t       *********************************** DETAILS ***************************************\n");
    printf("\n");
    printf("=======================================================================================================");
    printf("\n| PID\t|  Name\t|  Gender   |  Contact    |  Address\t|  Room  No |  Age \t|   Doctor    |   DOA   |   DOD   |\n");
    printf("=======================================================================================================");
    printf("\n");
    while(1)
    {

        fread(&p1,p_size,1,fp);
        if(feof(fp))
            break;
        printf("|%d\t",p1.pid);
        printf(" %s     ",p1.name);
        printf("%s\t",p1.gen);
        printf("%0.0f\t  ",p1.con);
        printf(" %s     ",p1.add);
		printf("  %d\t",p1.room);
		printf("       %d\t",p1.age);
		printf("   %s   ",p1.doc);
        printf("%d/%d/%d\t ",p1.dd,p1.mm,p1.yy);
        printf("%d/%d/%d\t ",p1.dd1,p1.mm1,p1.yy1);
        printf("\n");
    }
    printf("\t==============================================================================================\n\t");
    system("pause");
    system("cls");
    fclose(fp);
}
void adddoc()
{
	FILE *fp;
	fp=fopen("doc.txt","w");
	system("cls");
		if(fp==NULL)
	{
		printf("\n\t\t\t\tCan't Open File!\n\t\t\t\t");
		exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** ADD DOCTOR RECORDS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter Doctor ID:\n\t\t\t\t");
	scanf("%d",&doc.docid);
	printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
	fflush(stdin);
	scanf("%[^\n]s",doc.name);
	printf("\n\t\t\t\tEnter Gender:\n\t\t\t\t");
	fflush(stdin);
	scanf("%s",doc.gender);
	fflush(stdin);
	printf("\n\t\t\t\tEnter Address:\n\t\t\t\t");
	fflush(stdin);
	scanf("%[^\n]s",doc.add);
	printf("\n\t\t\t\tEnter Speciality:\n\t\t\t\t");
	fflush(stdin);
	scanf("%[^\n]s",doc.spec);
	fflush(stdin);	
	printf("\n\t\t\t\tEnter Phone:\n\t\t\t\t");
	scanf("%s",doc.phone);
	fflush(stdin);	
	printf("\n\t\t\t\tEnter Username:\n\t\t\t\t");
	scanf("%s",doc.username);
	fflush(stdin);	
	printf("\n\t\t\t\tEnter Password:\n\t\t\t\t");
	scanf("%s",doc.password);
	fwrite(&doc,doc_size,1,fp);
	fclose(fp);
}
void addroom()
{
	FILE *fp;
	fp=fopen("room.txt","a");
	system("cls");
		if(fp==NULL)
	{
		printf("\n\t\t\t\tCan't Open File!\n\t\t\t\t");
		exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** ADD ROOM RECORDS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter Room ID:\n\t\t\t\t");
	scanf("%d",&room.id);
	printf("\n\t\t\t\tEnter Room Type:\n\t\t\t\t");
	scanf("%s",room.type);
	printf("\n\t\t\t\tEnter Room Availability:\n\t\t\t\t");
	scanf("%s",room.avail);
	fwrite(&room,r_size,1,fp);
	fclose(fp);
}
void disdoc()
{
	FILE *fp;
	fp=fopen("doc.txt","r");
	system("cls");
	while(1)
	{
		if(fp==NULL)
	{
		printf("\n\t\t\t\tCan't Open File!\n\t\t\t\t");
		break;
	}
		fread(&doc,doc_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** DOCTORS LIST ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\tDoctor Name\t|\tSpecialization\t|\tExperience\t|\n");
	printf("\n\t\t%s\t\t\t%s\t\t\t%s\n",doc.name,doc.spec,doc.gender);
	}
	fclose(fp);
	getch();
}

void takeapp()
{
	FILE *fp;
	fp=fopen("app.txt","a");
	system("cls");	
		if(fp==NULL)
	{
		printf("\n\t\t\t\tCan't Open File!\n\t\t\t\t");
		exit(0);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** MAKE APPOINTMENT ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");	
	printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
	fflush(stdin);
	scanf("%s",app.name);
	fflush(stdin);
	printf("\n\t\t\t\tEnter Address:\n\t\t\t\t");
	scanf("%s",app.add);
	printf("\n\t\t\t\tEnter Date:\n\t\t\t\t");
	scanf("%d/%d/%d",&app.dd,&app.mm,&app.yy);
	printf("\n\t\t\t\tEnter Doctor:\n\t\t\t\t");
	scanf("%s",app.doc);
	fwrite(&app,app_size,1,fp);
	fclose(fp);
}

void penapp()
{
	FILE *fp,*fp1,*fp2,*fp3,*fpt;
	char  name[30];
	int type,con,size;
	system("cls");
	app1:
	fp2=fopen("labapp.txt","r");
	fp3=fopen("conlab.txt","a");
	fpt=fopen("temp.txt","w");
	printf("\n\n\t\t\t\tChoose a type to continue:\n\t\t\t\t");
	printf("\n\t\t\t\t1.Doctor Appointment\n\t\t\t\t2.Lab Appointment\n\t\t\t\t");
	scanf("%d",&type);
	switch(type)
	{
		case 1:
		fp=fopen("app.txt","r");
		fp1=fopen("conapp.txt","a");
		if(fp==NULL)
		{
			printf("\n\t\t\tCannot Open File!\n\t\t\t");
			getch();
			break;	
		}
		else
		{
			fseek (fp, 0, SEEK_END);
   			size = ftell(fp);

   			if (0 == size)
			{
        		printf("\n\t\t\t\tFile is empty\n");
   			}	
		}	
		rewind(fp);
		if(size!=0)
		{
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t  \t ****** PENDING APPOINTMENTS ****** \t \n");
		printf("-----------------------------------------------------------------------------------------------------------------------\n");	
		printf("\n\n\t\t\t|  Name\t |  Address\t |  Date\t |  Doctor\t |\n\t\t\t");
		while(1)
		{
			fread(&app,app_size,1,fp);
			if(feof(fp))
			{
				break;
			}
			printf("%s\t ",app.name);
			printf(" %s\t ",app.add);
			printf(" %d/%d/%d\t ",app.dd,app.mm,app.yy);
			printf(" %s\t |\n",app.doc);
		}
		rewind(fp);
		printf("\n\t\t\t\tEnter an option:\n\t\t\t\t1.Approve an appointment\n\t\t\t\t2.Goto Main Menu\n\t\t\t\t");
		scanf("%d",&con);
		if(con==1)
		{
			printf("\n\t\t\t\tEnter name of Patient to approve:\n\t\t\t\t");
			scanf("%s",name);
			while(1)
			{
				fread(&app,app_size,1,fp);
				if(feof(fp))
				{
					break;
				}
				if(strcmp(name,app.name)==0)
				{
					fwrite(&app,app_size,1,fp1);
				}
				else
				{
					fwrite(&app,app_size,1,fpt);
				}
				
			}
		}
}
		
		fclose(fp);
		fclose(fp1);
		fclose(fpt);
		remove("app.txt");
		rename("temp.txt","app.txt");
		printf("\n\t\t\t\tWant to Continue?\n\t\t\t\t1.Yes\n\t\t\t\t2.No\n\t\t\t\t");
		scanf("%d",&con);
		if(con==1)
		{	
			goto app1;
		}
		else
		{
			break;
		}
		
		case 2:
		
		mglbs();
		break;
		
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
	
}
void docsch()
{
	FILE *fp;
	char  name[30];
	int c=0;
	system("cls");
	fp=fopen("conapp.txt","r");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** APPOINTMENTS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");	

	printf("\n\t\t\t\tEnter your name to continue:\n\t\t\t\t");
	scanf("%s",name);
	printf("-----------------------------------------------------------------------------------------------------------------------\n");	
	printf("\n\n\t\t\t|  Name\t |  Address\t |  Date\t |\n\t\t\t");
	if(fp==NULL)
	{
		printf("NULL");
	}
	while(1)
	{
		fread(&app,app_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(strcmp(app.doc,name)==0)
		{
			c++;
			printf("%s\t  ",app.name);
			printf(" %s\t  ",app.add);
			printf(" %d/%d/%d\t\n\t\t\t\t ",app.dd,app.mm,app.yy);
		}
	}
	getch();
	if(c==0)
	{
		printf("\n\t\t\t\tThere are no appointments sheduled for Today.\n\t\t\t\t");
	}
	
}
void opd()
{
	FILE *fp;
	char another='Y';
	system("cls");
	fp=fopen("opd.txt","a");
	if(fp==NULL)
	{
		printf("\n\t\t\t\tUnable  To Open file.\n\t\t\t\t");
	}
	while(another=='Y')
	{
		 system("cls"); 
        printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t| \t\t *** ADD RECORDS ***\t\t  |\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t <> Enter PatientID. = ");
        scanf("%d",&op.pid);
        printf("\n\t\t\t\t <> Enter Name = ");
        fflush(stdin);
        scanf("%[^\n]s",op.name);
        printf("\n\t\t\t\t <> Enter Age = ");
        scanf("%d",&op.age);
        printf("\n\t\t\t\t <> Enter Gender = ");
        fflush(stdin);
        scanf("%s",op.gen);
        printf("\n\t\t\t\t <> Enter contact = ");
    	fflush(stdin);
        scanf("%f",&op.con);
        printf("\n\t\t\t\t <> Enter Doctor = ");
        scanf("%s",op.doc); 
		printf("\n\t\t\t\t <> Enter Address = ");
        fflush(stdin);
        scanf("%[^\ns]",op.add);
		printf("\n\t\t\t\t <> Enter Date = ");
        scanf("%d/%d/%d",&op.dd,&op.mm,&op.yy);
       	fwrite(&op,op_size,1,fp);
		printf("\n\t\t\t\t /Want to Enter Another Record (Y/N)? : ");
       	fflush(stdin);
       	scanf("%c",&another);
    	system("cls");
	}
	fclose(fp);
}
void disopd()
{
	FILE *fp;
    fp = fopen("opd.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file\n");
        exit(0);
    }
    system("cls");
    printf("\n\t    *********************************** OPD DETAILS ***************************************\n");
    printf("\n");
    printf("========================================================================================================");
    printf("\n| PID\t|  Name\t   |  Age    | Gender\t|  Contact\t  |  Doctor\t  |  Address\t  |\tDATE\t|\n");
    printf("========================================================================================================");
    printf("\n");
    while(1)
    {

        fread(&op,op_size,1,fp);
        if(feof(fp))
            break;
        printf("|%d\t",op.pid);
        printf(" %s    ",op.name);
        printf("     %d\t",op.age);
        printf(" %s     ",op.gen);
        printf("  %0.0f   ",op.con);
        printf("    %s\t",op.doc);
        printf("      %s\t ",op.add);
	    printf("   %d/%d/%d\t ",op.dd,op.mm,op.yy);
        printf("\n");
    }
    printf("=======================================================================================================\n\t");
    system("pause");
    system("cls");
    fclose(fp);
}
void mguser()
{
	FILE *fp,*fp1;
	int choice,c=0,size;
	char name[30];
	system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t *** MANAGE USERS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n\t\t\t\tEnter a  choice to continue:\n\t\t\t\t");
	printf("1.View all users\n\t\t\t\t2.Delete a user profile\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			system("cls");
			fp=fopen("pat.txt","r");
			if(fp==NULL)
			{
				printf("\n\t\t\t\tCannot Open File!\n\t\t\t\t");
				exit(0);
			}
			while(1)
			{
				fread(&pat,pasize,1,fp);
				if(feof(fp))
				{
					break;
				}
				c++;
				if(c==1)
				{
					printf("\n    *********************************** USER DETAILS ***************************************\n");
  					printf("\n");
  					printf("\n\t  ========================================================================");
					printf("\n\t  |\t  Name      |  \t  E-Mail \t \t  | \t  Username\t |\n");
 					printf("\t  ========================================================================");
				}
				printf("\n\t  |    %s\t",pat.name);
				printf(" \t%s\t",pat.email);
				printf(" %s\t |",pat.username);
				printf("\n");				
			
				printf("\t  ========================================================================");
			}
			if(c==0)
			{
				printf("\n\t\t\t\tNo Records Found!\n\t\t\t");
			}
				fflush(stdin);
				getch();
				fclose(fp);
				break;
				
			case 2:
				fp=fopen("pat.txt","r");
				fp1=fopen("temp.txt","w");
				c=0;
				system("cls");
				if(fp==NULL)
				{
					printf("\n\t\t\t\tCannot Open File!\n");
					exit(0);
				}
				if (NULL != fp) 
				{
    				fseek (fp, 0, SEEK_END);
   				 	size = ftell(fp);

   					if (0 == size)
					{
        				printf("\n\t\t\t\tFile is empty\n");
   					 }
				}
				rewind(fp);
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("\t\t\t\t| \t\t *** REMOVE USERS ***\t\t  |\n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");	
				printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
				scanf("%s",name);
				while(1)
				{
					
					fread(&pat,pasize,1,fp);
					if(feof(fp))
					{
						break;
					}
					if(strcmp(pat.name,name)==0)
					{
						c=1;
					}
					else
					{
						fwrite(&pat,pasize,1,fp1);
					}
				}
				if(c==0)
				{
					printf("\n\t\t\t\tNo Such Name!\n\t\t\t\t");
				}
	
				fclose(fp);
				fclose(fp1);
				remove("pat.txt");
				rename("temp.txt","pat.txt");
				getch();
	}
}
void repo()
{
	int choice;
	printf("\n\t\t\t\tEnter a choice to continue:\n\t\t\t\t");
	printf("\n\t\t\t\t1.Patient Report\n\t\t\t\t2.Doctor  Report\n\t\t\t\t3.Lab Report\n\t\t\t\t4. Room Report\n\t\t\t\t5.Birth and Death Reports\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			patrep();
			break;
		case 2:
			docrep();
			break;
		case 3:
			labrep();
			break;
		case 4:
			roomrep();
			break;
		case 5:
			bdrep();
			break;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
	getch();
}
void patrep()
{
	FILE  *fp,*fp2;
	int choice,dd,mm,yy,dd1,mm1,yy1;
	printf("\n\t\t\t\t|\tPatients Report\t|\n\t\t\t\t");
	printf("\n\n\t\t\t\tChoose an option:\n\t\t\t\t");
	printf("\n\t\t\t\t1.Out-Patients");
	printf("\n\t\t\t\t2.In-Patients\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			fp=fopen("opd.txt","r");
			printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
			scanf("%d/%d/%d",&dd,&mm,&yy);
			printf("\t\t\t\tTo:\n\t\t\t\t");
			fflush(stdin);
			scanf("%d/%d/%d",&dd1,&mm1,&yy1);
			printf("\n\t    *********************************** OPD DETAILS ***************************************\n");
		    printf("\n");
		    printf("========================================================================================================");
   			printf("\n| PID\t|  Name\t   |  Age    | Gender\t|  Contact\t  |  Doctor\t  |  Address\t  |\tDATE\t|\n");
    		printf("========================================================================================================");
    		printf("\n");
			while(1)
			{
				fread(&op,op_size,1,fp);
				if(feof(fp))
				{
					break;
				}
				if(op.yy>yy&&op.yy<yy1)
				{
					printf("|%d\t",op.pid);
        			printf(" %s    ",op.name);
        			printf("     %d\t",op.age);
        			printf(" %s     ",op.gen);
        			printf("  %0.0f   ",op.con);
        			printf("    %s\t",op.doc);
        			printf("      %s\t ",op.add);
	    			printf("   %d/%d/%d\t ",op.dd,op.mm,op.yy);
        			printf("\n");
				}
				else if(op.yy==yy||op.yy==yy1)
				{
					if(op.mm>=mm&&op.mm<=mm1)
					{
						if(op.dd>=dd&&op.dd<=dd1)
						{
							printf("|%d\t",op.pid);
        					printf(" %s    ",op.name);
        					printf("     %d\t",op.age);
        					printf(" %s     ",op.gen);
        					printf("  %0.0f   ",op.con);
        					printf("    %s\t",op.doc);
        					printf("      %s\t ",op.add);
	    					printf("   %d/%d/%d\t ",op.dd,op.mm,op.yy);
        					printf("\n");
						}
					}
				}
		
			}
			fclose(fp);
			break;
			
		case 2:
			fp=fopen("ipd.txt","r");
			printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
			scanf("%d/%d/%d",&dd,&mm,&yy);
			printf("\t\t\t\tTo:\n\t\t\t\t");
			fflush(stdin);
			scanf("%d/%d/%d",&dd1,&mm1,&yy1);
			system("cls");
			printf("\n\t       *********************************** DETAILS ***************************************\n");
    		printf("\n");
    		printf("=======================================================================================================");
    		printf("\n| PID\t|  Name\t|  Gender   |  Contact    |  Address\t|  Room  No |  Age \t|   Doctor    |   DOA   |   DOD   |\n");
    		printf("=======================================================================================================");
    		printf("\n");
    		while(1)
    		{
    			fread(&s,p_size,1,fp);
    			if(feof(fp))
    			{
    				break;
				}
				if(s.yy>yy&&s.yy1<yy1)
				{
					printf("|%d\t",s.pid);
        			printf(" %s     ",s.name);
        			printf("%s\t    ",s.gen);
        			printf("%0.0f\t  ",s.con);
        			printf(" %s\t ",s.add);
					printf("  %d\t",s.room);
					printf("       %d\t",s.age);
					printf("   %s   ",s.doc);
        			printf("%d/%d/%d\t ",s.dd,s.mm,s.yy);
        			printf("%d/%d/%d\t ",s.dd1,s.mm1,s.yy1);
        			printf("\n");
				}
				else if(s.yy==yy||s.yy1==yy1)
				{
					if(s.mm>=mm&&s.mm1<=mm1)
					{
						if(s.dd>=dd&&s.dd1<=dd1)
						{
							printf("|%d\t",s.pid);
        					printf(" %s     ",s.name);
        					printf("%s\t    ",s.gen);
        					printf("%0.0f\t  ",s.con);
        					printf(" %s\t ",s.add);
							printf("  %d\t",s.room);
							printf("       %d\t",s.age);
							printf("   %s   ",s.doc);
        					printf("%d/%d/%d\t ",s.dd,s.mm,s.yy);
        					printf("%d/%d/%d\t ",s.dd1,s.mm1,s.yy1);
        					printf("\n");	
						}
					}
				}
			}
			fclose(fp);
			break;
		default:
			printf("\n\n\t\t\t\tWrong Choice!\n");
			
	}
		
}
void docrep()
{
	char doc[30];
	FILE  *fp,*fp2;
	int c=0,choice,dd,mm,yy,dd1,mm1,yy1;
	printf("\n\t\t\t\t|\tDoctor Report\t|\n\t\t\t\t");
	printf("\n\n\t\t\t\tChoose an option:\n\t\t\t\t");
	printf("\n\t\t\t\t1.Out-Patients");
	printf("\n\t\t\t\t2.In-Patients\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			fp=fopen("opd.txt","r");
			printf("\n\t\t\t\tEnter the doctor name:\n\t\t\t\t");
			scanf("%s",doc);
			printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
			scanf("%d/%d/%d",&dd,&mm,&yy);
			printf("\t\t\t\tTo:\n\t\t\t\t");
			fflush(stdin);
			scanf("%d/%d/%d",&dd1,&mm1,&yy1);
			printf("\n\t    *********************************** OPD DETAILS ***************************************\n");
		    printf("\n");
		    printf("========================================================================================================");
   			printf("\n| PID\t|  Name\t   |  Age    | Gender\t|  Contact\t  |  Doctor\t  |  Address\t  |\tDATE\t|\n");
    		printf("========================================================================================================");
    		printf("\n");
			while(1)
			{
				fread(&op,op_size,1,fp);
				if(feof(fp))
				{
					break;
				}
			if(strcmp(op.doc,doc)==0)
			{
				c++;
				if(op.yy>yy&&op.yy<yy1)
				{
				printf("|%d\t",op.pid);
        		printf(" %s    ",op.name);
        		printf("     %d\t",op.age);
        		printf(" %s     ",op.gen);
       			printf("  %0.0f   ",op.con);
        		printf("    %s\t",op.doc);
       			printf("      %s\t ",op.add);
	   			printf("   %d/%d/%d\t ",op.dd,op.mm,op.yy);
       			printf("\n");
				}
				
				else if(op.yy==yy||op.yy==yy1)
				{
					if(op.mm>=mm&&op.mm<=mm1)
					{
						if(op.dd>=dd&&op.dd<=dd1)
						{
							printf("|%d\t",op.pid);
        					printf(" %s    ",op.name);
        					printf("     %d\t",op.age);
        					printf(" %s     ",op.gen);
        					printf("  %0.0f   ",op.con);
        					printf("    %s\t",op.doc);
        					printf("      %s\t ",op.add);
	    					printf("   %d/%d/%d\t ",op.dd,op.mm,op.yy);
        					printf("\n");
						}
					}
				}
		
			}
			}
			if(c==0)
			{
				printf("\n\t\t\t\tNo Record Found!\n\t\t\t\t");
			}
			else
			{
				printf("\n\n\t\t\t%d Records were Found!\n\t\t\t",c);
			}
			c=0;
			fclose(fp);
			break;
		
		case 2:
			fp=fopen("ipd.txt","r");
			printf("\n\t\t\t\tEnter Doctor Name:\n\t\t\t\t");
			scanf("%s",doc);
			printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
			scanf("%d/%d/%d",&dd,&mm,&yy);
			printf("\t\t\t\tTo:\n\t\t\t\t");
			fflush(stdin);
			scanf("%d/%d/%d",&dd1,&mm1,&yy1);
			system("cls");
			printf("\n\t       *********************************** DETAILS ***************************************\n");
    		printf("\n");
    		printf("=======================================================================================================");
    		printf("\n| PID\t|  Name\t|  Gender   |  Contact    |  Address\t|  Room  No |  Age \t|   Doctor    |   DOA   |   DOD   |\n");
    		printf("=======================================================================================================");
    		printf("\n");
    		while(1)
    		{
    			fread(&s,p_size,1,fp);
    			if(feof(fp))
    			{
    				break;
				}
				if(strcmp(s.doc,doc)==0)
				{
					c++;
				if(s.yy>yy&&s.yy1<yy1)
				{
					printf("|%d\t",s.pid);
        			printf(" %s     ",s.name);
        			printf("%s\t    ",s.gen);
        			printf("%0.0f\t  ",s.con);
        			printf(" %s\t ",s.add);
					printf("  %d\t",s.room);
					printf("       %d\t",s.age);
					printf("   %s   ",s.doc);
        			printf("%d/%d/%d\t ",s.dd,s.mm,s.yy);
        			printf("%d/%d/%d\t ",s.dd1,s.mm1,s.yy1);
        			printf("\n");
				}
				else if(s.yy==yy||s.yy1==yy1)
				{
					if(s.mm>=mm&&s.mm1<=mm1)
					{
						if(s.dd>=dd&&s.dd1<=dd1)
						{
							printf("|%d\t",s.pid);
        					printf(" %s     ",s.name);
        					printf("%s\t    ",s.gen);
        					printf("%0.0f\t  ",s.con);
        					printf(" %s\t ",s.add);
							printf("  %d\t",s.room);
							printf("       %d\t",s.age);
							printf("   %s   ",s.doc);
        					printf("%d/%d/%d\t ",s.dd,s.mm,s.yy);
        					printf("%d/%d/%d\t ",s.dd1,s.mm1,s.yy1);
        					printf("\n");	
						}
					}
				}
				}
			}
			if(c==0)
			{
				printf("\n\t\t\t\tNo Record Found!\n\t\t\t\t");
			}
			else
			{
				printf("\n\n\t\t\t%d Records were Found!\n\t\t\t",c);
			}
			c=0;
			fclose(fp);
			break;
		default:
			printf("\n\n\t\t\t\tWrong Choice!\n");	
			
		
	}
}
void mgdocs()
{
	FILE *fp,*fp2;
	char  pname[30];
	int c=0,ch,d=0,cont;
	rem:
	system("cls");
	fp=fopen("conapp.txt","r");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** APPOINTMENTS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");	
	printf("-----------------------------------------------------------------------------------------------------------------------\n");	
	printf("\n\n\t\t\t|  Name\t |  Address\t |  Date\t |\n\t\t\t");
	if(fp==NULL)
	{
		printf("NULL");
	}
	while(1)
	{
		fread(&app,app_size,1,fp);
		if(feof(fp))
		{
			break;
		}
			c++;
			printf("%s\t  ",app.name);
			printf(" %s\t  ",app.add);
			printf(" %d/%d/%d\t\n\t\t\t ",app.dd,app.mm,app.yy);
	}
	getch();
	if(c==0)
	{
		printf("\n\t\t\t\tThere are no appointments.\n\t\t\t\t");
		getch();
	}
	fclose(fp);
	if(c!=0)
	{
		
		printf("\n\t\t\t\tEnter\n\t\t\t\t 1- Remove a schedule\n\t\t\t\t 2. Go Back to Main Menu.\n\t\t\t\t");
		scanf("%d",&ch);
		if(ch==1)
		{		
				fp=fopen("conapp.txt","r");
				fp2=fopen("temp.txt","a");
				system("cls");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("\t\t\t\t  \t ****** REMOVE APPOINTMENTS ****** \t \n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");	
				printf("\n\t\t\t\tEnter the name of the patient to remove:\n\t\t\t\t");
				scanf("%s",pname);
				while(1)
				{
					fread(&app,app_size,1,fp);
					if(feof(fp))
					{
						break;
					}
					if(strcmp(app.name,pname)==0)
					{
						d++;
					}
					else
					{
						fwrite(&app,app_size,1,fp2);
					}
				}
			
				if(d==0)
				{
					printf("\n\t\t\t\tNo Such Name!\n\t\t\t\t");
				}
	
				fclose(fp);
				fclose(fp2);
				remove("conapp.txt");
				rename("temp.txt","conapp.txt");
				printf("\n\t\t\t\tEnter\n\t\t\t1-  Continue\t2- Go to Main Menu\n\t\t\tChoice:  ");
				scanf("%d",&cont);
				if(cont==1)
				{
					goto rem;
				}
				getch();
		
	}
}
	
}
void genop()
{
	FILE *fp,*fp2;
	int c=0,id,cont;
	opb:
	c=0;
	fp=fopen("opd.txt","r");
	fp2=fopen("opbill.txt","a");
	printf("\n\t\t\t\tEnter patid:\n\t\t\t\t");
	scanf("%d",&id);
	while(1)
	{
			fread(&op,op_size,1,fp);
			if(feof(fp))
			{
				break;
			}
			if(op.pid==id)
			{
				c=1;
			}
	}
	fclose(fp);
	if(c!=0)
	{
		c=0;
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t  \t ****** OP BILLING ****** \t \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");	
		b1.patid=id;
		printf("\n\n\t\t\t\tEnter Bill no:\n\t\t\t\t");
		scanf("%d",&b1.billno);
		printf("\n\t\t\t\tEnter name:\n\t\t\t\t");
		scanf("%s",b1.patname);
		fflush(stdin);
		printf("\n\t\t\t\tEnter age:\n\t\t\t\t");
		scanf("%d",&b1.age);
		printf("\n\t\t\t\tEnter gender:\n\t\t\t\t");
		scanf("%s",b1.gender);
		printf("\n\t\t\t\tEnter date:\n\t\t\t\t");
		scanf("%d/%d/%d",&b1.dd,&b1.mm,&b1.yy);
		printf("\n\t\t\t\tEnter Lab Charge:\n\t\t\t\t");
		scanf("%f",&b1.lab);
		printf("\n\t\t\t\tEnter Doctor Charge:\n\t\t\t\t");
		scanf("%f",&b1.doc);
		b1.total=b1.doc+b1.lab;	
		fwrite(&b1,ob_size,1,fp2);	
		fclose(fp2);
	}
	else
	{
		printf("\n\t\t\t\tNo Such patient record found!\n\t\t\t\t");
		printf("Enter 1- Generate another bill\t2-Exit to main menu\n\t\t\t\t");
		scanf("%d",&cont);
		if(cont==1)
		{
			goto opb;
		}
		else
		{
			
		}
	}
	
}

void genip()
{
	FILE *fp,*fp2;
	int c=0,id,cont;
	ipb:
	fp=fopen("ipd.txt","r");
	fp2=fopen("ipbill.txt","a");
	printf("\n\t\t\t\tEnter patid:\n\t\t\t\t");
	scanf("%d",&id);
	while(1)
	{
			fread(&s,p_size,1,fp);
    		if(feof(fp))
    		{
    			break;
			}
			if(s.pid==id)
			{
				c=1;
			}
	}
	fclose(fp);
	if(c!=0)
	{
		c=0;
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t  \t ****** IP BILLING ****** \t \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");	
		b2.patid=id;
		printf("\n\n\t\t\t\tEnter Bill no:\n\t\t\t\t");
		scanf("%d",&b2.billno);
		printf("\n\t\t\t\tEnter name:\n\t\t\t\t");
		scanf("%s",b2.patname);
		fflush(stdin);
		printf("\n\t\t\t\tEnter age:\n\t\t\t\t");
		scanf("%d",&b2.age);
		printf("\n\t\t\t\tEnter gender:\n\t\t\t\t");
		scanf("%s",b2.gender);
		printf("\n\t\t\t\tEnter Room No:\n\t\t\t\t");
		scanf("%f",&b2.room);
		printf("\n\t\t\t\tEnter date of Admission:\n\t\t\t\t");
		scanf("%d/%d/%d",&b2.dd,&b2.mm,&b2.yy);
		printf("\n\t\t\t\tEnter date of Discharge:\n\t\t\t\t");
		scanf("%d/%d/%d",&b2.dd1,&b2.mm1,&b2.yy1);		
		printf("\n\t\t\t\tEnter Lab Charge:\n\t\t\t\t");
		scanf("%f",&b2.lab);
		printf("\n\t\t\t\tEnter Doctor Charge:\n\t\t\t\t");
		scanf("%f",&b2.doc);
		printf("\n\t\t\t\tEnter Room Charge:\n\t\t\t\t");
		scanf("%f",&b2.roomc);
		b2.total=b2.doc+b2.lab+b2.roomc;	
		fwrite(&b2,ib_size,1,fp2);	
		fclose(fp2);
	}
	else
	{
		printf("\n\t\t\t\tNo Such patient record found!\n\t\t\t\t");
		printf("Enter 1- Generate another bill\t2-Exit to main menu\n\t\t\t\t");
		scanf("%d",&cont);
		if(cont==1)
		{
			goto ipb;
		}
		else
		{
			
		}
	}
}

void viewdoc()
{
	FILE *fp;
	int c=0;
	fp=fopen("doc.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		if(fp==NULL)
	{
		printf("\n\t\t\t\tCan't Open File!\n\t\t\t\t");
		break;
	}
		fread(&doc,doc_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		c=1;
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t|     ****** HOSPITAL MANAGEMENT SYSTEM ******     |\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t  \t ****** DOCTORS LIST ****** \t \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\tDoctor Name\t|\tSpecialization\t|\tGender\t|\tPhone\t|\t     Address\t|\n");
		printf("\n\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",doc.name,doc.spec,doc.gender,doc.phone,doc.add);
	}
	fclose(fp);
	if(c=0)
	{
		printf("ERROR");
	}
	getch();
}

void viewib()
{
	FILE *fp;
	int patid,c=0,cont;
	vip:
	c=0;
	fp=fopen("ipbill.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** VIEW IP BILL ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter patient ID:\n\t\t\t\t");
	scanf("%d",&patid);
	while(1)
	{
		fread(&b2,ib_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(b2.patid==patid)
		{
			c=1;
			printf("\n\t\t\tBILL FOR PATIENT ID: %d\n\t\t\t",patid);
			printf("\n\n\t\tBill No: %d\n\t\tName:%s\n\t\tAge:%d\n\t\t\n\t\tGender: %s\n\t\tRoom: %d\n\t\tDOA: %d/%d/%d\n\t\tDOD: %d/%d/%d\n\t\t",b2.billno,b2.patname,b2.age,b2.gender,b2.room,b2.dd,b2.mm,b2.yy,b2.dd1,b2.mm1,b2.yy1);	
			printf("Charges:\n\t\t");
			printf("Lab Charges: %0.2f\n\t\tDoctor Charges: %0.2f\n\t\tRoom Charges: %0.2f\n\t\tTotal Charge: %0.2f\n\t\t",b2.lab,b2.doc,b2.roomc,b2.total);
		}
		getch();
	}
	
	fclose(fp);
	if(c==0)
	{
		printf("\n\t\t\t\tNo Such patient record found!\n\t\t\t\t");
		printf("Enter 1- Try Again\t2-Exit to main menu\n\t\t\t\t");
		scanf("%d",&cont);
		if(cont==1)
		{
			goto vip;
		}
		else
		{
			
		}
	}
	
}

void viewob()
{
	FILE *fp;
	int patid,c=0,cont;
	vop:
	c=0;
	fp=fopen("opbill.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** VIEW OP BILL ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter patient ID:\n\t\t\t\t");
	scanf("%d",&patid);
	while(1)
	{
		fread(&b1,ob_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(b1.patid==patid)
		{
			c=1;
			printf("\n\t\t\tBILL FOR PATIENT ID: %d\n\t\t\t",patid);
			printf("\n\n\t\tBill No: %d\n\t\tName:%s\n\t\tAge:%d\n\t\t\n\t\tGender: %s\n\t\tDate: %d/%d/%d\n\t\t",b1.billno,b1.patname,b1.age,b1.gender,b1.dd,b1.mm,b1.yy);	
			printf("Charges:\n\t\t");
			printf("Lab Charges: %0.2f\n\t\tDoctor Charges: %0.2f\n\t\tTotal Charge: %0.2f\n\t\t",b1.lab,b1.doc,b1.total);
		}
	}
	getch();
	fclose(fp);
	if(c==0)
	{
		printf("\n\t\t\t\tNo Such patient record found!\n\t\t\t\t");
		printf("Enter 1- Try Again\t2-Exit to main menu\n\t\t\t\t");
		scanf("%d",&cont);
		if(cont==1)
		{
			goto vop;
		}
		else
		{
			
		}
	}
}
void aplab()
{
	FILE *fp;
	fp=fopen("pentest.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** APPLY FOR TEST ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\tEnter name:\n\t\t\t");
	scanf("%s",t1.name);
	printf("\n\t\t\tEnter Address:\n\t\t\t");
	scanf("%s",t1.add);
	printf("\n\t\t\tEnter Test Type:\n\t\t\t");
	scanf("%s",t1.type);
	printf("\n\t\t\tEnter Date:\n\t\t\t");
	scanf("%d/%d/%d",&t1.dd,&t1.mm,&t1.yy);
	printf("\n\t\t\tEnter Prescribed Doctor:\n\t\t\t");
	scanf("%s",t1.doc);	
	fwrite(&t1,t_size,1,fp);
	fclose(fp);
	
}
void mglbs()
{
	FILE *fp,*fp2,*fp1;
	int c=0,choice,d=0,cont;
	char name[30];
	fp=fopen("pentest.txt","r");
	fp2=fopen("temp.txt","a");
	fp1=fopen("contest.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Lab Appointments ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t|\tName\t|\tAddress\t|\tType\t|\tDate\t|\tDoctor\t|\n\t ");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		fread(&t1,t_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		c++;
		printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\n\t  ",t1.name,t1.add,t1.type,t1.dd,t1.mm,t1.yy,t1.doc);
	}
	if(c==0)
	{
		printf("\n\n\t\tNo Pending Appointments!\n\t\t");
	}
	else
	{
		printf("\n\t\t\tChoose an option to continue:\n\t\t\t");
		printf("1. Approve Appointment.\n\t\t\t");
		printf("2. Goto Main Menu\n\t\t\t");
		scanf("%d",&choice);
		rewind(fp);
		if(choice==1)
		{
			pent:
			d=0;
			printf("\n\t\t\tEnter name to Approve:\n\t\t\t");
			scanf("%s",name);
			while(1)
			{
				fread(&t1,t_size,1,fp);
				if(feof(fp))
				{
					break;
				}
				if(strcmp(name,t1.name)==0)
				{
					fwrite(&t1,t_size,1,fp1);
					d=1;
				}
				else
				{
					fwrite(&t1,t_size,1,fp2);	
				}
			}
		
			if(d==0)
			{
				printf("\n\t\t\tNo such name\n\t\t\t1-Continue\n\t\t\t2-Exit\n\t\t\t");
				scanf("%d",&cont);
				if(cont==1)
				{
					goto pent;
				}
			}
		}
			fclose(fp);
			fclose(fp2);
			fclose(fp1);
			remove("pentest.txt");
			rename("temp.txt","pentest.txt");
		
	
	}
}

void vlabs()
{
	FILE *fp,*fp2;
	int c=0,ch,d=0;
	char pname[30];
	fp=fopen("contest.txt","r");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Lab Appointments ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t|\tName\t|\tAddress\t|\tType\t|\tDate\t|\tDoctor\t|\n\t ");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		fread(&t1,t_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		c++;
		printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\n\t  ",t1.name,t1.add,t1.type,t1.dd,t1.mm,t1.yy,t1.doc);
	}
	if(c==0)
	{
		printf("\n\t\t\t\tThere are no appointments.\n\t\t\t\t");
		getch();
		return;
	}
	fclose(fp);
	if(c!=0)
	{
		
		printf("\n\t\t\t\tEnter\n\t\t\t\t 1- Remove a schedule\n\t\t\t\t 2. Go Back to Main Menu.\n\t\t\t\t");
		scanf("%d",&ch);
		if(ch==1)
		{		
				fp=fopen("contest.txt","r");
				fp2=fopen("temp.txt","a");
					if(fp==NULL)
			{
				printf("\n\t\tCannot Open File!\n\t\t\t");
				getch();
				return;
			}
				system("cls");
				printf("------------------------------------------------------------------------------------------------------------------------\n");
				printf("\t\t\t\t  \t ****** REMOVE APPOINTMENTS ****** \t \n");
				printf("------------------------------------------------------------------------------------------------------------------------\n");	
				printf("\n\t\t\t\tEnter the name of the patient to remove:\n\t\t\t\t");
				scanf("%s",pname);
				while(1)
				{
					fread(&t1,t_size,1,fp);
					if(feof(fp))
					{
						break;
					}
					if(strcmp(t1.name,pname)==0)
					{
						d++;
					}
					else
					{
						fwrite(&t1,t_size,1,fp2);
					}
				}
			
				if(d==0)
				{
					printf("\n\t\t\t\tNo Such Name!\n\t\t\t\t");
				}
	
				fclose(fp);
				fclose(fp2);
				remove("contest.txt");
				rename("temp.txt","contest.txt");
				getch();
		
	}
	}
}

void slabs()
{
	FILE *fp;
	int c=0;
	fp=fopen("contest.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Lab Appointments ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t|\tName\t|\tAddress\t|\tType\t|\tDate\t|\tDoctor\t|\n\t ");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		fread(&t1,t_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		c++;
		printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\n\t  ",t1.name,t1.add,t1.type,t1.dd,t1.mm,t1.yy,t1.doc);
	}
	if(c==0)
	{
		printf("\n\t\t\t\tThere are no appointments.\n\t\t\t\t");
		getch();
		return;
	}
	getch();
	fclose(fp);
}

void uplabs()
{
	FILE *fp,*fp2;
	int c=0,cont;
	char name[30];
	rep:
	c=0;
	fp2=fopen("contest.txt","r");
	fp=fopen("labrep.txt","a");
	if(fp2==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t");
		return;
	}
	printf("\n\t\t\tEnter name of the patient:\n\t\t\t");
	scanf("%s",name);
	while(1)
	{
		fread(&t1,t_size,1,fp2);
		if(feof(fp2))
		{
			break;
		}
		if(strcmp(name,t1.name)==0)
		{
			c=1;
			strcpy(t2.name,t1.name);
			strcpy(t2.add,t1.add);
			strcpy(t2.type,t1.type);
			strcpy(t2.doc,t1.doc);
			t2.dd=t1.dd;
			t2.mm=t1.mm;
			t2.yy=t1.yy;
		}
	}
	if(c!=0)
	{
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t  \t ****** Upload Lab Report ****** \t \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\t\t\tEnter Status:\n\t\t\t");
		scanf("%s",t2.state);
		fwrite(&t2,t1_size,1,fp);
		fclose(fp);
	    fclose(fp2);
	}
	else
	{
		printf("\n\t\t\tNo such test found!\n\t\t\t");
		printf("\n\t\t\t1- Continue\t2-  Exit\n\t\t\t");
		scanf("%d",&cont);
		if(cont==1)
		{
			goto rep;
		}
		else
		{
			exit(0);
		}
	}

}

void vlabr()
{
	FILE *fp;
	int c=0;
	fp=fopen("labrep.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Lab Reports ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t|\tName\t|\tAddress\t|\tType\t|\tDate\t|\tDoctor\t|\tStatus\t|\n\t ");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		fread(&t2,t1_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		c++;
		printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s\n\t  ",t2.name,t2.add,t2.type,t2.dd,t2.mm,t2.yy,t2.doc,t2.state);
	}
	if(c==0)
	{
		printf("\n\t\t\t\tThere are no reports.\n\t\t\t\t");
		getch();
		return;
	}
	getch();
	fclose(fp);
}
void uppres()
{
	FILE *fp;
	fp=fopen("pres.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Upload Prescription ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\tEnter Doctor Name:\n\t\t\t");
	scanf("%s",p.doc);
	printf("\n\t\t\tEnter Date:\n\t\t\t");
	fflush(stdin);
	scanf("%s",p.date);
	printf("\n\t\t\tEnter Patient Name:\n\t\t\t");
	scanf("%s",p.patname);
	printf("\n\t\t\tEnter DOB:\n\t\t\t");
	scanf("%s",p.dob);
	printf("\n\t\t\tEnter Gender:\n\t\t\t");
	scanf("%s",p.gender);
	printf("\n\t\t\tEnter Age:\n\t\t\t");
	scanf("%d",&p.age);	
	printf("\n\t\t\tEnter Prescription:\n\t\t\t");
	fflush(stdin);
	scanf("%[^\n]s",p.pres);
	fwrite(&p,p1_size,1,fp);
	fclose(fp);
}
void vpres()
{
	FILE *fp;
	fp=fopen("pres.txt","r");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** View Prescription ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");

	while(1)
	{
		fread(&p,p1_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		printf("\n\n\t\t\tDoctor: %s\n\t\t\tDate: %s\n\n\t\t",p.doc,p.date);
		printf("Patient Name: %s\t\tDOB: %s\n\t\tGender: %s\t\tAge: %d\n\t\tPrescriptions: \n\t\t%s\n\t\t",p.patname,p.dob,p.gender,p.age,p.pres);
	}
	getch();
}

void modip()
{
	int choice;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** MODIFY IP RECORDS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tChoose an action to continue:\n\t\t1- Update\t2- Delete\t3- Go to main menu.\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			updip();
			break;
		case 2:
			delip();
			break;
		case 3:
			return;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
	
	
}

void modop()
{
	
	int choice;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** MODIFY OP RECORDS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tChoose an action to continue:\n\t\t1- Update\t2- Delete\t3- Go to main menu.\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			updop();
			break;
		case 2:
			delop();
			break;
		case 3:
			return;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
	
}

void  moddoc()
{
	
	int choice;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** MODIFY DOCTOR RECORDS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tChoose an action to continue:\n\t\t1- Update\t2- Delete\t3- Go to main menu.\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			upddoc();
			break;
		case 2:
			deldoc();
			break;
		case 3:
			return;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
	
}

void modroom()
{
	
	int choice;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** MODIFY ROOM RECORDS ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tChoose an action to continue:\n\t\t1- Update\t2- Delete\t3- Display\t4- Goto Main Menu\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			updroom();
			break;
		case 2:
			delroom();
			break;
		case 3:
			disroom();
		case 4:
			return;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
		
}

void updip()
{
	FILE *fp,*fp2;
	int c=0,pid;
	fp=fopen("ipd.txt","r");
	fp2=fopen("temp.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter patient ID to Update:\n\t\t\t\t");
	scanf("%d",&pid);
	while(1)
	{
		fread(&s,p_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(pid==s.pid)
		{
		 	c=1;
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t| \t\t *** UPDATED RECORDS ***\t\t  |\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
        	printf("\n\t\t\t\t <> Enter Name = ");
        	fflush(stdin);
        	scanf("%[^\n]s",s.name);
        	printf("\n\t\t\t\t <> Enter Age = ");
        	scanf("%d",&s.age);
        	printf("\n\t\t\t\t <> Enter Gender = ");
        	fflush(stdin);
        	scanf("%s",s.gen);
        	printf("\n\t\t\t\t <> Enter contact = ");
        	scanf("%f",&s.con);
        	printf("\n\t\t\t\t <> Enter Doctor = ");
        	scanf("%s",s.doc); 
			printf("\n\t\t\t\t <> Enter Address = ");
        	fflush(stdin);
        	scanf("%[^\ns]",s.add);
        	printf("\n\t\t\t\t <> Enter Room No = ");
        	scanf("%d",&s.room);
			printf("\n\t\t\t\t <> Enter Date of Admission = ");
        	scanf("%d/%d/%d",&s.dd,&s.mm,&s.yy);
        	printf("\n\t\t\t\t <> Enter Date of Discharge = ");
      		scanf("%d/%d/%d",&s.dd1,&s.mm1,&s.yy1);
      		fwrite(&s,p_size,1,fp2);
		}
		else
		{
			fwrite(&s,p_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	fclose(fp);
	fclose(fp2);
	remove("ipd.txt");
	rename("temp.txt","ipd.txt");
}
void delip()
{
	FILE *fp,*fp2;
	int c=0,pid;
	fp=fopen("ipd.txt","r");
	fp2=fopen("temp.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter patient ID to Delete:\n\t\t\t\t");
	scanf("%d",&pid);
	while(1)
	{
		fread(&s,p_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(pid==s.pid)
		{
		 	c=1;
		}
		else
		{
			fwrite(&s,p_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	fclose(fp);
	fclose(fp2);
	remove("ipd.txt");
	rename("temp.txt","ipd.txt");
}
void updop()
{
	FILE *fp,*fp2;
	int c=0,pid;
	fp=fopen("opd.txt","r");
	fp2=fopen("temp.txt","a");
	printf("\n\t\t\t\tEnter patient ID to Update:\n\t\t\t\t");
	scanf("%d",&pid);
	while(1)
	{
		fread(&op,op_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(pid==op.pid)
		{
		 	c=1;
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t| \t\t *** UPDATED RECORDS ***\t\t  |\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
        	printf("\n\t\t\t\t <> Enter Name = ");
        	fflush(stdin);
        	scanf("%[^\n]s",op.name);
        	printf("\n\t\t\t\t <> Enter Age = ");
        	scanf("%d",&op.age);
        	printf("\n\t\t\t\t <> Enter Gender = ");
        	fflush(stdin);
        	scanf("%s",op.gen);
        	printf("\n\t\t\t\t <> Enter contact = ");
        	scanf("%f",&op.con);
        	printf("\n\t\t\t\t <> Enter Doctor = ");
        	scanf("%s",op.doc); 
			printf("\n\t\t\t\t <> Enter Address = ");
        	fflush(stdin);
        	scanf("%[^\ns]",op.add);
			printf("\n\t\t\t\t <> Enter Date = ");
        	scanf("%d/%d/%d",&s.dd,&s.mm,&s.yy);
      		fwrite(&op,op_size,1,fp2);
		}
		else
		{
			fwrite(&op,op_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	fclose(fp);
	fclose(fp2);
	remove("opd.txt");
	rename("temp.txt","opd.txt");
}
void delop()
{
	FILE *fp,*fp2;
	int c=0,pid;
	fp=fopen("opd.txt","r");
	fp2=fopen("temp.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter patient ID to Delete:\n\t\t\t\t");
	scanf("%d",&pid);
	while(1)
	{
		fread(&op,op_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(pid==op.pid)
		{
		 	c=1;
		}
		else
		{
			fwrite(&op,op_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	fclose(fp);
	fclose(fp2);
	remove("opd.txt");
	rename("temp.txt","opd.txt");
}
void deldoc()
{
	FILE *fp,*fp2;
	int c=0,id;
	fp=fopen("doc.txt","r");
	fp2=fopen("temp.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter Doctor ID to Delete:\n\t\t\t\t");
	scanf("%d",&id);
	while(1)
	{
		fread(&doc,doc_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(id==doc.docid)
		{
		 	c=1;
		
			}
			else
			{
				fwrite(&doc,doc_size,1,fp2);
			}
		}	
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	fclose(fp);
	fclose(fp2);
	remove("doc.txt");
	rename("temp.txt","doc.txt");
}
void upddoc()
{
	FILE *fp,*fp2;
	int c=0,id;
	fp=fopen("doc.txt","r");
	fp2=fopen("temp.txt","a");	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter Doctor ID to Update:\n\t\t\t\t");
	scanf("%d",&id);
	while(1)
	{
		fread(&doc,doc_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(id==doc.docid)
		{
		 	c=1;
		 	printf("\n\t\t\t\tEnter Doctor ID:\n\t\t\t\t");
			scanf("%d",&doc.docid);
			printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
			fflush(stdin);
			scanf("%[^\n]s",doc.name);
			printf("\n\t\t\t\tEnter Gender:\n\t\t\t\t");
			fflush(stdin);
			scanf("%s",doc.gender);
			fflush(stdin);
			printf("\n\t\t\t\tEnter Address:\n\t\t\t\t");
			fflush(stdin);
			scanf("%[^\n]s",doc.add);
			printf("\n\t\t\t\tEnter Speciality:\n\t\t\t\t");
			fflush(stdin);
			scanf("%[^\n]s",doc.spec);
			fflush(stdin);	
			printf("\n\t\t\t\tEnter Phone:\n\t\t\t\t");
			scanf("%s",doc.phone);
			fflush(stdin);	
			printf("\n\t\t\t\tEnter Username:\n\t\t\t\t");
			scanf("%s",doc.username);
			fflush(stdin);	
			printf("\n\t\t\t\tEnter Password:\n\t\t\t\t");
			scanf("%s",doc.password);
			fwrite(&doc,doc_size,1,fp2);
		}
		else
		{
			fwrite(&doc,doc_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	fclose(fp);
	fclose(fp2);
	remove("doc.txt");
	rename("temp.txt","doc.txt");
}
void updroom()
{
	FILE *fp,*fp2;
	int c=0,rid;
	fp=fopen("room.txt","r");
	fp2=fopen("temp.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter Room ID to Update:\n\t\t\t\t");
	scanf("%d",&rid);
	while(1)
	{
		fread(&room,r_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(rid==room.id)
		{
		 	c=1;
		 	printf("\n\t\t\t\tEnter Type:\n\t\t\t\t");
		 	scanf("%s",room.type);
		 	printf("\n\t\t\t\tEnter Availability:\n\t\t\t\t");
		 	scanf("%s",room.avail);
		 	fwrite(&room,r_size,1,fp2);
		}
		else
		{
			fwrite(&room,r_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	getch();
	fclose(fp);
	fclose(fp2);
	remove("room.txt");
	rename("temp.txt","room.txt");
}
void delroom()
{
	FILE *fp,*fp2;
	int c=0,rid;
	fp=fopen("room.txt","r");
	fp2=fopen("temp.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter Room ID to Delete:\n\t\t\t\t");
	scanf("%d",&rid);
	while(1)
	{
		fread(&room,r_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(rid==room.id)
		{
		 	c=1;
		}
		else
		{
			fwrite(&room,r_size,1,fp2);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	getch();
	fclose(fp);
	fclose(fp2);
	remove("room.txt");
	rename("temp.txt","room.txt");
}
void disroom()
{
	FILE *fp;
	int c=0;
	fp=fopen("room.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t|\tRoom ID\t|\tType\t|\tAvailability\t|\n\t\t");
	while(1)
	{
		fread(&room,r_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		c=1;
		printf("\t%d\t\t%s\t\t%s\n\t\t",room.id,room.type,room.avail);
	}
	if(c==0)
	{
		printf("\n\t\t\t\tRecord Not Found!\n\t\t\t\t");
	}
	getch();
	fclose(fp);
}
void mgdbr()
{
	int choice,ch;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t *** MANAGE DEATH AND BIRTH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
 	printf("\n\t\t\t\tChoose an action to continue:\n\t\t\t\t");
 	printf("\n\t\t\t\t1.Birth Records\n\t\t\t\t2. Death Records\n\t\t\t\t3.Exit\n\t\t\t\t");
 	scanf("%d",&choice);
 	switch(choice)
 	{
 		case 1:
			system("cls");	
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t| \t\t *** MANAGE BIRTH RECORDS ***\t\t  |\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
 			printf("\n\t\t\t\tChoose an action to continue:\n\t\t\t\t");
 			printf("\n\t\t\t\t1.Add Record\n\t\t\t\t2.View Records\n\t\t\t\t3.Delete Record\n\t\t\t\t4.Exit.\n\t\t\t\t");
 			scanf("%d",&ch);
 			if(ch==1)
 			{
 				addb();	
			}
			else if(ch==2)
			{
				disb();
			}
			else if(ch==3)
			{
				delb();
			}
			else
			{
				return;
			}
			break;
		case 2:
			system("cls");	
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t| \t\t *** MANAGE DEATH RECORDS ***\t\t  |\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
 			printf("\n\t\t\t\tChoose an action to continue:\n\t\t\t\t");
 			printf("\n\t\t\t\t1.Add Record\n\t\t\t\t2.View Records\n\t\t\t\t3.Delete Record\n\t\t\t\t4.Exit.\n\t\t\t\t");
 			scanf("%d",&ch);
 			if(ch==1)
 			{
 				addd();	
			}
			else if(ch==2)
			{
				disd();
			}
			else if(ch==3)
			{
				deld();
			}
			else
			{
				return;
			}
			break;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
}

void addb()
{
	FILE *fp;
	char cont='Y';
	fp=fopen("birth.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t *** ADD BIRTH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
 	while(cont=='Y')
 	{
		printf("\n\t\t\t\tEnter S.No:\n\t\t\t\t");
 		scanf("%d",&b.sno);
 		printf("\n\t\t\t\tEnter Date:\n\t\t\t\t");
 		scanf("%d/%d/%d",&b.dd,&b.mm,&b.yy);
 		printf("\n\t\t\t\tEnter Time:\n\t\t\t\t");
 		scanf("%s",b.time);
 		printf("\n\t\t\t\tEnter Place:\n\t\t\t\t");
 		scanf("%s",b.place);
 		printf("\n\t\t\t\tEnter Mother's Name:\n\t\t\t\t");
 		scanf("%s",b.mother);
 		printf("\n\t\t\t\tEnter Father's Name:\n\t\t\t\t");
 		scanf("%s",b.father);
		printf("\n\t\t\t\tEnter Parents's Contact:\n\t\t\t\t");
 		scanf("%s",b.pcontact);
 		printf("\n\t\t\t\tEnter Sex:\n\t\t\t\t");
 		scanf("%s",b.sex);
		fwrite(&b,b_size,1,fp);
		printf("\n\t\t\t\tContinue?(Y/N)\n\t\t\t\t");
		scanf("%c",&cont);
	}
	fclose(fp);
}

void disb()
{
	FILE *fp;
	int c=0;
	fp=fopen("birth.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  BIRTH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("=======================================================================================================");
    printf("\n| S.No\t| Date\t|  Time   |\t  Place    | \t Mother's Name\t| Father's Name | Parents' Contact | Sex\t|\n");
    printf("=======================================================================================================\n");
    while(1)
    {
    	fread(&b,b_size,1,fp);
    	if(feof(fp))
    	{	
    		break;
		}
		printf("   %d\t%d/%d/%d\t%s\t%s\t\t%s\t%s   %s   %s\n",b.sno,b.dd,b.mm,b.yy,b.time,b.place,b.mother,b.father,b.pcontact,b.sex);	
	}
	
	getch();	
}

void delb()
{
	FILE *fp,*fp2;
	int c=0,sno,ch;
	bir:
	c=0;
	fp=fopen("birth.txt","r");
	fp2=fopen("temp.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  DELETE BIRTH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter S.No:\n\t\t\t\t");
	scanf("%d",&sno);
	while(1)
	{
		fread(&b,b_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(b.sno==sno)
		{
			c=1;
		}
		else
		{
			fwrite(&b,b_size,1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	remove("birth.txt");
	rename("temp.txt","birth.txt");
	if(c==0)
	{
		printf("\n\t\t\t\tNo such record!\n\t\t\t\t");
		printf("\n\t\t\t\tContinue\n\t\t\t1. Yes\n\t\t\t2.No\n\t\t\t\t");
		scanf("%d",&ch);
		if(ch==1)
		{
			goto bir;
		}
		else
		{
			return;
		}
	}
	
}

void addd()
{
	FILE *fp;
	char cont='Y';
	fp=fopen("death.txt","a");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t *** ADD DEATH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
 	while(cont=='Y')
 	{
		printf("\n\t\t\t\tEnter S.No:\n\t\t\t\t");
 		scanf("%d",&b.sno);
 		printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
 		scanf("%s",d.name);
 		printf("\n\t\t\t\tEnter DOB:\n\t\t\t\t");
 		scanf("%d/%d/%d",&d.dd,&d.mm,&d.yy);
 		printf("\n\t\t\t\tEnter DOD:\n\t\t\t\t");
 		scanf("%d/%d/%d",&d.dd1,&d.mm1,&d.yy1);
 		printf("\n\t\t\t\tEnter Time:\n\t\t\t\t");
 		scanf("%s",d.time);
		printf("\n\t\t\t\tEnter Relatives' Contact:\n\t\t\t\t");
 		scanf("%s",d.rcontact);
 		printf("\n\t\t\t\tEnter Sex:\n\t\t\t\t");
 		scanf("%s",d.sex);
		fwrite(&b,b_size,1,fp);
		printf("\n\t\t\t\tContinue?(Y/N)\n\t\t\t\t");
		scanf("%c",&cont);
	}
	fclose(fp);
}

void disd()
{
	FILE *fp;
	int c=0;
	fp=fopen("death.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  DEATH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("=======================================================================================================");
    printf("\n| S.No\t| Name\t|  DOB\t   |  DOD\t   |  Time  \t|Relatives' Contact | Sex\t|\n");
    printf("=======================================================================================================\n");
    while(1)
    {
    	fread(&d,d_size,1,fp);
    	if(feof(fp))
    	{	
    		break;
		}
		printf("   %d\t%s\t%d/%d/%d\t%d/%d/%d\t%s\t%s\t%s\n",d.sno,d.name,d.dd,d.mm,d.yy,d.dd1,d.mm1,d.yy1,d.time,d.rcontact,d.sex);	
	}
	
	getch();	
}

void deld()
{
	FILE *fp,*fp2;
	int c=0,sno,ch;
	dea:
	c=0;
	fp=fopen("death.txt","r");
	fp2=fopen("temp.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  DELETE DEATH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter S.No:\n\t\t\t\t");
	scanf("%d",&sno);
	while(1)
	{
		fread(&d,d_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(d.sno==sno)
		{
			c=1;
		}
		else
		{
			fwrite(&d,d_size,1,fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	remove("death.txt");
	rename("temp.txt","death.txt");
	if(c==0)
	{
		printf("\n\t\t\t\tNo such record!\n\t\t\t\t");
		printf("\n\t\t\t\tContinue\n\t\t\t1. Yes\n\t\t\t2.No\n\t\t\t\t");
		scanf("%d",&ch);
		if(ch==1)
		{
			goto dea;
		}
		else
		{
			return;
		}
	}
}

void bdrep()
{
	int choice;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  BIRTH & DEATH REPORT ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\t1. Birth Report\n\t\t\t\t2.Death Report\n\t\t\t\t3.Exit\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			birthrep();
			break;
		case 2:
			deathrep();
			break;
		case 3:
			return;
		default:
			printf("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
}

void birthrep()
{
	FILE  *fp;
	int c=0,dd,mm,yy,dd1,mm1,yy1;
	fp=fopen("birth.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
	scanf("%d/%d/%d",&dd,&mm,&yy);
	printf("\t\t\t\tTo:\n\t\t\t\t");
	fflush(stdin);
	scanf("%d/%d/%d",&dd1,&mm1,&yy1);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  BIRTH REPORT ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("=======================================================================================================");
    printf("\n| S.No\t| Date\t|  Time   |\t  Place    | \t Mother's Name\t| Father's Name | Parents' Contact | Sex\t|\n");
    printf("=======================================================================================================\n");
	while(1)
	{
		fread(&b,b_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(b.yy>yy&&b.yy<yy1)
		{
			c++;
			printf("   %d\t%d/%d/%d\t%s\t%s\t\t%s\t%s   %s   %s\n",b.sno,b.dd,b.mm,b.yy,b.time,b.place,b.mother,b.father,b.pcontact,b.sex);	
		}
		if(b.yy==yy||b.yy==yy1)
		{
			if(b.mm>=mm&&b.mm<=mm1)
			{
				if(b.dd>=dd&&b.dd<=dd1)
				{
					c++;
					printf("   %d\t%d/%d/%d\t%s\t%s\t\t%s\t%s   %s   %s\n",b.sno,b.dd,b.mm,b.yy,b.time,b.place,b.mother,b.father,b.pcontact,b.sex);	
				}
			}
		}
	}
	fclose(fp);
	if(c==0)
	{
		printf("\n\t\t\t\tNo Record Found!\n\t\t\t\t");
	}
	else
	{
		printf("\n\n\t\t\t%d Records were Found!\n\t\t\t",c);
	}
	getch();
	
}

void deathrep()
{
	FILE  *fp;
	int c=0,dd,mm,yy,dd1,mm1,yy1;
	fp=fopen("death.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
	scanf("%d/%d/%d",&dd,&mm,&yy);
	printf("\t\t\t\tTo:\n\t\t\t\t");
	fflush(stdin);
	scanf("%d/%d/%d",&dd1,&mm1,&yy1);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t| \t\t ***  DEATH RECORDS ***\t\t  |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("=======================================================================================================");
    printf("\n| S.No\t| Name\t|  DOB\t   |  DOD\t   |  Time  \t|Relatives' Contact | Sex\t|\n");
    printf("=======================================================================================================\n");
	while(1)
	{
		fread(&d,d_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(d.yy1>yy&&d.yy1<yy1)
		{
			c++;
			printf("   %d\t%s\t%d/%d/%d\t%d/%d/%d\t%s\t%s\t%s\n",d.sno,d.name,dd,d.mm,d.yy,d.dd1,d.mm1,d.yy1,d.time,d.rcontact,d.sex);	
		}
		if(d.yy1==yy||d.yy1==yy1)
		{
			if(d.mm1>=mm&&d.mm1<=mm1)
			{
				if(d.dd1>=dd&&d.dd1<=dd1)
				{
					c++;
					printf("   %d\t%s\t%d/%d/%d\t%d/%d/%d\t%s\t%s\t%s\n",d.sno,d.name,dd,d.mm,d.yy,d.dd1,d.mm1,d.yy1,d.time,d.rcontact,d.sex);	
				}
			}
		}
	}
	fclose(fp);
	if(c==0)
	{
		printf("\n\t\t\t\tNo Record Found!\n\t\t\t\t");
	}
	else
	{
		printf("\n\n\t\t\t%d Records were Found!\n\t\t\t",c);
	}
	getch();
}

void ulabr()
{
	FILE *fp;
	int c=0;
	char name[30];
	fp=fopen("labrep.txt","r");
		if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
	scanf("%s",name);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Lab Reports ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t|\tName\t|\tAddress\t|\tType\t|\tDate\t|\tDoctor\t|\tStatus\t|\n\t ");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		fread(&t2,t1_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(strcmp(t2.name,name)==0)
		{
		c++;
		printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s\n\t  ",t2.name,t2.add,t2.type,t2.dd,t2.mm,t2.yy,t2.doc,t2.state);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tThere are no reports.\n\t\t\t\t");
		getch();
		return;
	}
	getch();
	fclose(fp);
}

void ubill()
{
	int choice;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** VIEW BILL ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n\t\t\t\t1.OP BILL\n\t\t\t\t2.IP BILL\n\t\t\t\t3.Exit\n\t\t\t\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			viewob();
			break;
		case 2:
			viewib();
			break;
		case 3:
			return;
		default:
			("\n\t\t\t\tWrong Choice!\n\t\t\t\t");
	}
}

void uvpres()
{
	FILE *fp;
	char name[30],c=0;
	fp=fopen("pres.txt","r");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** View Prescription ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\tEnter Name:\n\t\t\t\t");
	scanf("%s",name);
	while(1)
	{
		fread(&p,p1_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		if(strcmp(p.patname,name)==0)
		{
		c=1;
		printf("\n\n\t\t\tDoctor: %s\n\t\t\tDate: %s\n\n\t\t",p.doc,p.date);
		printf("Patient Name: %s\t\tDOB: %s\n\t\tGender: %s\t\tAge: %d\n\t\tPrescriptions: \n\t\t%s\n\t\t",p.patname,p.dob,p.gender,p.age,p.pres);
		}
	}
	if(c==0)
	{
		printf("\n\t\t\t\tNot Found!\n\t\t\t\t");
	}
	getch();
}

void roomrep()
{
	FILE *fp;
	int c=0,id,dd,mm,yy,dd1,mm1,yy1;
	fp=fopen("ipd.txt","r");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	printf("\n\t\t\t\tEnter Room ID:\n\t\t\t\t");
	scanf("%d",&id);
	printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
	scanf("%d/%d/%d",&dd,&mm,&yy);
	printf("\t\t\t\tTo:\n\t\t\t\t");
	fflush(stdin);
	scanf("%d/%d/%d",&dd1,&mm1,&yy1);
	system("cls");
	printf("\n\t       *********************************** DETAILS ***************************************\n");
   	printf("\n");
   	printf("=======================================================================================================");
   	printf("\n| PID\t|  Name\t|  Gender   |  Contact    |  Address\t|  Room  No |  Age \t|   Doctor    |   DOA   |   DOD   |\n");
   	printf("=======================================================================================================");
   	printf("\n");
   	while(1)
   	{
   		fread(&s,p_size,1,fp);
   		if(feof(fp))
    	{
   			break;
		}
		if(id==s.room)
		{
			c++;
			if(s.yy>yy&&s.yy1<yy1)
			{
				printf("|%d\t",s.pid);
      			printf(" %s     ",s.name);
        			printf("%s\t    ",s.gen);
        			printf("%0.0f\t  ",s.con);
        			printf(" %s\t ",s.add);
					printf("  %d\t",s.room);
					printf("       %d\t",s.age);
					printf("   %s   ",s.doc);
        			printf("%d/%d/%d\t ",s.dd,s.mm,s.yy);
        			printf("%d/%d/%d\t ",s.dd1,s.mm1,s.yy1);
        			printf("\n");
				}
				else if(s.yy==yy||s.yy1==yy1)
				{
					if(s.mm>=mm&&s.mm1<=mm1)
					{
						if(s.dd>=dd&&s.dd1<=dd1)
						{
							printf("|%d\t",s.pid);
        					printf(" %s     ",s.name);
        					printf("%s\t    ",s.gen);
        					printf("%0.0f\t  ",s.con);
        					printf(" %s\t ",s.add);
							printf("  %d\t",s.room);
							printf("       %d\t",s.age);
							printf("   %s   ",s.doc);
        					printf("%d/%d/%d\t ",s.dd,s.mm,s.yy);
        					printf("%d/%d/%d\t ",s.dd1,s.mm1,s.yy1);
        					printf("\n");	
						}
					}
				}
		}
	}
			fclose(fp);
			if(c==0)
			{
				printf("\n\t\t\t\tNo Record Found!\n\t\t\t\t");
			}
			else
			{
				printf("\n\n\t\t\t%d Records were Found!\n\t\t\t",c);
			}
		
}

void labrep()
{
	FILE *fp;
	int c=0,dd,mm,yy,dd1,mm1,yy1;
	fp=fopen("labrep.txt","r");
	printf("\n\t\t\t\tEnter the date range:\n\t\t\t\tFrom:\n\t\t\t\t");
	scanf("%d/%d/%d",&dd,&mm,&yy);
	printf("\t\t\t\tTo:\n\t\t\t\t");
	fflush(stdin);
	scanf("%d/%d/%d",&dd1,&mm1,&yy1);
	system("cls");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t  \t ****** Lab Reports ****** \t \n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t|\tName\t|\tAddress\t|\tType\t|\tDate\t|\tDoctor\t|\tStatus\t|\n\t ");
	if(fp==NULL)
	{
		printf("\n\t\tCannot Open File!\n\t\t\t");
		getch();
		return;
	}
	while(1)
	{
		fread(&t2,t1_size,1,fp);
		if(feof(fp))
		{
			break;
		}
		
			
			if(t2.yy>yy&&t2.yy<yy1)
			{
				c++;
				printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s\n\t  ",t2.name,t2.add,t2.type,t2.dd,t2.mm,t2.yy,t2.doc,t2.state);
			}
			else if(t2.yy==yy||t2.yy==yy1)
			{
				if(t2.mm>=mm&&t2.mm<=mm1)
				{
					if(t2.dd>=dd&&t2.dd<=dd1)
					{
						printf("\t%s\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s\n\t  ",t2.name,t2.add,t2.type,t2.dd,t2.mm,t2.yy,t2.doc,t2.state);
					}
				}
			}
	
	}
	if(c==0)
	{
		printf("\n\t\t\t\tNo Record Found!\n\t\t\t\t");
	}
	else
	{
		printf("\n\n\t\t\t%d Records were Found!\n\t\t\t",c);
	}
	getch();
	fclose(fp);
}
