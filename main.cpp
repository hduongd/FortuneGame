#include <iostream>
#include "Tile.h"
#include "Property.h"

using std::string;
using std::ostream;

ostream& operator<<(ostream& os, Property& prop);

int main()
{
    std::cout << "Hello world!" << std::endl;
    Tile t("Luxury Tax", Tile::LUXURY_TAX);
    unsigned int r[] = {10, 30, 50, 100, 250, 500, 750};
    Property p("Ventnor Avenue", Tile::NO_ACTION, 300, r);
    std::cout << p << std::endl;
    return 0;
}

ostream& operator<<(ostream& os, Property& prop)
{
    os << "\tPROPERTY\n";
    os << "Name: " << prop.GetName() << "\n";
    os << "Cost: $" << prop.GetCost() << "\n\n";
    os << "\tRENT\n";

    const unsigned int* rents = prop.GetRentArray();

    os << "Rent: $" << rents[Property::RENT_SINGLE] << std::endl;
    os << "Rent with color set: $" << rents[Property::RENT_MONOPOLY] << std::endl;
    os << "Rent with one house: $" << rents[Property::ONE_HOUSE] << std::endl;
    os << "Rent with two houses: $" << rents[Property::TWO_HOUSE] << std::endl;
    os << "Rent with three houses: $" << rents[Property::THREE_HOUSE] << std::endl;
    os << "Rent with four houses: $" << rents[Property::FOUR_HOUSE] << std::endl;
    os << "Rent with hotel: $" << rents[Property::HOTEL] << std::endl;
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

    return os;

}
