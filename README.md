# SieveOfEratosthenes
Finding prime numbers less than or equal to a given number n ie., all primes in the range 2 through n using Sieve Of Eratosthenes method

Logic of Sieve of Eratosthnes method:

Consider the list of numbers from 2 through n. Two is the first prime number but
multiples of 2 (4, 6, 8, …) are not, and so they are crossed out in the list. The first number
after 2 that was not crossed out is 3, the next prime. We then cross out from the list all
higher multiples of 3 (6, 9, 12, …). The next number not crossed out is 5, the next prime,
and so we cross out all higher multiples of 5 (10, 15, 20, …). We repeat this procedure
until we reach the first number in the list that has not been crossed out and whose square
is greater than n.

Description of the program:

The program uses the above outlined sieve method to find all the prime numbers
from 2 through n. The program will be reading the values of n from a file. The program will be
using a two-dimensional dynamic array to store the stepwise results of the sieve method.
The starting dimensions of the array will be 5 by n. When needed, the array will be
resized to grow row-wise in increments of 5 and a message ‘Array Resized’ will be
sent to the screen. Additionally, the user should is given a choice of two modes to run
the program – in the first mode, the contents of the entire array is sent to the screen and
in the second mode only the final result i.e. the remaining numbers of the list at the end
are sent to the screen. This information about the mode is also coming from
the file.
