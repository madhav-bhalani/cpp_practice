#include <vector>
#include <fstream>
#include <iostream>
#include <limits> // Required for numeric_limits
using namespace std;

class Item {
public:
    string name;
    int price;
    int quantity;

    Item() {}
    Item(string n, int p, int q);

    friend ofstream &operator<<(ofstream &ofs, Item &i);
    friend ifstream &operator>>(ifstream &ifs, Item &i);
    friend ostream &operator<<(ostream &os, Item &i);
};

Item::Item(string n, int p, int q) {
    name = n;
    price = p;
    quantity = q;
}

ofstream &operator<<(ofstream &ofs, Item &i) {
    ofs << i.name << endl;
    ofs << i.price << endl;
    ofs << i.quantity << endl;
    return ofs;
}

ifstream &operator>>(ifstream &ifs, Item &i) {
    getline(ifs, i.name); // Read full name
    ifs >> i.price >> i.quantity;
    ifs.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline
    return ifs;
}

ostream &operator<<(ostream &os, Item &i) {
    os << "Name: " << i.name << endl
       << "Price: " << i.price << endl
       << "Quantity: " << i.quantity << endl;
    return os;
}

int main() {
    int num, p, q;
    string n;
    vector<Item *> list;

    cout << "Enter number of items:" << endl;
    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter all items: " << endl;
    for (int i = 0; i < num; i++) {
        cout << "Enter " << i + 1 << " item name, price, and quantity:" << endl;
        getline(cin, n); // Read name
        cin >> p >> q;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        list.push_back(new Item(n, p, q));
    }

    // Writing into file
    ofstream ofs("item.txt", ios::trunc);
    for (auto itr = list.begin(); itr != list.end(); itr++) {
        ofs << **itr;
    }
    ofs.close();

    // Reading from file
    ifstream ifs("item.txt");
    Item item;

    cout << "\nItems from file:\n";
    for (int i = 0; i < num; i++) {
        ifs >> item;
        cout << "Item " << i + 1 << ":\n" << item << endl;
    }
    ifs.close();

    // Cleanup memory
    for (auto i : list) {
        delete i;
    }

    return 0;
}
