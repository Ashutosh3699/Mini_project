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

        void setData(string name, string product_id, int price, string company_name){

            this->name = name;
            this->product_id = product_id;
            this->price = price;
            this->company_name = company_name;
        }
        void setStock(int d){
            this->stockLevel = d;
        }

        int getprice(){return this->price;}
        string getname(){return this->name;}
        int getstock(){return this->stockLevel;}

        bool operator==(Product &p){
            return (getname() == p.getname() && getprice() == p.getprice() && getstock() == p.getstock());
        }


};
//by using inheritance we can diffrentiate product into two classes
class Tech_p : public Product{

    int rating;
    int discount;

    public:

        Tech_p(int r, int dis){
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

class Non_tech_p : public Product{

    int discount;
    string manu_date;

    public:

        Non_tech_p(int dis, string ch){
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

//used this because i have to initialised the map container int the inventory
namespace std {
template<>
struct hash<Product> {
    size_t operator()(Product& p) {
        size_t h1 = hash<string>()(p.getname());     
        size_t h2 = hash<double>()(p.getprice());
        size_t h3 = hash<int>()(p.getstock());
        return h1 ^ h2 ^ h3 ;
    }
};


template<>
struct equal_to<Product> {
    bool operator()(Product& p1, Product& p2)  {
        return p1 == p2;
    }
};
}

class object{

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

class shoping_cart{

    private:
        vector<Product>store;

    public:
        void addProduct(Product ob){
            store.push_back(ob);
        }

        //remove
        void removeProduct(Product ob){

            for(auto it=store.begin(); it!=store.end(); it++){

                if(*it == ob){
                    store.erase(it);
                    break;
                }
            }
        }

        int totalCost(){

            int sum = 0;
            for(int i=0; i < store.size(); i++){//waring checkout
                sum += store[i].getprice();
            }
            return sum;
        }

        void view(){
            cout<<"Detail of the order: "<<endl;
            for(int i=0; i<store.size(); i++){
                cout<<"The name of the product: "<<store[i].getname()<<"    Price is:"<<store[i].getprice()<<endl;
            }
        }

};

class customer{

    //details of the customer
    string name;
    int customer_id;
    string address;
    string email;

    public:
        customer(string name, int customer_id, string address, string email){
            this->name = name;
            this->customer_id = customer_id;
            this->address = address;
            this->email = email;
        }

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
/*
    inventory storage;
    storage.SetStore(iphone,10);
    storage.SetStore(notebook,10);
*/
    object play;
    play.addProduct(iphone);
    play.addProduct(notebook);

    customer ashu("ashu",122,"surat","ashu.in");
    play.dispProduct();

    string s;
    shoping_cart cust;

    do {

        cin >> s;

        if(s == "exit"){
            break;
        }

        pair<Product,bool> stockP = play.compareP(s);
        
        // cust.addProduct();
        if(stockP.second){
            cust.addProduct(stockP.first);
        }
        else{
            cout<<"no such product is there"<<endl;
        }

    }while(s!="exit");

    cust.view();
    int amount = cust.totalCost();
    cout<<"The total cost is: "<<amount<<endl;

    payment pay;
    shipping ship("truck",10);

    pay.setPayment(amount+ship.getCost(),"credit_card");

    order placed(1002,"11-12-2023");

    placed.OrderPlace(ashu,cust,pay,ship);


    //********************removed inventory (for now)*********************** 

    return 0;
}