#include "nsflow/field2d.hpp"
#include <vector>
nsflow::Field2D::Field2D(const Grid &g)
    : nx_(g.nx()), ny_(g.ny()), g_(g.ghost()), stride_(nx_ + 2 * g_),
      data_(stride_ * (ny_ + 2 * g_), 0.0) {}

void nsflow::Field2D::fill(const double s) {
    for (auto &v : data_)
        v = s;
}
