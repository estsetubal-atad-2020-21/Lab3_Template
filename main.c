#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "countries.h"

int main() {

    CountryInfo countries[235];

    int n = loadCountries(countries, 235);

    for(int i=0; i < n; i++) {
        printf("%s | %d | %d | %d | %.2f %% | %.2f %% \n", 
            countries[i].name,
            countries[i].population,
            countries[i].area,
            countries[i].medianAge,
            countries[i].urbanPopulation,
            countries[i].worldShare);
    }

    return EXIT_SUCCESS;
}
