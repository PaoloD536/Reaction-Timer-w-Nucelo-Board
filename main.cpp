#include "mbed.h"

// main() runs in its own thread in the OS
Timer t;
DigitalIn reaction_button(PC_13);
DigitalOut reactionlight(LED1);
int main()
{
    t.reset();
    int randtime = rand() % 10+1;
    thread_sleep_for(randtime*1000);
    reactionlight = 1;
    t.start();
    while (true){
        if(!reaction_button)
        {
        reactionlight = 0;
        t.stop();
        printf("The time taken was %llu milliseconds\n", duration_cast<std::chrono::milliseconds>(t.elapsed_time()).count());
        thread_sleep_for(500);
        }
    }
}