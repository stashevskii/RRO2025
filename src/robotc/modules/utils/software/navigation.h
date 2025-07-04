#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

void directions(int currDir, int finishDir) {
    int diff = (finishDir - currDir + 4) % 4;
    switch (diff) {
        case 1: turnLineRight(60, 70, 30); break;
        case 2: turnLine180(60, 165, 30); break;
        case 3: turnLineLeft(60, 70, 30); break;
    }
}

void directionsDeg(int currDir, int finishDir) {
    int diff = (finishDir - currDir + 4) % 4;
    switch (diff) {
        case 1: turnRight(60, 91, 35); break;
        case 2: turnLine180(60); break;
        case 3: turnLeft(60, 91, 35); break;
    }
}

int opposite(int currDir) {return (currDir + 2) % 4;}

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
    stopBC(20);
    
    dir = targetDir;
    
    if (lineAtStart) {
        lineCM(80, 4.1, 25, 25);
    }

    QCross(80, abs(delta), 80, false, 2);
    outDir = dir;
}

#endif