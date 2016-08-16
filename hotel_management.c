#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>

//Global variables............
int i;
struct Cust
{
int room_no;
char r_type[15];
char name[30];
char c_address[30];
char c_nat[20];
int r_per;//number of persons in one room
int year;
int month;
int day;
int num_d;
int advance;    //to be subtracted from final bill
int r_charge;
int res_charge;
long int tot;
float tax;
double g_tot;
}ob;

//Function prototypes.........
char getavail(int);
void features();
void allocate();
void display();
void restaurant();
void deallocate();
void intro();
void screenheader();

//Function definitions..........
void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}
void screenheader()
 {
   printf("\n                      :::::::::::::::::::::::::::::::::::::");
   printf("\n                      ::                                 ::");
   printf("\n                      ::     $$$$$$$$$$$$$$$$$$$$$$$     ::");
   printf("\n                      ::     $                     $     ::");
   printf("\n                      ::     $      WELCOME TO     $     ::");
   printf("\n                      ::     $        HOTEL        $     ::");
   printf("\n                      ::     $    SUN MAGNETICA    $     ::");
   printf("\n                      ::     $                     $     ::");
   printf("\n                      ::     $$$$$$$$$$$$$$$$$$$$$$$     ::");
   printf("\n                      ::                                 ::");
   printf("\n                      :::::::::::::::::::::::::::::::::::::\n\n");

   }
void intro()
 {
   printf("\n\t            Side Marg, Sector-13, Chandigarh,\n\t\t\t\t 160013, INDIA");
   printf("\n\n                              Ph. No.:011-27223959");
   printf("\n\n\n                            WELCOMES YOU...........");
   printf("\n\n\n\tHotel Sun Magnetica is one of the newest Hotels in Chandigarh.\n\tThe Hotel is equipped with all the general amenities and facilities \n\tthat go along with a memorable stay.\n\tSet amidst beautifully landscaped gardens, it proves to be an ideal \n\tdream destination for a prospective tourist.");
   printf("\n\n\tThe Hotel has well furnished rooms along with rooms providing pleasant \n\tviews of the city. The hotel satisfies the needs of business as well \n\tas the leisure traveler. All the rooms at the hotel are furnished beautifully.");
   printf("\n\n                     AMENITIES .......\n");
   printf("\n\t\t\t1. 24*7 Power backup.\n");
   printf("\t\t\t2. Automatic System.\n");
   printf("\t\t\t3. Ample parking space.\n");
   printf("\t\t\t4. Round the clock security.\n");
   printf("\t\t\t5. Running hot and cold water.\n");
   printf("\t\t\t6. Free Internet service.\n");
   printf("\t\t\t7. 24 hours room service.\n");
   printf("\t\t\t8. Free laundry service.\n");
   printf("\nPress any character to continue:");
   getch();
 }
char getavail(int room)
 {
  FILE *fp;
  fp=fopen("HOTEL_RECORDS.dat","rb");
  if(fp==NULL)
  {
  printf("\nTHE SYSTEM IS FACING A PROBLEM LOADING THE FILE...\nPLEASE TRY LATER..\n");
  getch();
  exit(0);
  }

  fread(&ob,sizeof(ob),1,fp);
  while(!feof(fp))
  {
   if(ob.room_no==room)
       return 'n';
  }
fclose(fp);
return 'y';
 }


