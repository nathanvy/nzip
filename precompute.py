#!/usr/bin/python

#this script pre-computes powers of 2 up to whatever you specify
# in the range() statement, and writes it to a file as a C++ array.
#
#Note that this assumes you are linking against the GNU GMP library

#change desired filename here
f = open('nzip-array.h', 'a')
f.write('const mpz_class TWOS[] = {1, \n')
#change array size here
for i in range (1, 226):
    f.write(str(2**i) + ',\n')
    #print "2 to the ",i," equals ",2**i #debug

f.write('};')
f.close()
