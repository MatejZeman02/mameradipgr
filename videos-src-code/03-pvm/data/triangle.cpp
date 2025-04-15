#include "triangle.h"
const int triangle_n_attribs_per_vertex = 8;
const int triangle_n_vertices = 3;
const int triangle_n_triangles = 1;
const float triangle_vertices[] = {
  1.000000,-1.000000,0.000000,-0.000000,0.000000,1.000000,1.000000,0.000000,
  -1.000000,1.000000,0.000000,-0.000000,0.000000,1.000000,0.000000,1.000000,
  -1.000000,-1.000000,0.000000,-0.000000,0.000000,1.000000,0.000000,0.000000,
}; // end triangle_vertices

const unsigned triangle_triangles[] = {
  0, 1, 2,
}; // end triangle_triangles

