// Header Class Defining Fractional Numbers
// Vincent Pham

#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <iostream>
#include <cstdlib>

// Forward Declaration(s)
class Fraction;
uint32_t findGCD(int32_t n, int32_t d);
std::ostream &operator<<(std::ostream &os, const Fraction &f);

class Fraction
{
private:
    int32_t m_numerator;
    int32_t m_denominator;

public:
    // INSERTION OVERLOAD
    friend std::ostream &operator<<(std::ostream &os, const Fraction &c);

    // DEFAULT CONSTRUCTOR
    Fraction()
    {
        m_numerator = 0;
        m_denominator = 0;
    }

    // PARAMETERIZED CONSTRUCTOR
    Fraction(int32_t n, int32_t d)
        : m_numerator(n), m_denominator(d)
    {
    }

    // SIMPLIFY
    bool simplify()
    {
        uint32_t gcd = findGCD(m_numerator, m_denominator);
        if (gcd == 1)
            return false;
        m_numerator /= gcd;
        m_denominator /= gcd;
        return true;
    }

    // GET m_numerator
    int32_t getNumerator() const
    {
        return m_numerator;
    }

    // GET DENOMINATOR
    int32_t getDenominator() const
    {
        return m_denominator;
    }

    // SET NUMERATOR
    void setNumerator(const int32_t &n)
    {
        m_numerator = n;
    }

    // SET DENOMINATOR
    void setDenominator(const int32_t &d)
    {
        m_denominator = d;
    }

    // ASSIGNMENT OVERLOAD
    Fraction &operator=(const Fraction &rhs)
    {
        m_numerator = rhs.getNumerator();
        m_denominator = rhs.getDenominator();
        return *this;
    }

    // ADDITION OVERLOAD
    Fraction operator+(const Fraction &rhs) const
    {
        Fraction res = Fraction(m_numerator, m_denominator);
        res.setNumerator(rhs.getDenominator() * res.getNumerator() + res.getDenominator() * rhs.getNumerator());
        res.setDenominator(rhs.getDenominator() * res.getDenominator());
        res.simplify();
        return res;
    }

    // SUBTRACTION OVERLOAD
    Fraction operator-(const Fraction &rhs) const
    {
        Fraction res = Fraction(m_numerator, m_denominator);
        res.setNumerator(rhs.getDenominator() * res.getNumerator() - res.getDenominator() * rhs.getNumerator());
        res.setDenominator(rhs.getDenominator() * res.getDenominator());
        res.simplify();
        return res;
    }

    // MULTIPLICATION OVERLOAD
    Fraction operator*(const Fraction &rhs) const
    {
        Fraction res = Fraction(m_numerator * rhs.getNumerator(), m_denominator * rhs.getDenominator());
        res.simplify();
        return res;
    }

    Fraction operator*(const int &rhs) const
    {
        Fraction res = Fraction(m_numerator * rhs, m_denominator);
        res.simplify();
        return res;
    }

    // DIVISION OVERLOAD
    Fraction operator/(const Fraction &rhs) const
    {
        Fraction res = Fraction(m_numerator * rhs.getDenominator(), m_denominator * rhs.getNumerator());
        res.simplify();
        return res;
    }
};

// INSERTION OVERLOAD IMPLEMENTATION
std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    os << f.getNumerator() << "/" << f.getDenominator();
    return os;
}

// Finds GCD using Euclidian Algorithm
uint32_t findGCD(int32_t n, int32_t d)
{
    //Base Cases
    if (n == 0)
        return d;
    if (d == 0)
        return n;
    int32_t r = n % d;
    return findGCD(n, r);
}

#endif //__FRACTION_H__