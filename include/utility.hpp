/**
 * @file utility.hpp
 * @brief
 * @author Salvatore Cardamone
 */
#ifndef __TEMPMETA_UTILITY_HPP
#define __TEMPMETA_UTILITY_HPP

namespace TempMeta {

template <typename T>
constexpr std::string_view type_name() {

  std::string_view name, prefix, suffix;
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr std::string_view type_name() [with T = ";
  suffix = "; std::string_view = std::basic_string_view<char>]";
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;

}

} // namespace TempMeta

#endif /* #ifndef __TEMPMETA _UTILITY_HPP */
