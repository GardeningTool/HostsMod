#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const std::vector<std::string> blocked_sites = {
        //Kant's sites
        
        "mvncentral.net", //Hosts a fake Netty JAR that downloads a rat
        "vladvilcu2006.tech", //Older, suspended
        "verble.software", //Most likely Kant's main domain
        "jonathanhardwick.me", //Older, suspended
        "etc.catering", //Older, suspended
        "khonsarifamily.tech",
        "verbleisover.party",
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
        "ps3cfw.com",

        //iplogger.org
        "iplogger.org",

        //Others
        "gaymers.ax", //No clue what this is but someone opened a PR and multiple reputable people vouched for it
        "tlrepo.cc", // Not one of Kant's sites, however still malicious
        "steancomunnity.ru", //People keep posting all over discord, when asked they said they didnt send that link so probably a token logger
};

void read(std::vector<std::string> *lines);
void write(std::vector<std::string> vec, std::ofstream &hosts_file);

int main() {

    std::ofstream hosts_file;
    hosts_file.open(R"(C:\Windows\System32\drivers\etc\hosts)", std::ios::app);

    if (!hosts_file) {
        std::cout << "Unable to access hosts file! Try running as Administrator." << std::endl;
        getchar();
        return -1; //no access
    }

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
