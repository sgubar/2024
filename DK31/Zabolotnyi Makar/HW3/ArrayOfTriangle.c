#include "ArrayOfTriangle.h"
#include <stdlib.h>
#include <strings.h>

int extendArrayOfTriangles(ArrayOfTriangles *anArray);

ArrayOfTriangles *createArrayOfTriangles(int aReserved) {
  ArrayOfTriangles *result = (ArrayOfTriangles *)malloc(sizeof(ArrayOfTriangles));

  if (NULL != result) {
    result->preservedCount = (aReserved > 0) ? aReserved : 2;
    result->count = 0;
    result->storage = (Triangle **)malloc(sizeof(Triangle *) * result->preservedCount);

    if (NULL == result->storage) { // if failed to alloc memory for internal storage
      free(result);
      return NULL;
    } else {
      bzero(result->storage, sizeof(Triangle *) * result->preservedCount);
      // memset(result->storage, 0, sizeof(Point *) * result->preservedCount);
    }
  }

  return result;
}

void destroyArrayOfTriangles(ArrayOfTriangles *anArray) {
  if (NULL == anArray) {
    return ;
  }

  free(anArray->storage);
  free(anArray);
}

void addTriangle(ArrayOfTriangles *anArray, Triangle *aTriangle) {
  if (NULL == anArray) {
    return ;
  }

  if (anArray->count == anArray->preservedCount) {
    if (0 != extendArrayOfTriangles(anArray)) {
      return ;
    }
  }

  anArray->storage[anArray->count] = aTriangle;
  anArray->count ++;
}

void printArrayOfTriangles(ArrayOfTriangles *anArray) {
  if (NULL == anArray) {
    return ; //Bad input parameters
  }

  for (int i = 0; i < anArray->count; i ++) {
    printTriangle(anArray->storage[i]);
    printf(" ");
  }
}

Point *getTriangleAt(ArrayOfTriangles *anArray, int aIndex) {
  if (NULL == anArray || aIndex >= anArray->count) {
    return NULL; //Bad input parameters
  }

  return anArray->storage[aIndex];
}

int countArrayOfTriangles(ArrayOfTriangles *anArray) {
  return (NULL != anArray) ? anArray->count : -1;
}

int extendArrayOfTriangles(ArrayOfTriangles *anArray) {
  if (NULL == anArray) {
    return 1; //Bad input parameters
  }

  printf("realloc \n");

  anArray->preservedCount *= 2;
  Triangle **local = (Triangle **)malloc(sizeof(Triangle *) * anArray->preservedCount);

  if (NULL == local) {
    return 2;
  }

  memcpy(local, anArray->storage, anArray->count * sizeof(Point *));

  free(anArray->storage);

  anArray->storage = local;

  return 0;
}
