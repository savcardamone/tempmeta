/**
 * @file numerical.hpp
 * @brief Numerical TMP functions.
 * @author Salvatore Cardamone
 */
#ifndef __TEMPMETA_NUMERICAL_HPP
#define __TEMPMETA_NUMERICAL_HPP

// Standard Library Inclusions
#include <complex>
#include <type_traits>

namespace TempMeta {

template <typename T>
struct is_complex_t : public std::false_type {};
template <typename T>
struct is_complex_t<std::complex<T>> : public std::true_type {};
/**
 * @brief Return true if the templated type is complex, and false otherwise.
 * @tparam The datatype we're establishing is complex or not.
 * @retval As above, true if the templated type is complex and false otherwise.
 */
template <typename T>
constexpr bool is_complex() { return is_complex_t<T>::value; }

template <typename T>
struct numerical_precision_t {
  using type = T;
};
template <typename T>
struct numerical_precision_t<std::complex<T>> {
  using type = T;
};
/**
 * @brief Return the numerical precision of a datatype.
 * @tparam The datatype whose precision we're evaluating.
 * @retval The numerical precision of the datatype underlying the template
           parameter.
 */
template <typename T>
struct numerical_precision {
  using type = typename numerical_precision_t<T>::type;
};

} // namespace TempMeta

#endif /* #ifndef __TEMPMETA_NUMERICAL_HPP */
