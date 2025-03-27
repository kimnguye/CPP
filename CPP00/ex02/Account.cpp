/*
L’ordre dans lequel les destructeurs sont appelés peut différer selon
votre compilateur/système d’exploitation. Ainsi, vos destructeurs
peuvent être appelés dans l’ordre inverse.
*/

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*constructeur*/
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts ++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
}

/*destructeur*/
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";
}

void	Account::_displayTimestamp()
{
	std::time_t now = std::time(0); 
    std::tm* localTime = std::localtime(&now);
	std::cout <<"["
	<< (localTime->tm_year + 1900)
	<< std::setfill ('0') << std::setw (2)
	<< (localTime->tm_mon + 1)  // Mois (0-indexé)
	<< std::setfill ('0') << std::setw (2)
	<< localTime->tm_mday
	<< "_"
	<< std::setfill ('0') << std::setw (2)
	<< localTime->tm_hour
	<< std::setfill ('0') << std::setw (2)
	<< localTime->tm_min
	<< std::setfill ('0') << std::setw (2)
	<< localTime->tm_sec <<"] ";
}


void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:"<< getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
	return ;
}

int		Account::getNbAccounts()
{
	return _nbAccounts;
}

int		Account::getTotalAmount()
{
	return _totalAmount;
}
int		Account::getNbDeposits()
{
	return _totalNbDeposits;
}
int		Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	return ;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << ";refused\n";
		return false;
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_totalAmount -=withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return true;
}
int		Account::checkAmount() const
{
	return _amount;
}
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return ;
}