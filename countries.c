#include "countries.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

CountryInfo countryInfoParse(char *name, char *population, char *area, 
    char *medianAge, char *urbanPopulation, char *worldShare) {

    CountryInfo info;

    strcpy(info.name, name);
    info.population = (strcmp(population, "N.A.") == 0) ? -1 : atoi(population);
    info.area = (strcmp(area, "N.A.") == 0) ? -1 : atoi(area);
    info.medianAge = (strcmp(medianAge, "N.A.") == 0) ? -1 : atoi(medianAge);
    info.urbanPopulation = (strcmp(urbanPopulation, "N.A.") == 0) ? -1 : atof(urbanPopulation);
    info.worldShare = (strcmp(worldShare, "N.A.") == 0) ? -1 : atof(worldShare);
    
    return info;
}

int loadCountries(CountryInfo arr[], int howMany) {

    FILE* stream = fopen("countries2020.csv", "r");
    int count = 0;

    if(!stream) return 0;

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if(count == howMany) break;

        char* tmp = strdup(line);
        
        char** tokens = splitString(tmp, 6, ";");
        
        arr[count++] = countryInfoParse(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}