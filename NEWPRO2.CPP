#include<iostream.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<time.h>
#include<fstream.h>
#include"projecthead.h"
int n=0;            //globally used for serial number in cart
int temp;	    //globally used for temporary storing indexes in shopping function
float total=0;      //globally used for total price in cart
ofstream fout;
ifstream fin;
fstream fio;
class shop
{
    int monitor[4],mthrbrd,pro,ram,gcard,hdd,dvdrw,
    rcpu,keymouse,speaker,printer;
    public:
	void monitorbrandmenu();
	void cpu();
	void keym();
	void Speaker();
	void Printer();
	void Cart();
	void bill();
	void shopmenu();
	void dell();
	void lg();
	void samsung();
	void viewsonic();
	void motherboard();
	void processor();
	void RAM();
	void grcard();
	void HDD();
	void DVDRW();
	void readycpu();
	void adcart();
	void vcart();
	void srcart();
	void reset()
	{
	       for(int i=0;i<4;i++)
		 monitor[i]=0;
	       mthrbrd=0;pro=0;
	       ram=0;gcard=0;hdd=0;dvdrw=0;
	       rcpu=0;keymouse=0;speaker=0;printer=0;
	}
}s;
class writing_cart
{
   public:
	  int s_no;
	  char cart[100];
	  float price;
	  void Show()
	  {
	     cout<<"\t\t"<<s_no<<") ";
	     puts(cart);
	  }
	  writing_cart()
	  {
	     s_no=0;
	  }
}c;
class billing
{
    private:
	   char name[30],phone[20],address[100],city[20],cart[100][150];
	   float total,od_id,discount;
	   int totalitems;
    public:
	   void SHOWDATA();
	   void GETDATA(float,float);
	   void SETTOTAL(float sum)
	   {
		total=sum;
	   }
	   float retid()
	   {
		return od_id;
	   }
	   char* retcity()
	   {
		return city;
	   }
	   void UPDATE();
}b;
void about();
void terms();
void manager();
void customer();
float getorderid();
void write_bill(billing);
void showall();
void updaterecord();
void deleterecord();
void showrecord();
void main()
{
    clrscr();
    int i;
    sh();
    welcome();
    sleep(5);
    clrscr();
    loading();
    clrscr();
    //Main Menu
    mainmenu:
    cout<<"\n\t\t\t\tComputer Shoppe";
    gotoxy(1,10);
    cout<<"\n\n\t\t1.Customer\n\n\t\t2.Manager\n\n\t\tSelect one option:";
    cin>>i;
    if(i==1)
       customer();
    else if(i==2)
    {
       security();
       manager();
    }
    else
    {
	   cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	   goto mainmenu;
    }
    getch();
}
void customer()
{
	clrscr();
	int j;
	cout<<"\n\t\t\t\tConsumer Portal\n";
	gotoxy(1,10);
	fout.open("cart.dat",ios::out|ios::binary);
	fout.close();
	total=0;n=0;
	cout<<"\n\n\t\t1.Let's Shop\n\n\t\t2.Search your order"
	<<"\n\n\t\t3.About Computer Shoppe"
	<<"\n\n\t\t4.Terms and Conditions\n\n\t\t5.Exit\n\n\t\tSelect one option:";
	cin>>j;
	if(j==1)
	   s.shopmenu();
	else if(j==2)
	{   showrecord();
	    getch();
	    customer();
	}
	else if(j==3)
	   about();
	else if(j==4)
	   terms();
	else if(j==5)
	   bye();
	else
	{
	   cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	   customer();
	}
}
void manager()
{
	clrscr();
	int j;
	cout<<"\n\t\t\t\tWELCOME MANAGER\n";
	gotoxy(1,10);
	cout<<"\n\n\t\t1.See all records\n\n\t\t2.Search a record"
	<<"\n\n\t\t3.Update a record \n\n\t\t4.Delete a record"
	<<"\n\n\t\t5.Exit\n\n\t\tSelect one option:";
	cin>>j;
	if(j==1)
	   showall();
	else if(j==2)
	{
	   showrecord();
	   manager();
	}
	else if(j==3)
	   updaterecord();
	else if(j==4)
	   deleterecord();
	else if(j==5)
	   exit(0);
	else
	{
	   cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	   manager();
	}
}
void about()
{
	clrscr();
	cout<<"\n\t\t\t\tAbout Computer Shoppe\n";
	gotoxy(1,10);
	cout<<"\n\n\n\n\tComputer Shoppe is a leading destination for shopping in India."
	<<"\n\n\tComputer Shopee offers some of the best prices and a completely"
	<<"\n\n\thassle free shopping experience with options of home delivery."
	<<"\n\n\tNow shop for your favorite monitors, CPU components, speakers,\n\n\tprinters "
	<<"and products from a host of other categories through\n\n\tComputer Shopee's shopping portal."
	<<"\n\n\tSome of the top selling brands on Computer Shopee are \n\n\tASUS,Samsung, Dell, Sony, Canon,LG."
	<<"\n\n\tGet the best prices and the best shopping experience \n\n\tevery time, guaranteed.";
	getch();
	customer();
}
void terms()
{
	clrscr();
	cout<<"\n\t\t\t\tTerms and conditons\n";
	gotoxy(1,10);
	cout<<"\n\n\n\n\t\t1.Goods once sold will not be exchanged/replaced."
	<<"\n\n\t\t2.Free Transit insurance for home delivery."
	<<"\n\n\t\t3.No credit is given."
	<<"\n\n\t\t4.Prices are fixed."
	<<"\n\n\t\t5.Minimum 5% discount is given to each customer."
	<<"\n\n\t\t6.For checking order details please save your orderid."
	<<"\n\n\t\t7.AN ISO 9001-2000 CERTIFIED COMPANY.";
	getch();
	customer();
}
void shop:: shopmenu()
{
    clrscr();
    int i;
    cout<<"\n\t\t\t\tComputer Shoppe";
    gotoxy(1,10);
    cout<<"\n\n\t\t1.Monitor\n\n\t\t2.C.P.U.\n\n\t\t3.Keyboard+Mouse\n\n\t\t4."<<
    "Speakers\n\n\t\t5.Printer\n\n\t\t6.View cart\n\n\t\t7.Pay Bill\n\n\t\t8.Exit\n";
    cout<<"\n\t\tPlease select any one option:";
    cin>>i;
    if(i==1)
       monitorbrandmenu();
    else if(i==2)
       cpu();
    else if(i==3)
       keym();
    else if(i==4)
       Speaker();
    else if(i==5)
       Printer();
    else if(i==6)
       Cart();
    else if(i==7)
       bill();
    else if(i==8)
       bye();
    else
    {
       cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
       shopmenu();
    }
}
void shop:: monitorbrandmenu()
{
     clrscr();
     int msub;
     cout<<"\n\t\t\t\tBrands available";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Dell\n\n\t\t2.LG\n\n\t\t3.Samsung\n\n\t\t4.ViewSonic"<<
     "\n\n\t\t5.Return to main menu\n\n\t\tPlease select any one option:";
     cin>>msub;
     clrscr();
     if(msub==1)
	dell();
     else if(msub==2)
	lg();
     else if(msub==3)
	samsung();
     else if(msub==4)
	viewsonic();
     else if(msub==5)
	shopmenu();
     else
     {
	cout<<"\nPlease select correct option.";sleep(2);clrscr();
	monitorbrandmenu();
     }
}
void shop:: cpu()
{
     clrscr();
     int cpch;
     gotoxy(35,2);
     cout<<"C.P.U.";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Motherboard\n\n\t\t2.Processor\n\n\t\t3.RAM\n\n\t\t4.Graphic Card"
     <<"\n\n\t\t5.Hard Disk\n\n\t\t6.Disc Writer\n\n\t\t7.Assembled CPUs\n\n\t\t8.Return to main menu"
     <<"\n\n\t\tPlease select the item you want to buy:";
     cin>>cpch;
     if(cpch==1)
       motherboard();
     else if(cpch==2)
       processor();
     else if(cpch==3)
	RAM();
     else if(cpch==4)
	grcard();
     else if(cpch==5)
	HDD();
     else if(cpch==6)
	DVDRW();
     else if(cpch==7)
	readycpu();
     else if(cpch==8)
	shopmenu();
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	cpu();
     }
}
void shop:: keym()
{
     clrscr();
     cout<<"\n\t\t\t\tKeyboard and Mouse combo";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Logitech Wireless Desktop Mk320\tRs1,350"
     <<"\n\n\t\t2.Logitech Wireless Combo MK260 \tRs1,296"
     <<"\n\n\t\t3.Logitech Wireless Combo M250  \tRs1,245"
     <<"\n\n\t\t4.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==4)
	 shopmenu();
     else if(temp>0&&temp<4)
     {
	 s.keymouse=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 shopmenu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	keym();
     }
}
void shop:: Speaker()
{
     clrscr();
     cout<<"\n\t\t\t\tSpeaker";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Philips HTS5530 Speaker\t Rs14,000"
     <<"\n\n\t\t2.Philips HTS2500 Speaker\t Rs7,210"
     <<"\n\n\t\t3.Logitech S-150 Usb 2.0 Speaker Rs600"
     <<"\n\n\t\t4.Sony 2.1 PC Speaker System\t Rs4,700"
     <<"\n\n\t\t5.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	shopmenu();
     else if(temp>0&&temp<5)
     {
	s.speaker=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	shopmenu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	Speaker();
     }
}
void shop:: Printer()
{
     clrscr();
     cout<<"\n\t\t\t\tPrinter";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Epson B-510DN Business Color Inkjet Printer\tRs23,000"
     <<"\n\n\t\t2.HP Officejet Pro 8000 Wireless Printer\tRs9,000"
     <<"\n\n\t\t3.HP Officejet 6000 Wireless\t\t\tRs6,000"
     <<"\n\n\t\t4.Canon Pixma iP4920 Inkjet Photo Printer\tRs10,000"
     <<"\n\n\t\t5.Epson WorkForce 60\t\t\t\tRs12,000"
     <<"\n\n\t\t6.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==6)
	 shopmenu();
     else if(temp>0&&temp<6)
     {
	 s.printer=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 shopmenu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 Printer();
     }
}
//**********Monitors***********
void shop:: dell()
{
     cout<<"\n\t\t\t\tDell";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.IN1720\t   17inches\tLCD\tRs5,590"
     <<"\n\n\t\t2.UltraSharp2007FP 20inches\tLCD\tRs9,000\n"
     <<"\n\t\t3.ST2220M\t   21.5inches\tLED\tRs8,150"
     <<"\n\n\t\t4.Back\n\n\t\t5.Return to main menu\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==4)
	 monitorbrandmenu();
     else if(temp==5)
	 shopmenu();
     else if(temp<4&&temp>0)
     {
	 s.monitor[0]=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 shopmenu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 dell();
     }
}
void shop:: lg()
{
     cout<<"\n\t\t\t\tLG";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.W2043C\t20inches\tLCD\tRs6,500\n\n\t\t2.W1943C\t18.5inches\tLCD\tRs6,050"
     <<"\n\n\t\t3.LG2381VR\t23inches\tLED\tRs12,350"
     <<"\n\n\t\t4.LG E2251VR\t21.5inches\tLED\tRs9,400\n\n\t\t5.Back\n\n\t\t6.Return to main menu"
     <<"\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	 monitorbrandmenu();
     else if(temp==6)
	 shopmenu();
     else  if(temp<5&&temp>0)
     {
	 s.monitor[1]=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 shopmenu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 lg();
     }
}
void shop:: samsung()
{
     cout<<"\n\t\t\t\tSamsung";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.B1930N\t18.5inches\tLCD\tRs6,400"
     <<"\n\n\t\t2.B2230 \t21.5inches\tLCD\tRs8,600"
     <<"\n\n\t\t3.PX2370\t23inches\tLED\tRs15,700\n\n\t\t4.S22A300B\t21.5inches\tLED\tRs9,100"
     <<"\n\n\t\t5.Back\n\n\t\t6.Return to main menu"
     <<"\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	monitorbrandmenu();
     else if(temp==6)
	shopmenu();
     else if(temp<5&&temp>0)
     {
	s.monitor[2]=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	shopmenu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	samsung();
     }
}
void shop:: viewsonic()
{
     cout<<"\n\t\t\t\tViewsonic";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.V3D231\t23inches\tLED\tRs11,750"
     <<"\n\n\t\t2.VP2365\t23inches\tLED\tRs12,325"
     <<"\n\n\t\t3.VA1931wa\t18.5inches\tLED\tRS4,770\n\n\t\t4.VA1948m\t19inches\tLED\tRs6,500"
     <<"\n\n\t\t5.Back\n\n\t\t6.Return to main menu"
     <<"\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	monitorbrandmenu();
     else if(temp==6)
	shopmenu();
     else if(temp<5&&temp>0)
     {
	s.monitor[3]=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	shopmenu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	viewsonic();
     }
}
//********CPU*****COMPONENTS*****
void shop:: motherboard()
{
     clrscr();
     cout<<"\n\t\t\t\tMotherboard";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Gigabyte GA-X58A-UD3R\tRs14,600\n\n\t\t2.EVGA 170-BL-E762\tRs18,000"
     <<"\n\n\t\t3.Asus P6X58D\t\tRs25,000\n\n\t\t4.EVGA E758-A1\t\tRs22,700\n\n\t\t5.Asus P6T Deluxe V2\tRs22,000\n\n\t\t6.Back"
     <<"\n\n\t\t7.Return to main menu."
     <<"\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==6)
	cpu();
     if(temp==7)
	shopmenu();
     else if(temp>0&&temp<6)
     {
	s.mthrbrd=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	cpu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	motherboard();
     }
}
void shop:: processor()
{
     clrscr();
     cout<<"\n\t\t\t\tProcessors";
     gotoxy(1,10);
     cout<<"\n\n\t1.Intel Core i7-3960X Extreme Edition\t6cores\t3.9Ghz\tRs55,000"
     <<"\n\n\t2.Intel Core i7-2600K\t\t\t4cores\t3.8Ghz\tRs16,960"
     <<"\n\n\t3.Intel Core i5-2500K\t\t\t4cores\t3.7Ghz\tRs11,735"
     <<"\n\n\t4.AMD Phenom II X6 1100T Black Edition\t6cores\t3.7Ghz\tRs14,000"
     <<"\n\n\t5.AMD FX-8150\t\t\t\t8cores\t4.2Ghz\tRs13,800"
     <<"\n\n\t6.Back\n\n\t7.Return to main menu.\n\n\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==6)
	cpu();
     if(temp==7)
	shopmenu();
     else if(temp>0&&temp<6)
     {
	s.pro=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	cpu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 processor();
     }
}
void shop:: RAM()
{
     clrscr();
     cout<<"\n\t\t\t\tR.A.M.";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Kingston 12GB (3x4GB)\tDDR3\t1333Mhz\tRs5,000"
     <<"\n\n\t\t2.Kingston 2GB (1x2GB)\tDDR3\t1333Mhz\tRs2,000"
     <<"\n\n\t\t3.Transcend 4GB aXeRam\tDDR3\t2400+\tRs4,500"
     <<"\n\n\t\t4.Transcend 2GB\t\tDDR3\t1600Mhz\tRs2,500"
     <<"\n\n\t\t5.Back\n\n\t\t6.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	cpu();
     if(temp==6)
	shopmenu();
     else if(temp>0&&temp<5)
     {
	s.ram=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	cpu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	RAM();
     }
}
void shop:: grcard()
{
     clrscr();
     cout<<"\n\t\t\t\tGraphic card";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.AMD Radeon HD 7950\t 900Mhz\t3GB\tRs11,945"
     <<"\n\n\t\t2.AMD Radeon HD 6970\t 880Mhz\t2GB\tRs22,000"
     <<"\n\n\t\t3.Nvidia GeForce GTX 570 742Mhz\t1.25GB\tRs22,450"
     <<"\n\n\t\t4.Nvidia GeForce GTS 450 810Mhz\t1GB\tRs7,250"
     <<"\n\n\t\t5.Back\n\n\t\t6.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	 cpu();
     if(temp==6)
	 shopmenu();
     else if(temp>0&&temp<5)
     {
	 s.gcard=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 cpu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 grcard();
     }
}
void shop:: HDD()
{
     clrscr();
     cout<<"\n\t\t\t\tHard Disk";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Seagate Barracuda\t\t500GB\tRs2,875"
     <<"\n\n\t\t2.Seagate Barracuda \t\t1TB\tRs5,000"
     <<"\n\n\t\t3.Western Digital Caviar Black  1TB\tRs7,000"
     <<"\n\n\t\t4.Western Digital Caviar Green  640GB\tRs3,000"
     <<"\n\n\t\t5.Back\n\n\t\t6.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==5)
	 cpu();
     if(temp==6)
	 shopmenu();
     else if(temp>0&&temp<5)
     {
	 s.hdd=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 cpu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 HDD();
     }
}
void shop:: DVDRW()
{
     clrscr();
     cout<<"\n\t\t\t\tDisc Writers";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Sony VRD-MC3\tDVD-RW\tRs1,500"
     <<"\n\n\t\t2.Sony MC5\tDVD-RW\tRs1,800"
     <<"\n\n\t\t3.LG BH10LS30\tBD-RW\tRs7,000"
     <<"\n\n\t\t4.Back\n\n\t\t5.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==4)
	 cpu();
     if(temp==5)
	 shopmenu();
     else if(temp>0&&temp<4)
     {
	 s.dvdrw=temp;
	 cout<<"\n\n\t\tAdded to cart.";sleep(1);
	 cpu();
     }
     else
     {
	 cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	 DVDRW();
     }
}
void shop:: readycpu()
{
     clrscr();
     cout<<"\n\t\t\t\tAssembled CPUs";
     gotoxy(1,10);
     cout<<"\n\n\t\t1.Low Budget (General Purpose) Rs15,000"
     <<"\n\n\t\t2.Medium Budget (Multimedia and light gaming) Rs25,000"
     <<"\n\n\t\t3.High Budget (High -end Gaming rig) Rs62,255"
     <<"\n\n\t\t4.Back\n\n\t\t5.Return to main menu.\n\n\t\tPlease select the item you want to buy:";
     cin>>temp;
     if(temp==4)
	 cpu();
     if(temp==5)
	 shopmenu();
     else if(temp>0&&temp<4)
     {
	s.rcpu=temp;
	cout<<"\n\n\t\tAdded to cart.";sleep(1);
	cpu();
     }
     else
     {
	cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
	readycpu();
     }
}
//***************CART***********CODING****************
//*************Adding*Items*in*CART********
void shop::adcart()
{
       fout.open("cart.dat",ios::out|ios::binary|ios::app);
       if(n==0)                  //If cart is empty
	 c.s_no=0;
       //Dell//
       if(monitor[0]==1)
       {
	   strcpy(c.cart,"Dell IN1720 Rs5,590\n");
	   c.price=5590;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[0]==2)
       {
	   strcpy(c.cart,"Dell UltraSharpTM 2007FP Rs9,000\n");
	   c.price=9000;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[0]==3)
       {
	   strcpy(c.cart,"Dell ST2220M Rs8,150\n");
	   c.price=8150;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       //LG//
       if(monitor[1]==1)
       {
	   strcpy(c.cart,"LG W2043C Rs6,500\n");
	   c.price=6500;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[1]==2)
       {
	   strcpy(c.cart,"LG W1943C Rs6,050\n");
	   c.price=6050;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[1]==3)
       {
	   strcpy(c.cart,"LG E2381VR Rs12,350\n");
	   c.price=12350;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[1]==4)
       {
	   strcpy(c.cart,"LG E2251VR Rs9,400\n");
	   c.price=9400;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       //Samsung//
       if(monitor[2]==1)
       {
	   strcpy(c.cart,"Samsung B1930N Rs6,400\n");
	   c.price=6400;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[2]==2)
       {
	   strcpy(c.cart,"Samsung B2230 Rs8,600\n");
	   c.price=8600;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[2]==3)
       {
	   strcpy(c.cart,"Samsung PX2370 Rs15,700\n");
	   c.price=15700;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[2]==4)
       {
	   strcpy(c.cart,"Samsung S22A300B Rs9,100\n");
	   c.price=9100;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       //Viewsonic//
       if(monitor[3]==1)
       {
	   strcpy(c.cart,"Viewsonic V3D231 Rs11,750\n");
	   c.price=11750;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[3]==2)
       {
	   strcpy(c.cart,"Viewsonic VP2365 Rs12,325\n");
	   c.price=12325;
	   c.s_no++;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[3]==3)
       {
	   c.s_no++;strcpy(c.cart,"Viewsonic VA1931wa Rs4,770\n");
	   c.price=4770;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(monitor[3]==4)
       {
	   c.s_no++;strcpy(c.cart,"Viewsonic VA1948m Rs6,500\n");
	   c.price=6500;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Motherboard//
       if(mthrbrd==1)
       {
	   c.s_no++;strcpy(c.cart,"Gigabyte GA-X58A-UD3R Rs14,600\n");
	   c.price=14600;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(mthrbrd==2)
       {
	   c.s_no++;strcpy(c.cart,"EVGA 170-BL-E762  Rs18,000\n");
	   c.price=18000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(mthrbrd==3)
       {
	   c.s_no++;strcpy(c.cart,"Asus P6X58D Rs25,000\n");
	   c.price=25000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(mthrbrd==4)
       {
	   c.s_no++;strcpy(c.cart,"EVGA E758-A1  Rs22,700\n");
	   c.price=22700;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(mthrbrd==5)
       {
	   c.s_no++;strcpy(c.cart,"Asus P6T Deluxe V2 Rs22,000\n");
	   c.price=22000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Processor//
       if(pro==1)
       {
	   c.s_no++;strcpy(c.cart,"Intel Core i7-3960X Extreme Edition Rs55,000\n");
	   c.price=55000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(pro==2)
       {
	   c.s_no++;strcpy(c.cart,"Intel Core i7-2600K  Rs16,960\n");
	   c.price=16960;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(pro==3)
       {
	   c.s_no++;strcpy(c.cart,"Intel Core i5-2500K  Rs11,735\n");
	   c.price=11735;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(pro==4)
       {
	   c.s_no++;strcpy(c.cart,"AMD Phenom II X6 1100T Black Edition  Rs14,000\n");
	   c.price=14000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(pro==5)
       {
	   c.s_no++;strcpy(c.cart,"AMD FX-8150  Rs13,800\n");
	   c.price=13800;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //RAM//
       if(ram==1)
       {
	   c.s_no++;strcpy(c.cart,"Kingston 12GB  Rs5,000\n");
	   c.price=5000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(ram==2)
       {
	   c.s_no++;strcpy(c.cart,"Kingston 2GB  Rs2,000\n");
	   c.price=2000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(ram==3)
       {
	   c.s_no++;strcpy(c.cart,"Transcend 4GB aXeRam  Rs4,500\n");
	   c.price=4500;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(ram==4)
       {
	   c.s_no++;strcpy(c.cart,"Transcend 2GB  Rs2,500\n");
	   c.price=2500;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Graphic Card//
       if(gcard==1)
       {
	   c.s_no++;strcpy(c.cart,"AMD Radeon HD 7950  Rs11,945\n");
	   c.price=11945;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(gcard==2)
       {
	   c.s_no++;strcpy(c.cart,"AMD Radeon HD 6970  Rs22,000\n");
	   c.price=22000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(gcard==3)
       {
	   c.s_no++;strcpy(c.cart,"Nvidia GeForce GTX 570  Rs22,450\n");
	   c.price=22450;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(gcard==4)
       {
	   c.s_no++;strcpy(c.cart,"Nvidia GeForce GTS 450  Rs7,250\n");
	   c.price=7250;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Hard Disk//
       if(hdd==1)
       {
	   c.s_no++;strcpy(c.cart,"Seagate Barracuda 500GB  Rs2,875\n");
	   c.price=2875;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(hdd==2)
       {
	   c.s_no++;strcpy(c.cart,"Seagate Barracuda  1TB  Rs5,000\n");
	   c.price=5000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(hdd==3)
       {
	   c.s_no++;strcpy(c.cart,"Western Digital Caviar Black  1TB  Rs7,000\n");
	   c.price=7000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(hdd==4)
       {
	   c.s_no++;strcpy(c.cart,"Western Digital Caviar Green  640GB Rs3,000\n");
	   c.price=3000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Disc Writers//
       if(dvdrw==1)
       {
	   c.s_no++;strcpy(c.cart,"Sony VRD-MC3  Rs1,500\n");
	   c.price=1500;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(dvdrw==2)
       {
	   c.s_no++;strcpy(c.cart,"Sony MC5  Rs1,800\n");
	   c.price=1800;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(dvdrw==3)
       {
	   c.s_no++;strcpy(c.cart,"LG BH10LS30  Rs7,000\n");
	   c.price=7000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       //Assembled CPU//
       if(rcpu==1)
       {
	   c.s_no++;strcpy(c.cart,"Low Budget Rs15,000\n");
	   c.price=15000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(rcpu==2)
       {
	   c.s_no++;strcpy(c.cart,"Medium Budget Rs25,000\n");
	   c.price=25000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(rcpu==3)
       {
	   c.s_no++;strcpy(c.cart,"High Budget  Rs62,255\n");
	   c.price=62255;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       //Keyboard+Mouse//
       if(keymouse==1)
       {
	   c.s_no++;strcpy(c.cart,"Logitech Wireless Desktop Mk320  Rs1,350\n");
	   c.price=1350;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(keymouse==2)
       {
	   c.s_no++;strcpy(c.cart,"Logitech Wireless Combo MK260  Rs1,296\n");
	   c.price=1296;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(keymouse==3)
       {
	   c.s_no++;strcpy(c.cart,"Logitech Wireless Combo M250  Rs1,245\n");
	   c.price=1245;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Speaker//
       if(speaker==1)
       {
	   c.s_no++;strcpy(c.cart,"Philips HTS5530 Speaker  Rs14,000\n");
	   c.price=14000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(speaker==2)
       {
	   c.s_no++;strcpy(c.cart,"Philips HTS2500 Speaker  Rs7,210\n");
	   c.price=7210;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(speaker==3)
       {
	   c.s_no++;strcpy(c.cart,"Logitech S-150 Usb 2.0 Speaker  Rs600\n");
	   c.price=600;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(speaker==4)
       {
	   c.s_no++;strcpy(c.cart,"Sony 2.1 PC Speaker System Rs4,700\n");
	   c.price=4700;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
      //Printer//
       if(printer==1)
       {
	   c.s_no++;strcpy(c.cart,"Epson B-510DN Business Color Inkjet Printer  Rs23,000\n");
	   c.price=23000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(printer==2)
       {
	   c.s_no++;strcpy(c.cart,"HP Officejet Pro 8000 Wireless Printer  Rs9,000\n");
	   c.price=9000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
	   c.s_no++;
       }
       else if(printer==3)
       {
	   c.s_no++;strcpy(c.cart,"HP Officejet 6000 Wireless  Rs6,000\n");
	   c.price=6000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(printer==4)
       {
	   c.s_no++;strcpy(c.cart,"Canon Pixma iP4920 Inkjet Photo Printer  Rs10,000\n");
	   c.price=10000;
	   total=total+c.price;fout.write((char*)&c,sizeof(c));
       }
       else if(printer==5)
       {
	   c.s_no++;strcpy(c.cart,"Epson WorkForce 60  Rs12,000\n");
	   c.price=12000;
	   total=total+c.price;
	   fout.write((char*)&c,sizeof(c));
       }
       fout.close();
}
void shop::vcart()		//***view*items*in*cart
{
       n=0;
       fin.open("cart.dat",ios::in|ios::binary);
       while(!fin.eof())
       {
	   fin.read((char*)&c,sizeof(c));
	   if(!fin.eof())
	   {
		c.Show();
		n++;
	   }
       }
       if(n==0)
       {
	   cout<<"\t\t!!Your cart is empty!!";
	   s.reset();
       }
       else
	   cout<<"Total:"<<"Rs."<<total;
       fin.close();
}
void shop::srcart()  		//Remove*items*from*Cart
{
       int i=0,no=1,a=0;
       char ch;
       fin.open("cart.dat",ios::in|ios::binary);
       fout.open("temp.dat",ios::out|ios::binary);
       cout<<"\n\nSelect the item you want to remove:";
       cin>>i;
       while(!fin.eof())
       {
	     fin.read((char*)&c,sizeof(c));
	     if(c.s_no==i&&!fin.eof())
	     {
		cout<<"\n\nAre you sure you want remove item  "<<i<<" ?(y/n):";
		cin>>ch;
		if(ch=='n'||ch=='N')
		{    fin.close();
		     fout.close();
		     s.reset();
		     Cart();
		}
		a++;
		total=total-c.price;
	     }
	     else if(i!=c.s_no && !fin.eof())
	     {
		c.s_no=no;
		fout.write((char*)&c,sizeof(c));
		no++;
	     }
       }
       if(a==0)
       {
	  cout<<"\n\nInvalid number selected.";
	  sleep(1.5);
	  fin.close();
	  fout.close();
	  srcart();
       }
       fin.close();
       fout.close();
       remove("cart.dat");
       rename("temp.dat","cart.dat");
       cout<<"\n\n!!Item removed!!";
       sleep(2);
       clrscr();
       s.reset();
       Cart();
}
void shop:: Cart()
{
     char ck;
     clrscr();
     cout<<"\n\t\t\t\tCart\n";
     gotoxy(1,10);
     adcart();  //writing items in cart
     vcart();   //view items of cart
     int  x=wherex(),y=wherey();
     gotoxy(74,36);
     cout<<"/~~~~~"
	 <<"\t\t\t\t\t\t                  	     /\n"
	 <<"\t\t\t\t\t\t    		       /\n"
	 <<"\t\t\t\t\t\t     		      /\n"
	 <<"\t\t\t\t\t\t     		     /\n"
	 <<"\t\t\t\t\t\t     		    /\n"
	 <<"\t\t\t\t\t    ------------------------\n";
     if(n==0)
     {   cout<<"\t\t\t\t\t    \\                     /\n";
	 cout<<"\t\t\t\t\t     \\    EMPTY          /\n";
	 cout<<"\t\t\t\t\t      \\                 /\n";
	 cout<<"\t\t\t\t\t       \\      CART     /\n";
	 cout<<"\t\t\t\t\t        \\             /\n";
	 cout<<"\t\t\t\t\t         \\___________/\n";
	 cout<<"\t\t\t\t\t            *     *";
     }
     else
     {
	 cout<<"\t\t\t\t\t    \\|||||||||||||||||||||/\n"
	 <<"\t\t\t\t\t     \\-------------------/\n"
	 <<"\t\t\t\t\t      \\|||||||||||||||||/\n"
	 <<"\t\t\t\t\t       \\---------------/\n"
	 <<"\t\t\t\t\t        \\|||||||||||||/\n"
	 <<"\t\t\t\t\t         \\===========/\n"
	 <<"\t\t\t\t\t            *     *";
     }
     gotoxy(x,y);
     if(n)
     {
	cout<<"\t\t\nA.Shop more\n\nB.Pay Bill\n\nC.Remove items from cart\n\nSelect one option:";
	cin>>ck;
	     if(ck=='A'||ck=='a')
	     {
		s.reset();
		shopmenu();
	     }
	     else if(ck=='B'||ck=='b')
	     {  s.reset();
		bill();
	     }
	     else if(ck=='C'||ck=='c')
		srcart();
	     else
	     {
		cout<<"\n\aPlease select correct option.";sleep(2);clrscr();
		s.reset();
		Cart();
	     }
      }
      getch();
      shopmenu();
}
//******************BILLING***********************
void shop:: bill()
{
   adcart();//writing items in cart
   n=0;
   char ch;
   fin.open("cart.dat",ios::in|ios::binary);
   while(!fin.eof())
   {
      fin.read((char*)&c,sizeof(c));
      if(!fin.eof())
	n++;
   }
   fin.close();
   if(n)                      //Checking if cart is non empty
   {
     char ck;
     float sum=0,tempid,tempdiscount;
     randomize();
     float ds=random(10)+5; //  Random discount to customers.From 5%-15%
     tempid=getorderid();// Random orderid for the current purchase
     clrscr();
     cout<<"\n\t\t\t\tBill";
     gotoxy(1,10);
     tempdiscount=total*ds/100;
     tempdiscount=floor(tempdiscount);
     sum=total-tempdiscount;
     cout<<"\n\n\t\tOrderid:OD"<<tempid<<endl<<endl;
     b.GETDATA(tempid,tempdiscount);
     vcart();	//Showing items,queued for buying
     cout<<"\n\n\nDiscount(%):"<<ds<<"("<<tempdiscount<<")";
     cout<<"\n\nWant products to be delivered at home?(y/n):";
     cin>>ck;
     if(ck=='y'||ck=='Y')
     {
       if(!strcmp(b.retcity(),"ajmer"))
       {
	  sum=sum+200;
	  cout<<"Deleivery charges(Ajmer):200";
       }
       else
       {
	  sum=sum+800;
	  cout<<"Deleivery charges(Outside Ajmer):800";
       }
     }
      sum=floor(sum);
      cout<<"\n\nTotal:"<<sum<<"\n\nThanks for using Computer Shoppe.";
      b.SETTOTAL(sum);
      getch();
      write_bill(b);
      cout<<"\nWant to visit consumer portal?:";
      cin>>ch;
      if(ch=='y'||ch=='Y')
	   customer();
       else
	   bye();
     }
     else
     {  clrscr();
	cout<<"\n\t\t\t\tBill\n\n\n\n\t\tYour cart is empty.";
	sleep(2);
	shopmenu();
     }
}
float getorderid()
{
     float temp_odid;
     temp_odid=random(1000001)+100;
     fin.open("record.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&b,sizeof(b));
	  if(!fin.eof())
	  {
	    if(fin.tellg()<0)
	      break;
	    else if(b.retid()==temp_odid)
	    {
		fin.close();
		getorderid();
	    }
	  }
     }
     fin.close();
     return  temp_odid;             //Returns unique orderid for the user
}
void write_bill(billing b)
{
     fout.open("record.dat",ios::binary|ios::app);
     fout.write((char*)&b,sizeof(b));
     fout.close();
     cout<<"\nRecord entered.";getch();
}
void billing:: GETDATA(float id,float disc)
{
     cout<<"\n\nEnter Name:";
     gets(name);
     cout<<"\nEnter Phone Number:";
     gets(phone);
     cout<<"\nEnter Address:";
     gets(address);
     cout<<"\nEnter City:";
     gets(city);
     for(int j=1;city[j]!='\0';j++)
	city[j]=(char)tolower(city[j]);
     od_id=id;discount=disc;
     int i=0;
     fin.open("cart.dat",ios::in|ios::binary);
     while(!fin.eof())
      {
	   fin.read((char*)&c,sizeof(c));
	   if(!fin.eof())
	   {
		 strcpy(cart[i],c.cart);//Writing bought items in the bill
		 i++;
	   }
      }
      fin.close();
      totalitems=i;
}
void billing::SHOWDATA()
{
     gotoxy(1,10);
     cout<<"\n\n\nOrderid:OD"<<od_id;
     cout<<"\n\nName:";puts(name);
     cout<<"\nPhone Number:";
     puts(phone);
     cout<<"\nAddress:";
     puts(address);
     cout<<"\nCity:";
     puts(city);
     cout<<endl;
     for(int i=0,j=totalitems;j>0;j--,i++)
     {
	  cout<<i+1<<". ";
	  puts(cart[i]);
     }
     cout<<"Total Items:"<<totalitems;
     cout<<"    Discount:"<<discount;
     cout<<"\t\tTotal Amount:"<<total;
}
void billing::UPDATE()
{
     cout<<"\n\nEnter Name:";gets(name);
     cout<<"\nEnter Phone Number:";gets(phone);
     cout<<"\nAddress:";gets(address);
     cout<<"\nCity:";gets(city);
}
//***********************RECORD*******ROOM**********************
void showrecord()
{
     clrscr();
     float temp_odid;
     int i=0;
     cout<<"\n\t\t\t\tSEARCH A RECORD";
     gotoxy(1,10);
     cout<<"Enter orderid: OD";
     cin>>temp_odid;
     fin.open("record.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&b,sizeof(b));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
		break;
	     else if(b.retid()==temp_odid)
	     {
	       b.SHOWDATA();
	       i++;
	     }
	  }
     }
     if(i==0)
	cout<<"\n\nNo record exists.";
     getch();
     fin.close();
}
void showall()
{
     clrscr();
     int i=1;
     gotoxy(35,2);
     cout<<"ALL RECORDS";
     gotoxy(1,10);
     cout<<"\n";
     fin.open("record.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&b,sizeof(b));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     clrscr();    gotoxy(35,2);
	     cout<<"ALL RECORDS";
	     gotoxy(1,10);
	     cout<<"\n";
	     b.SHOWDATA();
	     getch();
	  }
     }
     if(i==0)
     {	cout<<"\t\t!!Empty record room!!";
	getch();
     }
     fin.close();
     manager();

}
void updaterecord()
{
     clrscr();
     int i=0;
     long pos;
     float temp_odid;
     cout<<"\n\t\t\t\tUpdate Record details";
     gotoxy(1,10);
     cout<<"\n\nEnter orderid: OD";
     cin>>temp_odid;
     fio.open("record.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&b,sizeof(b));
	    if(b.retid()==temp_odid)
	    {
		  b.SHOWDATA();
		  getch();
		  b.UPDATE();
		  fio.seekp(pos);
		  fio.write((char*)&b,sizeof(b));
		  i++;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
     manager();
}
void deleterecord()
{
     clrscr();
     int i=0;
     float temp_odid;
     cout<<"\n\t\t\t\tDelete Record";
     gotoxy(1,10);
     cout<<"\n\nEnter orderid: OD";
     cin>>temp_odid;
     fout.open("temp.dat",ios::binary);
     fin.open("record.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&b,sizeof(b));
	  if(!fin.eof())
	    if(b.retid()==temp_odid)
	    {
		  b.SHOWDATA();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&b,sizeof(b));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("record.dat");
     rename("temp.dat","record.dat");
     getch();
     manager();
}