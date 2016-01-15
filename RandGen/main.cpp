#include <iostream>
#include <Eigen/Dense>
#include "_everyheader.h"

int main(int argc, char* argv[]) {
  
  // Declare experiment options variable.
  options_t opts;
  
  // Parse experiment options from input arguments.
  parse_options_from_args(argc, argv, opts);
  
  // Set the random seed.
  std::srand(opts.seed);
  
  // Generate random matrices U & V.
  MatrixXd_t U = MatrixXd_t::Random(opts.m, opts.r);
  MatrixXd_t V = MatrixXd_t::Random(opts.n, opts.r);
  
  if (opts.DISPLAY) {
    std::cout << "Generated random U and V." << std::endl;
  }
  
  // Write as binary files.
  std::string sample_prefix = opts.folder + "/" + opts.dataset + "_r" + std::to_string(opts.r);
  io::write_dense_matrix(sample_prefix + "_U0.bin", U, opts.m, opts.r);
  io::write_dense_matrix(sample_prefix + "_V0.bin", V, opts.n, opts.r);
  
  if (opts.DISPLAY) {
    std::cout << "Written U & V as binary files." << std::endl;
  }
  
  return 0;
}

//
//int main(void) {
//  /* Dataset test code */
//  int m = 72;
//  int n = 319;
//  int r = 4;
//  std::string M_path = "dino_trimmed_r4_M.bin";
//  std::string W_path = "dino_trimmed_r4_W.bin";
//  std::string U_path = "dino_trimmed_r4_U.bin";
//  std::string V_path = "dino_trimmed_r4_V.bin";
//  MatrixXd_t U(m, r), V(n, r);
//  io::read_dense_matrix(U_path, U, m, r);
//  io::read_dense_matrix(V_path, V, n, r);
//  
//  // Set the dataset.
//  dataset_t data(m, n, M_path, W_path);
//  
//  // Initialize the problem.
//  problem_t problem(&data, r, &U, &V);
//  
//  // Set optimizer options.

//  opts.max_iters = 300;
//  
//  // Run the optimizer.
//  optimizer_t optimizer(&problem, &opts);
//  optimizer.solve();
//  
//  return 0;
//}