void features()
 {
   int typ;
   system("cls");
   screenheader();
   printf("\nChoose the room type:\n1. Sp. Deluxe\n2. Deluxe");
   printf("\n3. General\n4. Couple\n5. Couple Deluxe\n");
   scanf("%d",&typ);
   if(typ>5)
     {
       printf("\nWrong choice!! Choose a number between 1-5:");
       features();
     }
   switch(typ)
     {
       case 1:system("cls");
       screenheader();
       printf("\n      SPECIAL DELUXE\n");
       printf("\n Advance                >>>1500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Sp.deluxe");
       printf("\n\n Room charges         >>> Rs.3000 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n\n 3.Balcony available     ");
       printf("\n------------------------------------------------------------------");
       printf("\n                     ADDITIONAL FEATURES                        ");
       printf("\n------------------------------------------------------------------");
       printf("\n\n 1.A/C  available ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       printf("\n------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.150 per bed ");
       break;
       case 2:system("cls");
       screenheader();
       printf("\n     DELUXE  \n ");
       printf("\n Advance                >>>1000\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Deluxe                                      ");
       printf("\n\n Room charges         >>>Rs.2000 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.A/C available   ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.150 per bed ");
       break;
       case 3:system("cls");
       screenheader();
       printf("\n     GENERAL \n");
       printf("\n Advance                >>>750\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> General                                    ");
       printf("\n\n Room charges         >>>Rs.1500 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
       case 4:system("cls");
       screenheader();
       printf("\n     COUPLE \n");
       printf("\n Advance                >>>1000\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Couple");
       printf("\n\n Room charges         >>>Rs.2000 per day");
       printf("\n\n 1. Bed               >>>      1");
       printf("\n\n 2.Capacity           >>>      2");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.Geyser available");
       printf("\n\n 2.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
       case 5:system("cls");
       screenheader();
       printf("\n    COUPLE DELUXE\n");
       printf("\n Advance                >>>1500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Couple Deluxe ");
       printf("\n\n Room charges         >>>Rs.3000 per day");
       printf("\n\n 1. Bed               >>>      1");
       printf("\n\n 2.Capacity           >>>      2");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.A/C available   ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
     }
 }
void allocate()
 {
   char avail,ch;
   int type,room,m;
   FILE* fp;
   fp=fopen("HOTEL_RECORDS.dat","wb");
   if(fp==NULL)
     printf("PROBLEM LOADING FILE...TRY LATER...");
   else
   {

   system("cls");
   screenheader();
   printf("\nENTER THE ROOM TYPE YOU WANT\n1.Special Deluxe\n2.Deluxe\n3.General\n4.Couple\n5:Couple Deluxe\n");
   scanf("%d",&type);
   if(type==1)
   {
    strcpy(ob.r_type,"Spl. Deluxe");
    ob.advance=1500;
    m=3000;
    }
   else if(type==2)
    {
     strcpy(ob.r_type,"Deluxe");
     ob.advance=1000;
     m=2000;
    }
   else if(type==3)
     {
     strcpy(ob.r_type,"General");
     ob.advance=750;
     m=1500;
     }
   else if(type==4)
     {
     strcpy(ob.r_type,"Couple");
     ob.advance=1000;
     m=2000;
     }
   else if(type==5)
     {
     strcpy(ob.r_type,"Couple Deluxe");
     ob.advance=1500;
     m=3000;
     }
   else
    {
    printf("\nWRONG CHOICE...PRESS ENTER TO START AGAIN");
    getch();
    allocate();
    }

   printf("\n ENTER ROOM NUMBER:");
   printf("\nType 1:101-120\nType 2:201-220\nType 3:301-320\nType 4:401-420\nType 5:501-520\n");
   scanf("%d",&room);
   avail=getavail(room);

   if(avail=='y')
     {
       fflush(stdin);
       printf("\n NAME : ");
       gets(ob.name);
       printf("\n ADDRESS :");
       gets(ob.c_address);
       printf("\n NATIONALITY :");
       gets(ob.c_nat);
       printf("\n NUMBER OF DAYS OF STAY :");
       scanf("%d",ob.num_d);
       ob.r_charge=m*ob.num_d;
       printf("\n NUMBER OF PEOPLE :");
       scanf("%d",ob.r_per);
       if(type==4||type==5)
  if(ob.r_per>2)
    {
      printf("\n %d Members cannot be allocated this room.",ob.r_per);
      printf("\nDo You Still Want To Continue??(y/n)");
      ch=getch();
      if(ch=='y'||ch=='Y')
	;
      else
      allocate();
    }
       else if(room>=1&&room<=3)
	if(ob.r_per>5)
    {
      printf("\n %d Members cannot be allocated this room.",ob.r_per);
      printf("\nDo You Still Want To Continue??(y/n)");
      ch=getch();
      if(ch=='y'||ch=='Y')
      ;
      else
      allocate();
    }
       ob.res_charge=0;
       entry_date:
       printf("\n ENTER THE DATE OF ARRIVAL :");
       printf("\n------------------------------");
       printf("\n YEAR : ");
       scanf("%d",ob.year);
       printf("\n MONTH :");
       scanf("%d",ob.month);
       printf("\n DAY :");
       scanf("%d",ob.day);
       fwrite(&ob,sizeof(ob),1,fp);
       printf("\n... Room is allocated to ");
       puts(ob.name);
       printf(" for %d days.",ob.num_d);
       getch();

 }
   else
     {
       printf("\n ERROR : Room cannot be allocated ...");
       printf("\n Room is not available...");
       getch();
     }
fclose(fp);
}
}

void deallocate()
 {
   int room;
   char avail,nam[30],ch;
   FILE *fp,*fp1;
   fp=fopen("HOTEL_RECORDS.dat","rb");
   fp1=fopen("temp.dat","wb");

   system("cls");
   screenheader();

   printf("\nENTER ROOM NUMBER:");
   scanf("%d",&room);
    avail=getavail(room);
    if(avail=='y')
     {
       printf("\nTHE ROOM IS EMPTY........");
       getch();
     }
   else
     {
       while(!feof(fp))
       {
       fread(&ob,sizeof(ob),1,fp);
       if(ob.room_no==room)
	 {
	 printf("\nROOM NUMBER %d IS DEALLOCATED......",room);
	 printf("\nPRESS ANY KEY TO VIEW BILL\n");
	 getch();
	 printf("\n\n\n");
	 ob.tot=ob.res_charge+ob.r_charge-ob.advance;
	 ob.tax=0.2*ob.tot;
	 ob.g_tot=ob.tot+ob.tax;
printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
printf("\n::              HOTEL  SUN  MAGNETICA                   ::\n");
printf("\n::                  NET  BILL                           ::\n");
printf("\n:: ROOM CHARGES: RS. %d                             ::\n",ob.r_charge);
printf("\n:: RESTAURANT CHARGES: RS. %d                       ::\n",ob.res_charge);
printf("\n:: TOTAL: RS. %d                                    ::\n",ob.tot);
printf("\n:: ADVANCE PAID: RS %d                              ::\n",ob.advance);
printf("\n:: TOTAL TAX AMOUNT: RS %f                         ::\n",ob.tax);
printf("\n:: GRAND TOTAL AMOUNT: RS %lf                      ::\n",ob.g_tot);
printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

	 }
       fwrite(&ob,sizeof(ob),1,fp1);
       }
       remove("HOTEL_RECORDS.dat");
       rename("temp.dat","HOTEL_RECORDS.dat");
       printf("\n\nTHANK YOU FOR VISITING US...HOPE TO SEE YOU SOON AGAIN...\n");
       getch();
}


       printf("\nTHANKS FOR STAYING IN OUR HOTEL..");
       getch();


 _fcloseall();
}

void display()
 {
 int room,found=0;
 FILE *fp;
 fp=fopen("HOTEL_RECORDS.dat","rb");
 system("cls");
 screenheader();
 printf("\nENTER ROOM NUMBER :");
 scanf("%d",&room);
   while(!feof(fp))
       {
       fread(&ob,sizeof(ob),1,fp);
       if(ob.room_no==room)
       {
       found=1;
       printf("\n ROOM NUMBER :%d",ob.room_no);
       printf("\n NAME :");
       puts(ob.name);
       printf("\n NUMBER OF DAYS OF STAY :%d",ob.num_d);
       printf("\n ADDRESS :");
       puts(ob.c_address);
       printf("\n NATIONALITY :");
       puts(ob.c_nat);
       printf("\n NUMBER OF MEMBERS :%d",ob.r_per);
       printf("\n ARRIVAL DATE :%d/%d/%d",ob.day,ob.month,ob.year);
       break;
       }
   }
if(found==0)
       printf("\nDATA NOT AVAILABLE...");
       getch();
_fcloseall();
}
void restaurant()
 {
   int count=0,z=0,fc[113],answ,cost=0,room;
   char ans;
   int price[113]={245,245,245,245,240,240,240,240,235,235,250,235,235,220,
   215,230,215,240,250,250,250,250,250,250,250,255,245,245,245,245,250,240,
   240,360,290,360,290,370,295,360,290,360,290,250,360,290,360,290,250,370,
   290,360,290,250,250,280,245,290,235,265,240,290,300,256,240,265,270,255,
   255,240,240,235,220,25,30,25,30,35,35,25,30,35,25,35,25,25,30,100,105,105,
   100,105,100,105,125,105,105,100,105,110,115,100,100,100,105,105,105,105,
   125,105,120,120,100};
   char food[113][30]={"SHAHI PANEER","KADAI PANEER","CHEESE KORMA",
   "MALAI KOFTA","MATAR PANEER","PALAK PANEER","MIX VEG.","ALOO GOBI",
   "ALOO JEERA","CHANA MASALA","MATAR MUSHROOM","RAJMA MAKHANI","DAL MAKHANI",
   "MIXED RAITA","BUNDI RAITA","PINEAPPLE RAITA","SALAD(GREEN)","DUM ALOO",
   "MUSHROOM PANEER","MUTTON MASALA","MUTTON MUGHLAI","MUTTON KORMA",
   "MUTTON DO PYAZA","MUTTON SAGH","MUTTON DAHI","MUTTON ROGAN JOSH",
   "MUTTON CURRY","KADAI MUTTON","KEEMA LEVER","KEEMA MATAR","KEEMA EGG",
   "BRAIN CURRY","EGG CURRY","BUTTER CHICKEN","BUTTER CHICKEN(1/2)",
   "KADAI CHICKEN","KADAI CHICKEN(1/2)","BUTTER CHICKEN(BL)",
   "BUTTER CHICKEN(BL)(1/2)","CHICKEN MUGHLAI","CHICKEN MUGHLAI(1/2)",
   "CHICKEN MASALA","CHICKEN MASALA(1/2)","CHICKEN MASALA(1/4)",
   "CHICKEN SAGH","CHICKEN SAGH(1/2)","CHICKEN DAHI","CHICKEN DAHI(1/2)",
   "CHICKEN DAHI(1/4)","CHICKEN KORMA","CHICKEN KORMA(1/2)",
   "CHICKEN DO PYAZA","CHICKEN DO PYAZA(1/2)","FISH CURRY","CHICKEN CURRY",
   "CHICKEN CURRY(1/2)","CHICKEN CURRY(1/4)","CHILLI CHICKEN","TANDOORI ALOO",
   "CHICKEN TIKKA","SEEKH KABAB","FISH TIKKA","CHICKEN TANDOORI",
   "CHICKEN TANDOORI(1/2)","PANEER TIKKA","CHICKEN SEEKH KABAB",
   "CHICKEN HARA KABAB","CHICKEN BIRYANI","MUTTON BIRYANI","PANEER PULAO",
   "VEG.PULAO","JEERA RICE","STEAMED RICE","RUMALI ROTI","ROTI","NAN",
   "ALOO NAN","PANEER NAN","KEEMA NAN","PARANTHA","ALOO PARANTHA",
   "PANEER PARANTHA","PUDINA PARANTHA","BUTTER NAN","LACHCHA PARANTHA",
   "MISSI ROTI","KHASTA ROTI","VEG.BURGER","PANEER BURGER","CHEESE SANDWICH",
   "VEG.PATTI","CHICKEN PATTI","TEA","COFFEE","COLD COFFEE","PINEAPPLE",
   "STRAWBERRY","CHOCOLATE","BLACK FOREST","DOUBLE STORIED","TRIPLE STORIED",
   "SOFT CONE","VANILLA","STRAWBERRY","CHOCOLATE","CHOCO CHIPS","MANGO",
   "TUTTI FRUITY","LICHI","PISTA BADAM","CHOCOLATE PISTA BADAM","CHOCO DIP",
   "CHOCOLATE LICHI"};
       FILE* fp;
	fp=fopen("HOTEL_RECORDS.dat","wb");
   system("cls");
   printf("\n                        *********");
   printf("\n                        MENU CARD");
   printf("\n                        *********");
   printf("\n\n          VEGETARIAN");
   for(i=0;i<113;count++,i++)
     {
       gotoxy(17,count+7);
       printf("%d",i+1);
       gotoxy(30,count+20);
       puts(food[i]);
       gotoxy(55,count+7);
       printf("%d\n",price[i]);
       if(count==16)
	 {
	  count=0;
	  printf("\n    ********PRESS ANY KEY TO CONTINUE********");
	  getch();
	  system("cls");
	 }
       if(i==17)
	 {
	 printf("\n\n          MUTTON\n");
	 count +=3;
	 }
       if(i==32)
	 {
	 printf("\n\n       CHICKEN\n");
	 count +=3;
	 }
       if(i==57)
	 {
	 printf("\n\n       BAR-BE-QUE\n");
	 count +=3;
	 }
      if(i==72)
	 {
	 printf("\n\n       ROTI-NAN-PARANTHA\n");
	 count +=3;
	 }
      if(i==91)
	 {
	 printf("\n\n       BEVERAGES\n");
	 count +=3;
	 }
      if(i==100)
	 {
	 printf("\n\n       ICE-CREAMS\n");
	 count +=3;
	 }
     }
   getch();
   system("cls");
   screenheader();
   printf("\n\nPRESS 0 TO GO BACK TO MENU CARD\nPRESS 1 TO GIVE YOUR ORDER ");
   scanf("%d",&answ);
   switch(answ)
     {
       case 0:restaurant();
       break;

       case 1 :system("cls");
	do
	{
     printf("\n\nENTER THE FOOD CODE YOU WANT TO HAVE :: ");
     scanf("%d",&fc[z]);
     z++;
     puts("DO YOU WANT MORE(Y/N) ::");
     fflush(stdin);
     scanf("%c",&ans);
	}while ((ans=='y')||(ans=='Y'));
	room_entry:
	printf("\nENTER YOUR ROOM NUMBER:");
	scanf("%d",&room);


	getch();
	system("cls");
	screenheader();
	while(!feof(fp))
	{
	fread(&ob,sizeof(ob),1,fp);
	if(ob.room_no==room)
	   for(i=0;i<z;i++)
		  ob.res_charge+=price[fc[i]-1];
	else
	   printf("\nROOM NOT ALLOCATED...");

	for(i=0;i<z;i++)
	  {
	 puts(food[fc[i]-1]);
	 printf("\t\t\t%d\n",price[fc[i]-1]);
	 cost+=price[fc[i]-1];
	  }
	printf("TOTAL\t\t\t\t%d",cost);
	break;
       default:printf("\nWrong choice entered!!!");
	getch();

     }
 }
 }


void main()
 {
   char ans,avail;
   int ch,room;

   system("cls");
   screenheader();
   intro();
   do
     {
       system("cls");
       screenheader();
       printf("\n\n\n                CHOOSE YOUR REQUIREMENT:\n");
       printf("                      1. FEATURES OF ROOMS\n");
       printf("                      2. ROOM ALLOCATION\n");
       printf("                      3. DISPLAY DETAILS FOR A PARTICULAR ROOM\n");
       printf("                      4. ROOM DEALLOCATION\n");
       printf("                      5. RESTAURANT\n");
       printf("                      6. CHECK AVAILABILITY OF A ROOM\n");
       printf("                      7. EXIT\n");
       printf("\n YOUR CHOICE: ");
       scanf("%d",&ch);
       switch(ch)
	{
	 case 1:
	    features();
	    break;
	 case 2:
	    allocate();
	    break;
	 case 3:
	    display();
	    break;
	 case 4:
	    deallocate();
	    break;
	 case 5:
	    restaurant();
	    break;
	 case 6:
	    printf("\nENTER ROOM NUMBER:");
	    scanf("%d",&room);
	    avail=getavail(room);
	    if(avail=='y'||avail=='Y')
	    printf("\nDESIRED ROOM IS AVAILABLE...Continue to book...");
	    else
	    printf("\nDESIRED ROOM IS ALREADY BOOKED...");
	    break;
	 case 7:
	    exit(0);
	default:printf("\n\n\nWrong choice!!!!\n\nPlease choose 1-7");
	getch();
      }
 printf("\n\nDo you want to continue(y/n):");
 fflush(stdin);
 scanf("%c",&ans);
   }while(ans=='y'||ans=='Y');
 }
