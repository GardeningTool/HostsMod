# HostsMod

### VirusTotal: 

https://www.virustotal.com/gui/file/ab414d0ae73f20561c4f7cd81b143979a35176f859f52c5207872ee0ccb1659b/detection

If you don't trust it, either compile it yourself or manually append each entry to your hosts file.

### Description

In the Minecraft cheating community, it's not uncommon for clients or client cracks/leaks to be malware. The most famous example of this would be the Autumn client "crack", released by Kant. This application attempts to blacklist known hosts of Kant's malware, in order to prevent someone from accidentally getting themselves ratted.

HostsMod also blocks grabify links as well as a few token loggers.

### Domains

For a list of blocked domains, check out https://raw.githubusercontent.com/GardeningTool/HostsMod/main/domains.txt.

### Important

One of the websites, "mvncentral.net" is made to look like maven central (https://repo1.maven.org/maven2/). 
Maven central **is** safe, but mvncentral.net **is not**.


Many of the domains may appear to be suspended. This is due to the fact that Kant, the purchaser of the domains and person who spread the malware this program attempts to block, purchased these domains fraudulently. Though they are suspended, I have decided to include them anyways.

All releases are Windows specific. If you'd like one for Linux, I'd suggest https://github.com/HackingMC/HostsMod (though there's no known rats from Kant for Linux)

### Usage

Run as administrator

### Clarification

If you run netstat after running HostsMod, you will likely see connections to mvncentral.net. This is caused by HostsMod pointing everything to localhost (127.0.0.1). To prove this, open a command prompt window and type "ping mvncentral.net". The reply should be "Reply from 127.0.0.1". This shows that mvncentral.net now points to localhost.
