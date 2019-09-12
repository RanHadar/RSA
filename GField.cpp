#include <iostream>
#include <malloc.h>
#include <math.h>
#include <cassert>
#include "GFNumber.h"
#include "GField.h"

/**
  *Constructor
  * @param Field Degree
  * @param Field Char
  */
GField::GField(long p, long l):_l(l), _p(abs(p))
{
    assert(l > 0);
    assert(isPrime(p));

}
/**
    *Copy Constructor
    * @param num
    */
GField::GField(const GField &num)
{
    _l = num.getDegree();
    _p = num.getChar();
}
/**
*Destructor
*/
GField::~GField() {}

//***************************Methods****************************************
/**
 *Returns char value - using to set the char field
 */
long& GField::getChar()
{
    return _p;
}
/**
 *Returns char value - const value, no changes.
 */
const long& GField::getChar() const
{
    return _p;
}
/**
*Returns Field's Degree
*/
long& GField::getDegree()
{
    return _l;
}
/**
*Returns degree value - using to set the char field
*/
const long& GField::getDegree() const
{
    return _l;
}
/**
*Returns field's order
*/
long GField::getOrder() const
{
    return lround(pow(_p, _l));
}
/**
*Checks if a given number is prime
*/
bool GField::isPrime(long p)
{
    p = abs(p);
    if(p == 0 || p == 1)
    {
        return false;
    }
    long sqt = lround(sqrt(p));
    while(sqt != p-1)
    {
        if(p % sqt == 0)
        {
            return false;
        }
        sqt++;
    }
    return true;
}
/**
*Returns gcd value of 2 given numbers
*/
GFNumber GField::gcd(const GFNumber &a, const GFNumber &b) const
{
    long a_n = a.getNumber();
    long b_n = b.getNumber();
    long gcdNum = gcdHelper(a_n, b_n);
    GFNumber num(gcdNum, a.getField());
    return num;
}
/**
  * @param num1 - long
  * @param num2 - long
  * @return gcd value
  */
long GField::gcdHelper(long num1, long num2) const
{
    if (num1 == 0)
    {
        return num2;
    }
    if (num2 == 0)
    {
        return num1;
    }
    if (num1 == num2)
    {
        return num1;
    }
    if (num1 > num2)
    {
        return gcdHelper(num1 - num2, num2);
    }
    return gcdHelper(num1, num2 - num1);
}
/**
* Gets a number and turns it to a number in the same field.
*/
GFNumber GField::createNumber(long k) const
{
    GFNumber num(k, *this);
    return num;
}
//****************************Operators-OverLoading******************************
/**
*Operator - output
* @param out
* @param other
* @return output stream
*/
std::ostream &operator<<(std::ostream& out, const GField& other)
{
    out << "GF(" << other.getChar() << "**" << other .getDegree() << ")" << std::endl;
    assert(!out.fail());
    return out;
}
/**
 *Operator - input
 * @param in
 * @param other
 * @return input stream
 */
std::istream &operator>>(std::istream& in, GField& other)
{
    long tempChar, tempDeg;
    in >> tempChar >> tempDeg;
    assert(!in.fail());
    assert(tempDeg > 0 && "Degree is negative");
    assert(other.isPrime(tempChar) && "Char is not a prime number");
//    assert(tempChar == 0 && "Char is zero");
    other.getChar() = abs(tempChar);
    other.getDegree() = tempDeg;
    return in;
}
/**
*Operator
* @param other -  GField
* @return new GField with same values.
*/
GField& GField::operator=(const GField &other)
{
    _p = other.getChar();
    _l = other.getDegree();
    return *this;
}
/**
 *Operator
 * @param other - GField
 * @return true/false
 */
bool GField::operator==(const GField &other)const
{
    return (_p == other.getChar()) && (_l == other.getDegree());
}
/**
*Operator
* @param other - GField
* @return true/false
*/
bool GField::operator!=(const GField &other)const
{
    return (_p != other.getChar()) || (_l != other.getDegree());
}
