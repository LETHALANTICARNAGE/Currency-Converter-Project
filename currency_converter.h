#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>

// Base class
class Currency {
public:
    virtual double convert(double amount, const std::string& toCurrency) const = 0;
    virtual std::string getCurrencyName() const = 0;
    virtual ~Currency() {}
};

// Derived class level 1
class USD : public Currency {
protected:
    std::map<std::string, double> rates;
public:
    USD();
    double convert(double amount, const std::string& toCurrency) const override;
    std::string getCurrencyName() const override;
};

// Derived class level 2
class EUR : public USD {
public:
    EUR();
    double convert(double amount, const std::string& toCurrency) const override;
    std::string getCurrencyName() const override;
};

// Another Derived class level 2
class GBP : public USD {
public:
    GBP();
    double convert(double amount, const std::string& toCurrency) const override;
    std::string getCurrencyName() const override;
};

// Exception class
class InvalidCurrencyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid currency conversion requested.";
    }
};

#endif
