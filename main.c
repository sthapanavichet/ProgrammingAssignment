#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    struct Company company;
	initializeInfo(&company);
	FILE* fp = NULL;

	fp = fopen("Apartments.txt", "r");
	if(fp != NULL) { // checking for a valid file pointer
		for (int i = 0; i < MAX_APART; ++i) {
			fscanf(fp, "%[^\n]s", &company.apartment[i].address);
			fscanf(fp, "%d", &company.apartment[i].roomNum);
			fscanf(fp, "%d", &company.apartment[i].bathroomNum);
			fscanf(fp, "%lf", &company.apartment[i].purchasePrice);
			fscanf(fp, "%lf", &company.apartment[i].monthlyRent);
			fscanf(fp, "%lf", &company.apartment[i].condoFees);
			fscanf(fp, "%f", &company.apartment[i].timeOwned);
			strcpy(company.apartment[i].type, "Apartments");
			while (fgetc(fp) != '\n' && feof(fp) == 0); // clear file buffer
		}
	}
	else {
		printf("Error! File could not be opened");
		return -1; // error code if file pointer is invalid for first file
	}
	fclose(fp);
	
	

	//Retrieve data for townhouses
	fp = fopen("Townhouses.txt", "r");
	if(fp != NULL) {
		for (int i = 0; i < 5; ++i) { // checking for a valid file pointer
			fscanf(fp, "%[^\n]s", &company.townHouse[i].address);
			fscanf(fp, "%d", &company.townHouse[i].roomNum);
			fscanf(fp, "%d", &company.townHouse[i].bathroomNum);
			fscanf(fp, "%lf", &company.townHouse[i].purchasePrice);
			fscanf(fp, "%lf", &company.townHouse[i].monthlyRent);
			fscanf(fp, "%lf", &company.townHouse[i].monthlyUtilities);
			fscanf(fp, "%lf", &company.townHouse[i].condoFees);
			fscanf(fp, "%lf", &company.townHouse[i].monthlyPropertyTax);
			fscanf(fp, "%f", &company.townHouse[i].timeOwned);
			strcpy(company.townHouse[i].type, "Townhouses");
			while (fgetc(fp) != '\n' && feof(fp) == 0); // clear file buffer
		}
	}
	else {
		printf("Error! File could not be opened");
		return -2; // error code if file pointer is invalid for second file
	}
	fclose(fp);

	//Retrieve data for semi-detached houses
	fp = fopen("SemiDetachedHouses.txt", "r");
	if(fp != NULL) { // checking for a valid file pointer
		for (int i = 0; i < 6; ++i) {
			fscanf(fp, "%[^\n]s", &company.semiDetachedHouse[i].address);
			fscanf(fp, "%d", &company.semiDetachedHouse[i].roomNum);
			fscanf(fp, "%d", &company.semiDetachedHouse[i].bathroomNum);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].purchasePrice);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].monthlyRent);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].monthlyUtilities);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].monthlyPropertyTax);
			fscanf(fp, "%f", &company.semiDetachedHouse[i].timeOwned);
			strcpy(company.semiDetachedHouse[i].type, "Semi-detached houses");
			while (fgetc(fp) != '\n' && feof(fp) == 0); // clear file buffer
		}
	}
	else {
		printf("Error! File could not be opened");
		return -3; // error code if file pointer is invalid for 3rd file
	}
	fclose(fp);

	// calculation for all apartment's performance
    struct BasicInfo *ptr;
	ptr = company.apartment;
	for(int i = 0; i < MAX_APART; i++) {
		monthlyEarnings(ptr);
		ROI(ptr);
		currentValue(ptr);
		capitalGains(ptr);
		performanceIndex(ptr);
		printf("%lf\n", ptr->monthlyEarnings);
		ptr++;
	}

	// calculation for all townhouse's performance
	ptr = company.townHouse;
	for(int i = 0; i < MAX_TOWNHOUSE; i++) {
		monthlyEarnings(ptr);
		ROI(ptr);
		currentValue(ptr);
		capitalGains(ptr);
		performanceIndex(ptr);
		printf("%lf\n", ptr->monthlyEarnings);
		ptr++;
	}

	// calculation for all semi-detached house's performance
	ptr = company.semiDetachedHouse;
	for(int i = 0; i < MAX_SEMIDETACHED; i++) {
		monthlyEarnings(ptr);
		ROI(ptr);
		currentValue(ptr);
		capitalGains(ptr);
		performanceIndex(ptr);
		printf("%lf\n", ptr->monthlyEarnings);
		ptr++; 
	}
	
	// calculation for company's total performance
	company.totalMonthlyEarnings = totalMonthlyEarnings(company.apartment) + totalMonthlyEarnings(company.townHouse) + totalMonthlyEarnings(company.semiDetachedHouse);
	company.totalROI = totalROi(company.apartment) + totalROi(company.townHouse) + totalROi(company.semiDetachedHouse);
	company.bestPerformanceIndex = topProperty(&company);

	//output
	printf("The following are financial stats for %s, %s.\n\n", company.name, company.address);
	printf("Total Properties Owned: %d\n\n", company.propertiesOwned);
	printf("Total Monthly Earnings: %lf\n\n", company.totalMonthlyEarnings);
	printf("Total ROI (for all units): %lf\n\n\n", company.totalROI);
	displayInfo(company.apartment);
	displayInfo(company.townHouse);
	displayInfo(company.semiDetachedHouse);
	displayBestProperty(&company);

	return 0;
}

//example for functions
double totalMonthlyEarnings(struct BasicInfo* property) {
    int runningTotal = 0;
    int num = 0;
    if(strcmp(property->type, "Apartments") == 0) {
		num = MAX_APART;
	}
    if(strcmp(property->type, "Townhouses") == 0) {
		num = MAX_TOWNHOUSE;
	}
    if(strcmp(property->type, "Semi-detached houses") == 0) {
		num = MAX_SEMIDETACHED;
	}
    for(int i = 0; i < num; i++) {
        runningTotal += property->monthlyEarnings;
        property++;
    }
	return runningTotal;
}
void monthlyEarnings(struct BasicInfo* property) {
    property->monthlyEarnings = property->monthlyRent - property->condoFees;
}