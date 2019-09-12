#ifndef EX1_GFNUMBER_H
#define EX1_GFNUMBER_H

#include "GField.h"
#include <array>
/**
 *
 */
class GFNumber
{

public:
    /**
     *Constructor
     * @param n - number
     * @param f - field
     */
    GFNumber(long n = 0, const GField& f = GField(2, 1));
    /**
     *Copy Constructor
     * @param num
     */
    GFNumber(const GFNumber &num);
    /**
     *Destructor
     */
    ~GFNumber() = default;
    //**********************************************************************************************
    /**
     * Getter - returns the number in the field
     */
    long getNumber() const;
    /**
     *Getter - returns the field
     */
    GField getField() const;
//    const GField& getField() const; //todo
    /**
     * @return if the number is prime
     */
    bool getIsPrime() const;
    /**
     * Calculate the number which divide the number
     * @return an array with prime numbers
     */
    GFNumber* getPrimeFactors(int *size) const;
    /**
      * Operator overloading
      * @return new GFNumber
      */
    friend std::istream &operator>>(std::istream& in, GFNumber& other);
    /**
      * Operator overloading
      * @return new GFNumber
      */
    friend std::ostream &operator<<(std::ostream& out, const GFNumber& other);
    /**
     * Assignment operator
     */
    GFNumber &operator=(const GFNumber &other);
    /**
     * Operator overloading
     * @return new GFNumber
     */
    GFNumber &operator+=(const GFNumber &other);
    /**
       * Operator overloading
       * @return new GFNumber
       */
    GFNumber &operator-=(const GFNumber &other);
    /**
      * Operator overloading
      * @return new GFNumber
      */
    GFNumber &operator*=(const GFNumber &other);
    /**
        * Operator overloading
        * @return new GFNumber
        */
    GFNumber &operator%=(const GFNumber &other);
    /**
      * Operator overloading
      * @return new GFNumber
      */
    GFNumber &operator+=(const long &n);
    /**
      * Operator overloading
      * @return new GFNumber
      */
    GFNumber &operator-=(const long &n);
    /**
       * Operator overloading
       * @return new GFNumber
       */
    GFNumber &operator*=(const long &n);
    /**
      * Operator overloading
      * @return new GFNumber
      */
    GFNumber &operator%=(const long &n);
    /**
     * Overloaded operator
     */
    bool operator<=(const GFNumber &other)const;
    /**
      * Overloaded operator
      */
    bool operator>=(const GFNumber &other)const;
    /**
     * Overloaded operator
     */
    bool operator>(const GFNumber &other)const;
    /**
     * Overloaded operator
     */
    bool operator<(const GFNumber &other)const;
    /**
     * Overloaded operator
     */
    bool operator==(const GFNumber &other) const;
    /**
     * Overloaded operator
     */
    bool operator!=(const GFNumber &other) const;
    /**
     * Overloaded operator +
     */
    GFNumber operator+(const GFNumber &other) const;
    /**
    * Overloaded operator +
    */
    GFNumber operator-(const GFNumber &other)const;
    /**
     * Overloaded operator +
     */
    GFNumber operator*(const GFNumber &other)const;
    /**
     * Overloaded operator +
     */
    GFNumber operator%(const GFNumber &other)const;
    /**
    * Overloaded operator +
    */
    GFNumber operator+(const long &n)const;
    /**
      * Overloaded operator +
      */
    GFNumber operator-(const long &n) const;
    /**
      * Overloaded operator +
      */
    GFNumber operator*(const long &n) const;
    /**
       * Overloaded operator +
       */
    GFNumber operator%(const long &n) const;
    /**
     *Prints an array of prime number which divide the number
     */
    void printFactors() const;


private:
    long _number;
    GField _field;

    /**
    * Responsible for calculating the number inside the given field
    */
    long _calcMod(long n, const GField &f) const;
    /**
     * Responsible for generating a random number inside the field
     */
    long _generateRandNum(long n) const;
    /**
    * Polard function, responsible for calculating a prime number which divides n
    */
    long _polardFun(long n) const;
    /**
     * An Helper function for polard function
     */
    long _polardHelper(long& x) const { return (x ^ 2) + 1; }

    /**
     * Checks overflow-size in the array
     */
    GFNumber* _checkOverFlow(GFNumber *primes, int size) const;
    /**
     * Bruth-Force algorithm for finding prime divisiors.
     */
    GFNumber *_trailDivision(GFNumber *primeArr, long num, int &devCount) const;


};

#endif //EX1_GFNUMBER_H
