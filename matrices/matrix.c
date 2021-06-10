#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void mx_free(TMatrix *m) {
	if (m != NULL)
		if (m->a != NULL) {
			free(m->a);
			free(m);
		}
}

void mx_print(TMatrix *m) {
	unsigned int i, j;

	if (m != NULL) {
		if (m->a != NULL) {
			for (i = 0; i < m->m; i++) {
				for (j = 0; j < m->n; j++)
					printf("%8.2lf", m->a[i * m->n + j]);
				printf("\n");
			}
		}
	}
}

TMatrix *mx_identity(unsigned int n) {
	unsigned int i, j;
	TMatrix *m = NULL;

	m = (TMatrix*)malloc(sizeof(TMatrix));
	if (m != NULL) {
		m->a = (double*)malloc(n * n * sizeof(double));
		if (m->a != NULL) {
			m->n = m->m = n;
			for (i = 0; i < m->m; i++)
				for (j = 0; j < m->n; j++)
					m->a[i * n + j] = i == j ? 1 : 0;
		}
		else {
			free(m);
			m = NULL;
		}
	}

	return m;
}

void mx_sort(TMatrix *m) {
    unsigned int i, j, size;
    double temp;
    size = m->n * m->m;
    
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
            if(m->a[j] > m->a[j + 1]) {
                temp = m->a[j];
                m->a[j] = m->a[j + 1];
                m->a[j + 1] = temp;
            }
    }
}


void mx_invert_row(TMatrix *m, int row) {
    unsigned int i, firstRowElem, lastRowElem;
    double temp;
    firstRowElem = m->n * row;
    lastRowElem = m->n * (row + 1) - 1;
    
    for(i = 0; i < m->n / 2; i++) {
        temp = m->a[firstRowElem + i];
        m->a[firstRowElem + i] = m->a[lastRowElem - i];
        m->a[lastRowElem - i] = temp;
    }
}