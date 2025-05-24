#define NAME_LEN 21
#define ADDRESS_LEN 41
#define MODEL_LEN 21
#define BANK_NAME_LEN 21

// Enum for transaction types
enum TransactionType { CASH, LOAN, LEASE };

// Structure for cash transaction details
struct CashTransaction {
    float msrp;
    float sellingPrice;
    float salesTax;
    float licensingFee;
};

// Structure for lease transaction details
struct LeaseTransaction {
    float msrp;
    float sellingPrice;
    float downPayment;
    float securityDeposit;
    float monthlyPayment;
    int leaseTerm; // in months
};

// Structure for loan transaction details
struct LoanTransaction {
    float msrp;
    float sellingPrice;
    float salesTax;
    float licensingFee;
    float downPayment;
    int loanDuration;     // in months
    float interestRate;
    float monthlyPayment;
    char bankName[BANK_NAME_LEN];
};

// Union to store one of the transaction types
union TransactionDetails {
    struct CashTransaction cash;
    struct LoanTransaction loan;
    struct LeaseTransaction lease;
};

// Main sales record structure
struct Sale {
    char customerName[NAME_LEN];
    char customerAddress[ADDRESS_LEN];
    char model[MODEL_LEN];
    enum TransactionType type;
    union TransactionDetails details;
};
	

