#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>

#include "brokerage_api.h" // Include the brokerage API header file

int main()
{
    // Connect to brokerage API
    BrokerageAPI api;
    api.connect("username", "password");

    bool running = true;
    while (running)
    {
        std::cout << "1. View market data" << std::endl;
        std::cout << "2. Submit order" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter selection: ";

        int selection;
        std::cin >> selection;

        switch (selection)
        {
        case 1:
        {
            // Get the current price of a stock
            std::cout << "Enter ticker symbol: ";
            std::string ticker;
            std::cin >> ticker;
            double price = api.get_price(ticker);
            std::cout << "Current price of " << ticker << ": " << price << std::endl;
            break;
        }
        case 2:
        {
            // Submit an order
            std::cout << "Enter ticker symbol: ";
            std::string ticker;
            std::cin >> ticker;

            std::cout << "Enter quantity: ";
            int quantity;
            std::cin >> quantity;

            std::cout << "Enter order type (1 = MARKET, 2 = LIMIT): ";
            OrderType type;
            int type_input;
            std::cin >> type_input;
            if (type_input == 1)
                type = OrderType::MARKET;
            else
                type = OrderType::LIMIT;

            std::cout << "Enter order side (1 = BUY, 2 = SELL): ";
            OrderSide side;
            int side_input;
            std::cin >> side_input;
            if (side_input == 1)
                side = OrderSide::BUY;
            else
                side = OrderSide::SELL;

            api.submit_order(ticker, quantity, type, side);
            break;
        }
        case 3:
            running = false;
            break;
        default:
            std::cout << "Invalid selection" << std::endl;
            break;
        }
    }

    // Disconnect from brokerage API
    api.disconnect();

    return 0;
}
