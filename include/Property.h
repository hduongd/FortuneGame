#pragma once

#include <Tile.h>

#include <string>

class Property : public Tile
{
public:
    static const unsigned RENT_SLOTS = 6;

    enum rent {RENT, ONE, TWO, THREE, FOUR, HOTEL};
    friend std::ostream& operator<<(std::ostream& os, Property& prop);

    Property(const std::string& name, unsigned action, unsigned cost,
             unsigned* rents, unsigned group, unsigned house_cost=50);
    virtual ~Property();

    /* Getters and Setters */
    const unsigned* GetRentArray() const;
    unsigned GetCost() const;
    unsigned GetNumberHouses() const;
    unsigned GetGroup() const;
    bool IsMortgaged() const;
    //void TransferOwnership(const Player& player);
    void BuyHouse();
    void SellHouse();
    void Mortgage();
    void Unmortgage();

private:
    unsigned m_Cost;
    unsigned m_Group;
    unsigned m_Houses = 0;
    unsigned m_HouseCost;
    bool m_IsMortgaged = false;
    //Player* m_pOwner;
    unsigned* m_Rent = new unsigned[RENT_SLOTS];
};
