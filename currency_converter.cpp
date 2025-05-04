#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>
#include "currency_converter.h"

USD::USD() {
    rates["EUR"] = 0.93;
    rates["GBP"] = 0.80;
    rates["JPY"] = 151.23;
    rates["AUD"] = 1.50;
    rates["CAD"] = 1.36;
    rates["CHF"] = 0.91;
    rates["CNY"] = 7.23;
    rates["SEK"] = 10.65;
    rates["NZD"] = 1.61;
    rates["INR"] = 83.10;
    rates["USD"] = 1.0;
}

double USD::convert(double amount, const std::string& toCurrency) const {
    auto it = rates.find(toCurrency);
    if (it != rates.end()) {
        return amount * it->second;
    } else {
        throw InvalidCurrencyException();
    }
}

std::string USD::getCurrencyName() const {
    return "USD";
}

EUR::EUR() {
    rates["USD"] = 1.08;
    rates["GBP"] = 0.86;
    rates["JPY"] = 162.74;
    rates["AUD"] = 1.62;
    rates["CAD"] = 1.46;
    rates["CHF"] = 0.98;
    rates["CNY"] = 7.78;
    rates["SEK"] = 11.44;
    rates["NZD"] = 1.73;
    rates["INR"] = 89.75;
    rates["EUR"] = 1.0;
}

double EUR::convert(double amount, const std::string& toCurrency) const {
    auto it = rates.find(toCurrency);
    if (it != rates.end()) {
        return amount * it->second;
    } else {
        throw InvalidCurrencyException();
    }
}

std::string EUR::getCurrencyName() const {
    return "EUR";
}

GBP::GBP() {
    rates["USD"] = 1.25;
    rates["EUR"] = 1.17;
    rates["JPY"] = 189.12;
    rates["AUD"] = 1.88;
    rates["CAD"] = 1.69;
    rates["CHF"] = 1.14;
    rates["CNY"] = 9.03;
    rates["SEK"] = 13.32;
    rates["NZD"] = 2.00;
    rates["INR"] = 105.40;
    rates["GBP"] = 1.0;
}

double GBP::convert(double amount, const std::string& toCurrency) const {
    auto it = rates.find(toCurrency);
    if (it != rates.end()) {
        return amount * it->second;
    } else {
        throw InvalidCurrencyException();
    }
}

std::string GBP::getCurrencyName() const {
    return "GBP";
}
