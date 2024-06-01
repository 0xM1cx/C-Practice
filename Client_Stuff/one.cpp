/*
The program should be based on the following requirements:
1. The program must record the following details when a customer buys items:
    a. Product ID
    b. Product Description
    c. Quantity
    d. Item Price
    e. Transaction ID
    f. Transaction Date
2. Use the two classes(PRODUCT and TRANSACT) that you have defined in the last practice activity. You may modify the classes according
to the requirements of this task.
3. The program should compute for the amount of item purchased. If the total amount
is more than Php 1000.00 the customer is entitled to a 12% discount
4. The program should output the total amount of the item, the discount price, and
the amount due to the customer.
5. The program should be able to display the transaction. See sample output below.
6. There should be an option to run the program again or exit the program.
*/
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string generateRandomID(int length) {
    static const string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static default_random_engine rng(time(nullptr));
    static uniform_int_distribution<int> dist(0, charset.length() - 1);

    string randomID;
    for (int i = 0; i < length; ++i) {
        randomID += charset[dist(rng)];
    }
    return randomID;
}

string inputString() {
    string input;
    getline(cin, input);
    return input;
}

double inputNum() {
    string input;
    while (true) {
        getline(cin, input);
        try {
            for (char c : input) {
                if (!isdigit(c) && c != '.') {
                    throw invalid_argument("Invalid input. Please enter a valid number: ");
                }
            }
            double num = stod(input);
            return num;
        } catch (const invalid_argument &e) {
            cout << e.what();
        } catch (...) {
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
}

class User {
protected:
    string username;
    string password;

public:
    virtual bool login() = 0;
    virtual void menu() = 0;
};

class customer {
protected:
    string name, address;
    string contact;
    bool regular;

public:
    customer();
    void getInfo();
    bool isRegular();
    void askRegular();
};

class product {
private:
    int qty;
    string pID;
    string pDesc;
    double price;
    int reorderPoint; // added reorder point
public:
    product();
    void productIn();
    double calculateSubtotal();
    void displayProduct();
    string getProductID() { return pID; }
    int getQuantity() { return qty; }
    void setReorderPoint(int point);
    bool needsReplenishment();
};

class payment : public customer {
protected:
    bool cash;
    double frontPay, interestRate, months;

public:
    payment();
    void askType();
    void installmentPayment(double &total);
    void cashPayment(double &total, double discount, double &tDiscount);
};

class transact : private payment {
protected:
    static int transactionCount;
    string tranNo;
    string tranDate;
    vector<product> products;
    double total, discount, tDiscount;

public:
    transact();
    void startTran();
    void displayTrans();
    void saveTransaction();
    void saveCustomerInfo();
    void saveTranNo(); // save the transaction number sa separate na file for easy reading.
};

class SalesClerk : public User {
public:
    SalesClerk() {
        username = "salesclerk";
        password = "sales123";
    }

    bool login() override {
        string uname, pword;
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pword;
        cin.ignore();
        return (uname == username && pword == password);
    }

    void menu() override {
        char choice;
        do {
            cout << "\nSales Clerk Menu\n";
            cout << "1. Start Transaction\n";
            cout << "2. View Sales Transactions\n";
            cout << "3. Generate Reports\n";
            cout << "4. Nullify Transaction\n";
            cout << "5. View Inventory\n";
            cout << "6. Set Reorder Point\n";
            cout << "7. Determine Items to Replenish\n";
            cout << "8. Logout\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case '1': {
                transact transaction;
                transaction.startTran();
                break;
            }
            case '2': {
                viewTransactions();
                break;
            }
            case '3': {
                generateReports();
                break;
            }
            case '4': {
                nullifyTransaction();
                break;
            }
            case '5': {
                viewInventory();
                break;
            }
            case '6': {
                setReorderPoint();
                break;
            }
            case '7': {
                determineItemsToReplenish();
                break;
            }
            case '8':
                return;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (true);
    }

    void viewTransactions() {
        ifstream file("SalesTran.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void generateReports() {
        ifstream file("SalesTran.txt");
        ofstream custRetailFile("CustRetail.txt");
        ofstream custRegFile("CustReg.txt");
        ofstream salesIDFile("SalesID.txt");

        string line;
        double totalSales = 0;
        while (getline(file, line)) {
            if (line.find("Total Payable Amount: ") != string::npos) {
                totalSales += stod(line.substr(line.find(": ") + 2));
            } else if (line.find("Customer Type: Retail") != string::npos) {
                custRetailFile << line << endl;
            } else if (line.find("Customer Type: Regular") != string::npos) {
                custRegFile << line << endl;
            } else if (line.find("Product ID: ") != string::npos) {
                salesIDFile << line << endl;
            }
        }
        file.close();

        ofstream reportFile("SalesReport.txt");
        reportFile << "Total Sales: " << totalSales << endl;
        reportFile.close();

        custRetailFile.close();
        custRegFile.close();
        salesIDFile.close();

        cout << "Total Sales: " << totalSales << endl;
    }

    void nullifyTransaction() {
        ifstream file("SalesTran.txt");
        ofstream tempFile("temp.txt");
        string tranNo, line;
        cout << "Enter Transaction No to nullify: ";
        cin >> tranNo;
        cin.ignore();
        bool found = false;

        while (getline(file, line)) {
            if (line.find("Transaction No.: " + tranNo) == string::npos) {
                tempFile << line << endl;
            } else {
                found = true;
                for (int i = 0; i < 7; ++i) {
                    getline(file, line); // skip the next lines of the transaction
                }
            }
        }
        file.close();
        tempFile.close();
        remove("SalesTran.txt");
        rename("temp.txt", "SalesTran.txt");

        if (found) {
            cout << "Transaction " << tranNo << " nullified." << endl;
        } else {
            cout << "Transaction " << tranNo << " not found." << endl;
        }
    }

    void viewInventory() {
        ifstream file("Inventory.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void setReorderPoint() {
        ifstream file("Inventory.txt");
        ofstream tempFile("temp.txt");
        string pID, line;
        int reorderPoint;

        cout << "Enter Product ID to set reorder point: ";
        cin >> pID;
        cout << "Enter Reorder Point: ";
        cin >> reorderPoint;
        cin.ignore();

        while (getline(file, line)) {
            if (line.find("Product ID: " + pID) != string::npos) {
                tempFile << line << endl;
                getline(file, line);
                tempFile << line << endl;
                getline(file, line);
                tempFile << "Reorder Point: " << reorderPoint << endl;
                while (getline(file, line)) {
                    if (line.empty())
                        break;
                    tempFile << line << endl;
                }
            } else {
                tempFile << line << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("Inventory.txt");
        rename("temp.txt", "Inventory.txt");

        cout << "Reorder point set for Product ID " << pID << "." << endl;
    }

    void determineItemsToReplenish() {
        ifstream file("Inventory.txt");
        string line;
        cout << "Items to Replenish:\n";
        while (getline(file, line)) {
            if (line.find("Quantity: ") != string::npos) {
                int quantity = stoi(line.substr(line.find(": ") + 2));
                getline(file, line);
                int reorderPoint = stoi(line.substr(line.find(": ") + 2));
                if (quantity <= reorderPoint) {
                    cout << line << endl;
                }
            }
        }
        file.close();
    }
};

class StoreManager : public User {
public:
    StoreManager() {
        username = "manager";
        password = "manager123";
    }

    bool login() override {
        string uname, pword;
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pword;
        cin.ignore();
        return (uname == username && pword == password);
    }

    void menu() override {
        char choice;
        do {
            cout << "\nStore Manager Menu\n";
            cout << "1. View Sales Reports\n";
            cout << "2. Logout\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case '1':
                viewSalesReports();
                break;
            case '2':
                return;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (true);
    }

    void viewSalesReports() {
        ifstream file("SalesReport.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int transact::transactionCount = 0;

customer::customer() {
    name = "";
    address = "";
    contact = "";
    regular = false;
}

void customer::getInfo() {
    cout << "Enter customer name: ";
    name = inputString();
    cout << "Enter customer address: ";
    address = inputString();
    cout << "Enter customer contact: ";
    contact = inputString();
}

bool customer::isRegular() {
    return regular;
}

void customer::askRegular() {
    char ans;
    cout << "Is the customer a regular? (Y/N): ";
    cin >> ans;
    cin.ignore();
    regular = (ans == 'Y' || ans == 'y');
}

payment::payment() : customer() {
    cash = true;
    frontPay = 0.0;
    interestRate = 0.0;
    months = 0.0;
}

void payment::askType() {
    int x;
    cout << "Choose payment type (1 = Installment / 2 = Cash): ";
    while (true) {
        cin >> x;
        if (x == 1) {
            cash = false;
            break;
        } else if (x == 2) {
            break;
        } else {
            cout << "Invalid input, Please pick one (1 = Installment / 2 = Cash): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void payment::installmentPayment(double &total) {
    frontPay = 0.3 * total;
    interestRate = 0.02;
    months = 12;
    total = ((total - frontPay) + ((total - frontPay) * interestRate));
    cout << "Total payable amount: " << total << "\n";
}

void payment::cashPayment(double &total, double discount, double &tDiscount) {
    tDiscount = total * discount;
    total = total - tDiscount;
    cout << "Total payable amount: " << total << "\n";
}

void transact::saveTranNo() {
    ofstream file("TransactionNumbers.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    file << tranNo << "\n";
    file.close();
}

transact::transact() {
    ifstream file("TransactionNumbers.txt");
    int maxTranNo = 0;
    string line;
    while (getline(file, line)) {
        int currentTranNo = stoi(line);
        if (currentTranNo > maxTranNo) {
            maxTranNo = currentTranNo;
        }
    }
    file.close();
    tranNo = maxTranNo + 1;
    time_t now = time(0);
    tranDate = ctime(&now);
    total = 0.0;
    discount = 0.05;
    tDiscount = 0.0;
}

void transact::startTran() {
    askRegular();
    if (!isRegular()) {
        discount = 0.0;
    }
    getInfo();
    askType();
    char addMore = 'Y';
    while (addMore == 'Y' || addMore == 'y') {
        product p;
        p.productIn();
        products.push_back(p);
        total += p.calculateSubtotal();
        cout << "Add another product? (Y/N): ";
        cin >> addMore;
        cout << addMore << endl;
        cin.ignore();
    }

    if (cash) {
        if (total > 1000.0) {
            discount = 0.12;
        }
        cashPayment(total, discount, tDiscount);
    } else {
        installmentPayment(total);
    }

    displayTrans();
    saveTransaction();
    saveCustomerInfo();
}

void transact::displayTrans() {
    cout << "Transaction No.: " << tranNo << "\n";
    cout << "Transaction Date: " << tranDate;
    for (auto &p : products) {
        p.displayProduct();
    }
    cout << "Total Payable Amount: " << total << "\n";
}

void transact::saveTransaction() {
    saveTranNo();
    ofstream file("SalesTran.txt", ios::app);
    file << "Transaction No.: " << tranNo << "\n";
    file << "Transaction Date: " << tranDate;
    for (auto &p : products) {
        file << "Product ID: " << p.getProductID() << ", Quantity: " << p.getQuantity() << "\n";
    }
    file << "Total Payable Amount: " << total << "\n";
    file << "------------------------------------\n";
    file.close();
}

void transact::saveCustomerInfo() {
    ofstream file("CustInfo.txt", ios::app);
    file << "Customer Name: " << name << "\n";
    file << "Customer Address: " << address << "\n";
    file << "Customer Contact: " << contact << "\n";
    file << "Customer Type: " << (isRegular() ? "Regular" : "Retail") << "\n";
    file << "------------------------------------\n";
    file.close();
}

product::product() {
    qty = 0;
    price = 0.0;
    pID = generateRandomID(5);
    pDesc = "";
    reorderPoint = 0;
}

void product::productIn() {
    cout << "Enter product description: ";
    cin.ignore();
    getline(cin, pDesc);
    cout << "Enter product price: ";
    price = inputNum();
    cout << "Enter product quantity: ";
    qty = inputNum();
}

double product::calculateSubtotal() {
    return price * qty;
}

void product::displayProduct() {
    cout << "Product ID: " << pID << "\n";
    cout << "Product Description: " << pDesc << "\n";
    cout << "Product Price: " << price << "\n";
    cout << "Product Quantity: " << qty << "\n";
    cout << "Subtotal: " << calculateSubtotal() << "\n";
}

void product::setReorderPoint(int point) {
    reorderPoint = point;
}

bool product::needsReplenishment() {
    return qty <= reorderPoint;
}

int main() {
    char userType;
    User *user = nullptr;

    do {
        cout << "Select user type:\n";
        cout << "1. Sales Clerk\n";
        cout << "2. Store Manager\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> userType;
        cin.ignore();

        switch (userType) {
        case '1':
            user = new SalesClerk();
            break;
        case '2':
            user = new StoreManager();
            break;
        case '3':
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        if (user != nullptr && user->login()) {
            user->menu();
        } else {
            cout << "Login failed. Try again.\n";
        }

        delete user;
        user = nullptr;

    } while (true);

    return 0;
}