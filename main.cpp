#include <iostream>
#include <iomanip>
#include "include/Property.h"
#include "include/Board.h"

using std::string;
using std::ostream;

ostream& operator<<(ostream& os, Property& prop);

int main()
{
    Board gameBoard;
    Tile* pTile = gameBoard.GetTileInPosition(1);
    Tile* pTile2 = gameBoard.GetTileInPosition(3);
    Property* pProp = static_cast<Property*>(pTile);
    Property* pProp2 = static_cast<Property*>(pTile2);

    pProp->Mortgage();

    std::cout << *pProp << std::endl;
    std::cout << *pProp2 << std::endl;
    return 0;
}

ostream& operator<<(ostream& os, Property& prop)
{
    os << "\n\tPROPERTY\n";
    os << "Name: " << prop.GetName() << ", Group " << prop.GetGroup() << "\n";
    os << "Cost: $" << prop.GetCost() << "\n\n";
    os << "\tRENT\n";

    const unsigned* rents = prop.GetRentArray();

    os << "Rent" << std::right << std::setfill('.') << std::setw(60) << "$" << rents[Property::RENT] << std::endl;
    os << "Rent with color set" << std::right << std::setfill('.') << std::setw(45) << "$" << rents[Property::RENT] * 2 << std::endl;
    os << "Rent with one house" << std::right << std::setfill('.') << std::setw(45) << "$" << rents[Property::ONE] << std::endl;
    os << "Rent with two houses" << std::right << std::setfill('.') << std::setw(44) << "$" << rents[Property::TWO] << std::endl;
    os << "Rent with three houses" << std::right << std::setfill('.') << std::setw(42) << "$" << rents[Property::THREE] << std::endl;
    os << "Rent with four houses" << std::right << std::setfill('.') << std::setw(43) << "$" << rents[Property::FOUR] << std::endl;
    os << "Rent with hotel" << std::right << std::setfill('.') << std::setw(49) << "$" << rents[Property::HOTEL] << std::endl;
    os << "\tDETAILS\n";
    if (prop.IsMortgaged())
    {
        os << "This property is mortgaged.\n";
    }
    else
    {
        os << "This property is not mortgaged.\n";
    }
    os << "Number of houses built on this property: " << prop.GetNumberHouses() << std::endl;
    os << std::setfill('#') << std::setw(80);

    return os;

}
