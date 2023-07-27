#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t\t\t\t                                        \n";
    cout << "\t\t\t\t\t\t\t        SUPERMARKET MAIN MENU           \n";
    cout << "\t\t\t\t\t\t\t                                        \n";
    cout << "\t\t\t\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t\t\t\t                                        \n";
    cout << "\t\t\t\t\t\t\t      1) Administrator                  \n";
    cout << "\t\t\t\t\t\t\t      2) Buyer                          \n";
    cout << "\t\t\t\t\t\t\t      3) Exit                           \n";
    cout << "\t\t\t\t\t\t\t                                        \n";
    cout << "\n\t\t\t\t\t\t\t      Please Select!";

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t     Please login...\n";
        cout << "\t\t\t     Enter email...\n";
        cin >> email;
        cout << "\t\t\t     Password...\n";
        cin >> password;

        if (email == "radhika@gmail.com" && password == "radhika@111")
        {
            administrator();
        }
        else
        {
            cout << "invalid password..........";
        }
        break;
    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }
    break;

    default:
    {
        cout << "Please Select for the Above...";
    }
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\t\t\t\t\t\t\t        ADMINISTRATOR MENU                        \n";
    cout << "\t\t\t\t\t\t\t     ____________ 1) Add Product_____________    \n";
    cout << "\t\t\t\t\t\t\t                                                 \n";
    cout << "\t\t\t\t\t\t\t     ____________ 2) Modify Product_____________    \n";
    cout << "\t\t\t\t\t\t\t                                                 \n";
    cout << "\t\t\t\t\t\t\t     ____________ 3) Delete Product_____________    \n";
    cout << "\t\t\t\t\t\t\t                                                 \n";
    cout << "\t\t\t\t\t\t\t     ____________ 4) Back To Main Menu_____________    \n";
    cout << "\t\t\t\t\t\t\t                                                 \n";

    cout << "n\n\n\t\t\t\t\t\t\t                    PLEASE ENTER YOUR CHOICE  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid Choice";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t\t\t\t               BUYER                       \n";
    cout << "\t\t\t\t\t\t\t     _________________________    \n";
    cout << "\t\t\t\t\t\t\t         1) Buy Product     \n";
    cout << "\t\t\t\t\t\t\t         2) GO Back          \n";
    cout << "\t\t\t\t\t\t\t     _________________________    \n";
    cout << "\t\t\t\t\t\t\t                                                 \n";

    cout << "n\n\n\t\t\t\t\t\t\t                    PLEASE ENTER YOUR CHOICE  ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid Choice";
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\t\t\t     Add New  Product   \n ";
    cout << "\n\n\t\t\t  ProductCode of  Product   \n ";
    cin >> pcode;
    cout << "\n\n\t\t\t  Name of  Product   \n ";
    cin >> pname;
    cout << "\n\n\t\t\t Price of  Product   \n ";
    cin >> price;
    cout << "\n\n\t\t Discount of  Product   \n ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
        goto m;
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "REcord inserted";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    int p;
    int d;
    string n;
    cout << "\n\n\t\t\t\t   Modify the record";
    cout << "\n\n\t\t\t\t   Product Code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File Doesn't Exist!!!!";
    }
    else
    {
        data1.open("database1.text", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\n\t\t\t Product New Code   :";
                cin >> c;
                cout << "\n\t\t\t  Name of Prodcut  : ";
                cin >> n;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t\t Discount : ";
                cin >> d;
                data1 << "  " << c << "  " << n << "  " << p << "  " << d << "\n";
                cout << "REcord inserted";
                token++;
            }
            else
            {
                data1 << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("databas1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t\t DELETE PRODUCT";
    cout << "\n\n Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File does not exist!!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t prodcut deleted successfully";
                token++;
            }
            else
            {
                data1 << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data>>pcode>>pname>>price>>dis;
            }

            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", " database.txt");

            if (token == 0)
            {
                cout << "\n\n Record not found sorry!";
            
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|__________________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|__________________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{

    fstream data;
    int arr[100];
    int arrq[100];
    string choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t  RECEIPT    ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty Database";
    }
    else
    {
        data.close();

        list();
        cout << "\n______________________________________________\n";
        cout << "\n|                                             |\n";
        cout << "\n|            Please Place The Order           |\n";
        cout << "\n|                                             |\n";
        cout << "\n______________________________________________\n";
        do
        {
            m:
            cout << "\n\n Enter Product code : ";
            cin >> arr[c];
            cout << "\n\n Enter Product Quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arr[c] == arr[i])
                {
                    cout << "\n\n Duplicate Product code.Please Try Again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want another product? if yes then press Y els no";
            cin>>choice;
        } while(choice == "y");
        cout<<"\n\n\t\t\t______________________RECEIPT_________________________\n";
        cout << "ProNo\t\t product Name\t\tproduct quantity\t price\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
           data.open("database.txt",ios::in);
           data>>pcode>>pname>>price>>dis;
           while(!data.eof()){
            if(pcode==arr[i]){
                amount=price*arrq[i];
                dis=amount-(amount*dis/100);
                total=total+dis;
                cout<<"\n"<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<dis;
            }
            data>>pcode>>pname>>price>>dis;
           }
        }
        data.close();
    }
    cout<<"\n\n_________________________________________\n";
    cout<<"\n Total Amount : "<<total ;
}
int main()
{
shopping s;
s.menu();
    return 0;
}