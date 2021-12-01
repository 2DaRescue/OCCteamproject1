/*
    CodingRivals
    
    Souza, Hugo D
    Arvizu, Israel
    Luna, Francisco
    Sanchez, David
    Trinh, Thuc
    
    November 27th, 2021
    
    CS A250
    Project 1 
*/
#include "MemberType.h"

#include <iostream>
using namespace std;

MemberType::MemberType(const std::string& newFirst, 
    const std::string& newLast, int newMemNo)
{
    firstName = newFirst;
    lastName = newLast;
    membershipNo = newMemNo;
}

void MemberType::setMemberInfo(const std::string& newFirst, 
    const std::string& newLast, int newMemNo)
{
    firstName = newFirst;
    lastName = newLast;
    membershipNo = newMemNo;
}

string MemberType::getFirstName() const
{
    return firstName;
}

string MemberType::getLastName() const
{
    return lastName;
}

int MemberType::getMembershipNo() const
{
    return membershipNo;
}

void MemberType::printName() const
{
    cout << lastName << ", " << firstName << endl;
}

void MemberType::printMemberInfo() const
{
    cout << membershipNo << " - " << firstName 
    << " "<< lastName << endl;
}
