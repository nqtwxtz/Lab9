#include<iostream>
#include<iomanip> 
using namespace std;

int main() {
    double loan, rate, payPerYear;

    cout << "Enter initial loan: ";
    cin >> loan;
    cout << "Enter interest rate per year (%): ";
    cin >> rate;
    cout << "Enter amount you can pay per year: ";
    cin >> payPerYear;

    cout << setw(13) << left << "EndOfYear#"; 
    cout << setw(13) << left << "PrevBalance"; 
    cout << setw(13) << left << "Interest"; 
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";
    
    int year = 1;
    double prevBalance = loan;
    
    cout << fixed << setprecision(2); 

    while (prevBalance > 0) {
        double interest = prevBalance * (rate / 100.0);
        double total = prevBalance + interest;
        double payment;

        if (total < payPerYear) {
            payment = total;
        } else {
            payment = payPerYear;
        }

        double newBalance = total - payment;

        cout << setw(13) << left << year; 
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        
        if (newBalance < 0.01) cout << setw(13) << left << 0.00;
        else cout << setw(13) << left << newBalance;
        
        cout << "\n";

        prevBalance = newBalance;
        year++;
        
        if (interest >= payPerYear && prevBalance > 0) break;
    }
    
    return 0;
}