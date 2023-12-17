#include <iostream>
#include <vector>
#include <cmath> // for pow function

// Function to calculate fitness for an agent
double Calculate_Fitness(const std::vector<double>& Agent, int t, int w) {
    const double omega1 = 1.0;
    const double omega2 = 1.0;
    const double omega3 = 1.0;

    double TotalDelay = 0.0;
    double Task = 0.0;
    double UAVEnergy = 0.0;
    double Load = 0.0;

    double tijb_tr = 0.2, tij_wait = 0.4, tijb_comp = 0.7, tijbj_rec = 0.9;
    double ejb_tr = 0.3, ejb_comp = 0.5, ebj_rec = 0.8;
    double ecflying = 0.6, echover = 0.9;

    std::vector<double> load(t + w, 0.0);
    std::vector<double> FitnessTime(t + w, 0.0);

    for (const auto& ajit : Agent) {
        int b = static_cast<int>(ceil(ajit));
        Task += (tijb_tr + tij_wait + tijb_comp + tijbj_rec); // Update delay
        Task += (ejb_tr + ejb_comp + ebj_rec); // Update energy consumption
        if (b >= t + 1) {
            UAVEnergy += (ecflying + echover); // Update UAV energy consumption
        }
        load[b - 1] += FitnessTime[b - 1];
        FitnessTime[b - 1] += tijb_comp; // Update FitnessTime
    }

    double mu = 0.0;
    for (int b = 0; b < t + w; ++b) {
        mu += load[b];
    }
    mu /= (t + w);

    for (int b = 0; b < t + w; ++b) {
        Load += pow((load[b] - mu), 2);
    }

    TotalDelay = Task;
    double TotalEnergy = Task + UAVEnergy;
    double Fitness = omega1 * TotalDelay + omega2 * TotalEnergy + omega3 * Load;

    return Fitness;
}

int main() {
    // Example usage
    int t = 5; // Example value for t
    int w = 3; // Example value for w

    std::vector<double> agent = {1.2, 2.8, 3.5, 4.1, 5.7}; // Example agent vector

    double fitness = Calculate_Fitness(agent, t, w);

    std::cout << "Fitness: " << fitness << std::endl;

    return 0;
}
