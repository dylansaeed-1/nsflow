#pragma once
#include "nsflow/vec2.hpp"
namespace nsflow {

class Grid {
  public:
    Grid(const int nx, const int ny, const double lx, const double ly, const int g)
        : nx_(nx), ny_(ny), g_(g), lx_(lx), ly_(ly), dx_(lx / static_cast<double>(nx)),
          dy_(ly / static_cast<double>(ny)){};
    int nx() const { return nx_; }
    int ny() const { return ny_; }
    int ghost() const { return g_; }

    double lx() const { return lx_; }
    double ly() const { return ly_; }
    double dx() const { return dx_; }
    double dy() const { return dy_; }
    const Vec2 origin() const { return Vec2{0.0, 0.0}; }

  private:
    const int nx_, ny_, g_;
    const double lx_, ly_;
    const double dx_, dy_;
};
} // namespace nsflow