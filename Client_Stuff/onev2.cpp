#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to generate random ID
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

// Function to input string
string inputString() {
    string input;
    getline(cin, input);
    return input;
}

// Function to input number
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

// Abstract class for user
class User {
protected:
    string username;
    string password;

public:
    virtual bool login() = 0;
    virtual void menu() = 0;
};

// Class for customer
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

// Class for product
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

// Class for payment
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

// Class for transaction
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
    string generateUniqueTranNo(int desiredLength); // save the transaction number sa separate na file for easy reading.
};

// Class for Sales Clerk
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
        cin.ignore(); // Consume newline character

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

// Class for Store Manager
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
            cout << "1. View Sales Transactions\n";
            cout << "2. View Reports\n";
            cout << "3. Logout\n";
            cout << "Choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case '1':
                viewSalesTransactions();
                break;
            case '2':
                viewReports();
                break;
            case '3':
                return;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (true);
    }

    void viewSalesTransactions() {
        ifstream file("SalesTran.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void viewReports() {
        ifstream file;
        string line;

        cout << "\nRetail Customers Information:\n";
        file.open("CustRetail.txt");
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();

        cout << "\nRegular Customers Information:\n";
        file.open("CustReg.txt");
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();

        cout << "\nSales Transactions per Product ID:\n";
        file.open("SalesID.txt");
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();

        cout << "\nTotal Sales:\n";
        file.open("SalesReport.txt");
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

// Function to display login menu
void displayLoginMenu() {
    User *user = nullptr;
    char choice;

    do {
        cout << "Login Menu\n";
        cout << "1. Sales Clerk\n";
        cout << "2. Store Manager\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            user = new SalesClerk();
            break;
        case '2':
            user = new StoreManager();
            break;
        case '3':
            return;
        default:
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        if (user && user->login()) {
            user->menu();
        } else {
            cout << "Invalid credentials. Try again.\n";
        }

        delete user;
        user = nullptr;

    } while (true);
}

// Implementations of customer methods
customer::customer() : regular(false) {}

void customer::getInfo() {
    cout << "Enter customer name: ";
    name = inputString();
    cout << "Enter customer address: ";
    address = inputString();
    cout << "Enter customer contact: ";
    contact = inputString();
}

bool customer::isRegular() { return regular; }

void customer::askRegular() {
    char choice;
    cout << "Is the customer a regular customer? (y/n): ";
    cin >> choice;
    regular = (choice == 'y' || choice == 'Y');
}

// Implementations of product methods
product::product() : qty(0), price(0.0), reorderPoint(0) {}

void product::productIn() {
    cout << "Enter product ID: ";
    pID = inputString();
    cout << "Enter product description: ";
    pDesc = inputString();
    cout << "Enter product price: ";
    price = inputNum();
    cout << "Enter product quantity: ";
    qty = inputNum();
}

double product::calculateSubtotal() { return price * qty; }

void product::displayProduct() {
    cout << "Product ID: " << pID << "\n";
    cout << "Product Description: " << pDesc << "\n";
    cout << "Product Price: " << price << "\n";
    cout << "Product Quantity: " << qty << "\n";
}

void product::setReorderPoint(int point) { reorderPoint = point; }

bool product::needsReplenishment() { return qty <= reorderPoint; }

// Implementations of payment methods
payment::payment() : cash(false), frontPay(0.0), interestRate(0.0), months(0) {}

void payment::askType() {
    char choice;
    cout << "Is the payment mode cash? (y/n): ";
    cin >> choice;
    cash = (choice == 'y' || choice == 'Y');
}

void payment::installmentPayment(double &total) {
    if (isRegular()) {
        frontPay = total * 0.25;
        cout << "Choose terms of payment: 3, 6, or 9 months: ";
        months = inputNum();
    } else {
        frontPay = total * 0.30;
        interestRate = 0.025;
        cout << "Choose terms of payment: 3, 6, or 9 months: ";
        months = inputNum();
        total += total * interestRate * months;
    }
}

void payment::cashPayment(double &total, double discount, double &tDiscount) {
    tDiscount = total * discount;
    total -= tDiscount;
}

// Implementations of transact methods
int transact::transactionCount = 0;

transact::transact() : total(0.0), discount(0.0), tDiscount(0.0) {}

void transact::startTran() {
    transactionCount++;
    tranNo = generateUniqueTranNo(8);
    time_t now = time(0);
    char *dt = ctime(&now);
    tranDate = string(dt);

    int itemCount;
    cout << "Enter number of items: ";
    itemCount = inputNum();

    for (int i = 0; i < itemCount; ++i) {
        product p;
        p.productIn();
        products.push_back(p);
        total += p.calculateSubtotal();
    }

    getInfo();
    askRegular();
    if (isRegular()) {
        askType();
        if (cash) {
            discount = 0.05;
            cashPayment(total, discount, tDiscount);
        } else {
            installmentPayment(total);
        }
    } else {
        installmentPayment(total);
    }

    displayTrans();
    saveTransaction();
    saveCustomerInfo();
}

void transact::displayTrans() {
    cout << "\nTransaction No.: " << tranNo << "\n";
    cout << "Transaction Date: " << tranDate << "\n";
    for (const auto &p : products) {
        p.displayProduct();
        cout << "Subtotal: " << p.calculateSubtotal() << "\n";
    }
    cout << "Total Purchase Price: " << total << "\n";
    if (cash) {
        cout << "Discount: " << tDiscount << "\n";
        cout << "Total Payable Amount: " << total << "\n";
    } else {
        cout << "Front Payment: " << frontPay << "\n";
        cout << "Monthly Payment for " << months << " months: " << (total - frontPay) / months << "\n";
        cout << "Total Payable Amount: " << total << "\n";
    }
}

void transact::saveTransaction() {
    ofstream file("SalesTran.txt", ios::app);
    file << "Transaction No.: " << tranNo << "\n";
    file << "Transaction Date: " << tranDate << "\n";
    for (const auto &p : products) {
        file << "Product ID: " << p.getProductID() << "\n";
        file << "Subtotal: " << p.calculateSubtotal() << "\n";
    }
    file << "Total Purchase Price: " << total << "\n";
    if (cash) {
        file << "Discount: " << tDiscount << "\n";
        file << "Total Payable Amount: " << total << "\n";
    } else {
        file << "Front Payment: " << frontPay << "\n";
        file << "Monthly Payment for " << months << " months: " << (total - frontPay) / months << "\n";
        file << "Total Payable Amount: " << total << "\n";
    }
    file << "Customer Type: " << (isRegular() ? "Regular" : "Retail") << "\n\n";
    file.close();
}

void transact::saveCustomerInfo() {
    ofstream file("CustInfo.txt", ios::app);
    file << "Customer Name: " << name << "\n";
    file << "Customer Address: " << address << "\n";
    file << "Customer Contact: " << contact << "\n";
    file << "Customer Type: " << (isRegular() ? "Regular" : "Retail") << "\n";
    file << "Transaction No.: " << tranNo << "\n\n";
    file.close();
}

string transact::generateUniqueTranNo(int desiredLength) {
    string uniqueTranNo;
    do {
        uniqueTranNo = generateRandomID(desiredLength);
    } while (uniqueTranNo.empty());
    return uniqueTranNo;
}

// Main function
int main() {
    displayLoginMenu();
    return 0;
}
