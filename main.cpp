#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const vector<string> blocked_sites = {
    "mvncentral.net",
    "vladvilcu2006.tech",
    "verble.software",
    "jonathanhardwick.me",
    "vladvilcu2006.tech",
    "etc.catering" };

int main() {

    ofstream hosts_file;
    hosts_file.open("C:\\Windows\\System32\\drivers\\etc\\hosts", ios::app);

    if (!hosts_file) {
        cout << "Unable to access hosts file! Try running as Administrator." << endl;
        return -1; //no access
    }

    for (auto site : blocked_sites) {
        hosts_file << "127.0.0.1     " << site << "\n";
        cout << "Blacklisted " << site << endl;
    }

    hosts_file.close();

}