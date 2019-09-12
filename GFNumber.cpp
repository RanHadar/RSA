#include "GFNumber.h"
#include "GField.h"
#include <cassert>
#include <math.h>
#include <iostream>
#include <random>
#include <ctime>
//******************************Constructors*****************************************
/**
*Constructor
* @param n - number
* @param f - field
*/
GFNumber::GFNumber(long n, const GField &f) : _number(_calcMod(n, f)), _field(f)
{
}
/**
 *Copy Constructor
 * @param num
 */
GFNumber::GFNumber(const GFNumber &num)
{
    this->_number = num.getNumber();
    this->_field = num.getField();
}

//***********************************************************************************
/**
 * Returns the number in the field
 */
long GFNumber::getNumber() const
{
    return this->_number;
}

/**
 * Returns the field
 */
GField GFNumber::getField() const
{
    return this->_field;
}

/**
 * Responsible for calculating the number inside the given field
 */
long GFNumber::_calcMod(long n, const GField &f) const
{
    if (n < 0)
    {
        n = f.getOrder() - (n * (-1));
        if(f.getOrder() < abs(n))
        {
            n = abs(n);
        }
    }
    return n % f.getOrder();
}
//********************************Operators******************************************
/**
* Assignment operator
*/
GFNumber &GFNumber::operator=(const GFNumber &other)
{
    this->_number = other.getNumber();
    this->_field = other.getField();
    return *this;
}

/**
 * Overloaded operator  >>
 */
std::istream &operator>>(std::istream &in, GFNumber &other)
{
    long temp;
    in >> temp >> other._field;
//    assert(in.fail() && "insertaion type not legal");
    other._number = other._calcMod(temp, other._field);
    return in;
}

/**
 * Overloaded operator  <<
 */
std::ostream &operator<<(std::ostream &out, const GFNumber &other)
{
    out << other._number << " GF(" << other._field.getChar()
        << "**" << other._field.getDegree() << ")" << std::endl;
//    assert(!out.fail());
    return out;
}

/**
 * Overloaded operator  ==
 */
bool GFNumber::operator==(const GFNumber &other) const
{
    return ((this->_number == other._number) && (this->_field == other._field));
}

/**
 * Overloaded operator  !=
 */
bool GFNumber::operator!=(const GFNumber &other) const
{
    return ((this->_number != other._number) || (this->_field == other._field));
}

/**
 * Overloaded operator +
 */
GFNumber GFNumber::operator+(const GFNumber &other)const
{
    assert(this->_field == other.getField());
    long sum = this->_number + other.getNumber();
    sum = _calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}

/**
 * Overloaded operator +
 */
GFNumber GFNumber::operator+(const long &n)const
{
    long sum = this->_number + n;
    sum = _calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}

/**
 * Overloaded operator -
 */
GFNumber GFNumber::operator-(const long &n)const
{
    long sum = this->_number - n;
    sum = _calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}
/**
 * Overloaded operator *
 */
GFNumber GFNumber::operator*(const long &n)const
{
    long sum = this->_number * n;
    sum = _calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}
/**
 * Overloaded operator %
 */
GFNumber GFNumber::operator%(const long &n)const
{
    long sum = this->_number % n;
    sum = _calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}
/**
 * Overloaded operator -
 */
GFNumber GFNumber::operator-(const GFNumber &other)const
{
    assert(this->_field == other.getField());
    long sum = this->_number - other.getNumber();
    sum = other._calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}

/**
 * Overloaded operator *
 */
GFNumber GFNumber::operator*(const GFNumber &other)const
{
    assert(this->_field == other.getField());
    long sum = this->_number * other.getNumber();
    sum = other._calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}

/**
 * Overloaded operator %
 */
GFNumber GFNumber::operator%(const GFNumber &other)const
{
    assert(this->_field == other.getField());
    long sum = this->_number % other.getNumber();
    sum = other._calcMod(sum, this->_field);
    GFNumber num(sum, this->_field);
    return num;
}

/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator+=(const GFNumber &other)
{
    long sum = this->_number + other.getNumber();
    this->_number = _calcMod(sum, this->_field);
    assert(this->_field == other.getField());
    return *this;
}
/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator-=(const GFNumber &other)
{
    long sum = this->_number - other.getNumber();
    this->_number = _calcMod(sum, this->_field);
    assert(this->_field == other.getField());
    return *this;
}
/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator*=(const GFNumber &other)
{
    long sum = this->_number * other.getNumber();
    this->_number = _calcMod(sum, this->_field);
    assert(this->_field == other.getField());
    return *this;
}
/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator%=(const GFNumber &other)
{
    assert(this->_field == other.getField());
    long sum = _number % other.getNumber();
    _number = _calcMod(sum, this->_field);
    return *this;
}

/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator+=(const long &n)
{
    long sum = this->_number + n;
    this->_number = _calcMod(sum, this->_field);
    return *this;
}

/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator-=(const long &n)
{
    long sum = this->_number - n;
    this->_number = _calcMod(sum, this->_field);
    return *this;
}
/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator*=(const long &n)
{
    long sum = this->_number * n;
    this->_number = _calcMod(sum, this->_field);
    return *this;
}

