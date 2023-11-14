#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

// class for product that we use
class Product{

    protected:
        string name;
        string product_id;
        int price;
        string company_name;
        int stockLevel;

    public:

        //set deatils for the product info
        void setData(string name, string product_id, int price, string company_name){

            this->name = name;
            this->product_id = product_id;
            this->price = price;
            this->company_name = company_name;
        }

        //to check the stock level of the that product
        void setStock(int d){
            this->stockLevel = d;
        }

        //to fetch the details of that product
        int getprice(){return this->price;}
        string getname(){return this->name;}
        int getstock(){return this->stockLevel;}

        //to match between two product:
        //operator overload
        bool operator==(Product &p){
            return (getname() == p.getname() && getprice() == p.getprice() && getstock() == p.getstock());
        }


};
//by using inheritance we can diffrentiate product into two classes
class Tech_p : public Product{ //heritate the properties from product class

    int rating;
    int discount;

    public:

        Tech_p(int r, int dis){ //construct call of that product with rating and discount 
            this->rating = r;
            this->discount = dis;
        }

        void display(){

            cout<<"name of product: "<<this->name<<endl;
            cout<<"the price is: "<<this->price<<endl;
            cout<<"the stock level is: "<<this->stockLevel<<endl;
            cout<<"the product_id is: "<<this->product_id<<endl;
            cout<<"the company name is: "<<this->company_name<<endl;
            cout<<"the rating is: "<<this->rating<<endl;

        }

};

class Non_tech_p : public Product{ //inherit the properties from product class

    int discount;
    string manu_date;

    public:

        Non_tech_p(int dis, string ch){//taking detail of discount and manufacture date
            this->discount = dis;
            this->manu_date = ch;
        }

        void display(){

            cout<<"name of product: "<<this->name<<endl;
            cout<<"the price is: "<<this->price<<endl;
            cout<<"the stock level is: "<<this->stockLevel<<endl;
            cout<<"the product_id is: "<<this->product_id<<endl;
            cout<<"the company name is: "<<this->company_name<<endl;
            cout<<"the manu_date is: "<<this->manu_date<<endl;

        }

};

//class store product details in a container: we can remove and add and view all the product details
class inventory{

    private:
        vector<Product>disp;

    public:
        void addProduct(Product ob){
            disp.push_back(ob);
        }

        void dispProduct(){
            cout<<"Detail of the order: "<<endl;
            for(int i=0; i<disp.size(); i++){
                cout<<disp[i].getname()<<"    Price is:"<<disp[i].getprice()<<endl;
            }
        }

        //compare name of the product and provide all the details of that same product if it is present in the store
        pair<Product,bool> compareP(string s){

            for(int i=0; i<disp.size(); i++){
                if(disp[i].getname() == s){
                    pair<Product,bool>p = make_pair(disp[i],true );
                    return p;
                }
            }
            pair<Product,bool>p = make_pair(disp[0],false);
            return p;
        }

};

//class for the customer to select the object and store selected object 
class shoping_cart{

    private:
        vector<Product>store;

    public:
    //store the selected object
        void addProduct(Product ob){
            store.push_back(ob);
        }

        //remove the item from add to cart
        void removeProduct(Product ob){

            for(auto it=store.begin(); it!=store.end(); it++){

                if(*it == ob){
                    store.erase(it);
                    break;
                }
            }
        }
        //get the total cost of the shopping cart
        int totalCost(){

            int sum = 0;
            for(int i=0; i < store.size(); i++){//waring checkout
                sum += store[i].getprice();
            }
            return sum;
        }

        //to do any operation over the selected product by users
        pair<Product,bool> compareP(string s){

            for(int i=0; i<store.size(); i++){
                if(store[i].getname() == s){
                    pair<Product,bool>p = make_pair(store[i],true );
                    return p;
                }
            }
            pair<Product,bool>p = make_pair(store[0],false);
            return p;
        }
        //get the deatils of the object
        void view(){
            cout<<"Detail of the order: "<<endl;
            for(int i=0; i<store.size(); i++){
                cout<<"The name of the product: "<<store[i].getname()<<"    Price is:"<<store[i].getprice()<<endl;
            }
            if(store.size()==0){
                cout<<"no item is present: "<<endl;
            }
        }
        //to check the size is 0 or not
        bool no_of_item(){
            if(store.size()){
                return true;
            }
            return false;
        }

};

