#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> blocked_sites = {
    "mvncentral.net",
    "vladvilcu2006.tech",
    "verble.software",
    "jonathanhardwick.me",
    "etc.catering",
    "batonrogue.tech"
};

vector<string> read();
void write(vector<string> vec, ofstream &hosts_file);

int main() {

    ofstream hosts_file;
    hosts_file.open(R"(C:\Windows\System32\drivers\etc\hosts)", ios::app);

    if (!hosts_file) {
        cout << "Unable to access hosts file! Try running as Administrator." << endl;
        getchar();
        return -1; //no access
    }

    write(read(), hosts_file);
    hosts_file.close();
    cout << "Finished! Press any key to close." << endl;

    getchar();
}

vector<string> read() {
    vector<string> lines = {};
    string line;
    ifstream in (R"(C:\Windows\System32\drivers\etc\hosts)");
    while (getline(in,line) ) {
        if (line.find("127.0.0.1") != string::npos) {
            lines.push_back(line);
        }
    }
    in.close();
    return lines;
}

void write(vector<string> vec, ofstream &hosts_file) {
    for (const auto &site : blocked_sites) {
        if (find(vec.begin(), vec.end(), "127.0.0.1     " + site) == vec.end()) {
            hosts_file << "127.0.0.1     " << site << "\n";
            cout << "Blacklisted " << site << endl;
        }
    }
}
