#include "bitreference.h"
#include "bitset.h"

BitReference& BitReference::operator=(bool b) {
	//
	// *** IMPLEMENT ***
	// This corresponds to the set() function in SimpleBitset.
	//
	// *p_bits: pointer to 'word', is memeber variable, known to function
	// actually not pointer but pointer to pointer which is the actual variable again ?
	// pos is here compared to simplebitset a private member variable
	// BitReference is only pointing to one specific bit with a specific position
	if (b) {
		*p_bits |= 1L << pos;
	} else {
		*p_bits &= ~ (1L << pos);
	}
	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
	//
	// *** IMPLEMENT ***
	// Same as operator=(bool), but the bit is picked from rhs
	//
	bool b = rhs; // automatically uses bool operator ?!

	if (b) {
		*p_bits |= 1L << pos;
	} else {
		*p_bits &= ~ (1L << pos);
	}
	
	return *this;

	//return *this=b;
}

BitReference::operator bool() const {
	//
	// *** IMPLEMENT ***
	// This corresponds to the get() function in SimpleBitset.
	//

	//return true;
	return (*p_bits & (1L << pos)) != 0;
}
