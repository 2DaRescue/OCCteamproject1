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
#ifndef DONORLIST_H
#define DONORLIST_H

#include "Database.h"
#include "DonorType.h"

#include <string>

class Node 
{
public:
    Node() : next(nullptr) {}
    Node(const std::string firstName, const std::string lastName,
        int membershipNo, double donationAmount, Node* newNext)
        { donor.setDonorInfo(firstName, lastName, membershipNo, donationAmount);
        next = newNext; }
        //: donor(firstName, lastName, membershipNo, donationAmount), 
        //next(newNext) {}
    Node* getNext() const { return next; }
    DonorType& getDonor() { return donor; }
    void setDonorInfo(const std::string firstName, const std::string lastName,
        int membershipNo, double donationAmount)
        { donor.setDonorInfo(firstName, lastName, membershipNo, donationAmount); }
    void setNext(Node* newNext) { next = newNext; }
    ~Node() {}

private:
    DonorType donor;
    Node* next;
};

class DonorList 
{
public:
    DonorList() : first(nullptr), last(nullptr), count(0) {}
    void addDonor(const std::string firstName, const std::string lastName,
        int membershipNo, double donationAmount);
    void createList();
    int getNoOfDonors() const;
    double getTotalDonations() const;
    bool isEmpty() const;
    bool searchID(int keyID) const;
    void deleteDonor(int keyID);
    void printAllDonors() const;
    void printAllDonations() const;
    void clearList();
    ~DonorList();

private:
    Node* first;
    Node* last;
    int count;
};

#endif