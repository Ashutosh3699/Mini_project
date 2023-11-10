
//************************************** DEMO PROJECT ***************************************

#include <iostream>
using namespace std;

class snack
{
    // declaration of detail of order
protected:
    static string id;
    /*used static id as user should not get changed as the name will we used by diffrent
    classes*/
    static char size;
    static string name_of_order;
    char choice;
    static int count;
    /*used static count as user should not get changed as the name will we used by diffrent
    classes at the same instances*/
    static int price;
    /*shouldn't get vary according to changes */

public:
    void set_data(char); // set the data that user clicked

    void display(); // display the item details that user order

    void size_packet(); // size of the item user will select
};

// call out of static variables
int snack ::price = 0;

string snack ::name_of_order;

string snack ::id;

char snack ::size;

int snack ::count;

void snack ::size_packet()
{
    // size user can order

    cout << "You have three size " << endl;
    cout << "1. S(base price:20)" << endl
         << "2. M(base price:30)" << endl
         << "3. L(base price:40)" << endl;

    cin >> choice;
    // user will provide the size
}

void snack ::set_data(char choice)
{
    /*****setting up the selected data int the static variables ****/

    if (choice == 'S' || choice == 's')
    { // small size of any item user select
        this->id = "s10023948small";
        this->size = choice;
        this->price = 20;
    }
    if (choice == 'M' || choice == 'm')
    { // medium size of any item user select
        this->id = "m10023948medium";
        this->size = choice;
        this->price = 30;
    }
    if (choice == 'L' || choice == 'l')
    { // large size of any item user select
        this->id = "l10023948large";
        this->size = choice;
        this->price = 40;
    }
}

void snack ::display()
{
    // display the item and its detail
    cout << "the order has been place" << endl;
    cout << "the order details are" << endl;
    cout << "item id: " << this->id << endl;
    cout << "size: " << this->size << endl;
    cout << "name of the order: " << this->name_of_order << endl;
    cout << "number of product in the cart: " << this->count << endl;
    cout << "price: " << this->price << "$" << endl;
}

class fruitsnack : public snack
{

public:
    bool citrus()
    { // if the user want to select the citrus
        char c;

        // this is a infinite loop for the user if any invalid value is entered

        do
        {
            cout << "Do you want citrus fruit:" << endl
                 << "press 'Y' for yes" << endl
                 << "press 'N' for no" << endl;
            cin >> c;

            if (c == 'y' || c == 'Y')
            { // if nut
                return true;
            }
            else if (c == 'N' || c == 'n')
            { // non nut
                return false;
            }
            else
            {
                cout << "invalid entry : please enter write mentions" << endl;
            }
        } while (c != 'y' || c != 'Y' || c != 'N' || c != 'n');
    }

    void enter_choice()
    {                   // code addtion
        int user_count; // for the input that user will provide

        if (citrus())
        { // if citrus
            this->name_of_order = "citus fruit";
            size_packet();
            cout << "enter the count " << endl;
            cin >> user_count;          // user count
            count = user_count + count; // static count plus new count
            process1(count);
        }
        else
        { // if non cuiturs
            this->name_of_order = "non-citus fruit";
            size_packet();
            cout << "enter the count " << endl;
            cin >> user_count;
            count = user_count + count; // static count plus new count
            process2(count);
        }
    }

    void process2(int);

    void process1(int);
};

void fruitsnack ::process1(int count)
{
    set_data(choice);
    this->price = (price - 6) * count; // total price of the amunt
    if (price == 0)
    {
        // if the count is selected is zero
        cout << "the item count is 0" << endl;
    }
}

void fruitsnack ::process2(int count)
{

    set_data(choice);
    this->price = price * count; // total price of the amunt
    if (price == 0)
    {
        // if the count is selected is zero
        cout << "the item is count is 0" << endl;
    }
}

class saltysnack : public snack
{

public:
    bool nut()
    { // if the user want to select the nut
        char c;

        // this is a infinite loop for the user if any invalid value is entered

        do
        {
            cout << "Do you want citrus fruit:" << endl
                 << "press 'Y' for yes" << endl
                 << "press 'N' for no" << endl;
            cin >> c;

            if (c == 'y' || c == 'Y')
            { // if nut
                return true;
            }
            else if (c == 'N' || c == 'n')
            { // non nut
                return false;
            }
            else
            {
                cout << "invalid entry : please enter write mentions" << endl;
            }
        } while (c != 'y' || c != 'Y' || c != 'N' || c != 'n');
    }

    void enter_choice()
    {
        int user_count; // for the input that user will provide
        if (nut())
        {
            this->name_of_order = "nut fruit";
            size_packet();
            cout << "enter the count " << endl;
            cin >> user_count;
            count = user_count + count; // static count plus new count
            process1(count);
        }
        else
        {
            this->name_of_order = "non-nut fruit";
            size_packet();
            cout << "enter the count " << endl;
            cin >> user_count;
            count = user_count + count; // static count plus new count
            process2(count);
        }
    }
    void process2(int);

    void process1(int);
};

void saltysnack ::process1(int count)
{

    set_data(choice);
    this->price = (price - 5) * count; // total price of the amunt
    if (price == 0)
    {
        // if the count is selected is zero
        cout << "the item is count is 0" << endl;
    }
}

void saltysnack ::process2(int count)
{

    set_data(choice);
    this->price = price * count; // total price of the amunt
    if (price == 0)
    {
        // if the count is selected is zero
        cout << "the item is count is 0" << endl;
    }
}

class add_to_cart : public snack
{

public:
    void show_total();

    void place_order();
};

void add_to_cart ::show_total()
{

    cout << "number of product in the cart: " << this->count << endl;
    // name of the order you selected
    //  cout<<"name of the order you select: "<<this->name

    cout << "the amount is:" << this->price << endl;
}

void add_to_cart ::place_order()
{
    display();
}

int main()
{

    char op; // user to asked the user what snack user want

    add_to_cart ok; // add_to_cart object is created

    // starting line
    cout << "Welcome to new snack" << endl
         << "you have two choice" << endl;

    // cout << "1.fruitsnack(enter f)" << endl
        //  << "2.saltysnack(enter s)" << endl;

    // if any value other than given value the user will provide it will run in a do while loop
    do
    {
         cout << "1.fruitsnack(enter f)" << endl
         << "2.saltysnack(enter s)" << endl;

        cout << "Enter 'p' to place_order" << endl
             << "Enter 'e' to exit from app" << endl;
        cin >> op;

        if (op == 'f' || op == 'F')
        {
            fruitsnack ob1;
            ob1.enter_choice();
        }

        else if (op == 's' || op == 'S')
        {
            saltysnack ob2;
            ob2.enter_choice();
        }
        else if (op == 'e' || op == 'E')
        {
            exit(1);
        }
        else
        {
            ok.show_total();
        }

    } while (op != 'p');

    ok.display();// if exit nothing will display but while middle of any process 
    // and exit then will display all value zero
    

    return 0;
}