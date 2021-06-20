# HostsMod

### VirusTotal: https://www.virustotal.com/gui/file/58a61f545e21e60ff24f227571ef50b7ed1cd94b0d654bdd3f8267565f67a795/detection

### Description

In the Minecraft cheating community, it's not uncommon for clients or client cracks/leaks to be malware. The most famous example of this would be the Autumn client "crack", released by Kant. This application attempts to blacklist known hosts of Kant's malware, in order to prevent someone from accidentally getting themselves ratted.

I've also decided to include common IP logger links.

### Domains

    mvncentral.net
    vladvilcu2006.tech
    verble.software (Main domain for his rat)
    jonathanhardwick.me
    etc.catering
    tlrepo.cc (Not owned by Kant, however does contain a rat)
    khonsarifamily.tech
    batonrogue.tech
    verbleisover.party
    grabify.link
    bmwforum.co
    leancoding.co
    spottyfly.com
    stopify.co
    yoütu.be
    discörd.com
    minecräft.com
    freegiftcards.co
    disçordapp.com
    särahah.eu
    särahah.pl
    xda-developers.us
    quickmessage.us
    fortnight.space
    fortnitechat.site
    youshouldclick.us
    joinmy.site
    crabrave.pw
    lovebird.guru
    trulove.guru
    dateing.club
    otherhalf.life
    shrekis.life
    datasig.io
    datauth.io
    headshot.monster
    gaming-at-my.best
    progaming.monster
    yourmy.monster
    screenshare.host
    imageshare.best
    screenshot.best
    gamingfun.me
    catsnthing.com
    mypic.icu
    catsnthings.fun
    curiouscat.club
    gyazo.nl
    gaymers.ax
    ps3cfw.com
    iplogger.org
    steancomunnity.ru
    streamcommunnlty.ru

### Important

One of the domains, "mvncentral.net" is disguised as Maven Central, which is not a malicious site, however "mvncentral.net" is.

Many of the domains may appear to be suspended. This is due to the fact that Kant, the purchaser of the domains and person who spread the malware this program attempts to block, purchased these domains fraudulently. Though they are suspended, I have decided to include them anyways.

All releases are Windows specific. If you'd like one for Linux, I'd suggest https://github.com/HackingMC/HostsMod (though there's no known rats from Kant for Linux)

### Usage

Run as administrator

### Clarification

If you run netstat after running HostsMod, you will likely see connections to mvncentral.net. This is likely because I point everything to localhost (127.0.0.1). To ensure this, open a command prompt window and type "ping mvncentral.net". The reply should be "Reply from 127.0.0.1". This shows that mvncentral.net now points to localhost.
