#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class csv_loader{ 
    public:
    
        std::vector<std::vector<int>> loadCSV(const std::string& filename);
};