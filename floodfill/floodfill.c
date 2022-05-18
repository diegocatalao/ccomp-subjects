#include "floodfill.h"

void floodfill(int x, int y, FLOODMAP floodmap) {
    if (floodmap[x][y] == 'X')
        return;
    
    floodmap[x][y] = 'X';
    floodfill(x + 1, y, floodmap);
    floodfill(x - 1, y, floodmap);
    floodfill(x, y + 1, floodmap);
    floodfill(x, y - 1, floodmap);
}

void floodmap_Print(PFloodMap *pFloodMap) {
    for (int i = 0; i < pFloodMap->clines; i++)
        printf("%s", pFloodMap->floodmap[i]);
}

void floodmap_LoadFromFile(PFloodMap *pFloodMap) {
    fseek(pFloodMap->pFile, 0, SEEK_SET);
    
    pFloodMap->floodmap = malloc(pFloodMap->clines * sizeof(char *));

    for (int i = 0; i < pFloodMap->clines; i++) {
        pFloodMap->floodmap[i] = malloc(pFloodMap->ccolumns * sizeof(char));
        for (int j = 0; j < pFloodMap->ccolumns; j++)
            pFloodMap->floodmap[i][j] = fgetc(pFloodMap->pFile);
    }
}

void floodmap_CountLines(PFloodMap *pFloodMap) {
    char buffer;

    fseek(pFloodMap->pFile, 0, SEEK_SET);
    pFloodMap->clines = 0;

    while ((buffer = fgetc(pFloodMap->pFile)) != EOF)
        if (buffer == EOL)
            pFloodMap->clines++;
}

void floodmap_CountColumns(PFloodMap *pFloodMap) {
    char buffer;

    fseek(pFloodMap->pFile, 0, SEEK_SET);
    pFloodMap->ccolumns = 1;

    while ((buffer = fgetc(pFloodMap->pFile)) != EOF)
        if (buffer == EOL)
            break;
        else
            pFloodMap->ccolumns++;
}

void floodmap_CountChars(PFloodMap *pFloodMap) {
    char buffer;

    fseek(pFloodMap->pFile, 0, SEEK_SET);
    pFloodMap->cchar = 0;

    while ((buffer = fgetc(pFloodMap->pFile)) != EOF)
        pFloodMap->cchar++;
}

void floodmap_GetPoint(PFloodMap *pFloodMap) {
    char buffer;
    int buffer_count_lines = 0;
    
    fseek(pFloodMap->pFile, 0, SEEK_SET);
    
    while ((buffer = fgetc(pFloodMap->pFile)) != EOF) {
        if (buffer == EOL) {
            buffer_count_lines++;
        }
        if (buffer_count_lines == pFloodMap->clines) {
            break;
        }
    }
    fscanf(pFloodMap->pFile, "%d %d", &(pFloodMap->x), &(pFloodMap->y));

}

void floodmap_Setup(PFloodMap *pFloodMap) {
    floodmap_CountLines(pFloodMap);
    floodmap_CountColumns(pFloodMap);
    floodmap_CountChars(pFloodMap);
    floodmap_GetPoint(pFloodMap);
    floodmap_LoadFromFile(pFloodMap);
}

void floodmap_Dealoc(PFloodMap *pFloodMap) {
    if (pFloodMap != NULL)
        free(pFloodMap);
}