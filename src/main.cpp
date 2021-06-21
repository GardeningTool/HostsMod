#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<std::string> blocked_sites;

void fetchDomains();
void read(std::vector<std::string> *lines);
void write(std::vector<std::string> vec, std::ofstream &hosts_file);

int main() {

    fetchDomains();

    std::ofstream hosts_file;
    hosts_file.open(R"(C:\Windows\System32\drivers\etc\hosts)", std::ios::app);

    if (!hosts_file) {
        std::cout << "Unable to access hosts file! Try running as Administrator." << std::endl;
        getchar();
        return -1; //no access
    }

    fetchDomains();

    std::vector<std::string> current;
    read(&current);
    write(current, hosts_file);
    hosts_file.close();

    getchar();
}

void read(std::vector<std::string> *lines) {
    std::string line;
    std::ifstream in (R"(C:\Windows\System32\drivers\etc\hosts)");
    while (getline(in,line) ) {
        if (line.find("127.0.0.1") != std::string::npos) {
            lines->push_back(line);
        }
    }
    in.close();
}

void write(std::vector<std::string> vec, std::ofstream &hosts_file) {
    int blacklisted = 0;
    for (const auto &site : blocked_sites) {
        if (find(vec.begin(), vec.end(), "127.0.0.1     " + site) == vec.end()) {
            hosts_file << "\n127.0.0.1     " << site;
            std::cout << "Blacklisted " << site << std::endl;
            ++blacklisted;
        }
    }
    std::cout << "Finished blacklisting " << blacklisted << " sites! Press any key to close." << std::endl;
}

void fetchDomains() {
    system(R"(C:\Windows\System32\curl https://raw.githubusercontent.com/GardeningTool/HostsMod/main/domains.txt > domains.txt)");
    std::string line;
    std::ifstream in ("domains.txt");
    while (getline(in, line)) {
        blocked_sites.push_back(line);
    }
}
