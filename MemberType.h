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
#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <string>

class MemberType 
{
public:
    MemberType() : firstName("N/A"), lastName("N/A"), 
        membershipNo(0) {}
    MemberType(const std::string& newFirst, 
        const std::string& newLast, int newMemNo);
    void setMemberInfo(const std::string& newFirst, 
        const std::string& newLast, int newMemNo);
    std::string getFirstName() const;
    std::string getLastName() const;
    int getMembershipNo() const;
    void printName() const;
    void printMemberInfo() const;
    ~MemberType() {}
    
private:
    std::string firstName;
    std::string lastName;
    int membershipNo;
};

#endif