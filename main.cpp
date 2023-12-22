#include <iostream>
#include <vector>
#include <string>

class BankAccount {
public:
    BankAccount(const std::string& owner, double balance = 0.0) : owner(owner), balance(balance) {}

    const std::string& getOwner() const {
        return owner;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << amount << " TL yatırıldı. Yeni bakiye: " << balance << " TL" << std::endl;
        }
        else {
            std::cout << "Geçersiz miktar. Lütfen pozitif bir miktar girin." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                std::cout << amount << " TL çekildi. Yeni bakiye: " << balance << " TL" << std::endl;
            }
            else {
                std::cout << "Yetersiz bakiye. Çekim işlemi gerçekleştirilemedi." << std::endl;
            }
        }
        else {
            std::cout << "Geçersiz miktar. Lütfen pozitif bir miktar girin." << std::endl;
        }
    }

private:
    std::string owner;
    double balance;
};

class Bank {
public:
    void createAccount(const std::string& owner) {
        BankAccount account(owner);
        accounts.push_back(account);
        std::cout << "Yeni hesap oluşturuldu. Hesap sahibi: " << owner << std::endl;
    }

    void displayAccounts() const {
        std::cout << "Banka Hesapları:" << std::endl;
        for (const auto& account : accounts) {
            std::cout << "Hesap Sahibi: " << account.getOwner() << " - Bakiye: " << account.getBalance() << " TL" << std::endl;
        }
    }

    BankAccount* findAccount(const std::string& owner) {
        for (auto& account : accounts) {
            if (account.getOwner() == owner) {
                return &account;
            }
        }
        return nullptr;
    }

private:
    std::vector<BankAccount> accounts;
};

int main() {
    setlocale(LC_ALL, "Turkish");
    Bank bank;

    bank.createAccount("Ahmet");
    bank.createAccount("Ayşe");

    bank.displayAccounts();

    BankAccount* ahmetAccount = bank.findAccount("Ahmet");
    if (ahmetAccount) {
        ahmetAccount->deposit(1000.0);
        ahmetAccount->withdraw(500.0);
    }

    bank.displayAccounts();

    return 0;
}
