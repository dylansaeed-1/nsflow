#include "nsflow/boundary.hpp"
#include "nsflow/field2d.hpp"
#include "nsflow/grid.hpp"
#include "nsflow/vec2.hpp"
#include <cassert>
#include <csignal>
#include <tuple>
namespace nsflow {

Index2 get_offset(const Side2D s) {
    switch (s) {
    case Side2D::LEFT:
        return {-1, 0};
    case Side2D::RIGHT:
        return {1, 0};
    case Side2D::TOP:
        return {0, 1};
    case Side2D::BOTTOM:
        return {0, -1};
    }
    assert(false and "Invalid Side2D");
    return {0, 0};
}
Neumann::Neumann(const double s) : q_(s) {}

Dirichlet::Dirichlet(const double s) : val_(s) {}

void Boundary::apply(const Grid &g, const Side2D side, Field2D &f) const{
    auto offset = get_offset(side);

    int n_boundary = (offset.i == 0) ? f.nx() : f.ny();
    int n_across = (offset.j == 0) ? f.nx() : f.ny();
    double spacing = (offset.i == 0) ? g.dy() : g.dx();


    int sign = offset.i + offset.j;
    int corner_idx = (sign < 0) ? 0 : n_across - 1;


    Index2 interior, ghost_cell;

    for (int i = 0; i < n_boundary; ++i) {
        if (offset.i == 0)
            
            interior = {i, corner_idx};
        else
            interior = {corner_idx, i};
        ghost_cell = interior + offset;
        f(ghost_cell.i, ghost_cell.j) = ghost_value(f(interior.i, interior.j), spacing);
    }
    return;
};
// v is interior
double Dirichlet::ghost_value(const double v, [[maybe_unused]] const double) const {
    return 2 * val_ - v;
}

double Neumann::ghost_value(const double v, const double h) const { return q_ * h + v; }

void fillGhosts(const Grid &g, const Boundary &left, const Boundary &right, const Boundary &top, const Boundary &bottom, Field2D &f){
    left.apply(g, Side2D::LEFT, f);
    right.apply(g, Side2D::RIGHT, f);
    top.apply(g, Side2D::TOP, f);
    bottom.apply(g, Side2D::BOTTOM, f);
}

} // namespace nsflow
/*
base
LEFT = (0,k) + (-1,0)
RIGHT = (nx-1, k) + (1,0)
BOTTOM = (k, 0) + (0,-1)
TOP = (k, ny-1) + (0,1)
*/