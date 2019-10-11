#include "pch.h"
#include "Uctenka.h"

Receipt::Receipt(int receiptNumber, double dph, double amount)
{
	Receipt::amount = amount;
	Receipt::receiptNumber = receiptNumber;
	Receipt::dph = dph;
}

void Receipt::setReceiptNumber(int a)
{
	receiptNumber = a;
}

void Receipt::setAmount(double a)
{
	amount = a;
}

void Receipt::setDph(double a)
{
	dph = a;
}

int Receipt::getReceiptNumber()
{
	return receiptNumber;
}

double Receipt::getAmount()
{
	return amount;
}

double Receipt::getDph()
{
	return dph;
}
