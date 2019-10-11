#ifndef POKLADNA_H
#define POKLADNA_H

#include "Uctenka.h"

#define COUNTER_ID_INIT 1000
#define CONTER_RECEPIET 10

class CashRegister {
public:
	CashRegister();

	Receipt& createReceipt(double amount, double dph);
	void printReceipt(int x);

	Receipt& giveReceipt(int x);
	double getAmount() const;
	double getAmountWDph() const;

private:
	int  counterID;
	Receipt *arrayOfReceipts;
	int counterOFReceipts = 0;



};

#endif // !POKLADNA_H