/**
 * Operator overloading
 * @return new GFNumber
 */
GFNumber &GFNumber::operator%=(const long &n)
{
    return (*this %= GFNumber(n, _field));
}

/**
 * Overloaded operator  <=
 */
bool GFNumber::operator<=(const GFNumber &other) const
{
    assert(this->_field == other.getField());
    return (this->getNumber() <= other.getNumber());
}

/**
 * Overloaded operator  >=
 */
bool GFNumber::operator>=(const GFNumber &other) const
{
    assert(this->_field == other.getField());
    return (this->getNumber() >= other.getNumber());
}

/**
 * Overloaded operator  <
 */
bool GFNumber::operator<(const GFNumber &other) const
{
    assert(this->_field == other.getField());
    return (this->getNumber() < other.getNumber());
}

/**
 * Overloaded operator >
 */
bool GFNumber::operator>(const GFNumber &other) const
{
    assert(this->_field == other.getField());
    return (this->getNumber() > other.getNumber());
}
//***********************************************************************************
/**
* @return if the number is prime
*/
bool GFNumber::getIsPrime() const
{
    long num = abs(this->getNumber());
    if(num == 0 || num == 1)
    {
        return false;
    }
    long sqt = lround(sqrt(num));
    while (sqt != num - 1)
    {
        if (num % sqt == 0)
        {
            return false;
        }
        sqt++;
    }
    return true;
}

/**
* Calculate the number which divide the number
* @return an array with prime numbers
*/
GFNumber *GFNumber::getPrimeFactors(int *size) const
{
    long num = this->getNumber();
    int devCount = 0;

    if (num == 0 || num == 1 || getIsPrime())
    {
        *size = devCount;
        return nullptr;
    }
    GFNumber *primeArr = new GFNumber[5];
    while (num % 2 == 0)
    {
        GFNumber divisor(2, this->getField());
        primeArr[devCount] = divisor;
        devCount = devCount + 1;
        num = num / 2;
    }
    long p;
    while (num > 1 && (p = _polardFun(num)) != -1)
    {
        GFNumber divisor(p, this->getField());
        primeArr[devCount] = divisor;
        num = num / p;
        devCount = devCount + 1;
        primeArr = this->_checkOverFlow(primeArr, devCount);

    }
    if (num != 1)
    {
        primeArr = _trailDivision(primeArr, num, devCount);
    }

    *size = devCount;
    return primeArr;
}

/**
 * Bruth-Force algorithm for finding prime divisiors.
 */
GFNumber *GFNumber::_trailDivision(GFNumber *primeArr, long num, int &devCount) const
{
    int i = 2;
    while (i < sqrt(num))
    {
        if (num % i == 0)
        {
            GFNumber divisor(i, getField());
            primeArr[devCount] = divisor;
            num = num / floor(i);
            devCount = devCount + 1;
            primeArr = _checkOverFlow(primeArr, devCount);
        }
        else
        {
            i++;
        }
    }
    if (num > 1)
    {
        GFNumber divisor(num, getField());
        primeArr[devCount] = divisor;
        devCount++;
    }
    return primeArr;
}

/**
* Checks overflow-size in the array
*/
GFNumber *GFNumber::_checkOverFlow(GFNumber *primes, int devCount) const
{
    if (devCount % 5 == 0)
    {
        GFNumber *primeArr = new GFNumber[devCount + 5];
        for(int i = 0; i < devCount; i++)
        {
            primeArr[i] = primes[i];
        }
        delete[]primes;
        return primeArr;
    }
    return primes;
}


/**
 * Polard function, responsible for calculating a prime number which divides n
 */
long GFNumber::_polardFun(long n) const
{
    if (this->getField().isPrime(n))
    {
        return n;
    }
    long x = this->_generateRandNum(n);
    long y = x;
    long p = 1;
    while (p == 1)
    {
        x = _polardHelper(x) % this->getField().getOrder();
        y = _polardHelper(y) % this->getField().getOrder();
        p = this->_field.gcdHelper(abs(x - y), n);
        p = p % this->getField().getOrder();
    }
    if (p == n)
    {
        return -1;
    }
    return p;
}

/**
 * Responsible for generating a random number inside the field
 */
long GFNumber::_generateRandNum(long n) const
{
    std::mt19937 generator;
//    generator.seed(std::time(0));
    std::uniform_int_distribution<long> dice(1, n - 1);
    long random = dice(generator);
    return random;
}

/**
*Prints an array of prime number which divide the number
*/
void GFNumber::printFactors() const
{
    int *size = new int;
    GFNumber *factors = getPrimeFactors(size);
    std::cout << this->getNumber() << "=";
    if (*size == 0)
    {
        std::cout << this->getNumber() << "*" << "1" << std::endl;
    }
    else
    {
        for (int i = 0; i < (*size) - 1; i++)
        {
            std::cout << factors[i].getNumber() << "*";
        }
        std::cout << factors[*size - 1].getNumber() << std::endl;
        delete[]factors;
    }
    delete size;
}
