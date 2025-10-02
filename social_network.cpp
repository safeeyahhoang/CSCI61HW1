#include <iostream>
#include "network.h"

int main(int argc, char* argv[]) {
    Network net;
    net.readUsers(argv[1]);
    return 0;
}
