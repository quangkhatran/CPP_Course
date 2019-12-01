#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void draw_a_line(int length){
    std::string line (length,'-');
    std::cout << line << std::endl;
}

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    draw_a_line(80);
    std::cout << std::setw(40+tours.title.length()/2 ) << tours.title << std::endl;
    draw_a_line(80);
    std::cout << std::setw(20) << std::left << "Country" << std::setw(20) << std::left << "City" << std::setw(20) 
                    << std::right << "Population" << std::setw(20) << std::right << "Price" << std::endl;                    
    draw_a_line(80);
    bool display_country {true};
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::setw(20) << std::left << country.name; 
        for(auto city : country.cities) {       // loop through the cities for each country
            if(!display_country)
                std::cout << std::setw(20) << " ";
            std::cout << std::setw(20) << std::left << city.name 
                          << std::setw(20) << std::right << city.population 
                          << std::setw(20) << std::right << city.cost 
                          << std::endl;
            display_country = false;
        }
        display_country = true;
    }
    draw_a_line(80);
    return 0;
}