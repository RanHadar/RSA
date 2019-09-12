#ifndef EX1_GFIELD_H
#define EX1_GFIELD_H
#include <iostream>
/**
 * Class represents a Number in a given field
 */
class GFNumber;
/**
 *Class represents a field
 */
class GField
{

public:

    /**
     *Constructor
     * @param Field Degree
     * @param Field Char
     */
    explicit GField(long p = 2, long l = 1);
    /**
     *Copy Constructor
     * @param num
     */
    GField(const GField &num);
    /**
     *Destructor
     */
    ~GField();
//*********************************************************************************************************
    /**
     *Returns char value - using to set the char field
     */
    long& getChar();
    /**
     *Returns char value - const value, no changes.
     */
    const long& getChar() const;
    /**
     *Returns Field's Degree
     */
    long& getDegree();
    /**
     *Returns degree value - using to set the char field
     */
    const long& getDegree() const;
    /**
     *Returns field's order
     */
    long getOrder() const;
    /**
     *
     *Checks if a given number is prime
     */
    static bool isPrime(long p);
    /**
     *Returns gcd value of 2 given numbers
     */
    GFNumber gcd(const GFNumber &a, const GFNumber &b) const;
    /**
     * @param num1 - long
     * @param num2 - long
     * @return gcd value
     */
    long gcdHelper(long num1, long num2) const;
    /**
     * Gets a number and turns it to a number in the same field.
     */
    GFNumber createNumber(long k) const;
    /**
     *Operator
     * @param other -  GField
     * @return new GField with same values.
     */
    GField &operator=(const GField &other);
    /**
     *Operator
     * @param other - GField
     * @return true/false
     */
    bool operator==(const GField &other) const;
    /**
     *Operator
     * @param other - GField
     * @return true/false
     */
    bool operator!=(const GField &other) const;
    /**
     *Operator - output
     * @param out
     * @param other
     * @return output stream
     */
    friend std::ostream &operator<<(std::ostream& out, const GField& other);
    /**
     *Operator - input
     * @param in
     * @param other
     * @return input stream
     */
    friend std::istream &operator>>(std::istream& in, GField& other);

private:
    long _l;
    long _p;

};

#endif //EX1_GFIELD_H
