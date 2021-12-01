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
#include "DonorList.h"
#include <iostream>

using namespace std;

void DonorList::addDonor(const std::string firstName, 
    const std::string lastName, int membershipNo, double donationAmount)
{
    if (first == nullptr)
    {
        first = new Node(firstName, lastName, membershipNo, 
            donationAmount, nullptr);
        last = first;
    }
    else
    {
        last->setNext(new Node(firstName, lastName, membershipNo, 
            donationAmount, nullptr));
        last = last->getNext();
    }
    count++;
}

void DonorList::createList()
{
    set<DonorType> donorSet = getData();
    if (donorSet.empty())
    {
        cerr << "Database has no data." << endl;
    }
    else
    {
        for (const DonorType& donor : donorSet)
        {
            addDonor(donor.getFirstName(), donor.getLastName(),
                donor.getMembershipNo(), donor.getAmountDonated());
        }
    }
}

int DonorList::getNoOfDonors() const
{
    return count;
}

double DonorList::getTotalDonations() const
{
    double totalDonations = 0;
    Node* current = first;
    for(int i = 0; i < count; ++i)
    {
        totalDonations += current->getDonor().getAmountDonated();
        current = current->getNext();
    }
    return totalDonations;
}

bool DonorList::isEmpty() const
{
    return (count == 0);
}

bool DonorList::searchID(int keyID) const
{
    Node* current = first;
    while (current != nullptr)
    {
        if ((current->getDonor().getMembershipNo()) == keyID)
        {
            return true;
        }
        else
        {
            current = current->getNext();
        }
    }
    return false;
}

void DonorList::deleteDonor(int keyID)
{
    if (first->getDonor().getMembershipNo() == keyID)
    {
        if (first == last)
        {
            delete first;
            first = nullptr;
        }
        else
        {
            Node* current = first;
            first = first->getNext();
            delete current;
            current = nullptr;
        }
        count--;
    }
    else
    {
        Node* current = first->getNext();
        Node* trailCurrent = first;
        bool found = false;
        while (current != nullptr && !found)
        {
            if ((current->getDonor().getMembershipNo()) == keyID)
            {
                if (current == last)
                {
                    last = trailCurrent;
                }
                trailCurrent->setNext(current->getNext());
                delete current;
                current = nullptr;
                found = true;
                count--;
            }
            else
            {
                trailCurrent = current;
                current = current->getNext();
            }
        }
        if (!found)
        {
            cout << "Donor is not in the list." << endl;
        }
    }
}

void DonorList::printAllDonors() const
{
    Node* current = first;
    for (int i = 0; i < count; ++i)
    {
        current->getDonor().printMemberInfo();
        current = current->getNext();
    }
}

void DonorList::printAllDonations() const
{
    Node* current = first;
    for (int i = 0; i < count; ++i)
    {
        current->getDonor().printDonation();
        current = current->getNext();
    }
}

void DonorList::clearList()
{
    Node* current = first;
    while(first != nullptr)
    {
        first = current->getNext();
        delete current;
        current = first;
    }
    last = nullptr;
    count = 0;
}

DonorList::~DonorList()
{
    clearList();
}
