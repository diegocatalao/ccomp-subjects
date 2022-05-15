/**
 * @file main.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Implemente um programa em múltiplos arquivos que demonstre o 
 *        resultado do algoritmo flood fill recursivo
 * @version 0.0.1
 * @date 2022-05-14
 */
#include "floodfill.h"

int main(int argc, char *argv[]) {
    PFloodMap *pFloodMap = (PFloodMap *) malloc(sizeof(PFloodMap));

    // read file from stdin
    scanf("%s", pFloodMap->filepath);
    if ((pFloodMap->pFile = fopen(pFloodMap->filepath, "r")) == NULL) {
        printf("Erro arquivo inexistente\n");
        // assert((pFloodMap->pFile != NULL) && "File not found.");
        exit(EXIT_FAILURE);
    }

    // setup flood map structure
    floodmap_Setup(pFloodMap);
    floodfill(pFloodMap->x, pFloodMap->y, pFloodMap->floodmap);
    floodmap_Print(pFloodMap);
    floodmap_Dealoc(pFloodMap);

    return EXIT_SUCCESS;
}