#include <stdio.h>
#include <time.h>

void showTime(long timeMinus, time_t seconds,char style);
void convert(time_t seconds);

// Define time units with floating-point precision
const double DROP = 4.0;                                // 1 drop ≈ 4 seconds (0.00021428571L)
const double KIAF = 210.0 * DROP;                       // 1 kiaf ≈ 14 minutes (0.045L)
const double SKIFOS = 1845 * DROP;                      // 1 skifos ≈ 2 hours 3 minutes (0.395L)
const double KARAS = 24300 * DROP;                      // 1 karas ≈ 27 hours (5.20714L)
const double PITHOS = 190.6996931136862078 * KARAS;     // 1 pithos ≈ 18536010.17065029939816 seconds (993L)   993 - you know.

long pithoses;
long karases;
long skifoses;
long kiafs;
long drops;


int main() {
    
    // Get current UNIX time
    time_t seconds = time(NULL);

                            // printf("\033[93mLight Yellow Text\033[0m\n");
    char stroke[] = "\033[93m=========================================================||\033[0m";
    printf("%s", stroke);
    printf("\n\033[92mSince January 1, 1970:\033[0m\n");
    showTime(0, seconds,94);  //- what time after 1970 start count, current time, color.
    printf("\n");

    // printf("\033[92mSince my birthday:\033[0m\n");
    // long mB = 1000000000; //- your birthday
    // showTime(mB, seconds,33);


    printf("%s\n", stroke);
    return 0;
}

void convert(time_t seconds)
{
    pithoses = (long)(seconds / PITHOS);
    karases = (long)((seconds - pithoses * PITHOS) / KARAS);
    skifoses = (long)((seconds - pithoses * PITHOS - karases * KARAS) / SKIFOS);
    kiafs = (long)((seconds - pithoses * PITHOS - karases * KARAS - skifoses * SKIFOS) / KIAF);
    drops = (long)((seconds - pithoses * PITHOS - karases * KARAS - skifoses * SKIFOS - kiafs * KIAF) / DROP);
}

void showTime(long timeMinus, time_t seconds, char style)
{
    convert(seconds - timeMinus); //- converts
    printf("\033[%dm%ld pithoses, %ld karases, %ld skifoses, %ld kiafs, %ld drops.\033[0m\n", style, pithoses, karases, skifoses, kiafs, drops); //- prints


}

