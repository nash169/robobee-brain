#include <iostream>
#include <string>
#include "environment.hh"

int main(int argc, char const *argv[]) {
  std::string folder;
  bool LOAD = false;
  int action = 0;
  double start = 0, end = 0;

  std::cout << "Insert folder name: ";
  std::cin >> folder;
  folder = "Simulations/" + folder + "/";
  Plotter Plot(folder, LOAD);

  std::cout << "\n1. Plot&Save Results\n2. Plot Zoomed Results\n3. View Simulation\n4. Exit" << std::endl;
  std::cout << "Choose action: ";
  std::cin >> action;

  switch (action) {
    case 1:
      Plot.InState();
      Plot.Control();
      Plot.RobotPos();
      Plot.NetActivity();
      Plot.EnvActivity();
      Plot.Weights();
      Plot.ValueMat();
      break;
    case 2:
      std::cout << "Start View Time: ";
      std::cin >> start;
      std::cout << "End View Time: ";
      std::cin >> end;
      Plot.Results(start, end);
      break;
    case 3:
      std::cout << "Start View Time: ";
      std::cin >> start;
      std::cout << "End View Time: ";
      std::cin >> end;
      Plot.Simulation(start, end);
      break;
    case 4:
      break;
    default:
      break;
  }

  return 0;
}
