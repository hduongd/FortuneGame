#include <Tile.h>

#include <string>

const int RENT_SLOTS = 7;

class Property : public Tile
{
public:
    enum rent {RENT_SINGLE, RENT_MONOPOLY, ONE_HOUSE, TWO_HOUSE, THREE_HOUSE, FOUR_HOUSE, HOTEL};
    friend std::ostream& operator<<(std::ostream& os, Property& prop);

    Property(const std::string& name, unsigned int action, unsigned int cost,
             unsigned int* rents, unsigned int houses=0, unsigned int house_cost=50);

    /* Getters and Setters */
    const unsigned int* GetRentArray() const;
    unsigned int GetCost() const;
    unsigned int GetNumberHouses() const;
    bool IsMortgaged() const;
    //void TransferOwnership(const Player& player);
    void BuyHouse();
    void SellHouse();
    void Mortgage();
    void Unmortgage();

private:
    unsigned int m_Cost;
    unsigned int m_Houses;
    unsigned int m_HouseCost;
    bool m_IsMortgaged = false;
    //Player* m_pOwner;
    unsigned int m_Rent[RENT_SLOTS];
};
