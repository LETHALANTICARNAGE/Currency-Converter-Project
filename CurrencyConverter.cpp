#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "currency_converter.h"

int main() {
    std::vector<Currency*> converters;
    converters.push_back(new USD());
    converters.push_back(new EUR());
    converters.push_back(new GBP());

    std::string fromCurrency, toCurrency;
    double amount;

    try {
        std::cout << "Available currencies: USD, EUR, GBP, JPY, AUD, CAD, CHF, CNY, SEK, NZD, INR" << std::endl;
        std::cout << "Enter source currency(case sensitive): ";
        std::cin >> fromCurrency;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        std::cout << "Enter target currency(case sensitive): ";
        std::cin >> toCurrency;

        auto it = std::find_if(converters.begin(), converters.end(), [&](Currency* c) {
            return c->getCurrencyName() == fromCurrency;
        });

        if (it != converters.end()) {
            double result = (*it)->convert(amount, toCurrency);
            std::cout << amount << " " << fromCurrency << " = " << result << " " << toCurrency << std::endl;
        } else {
            throw InvalidCurrencyException();
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    for (Currency* c : converters) delete c;
    return 0;
}
