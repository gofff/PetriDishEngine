#include <app/App.h>

#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Use config path as first cl arg\n";
        return -1;
    }
    petri::App app{ std::string(argv[1]) };
    return app.Run();
}