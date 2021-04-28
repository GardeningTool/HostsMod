#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> blocked_sites = {
        //Kant's sites
        
        "mvncentral.net",
        "vladvilcu2006.tech",
        "verble.software", //Most likely Kant's main domain
        "jonathanhardwick.me",
        "etc.catering",
        "tlrepo.cc", // Another Kant URL used by the Tenacity crack.
        "batonrogue.tech",
        
        //IP Loggers
        "grabify.link",
        "bmwforum.co",
        "leancoding.co",
        "spottyfly.com",
        "stopify.co",
        "yoütu.be",
        "discörd.com",
        "minecräft.com",
        "freegiftcards.co",
        "disçordapp.com",
        "särahah.eu",
        "särahah.pl",
        "xda-developers.us",
        "quickmessage.us",
        "fortnight.space",
        "fortnitechat.site",
        "youshouldclick.us",
        "joinmy.site",
        "crabrave.pw",
        "lovebird.guru",
        "trulove.guru",
        "dateing.club",
        "otherhalf.life",
        "shrekis.life",
        "datasig.io",
        "datauth.io",
        "headshot.monster",
        "gaming-at-my.best",
        "progaming.monster",
        "yourmy.monster",
        "screenshare.host",
        "imageshare.best",
        "screenshot.best",
        "gamingfun.me",
        "catsnthing.com",
        "mypic.icu",
        "catsnthings.fun",
        "curiouscat.club",
        "gyazo.nl",
        "gaymers.ax", //no clue what this is
        "ps3cfw.com"
};

void read(vector<string> *lines);
void write(vector<string> vec, ofstream &hosts_file);

int main() {

    ofstream hosts_file;
    hosts_file.open(R"(C:\Windows\System32\drivers\etc\hosts)", ios::app);

    if (!hosts_file) {
        cout << "Unable to access hosts file! Try running as Administrator." << endl;
        getchar();
        return -1; //no access
    }

    vector<string> current;
    read(&current);
    write(current, hosts_file);
    hosts_file.close();
    cout << "Finished blacklisting " << blocked_sites.size() << " sites! Press any key to close." << endl;

    getchar();
}

void read(vector<string> *lines) {
    string line;
    ifstream in (R"(C:\Windows\System32\drivers\etc\hosts)");
    while (getline(in,line) ) {
        if (line.find("127.0.0.1") != string::npos) {
            lines->push_back(line);
        }
    }
    in.close();
}

void write(vector<string> vec, ofstream &hosts_file) {
    for (const auto &site : blocked_sites) {
        if (find(vec.begin(), vec.end(), "127.0.0.1     " + site) == vec.end()) {
            hosts_file << "\n127.0.0.1     " << site;
            cout << "Blacklisted " << site << endl;
        }
    }
}
