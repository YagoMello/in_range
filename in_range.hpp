#ifndef IN_RANGE_HPP
#define IN_RANGE_HPP

#include <cstddef>
#include <cmath>

/* Iterator simplification lib
 * Author:  Yago T. de Mello
 * e-mail:  yago.t.mello@gmail.com
 * Version: 1.0.0 2022-08-31
 * C++ > 17
 */

namespace in_range_impl {

// The iterator, incremented at each loop iteration
template <typename T>
class in_range_iterator_t {
public:
    using value_type = T;
    
    // Only the initial position and the step are needed
    in_range_iterator_t(const value_type begin, const value_type step) {
        pos_ = begin;
        step_ = step;
    }
    
    // The value returned to the user
    constexpr value_type operator *() const {
        return pos_;
    }
    
    // Generates the next value
    constexpr in_range_iterator_t & operator ++() {
        pos_ += step_;
        return *this;
    }
    
    // Breaks the loop
    constexpr bool operator !=(const value_type rhs) const {
        // same as abs(pos_) < abs(rhs_) but more generic
        if(step_ >= 0) {
            return pos_ < rhs;
        }
        else {
            return pos_ > rhs;
        }
    }
    
private:
    value_type pos_;
    value_type step_;
};

// This class implements the functions required
// by the range for:
// iterator begin()
// something end()
template <typename T>
class in_range_t {
public:
    using value_type = T;
    using iterator_type = in_range_iterator_t<value_type>;
    
    in_range_t(const value_type start, const value_type stop, const value_type step) {
        begin_ = start;
        end_   = stop;
        step_  = step;
    }
    
    // Used by the range for to create the iterator
    constexpr iterator_type begin() const {
        return iterator_type(begin_, step_);
    }
    
    // Used by the range for to check if the
    // iterator reached the end of the sequence
    constexpr value_type end() const {
        return end_;
    }
    
private:
    // First point, part of the sequence
    value_type begin_;

    // First point not in the sequence
    value_type end_;

    // Increment at each step
    value_type step_;
};

} // namespace in_range_impl

// Iterate from 0 to stop-1
template <typename T>
in_range_impl::in_range_t<T> in_range(const T stop) {
    const T start = 0;
    const T step  = 1;
    return in_range_impl::in_range_t(start, stop, step);
}

// Iterate from start to stop-1
template <typename T>
in_range_impl::in_range_t<T> in_range(const T start, const T stop) {
    const T step = 1;
    return in_range_impl::in_range_t(start, stop, step);
}

// Iterate from start to stop-step
template <typename T>
in_range_impl::in_range_t<T> in_range(const T start, const T stop, const T step) {
    return in_range_impl::in_range_t(start, stop, step);
}

#endif // IN_RANGE_HPP
