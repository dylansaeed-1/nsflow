#include "nsflow/grid.hpp"
#include <vector>
#pragma once
namespace nsflow {
class Field2D {
  public:
    explicit Field2D(const Grid &g);
    double &operator()(int i, int j) { return data_[flat_(i, j)]; }
    const double &operator()(int i, int j) const { return data_[flat_(i, j)]; }
    int nx() const { return nx_; }
    int ny() const { return ny_; }
    void fill(const double s);

  private:
    std::size_t flat_(int i, int j) const { return (j + g_) * stride_ + (i + g_); }
    int nx_, ny_, g_, stride_;
    std::vector<double> data_;
};

} // namespace nsflow