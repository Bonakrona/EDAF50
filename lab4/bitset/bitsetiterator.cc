#include "bitsetiterator.h"

BitsetIterator::BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}

bool BitsetIterator::operator!=(const BitsetIterator& bsi) const {
    return ref.p_bits != bsi.ref.p_bits || ref.pos != bsi.ref.pos;
}

BitsetIterator& BitsetIterator::operator++() {
    ref.pos++;
    return *this;
}

BitReference BitsetIterator::operator*() {
    return ref;
}

BitsetIterator& BitsetIterator::operator=(const BitsetIterator& rhs) {
    ref.p_bits = rhs.ref.p_bits;
    ref.pos = rhs.ref.pos;
    return *this;
}
