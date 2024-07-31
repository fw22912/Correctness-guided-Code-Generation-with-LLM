struct Account {
    unsigned short bal;
};


void withdraw(struct Account *account, unsigned short amount) {
    unsigned short de = account->bal;
    account->bal = de - amount;
}
