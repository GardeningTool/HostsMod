#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const vector<string> blocked_sites = {
    "mvncentral.net",
    "vladvilcu2006.tech",
    "verble.software",
    "jonathanhardwick.me",
    "etc.catering",
    "batonrogue.tech"
};

int main() {

    ofstream hosts_file;
    hosts_file.open(R"(C:\Windows\System32\drivers\etc\hosts)", ios::app);

    if (!hosts_file) {
        cout << "Unable to access hosts file! Try running as Administrator." << endl;
        getchar();
        return -1; //no access
    }

    for (const auto& site : blocked_sites) {
        hosts_file << "127.0.0.1     " << site << "\n";
        cout << "Blacklisted " << site << endl;
    }

    hosts_file.close();

    cout << "Finished! Press any key to close." << endl;

    getchar();
}
