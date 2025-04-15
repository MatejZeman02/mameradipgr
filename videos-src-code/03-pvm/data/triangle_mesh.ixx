export module triangle_mesh; // XD 0

export const int triangle_n_attribs_per_vertex = 8;
export const int triangle_n_vertices = 3;
export const int triangle_n_triangles = 1;
export const float triangle_vertices[] = {
//     x         y      z         nx        ny      nz       u        v
  1.000000,-1.000000,0.000000,-0.000000,0.000000,1.000000,1.000000,0.000000,
  -1.000000,1.000000,0.000000,-0.000000,0.000000,1.000000,0.000000,1.000000,
  -1.000000,-1.000000,0.000000,-0.000000,0.000000,1.000000,0.000000,0.000000,
}; // end triangle_vertices

export const unsigned triangle_triangles[] = {
  0, 1, 2,
}; // end triangle_triangles

