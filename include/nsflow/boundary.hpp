#pragma once
#include "nsflow/field2d.hpp"
#include "nsflow/grid.hpp"
#include "nsflow/vec2.hpp"
namespace nsflow {

enum class Side2D { LEFT, RIGHT, TOP, BOTTOM };
Index2 get_offset(Side2D s);

class Boundary {

  public:
    virtual ~Boundary() = default;
    void apply(const Grid &, const Side2D, Field2D &) const;
  protected:
    double virtual ghost_value(const double v, const double h) const = 0;
};

class Neumann : public Boundary {
  public:
    explicit Neumann(const double s);

  protected:
    double ghost_value(const double interior, const double h) const override;

  private:
    double q_;
};
class Dirichlet : public Boundary {
  public:
    explicit Dirichlet(const double s);

  protected:
    // takes in interior value and return mirrored ghost cell value.
    double ghost_value(const double interior, const double h) const override;

  private:
    // boundary condiiton to enforce
    double val_;
};

void fillGhosts(const Grid &, const Boundary& left, const Boundary& right, const Boundary& top, const Boundary& bottom, Field2D& f);
} // namespace nsflow