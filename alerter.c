#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Simulate failure for high temperatures
    if (celcius > 150.0) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Bug: The code does not increment the alertFailureCount
        alertFailureCount += 1; // This should be incremented when there's a failure
    }
}

int main() {
    alertInCelcius(400.5); 
    alertInCelcius(303.6); 
    
    assert(alertFailureCount == 1); 
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
