/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani <ggargani@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:12:21 by ggargani          #+#    #+#             */
/*   Updated: 2025/07/31 12:32:02 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Account.hpp"
#include<iostream>
#include<ctime>
#include <iomanip>
#include <chrono> 

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << checkAmount() 
			  << ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << checkAmount() 
			  << ";closed" << std::endl;
	
}

int	Account::getNbAccounts( void )
{
	return 	_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp( void )
{
    std::time_t timeStamp = 
	std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    struct std::tm* ptm = std::localtime(&timeStamp);
    
    std::cout << "[" << std::put_time(ptm, "%c") << "] ";
}

void	Account::displayAccountsInfos( void )
{
				_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:"  << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  <<";withdrawals:" << getNbWithdrawals()
			  << std::endl;	
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
	<< ";deposit:" << deposit << ";amount:" << _amount + deposit
	<< ";nb_deposits:" << _nbDeposits << std::endl;
	
	_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount +=deposit;
	
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
				  << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused"  << std::endl;;
		return false;
	}
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	
	std::cout << withdrawal << ";amount:" 
	<< checkAmount() - withdrawal 
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	
	_amount -= withdrawal;
	Account::_totalAmount -=withdrawal;
	
	return true;	
}

int		Account::checkAmount( void ) const{

	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals 
			  << std::endl;	
}