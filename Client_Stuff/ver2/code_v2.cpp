#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <windows.h> // used to call the Sleep() function
using namespace std;

// functions not in classes:
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

// ##### Store manager class #####
class StoreManager : public User {
public:
    void menu() override {
        char choice;
        do {
            cout << "\nStore Manager Menu\n";
            cout << "1. View Sales Reports\n";
            cout << "2. Logout\n";

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

// ##### Sales Clerk Class #####
class SalesClerk : public User {
public:
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

    // this will read the invetory.txt file and display its current inventory
    void viewInventory() {
        ifstream file("Inventory.txt");
        if (!file.is_open()) {
            cout << "Unable to open inventory file.\n";
            return;
        }

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
        bool insideItem = false;
        while (getline(file, line)) {
            if (!insideItem && !line.empty()) {
                insideItem = true; // Start printing if not already
                cout << "Items to Replenish:\n";
                cout << "====================\n";
            }
            if (insideItem && line.substr(0, 11) == "Product ID:") {
                cout << line << endl; // Print Product ID
                for (int i = 0; i < 4; ++i) {
                    getline(file, line);  // Read the next 4 lines
                    cout << line << endl; // Print each line
                }
                insideItem = false; // Stop printing after reaching Reorder Point
                cout << "---------------------\n";
            }
            if (insideItem && line.empty()) {
                insideItem = false; // Stop printing on encountering a blank line
            }
        }
        file.close();
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
            // Look for lines starting with "Transaction No.: " followed by a space
            if (line.find("Transaction No.: ") == 0) {
                size_t startPos = line.find(": ") + 2;                         // Skip "Transaction No.: "
                size_t endPos = line.find_first_of(" \t\n", startPos);         // Find yung next whitespace
                string foundTranNo = line.substr(startPos, endPos - startPos); // Extract transaction number

                if (foundTranNo == tranNo) {
                    found = true;
                    line.replace(startPos, foundTranNo.length(), "NULLIFIED"); // replace the tranNo with the word NULLIFIEd
                }
            }
            tempFile << line << endl;
        }

        file.close();
        tempFile.close();

        // Replace SalesTran.txt with temp.txt
        remove("SalesTran.txt");
        rename("temp.txt", "SalesTran.txt");

        if (found) {
            cout << "Transaction " << tranNo << " nullified." << endl;
        } else {
            cout << "Transaction " << tranNo << " not found." << endl;
        }
    }
};

double inputNum() {
    string input;
    while (true) {
        getline(cin, input);
        try {
            if (input.find_first_not_of("0123456789") != string::npos) {
                throw invalid_argument("Invalid input. Please enter a valid number: ");
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

// ##### Customer Class #####
class customer {
protected:
    string name, address;
    int contact;
    bool regular;

public:
    customer();
    void getInfo();
    bool isRegular();
    void askRegular();
};

// ##### Product Class #####
class product {
private:
    int qty;
    string pID = generateRandomID(5);
    string pDesc;
    double price;

public:
    product();
    void productIn();
    double calculateSubtotal();
    void displayProduct();
};

// ##### Payment Class #####
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
};

customer::customer() {
    regular = true;
    cout << "-------------- CUSTOMER DETAILS --------------\n";
}

bool customer::isRegular() {
    return regular;
}

void customer::askRegular() {
    int x;
    cout << "Choose Customer Type (1 = Regular / 2 = Retail): ";
    while (true) {
        cin >> x;
        if (x == 1) {
            break;
        } else if (x == 2) {
            regular = false;
            break;
        } else {
            cout << "Invalid input, Please pick one (1 = Regular / 2 = Retail): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void customer::getInfo() {
    cout << "Name: ";
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    cout << "Contact No: ";
    contact = inputNum();
}

payment::payment() {
    cash = true;
}

void payment::askType() {
    int x;
    cout << "What Payment Type? (1 = Cash / 2 = Installment): ";
    while (true) {
        cin >> x;
        if (x == 1) {
            break;
        } else if (x == 2) {
            cash = false;
            break;
        } else {
            cout << "Invalid input, Please pick one (1 = Cash / 2 = Installment): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void payment::installmentPayment(double &total) {
    double temp = 0;
    if (isRegular()) {
        frontPay = 0.25;
        interestRate = 0.0;
    } else {
        frontPay = 0.30;
        interestRate = 0.025;
        total += total * interestRate; // code I added, hindi na 2.5% per month, just a incrase in 2.5%
    }

    double monthlyPayment = 0;
    double initialPayment = total * frontPay;
    double remainingBalance = total - initialPayment;

    cout << "\n---------------------------------------------\n";
    cout << "You have an interest of " << interestRate * 100 << "% & " << frontPay * 100 << "% for your initial payment to be settled\n";
    cout << "Choose the number of installments (3, 6, or 9 months): ";
    cin >> months;
    while (months != 3 && months != 6 && months != 9) {
        cout << "Invalid input. Only option are 3 | 6 | 9. Try again:";
        cin >> months;
    }
    cout << "\n\nInitial payment of " << initialPayment << " must first be settled.\n";
    temp += initialPayment;
    double monthly = remainingBalance / months;
    for (int i = 0; i < months; i++) {
        // double interest = remainingBalance * interestRate; # commented out since hindi 2.5% per month an interest rate
        monthlyPayment = monthly;
        remainingBalance -= monthly;
        temp += monthlyPayment;
        cout << "Month " << i + 1 << ": " << monthlyPayment << endl;
    }
    cout << "\n\nOriginal amount: " << total;
    cout << "\nInterest: " << temp - total;
    total = temp;
}

void payment::cashPayment(double &total, double discount, double &tDiscount) {
    if (isRegular()) {
        discount = total * 0.05;
        total -= discount;
        tDiscount += discount;
        cout << "Cash Purchase is made by a Regular Customer 5% discount " << discount << " applied.\n";
    }
}

product::product() {
    cout << "\n-------------- PRODUCT DETAILS --------------\n";
}

double product::calculateSubtotal() {
    return qty * price;
}

void product::displayProduct() {
    cout << "Product ID: " << pID << endl;
    cout << "Description: " << pDesc << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity: " << qty << endl;
}

void product::productIn() {
    cout << "\nProduct ID: " << pID;
    cout << "\nProduct description: ";
    getline(cin, pDesc);
    cout << "Price: ";
    price = inputNum();
    cout << "\nQuantity: ";
    qty = inputNum();
    cout << "\n---------------------------------------------\n";
}

transact::transact() {
    transactionCount++;
    tranNo = "T" + to_string(transactionCount);
    tDiscount = 0;
    discount = 0;
}

void transact::startTran() {
    getInfo();
    askRegular();
    askType();
    cout << "Transaction date (mm-dd-yy): ";
    cin.ignore();
    getline(cin, tranDate);

    char addP;
    do {
        product product;
        product.productIn();
        products.push_back(product);
        cout << "Add more product? (Y/N): ";
        cin >> addP;
        cin.ignore();
    } while (addP == 'Y' || addP == 'y');

    displayTrans();
}

void transact::displayTrans() {
    system("cls");
    cout << "\n---------------===== Summary of Order =====---------------\n";
    cout << "Transaction No.: " << tranNo;
    cout << "\nName: " << name;
    cout << "\nAddress: " << address;
    cout << "\nContact Number: " << contact;
    cout << "\nCustomer Type: ";
    if (regular) {
        cout << "Regular";
    } else {
        cout << "Retail";
    }
    cout << "\nPayment Type: ";
    if (cash) {
        cout << "Cash";
    } else {
        cout << "Installment";
    }
    cout << "\n---------------------------------------------\n";

    double totalBeforeDiscount = 0;
    for (auto &product : products) {
        product.displayProduct();
        double subtotal = product.calculateSubtotal();
        cout << "Subtotal: " << subtotal << endl;
        totalBeforeDiscount += subtotal;
        cout << "---------------------------------------------\n";
    }

    cout << "Total amount purchased before discount: " << totalBeforeDiscount << endl;
    cout << "---------------------------------------------\n";

    if (totalBeforeDiscount > 1000.0) {
        discount = totalBeforeDiscount * 0.12;
        totalBeforeDiscount -= discount;
        tDiscount += discount;
        cout << "\nPurchase exceeds 1,000 applying 12% discount of " << discount << "\n";
    }

    if (cash && isRegular()) {
        cashPayment(totalBeforeDiscount, discount, tDiscount);
    } else if (!cash) {
        installmentPayment(totalBeforeDiscount);
    }

    cout << "\n---------------------------------------------\n";
    cout << "\nTotal Discount applied: " << tDiscount;
    cout << "\n\nTotal Payable Amount: " << totalBeforeDiscount;
}

class User {
public:
    virtual void menu();
};

int main() {
    double amountDue;
    char t;
    User *user;
    string users[] = {"manager", "salesclerk"};
    string passwords[] = {"manager123", "sales123"};
    string userName;
    string password;

    cout << "----------===== Login =====----------\n\n";
    cout << "Username: ";
    cin >> userName;

    if (userName == users[0]) {
        cout << "Password: ";
        cin >> password;
        if (password == passwords[0]) {
            user = new StoreManager();
            user->menu();
        } else {
            cout << "Wrong password\n\n";
            Sleep(3000);
            system("cls");
            main();
        }
    } else if (userName == users[1]) {
        cout << "Password: ";
        cin >> password;
        if (password == passwords[1]) {
            user = new SalesClerk();
            user->menu();
        } else {
            cout << "Wrong password\n\n";
            Sleep(3000);
            system("cls");
            main();
        }
    } else {
        cout << "User not found";
        Sleep(3000);
        system("cls");
        main();
    }

    while (true) {

        cout << "----------===== Point of Sales v2 =====----------\n\n";
        transact transact;
        transact.startTran();

        cout << "\n\nAnother Transaction? (Y / N): ";
        cin >> t;
        if (t == 'N' || t == 'n') {
            cout << "Thank you for using the code!";
            return 0;
        }
        cin.ignore();
        system("cls");
    }
    return 0;
}