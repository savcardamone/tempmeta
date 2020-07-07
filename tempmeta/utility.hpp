/**
 * @file utility.hpp
 * @brief Generic TMP functions.
 * @author Salvatore Cardamone
 */
#ifndef __TEMPMETA_UTILITY_HPP
#define __TEMPMETA_UTILITY_HPP

namespace TempMeta {

/**
 * @brief Generate a readable string for the datatype of the
 *        template parameter.
 * @tparam T The type we want to print.
 * @return constexpr std::string_view String of the datatype.
 */
template <typename T>
constexpr std::string_view type_name() {

  // Garbage that __PRETTY_FUNCTION__ creates with GNU compiler that
  // we want to discard from the string
  std::string_view name = __PRETTY_FUNCTION__;
  std::string_view prefix = "constexpr std::string_view type_name() [with T = ";
  std::string_view suffix = "; std::string_view = std::basic_string_view<char>]";

  // Remove the garbage
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;

}

} // namespace TempMeta

#endif /* #ifndef __TEMPMETA _UTILITY_HPP */
