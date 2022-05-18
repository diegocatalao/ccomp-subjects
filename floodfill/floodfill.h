#ifndef _H_FLOODFILL
#define _H_FLOODFILL

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define EOL '\n'
#define DEFAULT_FILEPATH_LIMIT 50

typedef char ** FLOODMAP;

typedef struct {
    // file path
    char filepath[DEFAULT_FILEPATH_LIMIT];

    // pointer to the file with the "image"
    FILE *pFile;

    // array with file content
    FLOODMAP floodmap;

    // number of lines in the file not counting the last
    int clines;

    // number of columns in the file not counting the last line
    int ccolumns;

    // number of characters in file
    int cchar;

    // x coordinate that will be filled
    int x;

    // y coordinate that will be filled
    int y;
} PFloodMap;

#endif

/**
 * @brief Flood Fill algorithm
 * 
 * @param x x position when flood fill begins
 * @param y y position when flood fill begins
 * @param floodmap array with flood map from file
 */
void floodfill(int x, int y, FLOODMAP floodmap);

/**
 * @brief Print flood map array
 * 
 * @param pFloodMap flood map struct object
 */
void floodmap_Print(PFloodMap *pFloodMap);

/**
 * @brief Count lines os file with flood map
 * 
 * @param pFloodMap flood map struct object
 */
void floodmap_CountLines(PFloodMap *pFloodMap);

/**
 * @brief Count columns os file with flood map
 * 
 * @param pFloodMap flood map struct object
 */
void floodmap_CountColumns(PFloodMap *pFloodMap);

/**
 * @brief Count chars os file with flood map
 * 
 * @param pFloodMap flood map struct object
 */
void floodmap_CountChars(PFloodMap *pFloodMap);

/**
 * @brief Setup flood map structure
 * 
 * @param pFloodMap pFloodmap object
 */
void floodmap_Setup(PFloodMap *pFloodMap);

/**
 * @brief Dealoc flood map struct
 * 
 * @param pFloodMap pFloodmap object
 */
void floodmap_Dealoc(PFloodMap *pFloodMap);