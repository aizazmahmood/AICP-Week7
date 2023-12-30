#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Charity {
private:
    string name;
    int totalDonation;

public:
    Charity(const string& charityName) : name(charityName), totalDonation(0) {}

    const string& getName() const {
        return name;
    }

    int getTotalDonation() const {
        return totalDonation;
    }

    void addDonation(int amount) {
        totalDonation += amount;
    }
};

class DonationManager {
private:
    vector<Charity> charities;
    int grandTotal;

public:
    DonationManager() : grandTotal(0) {}

    void setupCharities() {
        cin.ignore(); 
        for (int i = 0; i < 3; ++i) {
            string name;
            cout << "Enter the name of charity " << (i + 1) << ": ";
            getline(std::cin, name);
            charities.emplace_back(name);
    }
}


    void displayCharities() const {
        for (size_t i = 0; i < charities.size(); ++i) {
              cout << i + 1 << ". " << charities[i].getName() << endl;
        }
    }

    void recordDonation() {
        int choice;
        do {
             cout << "\nEnter the number (1, 2, or 3) for the chosen charity (-1 to show totals): ";
             cin >> choice;

            if (choice >= 1 && choice <= 3) {
                int billAmount;
                cout << "\nEnter the customer's shopping bill amount: ";
                cin >> billAmount;

                int donationAmount = billAmount / 100; // 1% of the shopping bill
                charities[choice - 1].addDonation(donationAmount);
                grandTotal += donationAmount;

                cout << "\nDonation of $" << donationAmount << " added to " << charities[choice - 1].getName() << endl;
            } else if (choice != -1) {
                cout << "Invalid choice. Please enter 1, 2, 3, or -1." << endl;
                cin.clear(); // Clear error flag
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        } while (choice != -1);
    }

    void showTotals() const {
         vector<Charity> sortedCharities(charities.begin(), charities.end());
         sort(sortedCharities.begin(), sortedCharities.end(),
                  [](const Charity& a, const Charity& b) {
                      return a.getTotalDonation() > b.getTotalDonation();
                  });

        cout << "\nCharity Totals:" << endl;
        for (const auto& charity : sortedCharities) {
              cout << charity.getName() << ": $" << charity.getTotalDonation() << endl;
        }

            cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << grandTotal << endl;
    }
};

int main() {
    DonationManager manager;
    manager.setupCharities();
    manager.displayCharities();
    manager.recordDonation();
    manager.showTotals();

    return 0;
}
