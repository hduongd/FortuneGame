#pragma once

#include <Tile.h>

#include <string>

const int RENT_SLOTS = 7;

class Property : public Tile
{
public:
    enum rent {RENT_SINGLE, RENT_MONOPOLY, ONE_HOUSE, TWO_HOUSE, THREE_HOUSE, FOUR_HOUSE, HOTEL};
    friend std::ostream& operator<<(std::ostream& os, Property& prop);

    Property(const std::string& name, unsigned action, unsigned cost,
             unsigned* rents, unsigned houses=0, unsigned house_cost=50);
    virtual ~Property();

    /* Getters and Setters */
    const unsigned* GetRentArray() const;
    unsigned GetCost() const;
    unsigned GetNumberHouses() const;
    bool IsMortgaged() const;
    //void TransferOwnership(const Player& player);
    void BuyHouse();
    void SellHouse();
    void Mortgage();
    void Unmortgage();

private:
    unsigned m_Cost;
    unsigned m_Houses;
    unsigned m_HouseCost;
    bool m_IsMortgaged = false;
    //Player* m_pOwner;
    unsigned* m_Rent = new unsigned[RENT_SLOTS];
};