class customer{

    //details of the customer
    string name;
    int customer_id;
    string address;
    string email;

    public:
    //details of the customers directly calling constructor
        customer(string name, int customer_id, string address, string email){
            this->name = name;
            this->customer_id = customer_id;
            this->address = address;
            this->email = email;
        }

        //to fetch the details of the customer
        string getaddress(){
            return this->address;
        }
        string getname(){
            return this->name;
        }
        string getemail(){
            return this->email;
        }
};

class payment{


    //payment system for the customer
    int amount;
    string paymentMethod;

    public:

        void setPayment(int amount, string method){
            this->amount = amount;
            this->paymentMethod = method;
        }
        void displaypayment(){
            cout<<"payment method is: "<<paymentMethod<<endl;
            cout<<"the total amount is: "<<amount<<endl;
        }
        int getAmount(){
            return amount;
        }
        string getMethod(){
            return paymentMethod;
        }

};

class shipping{

    string shippingMethod;
    int charge;

    public:

        shipping(){}

        shipping(string shippingMethod, int shippingCost) {
        this->shippingMethod = shippingMethod;
        this->charge = shippingCost;
        }

        void setship(string , int);

        int getCost(){
            return charge;
        }
        string getMethod(){
            return shippingMethod;
        }

};

void shipping :: setship(string shippingMethod, int shippingCost){
    this->shippingMethod = shippingMethod;
    this->charge = shippingCost;
}

class order{

    int order_id;
    string date;

    public:
        order(int order_id, string date){
            this->order_id = order_id;
            this->date = date;
        }

        void OrderPlace(customer, shoping_cart, payment, shipping);

};

void order :: OrderPlace(customer cust, shoping_cart prod, payment pay, shipping ship){

    //customer wala part
    cout<<"The order has been placed:"<<endl<<endl<<endl;
    cout<<"customer name : "<<cust.getname()<<"         email id: "<<cust.getemail()<<endl;
    cout<<"address to be placed: "<<cust.getaddress();
    cout<<endl<<endl;

    //product wala part
    prod.view();
    cout<<endl<<endl;

    //shipping ka part
    cout<<"The shipping detail are:"<<endl;
    cout<<"The mode of ship is: "<<ship.getMethod()<<" and the charge is: "<<ship.getCost();
    cout<<endl<<endl;

    //payment ka part
    cout<<"The mode of payment was: "<<pay.getMethod()<<endl;
    cout<<"The total cost is: "<<pay.getAmount()<<endl;
}

