/**
 * @file container.hpp
 * @brief Container TMP functions.
 * @author Salvatore Cardamone
 */
#ifndef __TEMPMETA_CONTAINER_HPP
#define __TEMPMETA_CONTAINER_HPP

namespace TempMeta {

template <class Container, class Iter>
auto insert_impl(Container &c, Iter where, const size_t &num_vals, const typename Container::value_type &pad_val, int)
    -> decltype(c.insert(where, num_vals, pad_val))
{
    return c.insert(where, num_vals, pad_val);
}
template <class Container, class Iter>
auto insert_impl(Container &c, Iter where, const size_t &num_vals, const typename Container::value_type &pad_val, long)
    -> void
{
    // Just shut the compiler up about unused variables
    static_cast<void>(c); static_cast<void>(where); static_cast<void>(num_vals); static_cast<void>(pad_val);
    throw std::runtime_error("Container has no insert method.");
}
/**
 * @brief Invoke the insert() container method if the container supports
 *        this functionality, otherwise throw a runtime_error.
 *
 *        Allows containers which don't support dynamic resizing to be passed to
 *        functions which require insert on certain conditional branches. The
 *        container can then be used on the branches not using insert(), making
 *        an implementation more generic. A runtime error will be thrown if a
 *        branch requiring insert() is taken.
 * @tparam Container The container we're querying for insert().
 * @tparam Iter Iterator to the element in the container we're trying to insert.
 * @param c The container.
 * @param where Iterator to the element in the container where insertion will happen.
 * @param num_vals Number of values to insert.
 * @param pad_val Value to insert.
 */
template <class Container, class Iter>
auto insert(Container &c, Iter where, const size_t &num_vals, const typename Container::value_type &pad_val)
    -> decltype(insert_impl(c, where, num_vals, pad_val, 0))
{
    return insert_impl(c, where, num_vals, pad_val, 0);
}

} // namespace TempMeta

#endif /* #ifndef __TEMPMETA_CONTAINER_HPP */
