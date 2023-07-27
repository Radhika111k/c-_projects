#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <String>

using namespace std;
void menu();// forward declaration of function

class ManageMenu
{
protected:
    string userName;

public:
    ManageMenu()
    {
        system("color 0D"); // change terminal color green blue red purple yellow white
        /*  0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White

    1 = Blue        9 = Light Blue*/
        cout << "\n\n\n\n\n\n\n\t   Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu();
    }
    ~ManageMenu() {}
};

class Customers
{
public:
    static string name;
    string gender, address;
    int age;
    long int mobileNo;
    static int cusID;
    char all[999];

    void getDetails()
    {

        ofstream out("old_customers.txt", ios::app);
        {
            cout << "Enter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            // getline(cin, name);
             cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Customer MobileNumber: ";
            cin >> mobileNo;
            cout << "Enter Customer Address: ";
            cin >> address;
            cout << "Enter Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName : " << name << "\nAge : " << age << "\nMObile Number : " << mobileNo << "\nAddress : " << address << "\nGender : " << gender << endl;
        out.close();
        cout << "\n SAVED \nNOTE : We saved your details record for future purpose\n"
             << endl;
    }
    void showDetails()
    {
        ifstream in("old_customers.txt");
        {
            if (!in)
            {
                cout << "FILE ERROR!" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};
int Customers::cusID;
string Customers::name;
class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastcabCost;

    void cabDetails()
    {

        cout << "We collaborated with fastest, safest and smartest cab service around the country" << endl;
        cout << "------------------ABC Cabs---------------------\n"
             << endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 for 1KM" << endl;

        cout << "\nTo Calculate Cost For your JOURNEY : " << endl;
        cout << "Enter Which kind of cab you need :";
        cin >> cabChoice;
        cout << "Enter kilometers you have to travel :";
        cin >> kilometers;

        int hireCab;

        if (cabChoice == 1)
        {
            cabCost = kilometers * 15;
            cout << "\nYour Tour cost " << cabCost << " rupees for a STANDARD CAB\n " << endl;
            cout << "press 1 to hire this cab: or ";
            cout << "press 2 to Select another cab: ";
            cin >> hireCab;

            system("CLS"); // to clear console
            if (hireCab == 1)
            {
                lastcabCost = cabCost;
                cout << "\n You have Successfully Hired a STANDARD CAB" << endl;
                cout << "    Goto Menu and take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to previous Menu \nPlease Wait!" << endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 25;
            cout << "\nYour Tour cost " << cabCost << " rupees for a LUXURY CAB " << endl;
            cout << "press 1 to hire this cab: or";
            cout << "press 2 to Select another cab: ";
            cin >> hireCab;

            system("CLS"); // to clear console
            if (hireCab == 1)
            {
                lastcabCost = cabCost;
                cout << "\n You have Successfully Hired a LUXURY CAB" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Main Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
        {
            menu();
        }
    }
};

float Cabs::lastcabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;
    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        for (int a = 0; a < 3; a++)
        {
            cout << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }
        cout << "\nCurrently we collaborated with above hotels!\n" << endl;
        cout << "Press any key to back or \nEnter number of the hotel you want to book: ";
        cin >> choiceHotel;
        system("CLS");

        // WELCOME TO HOTEL AVENDRA-------------------------------------------------------------------------------

        if (choiceHotel == 1)
        {
            cout << "................WELCOME TO HOTEL AVENDRA.................\n"
                 << endl;
            cout << "The Garden Food and Breverage, Enjoy all you can drink, stay and get chilled in the summer sun." << endl;
            cout << "Packages offered by Avendra:\n"
                 << endl;
            cout << "1. STANDARD PACK" << endl;
            cout << "\tAll basic facilities you need just for: RS.5000.00" << endl;
            cout << "2. PREMIUM PACK" << endl;
            cout << "\tEnjoy premium pack: RS.10000.00" << endl;
            cout << "3. LUXURY PACK" << endl;
            cout << "\tLive luxurius life at Avendra: RS.15000.00" << endl;
            cout << "\nPress another key to back or\nEnter packages number you want to book: ";
            cin >> packChoice;

            if (packChoice == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to previous Menu\nPlease wait...." << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to Redirect main menu: ";
            cin >> gotomenu;
            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        // WELCOME TO HOTEL CHOICEYOU-------------------------------------------------------------------------------
        if (choiceHotel == 2)
        {
            cout << "................WELCOME TO HOTEL CHOICEYOU.................\n"
                 << endl;
            cout << "The Garden Food and Breverage, Enjoy all you can drink, stay and get chilled in the summer sun." << endl;
            cout << "Packages offered by ChoiceYOu:\n"
                 << endl;
            cout << "1. STANDARD PACK" << endl;
            cout << "\tAll basic facilities you need just for: RS.6000.00" << endl;
            cout << "2. PREMIUM PACK" << endl;
            cout << "\tEnjoy premium pack: RS.12000.00" << endl;
            cout << "3. LUXURY PACK" << endl;
            cout << "\tLive luxurius life at ChoiceYou: RS.15000.00" << endl;
            cout << "\nPress another key to back or\nEnter packages number you want to book: ";
            cin >> packChoice;

            if (packChoice == 1)
            {
                hotelCost = 6000.00;
                cout << "\nYou have successfully booked Standard Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 2)
            {
                hotelCost = 12000.00;
                cout << "\nYou have successfully booked Premium Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to previous Menu\nPlease wait...." << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to Redirect main menu: ";
            cin >> gotomenu;
            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        // WELCOME TO HOTEL ELEPHANTBAY-------------------------------------------------------------------------------
        if (choiceHotel == 2)
        {
            cout << "................WELCOME TO HOTEL ELEPHANTBAY.................\n"
                 << endl;
            cout << "The Garden Food and Breverage, Enjoy all you can drink, stay and get chilled in the summer sun." << endl;
            cout << "Packages offered by ELEPHANTBAY:\n"
                 << endl;
            cout << "1. STANDARD PACK" << endl;
            cout << "\tAll basic facilities you need just for: RS.6000.00" << endl;
            cout << "2. PREMIUM PACK" << endl;
            cout << "\tEnjoy premium pack: RS.12000.00" << endl;
            cout << "3. LUXURY PACK" << endl;
            cout << "\tLive luxurius life at ELEPHANTBAY: RS.15000.00" << endl;
            cout << "\nPress another key to back or\nEnter packages number you want to book: ";
            cin >> packChoice;

            if (packChoice == 1)
            {
                hotelCost = 6000.00;
                cout << "\nYou have successfully booked Standard Pack at ELEPHANTBAY" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 2)
            {
                hotelCost = 12000.00;
                cout << "\nYou have successfully booked Premium Pack at ELEPHANTBAY" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at ELEPHANTBAY" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to previous Menu\nPlease wait...." << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to Redirect main menu: ";
            cin >> gotomenu;
            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
    }
};
float Booking::hotelCost;
class Charges : public Booking, Cabs, Customers
{
public:
    void printBill()
    {
        ofstream outf("receipt.txt");
        {
            outf << "................ABC Travel Agency.................." << endl;
            outf << "................     RECEIPT     .................." << endl;
            outf << "___________________________________________________" << endl;
            outf << "Customer ID     :" << Customers::cusID << endl
                 << endl;
            outf << "Customer Name   :" << Customers::name << endl
                 << endl;
            outf << "Description\t\t\t   Total" << endl;
            outf << "Hotel cost      :\t\t" << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel(cab)cost :\t\t" << fixed << setprecision(2) << Cabs::lastcabCost << endl;
            outf << "___________________________________________________" << endl;
            outf << "Total Charge    :\t\t" << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastcabCost << endl;
            outf << "___________________________________________________" << endl;
            outf << "..............Thank You for Visiting................" << endl;
        }
        outf.close();
    }
    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File opening Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotomenu;
    cout << "\t\t   *     ABC TRAVELS    *\n"
         << endl;
    cout << "         ..........  MAIN MENU  ...............  " << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBooking Management  -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Your Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if (mainChoice == 1)
    {
        cout << "........Customers.........\n"<< endl;
        cout << "1.Enter New Customer" << endl;
        cout << "2.See Old Customers" << endl;

        cout << "\nEnter Choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to previous Menu\nPlease wait...." << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "\nPress 1 to Redirect main menu : ";
        cin >> gotomenu;
        system("CLS");
        if (gotomenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "---------> Book a Luxury Hotel using the System <------" << endl;
        a4.hotels();
    }
    else if (mainChoice == 4)
    {
        cout << "           -----> Get Your RECEIPT <-----" << endl;
        a5.printBill();
        cout << " Your receipt is already printed you can get it from file path\n"
             << endl;
        cout << "to display the your recipt in the screen Enter 1 :\n or\nEnter another key to back main menu :";
        cin >> gotomenu;
        if (gotomenu == 1)
        {
            system("CLS");
            a5.showBill();
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            system("CLS");
            if (gotomenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        cout << "\t\t\t...GOOD BYE...." << endl;
        cout << "\t\t...THANK YOU FOR VISITING US...." << endl;
        Sleep(2000);
        system("CLS");
        menu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to previous Menu\nPlease wait...." << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;

    return 0;
}