int main(){

    Tech_p iphone(5,10);
    iphone.setData("iphone_15", "1002Iphone", 100000, "apple");
    iphone.setStock(10);

    Non_tech_p notebook(10,"10-11-2023");
    notebook.setData("single_line","1002book", 100, "classmate");
    notebook.setStock(10);

    Tech_p samsung(5,10);
    samsung.setData("samsung_A50", "1003samsung", 50000, "samsung");
    samsung.setStock(10);

    inventory storage;
    storage.addProduct(iphone);
    storage.addProduct(notebook);
    storage.addProduct(samsung);


    cout<<"             Welcome to shopping cart       "<<endl;
    cout<<"Enter '1' to login as admin or '2' to login as customer:"<<endl;
    int num;
    do {
        cin>>num;
        if(num!=1 && num!=2){
            cout<<"you entered wrong number"<<endl;
        }
        if(num==3){
            exit(0);
        }
    }while(num!=1 && num!=2);

    //customer part:
    if(num == 2){
        cout<<"enter the customer detail:"<<endl;
        string name,address,email;
        cin>>name>>address>>email;

        //customer_id is given as an autogenerated

        customer ashu(name,1221,address,email);
        label:
        storage.dispProduct();

        string s;
        shoping_cart cust;

        do {

            cout<<"enter the product name that you want to store in shopping cart"<<endl;
            cout<<"enter exit to move forward"<<endl;
            cin >> s;

            if(s == "exit"){
                break;
            }

            pair<Product,bool> stockP = storage.compareP(s);
            
            // cust.addProduct();
            if(stockP.second){
                cust.addProduct(stockP.first);
            }
            else{
                cout<<"no such product is there"<<endl;
            }

        }while(s!="exit");

        char show;

        cout<<"Press s to view the item you selected:"<<endl;
        cout<<"Press r to remove the item you selected:"<<endl;
        cin>>show;

        int amount = cust.totalCost();

        if(show == 's'){
            cust.view();
            cout<<"The total cost is: "<<amount<<endl;
        }
        if(show == 'r'){
            string s;
        remove:
            do {

                cout<<"enter the product name that you remove to store in shopping cart"<<endl;
                cout<<"enter exit to move forward"<<endl;
                cin >> s;

                if(s == "exit"){
                    break;
                }

                pair<Product,bool> stockP = storage.compareP(s);
                
                // cust.addProduct();
                if(stockP.second){
                    cust.removeProduct(stockP.first);
                }
                else{
                    cout<<"no such product is there"<<endl;
                }

            }while(s!="exit");
            
            if(cust.no_of_item()){
                cout<<"there is no product in cart"<<endl;
            }

            char select;
            cout<<"enter 's' to select product again or 'p' to place order or 'r' to remove "<<endl;
            cin>>select;

            if(select == 's'){
                goto label;
            }
            if(select == 'r'){
                goto remove;
            }
            
        }
        char place;
        cout<<"Press p to place the order :"<<endl;
        cin>>place;

        payment pay;
        shipping ship("truck",10);

        pay.setPayment(amount+ship.getCost(),"credit_card");

        order placed(1002,"11-12-2023");

        placed.OrderPlace(ashu,cust,pay,ship);

    }
    
    //Admin part :

    if(num == 1){

        int num;
        do{

            cout<<"Enter the num to do the required process : "<<endl;
            cout<<"1. list of product :"<<endl<<"2. want to add some product "<<endl;
            cin>>num;

        }while(num != 1 && num != 2);

        if(num == 2){

            cout<<"Want to add some product into the ineventory:"<<endl;

            int num;
            do{

                cout<<"Enter the product type you want to add: "<<endl;
                cout<<"1. tech product:"<<endl<<"2. non_tech product"<<endl<<"3. exit";
                cin>>num;

                if(num == 3){
                    exit(0);
                }

            }while(num != 1 && num != 2);
            start: 
            if(num == 1){

                cout<<"enter the details of the product: "<<endl;
                string name,id,company;
                int price,stocklevel,rating,discount;

                cout<<"enter the name: "<<endl;
                cin>>name;
                cout<<"enter the id: "<<endl;
                cin>>id;
                cout<<"enter the company: "<<endl;
                cin>>company;
                cout<<"enter the price: "<<endl;
                cin>>price;
                cout<<"enter the stocklevel: "<<endl;
                cin>>stocklevel;
                cout<<"enter the rating: "<<endl;
                cin>>rating;
                cout<<"enter the discount: "<<endl;
                cin>>discount;

                Tech_p prod(rating,discount);
                prod.setData(name, id, price, company);
                prod.setStock(stocklevel);

                storage.addProduct(prod);

                cout<<"your product has been added in the inventory"<<endl;

                cout<<"if you want to add some more product enter y else if see inventory press 'o':"<<endl;
                char yes;
                cin>>yes;
                if(yes == 'y'){
                    goto start;
                }
                if(yes == 'o'){
                    goto start2;
                }
            }

        }

        if(num == 1){
            start2:
                cout<<"the list of the product are: "<<endl;
                storage.dispProduct();

        }
        

    }

    return 0;
}