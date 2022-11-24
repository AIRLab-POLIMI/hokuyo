#include "hokuyo.h"
#include <unistd.h>


int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3)
    {
        fprintf(stderr, "usage: getID /dev/ttyACM? [quiet]\nOutputs the device ID of a hokuyo at /dev/ttyACM?. Add a second argument for script friendly output.\n");
        return 1;
    }

    bool verbose = (argc == 2);

    hokuyo::Laser laser;

    for (int retries = 10; retries; retries--)
    {
        try
        {
            laser.open(argv[1]);
            std::string device_id = laser.getID();
            if (verbose)
                printf("Device at %s has ID ", argv[1]);
            printf("%s\n", device_id.c_str());
            laser.close();
            return 0;
        }
        catch (hokuyo::Exception &e)
        {
            printf("getID failed: %s", e.what());
            laser.close();
        }
        sleep(1);
    }
    return 1;
}
