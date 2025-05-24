// Structure to represent a phone number
struct PhoneNumber {
    int areaCode;       // e.g., 212
    int exchange;       // e.g., 555
    int stationNumber;  // e.g., 1234
};

// Structure to represent the date and time of the call
struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Structure to represent the billing information
struct BillingInfo {
    struct DateTime callTime;             // Date and time of the call
    struct PhoneNumber numberCalled;      // Number that was called
    struct PhoneNumber numberCallingFrom; // Originating number
    struct PhoneNumber numberBilled;      // Number to be billed
};


