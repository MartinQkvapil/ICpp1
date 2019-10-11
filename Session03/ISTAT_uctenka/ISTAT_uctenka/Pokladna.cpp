#include "pch.h"
#include "Pokladna.h"
#include <iostream>
#include <exception>

CashRegister::CashRegister()
{
	counterID = COUNTER_ID_INIT;	
	arrayOfReceipts = new Receipt[CONTER_RECEPIET];
}

Receipt& CashRegister::createReceipt(double castka, double dph)
{
	if (counterOFReceipts >= 10) {
		throw std::overflow_error("CashRegister is full");
	}

	arrayOfReceipts[counterOFReceipts].setReceiptNumber(counterID++);
	arrayOfReceipts[counterOFReceipts].setAmount(castka);
	arrayOfReceipts[counterOFReceipts].setDph(dph);
	counterOFReceipts++;
	
	return arrayOfReceipts[counterOFReceipts - 1];
}

void CashRegister::printReceipt(int x)
{
	std::cout << "ID: " << arrayOfReceipts[x].getReceiptNumber()
		<< ", Castka: " << arrayOfReceipts[x].getAmount()
		<< ", DPH: " << arrayOfReceipts[x].getDph() << std::endl;
}

Receipt& CashRegister::giveReceipt(int x){
	for (size_t i = 0; i < counterOFReceipts; i++)
	{
		int tmp = arrayOfReceipts[i].getReceiptNumber();
		if (tmp == x) {
			return arrayOfReceipts[i];
		}
		else {
			return arrayOfReceipts[0];
		}
	}
	throw std::out_of_range("CashRegister is full");
}

double CashRegister::getAmount() const
{
	double sum = 0.0;
	for (size_t i = 0; i < sizeof(CashRegister::arrayOfReceipts) / sizeof(CashRegister::arrayOfReceipts[0]); i++)
	{
		if (arrayOfReceipts[i].getAmount() != 0) {
			sum += arrayOfReceipts[i].getAmount();
		}
		
	}
	return sum;
	
}

double CashRegister::getAmountWDph() const
{
	double sum = 0.0;
	for (size_t i = 0; i < sizeof(CashRegister::arrayOfReceipts) / sizeof(CashRegister::arrayOfReceipts[0]); i++)
	{
		if (arrayOfReceipts[i].getAmount() != 0) {
			sum += arrayOfReceipts[i].getAmount() * (1+ arrayOfReceipts[i].getDph());
		}

	}
	return sum;
	
}
