#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using vector_t = std::vector<std::string>;

namespace vars
{
  vector_t blocked_sites{};
}

vector_t read()
{
  vector_t lines{};

  std::ifstream hosts("C:\\Windows\\System32\\drivers\\etc\\hosts");
  std::string line{};

  while (std::getline(hosts, line))
  {
    if (line.find("0.0.0.0") != std::string::npos)
    {
      lines.push_back(line);
    }
  }

  return lines;
}

bool write(vector_t& vec)
{
  int blacklisted{ 0 };

  std::ofstream hosts_file{ L"C:\\Windows\\System32\\drivers\\etc\hosts", std::ios::app };

  // this won't ever happen
  if (!hosts_file)
    std::exit(-1); 

  for (const auto& site : vars::blocked_sites)
  {
    if (std::find(vec.begin(), vec.end(), "0.0.0.0     " + site) == vec.end()) 
    {
      hosts_file << "\n0.0.0.0     " << site;
      std::cout << "Blacklisted " << site << '\n';
      ++blacklisted;
    }
  }

  std::cout << "Finished blacklisting " 
    << blacklisted 
    << " sites! Press any key to close\n";
}

void fetch_domains() 
{
  system("C:\\Windows\\System32\\curl \
    https://raw.githubusercontent.com/GardeningTool/HostsMod/main/domains.txt > domains.txt");

  std::ifstream domains("domains.txt");
  std::string line{};  

  while (std::getline(domains, line)) 
  {
    vars::blocked_sites.push_back(line);
  }
}

int main()
{
  fetch_domains();
    
  vector_t current{ read() };

  write(current);

  return std::cin.get();
}
