#ifndef UCTENKA_H
#define UCTENKA_H

class Receipt {
private:
	int receiptNumber;
	double amount;
	double dph;
public:
	Receipt() {};
	Receipt(int receiptNumber, double dph, double amount);

	//Setters 
	void setReceiptNumber(int a);
	void setAmount(double a);
	void setDph(double a);
	// Getters
	int getReceiptNumber();
	double getAmount();
	double getDph();

};


#endif UCTENKA_H