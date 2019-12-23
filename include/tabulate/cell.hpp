#pragma once
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tabulate/format.hpp>
#include <vector>

namespace tabulate {

class Cell {
public:
  void set_text(const std::string &text) { data_ = text; }

  size_t size() const { return data_.size(); }

  Format &format() {
    if (!format_.has_value()) {      // no cell format
      format_ = table_format_.get(); // Use parent table format
    }
    return format_.value();
  }

private:
  explicit Cell(class Row& parent, Format &table_format) : parent_(parent), table_format_(table_format) {}

  friend class Row;
  friend class Table;
  std::string data_;
  std::reference_wrapper<class Row> parent_;
  std::reference_wrapper<Format> table_format_;
  std::optional<Format> format_;
};

} // namespace tabulate
