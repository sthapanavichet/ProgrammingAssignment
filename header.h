#define MAX_STR 64
#define MAX_APART 2
#define MAX_TOWNHOUSE 5
#define MAX_SEMIDETACHED 6

struct BasicInfo {
    char address[MAX_STR];
    int roomNum; //number of rooms
    int bathroomNum; //number of rooms
    double monthlyRent; //dollars $
    double purchasePrice; //dollars $
    double condoFees; //dollars $
    double monthlyPropertyTax; //dollars $
    double monthlyUtilities; //dollars $
    float timeOwned; //years
    double currentValue; // dollars $
    double monthlyEarnings; // dollars $
    double ROI; // percentage % 
    double capitalGains; // dollars 
    double gainRate; //dollars per year $/year
    char type[MAX_STR]; //type of property
    double performanceIndex; //ROI x capital gains rate
};
struct Company {
    char name[MAX_STR];
    char address[MAX_STR];
    int propertiesOwned;
    double totalMonthlyEarnings;
    double averageMonthlyEarnings;
    double totalROI;
    int bestPerformanceIndex;
    struct BasicInfo apartment[MAX_APART];
    struct BasicInfo townHouse[MAX_TOWNHOUSE];
    struct BasicInfo semiDetachedHouse[MAX_SEMIDETACHED];
};

void initializeInfo(struct Company *property);
void monthlyEarnings(struct BasicInfo *property); // aditti
double totalMonthlyEarnings(struct BasicInfo *property); // aditti 
void averageMonthlyEarnings(struct BasicInfo *property); // has
void ROI(struct BasicInfo *property); // sarah
double totalROI(struct BasicInfo *property); // sarah
void currentValue(struct BasicInfo *property); // defne
void totalValue(struct BasicInfo *property); // defne
void capitalGains(struct BasicInfo *property); // has
void averageGainsRate(struct BasicInfo *property); // has
void performanceIndex(struct BasicInfo *property);
int topProperty(struct Company *property);
void displayinfo(sturct Company *property);
