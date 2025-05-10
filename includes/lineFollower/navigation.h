#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

void directions(int currDir, int finishDir) {
    int diff = (finishDir - currDir + 4) % 4;
    
    switch (diff) {
        case 1: turnLineRight(75, 70); break;
        case 2: turnLine180(75); break;
        case 3: turnLineLeft(75, 70); break;
    }
    stopBC(20);
}

void directionsDeg(int currDir, int finishDir) {
    int diff = (finishDir - currDir + 4) % 4;
    
    switch (diff) {
        case 1: turnRight(75, 91, 35); break;
        case 2: turnLine180(75); break;
        case 3: turnLeft(75, 91, 35); break;
    }
    stopBC(20);
}

int oppositeDir(int currDir) {return (currDir + 2) % 4;}

void navigate(int startX, int finishX, int dir, bool degr = false, int &outDir, bool lineAtStart = false) {
    if (startX == finishX) {
        outDir = dir;
        return;
    }

    int delta = finishX - startX;
    int targetDir = (delta < 0) ? 2 : 0;
    
    if (!degr) {
        directions(dir, targetDir);
    } else {
        directionsDeg(dir, targetDir);
    }
    
    dir = targetDir;
    
    if (lineAtStart) {
        lineCM(80, 4.1, 45, 45);
    }
    
    QCross(85, abs(delta), 80, false, 2.71);
    outDir = dir;
}

#endif