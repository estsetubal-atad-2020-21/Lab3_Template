#pragma once

typedef struct countryInfo {
    char name[50];
    int population;
    int area;
    int medianAge;
    float urbanPopulation;
    float worldShare;
} CountryInfo;

CountryInfo countryInfoParse(char *name, char *population, char *area, 
    char *medianAge, char *urbanPopulation, char *worldShare);

int loadCountries(CountryInfo arr[], int howMany);
