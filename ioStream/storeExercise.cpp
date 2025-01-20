#include<fstream>
#include<cstring>
#include <iostream>
using namespace std;

class Shop{
      
    public:

        string name;
        int price;
        int quantity;


        Shop(string n, int p, int q){
            name = n;
            price = p;
            quantity = q;
        }

        friend ofstream & operator<<(ofstream &ofs, Shop &s);

        friend ifstream & operator>>(ifstream &ifs, Shop &s);
};

ofstream & operator<<(ofstream &ofs, Shop &s){
    ofs<<s.name<<endl;
    ofs<<s.price<<endl;
    ofs<<s.quantity<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Shop &s){
    ifs>>s.name>>s.price>>s.quantity;
    return ifs;
}

int main()
{
    int p, q;
    string n;

    cout<<"Enter name of product:"<<endl;
    getline(cin, n);

    cout<<"Enter price of product:"<<endl;
    cin>>p;

    cout<<"Enter quantity of product:"<<endl;
    cin>>q;

    Shop s1(n, p, q);

    //writing content into file
    ofstream ofs("shop.text",ios::trunc);
    ofs<<s1;
    //closing file
    ofs.close();

    //reading content from file
    ifstream ifs;
    ifs.open("shop.text");

    //checking if file opened
    if(ifs.is_open()){
        cout<<"File opened successfully"<<endl;
        
        ifs>>s1;
        cout<<"The contents of files are:"<<endl;
        cout<<"Product: "<<s1.name<<endl<<"Price: "<<s1.price<<endl<<"Quantity: "<<s1.quantity<<endl;

    }
    else{
        cout<<"File not found. ERROR!!"<<endl;
    }


    //closing file after reading content
    ifs.close();

    return 0;
}